#include "mainwindow.h"
#include "cipher.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //Cipher cript();

    return a.exec();
}
