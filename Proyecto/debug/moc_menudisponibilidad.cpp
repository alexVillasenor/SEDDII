/****************************************************************************
** Meta object code from reading C++ file 'menudisponibilidad.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../menudisponibilidad.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'menudisponibilidad.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MenuDisponibilidad_t {
    QByteArrayData data[15];
    char stringdata0[301];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MenuDisponibilidad_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MenuDisponibilidad_t qt_meta_stringdata_MenuDisponibilidad = {
    {
QT_MOC_LITERAL(0, 0, 18), // "MenuDisponibilidad"
QT_MOC_LITERAL(1, 19, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(4, 66, 29), // "on_comboBox_Carrera_activated"
QT_MOC_LITERAL(5, 96, 4), // "arg1"
QT_MOC_LITERAL(6, 101, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(7, 125, 27), // "on_tabWidget_currentChanged"
QT_MOC_LITERAL(8, 153, 5), // "index"
QT_MOC_LITERAL(9, 159, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(10, 183, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(11, 207, 23), // "on_pushButton_6_clicked"
QT_MOC_LITERAL(12, 231, 21), // "on_comboBox_activated"
QT_MOC_LITERAL(13, 253, 23), // "on_pushButton_7_clicked"
QT_MOC_LITERAL(14, 277, 23) // "on_pushButton_8_clicked"

    },
    "MenuDisponibilidad\0on_pushButton_clicked\0"
    "\0on_pushButton_2_clicked\0"
    "on_comboBox_Carrera_activated\0arg1\0"
    "on_pushButton_3_clicked\0"
    "on_tabWidget_currentChanged\0index\0"
    "on_pushButton_4_clicked\0on_pushButton_5_clicked\0"
    "on_pushButton_6_clicked\0on_comboBox_activated\0"
    "on_pushButton_7_clicked\0on_pushButton_8_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MenuDisponibilidad[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    1,   71,    2, 0x08 /* Private */,
       6,    0,   74,    2, 0x08 /* Private */,
       7,    1,   75,    2, 0x08 /* Private */,
       9,    0,   78,    2, 0x08 /* Private */,
      10,    0,   79,    2, 0x08 /* Private */,
      11,    0,   80,    2, 0x08 /* Private */,
      12,    1,   81,    2, 0x08 /* Private */,
      13,    0,   84,    2, 0x08 /* Private */,
      14,    0,   85,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MenuDisponibilidad::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MenuDisponibilidad *_t = static_cast<MenuDisponibilidad *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_pushButton_2_clicked(); break;
        case 2: _t->on_comboBox_Carrera_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_3_clicked(); break;
        case 4: _t->on_tabWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_pushButton_4_clicked(); break;
        case 6: _t->on_pushButton_5_clicked(); break;
        case 7: _t->on_pushButton_6_clicked(); break;
        case 8: _t->on_comboBox_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_pushButton_7_clicked(); break;
        case 10: _t->on_pushButton_8_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MenuDisponibilidad::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MenuDisponibilidad.data,
      qt_meta_data_MenuDisponibilidad,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MenuDisponibilidad::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MenuDisponibilidad::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MenuDisponibilidad.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MenuDisponibilidad::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
