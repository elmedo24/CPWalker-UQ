#include "cpwalker.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CPWalker w;
    w.show();

    return a.exec();
}
