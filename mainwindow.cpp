#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    c.createconnect();
    ui->stackedWidget->setCurrentIndex(0);
    ui->tableView->setModel(cl.Afficher());
    ui->tableView_2->setModel(cr.Afficher());
    ui->tableView_3->setModel(cl.Afficher_ID());
    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget_2->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    c.close();
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    ui->tableView->setModel(cl.Afficher());
}

void MainWindow::on_pushButton_8_clicked()
{
    int id = ui->lineEdit_5->text().toInt();
    QString nom = ui->lineEdit_6->text();
    QString prenom = ui->lineEdit_9->text();
    QString adresse = ui->lineEdit_7->text();
    QString sexe = ui->lineEdit_8->text();
    QString num = ui->lineEdit_11->text();


    Client O(id,nom,prenom,sexe,adresse,1,num);

    if(O.verif())
    {
        if(O.Ajouter())
        {
            ui->tableView->setModel(cl.Afficher());
            ui->tableView_3->setModel(cl.Afficher_ID());
            ui->tabWidget->setCurrentIndex(0);
        }
    }
    else
    {
        QMessageBox::critical(this,"ajouter client","id exist !");
    }
}

void MainWindow::on_pushButton_7_clicked()
{
   // int id = ui->lineEdit_10->text().toInt();
    QString idd = ui->label_12->text();
    if(idd!="")
    {
        int id = idd.toInt();
        Client O;
        O.setID(id);
        if(O.Supprimer())
        {
            ui->tableView->setModel(cl.Afficher());
            ui->tabWidget->setCurrentIndex(0);
            ui->tableView_3->setModel(cl.Afficher_ID());
            ui->tableView_2->setModel(cr.Afficher());


        }
    }
    else
    {
        QMessageBox::critical(this,"supprime client","select un id !");
    }

}

void MainWindow::on_pushButton_9_clicked()
{
    Client O;
    O.setID(ui->lineEdit_12->text().toInt());
    QString x = ui->lineEdit_15->text();
    if(ui->radioButton->isChecked())
    {
        if(O.Modifier_Adr(x))
        {
            ui->tableView->setModel(cl.Afficher());
            ui->tabWidget->setCurrentIndex(0);
        }
    }
    else
    {
        if(O.Modifier_Num(x))
        {
            ui->tableView->setModel(cl.Afficher());
            ui->tabWidget->setCurrentIndex(0);
        }
    }
    ui->lineEdit_12->clear();
    ui->lineEdit_15->clear();
}

void MainWindow::on_pushButton_5_clicked()
{
    int id = ui->lineEdit->text().toInt();
    int id_client = ui->lineEdit_3->text().toInt();
    QString points = ui->lineEdit_2->text();

    Carte O(id,id_client,points);
    if(O.verif())
    {
        if(!O.verif_cl())
        {
            if(O.Ajouter())
            {
                ui->tableView_2->setModel(cr.Afficher());
                ui->tabWidget_2->setCurrentIndex(0);
            }
        }
        else
        {
            QMessageBox::critical(this,"ajouter carte","id client n'exist pas !");
        }
    }
    else
    {
        QMessageBox::critical(this,"ajouter carte","id exist !");
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    int id = ui->lineEdit_4->text().toInt();

    Carte O;
    O.setID(id);
    if(O.Supprimer())
    {
        ui->tableView_2->setModel(cr.Afficher());
        ui->tabWidget_2->setCurrentIndex(0);
    }
}

void MainWindow::on_pushButton_10_clicked()
{
    int id = ui->lineEdit_13->text().toInt();
    QString points = ui->lineEdit_14->text();

    Carte O;
    O.setID(id);
    if(O.Modifier(points))
    {
        ui->tableView_2->setModel(cr.Afficher());
        ui->tabWidget_2->setCurrentIndex(0);
    }
}

void MainWindow::on_tableView_3_activated(const QModelIndex &index)
{
    ui->label_12->setText(index.data().toString());
}

void MainWindow::on_pushButton_12_clicked()
{
    ui->tableView_2->setModel(cr.Trier_points());
}

void MainWindow::on_pushButton_11_clicked()
{
    ui->tableView_2->setModel(cr.Afficher());
}

void MainWindow::on_lineEdit_10_textChanged(const QString &arg1)
{
    if(arg1 == "")
    {
        ui->tableView->setModel(cl.Afficher());
    }
    else
    {
        ui->tableView->setModel(cl.recheche(arg1));
    }
}

void MainWindow::on_tabWidget_2_currentChanged(int index)
{
    /*ui->tableView->setModel(cl.Afficher());
    ui->tableView_3->setModel(cl.Afficher_ID());*/
}
