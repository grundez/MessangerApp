#include "ChatItemWidget.h"
#include "ui_ChatItemWidget.h"

ChatItemWidget::ChatItemWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatItemWidget)
{
    ui->setupUi(this);
}

ChatItemWidget::~ChatItemWidget()
{
    delete ui;
}

void ChatItemWidget::setMessage(QString message, bool isMyMessage)
{
    if(isMyMessage){
        ui->lblMessage->setAlignment(Qt::AlignRight);
        ui->lblTime->setAlignment(Qt::AlignRight);
        ui->widget->setStyleSheet("background-color: rgb(200, 255, 200); border-radius: 41px solid;");
    }
    else{
        ui->widget->setStyleSheet("background-color: rgb(255, 255, 255); border-radius: 41px solid;");
    }
    ui->lblMessage->setText(message);
    ui->lblTime->setText(QDateTime::currentDateTime().toString("HH:mm"));
}
