#include "mainwindow.h"

#include <QApplication>

QString R0_result;
QString Norma_result;
QString Long_Max_result;
QString Long_result;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("SanPin v.0.0.1");
    w.show();

    return a.exec();
}
