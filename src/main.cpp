

#include <QApplication>
#include "app2.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(application);
    QApplication app(argc, argv);
    app2 * mw = new app2();
    mw->show();
    return app.exec();
}

