#include "mainwindow.h"
#include <QApplication>
#include <QRandomGenerator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Путь к плагинам
    QCoreApplication::addLibraryPath("C:/Qt/6.5.1/mingw_64/plugins");
    QCoreApplication::addLibraryPath("C:/Qt/6.5.1/mingw_64/include/OpenSSL-Win64");
    //qDebug() << "Plugin paths:" << QCoreApplication::libraryPaths();

    // Проверка доступных драйверов базы данных
    //qDebug() << "Available SQL drivers:" << QSqlDatabase::drivers();
    MainWindow w;
    w.show();
    return a.exec();
}
