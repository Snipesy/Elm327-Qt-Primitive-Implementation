#include <QCoreApplication>
#include "someclass.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Someclass *sc = new Someclass();


    return a.exec();
}
