#include "login.h"
#include "ui_login.h"
#include <QString>

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    this->setWindowTitle("登录");
    ui->label_5->setText("<h1>cwb图形化数据库管理系统</h1>");
    ui->label_5->setStyleSheet("background-color:PINK;");
    ui->lineEdit_key->setEchoMode(QLineEdit::Password);
}

login::~login()
{
    delete ui;
    delete w;
}

void login::on_pushButton_login_clicked()
{
    QString serverid=ui->lineEdit_serverid->text();
    QString id=ui->lineEdit_id->text();
    QString key=ui->lineEdit_key->text();
    QString type="QODBC3";
    QString mytable=ui->lineEdit_mytable->text();
    QSqlDatabase db=QSqlDatabase::addDatabase(type);
    //qDebug()<<"ODBC driver?"<<db.isValid();
    db.setHostName(serverid);//数据库服务器id
    db.setUserName(id);//用户名
    db.setPassword(key);//密码
    db.setDatabaseName("qttest_sql");//obdc数据源名称
    if(!db.open())
    {
        qDebug()<<db.lastError().text();
        QMessageBox::critical(this, QObject::tr("Database error"), db.lastError().text());
        return ;
    }
   // qDebug()<<"database open success!";
    w = new Widget();
   // qDebug()<<"database open success!";
    w->mySwitch(db,mytable);
   // qDebug()<<"database open success!";
    this->hide();
    w->show();
}
