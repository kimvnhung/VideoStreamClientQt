#include "protobufhelper.h"

ProtobufHelper::ProtobufHelper(QObject *parent) : QObject(parent)
{

}

QByteArray ProtobufHelper::getQByteArrayFrom(const char* data,int size)
{
    return QByteArray(data,size);
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
