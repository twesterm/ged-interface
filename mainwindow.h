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


    // all Callbacks are in events.cpp
 public slots:
     void on_actionOpenFile_triggered();
     void on_listWidget_itemClicked(QListWidgetItem *item);
     //slots for the signals comming from the lineEdits
     void on_PIXELlineEdit_textEdited(QString );
     void on_XPIXFAlineEdit_textEdited(QString );
     void on_YPIXFAlineEdit_textEdited(QString );
     void on_XSCATlineEdit_textEdited(QString );
     void on_YSCATlineEdit_textEdited(QString );
     void on_ANGLElineEdit_textEdited(QString );
     void on_XNULLlineEdit_textChanged(QString );
     void on_YNULLlineEdit_textChanged(QString );
     void on_RMINlineEdit_textEdited(QString );
     void on_RMAXlineEdit_textEdited(QString );
     void on_DRlineEdit_textEdited(QString );
     void on_RMINTlineEdit_textEdited(QString );
     void on_RMAXTlineEdit_textEdited(QString );
     void on_DRTlineEdit_textEdited(QString );
     void on_TUNEXPlineEdit_textEdited(QString );
     void on_RADIlineEdit_textEdited(QString );
     void on_CADISTlineEdit_textEdited(QString );
     void on_WAVElineEdit_textEdited(QString );
     void on_DELTASlineEdit_textEdited(QString );
     void on_IRECOAlineEdit_textEdited(QString );
     void on_IRECOA2lineEdit_textEdited(QString );
     void on_SEPLAlineEdit_textEdited(QString );
     void on_ISECTlineEdit_textEdited(QString );

private:
    Ui::MainWindowClass *ui;
};

#endif // MAINWINDOW_H
