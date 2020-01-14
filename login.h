#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QString>
#include <QSqlDatabase>
#include <QtDebug>
#include <QMessageBox>//报错消息
#include <QSqlQuery>//sql语句
#include <QSqlError>//获取sql报错
#include <QVariantList>//批量插入的表
#include <QString>
#include "widget.h"
namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    //QSqlDatabase db=QSqlDatabase::addDatabase("QODBC3");
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_pushButton_login_clicked();


private:
    Ui::login *ui;
    Widget *w;
};

#endif // LOGIN_H
