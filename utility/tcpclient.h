#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QDataStream>
#include <QDateTime>
#include <QTcpSocket>
#include <QThread>

#define CONNECTION_TIMEOUT 1000

class TCPClient : public QObject {
    Q_OBJECT
   public:
    TCPClient(const QString &serverIp, quint16 serverPort);
    ~TCPClient();

    int getTimeoutAlive() const;
    void setTimeoutAlive(int timeoutAlive);

   private:
    // server
    QString hostName;
    quint16 port;

    // socket
    QTcpSocket *clientSocket = nullptr;
    QByteArray receiveBuffer;

    // timeout
    int m_timeoutAlive = 2;

    // Datetime for connection tracking
    QDateTime lastReceiveTime;

    QByteArray getPacket();
    bool isConnected();

   public slots:

    void connectServer(const QString &serverIp, quint16 serverPort);
    void trackConnection();
    void closeConnection();

    void processPacket();
    void displayError(QAbstractSocket::SocketError socketError);
    void serverConnected();
    void serverDisconnected();

    void sendData(const QByteArray &data);
    void sendDataAndWait(const QByteArray &data);
   signals:
    void connectionChanged(bool isConnected);
    void hasNewPacket(const QByteArray &packet);
    void hasErrorMsg(const QString &errorMsg);
};

#endif  // TCPCLIENT_H
