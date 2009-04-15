/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Wed Apr 15 14:28:14 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindowClass[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      36,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x0a,
      47,   16,   16,   16, 0x0a,
      87,   82,   16,   16, 0x0a,
     131,   16,   16,   16, 0x0a,
     168,   16,   16,   16, 0x0a,
     206,   16,   16,   16, 0x0a,
     244,   16,   16,   16, 0x0a,
     282,   16,   16,   16, 0x0a,
     320,   16,   16,   16, 0x0a,
     358,   16,   16,   16, 0x0a,
     396,   16,   16,   16, 0x0a,
     434,   16,   16,   16, 0x0a,
     470,   16,   16,   16, 0x0a,
     506,   16,   16,   16, 0x0a,
     540,   16,   16,   16, 0x0a,
     578,   16,   16,   16, 0x0a,
     616,   16,   16,   16, 0x0a,
     651,   16,   16,   16, 0x0a,
     689,   16,   16,   16, 0x0a,
     725,   16,   16,   16, 0x0a,
     763,   16,   16,   16, 0x0a,
     799,   16,   16,   16, 0x0a,
     837,   16,   16,   16, 0x0a,
     875,   16,   16,   16, 0x0a,
     914,   16,   16,   16, 0x0a,
     951,   16,   16,   16, 0x0a,
     988,   16,   16,   16, 0x0a,
    1017,   16,   16,   16, 0x0a,
    1047,   16,   16,   16, 0x0a,
    1075,   16,   16,   16, 0x0a,
    1116,   16,   16,   16, 0x0a,
    1144,   16,   16,   16, 0x0a,
    1171,   16,   16,   16, 0x0a,
    1214, 1209, 1204,   16, 0x0a,
    1233, 1228,   16,   16, 0x0a,
    1271,   16,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindowClass[] = {
    "MainWindowClass\0\0on_actionOpenFile_triggered()\0"
    "on_actionLicenceAuthor_triggered()\0"
    "item\0on_listWidget_itemClicked(QListWidgetItem*)\0"
    "on_PIXELlineEdit_textEdited(QString)\0"
    "on_XPIXFAlineEdit_textEdited(QString)\0"
    "on_YPIXFAlineEdit_textEdited(QString)\0"
    "on_XSCATlineEdit_textChanged(QString)\0"
    "on_YSCATlineEdit_textChanged(QString)\0"
    "on_ANGLElineEdit_textChanged(QString)\0"
    "on_XNULLlineEdit_textChanged(QString)\0"
    "on_YNULLlineEdit_textChanged(QString)\0"
    "on_RMINlineEdit_textEdited(QString)\0"
    "on_RMAXlineEdit_textEdited(QString)\0"
    "on_DRlineEdit_textEdited(QString)\0"
    "on_RMINTlineEdit_textChanged(QString)\0"
    "on_RMAXTlineEdit_textChanged(QString)\0"
    "on_DRTlineEdit_textEdited(QString)\0"
    "on_TUNEXPlineEdit_textEdited(QString)\0"
    "on_RADIlineEdit_textEdited(QString)\0"
    "on_CADISTlineEdit_textEdited(QString)\0"
    "on_WAVElineEdit_textEdited(QString)\0"
    "on_DELTASlineEdit_textEdited(QString)\0"
    "on_IRECOAlineEdit_textEdited(QString)\0"
    "on_IRECOA2lineEdit_textEdited(QString)\0"
    "on_SEPLAlineEdit_textEdited(QString)\0"
    "on_ISECTlineEdit_textEdited(QString)\0"
    "on_UseCheckBox_clicked(bool)\0"
    "on_StartRadioButton_clicked()\0"
    "on_EndRadioButton_clicked()\0"
    "on_comboBox_currentIndexChanged(QString)\0"
    "on_BeamPushButton_pressed()\0"
    "on_AdvPushButton_pressed()\0"
    "on_IntegratePushButton_pressed()\0bool\0"
    "name\0isIn(QString)\0text\0"
    "on_SECFIlineEdit_textChanged(QString)\0"
    "on_SECFIpushButton_pressed()\0"
};

const QMetaObject MainWindowClass::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindowClass,
      qt_meta_data_MainWindowClass, 0 }
};

const QMetaObject *MainWindowClass::metaObject() const
{
    return &staticMetaObject;
}

void *MainWindowClass::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindowClass))
        return static_cast<void*>(const_cast< MainWindowClass*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindowClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_actionOpenFile_triggered(); break;
        case 1: on_actionLicenceAuthor_triggered(); break;
        case 2: on_listWidget_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: on_PIXELlineEdit_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: on_XPIXFAlineEdit_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: on_YPIXFAlineEdit_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: on_XSCATlineEdit_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: on_YSCATlineEdit_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: on_ANGLElineEdit_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: on_XNULLlineEdit_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: on_YNULLlineEdit_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: on_RMINlineEdit_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: on_RMAXlineEdit_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: on_DRlineEdit_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: on_RMINTlineEdit_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: on_RMAXTlineEdit_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: on_DRTlineEdit_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 17: on_TUNEXPlineEdit_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: on_RADIlineEdit_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: on_CADISTlineEdit_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 20: on_WAVElineEdit_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 21: on_DELTASlineEdit_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 22: on_IRECOAlineEdit_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 23: on_IRECOA2lineEdit_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 24: on_SEPLAlineEdit_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 25: on_ISECTlineEdit_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 26: on_UseCheckBox_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 27: on_StartRadioButton_clicked(); break;
        case 28: on_EndRadioButton_clicked(); break;
        case 29: on_comboBox_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 30: on_BeamPushButton_pressed(); break;
        case 31: on_AdvPushButton_pressed(); break;
        case 32: on_IntegratePushButton_pressed(); break;
        case 33: { bool _r = isIn((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 34: on_SECFIlineEdit_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 35: on_SECFIpushButton_pressed(); break;
        default: ;
        }
        _id -= 36;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
