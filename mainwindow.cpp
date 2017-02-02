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
}

MainWindow::~MainWindow()
{
    delete ui;
}
