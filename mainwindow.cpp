#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog.h"
#include "geditem.h"
#include "events.cpp"
#include "qfile.h"
#include <qimage.h>

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


