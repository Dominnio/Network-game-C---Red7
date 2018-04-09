#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    ui->label_2->setVisible(false);
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->setVisible(false);
    ui->label_2->setVisible(true);
    while(getchar()!=13){;}

}
