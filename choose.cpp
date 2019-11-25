#include "choose.h"
#include "ui_choose.h"
#include <QMessageBox>
#include<QDate>
#include <QComboBox>
#include "clients.h"
#include"articles.h"
#include <QSqlQuery>
#include <QVariant>

choose::choose(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::choose)
{
    ui->setupUi(this);
    ui->cin3->setValidator( new QIntValidator(0, 99999999, this) );
    ui->cinC_2->setValidator( new QIntValidator(0, 99999999, this) );
    ui->cinClient_1->setValidator( new QIntValidator(0, 99999999, this) );
    ui->telCient->setValidator( new QIntValidator(0, 99999999, this) );
    /*ui->cinClientR->setValidator( new QIntValidator(0, 99999999, this) );*/
    ui->liste_commande->setModel(tmpcommande.afficher());
    ui->liste_reclamation->setModel(tmpreclamations.afficher());
    ui->comboBox_2->setModel(tmparticles.afficherRef());
              ui->comboBox_3->setModel(tmparticles.afficherRef());

              ui->comboBox->setModel(tmpclients.afficherCin());

}

choose::~choose()
{
    delete ui;
}


void choose::on_ajoutClient_clicked(){}
void choose::on_ajouterArticle_clicked(){}
void choose::on_modifC_clicked(){}
void choose::on_annuC_clicked(){}
void choose::on_pushButton_15_clicked(){}
void choose::on_retourConnexion_clicked(){};
void choose::on_modifierR_clicked(){};
void choose::on_pushButton_14_clicked(){}
void choose::on_ajoutReclamations_clicked(){}

void choose::on_pushButton_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void choose::on_pushButton_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void choose::on_pushButton_12_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
}

void choose::on_retour_commande_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void choose::on_retour_reclamations_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void choose::on_retour_paiement_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}



void choose::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void choose::on_pushButton_4_clicked()
{ ui->snum->clear();

}




void choose::on_pushButton_13_clicked()
{
    ui->numeroc->clear();
      ui->dateEdit_2->clear();
     ui->montantc->clear();
}


/*******************************ajouter commande***********************************/

