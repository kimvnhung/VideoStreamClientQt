#include "utility.h"

#include <QFile>
#include <QTextStream>
#include <QColor>


Utility::Utility()
{

}

bool Utility::writeToTextFile(QString filePath, QString content)
{
    QFile qFile(filePath);
    if(qFile.open(QIODevice::WriteOnly)){
        QTextStream out(&qFile);
        out<<content;
        qFile.close();
        return true;
    }
    return false;
}

int32_t Utility::RGB32toInt32(QRgb rgb)
{
    QColor color(rgb);
    return (color.red()<<24)+(color.green()<<16)+(color.blue()<<8);
}
