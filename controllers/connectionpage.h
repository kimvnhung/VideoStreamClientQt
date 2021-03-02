#ifndef CONNECTIONPAGE_H
#define CONNECTIONPAGE_H

#include <QWidget>

namespace Ui {
class ConnectionPage;
}

class ConnectionPage : public QWidget
{
    Q_OBJECT

public:
    explicit ConnectionPage(QWidget *parent = nullptr);
    ~ConnectionPage();

signals:
    void connectClicked(const QString &serverIp);
    void disconnectClicked();
private slots:
    void on_connectBtn_clicked();
    void onConnectionStatusChanged(bool isConnected);

private:
    Ui::ConnectionPage *ui;
    bool isConnected = false;
};

#endif // CONNECTIONPAGE_H
