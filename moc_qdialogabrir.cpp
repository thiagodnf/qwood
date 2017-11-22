/****************************************************************************
** Meta object code from reading C++ file 'qdialogabrir.h'
**
** Created: Mon Mar 14 14:40:04 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qdialogabrir.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qdialogabrir.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QDialogAbrir[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      32,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QDialogAbrir[] = {
    "QDialogAbrir\0\0procurarArquivo()\0"
    "accept()\0"
};

const QMetaObject QDialogAbrir::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_QDialogAbrir,
      qt_meta_data_QDialogAbrir, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QDialogAbrir::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QDialogAbrir::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QDialogAbrir::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QDialogAbrir))
        return static_cast<void*>(const_cast< QDialogAbrir*>(this));
    return QDialog::qt_metacast(_clname);
}

int QDialogAbrir::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: procurarArquivo(); break;
        case 1: accept(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
