
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include <QPainter>
#include <QPdfWriter>
#include <QDesktopServices>

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

///ajouter
/*
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
    if(test)
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
*/






void MainWindow::on_pushButton_to_eleve_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_to_act_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_to_part_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_ajout_el_clicked()
{
    ptmp.set_nom(ui->lineEdit_Ele_nom->text());
    ptmp.set_prenom(ui->lineEdit_Ele_prenom->text());
    ptmp.set_class(ui->lineEdit_Ele_class->text());
    ptmp.set_sexe(ui->lineEdit_Ele_sexe->text());
    ptmp.set_adr(ui->lineEdit_Ele_adress->text());
    ptmp.set_tel(ui->lineEdit_Ele_numTel->text());
    ptmp.set_email(ui->lineEdit_Ele_email->text());


    bool test=ptmp.ajouter();
    if(test)
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
    ui->tableView_eleve->setModel(ptmp.afficher());
}


void MainWindow::on_pushButton_del_el_clicked()
{
    int id_del;
    id_del=ui->tableView_eleve->model()->data(ui->tableView_eleve->model()->index(ui->tableView_eleve->currentIndex().row(),0)).toInt();
    bool test=ptmp.supprimer(id_del);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                 QObject::tr("supprimé avec succes.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        //ptmp.notification_suppmagasin();

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                              QObject::tr("error.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tableView_eleve->setModel(ptmp.afficher());
}

//////CHECK
void MainWindow::on_tableView_eleve_doubleClicked(const QModelIndex &index)
{
    int id=ui->tableView_eleve->model()->data(ui->tableView_eleve->model()->index(ui->tableView_eleve->currentIndex().row(),0)).toInt();
    QString res = QString::number(id);
    //ui->lineEdit_id_e->setText(res);
    QString nom;
    nom=ui->tableView_eleve->model()->data(ui->tableView_eleve->model()->index(ui->tableView_eleve->currentIndex().row(),1)).toString();
    ui->lineEdit_Ele_nom->setText(nom);
    QString prenom;
    prenom=ui->tableView_eleve->model()->data(ui->tableView_eleve->model()->index(ui->tableView_eleve->currentIndex().row(),2)).toString();
    ui->lineEdit_Ele_prenom->setText(prenom);
    QString adr;
    adr=ui->tableView_eleve->model()->data(ui->tableView_eleve->model()->index(ui->tableView_eleve->currentIndex().row(),3)).toString();
    ui->lineEdit_Ele_adress->setText(adr);
    QString classe;
    classe=ui->tableView_eleve->model()->data(ui->tableView_eleve->model()->index(ui->tableView_eleve->currentIndex().row(),4)).toString();
    ui->lineEdit_Ele_class->setText(classe);
    QString mail;
    mail=ui->tableView_eleve->model()->data(ui->tableView_eleve->model()->index(ui->tableView_eleve->currentIndex().row(),5)).toString();
    ui->lineEdit_Ele_email->setText(mail);
    QString num;
    num=ui->tableView_eleve->model()->data(ui->tableView_eleve->model()->index(ui->tableView_eleve->currentIndex().row(),6)).toString();
    ui->lineEdit_Ele_numTel->setText(num);
    QString sexe;
    sexe=ui->tableView_eleve->model()->data(ui->tableView_eleve->model()->index(ui->tableView_eleve->currentIndex().row(),7)).toString();
    ui->lineEdit_Ele_sexe->setText(sexe);

}


void MainWindow::on_pushButton_mod_eleve_clicked()
{
    int id_up;
    id_up=ui->tableView_eleve->model()->data(ui->tableView_eleve->model()->index(ui->tableView_eleve->currentIndex().row(),0)).toInt();
    ptmp.set_nom(ui->lineEdit_Ele_nom->text());
    ptmp.set_prenom(ui->lineEdit_Ele_prenom->text());
    ptmp.set_adr(ui->lineEdit_Ele_adress->text());
    ptmp.set_class(ui->lineEdit_Ele_class->text());
    ptmp.set_email(ui->lineEdit_Ele_email->text());
    ptmp.set_sexe(ui->lineEdit_Ele_sexe->text());
    ptmp.set_tel(ui->lineEdit_Ele_numTel->text());

    bool test=ptmp.modifier(id_up);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                 QObject::tr("modifie avec succes.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        //ptmp1.notification_modifparking();

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                              QObject::tr("error.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tableView_eleve->setModel(ptmp.afficher());
}


void MainWindow::on_pushButton_ajout_act_clicked()
{
    ptmp1.set_nom(ui->lineEdit_Ele_nom->text());
    ptmp1.set_adr(ui->lineEdit_act_adr->text());
    ptmp1.set_description(ui->lineEdit_act_desc->text());
    ptmp1.set_type(ui->lineEdit_act_type->text());
    ptmp1.set_etat(ui->lineEdit_act_etat->text());
    ptmp1.set_nbrP(ui->lineEdit_act_nbrP->text().toInt());



    bool test=ptmp1.ajouter();
    if(test)
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
    ui->tableView_act->setModel(ptmp1.afficher());
}


void MainWindow::on_pushButton_del_act_clicked()
{
    int id_del;
    id_del=ui->tableView_act->model()->data(ui->tableView_act->model()->index(ui->tableView_act->currentIndex().row(),0)).toInt();
    bool test=ptmp1.supprimer(id_del);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                 QObject::tr("supprimé avec succes.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        //ptmp.notification_suppmagasin();

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                              QObject::tr("error.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tableView_act->setModel(ptmp1.afficher());
}


void MainWindow::on_tableView_act_doubleClicked(const QModelIndex &index)
{
    int id=ui->tableView_act->model()->data(ui->tableView_act->model()->index(ui->tableView_act->currentIndex().row(),0)).toInt();
    QString res = QString::number(id);
    //ui->lineEdit_id_e->setText(res);
    QString nom;
    nom=ui->tableView_act->model()->data(ui->tableView_act->model()->index(ui->tableView_act->currentIndex().row(),1)).toString();
    ui->lineEdit_act_nom->setText(nom);
    QString desc;
    desc=ui->tableView_act->model()->data(ui->tableView_act->model()->index(ui->tableView_act->currentIndex().row(),2)).toString();
    ui->lineEdit_act_desc->setText(desc);
    QString adr;
    adr=ui->tableView_act->model()->data(ui->tableView_act->model()->index(ui->tableView_act->currentIndex().row(),3)).toString();
    ui->lineEdit_act_adr->setText(adr);
    QString type;
    type=ui->tableView_act->model()->data(ui->tableView_act->model()->index(ui->tableView_act->currentIndex().row(),4)).toString();
    ui->lineEdit_act_type->setText(type);
    QString etat;
    etat=ui->tableView_act->model()->data(ui->tableView_act->model()->index(ui->tableView_act->currentIndex().row(),5)).toString();
    ui->lineEdit_act_etat->setText(etat);
    QString nbrp;
    nbrp=ui->tableView_act->model()->data(ui->tableView_act->model()->index(ui->tableView_act->currentIndex().row(),6)).toString();
    ui->lineEdit_act_nbrP->setText(nbrp);


}


void MainWindow::on_pushButton_mod_act_clicked()
{
    int id_up;
    id_up=ui->tableView_act->model()->data(ui->tableView_act->model()->index(ui->tableView_act->currentIndex().row(),0)).toInt();
    ptmp1.set_nom(ui->lineEdit_act_nom->text());
    ptmp1.set_description(ui->lineEdit_act_desc->text());
    ptmp1.set_adr(ui->lineEdit_act_adr->text());
    ptmp1.set_etat(ui->lineEdit_act_etat->text());
    ptmp1.set_type(ui->lineEdit_act_type->text());
    ptmp1.set_nbrP(ui->lineEdit_act_nbrP->text().toInt());


    bool test=ptmp1.modifier(id_up);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                 QObject::tr("modifie avec succes.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        //ptmp1.notification_modifparking();

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                              QObject::tr("error.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tableView_act->setModel(ptmp1.afficher());
}


void MainWindow::on_pushButton_eleve_triID_clicked()
{
    ui->tableView_eleve->setModel(ptmp.tri_id());
}


void MainWindow::on_pushButton_eleve_tri_class_clicked()
{
    ui->tableView_eleve->setModel(ptmp.tri_class());
}


void MainWindow::on_pushButton_eleve_tri_sexe_clicked()
{
    ui->tableView_eleve->setModel(ptmp.tri_sexe());
}


void MainWindow::on_pushButton_act_triID_clicked()
{
    ui->tableView_act->setModel(ptmp1.tri_id());
}


void MainWindow::on_pushButton_act_trinom_clicked()
{
    ui->tableView_act->setModel(ptmp1.tri_nom());
}


void MainWindow::on_pushButton_act_tri_nbrP_clicked()
{
    ui->tableView_act->setModel(ptmp1.tri_nbrP());
}


void MainWindow::on_lineEdit_eleve_sea_id_textChanged(const QString &arg1)
{
    if(ui->lineEdit_eleve_sea_id->text()!="")
    {
        QString a=ui->lineEdit_eleve_sea_id->text();
        ui->tableView_eleve->setModel(ptmp.displayClause("WHERE (id_e LIKE '%"+a+"%') "));
    }
    else
        ui->tableView_eleve->setModel(ptmp.afficher());
}


void MainWindow::on_lineEdit_eleve_sea_nom_textChanged(const QString &arg1)
{
    if(ui->lineEdit_eleve_sea_nom->text()!="")
    {
        QString a=ui->lineEdit_eleve_sea_nom->text();
        ui->tableView_eleve->setModel(ptmp.displayClause("WHERE (nom LIKE '%"+a+"%') "));
    }
    else
        ui->tableView_eleve->setModel(ptmp.afficher());
}


void MainWindow::on_lineEdit_eleve_sea_classe_textChanged(const QString &arg1)
{
    if(ui->lineEdit_eleve_sea_classe->text()!="")
    {
        QString a=ui->lineEdit_eleve_sea_classe->text();
        ui->tableView_eleve->setModel(ptmp.displayClause("WHERE (classe LIKE '%"+a+"%') "));
    }
    else
        ui->tableView_eleve->setModel(ptmp.afficher());
}


void MainWindow::on_lineEdit_act_sea_id_textChanged(const QString &arg1)
{
    if(ui->lineEdit_act_sea_id->text()!="")
    {
        QString a=ui->lineEdit_act_sea_id->text();
        ui->tableView_act->setModel(ptmp1.displayClause("WHERE (id_a LIKE '%"+a+"%') "));
    }
    else
        ui->tableView_act->setModel(ptmp1.afficher());
}


void MainWindow::on_lineEdit_act_sea_nom_textChanged(const QString &arg1)
{
    if(ui->lineEdit_act_sea_nom->text()!="")
    {
        QString a=ui->lineEdit_act_sea_nom->text();
        ui->tableView_act->setModel(ptmp1.displayClause("WHERE (nom LIKE '%"+a+"%') "));
    }
    else
        ui->tableView_act->setModel(ptmp1.afficher());
}


void MainWindow::on_lineEdit_act_sea_type_textChanged(const QString &arg1)
{
    if(ui->lineEdit_act_sea_type->text()!="")
    {
        QString a=ui->lineEdit_act_sea_type->text();
        ui->tableView_act->setModel(ptmp1.displayClause("WHERE (type LIKE '%"+a+"%') "));
    }
    else
        ui->tableView_act->setModel(ptmp1.afficher());
}


void MainWindow::on_pushButton_act_pdf_clicked()
{
    ptmp1.gen_pdf();
        int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
        if (reponse == QMessageBox::Yes)
        {
              QDesktopServices::openUrl(QUrl::fromLocalFile("D:/UNI/QTP/credit/PDF/Pdfactivite.pdf"));


        }

}


void MainWindow::on_pushButton_eleve_pdf_clicked()
{
        ptmp.genPdf();
        int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
        if (reponse == QMessageBox::Yes)
        {
              QDesktopServices::openUrl(QUrl::fromLocalFile("D:/UNI/QTP/credit/PDF/PdfEleve.pdf"));


        }

}

