#ifndef MAINWINDOWCLASS_H
#define MAINWINDOWCLASS_H

#include <QtGui/QMainWindow>
#include "ui_mainwindow.h"

/*namespace Ui
{
    class MainWindowClass;
} */

class MainWindowClass : public QMainWindow
{
    Q_OBJECT

public:
    MainWindowClass(QWidget *parent = 0);
    ~MainWindowClass();

 public slots:
     void on_actionOpenFile_triggered();
     void on_listWidget_itemClicked(QListWidgetItem *item);

private:
    Ui::MainWindowClass *ui;
};

#endif // MAINWINDOW_H
