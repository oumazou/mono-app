#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "connection.h"
#include "client.h"
#include "carte.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_10_clicked();

    void on_tableView_3_activated(const QModelIndex &index);

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void on_lineEdit_10_textChanged(const QString &arg1);

    void on_tabWidget_2_currentChanged(int index);

private:
    Connection c;
    Client cl;
    Carte cr;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
