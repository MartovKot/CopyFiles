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

QStringList DB::isListGroupServer(const QString &str1)
{
    QStringList out;
    QString str = "SELECT gs.name FROM servers as s "
                  "LEFT JOIN group_server as gs ON s.rowid_group = gs.rowid "
                  "LEFT JOIN contur as c ON s.rowid_contur = c.rowid "
                  "WHERE c.name = '%1' "
                  "GROUP BY gs.name";
    str = str.arg(str1);
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

QStringList DB::isListServers(const QString &name_contur, const QStringList &name_group)
{
    QString groups;
    for (int i=0;i<name_group.count();i++){
        groups += "'" + name_group.at(i) + "'";
        if (name_group.count() != i+1){
            groups += ",";
        }
    }
    QStringList out;
    QString str = "SELECT s.name FROM servers as s "
                  "LEFT JOIN group_server as gs ON s.rowid_group = gs.rowid "
                  "LEFT JOIN contur as c ON s.rowid_contur = c.rowid "
                  "WHERE c.name = '%1' "
                  "AND gs.name in (%2) ";

    str = str.arg(name_contur)
            .arg(groups);
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
                          "version varchar(5),"
                          "UNIQUE (version))"
                       << "CREATE TABLE contur( "
                          "name varchar(30),"
                          "UNIQUE (name))"
                       << "CREATE TABLE group_server("
                          "name varchar(30),"
                          "UNIQUE (name))"
                       << "CREATE TABLE servers("
                          "name varchar(30),"
                          "rowid_contur int,"
                          "rowid_group int,"
                          "UNIQUE (name))"
                          ;


    db_sql_data_list << "INSERT INTO version(version) VALUES ('00.06') "
                     << "INSERT INTO contur(name) VALUES ('TEST') "
                     << "INSERT INTO group_server(name) VALUES ('GROUP1')"
                     << "INSERT INTO group_server(name) VALUES ('GROUP2')"
                     << "INSERT INTO group_server(name) VALUES ('GROUP3')"
                     << "INSERT INTO group_server(name) VALUES ('GROUP4')"
                     << "INSERT INTO group_server(name) VALUES ('GROUP5')"
                     << "INSERT INTO group_server(name) VALUES ('GROUP6')"
                     << "INSERT INTO group_server(name) VALUES ('GROUP7')"
                     << "INSERT INTO group_server(name) VALUES ('GROUP8')"
                     << "INSERT INTO group_server(name) VALUES ('GROUP9')"
                     << "INSERT INTO group_server(name) VALUES ('GROUP10')"
                     << "INSERT INTO group_server(name) VALUES ('GROUP11')"
                     << "INSERT INTO group_server(name) VALUES ('GROUP12')"
                     << "INSERT INTO group_server(name) VALUES ('GROUP13')"
                     << "INSERT INTO group_server(name) VALUES ('GROUP14')"
                     << "INSERT INTO group_server(name) VALUES ('GROUP15')"
                     << "INSERT INTO servers(name,rowid_contur,rowid_group) VALUES('server1','1','1')"
                     << "INSERT INTO servers(name,rowid_contur,rowid_group) VALUES('server2','1','1')"
                     << "INSERT INTO servers(name,rowid_contur,rowid_group) VALUES('server3','1','2')"
                     << "INSERT INTO servers(name,rowid_contur,rowid_group) VALUES('server4','1','2')"
                     << "INSERT INTO servers(name,rowid_contur,rowid_group) VALUES('server5','1','3')"
                        ;


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
