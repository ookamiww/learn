#include <QCoreApplication>
#include <producer.h>
#include <consumer.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Producer p;
    Consumer c;

    p.start();
    c.start();

    return a.exec();
}
