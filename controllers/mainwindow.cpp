#include "mainwindow.h"
#include "ui_mainwindow.h"

Command_Header MainWindow::lastCommand = Command_Header::Command_Header_UNKNOWN_HEADER;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   connect(ui->connectionPage, SIGNAL(connectClicked(QString)), this, SLOT(onConnectionClicked(QString)));
   connect(ui->connectionPage, SIGNAL(disconnectClicked()), this, SLOT(onDisconnectionClicked()));

   connect(ui->displayPage, SIGNAL(startStreamClicked()), this, SLOT(onStartStreamClicked()));
   connect(ui->displayPage, SIGNAL(stopStreamClicked()), this, SLOT(onStopStreamClicked()));
   connect(ui->displayPage, SIGNAL(startTrackingClicked()), this, SLOT(onStartTrackingClicked()));
   connect(ui->displayPage, SIGNAL(stopTrackingClicked()), this, SLOT(onStopTrackingClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//slots
void MainWindow::onConnectionClicked(const QString &serverIp)
{
    if(client == nullptr){
        client = new TCPClient(serverIp,2021);
        connect(client, SIGNAL(connectionChanged(bool)), this, SLOT(onConnectionStatusChanged(bool)));
        connect(client, SIGNAL(connectionChanged(bool)), this, SLOT(onConnectionStatusChanged(bool)));
        connect(client, SIGNAL(hasNewPacket(QByteArray)), this, SLOT(onHasNewPacket(QByteArray)));
    }
    client->connectServer(serverIp,2021);

}

void MainWindow::onDisconnectionClicked()
{
    if(client != nullptr){
        client->closeConnection();
    }
}

void MainWindow::onConnectionStatusChanged(bool isConnected)
{
    if(isConnected){
        ui->stackedWidget->setCurrentIndex(1);
    }else {
        ui->stackedWidget->setCurrentIndex(2);
    }
}

void MainWindow::onStartStreamClicked()
{
    Command *cmd = new Command();
    cmd->set_header(Command_Header::Command_Header_START_STREAM);
    client->sendData(ProtobufHelper::getQByteArrayFrom(cmd->SerializeAsString().c_str(),cmd->ByteSize()));
    lastCommand = cmd->header();
    qDebug()<<"sent";
}

void MainWindow::onStopStreamClicked()
{
    Command *cmd = new Command();
    cmd->set_header(Command_Header::Command_Header_STOP_STREAM);
    client->sendData(ProtobufHelper::getQByteArrayFrom(cmd->SerializeAsString().c_str(),cmd->ByteSize()));
    lastCommand = cmd->header();
    qDebug()<<"sent";
}

void MainWindow::onStartTrackingClicked()
{
    Command *cmd = new Command();
    cmd->set_header(Command_Header::Command_Header_START_TRACKING);
    client->sendData(ProtobufHelper::getQByteArrayFrom(cmd->SerializeAsString().c_str(),cmd->ByteSize()));
    lastCommand = cmd->header();
    qDebug()<<"sent";
}

void MainWindow::onStopTrackingClicked()
{
    Command *cmd = new Command();
    cmd->set_header(Command_Header::Command_Header_STOP_TRACKING);

    client->sendData(ProtobufHelper::getQByteArrayFrom(cmd->SerializeAsString().c_str(),cmd->ByteSize()));
    lastCommand = cmd->header();
    qDebug()<<"sent";
}

void MainWindow::onHasNewPacket(const QByteArray arr)
{
    Reply *rep = ProtobufHelper::ParseRepplyFrom(arr);
    qDebug()<<rep->description().c_str();
    switch (rep->header()) {
    case Reply_Header::Reply_Header_START_STREAM:
        if(lastCommand == Command_Header::Command_Header_START_STREAM){

        }
        break;
    case Reply_Header::Reply_Header_STOP_STREAM:
        break;
    case Reply_Header::Reply_Header_START_TRACKING:
        break;
    case Reply_Header::Reply_Header_STOP_TRACKING:
        break;
    default:
        break;
    }
}

