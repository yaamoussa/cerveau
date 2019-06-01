/****************************************************************************
** Meta object code from reading C++ file 'temoin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../projet_se/temoin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'temoin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Temoin_t {
    QByteArrayData data[9];
    char stringdata0[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Temoin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Temoin_t qt_meta_stringdata_Temoin = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Temoin"
QT_MOC_LITERAL(1, 7, 19), // "situation_redacteur"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 6), // "numero"
QT_MOC_LITERAL(4, 35, 14), // "Etat_redacteur"
QT_MOC_LITERAL(5, 50, 4), // "etat"
QT_MOC_LITERAL(6, 55, 4), // "alea"
QT_MOC_LITERAL(7, 60, 17), // "situation_lecteur"
QT_MOC_LITERAL(8, 78, 12) // "Etat_lecteur"

    },
    "Temoin\0situation_redacteur\0\0numero\0"
    "Etat_redacteur\0etat\0alea\0situation_lecteur\0"
    "Etat_lecteur"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Temoin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   24,    2, 0x06 /* Public */,
       7,    3,   31,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4, QMetaType::Int,    3,    5,    6,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 8, QMetaType::Int,    3,    5,    6,

       0        // eod
};

void Temoin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Temoin *_t = static_cast<Temoin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->situation_redacteur((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Etat_redacteur(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->situation_lecteur((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Etat_lecteur(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Temoin::*_t)(int , Etat_redacteur , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Temoin::situation_redacteur)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Temoin::*_t)(int , Etat_lecteur , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Temoin::situation_lecteur)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Temoin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Temoin.data,
      qt_meta_data_Temoin,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Temoin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Temoin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Temoin.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Temoin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void Temoin::situation_redacteur(int _t1, Etat_redacteur _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Temoin::situation_lecteur(int _t1, Etat_lecteur _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
