#ifndef UTILITY_H
#define UTILITY_H

#include <QObject>
#include <QRgb>


class Utility
{
public:
    Utility();
    static bool writeToTextFile(QString filePath, QString content);
    static int32_t RGB32toInt32(QRgb color);

};

#endif // UTILITY_H
