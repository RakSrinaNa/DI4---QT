/****************************************************************************
** Meta object code from reading C++ file 'newpatientdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Projet/newpatientdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newpatientdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NewPatientDialog_t {
    QByteArrayData data[9];
    char stringdata0[178];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NewPatientDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NewPatientDialog_t qt_meta_stringdata_NewPatientDialog = {
    {
QT_MOC_LITERAL(0, 0, 16), // "NewPatientDialog"
QT_MOC_LITERAL(1, 17, 20), // "upperCase_textEdited"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 4), // "arg1"
QT_MOC_LITERAL(4, 44, 30), // "on_lastNameLineEdit_textEdited"
QT_MOC_LITERAL(5, 75, 31), // "on_firstNameLineEdit_textEdited"
QT_MOC_LITERAL(6, 107, 26), // "on_cityLineEdit_textEdited"
QT_MOC_LITERAL(7, 134, 19), // "on_okButton_clicked"
QT_MOC_LITERAL(8, 154, 23) // "on_cancelButton_clicked"

    },
    "NewPatientDialog\0upperCase_textEdited\0"
    "\0arg1\0on_lastNameLineEdit_textEdited\0"
    "on_firstNameLineEdit_textEdited\0"
    "on_cityLineEdit_textEdited\0"
    "on_okButton_clicked\0on_cancelButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NewPatientDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x08 /* Private */,
       4,    1,   47,    2, 0x08 /* Private */,
       5,    1,   50,    2, 0x08 /* Private */,
       6,    1,   53,    2, 0x08 /* Private */,
       7,    0,   56,    2, 0x08 /* Private */,
       8,    0,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void NewPatientDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NewPatientDialog *_t = static_cast<NewPatientDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->upperCase_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_lastNameLineEdit_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_firstNameLineEdit_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_cityLineEdit_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_okButton_clicked(); break;
        case 5: _t->on_cancelButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject NewPatientDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_NewPatientDialog.data,
      qt_meta_data_NewPatientDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NewPatientDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NewPatientDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NewPatientDialog.stringdata0))
        return static_cast<void*>(const_cast< NewPatientDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int NewPatientDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
