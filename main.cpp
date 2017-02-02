#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "db.h"
#include <QSqlDatabase>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QSqlDatabase db = DB::getConnection();
    qDebug() << db;
    w.show();

    return a.exec();
}
