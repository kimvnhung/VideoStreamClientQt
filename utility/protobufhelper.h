#ifndef PROTOBUFHELPER_H
#define PROTOBUFHELPER_H

#include <QObject>

#include "protobufs/Command.pb.h"
#include "protobufs/Reply.pb.h"

class ProtobufHelper : public QObject
{
    Q_OBJECT
public:
    explicit ProtobufHelper(QObject *parent = nullptr);
    static QByteArray getQByteArrayFrom(const char* data,int size);
    static Command* ParseCommandFrom(const QByteArray &data);
    static Reply* ParseRepplyFrom(const QByteArray &data);
signals:

public slots:
};

#endif // PROTOBUFHELPER_H
