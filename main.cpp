#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "db.h"
#include <QSqlDatabase>
#include <QFile>

static bool createConnection() //подключение к БД
{
    QString db_name;
    db_name = "db.sqlite3";
    QSqlDatabase dblink = QSqlDatabase::addDatabase("QSQLITE");
    dblink.setDatabaseName(db_name);

    if (dblink.driverName() == "QSQLITE"){
        QFile file(db_name);
        if (!file.exists()){
            if (file.open(QIODevice::WriteOnly)) {
                file.close();
            }else{ // не удалось создать/открыть файл
                qDebug() << "Файл не создан";
            }
        }
    }



    if (!dblink.isOpen()){
        if (!dblink.open()) {
            qDebug() << "Cannot open database:" << dblink.lastError();
            return false;
        }
        return false;
    }
    return true;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    createConnection();
    MainWindow w;
    w.show();

    return a.exec();
}
