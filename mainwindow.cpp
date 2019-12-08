#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCheckBox>
#include "articles.h"
#include <QComboBox>
#include <QDate>
#include <QMessageBox>
#include "promotions.h"
#include <stdio.h>
#include <QString>
#include "commande.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include "employee.h"
#include "conge.h"
#include"reclamations.h"
#include"client.h"
QT_CHARTS_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent,int type)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{ int num;
    QString ref;
    Articles a;
    ui->setupUi(this);
    this->load();
    this->load2();
     ui->comboBox_3->setModel(a.afficherRef());
     ui->comboBox_4->setModel(tmpcommande.afficherNum());
     ui->liste_commande->setModel(tmpcommande.afficher());
     ui->liste_reclamation->setModel(tmpreclamations.afficher());
     ui->liste_commande_A->setModel(tmpcommande.affecter(num,ref));
     ui->liste_commande_A->verticalHeader()->setVisible(false);
         ui->liste_commande_A->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
         ui->liste_commande_A->setAlternatingRowColors(true);
         ui->liste_commande_A->setShowGrid(false);
         ui->liste_commande->verticalHeader()->setVisible(false);
             ui->liste_commande->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
             ui->liste_commande->setAlternatingRowColors(true);
             ui->liste_commande->setShowGrid(false);
              ui->comboBox->setModel(tmpclient.AfficherCin());
              ui->comboBox_2->setModel(a.afficherRef());

}


MainWindow::~MainWindow()
{
    delete ui;
}

Articles a;

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    QString ref=ui->ref->text();
    QString prix=ui->prix->text();
    QString type=ui->type->currentText();
    int quant=ui->quant->text().toInt();
    QDate d=ui->d->date();
    QString marque=ui->marque->text();
    Articles a(ref,prix,type,quant,d,marque);
    bool test= a.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Ajouter un article"),
                                 QObject::tr("article ajouté.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un article"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    ui->ref->clear();
    ui->prix->clear();
    ui->type->clear();
    ui->quant->clear();
    ui->marque->clear();
}

void MainWindow::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    this->ui->tableView->setModel(a.afficher());
     ui->comboBox_3->setModel(a.afficherRef());
}

void MainWindow::on_pushButton_3_clicked()
{


}

void MainWindow::on_pushButton_2_clicked()
{

    if(ui->reff->text().isEmpty() || ui->modifPrix_2->text().isEmpty() || ui->modifType_2->currentText().isEmpty() || ui->modifQuant_2->text().isEmpty() || ui->modifDate_3->text().isEmpty() || ui->modifMarque_2->text().isEmpty())
    { QMessageBox ok;
        ok.setWindowTitle("Erreur");
        ok.setText("modification échouée! Veuillez sélèctionner un article.");
        ok.setStandardButtons(QMessageBox::Ok);
        ok.exec();
        return;
    }

    QString ref=ui->reff->text();
    QString prix=ui->modifPrix_2->text();
    QString type=ui->modifType_2->currentText();
    int quant=ui->modifQuant_2->text().toInt();
    QDate d=ui->modifDate_3->date();
    QString marque=ui->modifMarque_2->text();
    Articles a(ref,prix,type,quant,d,marque);
    if(a.recherche(ref)==true)
    {
        bool test=a.modifier(ref,prix,type,quant,d,marque);
        if(test)
        {
            ui->tableView->setModel(a.afficher());
            QMessageBox::information(nullptr, QObject::tr("modifier un article"),
                                     QObject::tr("article modifiée.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else{
            QMessageBox::critical(nullptr, QObject::tr("modifier un article"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);}
    }


}
void MainWindow::on_pushButton_4_clicked()////////////////////////////
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_6_clicked()
{

}


Promotions p;
void MainWindow::on_pushButton_14_clicked()
{

}

void MainWindow::on_pushButton_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_34_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}
/*
void MainWindow::on_pushButton_33_clicked()
{
    int num=ui->numSupprimer->text().toInt();
    Promotions p;
    p.supprimer(num);
} */
void MainWindow::on_pushButton_33_clicked(){}

void MainWindow::on_pushButton_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_35_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_37_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_15_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_36_clicked()
{

}

void MainWindow::on_pushButton_17_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_38_clicked()
{
    Articles a;
    bool test=true;
    if(test){
        if(ui->quant_2->isChecked())
        { ui->tableView->setModel(a.trierarticles());
            QMessageBox::information(nullptr, QObject::tr("trier articles"),
                                     QObject::tr("articles trier.\n"
                                                 "Voulez-vous enregistrer les modifications ?"),
                                     QMessageBox::Save
                                     | QMessageBox::Cancel,
                                     QMessageBox::Save);
        }
        else if (ui->prix_2->isChecked())
        {

            ui->tableView->setModel(a.trierprix());
            QMessageBox::information(nullptr, QObject::tr("trier articles"),
                                     QObject::tr("client articles.\n"
                                                 "Voulez-vous enregistrer les modifications ?"),
                                     QMessageBox::Save
                                     | QMessageBox::Cancel,
                                     QMessageBox::Save);
        }
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("trier client"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_18_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
    ui->a1->setText( a.prixHaut() );
    ui->a2->setText(a.nombreArticle());
    ui->a3->setText(a.prixBas());
    ui->p1->setText(p.highPromotion());
    ui->p2->setText(p.upcoming());
    ui->p3->setText(p.lowPromotion());
}

void MainWindow::on_pushButton_19_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    Articles a;
    ui->tableView->setModel(a.afficher());
     ui->comboBox_3->setModel(a.afficherRef());
}

void MainWindow::on_pushButton_20_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_23_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_22_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    Articles a;
    ui->tableView->setModel(a.afficher());
     ui->comboBox_3->setModel(a.afficherRef());
}

void MainWindow::on_pushButton_21_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from articles where ref='"+val+"'");

    if(qry.exec())
    {
        while(qry.next())
        {
            ui->reff->setText(qry.value(0).toString());
            ui->modifPrix_2->setText(qry.value(1).toString());
            ui->modifType_2->setCurrentText(qry.value(2).toString());
            ui->modifQuant_2->setText(qry.value(3).toString());
            ui->modifDate_3->setDate(qry.value(4).toDate());
            ui->modifMarque_2->setText(qry.value(5).toString());


        }
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Big Error"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}
void MainWindow:: on_pushButton_8_clicked() {}
void MainWindow::on_pushButton_24_clicked(){}



void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    Articles a;
    a.clearTable(ui->tableView);
    QString mat=ui->lineEdit->text();
    a.searchRegexp(ui->tableView,mat);
}

void MainWindow::on_pushButton_ajout_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_article_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_stock_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

    Articles a;
    ui->tableView->setModel(a.afficher());
     ui->comboBox_3->setModel(a.afficherRef());

}


void MainWindow::on_piechart_clicked() //cont
{

    ui->stackedWidget->setCurrentIndex(10);
    QPieSeries *series = new QPieSeries();
    series->append("Alimentaire", a.nombreCategorie1());
    series->append("Congelé", a.nombreCategorie2());
    series->append("Vêtements", a.nombreCategorie3());

    QPieSlice *slice = series->slices().at(1);
    slice->setExploded();
    slice->setLabelVisible();
    slice->setPen(QPen(Qt::darkGreen, 2));
    slice->setBrush(Qt::green);

    QChart *chart = new QChart(); //tasna3 doura
    chart->addSeries(series);
    chart->setTitle("stat");
    // chart->legend()->hide();

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    setCentralWidget(chartView);
    resize(440,300);
    show();
}

void MainWindow::on_ar_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_sto_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}


