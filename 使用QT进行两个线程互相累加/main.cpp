#include <QCoreApplication>
#include "numcount.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    NumCount num1, num2;
    num1.start();
    num2.start();

    return a.exec();
}
