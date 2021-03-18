#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

#include "utility/tcpclient.h"
#include "utility/protobufhelper.h"

#include "protobufs/Reply.pb.h"
#include "protobufs/Command.pb.h"
#include "protobufs/TrackingInformation.pb.h"
#include "protobufs/Address.pb.h"
#include "protobufs/VideoSource.pb.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void onStreamStarted();
    void connectionChanged(bool isConnected);

public slots:
    void onConnectionClicked(const QString &serverIp);
    void onDisconnectionClicked();
    void onConnectionStatusChanged(bool isConnected);

    void onStartStreamClicked();
    void onStopStreamClicked();
    void onStartTrackingClicked(TrackingInformation info);
    void onStopTrackingClicked();

    void onHasNewPacket(const QByteArray arr);
//void onServerReply(Repply *reply);

private:
    Ui::MainWindow *ui;
    TCPClient *client;

    bool isConnectionSuccessed = false;
};
#endif // MAINWINDOW_H
