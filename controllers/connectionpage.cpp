#include "connectionpage.h"
#include "ui_connectionpage.h"

#include <QMessageBox>

ConnectionPage::ConnectionPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConnectionPage)
{
    ui->setupUi(this);
}

ConnectionPage::~ConnectionPage()
{
    delete ui;
}

void ConnectionPage::on_connectBtn_clicked()
{
    if(isConnected){
        emit disconnectClicked();
    }else if(ui->serverIpTb->text() == ""){
        QMessageBox *message = new QMessageBox();
        message->setText("Server address is emtpy");
        message->setWindowTitle("Error!");
        message->show();
    }else {
        emit connectClicked(ui->serverIpTb->text());
    }
}

void ConnectionPage::onConnectionStatusChanged(bool isConnected)
{
    if(isConnected){
        ui->connectBtn->setText("Disconnect");
    }else {
        ui->connectBtn->setText("Connect");
    }

    this->isConnected = isConnected;
}
