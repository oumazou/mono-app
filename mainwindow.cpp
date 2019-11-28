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
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
QT_CHARTS_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
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

void MainWindow::on_pushButton_33_clicked()
{
    int num=ui->numSupprimer->text().toInt();
    Promotions p;
    p.supprimer(num);
}

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

}


void MainWindow::on_piechart_clicked()
{

    ui->stackedWidget->setCurrentIndex(10);
    QPieSeries *series = new QPieSeries();
    series->append("Alimentaire", a.nombreCategorie1()); //najouti fi wost serie append=associe
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
