#include "db.h"

DB::DB()
{
    createDB();
}

QStringList DB::isListContur()
{
    QStringList out;
    QString str = "SELECT name FROM contur";
    QSqlQuery query;
    if (query.exec(str)){
          while (query.next()){
              out << query.value(0).toString();
          }
    } else{
        qDebug() << query.lastError();
    }
    return out;
}

void DB::createDB()
{
    QString str = "SELECT version FROM version";
    QSqlQuery query;
    if (query.exec(str)){
        return;
    }

    QStringList db_sql_struct_list,db_sql_data_list;
    db_sql_struct_list << "CREATE TABLE version("
                          "version varchar(5))"
                       << "CREATE TABLE contur( "
                          "name varchar(30))";


    db_sql_data_list << "INSERT INTO version(version) VALUES ('00.01') "
                     << "INSERT INTO contur(name) VALUES ('TEST') ";


    for (int i=0;i<db_sql_struct_list.count();i++){
        if (!query.exec(db_sql_struct_list[i])){
            qDebug() << "db_sql_struct_list" << query.lastError();
        }
    }

    for (int i=0;i<db_sql_data_list.count();i++){
        if (!query.exec(db_sql_data_list[i])){
            qDebug() << "db_sql_data_list" << query.lastError();
        }
    }

}

