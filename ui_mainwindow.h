/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Wed Apr 15 14:28:04 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *actionOpenFile;
    QAction *actionLicenceAuthor;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_11;
    QLineEdit *XNULLlineEdit;
    QLineEdit *YNULLlineEdit;
    QLineEdit *RMINlineEdit;
    QLineEdit *RMAXlineEdit;
    QLineEdit *DRlineEdit;
    QLabel *label_16;
    QLineEdit *DRTlineEdit;
    QLabel *label_19;
    QLineEdit *RMAXTlineEdit;
    QLineEdit *RMINTlineEdit;
    QLabel *label_20;
    QLabel *label_21;
    QLineEdit *YSCATlineEdit;
    QLabel *label_18;
    QLineEdit *XSCATlineEdit;
    QLabel *label_17;
    QLineEdit *ANGLElineEdit;
    QLabel *label_6;
    QCheckBox *UseCheckBox;
    QComboBox *comboBox;
    QLabel *label_29;
    QWidget *Beam;
    QLineEdit *DELTASlineEdit;
    QLabel *label_13;
    QLineEdit *CADISTlineEdit;
    QLabel *label_15;
    QLabel *label_12;
    QLabel *label_14;
    QLineEdit *WAVElineEdit;
    QPushButton *BeamPushButton;
    QWidget *bla;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_10;
    QLineEdit *PIXELlineEdit;
    QLineEdit *XPIXFAlineEdit;
    QLineEdit *YPIXFAlineEdit;
    QLabel *label_22;
    QLabel *label_23;
    QLineEdit *IRECOAlineEdit;
    QLabel *label_24;
    QLineEdit *IRECOA2lineEdit;
    QLabel *label_25;
    QLineEdit *TUNEXPlineEdit;
    QLabel *label_26;
    QLineEdit *RADIlineEdit;
    QLabel *label_27;
    QLineEdit *SEPLAlineEdit;
    QLabel *label_28;
    QLineEdit *ISECTlineEdit;
    QPushButton *AdvPushButton;
    QPushButton *SECFIpushButton;
    QLineEdit *SECFIlineEdit;
    QLabel *picLabel;
    QListWidget *listWidget;
    QRadioButton *StartRadioButton;
    QRadioButton *EndRadioButton;
    QRadioButton *centerRadioButton;
    QLabel *label_30;
    QLabel *label_31;
    QLabel *XPIXlabel;
    QLabel *YPIXlabel;
    QLabel *XMMlabel;
    QLabel *YMMlabel;
    QPushButton *IntegratePushButton;
    QRadioButton *IntegrateAllRadioButton;
    QRadioButton *IntegrteUsableRadioButton;
    QRadioButton *IntegrateSelectedRadioButton;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuLicence;
    QStatusBar *statusbar;
    QButtonGroup *buttonGroup_2;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QString::fromUtf8("MainWindowClass"));
        MainWindowClass->resize(1186, 733);
        actionOpenFile = new QAction(MainWindowClass);
        actionOpenFile->setObjectName(QString::fromUtf8("actionOpenFile"));
        actionLicenceAuthor = new QAction(MainWindowClass);
        actionLicenceAuthor->setObjectName(QString::fromUtf8("actionLicenceAuthor"));
        centralwidget = new QWidget(MainWindowClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(980, 30, 191, 601));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setUsesScrollButtons(false);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 30, 61, 17));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 60, 61, 17));
        label_7 = new QLabel(tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 120, 61, 17));
        label_8 = new QLabel(tab);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 150, 41, 17));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 90, 161, 17));
        label_11 = new QLabel(tab);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 0, 151, 17));
        XNULLlineEdit = new QLineEdit(tab);
        XNULLlineEdit->setObjectName(QString::fromUtf8("XNULLlineEdit"));
        XNULLlineEdit->setGeometry(QRect(60, 30, 91, 21));
        YNULLlineEdit = new QLineEdit(tab);
        YNULLlineEdit->setObjectName(QString::fromUtf8("YNULLlineEdit"));
        YNULLlineEdit->setGeometry(QRect(60, 60, 91, 21));
        RMINlineEdit = new QLineEdit(tab);
        RMINlineEdit->setObjectName(QString::fromUtf8("RMINlineEdit"));
        RMINlineEdit->setGeometry(QRect(62, 120, 91, 22));
        RMAXlineEdit = new QLineEdit(tab);
        RMAXlineEdit->setObjectName(QString::fromUtf8("RMAXlineEdit"));
        RMAXlineEdit->setGeometry(QRect(62, 150, 91, 22));
        DRlineEdit = new QLineEdit(tab);
        DRlineEdit->setObjectName(QString::fromUtf8("DRlineEdit"));
        DRlineEdit->setGeometry(QRect(62, 180, 91, 22));
        label_16 = new QLabel(tab);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(10, 180, 41, 17));
        DRTlineEdit = new QLineEdit(tab);
        DRTlineEdit->setObjectName(QString::fromUtf8("DRTlineEdit"));
        DRTlineEdit->setGeometry(QRect(62, 270, 91, 22));
        label_19 = new QLabel(tab);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(10, 240, 51, 17));
        RMAXTlineEdit = new QLineEdit(tab);
        RMAXTlineEdit->setObjectName(QString::fromUtf8("RMAXTlineEdit"));
        RMAXTlineEdit->setGeometry(QRect(62, 240, 91, 22));
        RMINTlineEdit = new QLineEdit(tab);
        RMINTlineEdit->setObjectName(QString::fromUtf8("RMINTlineEdit"));
        RMINTlineEdit->setGeometry(QRect(62, 210, 91, 22));
        label_20 = new QLabel(tab);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(10, 270, 41, 17));
        label_21 = new QLabel(tab);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(10, 210, 61, 17));
        YSCATlineEdit = new QLineEdit(tab);
        YSCATlineEdit->setObjectName(QString::fromUtf8("YSCATlineEdit"));
        YSCATlineEdit->setGeometry(QRect(90, 400, 80, 20));
        YSCATlineEdit->setReadOnly(true);
        label_18 = new QLabel(tab);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(10, 400, 61, 17));
        XSCATlineEdit = new QLineEdit(tab);
        XSCATlineEdit->setObjectName(QString::fromUtf8("XSCATlineEdit"));
        XSCATlineEdit->setGeometry(QRect(92, 370, 80, 20));
        XSCATlineEdit->setReadOnly(true);
        label_17 = new QLabel(tab);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(10, 370, 61, 17));
        ANGLElineEdit = new QLineEdit(tab);
        ANGLElineEdit->setObjectName(QString::fromUtf8("ANGLElineEdit"));
        ANGLElineEdit->setGeometry(QRect(90, 430, 80, 20));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 430, 41, 17));
        UseCheckBox = new QCheckBox(tab);
        UseCheckBox->setObjectName(QString::fromUtf8("UseCheckBox"));
        UseCheckBox->setGeometry(QRect(10, 500, 87, 21));
        comboBox = new QComboBox(tab);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setEnabled(false);
        comboBox->setGeometry(QRect(30, 330, 151, 26));
        comboBox->setAcceptDrops(false);
        comboBox->setEditable(false);
        label_29 = new QLabel(tab);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(20, 300, 111, 17));
        tabWidget->addTab(tab, QString());
        Beam = new QWidget();
        Beam->setObjectName(QString::fromUtf8("Beam"));
        DELTASlineEdit = new QLineEdit(Beam);
        DELTASlineEdit->setObjectName(QString::fromUtf8("DELTASlineEdit"));
        DELTASlineEdit->setGeometry(QRect(92, 110, 91, 22));
        label_13 = new QLabel(Beam);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(20, 50, 61, 17));
        CADISTlineEdit = new QLineEdit(Beam);
        CADISTlineEdit->setObjectName(QString::fromUtf8("CADISTlineEdit"));
        CADISTlineEdit->setGeometry(QRect(90, 50, 91, 22));
        label_15 = new QLabel(Beam);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(20, 110, 61, 17));
        label_12 = new QLabel(Beam);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(20, 10, 141, 17));
        label_14 = new QLabel(Beam);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(12, 80, 71, 17));
        WAVElineEdit = new QLineEdit(Beam);
        WAVElineEdit->setObjectName(QString::fromUtf8("WAVElineEdit"));
        WAVElineEdit->setGeometry(QRect(90, 80, 91, 22));
        BeamPushButton = new QPushButton(Beam);
        BeamPushButton->setObjectName(QString::fromUtf8("BeamPushButton"));
        BeamPushButton->setGeometry(QRect(40, 160, 113, 32));
        tabWidget->addTab(Beam, QString());
        bla = new QWidget();
        bla->setObjectName(QString::fromUtf8("bla"));
        label_3 = new QLabel(bla);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 100, 61, 17));
        label = new QLabel(bla);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 71, 16));
        label_2 = new QLabel(bla);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 70, 61, 17));
        label_10 = new QLabel(bla);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 10, 131, 17));
        PIXELlineEdit = new QLineEdit(bla);
        PIXELlineEdit->setObjectName(QString::fromUtf8("PIXELlineEdit"));
        PIXELlineEdit->setGeometry(QRect(90, 40, 80, 20));
        XPIXFAlineEdit = new QLineEdit(bla);
        XPIXFAlineEdit->setObjectName(QString::fromUtf8("XPIXFAlineEdit"));
        XPIXFAlineEdit->setGeometry(QRect(92, 70, 80, 20));
        YPIXFAlineEdit = new QLineEdit(bla);
        YPIXFAlineEdit->setObjectName(QString::fromUtf8("YPIXFAlineEdit"));
        YPIXFAlineEdit->setGeometry(QRect(90, 100, 80, 20));
        label_22 = new QLabel(bla);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(10, 140, 61, 17));
        label_23 = new QLabel(bla);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(10, 170, 61, 17));
        IRECOAlineEdit = new QLineEdit(bla);
        IRECOAlineEdit->setObjectName(QString::fromUtf8("IRECOAlineEdit"));
        IRECOAlineEdit->setGeometry(QRect(80, 170, 91, 22));
        label_24 = new QLabel(bla);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(10, 200, 61, 17));
        IRECOA2lineEdit = new QLineEdit(bla);
        IRECOA2lineEdit->setObjectName(QString::fromUtf8("IRECOA2lineEdit"));
        IRECOA2lineEdit->setGeometry(QRect(80, 200, 91, 22));
        label_25 = new QLabel(bla);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(10, 230, 61, 17));
        TUNEXPlineEdit = new QLineEdit(bla);
        TUNEXPlineEdit->setObjectName(QString::fromUtf8("TUNEXPlineEdit"));
        TUNEXPlineEdit->setGeometry(QRect(80, 230, 91, 22));
        label_26 = new QLabel(bla);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(10, 260, 61, 17));
        RADIlineEdit = new QLineEdit(bla);
        RADIlineEdit->setObjectName(QString::fromUtf8("RADIlineEdit"));
        RADIlineEdit->setGeometry(QRect(80, 260, 91, 22));
        label_27 = new QLabel(bla);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(10, 290, 61, 17));
        SEPLAlineEdit = new QLineEdit(bla);
        SEPLAlineEdit->setObjectName(QString::fromUtf8("SEPLAlineEdit"));
        SEPLAlineEdit->setGeometry(QRect(80, 290, 91, 22));
        label_28 = new QLabel(bla);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(10, 320, 61, 17));
        ISECTlineEdit = new QLineEdit(bla);
        ISECTlineEdit->setObjectName(QString::fromUtf8("ISECTlineEdit"));
        ISECTlineEdit->setGeometry(QRect(80, 320, 91, 22));
        AdvPushButton = new QPushButton(bla);
        AdvPushButton->setObjectName(QString::fromUtf8("AdvPushButton"));
        AdvPushButton->setGeometry(QRect(70, 430, 113, 32));
        SECFIpushButton = new QPushButton(bla);
        SECFIpushButton->setObjectName(QString::fromUtf8("SECFIpushButton"));
        SECFIpushButton->setGeometry(QRect(32, 400, 151, 32));
        SECFIlineEdit = new QLineEdit(bla);
        SECFIlineEdit->setObjectName(QString::fromUtf8("SECFIlineEdit"));
        SECFIlineEdit->setGeometry(QRect(10, 360, 161, 22));
        tabWidget->addTab(bla, QString());
        picLabel = new QLabel(centralwidget);
        picLabel->setObjectName(QString::fromUtf8("picLabel"));
        picLabel->setGeometry(QRect(160, 30, 800, 600));
        picLabel->setCursor(QCursor(Qt::CrossCursor));
        picLabel->setMouseTracking(true);
        picLabel->setFrameShape(QFrame::Box);
        picLabel->setScaledContents(true);
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(20, 30, 121, 211));
        listWidget->setSelectionMode(QAbstractItemView::ContiguousSelection);
        StartRadioButton = new QRadioButton(centralwidget);
        buttonGroup = new QButtonGroup(MainWindowClass);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(StartRadioButton);
        StartRadioButton->setObjectName(QString::fromUtf8("StartRadioButton"));
        StartRadioButton->setGeometry(QRect(380, 650, 101, 21));
        EndRadioButton = new QRadioButton(centralwidget);
        buttonGroup->addButton(EndRadioButton);
        EndRadioButton->setObjectName(QString::fromUtf8("EndRadioButton"));
        EndRadioButton->setGeometry(QRect(490, 650, 101, 21));
        centerRadioButton = new QRadioButton(centralwidget);
        buttonGroup->addButton(centerRadioButton);
        centerRadioButton->setObjectName(QString::fromUtf8("centerRadioButton"));
        centerRadioButton->setGeometry(QRect(300, 650, 101, 21));
        centerRadioButton->setChecked(true);
        label_30 = new QLabel(centralwidget);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(740, 650, 81, 17));
        label_31 = new QLabel(centralwidget);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(740, 670, 81, 17));
        XPIXlabel = new QLabel(centralwidget);
        XPIXlabel->setObjectName(QString::fromUtf8("XPIXlabel"));
        XPIXlabel->setGeometry(QRect(830, 650, 61, 17));
        XPIXlabel->setFrameShape(QFrame::Box);
        YPIXlabel = new QLabel(centralwidget);
        YPIXlabel->setObjectName(QString::fromUtf8("YPIXlabel"));
        YPIXlabel->setGeometry(QRect(830, 670, 61, 17));
        YPIXlabel->setFrameShape(QFrame::Box);
        XMMlabel = new QLabel(centralwidget);
        XMMlabel->setObjectName(QString::fromUtf8("XMMlabel"));
        XMMlabel->setGeometry(QRect(900, 650, 61, 17));
        XMMlabel->setFrameShape(QFrame::Box);
        YMMlabel = new QLabel(centralwidget);
        YMMlabel->setObjectName(QString::fromUtf8("YMMlabel"));
        YMMlabel->setGeometry(QRect(900, 670, 61, 17));
        YMMlabel->setFrameShape(QFrame::Box);
        IntegratePushButton = new QPushButton(centralwidget);
        IntegratePushButton->setObjectName(QString::fromUtf8("IntegratePushButton"));
        IntegratePushButton->setGeometry(QRect(20, 360, 131, 32));
        IntegrateAllRadioButton = new QRadioButton(centralwidget);
        buttonGroup_2 = new QButtonGroup(MainWindowClass);
        buttonGroup_2->setObjectName(QString::fromUtf8("buttonGroup_2"));
        buttonGroup_2->addButton(IntegrateAllRadioButton);
        IntegrateAllRadioButton->setObjectName(QString::fromUtf8("IntegrateAllRadioButton"));
        IntegrateAllRadioButton->setGeometry(QRect(20, 260, 101, 21));
        IntegrateAllRadioButton->setChecked(false);
        IntegrteUsableRadioButton = new QRadioButton(centralwidget);
        buttonGroup_2->addButton(IntegrteUsableRadioButton);
        IntegrteUsableRadioButton->setObjectName(QString::fromUtf8("IntegrteUsableRadioButton"));
        IntegrteUsableRadioButton->setGeometry(QRect(20, 290, 101, 21));
        IntegrteUsableRadioButton->setChecked(true);
        IntegrateSelectedRadioButton = new QRadioButton(centralwidget);
        buttonGroup_2->addButton(IntegrateSelectedRadioButton);
        IntegrateSelectedRadioButton->setObjectName(QString::fromUtf8("IntegrateSelectedRadioButton"));
        IntegrateSelectedRadioButton->setGeometry(QRect(20, 320, 121, 21));
        MainWindowClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindowClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1186, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuLicence = new QMenu(menubar);
        menuLicence->setObjectName(QString::fromUtf8("menuLicence"));
        MainWindowClass->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindowClass->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuLicence->menuAction());
        menuFile->addAction(actionOpenFile);
        menuLicence->addAction(actionLicenceAuthor);

        retranslateUi(MainWindowClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionOpenFile->setText(QApplication::translate("MainWindowClass", "Open File(s)", 0, QApplication::UnicodeUTF8));
        actionLicenceAuthor->setText(QApplication::translate("MainWindowClass", "Licence&Author", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindowClass", "X-Null", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindowClass", "Y-Null", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindowClass", "RMIN", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindowClass", "RMAX", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindowClass", "Center correction", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindowClass", "Guess for the Center", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindowClass", "DR", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("MainWindowClass", "RMAXT", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("MainWindowClass", "DRT", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("MainWindowClass", "RMINT", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MainWindowClass", "YSCAT:", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MainWindowClass", "XSCAT:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindowClass", "Angle:", 0, QApplication::UnicodeUTF8));
        UseCheckBox->setText(QApplication::translate("MainWindowClass", "Usable", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindowClass", "Set points first", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindowClass", "Whole area", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindowClass", "Top", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindowClass", "Down", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindowClass", "Top-Down", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindowClass", "Right-Left", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindowClass", "Right", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindowClass", "Left", 0, QApplication::UnicodeUTF8)
        );
        label_29->setText(QApplication::translate("MainWindowClass", "Integration Style", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindowClass", "Parameter", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindowClass", "CADIST", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindowClass", "DELTAS", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindowClass", "Electron Beam Settings", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindowClass", "Wavelenght", 0, QApplication::UnicodeUTF8));
        BeamPushButton->setText(QApplication::translate("MainWindowClass", "Set for all ", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(Beam), QApplication::translate("MainWindowClass", "Beam", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindowClass", "Y-Scale:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindowClass", "Resolution:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindowClass", "X-Scale: ", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindowClass", "Settings for the Plate", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("MainWindowClass", "Misc", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("MainWindowClass", "IRECOA:", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("MainWindowClass", "IRECOA2:", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("MainWindowClass", "TUNEXP:", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("MainWindowClass", "RADI:", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("MainWindowClass", "SEPLA:", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("MainWindowClass", "ISECT:", 0, QApplication::UnicodeUTF8));
        AdvPushButton->setText(QApplication::translate("MainWindowClass", "Set for all", 0, QApplication::UnicodeUTF8));
        SECFIpushButton->setText(QApplication::translate("MainWindowClass", "Open sectorfile", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(bla), QApplication::translate("MainWindowClass", "Adv.", 0, QApplication::UnicodeUTF8));
        picLabel->setText(QString());
        StartRadioButton->setText(QApplication::translate("MainWindowClass", "Start Point", 0, QApplication::UnicodeUTF8));
        EndRadioButton->setText(QApplication::translate("MainWindowClass", "End Point", 0, QApplication::UnicodeUTF8));
        centerRadioButton->setText(QApplication::translate("MainWindowClass", "Center", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("MainWindowClass", "x [pix], [mm]:", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("MainWindowClass", "y [pix], [mm]:", 0, QApplication::UnicodeUTF8));
        XPIXlabel->setText(QString());
        YPIXlabel->setText(QString());
        XMMlabel->setText(QString());
        YMMlabel->setText(QString());
        IntegratePushButton->setText(QApplication::translate("MainWindowClass", "write inputfiles", 0, QApplication::UnicodeUTF8));
        IntegrateAllRadioButton->setText(QApplication::translate("MainWindowClass", "All", 0, QApplication::UnicodeUTF8));
        IntegrteUsableRadioButton->setText(QApplication::translate("MainWindowClass", "All usable", 0, QApplication::UnicodeUTF8));
        IntegrateSelectedRadioButton->setText(QApplication::translate("MainWindowClass", "Selected one(s)", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindowClass", "File", 0, QApplication::UnicodeUTF8));
        menuLicence->setTitle(QApplication::translate("MainWindowClass", "Licence", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
