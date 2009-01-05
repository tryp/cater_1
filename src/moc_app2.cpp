/****************************************************************************
** Meta object code from reading C++ file 'app2.h'
**
** Created: Sun Jan 4 20:16:49 2009
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "app2.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'app2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_app2[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x08,
      16,    5,    5,    5, 0x08,
      28,    5,   23,    5, 0x08,
      35,    5,   23,    5, 0x08,
      44,    5,    5,    5, 0x08,
      52,    5,    5,    5, 0x08,
      74,    5,    5,    5, 0x08,
      83,    5,    5,    5, 0x08,
      93,    5,    5,    5, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_app2[] = {
    "app2\0\0newFile()\0open()\0bool\0save()\0"
    "saveAs()\0about()\0documentWasModified()\0"
    "zoomIn()\0zoomOut()\0newFeaturePoint()\0"
};

const QMetaObject app2::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_app2,
      qt_meta_data_app2, 0 }
};

const QMetaObject *app2::metaObject() const
{
    return &staticMetaObject;
}

void *app2::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_app2))
        return static_cast<void*>(const_cast< app2*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int app2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newFile(); break;
        case 1: open(); break;
        case 2: { bool _r = save();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: { bool _r = saveAs();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: about(); break;
        case 5: documentWasModified(); break;
        case 6: zoomIn(); break;
        case 7: zoomOut(); break;
        case 8: newFeaturePoint(); break;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
