#include "pidcurve.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PIDCurve w;
    w.show();

    return a.exec();
}
