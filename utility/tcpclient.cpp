#include "tcpclient.h"

#define RECEIVE_BUFFER_MAX_LENGTH 8192  // bytes
#define TIMEOUT_WRITE 200
#define BEGINNING_OF_PACKET "\n\x04\b"

TCPClient::TCPClient(const QString &serverIp, quint16 serverPort) {
    this->hostName = serverIp;
    this->port = serverPort;

    clientSocket = new QTcpSocket(this);

    connect(clientSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));
    connect(clientSocket, SIGNAL(readyRead()), this, SLOT(processPacket()));
    connect(clientSocket, SIGNAL(disconnected()), this, SLOT(serverDisconnected()));
    connect(clientSocket, SIGNAL(connected()), this, SLOT(serverConnected()));
}

TCPClient::~TCPClient() {
    closeConnection();
    clientSocket->deleteLater();
    clientSocket = nullptr;
}

int TCPClient::getTimeoutAlive() const {
    return m_timeoutAlive;
}

void TCPClient::setTimeoutAlive(int timeoutAlive) {
    m_timeoutAlive = timeoutAlive;
}

QString TCPClient::getCurrentServer()
{
    return this->hostName;
}

bool TCPClient::isConnected() {
    if (clientSocket == nullptr) {
        return false;
    }
    QAbstractSocket::SocketState connectionState = clientSocket->state();
    return (connectionState == QAbstractSocket::ConnectedState);
}

void TCPClient::connectServer(const QString &serverIp, quint16 serverPort) {
    lastReceiveTime = QDateTime::currentDateTime();

    // Change connection when a connection exists.
    if (isConnected() == true) {
        // Ignore if the new server have same ip and port with current connection.
        if (hostName == serverIp and port == serverPort) {
            qDebug("Nothing changed. Same as the current connection.");
            return;
        } else {
            // Close current connection.
            closeConnection();
            qDebug() << "Close the current connection: " << hostName << " | " << port;
        }
    }

    // Validation input serverIp and serverPort.
    if (serverIp == nullptr || serverIp.trimmed() == "" || serverPort <= 0) {
        return;
    } else {
        hostName = serverIp;
        port = serverPort;
    }

    // Establishing new connection.
    clientSocket->connectToHost(hostName, port);

    // Set timeout connection 3s.
    //    if (clientSocket->waitForConnected(3000)) {
    //        qDebug() << "Connected to: " << hostName << ":" << port;
    //    }
}

void TCPClient::trackConnection() {
    QDateTime currentDate = QDateTime::currentDateTime();
    // Lifetime of an connection.
    qint64 deltaTime = lastReceiveTime.secsTo(currentDate);

    //     Check if after timeout alive time there is no packet (heartbeat) receieved, reconnect
    if (qAbs(deltaTime) > m_timeoutAlive) {
        qDebug() << QString("Connection timeout: %2s last = %3")
                        .arg(deltaTime)
                        .arg(lastReceiveTime.toString("mm:ss:zzz"));
        closeConnection();
    }

    if (isConnected() == false) {
        connectServer(hostName, port);
    }
}

void TCPClient::closeConnection() {
    if (clientSocket != nullptr) {
        clientSocket->close();
    }
}

void TCPClient::displayError(QAbstractSocket::SocketError socketError) {
    QString errorMsg;
    switch (socketError) {
        case QAbstractSocket::RemoteHostClosedError:
            errorMsg = "REMOTE HOST CLOSED ERROR..................... ";
            break;
        case QAbstractSocket::HostNotFoundError:
            errorMsg = "The host was not found. Please check the host name and port settings.";
            break;
        case QAbstractSocket::ConnectionRefusedError:
            errorMsg =
                "The connection was refused by the peer.";
            break;
        default:
            errorMsg = QString("The following error occurred: %1.").arg(clientSocket->errorString());
    }
    qDebug() << errorMsg;
    clientSocket->close();
    emit hasErrorMsg(errorMsg);
}

void TCPClient::serverConnected() {
    lastReceiveTime = QDateTime::currentDateTime();
    clientSocket->setSocketOption(QAbstractSocket::LowDelayOption, 1);
    qDebug() << QString("[%1]Connected to server: %2:%3")
                    .arg(lastReceiveTime.toString("hh:mm:ss"))
                    .arg(hostName)
                    .arg(port);
    emit connectionChanged(true);
}

void TCPClient::serverDisconnected() {
    qDebug() << "Disconnected to server";

    receiveBuffer.clear();  // clean buffer
    closeConnection();
    emit connectionChanged(false);
}

void TCPClient::sendData(const QByteArray &data) {
    if (isConnected()) {
        qDebug()<<"data size : "<<data.size();
        clientSocket->write(data);
        // Send any data which has not yet been sent.
        //        clientSocket->flush();
    }
}

/**
 * @brief TCPClient::sendDataSynchronous
 * @param data
 */
void TCPClient::sendDataAndWait(const QByteArray &data) {
    if (isConnected()) {
        qint64 numSentByte = clientSocket->write(data);

        // Send any data which has not yet been sent.
        //        clientSocket->flush();

        clientSocket->waitForBytesWritten(TIMEOUT_WRITE);

        if (numSentByte == -1) {
            qDebug() << "Data sending failed: "
                     << data;
        } else if (numSentByte != data.size()) {
            qDebug() << "Data sending incomplete: "
                     << data;
        } else
            qDebug() << "Data sent successfully: "
                     << data;
    }
}

qint32 byteToInt(QByteArray source) {
    qint32 temp;
    QDataStream data(&source, QIODevice::ReadWrite);
    data >> temp;
    return temp;
}

QByteArray TCPClient::getPacket() {
    // Find the beginning of protobuf packet.
    int startIndex = 0;
    if (startIndex < 0) {
        return QByteArray();
    }
    // Set default end of packet.
    int endIndex = receiveBuffer.length() - 1;
    // Check if there are more than one message were received.
    if (receiveBuffer.indexOf(BEGINNING_OF_PACKET, startIndex + 1) != -1) {
        // Re-set end index of protobuf packet.
        endIndex = receiveBuffer.indexOf(BEGINNING_OF_PACKET, startIndex + 1) - 1;
    }
    int packetLen = endIndex - startIndex + 1;
    // Pop/cut out message packet and refresh global receiveBuffer.
    QByteArray packet = receiveBuffer.mid(startIndex, packetLen);
    receiveBuffer = receiveBuffer.remove(startIndex, packetLen);
    //    receiveBuffer.clear();
    return packet;
}

void TCPClient::processPacket() {
    //    qDebug() << "Receive buffer : " << receiveBuffer.count() << lastReceiveTime.toString("mm:ss:zzz");
    //    qint64 deltaTime = lastReceiveTime.msecsTo(QDateTime::currentDateTime());
    //    qDebug("===== New packet last: %lld", deltaTime);

    lastReceiveTime = QDateTime::currentDateTime();
    // Clean receive buffer when data size larger than the max length.
    if (receiveBuffer.length() > RECEIVE_BUFFER_MAX_LENGTH) {
        // overflow
        receiveBuffer.clear();  // clean buffer
    }

    receiveBuffer += clientSocket->readAll();
    //    qDebug() << "Receive buffer : " << receiveBuffer.count() << lastReceiveTime.toString("mm:ss:zzz");

    QByteArray packet;
    while (true) {
        packet = getPacket();
        //qDebug() << "Packet : " << getHex(packet);
        if (packet.length() > 0) {
            //            qDebug() << "Receive new packet: " << packet;
            emit hasNewPacket(packet);
        } else {
            break;
        }
    }
}
