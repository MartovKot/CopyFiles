#ifndef DB_H
#define DB_H
#include <QSqlDatabase>
#include <QDebug>


class DB
{
public:
    DB();
    static QSqlDatabase getConnection();
private:
    static QSqlDatabase dblink;
    void createConnection();
};

QSqlDatabase DB::getConnection()
{
    return dblink;
}

void DB::createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("db.sqlite3");
    dblink = db;
}

#endif // DB_H
