#include "mainwindow.hpp"

#include <QApplication>
#include "application.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    application app{w.get(), &w};
    w.show();
    return a.exec();
}
