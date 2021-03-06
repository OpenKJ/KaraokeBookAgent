#include "dialogabout.h"
#include "ui_dialogabout.h"
#include "version.h"

DialogAbout::DialogAbout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAbout)
{
    ui->setupUi(this);
    QString version = QString(VERSION_STRING);
    QString bldDate = QString(BUILD_DATE);
    ui->labelBuildDate->setText("Build date: " + bldDate);
    ui->labelVersion->setText("Version: " + version);
}

DialogAbout::~DialogAbout()
{
    delete ui;
}
