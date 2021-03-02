#ifndef DISPLAYPAGE_H
#define DISPLAYPAGE_H

#include <QWidget>
#include "protobufs/Command.pb.h"

namespace Ui {
class DisplayPage;
}

class DisplayPage : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayPage(QWidget *parent = nullptr);
    ~DisplayPage();

signals:
    void startStreamClicked();
    void stopStreamClicked();
    void startTrackingClicked();
    void stopTrackingClicked();
private slots:
    void on_startStreamBtn_clicked();

    void on_stopStreamBtn_clicked();

    void on_stopTrackingBtn_clicked();

    void on_startTrackingBtn_clicked();

private:
    Ui::DisplayPage *ui;
};

#endif // DISPLAYPAGE_H
