/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Mon Mar 14 14:40:02 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   12,   11,   11, 0x08,
      32,   11,   11,   11, 0x28,
      47,   11,   11,   11, 0x08,
      61,   11,   11,   11, 0x08,
      76,   11,   11,   11, 0x08,
      96,   11,   11,   11, 0x08,
     118,   11,   11,   11, 0x08,
     139,   11,  132,   11, 0x08,
     151,   11,  132,   11, 0x08,
     164,   11,  132,   11, 0x08,
     176,   11,  132,   11, 0x08,
     190,   11,  132,   11, 0x08,
     200,   11,  132,   11, 0x08,
     214,   11,  132,   11, 0x08,
     231,   11,   11,   11, 0x08,
     240,   11,   11,   11, 0x08,
     250,   11,   11,   11, 0x08,
     264,   11,   11,   11, 0x08,
     271,   11,   11,   11, 0x08,
     286,   11,   11,   11, 0x08,
     311,   11,   11,   11, 0x08,
     340,   11,   11,   11, 0x08,
     364,   11,   11,   11, 0x08,
     380,   11,   11,   11, 0x08,
     394,   11,   11,   11, 0x08,
     417,  410,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0x\0inserirValor(int)\0"
    "inserirValor()\0buscarValor()\0"
    "removerValor()\0alinhamentoPadrao()\0"
    "alinhamentoCompleto()\0updateMenus()\0"
    "QBase*\0createBST()\0createTRIE()\0"
    "createAVL()\0createSPLAY()\0createB()\0"
    "createBPlus()\0createOpenHash()\0zoomIn()\0"
    "zoomOut()\0exportToPNG()\0save()\0"
    "abrirArquivo()\0configurarOrdemArvoreB()\0"
    "configurarOrdemArvoreBPlus()\0"
    "configurarTamanhoHash()\0configuracoes()\0"
    "exibirAbout()\0limparArvores()\0window\0"
    "setActiveSubWindow(QWidget*)\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: inserirValor((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: inserirValor(); break;
        case 2: buscarValor(); break;
        case 3: removerValor(); break;
        case 4: alinhamentoPadrao(); break;
        case 5: alinhamentoCompleto(); break;
        case 6: updateMenus(); break;
        case 7: { QBase* _r = createBST();
            if (_a[0]) *reinterpret_cast< QBase**>(_a[0]) = _r; }  break;
        case 8: { QBase* _r = createTRIE();
            if (_a[0]) *reinterpret_cast< QBase**>(_a[0]) = _r; }  break;
        case 9: { QBase* _r = createAVL();
            if (_a[0]) *reinterpret_cast< QBase**>(_a[0]) = _r; }  break;
        case 10: { QBase* _r = createSPLAY();
            if (_a[0]) *reinterpret_cast< QBase**>(_a[0]) = _r; }  break;
        case 11: { QBase* _r = createB();
            if (_a[0]) *reinterpret_cast< QBase**>(_a[0]) = _r; }  break;
        case 12: { QBase* _r = createBPlus();
            if (_a[0]) *reinterpret_cast< QBase**>(_a[0]) = _r; }  break;
        case 13: { QBase* _r = createOpenHash();
            if (_a[0]) *reinterpret_cast< QBase**>(_a[0]) = _r; }  break;
        case 14: zoomIn(); break;
        case 15: zoomOut(); break;
        case 16: exportToPNG(); break;
        case 17: save(); break;
        case 18: abrirArquivo(); break;
        case 19: configurarOrdemArvoreB(); break;
        case 20: configurarOrdemArvoreBPlus(); break;
        case 21: configurarTamanhoHash(); break;
        case 22: configuracoes(); break;
        case 23: exibirAbout(); break;
        case 24: limparArvores(); break;
        case 25: setActiveSubWindow((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 26;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
