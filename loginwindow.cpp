#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "client.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWindow)
{
    client = new Client(this);
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_buttonLogin_clicked()
{
    w.show();
}

QPushButton* LoginWindow::getLoginButton()
{
    return ui->buttonLogin;
}
