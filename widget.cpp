#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>//数据库驱动头文件
#include <QtDebug>
#include <QMessageBox>//报错消息
#include <QSqlQuery>//sql语句
#include <QSqlError>//获取sql报错
#include <QVariantList>//批量插入的表

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    this->setWindowTitle("管理界面");
    ui->setupUi(this);

    //db=QSqlDatabase::addDatabase("QODBC3");
    //qDebug()<<"ODBC driver?"<<db.isValid();
//    db.setHostName("DESKTOP-GQT7OMB");//数据库服务器id
//    db.setUserName(id);//用户名
//    db.setPassword(key);//密码
//    db.setDatabaseName("qttest_sql");//obdc数据源名称
//    if(!db.open())
//    {
//        qDebug()<<db.lastError().text();
//        QMessageBox::critical(this, QObject::tr("Database error"), db.lastError().text());
//        return ;
//    }
    //qDebug()<<"database open success!";
}

Widget::~Widget()
{
    delete ui;
    delete dialog;
    delete model;
    delete db;
}

void Widget::on_pushButton_delete_clicked()
{

    QItemSelectionModel *select=ui->tableView->selectionModel();
    QModelIndexList list= select->selectedRows();
    for(int i=0;i<list.size();i++)
    {
        model->removeRow(list.at(i).row());
    }
    QMessageBox::StandardButton res =QMessageBox::question(this,
                                                           "are you sure",
                                                           "是否删除",
                                                         QMessageBox::Yes|QMessageBox::No,
                                                          QMessageBox::No);
    if(res==QMessageBox::Yes)
    {
        model->submitAll();
    }
    else
    {
        model->revertAll();
    }
}



void Widget::on_pushButton_modify_clicked()
{
    QMessageBox::StandardButton res =QMessageBox::question(this,
                                                           "are you sure",
                                                           "是否保存修改",
                                                         QMessageBox::Yes|QMessageBox::No,
                                                          QMessageBox::No);
    if(res==QMessageBox::Yes)
    {
        model->submitAll();
    }
    else
    {
        model->revertAll();
    }
}

void Widget::on_pushButton_add_clicked()
{
    QSqlRecord new_record=model->record();
    int num=model->rowCount();
    model->insertRecord(num,new_record);
    model->submitAll();
}

void Widget::on_pushButton_find_clicked()
{
    QString sno = ui->lineEdit->text();
    model->setFilter("sno = '"+sno+"'");
    model->select();
}

void Widget::mySwitch(QSqlDatabase mydb,QString mytable)
{
    db=&mydb;
    QSqlQuery qurey(*db);
    model = new QSqlTableModel(this);
    model->setTable(mytable);
    //qDebug()<<db->lastError().text();
    ui->tableView->setModel(model);
    model->select();
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setHeaderData(0,Qt::Horizontal,"学号");
    model->setHeaderData(1,Qt::Horizontal,"姓名");
}
