#include "displaypage.h"
#include "ui_displaypage.h"

DisplayPage::DisplayPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisplayPage)
{
    ui->setupUi(this);
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

void DisplayPage::on_stopTrackingBtn_clicked()
{
    emit stopTrackingClicked();
}

void DisplayPage::on_startTrackingBtn_clicked()
{

    emit startTrackingClicked();
}
