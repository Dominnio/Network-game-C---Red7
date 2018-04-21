#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    QWidget* p = new QWidget();
    QPushButton* b = new QPushButton();
    b->setText("Dołącz");
    QHBoxLayout* pL = new QHBoxLayout(p);
    pL->addWidget(b);
    pL->setAlignment(Qt::AlignCenter);
    pL->setContentsMargins(0,0,0,0);
    p->setLayout(pL);

    ui->setupUi(this);

    ui->tableWidget_4->setCellWidget(0,5,p);

    connect(b,SIGNAL(clicked()),this,SLOT(handleButton()));

}
void MainWindow::handleButton()
{
    w.show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
