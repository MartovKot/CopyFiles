#include "db.h"


DB::DB()
{
    createConnection();
}

//QSqlDatabase DB::getConnection()
//{
//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("db.sqlite3");
//    DB::dblink = db;
//    return dblink;
//}

//void DB::createConnection()
//{
////    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
////    db.setDatabaseName("db.sqlite3");
////    dblink = db;
//}
