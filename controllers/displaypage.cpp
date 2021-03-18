#include "displaypage.h"
#include "ui_displaypage.h"

DisplayPage::DisplayPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisplayPage)
{
    ui->setupUi(this);

    ui->videoDisplayer->installEventFilter(this);

}

DisplayPage::~DisplayPage()
{
    delete ui;
}

void DisplayPage::on_startStreamBtn_clicked()
{
    emit startStreamClicked();
}

void DisplayPage::on_stopStreamBtn_clicked()
{
    emit stopStreamClicked();
}


void DisplayPage::onStreamStarted()
{
    if(this->mp == nullptr){
        mp = new QMediaPlayer(this,QMediaPlayer::StreamPlayback);
        probe = new QVideoProbe();
        connect(probe, SIGNAL(videoFrameProbed(QVideoFrame)), this, SLOT(processFrame(QVideoFrame)));

        probe->setSource(mp);
        mp->setVideoOutput(ui->videoDisplayer);
        mp->setMedia(QUrl("rtsp://192.168.1.198:2020/test"));
    }
    mp->play();
}

void DisplayPage::processFrame(const QVideoFrame &frame)
{
//    if(frameCounter%12==0){
//        qDebug()<<"onReceiveFrame : "<<frameCounter;
//        qDebug()<<"Duration :"<<mp->duration();
//    }
    buffer = frame;
    frameCounter++;


}

bool DisplayPage::eventFilter(QObject *target, QEvent *event)
{
    if (target == ui->videoDisplayer) {
        if (event->type() == QMouseEvent::MouseButtonPress) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
            // Tracking mode
            if (mouseEvent->button() == Qt::LeftButton) {
                onSelectObject(mouseEvent);
            }
            return true;
        }
    }
    return false;
}


/*
max size for frame data is about 4300 bytes
*/
void DisplayPage::onSelectObject(QMouseEvent *event)
{

    int x = event->x();
    int y = event->y();

    Point *position = new Point();
    position->set_x(x);
    position->set_y(y);

    //convert frame to hex array
    QVideoFrame frame = buffer;
    //lock frame to memory
    frame.map(QAbstractVideoBuffer::MapMode::ReadOnly);

    qDebug()<<frame.pixelFormat();

    Image *image = new Image();
    qDebug()<<"bytesPerLine :"<<frame.bytesPerLine();

    //calculate total length
    int byteSize = frame.bytesPerLine()*frame.height();
    QByteArray arr((const char *)frame.bits(),byteSize);
    int edgeSize = 140;
    int cropSize = edgeSize*edgeSize*4;//kich thuoc 65*65 format RGB32 - 4bytes

    //x,y in pixels
    if( x < edgeSize/2 ){
        x = edgeSize/2;
    }
    if( y < edgeSize/2 ){
        y = edgeSize/2;
    }
    if( x > frame.width()-edgeSize/2 ){
        x = frame.width()-edgeSize/2;
    }
    if( y > frame.height() - edgeSize/2 ){
        y = frame.height() - edgeSize/2;
    }
    QRect rect(x-edgeSize/2,y-edgeSize/2,edgeSize,edgeSize);

    QImage img(frame.bits(),frame.width(),frame.height(),QImage::Format_RGB32);
    QImage crop = img.copy(rect);



    int pxSize = edgeSize*edgeSize;
    int32_t data[pxSize];
    for(int y = 0;y<edgeSize;y++){
        for(int x=0;x<edgeSize;x++){
            data[y*edgeSize+x] = Utility::RGB32toInt32(crop.pixel(x,y));
        }
    }

    for(int i=0;i<pxSize;i++){
        image->add_data(data[i]);
        //qDebug()<<data[i];
    }
    image->set_width(edgeSize);
    image->set_height(edgeSize);

    QImage rebuild(edgeSize,edgeSize,QImage::Format_RGB32);
    for(int x=0;x<edgeSize;x++){
        for(int y=0;y<edgeSize;y++){
            int32_t cl = data[y*edgeSize+x];
            unsigned char red = (cl&0xff000000)>>24;
            unsigned char green = (cl&0xff0000)>>16;
            unsigned char blue = (cl&0xff00)>>8;
            qDebug()<<red<<" "<<green<<" "<<blue;
            rebuild.setPixelColor(x,y,QColor(red,green,blue));
        }
    }



    ui->statusLb->setPixmap(QPixmap::fromImage(rebuild));




    frame.unmap();
    TrackingInformation info;
    qDebug()<<"infor size :"<<info.ByteSize();
    info.set_allocated_frame(image);
    qDebug()<<"infor size :"<<info.ByteSize();
    info.set_allocated_position(position);
    qDebug()<<"infor size :"<<info.ByteSize();
    emit startTrackingClicked(info);
}
