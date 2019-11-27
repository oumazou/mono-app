#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employee.h"
#include "conge.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
     ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabemp->setModel(tmpemp.afficher());
    ui->tabcong->setModel(tmpcong.afficher());
    ui->lineEdit_faza_num->hide();
    ui->lineEdit_faza_id->hide();




             //Modifier Employee
    ui->pushButton_annuler->hide();
    ui->lineEdit_modif_nom->hide();
    ui->lineEdit_modif_prenom->hide();
    ui->lineEdit_modif_num->hide();
    ui->lineEdit_modif_adresse->hide();
    ui->lineEdit_modif_cnss->hide();
    ui->pushButton__modifier_emp->hide();
    ui->label_18->hide();
    ui->label_19->hide();
    ui->label_20->hide();
    ui->label_21->hide();
    ui->label_22->hide();
}

MainWindow::~MainWindow()
{
    delete ui;


}

void MainWindow::on_pushButton_clicked()
{
    if(ui->lineEdit_id->text().isEmpty() || ui->lineEdit_nom->text().isEmpty() || ui->lineEdit_prenom->text().isEmpty()|| ui->lineEdit_num->text().isEmpty() || ui->lineEdit_adresse->text().isEmpty() || ui->lineEdit_cnss->text().isEmpty()){
        QMessageBox ok;
        ok.setWindowTitle("Erreur");
        ok.setText("Ajout échoué! Veuillez remplir tous les champs.");
        ok.setStandardButtons(QMessageBox::Ok);
        ok.exec();
        return;
    }
    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    int num = ui->lineEdit_num->text().toInt();
    QString adresse= ui->lineEdit_adresse->text();
    int cnss = ui->lineEdit_cnss->text().toInt();
    Employee e(id,nom,prenom,num,adresse,cnss);
    if(e.recherche(ui->lineEdit_id->text().toInt())==false){
    bool test=e.ajouter();
    if(test)
  {
  ui->tabemp->setModel(tmpemp.afficher());
  QMessageBox::information(nullptr, QObject::tr("Ajouter un employe"),
                    QObject::tr("Employee ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un employee"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
    else{
        QMessageBox ok;
        ok.setWindowTitle("Notification");
        ok.setText("Employee existe deja Ou Vous le champs ID est un numéro !");
        ok.setStandardButtons(QMessageBox::Ok);
        ok.exec();

    }
}

void MainWindow::on_pushButton__modifier_emp_clicked()
{
    if(ui->lineEdit_faza_id->text().isEmpty() || ui->lineEdit_modif_nom->text().isEmpty() || ui->lineEdit_modif_prenom->text().isEmpty()|| ui->lineEdit_modif_num->text().isEmpty() || ui->lineEdit_modif_adresse->text().isEmpty() || ui->lineEdit_modif_cnss->text().isEmpty()){
        QMessageBox ok;
        ok.setWindowTitle("Erreur");
        ok.setText("Modification échoué! Veuillez sélèctionner un employee.");
        ok.setStandardButtons(QMessageBox::Ok);
        ok.exec();
        return;
    }

    int id = ui->lineEdit_faza_id->text().toInt();
    QString nom = ui->lineEdit_modif_nom->text();
    QString prenom = ui->lineEdit_modif_prenom->text();
    int num = ui->lineEdit_modif_num->text().toInt();
    QString adresse = ui->lineEdit_modif_adresse->text();
    int cnss = ui->lineEdit_modif_cnss->text().toInt();
    Employee e;
    if(e.recherche(id)){
        bool test = e.modifier(id,nom,prenom,num,adresse,cnss);
        if(test){
            ui->tabemp->setModel(tmpemp.afficher());
            QMessageBox::information(nullptr,QObject::tr("Employee modifier"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
        }
    }
}

void MainWindow::on_pushButton_supprimer_emp_clicked()
{
    if(ui->lineEdit_faza_id->text().isEmpty()){
        QMessageBox ok;
        ok.setWindowTitle("Erreur");
        ok.setText("Suppression échoué! Veuillez remplir tous les champs.");
        ok.setStandardButtons(QMessageBox::Ok);
        ok.exec();
        return;
    }
    int id = ui->lineEdit_faza_id->text().toInt();
    Employee e;
    bool test=tmpemp.supprimer(id);
    if(test)
    {
        ui->tabemp->setModel(tmpemp.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un employee"),
                    QObject::tr("Employee supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un employee"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_tabemp_activated(const QModelIndex &index)
{
    QString val=ui->tabemp->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from employee where ID='"+val+"'");

    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit_faza_id->setText(qry.value(0).toString());
            ui->lineEdit_modif_nom->setText(qry.value(1).toString());
            ui->lineEdit_modif_prenom->setText(qry.value(2).toString());
            ui->lineEdit_modif_num->setText(qry.value(3).toString());
            ui->lineEdit_modif_adresse->setText(qry.value(4).toString());
            ui->lineEdit_modif_cnss->setText(qry.value(5).toString());

        }
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Big Error"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}


void MainWindow::on_pushButton_remplirconge_clicked()
{
    if(ui->lineEdit_numconge->text().isEmpty() || ui->lineEdit_num_remplir->text().isEmpty()){
        QMessageBox ok;
        ok.setWindowTitle("Erreur");
        ok.setText("Ajout échoué! Veuillez remplir tous les champs.");
        ok.setStandardButtons(QMessageBox::Ok);
        ok.exec();
        return;
    }

    int num = ui->lineEdit_num_remplir->text().toInt();
    QString debutconge= ui->dateEdit_debutconge->text();
    QString finconge= ui->dateEdit__finconge->text();
    int iduser = ui->lineEdit_numconge->text().toInt();

    Conge e(num,debutconge,finconge,iduser);
    bool test=e.ajouter();
    if(test)
  {
  ui->tabcong->setModel(tmpcong.afficher());
  QMessageBox::information(nullptr, QObject::tr("Remplir un Congé"),
                    QObject::tr("Congé ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Remplir un Congé"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_tabcong_activated(const QModelIndex &index)
{   
    QString val=ui->tabcong->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from conge where NUM='"+val+"'");

    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit_faza_num->setText(qry.value(0).toString());
        }
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Big Error"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_annulerconge_clicked()
{
    if(ui->lineEdit_faza_num->text().isEmpty()){
        QMessageBox ok;
        ok.setWindowTitle("Erreur");
        ok.setText("Suppression échoué! Veuillez sélèctionner un congé.");
        ok.setStandardButtons(QMessageBox::Ok);
        ok.exec();
        return;
    }
    int num = ui->lineEdit_faza_num->text().toInt();
    Conge e;
    bool test=tmpcong.supprimer(num);
    if(test)
    {
        ui->tabcong->setModel(tmpcong.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Annuler un congé"),
                    QObject::tr("Congé supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Annuler un congé"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_modifiercong_clicked()
{
    if(ui->lineEdit_nummm->text().isEmpty()){
        QMessageBox ok;
        ok.setWindowTitle("Erreur");
        ok.setText("Modification échoué! Veuillez sélèctionner un congé.");
        ok.setStandardButtons(QMessageBox::Ok);
        ok.exec();
        return;
    }

    int num = ui->lineEdit_nummm->text().toInt();
    QString debutconge = ui->lineEdit_modif_debutconge->text();
    QString finconge = ui->lineEdit_modif_finconge->text();

    Conge e;
    if(e.recherche(num)){
        bool test = e.modifier(debutconge,finconge,num);
        if(test){
            ui->tabcong->setModel(tmpcong.afficher());
            QMessageBox::information(nullptr,QObject::tr("Congé modifié"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
        }
    }
}

void MainWindow::on_rechlineedit_textChanged(const QString &arg1)
{
    Conge c;
    c.clearTable(ui->tabcong);
    int mat=ui->rechlineedit->text().toInt();
    c.searchRegexp(ui->tabcong,mat);
}

void MainWindow::on_rechlineedit_2_textChanged(const QString &arg1)
{
    Employee c;
    c.clearTable(ui->tabemp);
    int mat=ui->rechlineedit_2->text().toInt();
    c.searchRegexp(ui->tabemp,mat);
}

void MainWindow::on_pushButton_Activer_Modifier_clicked()
{
    ui->lineEdit_modif_nom->show();
    ui->lineEdit_modif_prenom->show();
    ui->lineEdit_modif_num->show();
    ui->lineEdit_modif_adresse->show();
    ui->lineEdit_modif_cnss->show();
    ui->pushButton__modifier_emp->show();
    ui->label_18->show();
    ui->label_19->show();
    ui->label_20->show();
    ui->label_21->show();
    ui->label_22->show();
    ui->pushButton_Activer_Modifier->hide();
    ui->pushButton_annuler->show();

}

void MainWindow::on_pushButton_annuler_clicked()
{
    ui->lineEdit_modif_nom->hide();
    ui->lineEdit_modif_prenom->hide();
    ui->lineEdit_modif_num->hide();
    ui->lineEdit_modif_adresse->hide();
    ui->lineEdit_modif_cnss->hide();
    ui->pushButton__modifier_emp->hide();
    ui->label_18->hide();
    ui->label_19->hide();
    ui->label_20->hide();
    ui->label_21->hide();
    ui->label_22->hide();
    ui->pushButton_Activer_Modifier->show();
    ui->pushButton_annuler->hide();
}



void MainWindow::on_pushButton_trier_clicked()
{
      ui->tabemp->setModel(tmpemp.trier());
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
