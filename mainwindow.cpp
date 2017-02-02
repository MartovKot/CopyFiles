#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralWidget->setLayout(ui->mainLayout);
    QSqlDatabase db = DB::getConnection();
    qDebug() << db;
    if (!db.isOpen()){
        if (!db.open()) {
            QMessageBox::critical(this,QObject::tr("Ошибка"),tr("База недоступна")+db.lastError().text());
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
