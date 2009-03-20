/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Fri Mar 20 15:15:13 2009
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
      26,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x0a,
      52,   47,   16,   16, 0x0a,
      96,   16,   16,   16, 0x0a,
     133,   16,   16,   16, 0x0a,
     171,   16,   16,   16, 0x0a,
     209,   16,   16,   16, 0x0a,
     246,   16,   16,   16, 0x0a,
     283,   16,   16,   16, 0x0a,
     320,   16,   16,   16, 0x0a,
     358,   16,   16,   16, 0x0a,
     396,   16,   16,   16, 0x0a,
     432,   16,   16,   16, 0x0a,
     468,   16,   16,   16, 0x0a,
     502,   16,   16,   16, 0x0a,
     539,   16,   16,   16, 0x0a,
     576,   16,   16,   16, 0x0a,
     611,   16,   16,   16, 0x0a,
     649,   16,   16,   16, 0x0a,
     685,   16,   16,   16, 0x0a,
     723,   16,   16,   16, 0x0a,
     759,   16,   16,   16, 0x0a,
     797,   16,   16,   16, 0x0a,
     835,   16,   16,   16, 0x0a,
     874,   16,   16,   16, 0x0a,
     911,   16,   16,   16, 0x0a,
     948,   16,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindowClass[] = {
    "MainWindowClass\0\0on_actionOpenFile_triggered()\0"
    "item\0on_listWidget_itemClicked(QListWidgetItem*)\0"
    "on_PIXELlineEdit_textEdited(QString)\0"
    "on_XPIXFAlineEdit_textEdited(QString)\0"
    "on_YPIXFAlineEdit_textEdited(QString)\0"
    "on_XSCATlineEdit_textEdited(QString)\0"
    "on_YSCATlineEdit_textEdited(QString)\0"
    "on_ANGLElineEdit_textEdited(QString)\0"
    "on_XNULLlineEdit_textChanged(QString)\0"
    "on_YNULLlineEdit_textChanged(QString)\0"
    "on_RMINlineEdit_textEdited(QString)\0"
    "on_RMAXlineEdit_textEdited(QString)\0"
    "on_DRlineEdit_textEdited(QString)\0"
    "on_RMINTlineEdit_textEdited(QString)\0"
    "on_RMAXTlineEdit_textEdited(QString)\0"
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
        case 1: on_listWidget_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: on_PIXELlineEdit_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: on_XPIXFAlineEdit_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: on_YPIXFAlineEdit_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: on_XSCATlineEdit_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: on_YSCATlineEdit_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: on_ANGLElineEdit_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: on_XNULLlineEdit_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: on_YNULLlineEdit_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: on_RMINlineEdit_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: on_RMAXlineEdit_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: on_DRlineEdit_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: on_RMINTlineEdit_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: on_RMAXTlineEdit_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: on_DRTlineEdit_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: on_TUNEXPlineEdit_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 17: on_RADIlineEdit_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: on_CADISTlineEdit_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: on_WAVElineEdit_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 20: on_DELTASlineEdit_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 21: on_IRECOAlineEdit_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 22: on_IRECOA2lineEdit_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 23: on_SEPLAlineEdit_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 24: on_ISECTlineEdit_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 25: on_UseCheckBox_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 26;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