void choose::on_ajoutCommande_clicked()
{  if(ui->numeroc->text().isEmpty() || ui->dateEdit_2->text().isEmpty() || ui->montantc->text().isEmpty())
    { QMessageBox ok;
        ok.setWindowTitle("Erreur");
        ok.setText("Ajout échoué! Veuillez remplir tous les champs.");
        ok.setStandardButtons(QMessageBox::Ok);
        ok.exec();
        return;
    }

    int num= ui->numeroc->text().toInt();
    QDate dates= ui->dateEdit_2->date();
    double montant =ui->montantc->text().toDouble();
   commande c(num,dates,montant);
   if(c.rech(ui->numeroc->text().toInt())==true)
   { bool test=c.ajouter();
     ui->numeroc->clear();
     ui->dateEdit_2->clear();
    ui->montantc->clear();
    if(test)
  { ui->liste_commande->setModel(tmpcommande.afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("Ajouter une commande"),
                    QObject::tr("commande ajoutée.\n"
                                "Click OK to exit."), QMessageBox::ApplyRole);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter une commande"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
   }
   else
   {
       QMessageBox ok;
              ok.setWindowTitle("Notification");
              ok.setText("commande existe deja !");
              ok.setStandardButtons(QMessageBox::Ok);
              ok.exec();
   }
}



/********************************supprimer commande*******************************/

void choose::on_suprimerCommande_clicked()
{
    if(ui->supp_num->text().isEmpty()){
            QMessageBox ok;
            ok.setWindowTitle("Erreur");
            ok.setText("Suppression échoué! Veuillez remplir tous les champs.");
            ok.setStandardButtons(QMessageBox::Ok);
            ok.exec();
            return;
        }


    int num = ui->supp_num->text().toInt();
    bool test=tmpcommande.supprimer(num);
    ui->supp_num->clear();
    if(test)
    {ui->liste_commande->setModel(tmpcommande.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une commande"),
                    QObject::tr("commande supprimée.\n"
                                "Click OK to exit."), QMessageBox::ApplyRole);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une commande"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}




/*******************************modifier commande***********************************/

void choose::on_modifierCommande_clicked()
{  if(ui->lineEdit_22->text().isEmpty() || ui->dateEdit_5->text().isEmpty() || ui->lineEdit_24->text().isEmpty())
    { QMessageBox ok;
        ok.setWindowTitle("Erreur");
        ok.setText("modification échouée! Veuillez sélèctionner une commande.");
        ok.setStandardButtons(QMessageBox::Ok);
        ok.exec();
        return;
    }


    int num=ui->lineEdit_22->text().toInt();
        QDate dates= ui->dateEdit_5->date();
        double montant = ui->lineEdit_24->text().toDouble();
        commande c1;

            if(c1.rech(num)){
                bool test = c1.modifier(num,dates,montant);
                ui->lineEdit_22->clear();
                ui->dateEdit_5->clear();
               ui->lineEdit_24->clear();
                if(test){
                    ui->liste_commande->setModel(tmpcommande.afficher());
                    QMessageBox::information(nullptr, QObject::tr("Modifier une commande"),
                                QObject::tr("commande modifiée.\n"
                                            "Click OK to exit."), QMessageBox::ApplyRole);
                }
                else
                    QMessageBox::critical(nullptr, QObject::tr("Modifier une commande"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
            }
}

/********************************** trier commandes ******************************************/

void choose::on_trierCommande_clicked()
{
    commande c;

        if(c.triercommande()){

                ui->liste_commande->setModel(tmpcommande.triercommande());
                QMessageBox::information(nullptr, QObject::tr("trier les commandes"),
                            QObject::tr("commandes triées.\n"
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


/*******************************************table view*********************************************/
void choose::on_rechercheC_textChanged(const QString &arg1)
{  commande c;
    c.clearTable(ui->liste_commande);
    int mat=ui->rechercheC->text().toInt();
    c.searchRegexp(ui->liste_commande,mat);

}

void choose::on_liste_commande_activated(const QModelIndex &index)
{
    QString val=ui->liste_commande->model()->data(index).toString();
        QSqlQuery qry;
        qry.prepare("select * from comm where num='"+val+"'");

        if(qry.exec())
        {
            while(qry.next())
            {
                ui->lineEdit_22->setText(qry.value(0).toString());
                ui->dateEdit_5->setDate(qry.value(1).toDate());
                ui->lineEdit_24->setText(qry.value(2).toString());


            }
        }
        else{
            QMessageBox::critical(nullptr, QObject::tr("Big Error"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
}

/********************************ajouter réclamation***********************************/
void choose::on_ajoutReclamations_5_clicked()
{
    if(ui->numR->text().isEmpty() || ui->dateR->text().isEmpty())
       { QMessageBox ok;
           ok.setWindowTitle("Erreur");
           ok.setText("Ajout échoué! Veuillez remplir tous les champs.");
           ok.setStandardButtons(QMessageBox::Ok);
           ok.exec();
           return;
       }
       int num= ui->numR->text().toInt();
           QDate d =ui->dateR->date();
           int ref =ui->refA_R->text().toInt();
           int cin= ui->cin3->text().toInt();
           reclamations c(num,d,ref,cin);
           if(c.reche(ui->numR->text().toInt())==true)
           { bool test=c.ajouter();
             ui->numR->clear();
             ui->dateR->clear();
             ui->refA_R->clear();
            ui->cin3->clear();
            if(test)
          { ui->liste_reclamation->setModel(tmpreclamations.afficher());//refresh
          QMessageBox::information(nullptr, QObject::tr("Ajouter une reclamation"),
                            QObject::tr("reclamation ajoutée.\n"
                                        "Click OK to exit."), QMessageBox::ApplyRole);

          }
            else
                QMessageBox::critical(nullptr, QObject::tr("Ajouter une reclamation"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
           }
           else
           {
               QMessageBox ok;
                      ok.setWindowTitle("Notification");
                      ok.setText("reclamation existe deja !");
                      ok.setStandardButtons(QMessageBox::Ok);
                      ok.exec();
           }
}



void choose::on_suprimerReclamations_clicked()
{
    int num = ui->snum->text().toInt();
    bool test=tmpreclamations.supprimer(num);
    if(test)
    {ui->liste_reclamation->setModel(tmpreclamations.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une reclamation"),
                    QObject::tr("reclamation supprimée.\n"
                                "Click OK to exit."), QMessageBox::ApplyRole);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une reclamation"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}



void choose::on_modifierReclamations_clicked()
{
    int num=ui->numR_2->text().toInt();
        QDate d =ui->dateR_2->date();
        int ref=ui->refA_2->text().toInt();
        int cin=ui->cinC_2->text().toInt();

        reclamations r1;
         if(r1.reche(num)){
                bool test = r1.modifier(num,d,ref,cin);
                if(test)
                { ui->liste_reclamation->setModel(tmpreclamations.afficher());
                    QMessageBox::information(nullptr, QObject::tr("Modifier une réclamation"),
                                QObject::tr("réclamation modifiée.\n"
                                            "Click OK to exit."), QMessageBox::ApplyRole);
                }
                else
                    QMessageBox::critical(nullptr, QObject::tr("Modifier une réclamation"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
            }
}





void choose::on_trierReclamations_clicked()
{
    reclamations r;

        if(r.trierReclamation()){

                ui->liste_reclamation->setModel(tmpreclamations.trierReclamation());
                QMessageBox::information(nullptr, QObject::tr("trier les reclamations"),
                            QObject::tr("reclamations triées.\n"
                                        "Voulez-vous enregistrer les modifications ?"),
                                   QMessageBox::Save
                                   | QMessageBox::Cancel,
                                  QMessageBox::Save);

            }
            else
                QMessageBox::critical(nullptr, QObject::tr("trier les reclamations"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
}
/****************************table view reclamation*******************************************************/
void choose::on_lineEdit_7_textChanged(const QString &arg1)
{

}

void choose::on_pushButton_17_clicked()
{
    int cin= ui->cinClient_1->text().toInt();
        QString nom= ui->nomClient->text();
        QString prenom =ui->prenomClient->text();
         QString sexe =ui->sexeClient->currentText();
         int tel= ui->telCient->text().toInt();


       clients c(cin,nom,prenom,sexe,tel);
        bool test=c.ajouter();
        if(test)
      {
            ui->comboBox->setModel(tmpclients.afficherCin());

      QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                        QObject::tr("client ajouté.\n"
                                    "Click OK to exit."), QMessageBox::ApplyRole);


      }
        else
            QMessageBox::critical(nullptr, QObject::tr("Ajouter un client"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

}




void choose::on_tableClient_activated(const QModelIndex &index){}



void choose::on_pushButton_19_clicked()
{
    int ref= ui->refA_R->text().toInt();
         QString type =ui->typeA->currentText();
         QString marque= ui->marqueA->text();
         double prix= ui->prixA->text().toDouble();


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

void choose::on_comboBox_currentIndexChanged(const QString &arg1)
{ QString v=ui->comboBox->currentText();
    QSqlQuery qry;
    qry.prepare("select * from clients where cin='"+v+"'");
   if(qry.exec())
   { while (qry.next())
       {   ui->cin3->setText(qry.value(0).toString());
           ui->cinClient_1->setText(qry.value(0).toString());
           ui->nomClient->setText(qry.value(1).toString());
           ui->prenomClient->setText(qry.value(2).toString());
           ui->sexeClient->setCurrentText(qry.value(3).toString());
           ui->telCient->setText(qry.value(4).toString());

       }




    }
        else
            QMessageBox::critical(nullptr, QObject::tr("afficher un client"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);



}



void choose::on_pushButton_11_clicked()
{


}

void choose::on_modifiercommande_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void choose::on_comboBox_3_activated(const QString &arg1)
{

}

void choose::on_comboBox_3_currentIndexChanged(const QString &arg1)
{
    Articles a;
       a.clearTable(ui->table_articles);
    if ( int mat=ui->comboBox_3->currentText().toInt())
        a.searchRegexp(ui->table_articles,mat);

}

void choose::on_comboBox_2_currentIndexChanged(const QString &arg1)
{ QString v=ui->comboBox_2->currentText();
    QSqlQuery qry;
    qry.prepare("select * from arti where ref='"+v+"'");
   if(qry.exec())
   { while (qry.next())
       {   ui->ref3->setText(qry.value(0).toString());
           ui->refA_R->setText(qry.value(0).toString());
           ui->typeA->setCurrentText(qry.value(1).toString());
           ui->marqueA->setText(qry.value(2).toString());

           ui->prixA->setText(qry.value(3).toString());

       }




    }
        else
            QMessageBox::critical(nullptr, QObject::tr("afficher un article"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


}




