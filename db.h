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
    QStringList isListGroupServer(const QString &name_contur);
    QStringList isListServers(const QString &name_contur, const QStringList &name_group);
private:
    void createDB();
};
#endif // DB_H
