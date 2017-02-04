#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralWidget->setLayout(ui->mainLayout);
    ui->cmBx_Contur->addItems(db.isListContur());
//    ui->treeView->setModel();
//    ui->treeWidget
//=======
//    QSqlDatabase db = DB::getConnection();
//    qDebug() << db;
//    if (!db.isOpen()){
//        if (!db.open()) {
//            QMessageBox::critical(this,QObject::tr("Ошибка"),tr("База недоступна")+db.lastError().text());
//        }
//    }
//>>>>>>> 6758f0c4e79b3c329001ed45a31c19b4c26c27c6
}

MainWindow::~MainWindow()
{
    delete ui;
}
