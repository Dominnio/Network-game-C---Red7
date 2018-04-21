#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include "mainwindow.h"
#include "client.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = 0);
    QPushButton* getLoginButton();
    ~LoginWindow();

private slots:
    void on_buttonLogin_clicked();

private:
    Ui::LoginWindow *ui;
    MainWindow w;
    Client *client;
};

#endif // LOGINWINDOW_H
