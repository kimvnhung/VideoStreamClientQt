#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "utility/utility.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   connect(ui->connectionPage, SIGNAL(connectClicked(QString)), this, SLOT(onConnectionClicked(QString)));
   connect(ui->connectionPage, SIGNAL(disconnectClicked()), this, SLOT(onDisconnectionClicked()));

   connect(ui->displayPage, SIGNAL(startStreamClicked()), this, SLOT(onStartStreamClicked()));
   connect(ui->displayPage, SIGNAL(stopStreamClicked()), this, SLOT(onStopStreamClicked()));
   connect(ui->displayPage, SIGNAL(startTrackingClicked(TrackingInformation)), this, SLOT(onStartTrackingClicked(TrackingInformation)));
   connect(ui->displayPage, SIGNAL(stopTrackingClicked()), this, SLOT(onStopTrackingClicked()));

   connect(this, SIGNAL(onStreamStarted()), ui->displayPage, SLOT(onStreamStarted()));
   connect(this, SIGNAL(connectionChanged(bool)), ui->connectionPage, SLOT(onConnectionStatusChanged(bool)));
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
    Command *cmd = new Command();
    cmd->set_header(Command_Header::Command_Header_ESTABLISH_CONNECTION);
    Address addr;
    addr.set_ip(client->getCurrentServer().toUtf8());
    addr.set_port(2020);
    cmd->mutable_payload()->PackFrom(addr);
    if(isConnected){
        qDebug()<<"onConnectionStatusChanged";
        client->sendData(ProtobufHelper::EncodeProtobufMessage(cmd->SerializeAsString().c_str(),cmd->ByteSize()));
    }else {
        ui->stackedWidget->setCurrentIndex(0);
    }

    emit connectionChanged(isConnected);
}

void MainWindow::onStartStreamClicked()
{
    Command *cmd = new Command();
    cmd->set_header(Command_Header::Command_Header_START_STREAM);

    VideoSource source;
    source.set_path("D:\\hungkv2\\StreamVideo\\drap videos\\test_video_60fps_720p.mp4");

    //cmd->set_path("D:\\hungkv2\\StreamVideo\\drap videos\\test_video_60fps_720p.mp4");
    //cmd->set_path("D:\\hungkv2\\StreamVideo\\drap videos\\test-video_1m12s.mp4");

    cmd->mutable_payload()->PackFrom(source);
    client->sendData(ProtobufHelper::EncodeProtobufMessage(cmd->SerializeAsString().c_str(),cmd->ByteSize()));

    qDebug()<<"sent";
}

void MainWindow::onStopStreamClicked()
{
    Command *cmd = new Command();
    cmd->set_header(Command_Header::Command_Header_STOP_STREAM);
    client->sendData(ProtobufHelper::EncodeProtobufMessage(cmd->SerializeAsString().c_str(),cmd->ByteSize()));
    qDebug()<<"sent";
}

void MainWindow::onStartTrackingClicked(TrackingInformation infor)
{
    Command *cmd = new Command();
    cmd->set_header(Command_Header::Command_Header_START_TRACKING);
    google::protobuf::Any payload;
    payload.PackFrom(infor);
    qDebug()<<"infor size :"<<infor.ByteSize();
    cmd->set_allocated_payload(&payload);
    qDebug()<<"start tracking length :"<<cmd->ByteSize();
    QByteArray arr = ProtobufHelper::EncodeProtobufMessage(cmd->SerializeAsString().c_str(),cmd->ByteSize());
    client->sendData(arr);

    Command *unpack = ProtobufHelper::ParseCommandFrom(arr.mid(2,cmd->ByteSize()));
    qDebug()<<(unpack->header()==Command_Header::Command_Header_START_TRACKING?"HEADER START_TRACKING":"Parse fail");
    TrackingInformation *unpackinfor = new TrackingInformation();
    if(cmd->payload().UnpackTo(unpackinfor)){
        qDebug()<<"Unpack successed!";
//        for(int i=0;i<unpackinfor->frame().data().size();i++){
//            qDebug()<<(int)unpackinfor->frame().data()[i];
//        }
    }
    qDebug()<<"sent";
}

void MainWindow::onStopTrackingClicked()
{
    Command *cmd = new Command();
    cmd->set_header(Command_Header::Command_Header_STOP_TRACKING);

    client->sendData(ProtobufHelper::EncodeProtobufMessage(cmd->SerializeAsString().c_str(),cmd->ByteSize()));
    qDebug()<<"sent";
}

void MainWindow::onHasNewPacket(const QByteArray arr)
{
    Command *cmd = ProtobufHelper::ParseCommandFrom(arr);
    qDebug()<<"onHasNewPacket";
    Reply *rep = new Reply();
    if(!cmd->payload().UnpackTo(rep)){
        qDebug()<<"Unpack fail";
    }else {
        qDebug()<<rep->description().c_str();
        switch (cmd->header()) {
        case Command_Header::Command_Header_UNKNOWN_HEADER:
            break;
        case Command_Header::Command_Header_ESTABLISH_CONNECTION:
            if(rep->status()  == Reply_Status::Reply_Status_SUCCESS){
                ui->stackedWidget->setCurrentIndex(1);
            }
            break;
        case Command_Header::Command_Header_STOP_TRACKING:
            break;
        case Command_Header::Command_Header_START_STREAM:
            if(rep->status() == Reply_Status::Reply_Status_SUCCESS){
                emit onStreamStarted();
            }
            break;
        case Command_Header::Command_Header_STOP_STREAM:
            if(rep->status() == Reply_Status::Reply_Status_SUCCESS){
                ui->stackedWidget->setCurrentIndex(0);
            }
            break;
        default:
            break;
        }
    }

}

