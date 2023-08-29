
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>

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



void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_clicked()
{

    ptmp.set_nom(ui->lineEdit_2->text());
    ptmp.set_prenom(ui->lineEdit_3->text());
    ptmp.set_class(ui->lineEdit_4->text());
    ptmp.set_sexe(ui->lineEdit_6->text());
    ptmp.set_adr(ui->lineEdit_7->text());
    ptmp.set_tel(ui->lineEdit_8->text());
    ptmp.set_email(ui->lineEdit_9->text());


    bool test=ptmp.ajouter();
    if(!test)
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                 QObject::tr("ajouté avec succes.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        //ptmp.notification_ajoutmagasin();


    }
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                              QObject::tr("error.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tableView->setModel(ptmp.afficher());
}