void MainWindow::on_ok_clicked()
{
    int num=ui->num_2->text().toInt();
    int pourcentage=ui->pourcentage_2->text().toInt();
    QDate d=ui->dateEdit_3->date();
    int jours=ui->jour_2->text().toInt();
    Promotions p(num,pourcentage,d,jours);
    bool test= p.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Ajouter une promotion"),
                                 QObject::tr("Promotion ajoutée.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter une promotion"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    ui->num_2->clear();
    ui->pourcentage_2->clear();
    ui->jour_2->clear();
}

void MainWindow::on_affichage_clicked()
{

}

void MainWindow::on_prom_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
    this->ui->tableView_3->setModel(p.afficher());
}

void MainWindow::on_pushButton_28_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_label_50_windowIconTextChanged(const QString &iconText)
{

}

void MainWindow::on_recherche_textChanged(const QString &arg1)
{
    Promotions p;
    p.clearTable(ui->tableView_3);
    QString mat=ui->recherche->text();
    p.searchRegexp(ui->tableView_3,mat);
}

void MainWindow::on_tableView_3_activated(const QModelIndex &index)
{
    QString val=ui->tableView_3->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from promotions where num='"+val+"'");

    if(qry.exec())
    {
        while(qry.next())
        {
            ui->num_3->setText(qry.value(0).toString());
            ui->pourcentage_3->setText(qry.value(1).toString());
            ui->date_3->setDate(qry.value(2).toDate());
            ui->jours_3->setText(qry.value(3).toString());


        }
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Big Error"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_modif_clicked()
{
    if(ui->num_3->text().isEmpty() || ui->pourcentage_3->text().isEmpty() || ui->date_3->text().isEmpty() || ui->jours_3->text().isEmpty())
    { QMessageBox ok;
        ok.setWindowTitle("Erreur");
        ok.setText("modification échouée! Veuillez sélèctionner une promotion.");
        ok.setStandardButtons(QMessageBox::Ok);
        ok.exec();
        return;
    }

    int num=ui->num_3->text().toInt();
    int pourcentage=ui->pourcentage_3->text().toInt();
    QDate d=ui->date_3->date();
    int jours=ui->jours_3->text().toInt();
    Promotions p(num,pourcentage,d,jours);
    if(p.recherche(num)==true)
    {
        bool test=p.modifier(num,pourcentage,d,jours);
        if(test)
        {
            ui->tableView_3->setModel(p.afficher());
            QMessageBox::information(nullptr, QObject::tr("modifier une promotion"),
                                     QObject::tr("promotion modifiée.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else{
            QMessageBox::critical(nullptr, QObject::tr("modifier une promotion"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);}
    }

}

void MainWindow::on_suppp_clicked()
{
    if(ui->num_3->text().isEmpty()){
        QMessageBox ok;
        ok.setWindowTitle("Erreur");
        ok.setText("Suppression échoué! Veuillez remplir tous les champs.");
        ok.setStandardButtons(QMessageBox::Ok);
        ok.exec();
        return;
    }
    int num = ui->num_3->text().toInt();
    Promotions p;
    bool test=p.supprimer(num);
    if(test)
    {
        ui->tableView_3->setModel(p.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une promotion"),
                                 QObject::tr("Promotion supprimé.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une promotion"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_26_clicked()
{
    Promotions p;
    bool test=true;
    if(test){
        if(ui->pourcentage_4->isChecked())
        { ui->tableView_3->setModel(p.trierpourcentage());
            QMessageBox::information(nullptr, QObject::tr("trier promotions"),
                                     QObject::tr("promotion trier.\n"
                                                 "Voulez-vous enregistrer les modifications ?"),
                                     QMessageBox::Save
                                     | QMessageBox::Cancel,
                                     QMessageBox::Save);
        }
        else if (ui->jours_2->isChecked())
        {

            ui->tableView_3->setModel(p.trierduree());
            QMessageBox::information(nullptr, QObject::tr("trier promotion"),
                                     QObject::tr("client promotion.\n"
                                                 "Voulez-vous enregistrer les modifications ?"),
                                     QMessageBox::Save
                                     | QMessageBox::Cancel,
                                     QMessageBox::Save);
        }
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("trier promotion"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_stooock_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_promoooo_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_affecter_clicked()
{
    Promotions p;
    ui->tableView_4->setModel(p.afficherAffectation());
    ui->stackedWidget->setCurrentIndex(13);

    QSqlQuery query;
    query.prepare("select * from promotions");
    query.exec();
    while(query.next())
    {
        ui->promo->addItem(query.value("num").toString());
    }
    QSqlQuery query1;
    query1.prepare("select * from articles");
    query1.exec();
    while(query1.next())
    {
        ui->art->addItem(query1.value("ref").toString());
    }
}

void MainWindow::on_valide_clicked()
{
    QString ref=ui->art->currentText();
    QString num=ui->promo->currentText();
    Promotions p;
    p.affecter(num,ref);
    ui->tableView_4->setModel(p.afficherAffectation());
}

void MainWindow::on_suppppp_clicked()
{
    Promotions p;
    QString ref=ui->ref_3->text();
    QString num=ui->num_4->text();
    p.supprimerAffect(ref,num);
    ui->tableView_4->setModel(p.afficherAffectation());


}

void MainWindow::on_tableView_4_activated(const QModelIndex &index)
{
    QString val=ui->tableView_4->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from affectation where ref='"+val+"'");

    if(qry.exec())
    {
        while(qry.next())
        {
            ui->num_4->setText(qry.value(0).toString());
            ui->ref_3->setText(qry.value(1).toString());



        }
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Big Error"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_aaa_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_bbb_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_ccc_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_modiffff_clicked()
{
    if(ui->reff->text().isEmpty() || ui->modifPrix_2->text().isEmpty() || ui->modifType_2->currentText().isEmpty() || ui->modifQuant_2->text().isEmpty() || ui->modifDate_3->text().isEmpty() || ui->modifMarque_2->text().isEmpty())
    { QMessageBox ok;
        ok.setWindowTitle("Erreur");
        ok.setText("modification échouée! Veuillez sélèctionner un article.");
        ok.setStandardButtons(QMessageBox::Ok);
        ok.exec();
        return;
    }

    QString ref=ui->reff->text();
    QString prix=ui->modifPrix_2->text();
    QString type=ui->modifType_2->currentText();
    int quant=ui->modifQuant_2->text().toInt();
    QDate d=ui->modifDate_3->date();
    QString marque=ui->modifMarque_2->text();
    Articles a(ref,prix,type,quant,d,marque);
    if(a.recherche(ref)==true)
    {
        bool test=a.modifier(ref,prix,type,quant,d,marque);
        if(test)
        {
            ui->tableView->setModel(a.afficher());

            QMessageBox::information(nullptr, QObject::tr("modifier un article"),
                                     QObject::tr("article modifiée.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else{
            QMessageBox::critical(nullptr, QObject::tr("modifier un article"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);}
    }
}

void MainWindow::on_suprimmm_clicked()
{
    if(ui->reff->text().isEmpty()){
        QMessageBox ok;
        ok.setWindowTitle("Erreur");
        ok.setText("Suppression échoué! Veuillez remplir tous les champs.");
        ok.setStandardButtons(QMessageBox::Ok);
        ok.exec();
        return;
    }
    QString ref = ui->reff->text();
    Articles a;
    bool test=a.supprimer(ref);
    if(test)
    {
        ui->tableView->setModel(a.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un employee"),
                                 QObject::tr("Employee supprimé.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un employee"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_prommm_clicked()
{
}

void MainWindow::on_ajoutemploy_clicked()
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
            ok.setText("Employee existe deja !");
            ok.setStandardButtons(QMessageBox::Ok);
            ok.exec();

        }
}

void MainWindow::on_aa_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);
    Employee e;
     ui->emp->setModel(e.afficher());
}

void MainWindow::on_abab_clicked()
{
    Employee e;

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

    if(e.recherche(id)){
        bool test = e.modifier(id,nom,prenom,num,adresse,cnss);
        if(test){
            ui->emp->setModel(e.afficher());
            QMessageBox::information(nullptr,QObject::tr("Employee modifier"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
        }
    }
}

void MainWindow::on_emp_activated(const QModelIndex &index)
{
    QString val=ui->emp->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from employee where id='"+val+"'");

    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit_modif_nom->setText(qry.value(1).toString());
            ui->lineEdit_modif_prenom->setText(qry.value(2).toString());
            ui->lineEdit_modif_adresse->setText(qry.value(4).toString());
            ui->lineEdit_modif_num->setText(qry.value(3).toString());
            ui->lineEdit_faza_id->setText(qry.value(0).toString());
            ui->lineEdit_modif_cnss->setText(qry.value(5).toString());


        }
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Big Error"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_supppp_clicked()
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
        bool test=e.supprimer(id);
        if(test)
        {
            ui->emp->setModel(e.afficher());//refresh
            QMessageBox::information(nullptr, QObject::tr("Supprimer un employee"),
                        QObject::tr("Employee supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un employee"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_trieeeee_clicked()
{
     Employee e;
      ui->emp->setModel(e.trier());
}

void MainWindow::on_recherchee_cursorPositionChanged(int arg1, int arg2)
{
    Employee e;
        e.clearTable(ui->emp);
        int mat=ui->recherchee->text().toInt();
        e.searchRegexp(ui->emp,mat);
}
void MainWindow :: load()
{
    ui->comboBoxid->clear();
    QSqlQuery query;
    query.prepare("select id from employee");
    if(query.exec())
    { while (query.next())
        {
            ui->comboBoxid->addItem(query.value(0).toString());
        }

    }

}
void MainWindow :: load2()
{
    ui->comboBoxid_2->clear();
    QSqlQuery query;
    query.prepare("select idemp from conge");
    if(query.exec())
    { while (query.next())
        {
            ui->comboBoxid_2->addItem(query.value(0).toString());
        }

    }

}

void MainWindow::on_emppp_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);
}


void MainWindow::on_congeee_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);
    this->load();
}

void MainWindow::on_ajoutconge_clicked()
{
   int  num=ui->numconge->text().toInt();
    QDate debutconge=ui->dated->date();
    QDate finconge=ui->datef->date();
    int idemp=ui->comboBoxid->currentText().toInt();
    Conge c(num,debutconge,finconge,idemp);
    bool test= c.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Ajouter un article"),
                                 QObject::tr("article ajouté.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un article"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    ui->numconge->clear();

}

void MainWindow::on_tableView_5_activated(const QModelIndex &index)
{
    QString val=ui->tableView_5->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from conge where numero='"+val+"'");

    if(qry.exec())
    {
        while(qry.next())
        {
            ui->modifnumm->setText(qry.value(0).toString());
            ui->dateEdit_5->setDate(qry.value(1).toDate());
            ui->dateEdit_6->setDate(qry.value(2).toDate());

         ui->comboBoxid_2->addItem(qry.value(3).toString());


        }
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Big Error"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_push_clicked()
{
    Conge c;
     ui->stackedWidget->setCurrentIndex(17);
  ui->tableView_5->setModel(c.afficher());
}

void MainWindow::on_abab_2_clicked()
{
    if(ui->modifnumm->text().isEmpty())
    { QMessageBox ok;
        ok.setWindowTitle("Erreur");
        ok.setText("modification échouée! Veuillez sélèctionner un congé.");
        ok.setStandardButtons(QMessageBox::Ok);
        ok.exec();
        return;
    }


    int  num=ui->modifnumm->text().toInt();
     QDate debutconge=ui->dateEdit_5->date();
     QDate finconge=ui->dateEdit_6->date();
     int idemp=ui->comboBoxid_2->currentText().toInt();
     Conge c(num,debutconge,finconge,idemp);
    if(c.recherche(num)==true)
    {
        bool test=c.modifier(num,debutconge,finconge,idemp);
        if(test)
        {
            ui->tableView_5->setModel(c.afficher());
            QMessageBox::information(nullptr, QObject::tr("modifier une promotion"),
                                     QObject::tr("promotion modifiée.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else{
            QMessageBox::critical(nullptr, QObject::tr("modifier une promotion"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);}
    }
}

void MainWindow::on_supppp_2_clicked()
{
    int num=ui->modifnumm->text().toInt();
    Conge c;
    c.supprimer(num);
     ui->tableView_5->setModel(c.afficher());
}

void MainWindow::on_recherchee_2_cursorPositionChanged(int arg1, int arg2)
{

}

void MainWindow::on_recherchee_2_textChanged(const QString &arg1)
{
    Conge c;
    c.clearTable(ui->tableView_5);
    int mat=ui->recherchee_2->text().toInt();
    c.searchRegexp(ui->tableView_5,mat);
}

void MainWindow::on_trieeeee_2_clicked()
{
    Conge c;
    bool test=true;
    if(test){

       ui->tableView_5->setModel(c.trierConge());
            QMessageBox::information(nullptr, QObject::tr("trier conges"),
                                     QObject::tr("conge trier.\n"
                                                 "Voulez-vous enregistrer les modifications ?"),
                                     QMessageBox::Save
                                     | QMessageBox::Cancel,
                                     QMessageBox::Save);
        }




    else
        QMessageBox::critical(nullptr, QObject::tr("trier conges"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_arrt_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_109_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    Articles a;
    this->ui->tableView->setModel(a.afficher());
    ui->tableView->verticalHeader()->setVisible(false);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableView->setAlternatingRowColors(true);
        ui->tableView->setShowGrid(false);
}

void MainWindow::on_pushButton_ajout_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_116_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    Articles a;
    this->ui->tableView_14->setModel(a.afficher1());
    ui->tableView_14->verticalHeader()->setVisible(false);
        ui->tableView_14->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableView_14->setAlternatingRowColors(true);
        ui->tableView_14->setShowGrid(false);
}

void MainWindow::on_modiffff_4_clicked()
{
    if(ui->reff_4->text().isEmpty() || ui->modifPrix_7->text().isEmpty() || ui->modifType_7->currentText().isEmpty() || ui->modifQuant_7->text().isEmpty() || ui->modifDate_10->text().isEmpty() || ui->modifMarque_7->text().isEmpty())
    { QMessageBox ok;
        ok.setWindowTitle("Erreur");
        ok.setText("modification échouée! Veuillez sélèctionner un article.");
        ok.setStandardButtons(QMessageBox::Ok);
        ok.exec();
        return;
    }

    QString ref=ui->reff_4->text();
    QString prix=ui->modifPrix_7->text();
    QString type=ui->modifType_7->currentText();
    int quant=ui->modifQuant_7->text().toInt();
    QDate d=ui->modifDate_10->date();
    QString marque=ui->modifMarque_7->text();
    Articles a(ref,prix,type,quant,d,marque);
    if(a.recherche(ref)==true)
    {
        bool test=a.modifier(ref,prix,type,quant,d,marque);
        if(test)
        {
            ui->tableView_14->setModel(a.afficher1());
            QMessageBox::information(nullptr, QObject::tr("modifier un article"),
                                     QObject::tr("article modifiée.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else{
            QMessageBox::critical(nullptr, QObject::tr("modifier un article"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);}
    }

}

void MainWindow::on_tableView_14_activated(const QModelIndex &index)
{
    QString val=ui->tableView_14->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from articles where ref='"+val+"'");

    if(qry.exec())
    {
        while(qry.next())
        {
            ui->reff_4->setText(qry.value(0).toString());
            ui->modifPrix_7->setText(qry.value(1).toString());
            ui->modifType_7->setCurrentText(qry.value(2).toString());
            ui->modifQuant_7->setText(qry.value(3).toString());
            ui->modifDate_10->setDate(qry.value(4).toDate());
            ui->modifMarque_7->setText(qry.value(5).toString());


        }
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Big Error"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_555_clicked()
{

    QString ref=ui->ref_10->text();
    QString prix=ui->prix_5->text();
    QString type=ui->type_4->currentText();
    int quant=ui->quant_5->text().toInt();
    QDate d=ui->d->date();
    QString marque=ui->marque_4->text();
    Articles a(ref,prix,type,quant,d,marque);
    bool test= a.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Ajouter un article"),
                                 QObject::tr("article ajouté.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un article"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    ui->ref_10->clear();
    ui->prix_5->clear();
    ui->type_4->clear();
    ui->quant_5->clear();
    ui->marque_4->clear();
}

void MainWindow::on_pushButton_121_clicked()
{

}

void MainWindow::on_pushButton_115_clicked()
{
    Articles a;
    bool test=true;
    if(test){
        if(ui->quant_4->isChecked())
        { ui->tableView_14->setModel(a.trierarticles1());
            QMessageBox::information(nullptr, QObject::tr("trier articles"),
                                     QObject::tr("articles trier.\n"
                                                 "Voulez-vous enregistrer les modifications ?"),
                                     QMessageBox::Save
                                     | QMessageBox::Cancel,
                                     QMessageBox::Save);
        }
        else if (ui->prix_4->isChecked())
        {

            ui->tableView_14->setModel(a.trierprix1());
            QMessageBox::information(nullptr, QObject::tr("trier articles"),
                                     QObject::tr("client articles.\n"
                                                 "Voulez-vous enregistrer les modifications ?"),
                                     QMessageBox::Save
                                     | QMessageBox::Cancel,
                                     QMessageBox::Save);
        }
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("trier articles"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_suprimmm_4_clicked()
{
    if(ui->reff_4->text().isEmpty()){
        QMessageBox ok;
        ok.setWindowTitle("Erreur");
        ok.setText("Suppression échoué! Veuillez remplir tous les champs.");
        ok.setStandardButtons(QMessageBox::Ok);
        ok.exec();
        return;
    }
    QString ref = ui->reff_4->text();
    Articles a;
    bool test=a.supprimer(ref);
    if(test)
    {
        ui->tableView_14->setModel(a.afficher1());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un employee"),
                                 QObject::tr("Employee supprimé.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un employee"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    Articles a;
    a.clearTable(ui->tableView_14);
    QString mat=ui->lineEdit_2->text();
    a.searchRegexp1(ui->tableView_14,mat);
}

void MainWindow::on_lineEdit_3_textChanged(const QString &arg1)
{
    Articles a;
    a.clearTable(ui->tableView_15);
    QString mat=ui->lineEdit_3->text();
    a.searchRegexp2(ui->tableView_15,mat);
}

void MainWindow::on_pushButton_888_clicked()
{
    QString ref=ui->ref_11->text();
    QString prix=ui->prix_7->text();
    QString type=ui->type_5->currentText();
    int quant=ui->quant_7->text().toInt();
    QDate d=ui->d_5->date();
    QString marque=ui->marque_5->text();
    Articles a(ref,prix,type,quant,d,marque);
    bool test= a.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Ajouter un article"),
                                 QObject::tr("article ajouté.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un article"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    ui->ref_11->clear();
    ui->prix_7->clear();
    ui->type_5->clear();
    ui->quant_7->clear();
    ui->marque_5->clear();
}

void MainWindow::on_pushButton_123_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    Articles a;
    this->ui->tableView_15->setModel(a.afficher2());
    ui->tableView_15->verticalHeader()->setVisible(false);
        ui->tableView_15->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableView_15->setAlternatingRowColors(true);
        ui->tableView_15->setShowGrid(false);
}

void MainWindow::on_pushButton_ajout_5_clicked()
{
     ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_modiffff_5_clicked()
{
    if(ui->reff_5->text().isEmpty() || ui->modifPrix_8->text().isEmpty() || ui->modifType_8->currentText().isEmpty() || ui->modifQuant_8->text().isEmpty() || ui->modifDate_11->text().isEmpty() || ui->modifMarque_8->text().isEmpty())
    { QMessageBox ok;
        ok.setWindowTitle("Erreur");
        ok.setText("modification échouée! Veuillez sélèctionner un article.");
        ok.setStandardButtons(QMessageBox::Ok);
        ok.exec();
        return;
    }

    QString ref=ui->reff_5->text();
    QString prix=ui->modifPrix_8->text();
    QString type=ui->modifType_8->currentText();
    int quant=ui->modifQuant_8->text().toInt();
    QDate d=ui->modifDate_11->date();
    QString marque=ui->modifMarque_8->text();
    Articles a(ref,prix,type,quant,d,marque);
    if(a.recherche(ref)==true)
    {
        bool test=a.modifier(ref,prix,type,quant,d,marque);
        if(test)
        {
            ui->tableView_15->setModel(a.afficher2());
            QMessageBox::information(nullptr, QObject::tr("modifier un article"),
                                     QObject::tr("article modifiée.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else{
            QMessageBox::critical(nullptr, QObject::tr("modifier un article"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);}
    }

}

void MainWindow::on_tableView_15_activated(const QModelIndex &index)
{
    QString val=ui->tableView_15->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from articles where ref='"+val+"'");

    if(qry.exec())
    {
        while(qry.next())
        {
            ui->reff_5->setText(qry.value(0).toString());
            ui->modifPrix_8->setText(qry.value(1).toString());
            ui->modifType_8->setCurrentText(qry.value(2).toString());
            ui->modifQuant_8->setText(qry.value(3).toString());
            ui->modifDate_11->setDate(qry.value(4).toDate());
            ui->modifMarque_8->setText(qry.value(5).toString());


        }
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Big Error"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_suprimmm_5_clicked()
{
    if(ui->reff_5->text().isEmpty()){
        QMessageBox ok;
        ok.setWindowTitle("Erreur");
        ok.setText("Suppression échoué! Veuillez remplir tous les champs.");
        ok.setStandardButtons(QMessageBox::Ok);
        ok.exec();
        return;
    }
    QString ref = ui->reff_5->text();
    Articles a;
    bool test=a.supprimer(ref);
    if(test)
    {
        ui->tableView_15->setModel(a.afficher2());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un employee"),
                                 QObject::tr("Employee supprimé.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un employee"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_12111_clicked()
{
    Articles a;
    bool test=true;
    if(test){
        if(ui->quant_6->isChecked())
        { ui->tableView_15->setModel(a.trierarticles2());
            QMessageBox::information(nullptr, QObject::tr("trier articles"),
                                     QObject::tr("articles trier.\n"
                                                 "Voulez-vous enregistrer les modifications ?"),
                                     QMessageBox::Save
                                     | QMessageBox::Cancel,
                                     QMessageBox::Save);
        }
        else if (ui->prix_6->isChecked())
        {

            ui->tableView_15->setModel(a.trierprix2());
            QMessageBox::information(nullptr, QObject::tr("trier articles"),
                                     QObject::tr("client articles.\n"
                                                 "Voulez-vous enregistrer les modifications ?"),
                                     QMessageBox::Save
                                     | QMessageBox::Cancel,
                                     QMessageBox::Save);
        }
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("trier client"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_111_clicked()
{
     ui->stackedWidget->setCurrentIndex(18);
}

void MainWindow::on_pushButton_110_clicked()
{
     ui->stackedWidget->setCurrentIndex(18);
}

void MainWindow::on_pushButton_114_clicked()
{
    ui->stackedWidget->setCurrentIndex(18);
}

void MainWindow::on_pushButton_117_clicked()
{
    ui->stackedWidget->setCurrentIndex(18);
}

void MainWindow::on_pushButton_118_clicked()
{
    ui->stackedWidget->setCurrentIndex(18);
}

void MainWindow::on_pushButton_122_clicked()
{
    ui->stackedWidget->setCurrentIndex(18);
}

void MainWindow::on_pushButton_444444_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_24444_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_106_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_stock1_clicked()
{
     ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_pushButton_1077_clicked()
{
     ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_pushButton_113_clicked()
{
      ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_pushButton_stock_4_clicked()
{
      ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_pushButton_119_clicked()
{
      ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_pushButton_stock_5_clicked()
{
      ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_ajoutCommande_clicked()
{
    if(ui->numeroc->text().isEmpty() || ui->dateEdit_2->text().isEmpty() /*|| ui->montantc->text().isEmpty()*/)
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
      { ui->liste_commande->setModel(tmpcommande.afficher());
             ui->comboBox_4->setModel(tmpcommande.afficherNum());
             //refresh
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

void MainWindow::on_pushButton_128_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_ajout_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_suprimmm_6_clicked()
{  if(ui->lineEdit_22->text().isEmpty()){
        QMessageBox ok;
        ok.setWindowTitle("Erreur");
        ok.setText("Suppression échoué! Veuillez sélectionner une commande.");
        ok.setStandardButtons(QMessageBox::Ok);
        ok.exec();
        return;
    }
  int ref;
    int num = ui->lineEdit_22->text().toInt();
bool test=tmpcommande.supprimer(num);
QString reff;
if(test)
{ui->liste_commande->setModel(tmpcommande.afficher());//refresh
     ui->liste_commande_A->setModel(tmpcommande.affecter(num,reff));


    QMessageBox::information(nullptr, QObject::tr("Supprimer une commande"),
                QObject::tr("commande supprimée.\n"
                            "Click OK to exit."), QMessageBox::ApplyRole);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer une commande"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_liste_commande_activated(const QModelIndex &index)
{ QString val=ui->liste_commande->model()->data(index).toString();

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

void MainWindow::on_comboBox_3_currentIndexChanged(const QString &arg1)
{
    Articles a;
       a.clearTable(ui->table_articles);
     QString mat=ui->comboBox_3->currentText();
        a.searchRegexp0(ui->table_articles,mat);
        ui->table_articles->verticalHeader()->setVisible(false);
            ui->table_articles->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
            ui->table_articles->setAlternatingRowColors(true);
            ui->table_articles->setShowGrid(false);
}

void MainWindow::on_affect_clicked()
{
      ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_127_clicked()
{
     ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_affecter1_clicked()
{
    QString ref=ui->comboBox_3->currentText();
    int num=ui->comboBox_4->currentText().toInt();

  ui->liste_commande_A->setModel(tmpcommande.affecter(num,ref));

}

void MainWindow::on_rechercheC_textChanged(const QString &arg1)
{
    commande c;
        c.clearTable(ui->liste_commande);
        c.clearTable(ui->liste_commande_A);
        int mat=ui->rechercheC->text().toInt();
        c.searchRegexp(ui->liste_commande,mat);
        c.searchRegexp2(ui->liste_commande_A,mat);
}

void MainWindow::on_modifierCommande_clicked()
{
    if(ui->lineEdit_22->text().isEmpty() || ui->dateEdit_5->text().isEmpty() || ui->lineEdit_24->text().isEmpty())
        { QMessageBox ok;
            ok.setWindowTitle("Erreur");
            ok.setText("modification échouée! Veuillez sélèctionner ou entrer le numéro d'une commande.");
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

void MainWindow::on_trier_clicked()
{

    bool test=true;
    if(test){
        if(ui->num8->isChecked())
        { ui->liste_commande->setModel(tmpcommande.triercommande());
            QMessageBox::information(nullptr, QObject::tr("trier commandes"),
                                     QObject::tr("commande trier.\n"
                                                 "Voulez-vous enregistrer les modifications ?"),
                                     QMessageBox::Save
                                     | QMessageBox::Cancel,
                                     QMessageBox::Save);
        }
        else if (ui->montant8->isChecked())
        {

            ui->liste_commande->setModel(tmpcommande.triercommande2());
            QMessageBox::information(nullptr, QObject::tr("trier commandes"),
                                     QObject::tr("commande trier.\n"
                                                 "Voulez-vous enregistrer les modifications ?"),
                                     QMessageBox::Save
                                     | QMessageBox::Cancel,
                                     QMessageBox::Save);
        }
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("trier commandes"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_129_clicked()
{
    ui->stackedWidget->setCurrentIndex(18);
}

void MainWindow::on_pushButton_130_clicked()
{
     ui->stackedWidget->setCurrentIndex(18);
}

void MainWindow::on_pushButton_131_clicked()
{
     ui->stackedWidget->setCurrentIndex(18);
}

void MainWindow::on_pushButton_30_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_client_clicked()
{
    int cin= ui->cinClient_1->text().toInt();
        QString Nom= ui->nomClient->text();
        QString Prenom =ui->prenomClient->text();
         QString Sexe =ui->sexeClient->currentText();
         QString Adresse =ui->adresseClient->text();
         QString tel= ui->telCient->text();


       Client c(cin,Nom,Prenom,Sexe,Adresse,tel);
        bool test=c.Ajouter();
        if(test)
      {
            ui->comboBox->setModel(tmpclient.AfficherCin());

      QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                        QObject::tr("client ajouté.\n"
                                    "Click OK to exit."), QMessageBox::ApplyRole);


      }
        else
            QMessageBox::critical(nullptr, QObject::tr("Ajouter un client"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_articleees_clicked()
{
    QString ref= ui->refA_R->text();
    QString prix= ui->prixA->text();
    QString type =ui->typeA->currentText();
    int quant=ui->quant222->text().toInt();
    QDate d=ui->date222->date();
    QString marque= ui->marqueA->text();



       Articles a(ref,prix,type,quant,d,marque);
        bool test=a.ajouter();
        if(test)
      { ui->comboBox_2->setModel(a.afficherRef());

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

void MainWindow::on_ajoutReclamations_5_clicked()
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
           QString ref =ui->refA_R->text();
           int cin= ui->cin3->text().toInt();
           QString type=ui->combotype->currentText();
           reclamations c(num,d,ref,cin,type);
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
void MainWindow:: on_ajoutReclamations_7_clicked(){}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QString v=ui->comboBox->currentText();
        QSqlQuery qry;
        qry.prepare("select * from client where cin='"+v+"'");
       if(qry.exec())
       { while (qry.next())
           {   ui->cin3->setText(qry.value(0).toString());
               ui->cinClient_1->setText(qry.value(0).toString());
               ui->nomClient->setText(qry.value(1).toString());
               ui->prenomClient->setText(qry.value(2).toString());
               ui->sexeClient->setCurrentText(qry.value(3).toString());
               ui->adresseClient->setText(qry.value(4).toString());
               ui->telCient->setText(qry.value(5).toString());

           }




        }
            else
                QMessageBox::critical(nullptr, QObject::tr("afficher un client"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_comboBox_2_currentIndexChanged(const QString &arg1)
{
    QString v=ui->comboBox_2->currentText();
    QSqlQuery qry;
    qry.prepare("select * from articles where ref='"+v+"'");
   if(qry.exec())
   {
       while (qry.next())
       {   ui->ref3->setText(qry.value(0).toString());
           ui->refA_R->setText(qry.value(0).toString());
           ui->prixA->setText(qry.value(1).toString());
            ui->typeA->setCurrentText(qry.value(2).toString());
            ui->quant222->setText(qry.value(3).toString());
           ui->marqueA->setText(qry.value(4).toString());



       }

    }
        else
            QMessageBox::critical(nullptr, QObject::tr("afficher un article"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_modiferReclamations_clicked()
{ if(ui->numR_2->text().isEmpty() || ui->dateR_2->text().isEmpty() || ui->refA_2->text().isEmpty() || ui->cinC_2->text().isEmpty())
    { QMessageBox ok;
        ok.setWindowTitle("Erreur");
        ok.setText("modification échouée! Veuillez sélèctionner ou entrer une réclamation.");
        ok.setStandardButtons(QMessageBox::Ok);
        ok.exec();
        return;
    }
    int num=ui->numR_2->text().toInt();
        QDate d =ui->dateR_2->date();
        QString ref=ui->refA_2->text();
        int cin=ui->cinC_2->text().toInt();
        QString type=ui->combotype_2->currentText();
        reclamations r1;
         if(r1.reche(num)){
                bool test = r1.modifier(num,d,ref,cin,type);
                ui->numR_2->clear();
                ui->dateR_2->clear();
               ui->refA_2->clear();
               ui->cinC_2->clear();
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

void MainWindow::on_liste_reclamation_activated(const QModelIndex &index)
{ QString val=ui->liste_reclamation->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from recl where num='"+val+"'");

    if(qry.exec())
    {
        while(qry.next())
        {
            ui->numR_2->setText(qry.value(0).toString());
            ui->dateR_2->setDate(qry.value(1).toDate());
            ui->cinC_2->setText(qry.value(2).toString());
            ui->refA_2->setText(qry.value(3).toString());
            ui->combotype_2->setCurrentText(qry.value(4).toString());

        }
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Big Error"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }

}

void MainWindow::on_lineEdit_7_textChanged(const QString &arg1)
{
    reclamations c;
        c.clearTable(ui->liste_reclamation);
        int mat=ui->lineEdit_7->text().toInt();
        c.searchRegexp(ui->liste_reclamation,mat);
}

void MainWindow::on_suprimerReclamations_clicked()
{
    if(ui->numR_2->text().isEmpty()){
            QMessageBox ok;
            ok.setWindowTitle("Erreur");
            ok.setText("Suppression échoué! Veuillez sélectionner une réclamation.");
            ok.setStandardButtons(QMessageBox::Ok);
            ok.exec();
            return;
        }
        int num = ui->numR_2->text().toInt();
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

void MainWindow::on_pushButton_12222_clicked()
{
    reclamations r;
    bool test=true;
    if(test){
        if(ui->datee->isChecked())
        { ui->tableView->setModel(r.trierReclamation2());
            QMessageBox::information(nullptr, QObject::tr("trier reclamations"),
                                     QObject::tr("reclamations trier.\n"
                                                 "Voulez-vous enregistrer les modifications ?"),
                                     QMessageBox::Save
                                     | QMessageBox::Cancel,
                                     QMessageBox::Save);
        }
        else if (ui->numm->isChecked())
        {

            ui->tableView->setModel(r.trierReclamation());
            QMessageBox::information(nullptr, QObject::tr("trier reclamations"),
                                     QObject::tr("trier reclamations.\n"
                                                 "Voulez-vous enregistrer les modifications ?"),
                                     QMessageBox::Save
                                     | QMessageBox::Cancel,
                                     QMessageBox::Save);
        }
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("trier reclamations"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_ajouter_clicked()
{

}
