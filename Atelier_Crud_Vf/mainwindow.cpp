#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fournisseur.h"
#include "commandeachat.h"
#include "articles.h"
#include "arduino.h"
#include <QMessageBox>
#include <QDate>
#include "mailing/SmtpMime"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
QPixmap pix("C:/Users/mohamed hichri/Desktop/pic.png");
ui->pic->setPixmap(pix);
ui->stackedWidget_2->setCurrentIndex(2);
animation =new QPropertyAnimation(ui->pb_ajouter, "geometry");
animation->setDuration(7000);
animation->setStartValue(QRect(250, 250, 0, 0));
animation->setEndValue(QRect(300, 300, 100, 30));

animation->start();
ui->tabfournisseu->setModel(tmpFournisseur.afficher());
ui->tableview->setModel(tmpc.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
    QPixmap pix("C:/Users/mohamed hichri/Desktop/pic.png");
    ui->labell->setPixmap(pix);


}
void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
   // QPixmap pix("C:/Users/mohamed hichri/Desktop/pic.png");
   // ui->label_22->setPixmap(pix);
}
void MainWindow::on_tabWidget_currentChanged(int index)
{
    ui->tabfournisseu->setModel(tmpFournisseur.afficher());
    ui->tableview->setModel(tmpc.afficher());
}

