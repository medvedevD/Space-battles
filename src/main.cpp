#include "headers/components.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    components w;
    w.show();
    return a.exec();
}
