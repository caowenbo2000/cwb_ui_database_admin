#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSqlTableModel>
#include <QString>
#include <iostream>
#include <string>
#include <QDialog>
#include <QMessageBox>
#include <QTableView>
#include <QSqlRecord>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlResult>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void mySwitch(QSqlDatabase mydb,QString mytable);

private slots:
    void on_pushButton_delete_clicked();
    void on_pushButton_modify_clicked();
    void on_pushButton_add_clicked();
    void on_pushButton_find_clicked();

private:
    Ui::Widget *ui;
    QDialog *dialog;
    QSqlTableModel *model;
    QSqlDatabase *db;

};

#endif // WIDGET_H
