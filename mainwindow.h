#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QSqlError>
#include "db.h"
#include "abstractlistmodelcheckable.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_cmBx_Contur_activated(const QString &arg1);

    void on_lstV_GroupServer_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    DB db;

};

#endif // MAINWINDOW_H
