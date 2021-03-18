#ifndef DISPLAYPAGE_H
#define DISPLAYPAGE_H

#include <QWidget>
#include <QMediaPlayer>
#include <QVideoProbe>
#include <QVideoFrame>

#include "protobufs/TrackingInformation.pb.h"

#include "utility/utility.h"

namespace Ui {
class DisplayPage;
}

class DisplayPage : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayPage(QWidget *parent = nullptr);
    ~DisplayPage();


    void onSelectObject(QMouseEvent *event);
signals:
    void startStreamClicked();
    void stopStreamClicked();
    void startTrackingClicked(TrackingInformation infor);
    void stopTrackingClicked();
private slots:
    void on_startStreamBtn_clicked();

    void on_stopStreamBtn_clicked();

    void onStreamStarted();

    void processFrame(const QVideoFrame &frame);


private:
    Ui::DisplayPage *ui;
    QMediaPlayer *mp = nullptr;
    QVideoProbe *probe = nullptr;
    int frameCounter = 0;
    QVideoFrame buffer;

    bool eventFilter(QObject *target, QEvent *event) override;
};

#endif // DISPLAYPAGE_H
