#include "mainwindow.h"
#include <QApplication>
#include <QHBoxLayout>
#include <QPushButton>
#include <QButtonGroup>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;
    window.show();

    return a.exec();
}
