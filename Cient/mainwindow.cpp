#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->centralwidget->setEnabled(false);
    ui->lnClientName->setEnabled(true);
    setupClient();
    ui->stackedWidget->insertWidget(0, ui->pgLogin);
    ui->stackedWidget->insertWidget(1, ui->pgMessanger);

    ui->stackedWidget->setCurrentIndex(0);

    ui->menubar->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setupClient()
{
    _client = new ClientManager();
    _client->connectToServer();
    connect(_client, &ClientManager::connected, [this](){
        //ui->centralwidget->setEnabled(true);
        ui->btnSend->setEnabled(false);
        ui->lnMessage->setEnabled(false);
        ui->actionConnect->setEnabled(false);
    });
    connect(_client, &ClientManager::disconnected, [this](){
        //ui->centralwidget->setEnabled(false);
        ui->lnClientName->setEnabled(true);
        ui->actionConnect->setEnabled(true);
    });
    connect(_client, &ClientManager::textMessageRecieved, this, &MainWindow::dataRecieved);
    connect(_client, &ClientManager::isTyping, this, &MainWindow::onTyping);
    connect(_client, &ClientManager::initReceivingFile, this, &MainWindow::onInitReceivingFile);
    connect(_client, &ClientManager::rejectReceivingFile, this, &MainWindow::onRejectReceivingFile);
    connect(ui->lnMessage, &QLineEdit::textChanged, _client, &ClientManager::sendIsTyping);

    connect(_client, &ClientManager::connectionACK, this, &MainWindow::onConnectionACK);
    connect(_client, &ClientManager::newClientConnectedToServer, this, &MainWindow::onNewClientConnectedToServer);
    connect(_client, &ClientManager::clientDisconnected, this, &MainWindow::onClientDisconnected);
    connect(_client, &ClientManager::clientNameChanged, this, &MainWindow::onClientNameChanged);

}

void MainWindow::on_actionConnect_triggered()
{   
    _client->connectToServer();
}

void MainWindow::on_actionExit_triggered()
{
    _client->disconnectFromServer();
    _client->deleteLater();
}

void MainWindow::dataRecieved(QString message)
{
   // ui->lstMessages->addItem(data);
    auto chatWidget = new ChatItemWidget(this);
    chatWidget->setMessage(message);
    auto listItemWidget = new QListWidgetItem();
    listItemWidget->setSizeHint(QSize(0,90));
    ui->lstMessages->addItem(listItemWidget);
    listItemWidget->setBackground(QColor(100, 100, 100));
    ui->lstMessages->setItemWidget(listItemWidget, chatWidget);
}


void MainWindow::on_btnSend_clicked()
{
    if(ui->lnMessage->text() == ""){
        return;
    }
    auto message = ui->lnClientName->text() + "\n"+ ui->lnMessage->text().trimmed();
    _client->sendMessage(message, ui->cmbDestination->currentText());
    //ui->lstMessages->addItem(message);

    ui->lnMessage->setText("");
    auto chatWidget = new ChatItemWidget(this);
    chatWidget->setMessage(message, true);
    auto listItemWidget = new QListWidgetItem();
    listItemWidget->setSizeHint(QSize(0,90));
    ui->lstMessages->addItem(listItemWidget);
    listItemWidget->setBackground(QColor(100, 100, 100));
    ui->lstMessages->setItemWidget(listItemWidget, chatWidget);
}

void MainWindow::on_lnMessage_returnPressed()
{
    if(ui->lnMessage->text() == ""){
        return;
    }

    auto message = ui->lnClientName->text() + ":\n" +ui->lnMessage->text().trimmed();
    _client->sendMessage(message, ui->cmbDestination->currentText());
    //ui->lstMessages->addItem(message);

    ui->lnMessage->setText("");
    auto chatWidget = new ChatItemWidget(this);
    chatWidget->setMessage(message, true);
    auto listItemWidget = new QListWidgetItem();
    listItemWidget->setSizeHint(QSize(0,90));
    ui->lstMessages->addItem(listItemWidget);
    listItemWidget->setBackground(QColor(100, 100, 100));
    ui->lstMessages->setItemWidget(listItemWidget, chatWidget);
}

void MainWindow::on_lnClientName_editingFinished()
{
    auto name = ui->lnClientName->text().trimmed();
    _client->sendName(name);
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    auto status = (ChatProtocol::Status)index;
    _client->sendStatus(status);
}

void MainWindow::onTyping()
{
    statusBar()->showMessage("Server is typing...", 750);
}

void MainWindow::on_btnSendFile_clicked()
{
    auto fileName = QFileDialog::getOpenFileName(this, "Select a File", "/home");
    _client->sendInitSendingFile(fileName);
}

void MainWindow::onRejectReceivingFile()
{
    QMessageBox::critical(this, "Sending file", "Operation rejected");
}

void MainWindow::onInitReceivingFile(QString clientName, QString fileName, qint64 fileSize)
{
    auto message = QString("Client %1 wants to send a file. Accept?\nFile name: %2\nFile size: %3 bytes")
                       .arg(clientName, fileName).arg(fileSize);
    auto result =  QMessageBox::question(this, "Receiving file", message);
    if(result == QMessageBox::Yes){
        _client->sendAcceptFile();
    }
    else{
        _client->sendRejectFile();
    }
}

void MainWindow::on_lnMessage_textChanged(const QString &arg1)
{
    ui->btnSend->setEnabled(arg1.trimmed().length() > 0);
    _client->sendIsTyping();
}

void MainWindow::onConnectionACK(QString myName, QStringList clientsName)
{
    ui->cmbDestination->clear();
    clientsName.prepend("All");
    clientsName.prepend("Server");
    clientsName.prepend("None");    
    foreach (auto client, clientsName) {
        if(client != "Server"){
            ui->cmbDestination->addItem(client);
        }
    }
    setWindowTitle(myName);
}

void MainWindow::onNewClientConnectedToServer(QString clienName)
{

    ui->cmbDestination->addItem(clienName);
}

void MainWindow::onClientNameChanged(QString prevName, QString clientName)
{
    for (int i = 0; i < ui->cmbDestination->count(); ++i) {
        if (ui->cmbDestination->itemText(i) == prevName) {
            ui->cmbDestination->setItemText(i, clientName);
            return;
        }
    }
}

void MainWindow::onClientDisconnected(QString clientName)
{
    for (int i = 0; i < ui->cmbDestination->count(); ++i) {
        if (ui->cmbDestination->itemText(i) == clientName) {
            ui->cmbDestination->removeItem(i);
            return;
        }
    }
}

void MainWindow::on_cmbDestination_currentIndexChanged(int index)
{
    if(index == 0){
        ui->lnMessage->setEnabled(false);
        ui->btnSend->setEnabled(false);
    }
    else{
        ui->lnMessage->setEnabled(true);
        ui->btnSend->setEnabled(true);
    }
}

void MainWindow::on_btnLogin_clicked()
{
    _client->connectToServer();
    auto name = ui->lnClientName->text().trimmed();
    _client->sendName(name);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_btnExit_clicked()
{
    _client->disconnectFromServer();
    _client->deleteLater();
    ui->stackedWidget->setCurrentIndex(0);
    ui->lnClientName->clear();
}


void MainWindow::on_lnClientName_returnPressed()
{
    ui->stackedWidget->setCurrentIndex(1);
}

