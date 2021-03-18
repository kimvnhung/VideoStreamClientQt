#include "protobufhelper.h"
#include "QDebug"

ProtobufHelper::ProtobufHelper(QObject *parent) : QObject(parent)
{

}

QByteArray ProtobufHelper::GetQByteArrayFrom(const char* data,int size)
{
    return QByteArray(data,size);
}

QByteArray ProtobufHelper::EncodeProtobufMessage(const char* data, int size)
{
    char *encode = new char[size+4];

    strcpy((encode+2),data);
    encode[0] = 175;//10101 1111 - 0xAF
    encode[1] = 250;//1111 10101 - 0xFA
    encode[size+2] = ((size+4)%256);
    int sum = 0;
    for(int i = 0; i<size+3;i++){
        sum += encode[i];
        sum %= 256;
    }
    encode[size+3] = sum;
    qDebug()<<"sum : "<<sum;
    QByteArray rt(encode,size+4);
    int newsize = rt.size();
    //qDebug()
    return rt;
}

Command* ProtobufHelper::ParseCommandFrom(const QByteArray &data)
{
    Command *cmd = new Command();
    cmd->ParseFromArray(data,data.length());
    return cmd;
}

Reply* ProtobufHelper::ParseRepplyFrom(const QByteArray &data)
{
    Reply *rep = new Reply();
    rep->ParseFromArray(data,data.length());
    return  rep;
}
