#include "mainwindow.h"
#include "ClientChatWidget.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupServer();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newClientConnect(QTcpSocket *client)
{
    auto id = client->property("id").toInt();
    ui->lstClients->addItem(QString("New Client connected: %1").arg(id));
    auto chatWidget = new ClientChatWidget(client);
    ui->tbChats->addTab(chatWidget, QString("Client %1").arg(id));

    connect(chatWidget, &ClientChatWidget::clientNameChanged, this, &MainWindow::setClientName);
    connect(chatWidget, &ClientChatWidget::statusChanged, this, &MainWindow::setClientStatus);
    connect(chatWidget, &ClientChatWidget::isTyping, [this](QString name){
        this->statusBar()->showMessage(name, 750);
    });
    connect(chatWidget, &ClientChatWidget::textForOtherClients, _server, &ServerManager::onTextForOtherClients);
}

void MainWindow::clientDisconnect(QTcpSocket *client)
{
    auto id = client->property("id").toInt();
    ui->lstClients->addItem(QString("Client disconnected: %1").arg(id));
    ui->tbChats->removeTab(id-1);
}

void MainWindow::setClientName(QString prevName, QString name)
{
    auto widget = qobject_cast<QWidget *>(sender());
    auto index = ui->tbChats->indexOf(widget);
    ui->tbChats->setTabText(index, name);
    _server->notifyOtherClients(prevName, name);
}

void MainWindow::setClientStatus(ChatProtocol::Status status)
{
    auto widget = qobject_cast<QWidget *>(sender());
    auto index = ui->tbChats->indexOf(widget);
    QString iconName = ":/icons/";
    switch (status) {
    case ChatProtocol::Available:
        iconName.append("available.png");
        break;
    case ChatProtocol::Away:
        iconName.append("away.png");
        break;
    case ChatProtocol::Busy:
        iconName.append("busy.png");
        break;
    default:
        iconName = "";
        break;
    }
    auto icon = QIcon(iconName);
    ui->tbChats->setTabIcon(index, icon);
}

void MainWindow::setupServer()
{
    _server = new ServerManager();
    ui->lstClients->addItem(QString("Server started at %1").arg(QDateTime::currentDateTime().toString()));
    connect(_server, &ServerManager::newClientConnected, this, &MainWindow::newClientConnect);
    connect(_server, &ServerManager::clientDisconnected, this, &MainWindow::clientDisconnect);
}


void MainWindow::on_tbChats_tabCloseRequested(int index)
{
    auto chatWidget = qobject_cast<ClientChatWidget*>(ui->tbChats->widget(index));
    chatWidget->disconnect();
    ui->tbChats->removeTab(index);
}


void MainWindow::on_btnDisconnectAll_clicked()
{
    foreach(auto cl, _server->clients()){
        cl->disconnectFromHost();
    }
}