///////////////////////////////////////////////////////////fournisseur//////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::on_pb_ajouter_clicked()
{
    if(ui->lineEdit_num->text().isEmpty() || ui->lineEdit_nom->text().isEmpty() || ui->lineEdit_mail->text().isEmpty())
        { QMessageBox ok;
            ok.setWindowTitle("Erreur");
            ok.setText("ajout échouée! ");
            ok.setStandardButtons(QMessageBox::Ok);
            ok.exec();
            return;
        }
    bool trrr = false;
    int rating = ui->spinBox->text().toInt();
    long num = ui->lineEdit_num->text().toLong();
    QString nom= ui->lineEdit_nom->text();
    QString mail= ui->lineEdit_mail->text();

    for(int i=0;i<mail.size();i++)
    {
        if(mail[i] == '@' )
        {
            trrr = true;
        }
    }

  if(trrr)
  {
      Fournisseur e(num,nom,rating,mail);
      bool test=e.ajouter();
      if(test)
    {ui->tabfournisseu->setModel(tmpFournisseur.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter un fournisseur"),
                      QObject::tr("fournisseur ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un fournisseur"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
  }
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un fournisseur"),
                  QObject::tr("mail no valide !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}
void MainWindow::on_pb_supprimer_clicked()
{

    if(ui->lineEdit_id_2->text().isEmpty() )
        { QMessageBox ok;
            ok.setWindowTitle("Erreur");
            ok.setText("suppression échouée! ");
            ok.setStandardButtons(QMessageBox::Ok);
            ok.exec();
            return;
        }
    QString nom= ui->lineEdit_id_2->text();
    bool test=tmpFournisseur.supprimer(nom);

if(test)
{ui->tabfournisseu->setModel(tmpFournisseur.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un fournisseur"),
                QObject::tr("fournisseur supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("supprimer un fournisseur"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);//


}
void MainWindow::on_trierfournisseur_clicked()
{
   Fournisseur c;

        if(c.trier()){

                ui->tab_12->setModel(tmpFournisseur.trier());
                QMessageBox::information(nullptr, QObject::tr("trier les fournisseurs"),
                            QObject::tr("fournisseur triées.\n"
                                        "Voulez-vous enregistrer les modifications ?"),
                                   QMessageBox::Save
                                   | QMessageBox::Cancel,
                                  QMessageBox::Save);

            }
            else
                QMessageBox::critical(nullptr, QObject::tr("trier les fournisseur"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
}
void MainWindow::on_pushButton_9_clicked()
{
    if(ui->lineEdit_9->text().isEmpty() || ui->lineEdit_11->text().isEmpty() || ui->lineEdit_10->text().isEmpty())
        { QMessageBox ok;
            ok.setWindowTitle("Erreur");
            ok.setText("modification échouée");
            ok.setStandardButtons(QMessageBox::Ok);
            ok.exec();
            return;
        }
    QString nom = ui->lineEdit_9->text();
    QString mail = ui->lineEdit_11->text();
    long num = ui->lineEdit_10->text().toLong();
    int rating = ui->spinBox_2->text().toInt();
    Fournisseur f;
    if(f.rech(nom)){
        bool test = f.Modifier(num,nom,rating,mail);
        if(test){
            ui->tabfournisseu->setModel(tmpFournisseur.afficher());
            QMessageBox::information(nullptr,QObject::tr("fournisseur modifier"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
        }
    }
}
////////////////////////////////////////commandeachat//////////////////////////////////////////////////////////////////////////////////////////
  void MainWindow::on_pushButton_3_clicked()
{
      if(ui->lineEdit_3->text().isEmpty() || ui->lineEdit_2->text().isEmpty() || ui->lineEdit->text().isEmpty())
          { QMessageBox ok;
              ok.setWindowTitle("Erreur");
              ok.setText("ajout échouée");
              ok.setStandardButtons(QMessageBox::Ok);
              ok.exec();
              return;
          }
    float price = ui->lineEdit_3->text().toFloat();
    float weight = ui->lineEdit_2->text().toFloat();
    int num= ui->lineEdit->text().toInt();
    QDate datee= ui->dateEdit->date();
  commandeachat e(num,weight,price,datee);
  bool test=e.ajouter();
  if(test)
{ui->tableview->setModel(tmpc.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une commande"),
                  QObject::tr("commande ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une commande"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}
  void MainWindow::on_pushButton_4_clicked()
  {

      if(ui->lineEdit_5->text().isEmpty())
          { QMessageBox ok;
              ok.setWindowTitle("Erreur");
              ok.setText("suppresion échouée");
              ok.setStandardButtons(QMessageBox::Ok);
              ok.exec();
              return;
          }

      int num= ui->lineEdit_5->text().toInt();
      bool test=tmpc.supprimer(num);

  if(test)
  {ui->tableview->setModel(tmpc.afficher());//refresh
      QMessageBox::information(nullptr, QObject::tr("Supprimer une commande"),
                  QObject::tr("commande supprimé.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

  }
  else
      QMessageBox::critical(nullptr, QObject::tr("supprimer une commande"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);//


  }

  void MainWindow::on_pushButton_6_clicked()
  {
      if(ui->lineEdit_12->text().isEmpty() || ui->lineEdit_8->text().isEmpty() || ui->lineEdit_7->text().isEmpty()|| ui->lineEdit_13->text().isEmpty())
          { QMessageBox ok;
              ok.setWindowTitle("Erreur");
              ok.setText("modification échouée");
              ok.setStandardButtons(QMessageBox::Ok);
              ok.exec();
              return;
          }
      float price = ui->lineEdit_12->text().toFloat();
      float weight = ui->lineEdit_8->text().toFloat();
      int num= ui->lineEdit_7->text().toInt();
      QDate datee= ui->dateEdit->date();
      commandeachat e;
      if(e.rech(num)){
          bool test = e.Modifier(num,weight,price,datee);
          if(test){
              ui->tableview->setModel(tmpc.afficher());
              QMessageBox::information(nullptr,QObject::tr("commandeachat modifier"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
          }
      }}
  void MainWindow::on_pushButton_7_clicked()
  {
     commandeachat c;

          if(c.trier()){

                  ui->tableView_2->setModel(tmpc.trier());
                  QMessageBox::information(nullptr, QObject::tr("trier les commandes"),
                              QObject::tr("commande triées.\n"
                                          "Voulez-vous enregistrer les modifications ?"),
                                     QMessageBox::Save
                                     | QMessageBox::Cancel,
                                    QMessageBox::Save);

              }
              else
                  QMessageBox::critical(nullptr, QObject::tr("trier les commandes"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
  }




void MainWindow::on_recherche_textChanged(const QString &arg1)
{    commandeachat c;
     c.cleartable(ui->tableview);
     c.cleartable(ui->tab_article);
     int mat=ui->recherche->text().toInt();
     c.searchRegexp(ui->tableview,mat);
     c.searchRegexp2(ui->tab_article,mat);

}





void MainWindow::on_pushButton_5_clicked()
{int ref= ui->lineEdit_16->text().toInt();
    QString type =ui->lineEdit_17->text();
    QString marque= ui->lineEdit_14->text();
    double prix= ui->lineEdit_6->text().toDouble();


  Articles a(ref,type,marque,prix);
   bool test=a.ajouter();
   if(test)
 { ui->comboBox_2->setModel(tmparticles.afficherRef());
      ui->comboBox_3->setModel(tmparticles.afficherRef());
      //refresh
 QMessageBox::information(nullptr, QObject::tr("Ajouter un article"),
                   QObject::tr("article ajouté.\n"
                               "Click OK to exit."), QMessageBox::ApplyRole);


 }
   else
       QMessageBox::critical(nullptr, QObject::tr("Ajouter un article"),
                   QObject::tr("Erreur !.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_8_clicked()
{

          int ref=ui->comboBox_3->currentText().toInt();
          int num=ui->lineEdit->text().toInt();

        ui->tab_article->setModel(tmpc.affecter(num,ref));


}
