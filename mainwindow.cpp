#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog.h"
#include "geditem.h"
#include "events.cpp"
#include <QFile>
#include <QImage>

MainWindowClass::MainWindowClass(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindowClass)
{
    ui->setupUi(this);
    ui->picLabel->installEventFilter(this); //installs the eventhandler do get the mousclicks on the pic
}

MainWindowClass::~MainWindowClass()
{
    delete ui;
}

void MainWindowClass::setValuesByMethod(QString method) {
    GEDItem *link = dynamic_cast <GEDItem*>(ui->listWidget->currentItem());
     // x1, y1 are the center coords, x2, y2 are the coords for the angle point
     float x1 = link->getXNULL().toFloat();
     float y1 = link->getYNULL().toFloat();
     float x2 = link->getxRMAXT().toFloat();
     float y2 = link->getyRMAXT().toFloat();
     if (method == "Whole area" ) {
         ui->XSCATlineEdit->setReadOnly(false);
         ui->YSCATlineEdit->setReadOnly(false);
         link->setMode(method);
         ui->XSCATlineEdit->setText(ui->RMAXTlineEdit->text());
         ui->YSCATlineEdit->setText(ui->RMAXTlineEdit->text());
         ui->ANGLElineEdit->setText(QString::number(0.0));
     } else if (method == "Right-Left" || method == "Left" || method == "Right") {
         ui->XSCATlineEdit->setText("0.0");
         ui->XSCATlineEdit->setReadOnly(true);
         ui->YSCATlineEdit->setReadOnly(false);
         ui->YSCATlineEdit->setText(ui->RMAXTlineEdit->text());
         link->setMode(method);
         float x3 = 0.0; // stupid
         // lets test it the user clicked left or right from the center for the angle point
         if (x1>x2) { // user clicked left
              x3 = x1-link->distance(x1, x2, y1, y2);
         } else { // right side
              x3 = x1+link->distance(x1, x2, y1, y2);
         }
         float y3 = y1;
         float angle = link->calcAngle(x1, y1, x2, y2, x3, y3);
         ui->ANGLElineEdit->setText(QString::number(angle));
     } else if (method == "Top-Down"|| method == "Top" || method == "Down") {
         ui->XSCATlineEdit->setReadOnly(false);
         ui->XSCATlineEdit->setText(ui->RMAXTlineEdit->text());
         ui->YSCATlineEdit->setText("0.0");
         ui->YSCATlineEdit->setReadOnly(true);
         link->setMode(method);
         float y3 = 0.0; // stupid
         //lets test if the user clicked under or above the center
         if (y1>y2) { // clicked above the center
              y3 = y1-link->distance(x1, x2, y1, y2);
         } else {
              y3 = y1 + link->distance(x1, x2, y1, y2);
         }
         float x3 = x1;
         float angle = link->calcAngle(x1, y1, x2, y2, x3, y3);
         ui->ANGLElineEdit->setText(QString::number(angle));
     } /*else if ( method == "Selected area" || method == "Set points first" || method == "Choose method") {
         ui->XSCATlineEdit->setReadOnly(false);
         ui->YSCATlineEdit->setReadOnly(false);
         ui->XSCATlineEdit->setText(ui->RMAXTlineEdit->text());
         ui->YSCATlineEdit->setText(ui->RMAXTlineEdit->text());
         link->setMode(method);
         float angle = link->calcAngle(link->getXNULL().toFloat(), link->getYNULL().toFloat(), link->getxRMAXT().toFloat(), link->getyRMAXT().toFloat(), link->getxAngle().toFloat(), link->getyAngle().toFloat());
         ui->ANGLElineEdit->setText(QString::number(angle));
     } */
 }

