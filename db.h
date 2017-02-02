#ifndef DB_H
#define DB_H
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>


class DB : public QObject
{
    Q_OBJECT
public:
    DB();
    QStringList isListContur();
private:
    void createDB();
};

#endif // DB_H
