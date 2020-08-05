#include "mainwindow.h"

#include <QApplication>

void setGlobalSettings(){
    QCoreApplication::setApplicationName(QString("Pacie"));
    QCoreApplication::setOrganizationName(QString("Nick Martin"));
    QCoreApplication::setApplicationVersion(QString("1.0.0"));
    QCoreApplication::setOrganizationDomain(QString("com.monkeymantech.pacie"));
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    setGlobalSettings();
    MainWindow w;
    w.show();
    return a.exec();
}
