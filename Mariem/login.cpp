#include "login.h"
#include "ui_login.h"
#include "login2.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QMessageBox>
#include <QSqlQuery>
#include <QRegExpValidator>
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_connecter_clicked()
{
    QString utilisateur = ui->lineEdit_utilisateur->text();
           QString password = ui->lineEdit_password->text();
           login2 login2(utilisateur,password);
          int test=login2.seconnect(utilisateur,password);

           if(test == 1){
               MainWindow *w=new MainWindow;


                this->hide();
               w->show();


               QMessageBox::information(nullptr,QObject::tr("Personnel ajouter"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
           }else{
               //ui->info->setStyleSheet( "QLabel { font-size: 9pt; color : red; }" );
               if(login2.checkuser()){
                   //ui->info->setText("Erreur : Vous avez entre un mot de passe incorrect");
                   ui->lineEdit_utilisateur->setStyleSheet( "QLineEdit{ border: 1px solid #414561;}QLineEdit:focus { border: 1px solid #828dff;}QLineEdit:hover{ border: 1px solid #828dff;}" );
               }else{
                  // ui->info->setText("Erreur : Vous avez entre un nom d'utulisateur incorrect");
                   ui->lineEdit_utilisateur->setStyleSheet( "QLineEdit{ border-width: 1px; border-style: solid; border-color: red; }QLineEdit:focus { border: 1px solid #828dff;}" );
               }
               ui->lineEdit_password->setStyleSheet( "QLineEdit{ border-width: 1px; border-style: solid; border-color: red; }QLineEdit:focus { border: 1px solid #828dff;}" );
               //QMessageBox::information(nullptr,QObject::tr("Personnel ajouter"),QObject::tr("Error!"),QMessageBox::Cancel);
           }


}


