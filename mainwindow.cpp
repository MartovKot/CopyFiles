#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralWidget->setLayout(ui->mainLayout);
    ui->cmBx_Contur->addItem("");
    ui->cmBx_Contur->addItems(db.isListContur());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_cmBx_Contur_activated(const QString &arg1)
{
    if (arg1 == ""){
        return;
    }

    AbstractListModelCheckable* model = new AbstractListModelCheckable;

    QVector<Item> items;
    QStringList list = db.isListGroupServer(arg1);
    if(list.count() == 0){
        return;
    }

    for (int i=0;i<list.count();i++){
        items.push_back(Item(list.at(i), Qt::Unchecked));
    }
    model->setItems(items);
    ui->lstV_GroupServer->setModel(model);
}

void MainWindow::on_lstV_GroupServer_clicked(const QModelIndex &index)
{
    QStringList groups;
    for (int i=0;i<ui->lstV_GroupServer->model()->rowCount();i++){
        if (ui->lstV_GroupServer->model()->index(i,0).data(Qt::CheckStateRole) == Qt::Checked){
            groups<<ui->lstV_GroupServer->model()->index(i,0).data().toString();
        }
    }

    AbstractListModelCheckable* model = new AbstractListModelCheckable;

    QVector<Item> items;
    QStringList list = db.isListServers(ui->cmBx_Contur->currentText(),groups);
    if(list.count() == 0){
        return;
    }

    for (int i=0;i<list.count();i++){
        items.push_back(Item(list.at(i), Qt::Checked));
    }
    model->setItems(items);

    ui->lstV_Servers->setModel(model);

}

void MainWindow::on_tBtn_OpenDir_clicked()
{
    QString dir;
    dir = QFileDialog::getExistingDirectory(this,
                                tr("Open Directory"),"C:\\",QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    ui->lEd_DirNameIn->setText(dir);
}
