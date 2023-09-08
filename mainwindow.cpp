
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include <QPainter>
#include <QPdfWriter>
#include <QDesktopServices>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
#include <QVector>
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QUrl>
#include "qcustomplot.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

           ui->lineEdit_Ele_numTel->setValidator(new QIntValidator(10000000,99999999,this));

           email_regex=QRegExp("^[0-9a-zA-Z]+([0-9a-zA-Z]*[-._+])*[0-9a-zA-Z]+@[0-9a-zA-Z]+([-.][0-9a-zA-Z]+)*([0-9a-zA-Z]*[.])[a-zA-Z]{2,6}$");
            chaine_regex=QRegExp("[a-zA-Z ]{2,20}$");




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
    ui->tableView_eleve->setModel(ptmp.afficher());
}


void MainWindow::on_pushButton_to_act_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->tableView_act->setModel(ptmp1.afficher());
}


void MainWindow::on_pushButton_to_part_clicked()
{
    QSqlQuery q;
    ui->comboBox_id_act->clear();
    ui->comboBox_id_eleve->clear();

    q.prepare("SELECT id_a FROM activite ");
    q.exec();
    while (q.next())
    {

        int id = q.value(0).toInt();

                   ui->comboBox_id_act->addItem(QString::number(id));

    }

    q.prepare("SELECT id_e FROM eleve ");
    q.exec();
    while (q.next())
    {

        int id = q.value(0).toInt();
                   ui->comboBox_id_eleve->addItem(QString::number(id));

    }
    ui->stackedWidget->setCurrentIndex(2);
    ui->tableView_particp->setModel(ptmp2.afficher());



}


void MainWindow::on_pushButton_ajout_el_clicked()
{
    if(chaine_regex.exactMatch(ui->lineEdit_Ele_nom->text())&&chaine_regex.exactMatch(ui->lineEdit_Ele_prenom->text())&&email_regex.exactMatch(ui->lineEdit_Ele_email->text())&&(ui->lineEdit_Ele_sexe->text()=="female"||ui->lineEdit_Ele_sexe->text()=="male"))



    {
        ptmp.set_nom(ui->lineEdit_Ele_nom->text());
        ptmp.set_prenom(ui->lineEdit_Ele_prenom->text());
        ptmp.set_class(ui->lineEdit_Ele_class->text());
        ptmp.set_sexe(ui->lineEdit_Ele_sexe->text());
        ptmp.set_adr(ui->lineEdit_Ele_adress->text());
        ptmp.set_tel(ui->lineEdit_Ele_numTel->text());
        ptmp.set_email(ui->lineEdit_Ele_email->text());
        ptmp.set_age(ui->spinBox_ele_age->value());
    }
    else
{ QMessageBox::warning(nullptr, QObject::tr("input invalid"),
                           QObject::tr("check input.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);}
  //ptmp.notification_ajoutmagasin();}

    bool test=ptmp.ajouter();
    if(test)
    {


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
    int age;
    age=ui->tableView_eleve->model()->data(ui->tableView_eleve->model()->index(ui->tableView_eleve->currentIndex().row(),8)).toInt();
    ui->spinBox_ele_age->setValue(age);

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
     ptmp.set_age(ui->spinBox_ele_age->value());

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
    if((ui->lineEdit_act_etat->text()=="en cours"||ui->lineEdit_act_etat->text()=="fini"))


    {
        ptmp1.set_nom(ui->lineEdit_act_nom->text());
        ptmp1.set_adr(ui->lineEdit_act_adr->text());
        ptmp1.set_description(ui->lineEdit_act_desc->text());
        ptmp1.set_type(ui->lineEdit_act_type->text());
        ptmp1.set_etat(ui->lineEdit_act_etat->text());
    }
    else{
        QMessageBox::warning(nullptr, QObject::tr("input invlid"),
                                 QObject::tr("check etat.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }



    bool test=ptmp1.ajouter();
    if(test)
    {

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
        ui->tableView_eleve->setModel(ptmp.displayClause("WHERE (id_e LIKE '%"+a+"%') or (nom LIKE '%"+a+"%') or (classe LIKE '%"+a+"%') "));
    }
    else
        ui->tableView_eleve->setModel(ptmp.afficher());
}








void MainWindow::on_lineEdit_act_sea_id_textChanged(const QString &arg1)
{
    if(ui->lineEdit_act_sea_id->text()!="")
    {
        QString a=ui->lineEdit_act_sea_id->text();
        ui->tableView_act->setModel(ptmp1.displayClause("WHERE (id_a LIKE '%"+a+"%') or (nom LIKE '%"+a+"%') or (type LIKE '%"+a+"%') "));
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
              QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/RayenSabri/Desktop/achref qt/garderie/PDF/Pdfactivite.pdf"));


        }

}


void MainWindow::on_pushButton_eleve_pdf_clicked()
{
        ptmp.genPdf();
        int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
        if (reponse == QMessageBox::Yes)
        {
              QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/RayenSabri/Desktop/achref qt/garderie/PDF/PdfEleve.pdf"));


        }

}
/*
void MainWindow::makePlot()
{
    // prepare data:
    QVector<double> x3(5), y3(20);
    for (int i=0; i<x3.size(); ++i)
    {
      x3[i] = i+1;

    }
    for (int i=0; i<y3.size(); ++i)
    {
      y3[i] = i+1;

    }

    QCPBars *bars1 = new QCPBars(ui->customplot->xAxis, ui->customplot->yAxis);
    bars1->setWidth(2/(double)x3.size());
    bars1->setData(x3, ptmp.statistiques());////fonction statistiques
    bars1->setPen(Qt::NoPen);
    bars1->setBrush(QColor(200, 40, 60, 170));
    ui->customplot->replot();


    // move bars above graphs and grid below bars:
    ui->customplot->addLayer("abovemain", ui->customplot->layer("main"), QCustomPlot::limAbove);
    ui->customplot->addLayer("belowmain", ui->customplot->layer("main"), QCustomPlot::limBelow);
    ui->customplot->xAxis->grid()->setLayer("belowmain");
    ui->customplot->yAxis->grid()->setLayer("belowmain");

    // set some pens, brushes and backgrounds:
    QVector<double> Ticks;
    Ticks<<1<<2<<3<<4<<5<<6<<7;//////
    QVector<QString> labels;
    labels<<"0-400"<<"400-700"<<"700-1000"<<"1000-1500"<<"1500+";////////
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(Ticks,labels);
    ui->customplot->xAxis->setTicker(textTicker);
    ui->customplot->xAxis->setSubTicks(false);
    ui->customplot->xAxis->setTickLength(0,4);
    ui->customplot->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->customplot->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->customplot->xAxis->setTickPen(QPen(Qt::transparent, 1));
    ui->customplot->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->customplot->xAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->customplot->yAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->customplot->xAxis->setTickLabelColor(Qt::white);
    ui->customplot->yAxis->setTickLabelColor(Qt::white);
    ui->customplot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customplot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customplot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customplot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customplot->xAxis->grid()->setSubGridVisible(true);
    ui->customplot->yAxis->grid()->setSubGridVisible(true);
    ui->customplot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customplot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customplot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->customplot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(00, 50, 80));
    plotGradient.setColorAt(1, QColor(10, 20, 50));
    ui->customplot->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(10, 50, 80));//
    axisRectGradient.setColorAt(1, QColor(0, 0, 30));
    ui->customplot->axisRect()->setBackground(axisRectGradient);

    ui->customplot->rescaleAxes();
    ui->customplot->xAxis->setRange(0, 7);
    ui->customplot->yAxis->setRange(0, 10);


}

*/


void MainWindow::makePlot()
{
    // prepare data:
    QVector<double> x3(5), y3(20);
    for (int i=0; i<x3.size(); ++i)
    {
      x3[i] = i+1;


    }
    for (int i=0; i<y3.size(); ++i)
    {
      y3[i] = i+1;

    }

    QCPBars *bars1 = new QCPBars(ui->customplot->xAxis, ui->customplot->yAxis);
    bars1->setWidth(2/(double)x3.size());
    bars1->setData(x3, ptmp.statistiques());////fonction statistiques
    bars1->setPen(Qt::NoPen);
    bars1->setBrush(QColor(200, 40, 60, 170));
    ui->customplot->replot();

    // move bars above graphs and grid below bars:
    ui->customplot->addLayer("abovemain", ui->customplot->layer("main"), QCustomPlot::limAbove);
    ui->customplot->addLayer("belowmain", ui->customplot->layer("main"), QCustomPlot::limBelow);
    ui->customplot->xAxis->grid()->setLayer("belowmain");
    ui->customplot->yAxis->grid()->setLayer("belowmain");

    // set some pens, brushes and backgrounds:
    QVector<double> Ticks;
    Ticks<<1<<2<<3<<4<<5<<6<<7;//////
    QVector<QString> labels;
    labels<<"4<"<<"4-7"<<"7-10"<<"10-13"<<"14+";////////
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(Ticks,labels);
    ui->customplot->xAxis->setTicker(textTicker);
    ui->customplot->xAxis->setSubTicks(false);
    ui->customplot->xAxis->setTickLength(0,4);
    ui->customplot->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->customplot->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->customplot->xAxis->setTickPen(QPen(Qt::transparent, 1));
    ui->customplot->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->customplot->xAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->customplot->yAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->customplot->xAxis->setTickLabelColor(Qt::white);
    ui->customplot->yAxis->setTickLabelColor(Qt::white);
    ui->customplot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customplot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customplot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customplot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customplot->xAxis->grid()->setSubGridVisible(true);
    ui->customplot->yAxis->grid()->setSubGridVisible(true);
    ui->customplot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customplot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customplot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->customplot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(00, 50, 80));
    plotGradient.setColorAt(1, QColor(10, 20, 50));
    ui->customplot->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(10, 50, 80));//
    axisRectGradient.setColorAt(1, QColor(0, 0, 30));
    ui->customplot->axisRect()->setBackground(axisRectGradient);

    ui->customplot->rescaleAxes();
    ui->customplot->xAxis->setRange(0, 7);
    ui->customplot->yAxis->setRange(0, 10);


}



void MainWindow::on_pushButton_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
    ui->customplot->clearPlottables();
    MainWindow::makePlot();
    MainWindow::makePlot();

}

void MainWindow::on_pushButton_stat_act_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT etat FROM activite WHERE  etat='en cours' ");
        float countC=model->rowCount();
        model->setQuery("SELECT etat FROM activite WHERE  etat='fini' ");
        float countEC=model->rowCount();

        float total=countC+countEC;

                QPieSeries *series = new QPieSeries();
                series->append("en cours",countC);
                series->append("fini",countEC);

                if (countC!=0)
                {QPieSlice *slice = series->slices().at(0);
                    slice->setLabel(QString("en cours").arg(100*slice->percentage(),3,'f',1));
                    slice->setLabelVisible();
                    slice->setPen(QPen(Qt::black));}
                if ( countEC!=0)
                {
                    // Add label, explode and define brush for 2nd slice
                    QPieSlice *slice1 = series->slices().at(1);
                    //slice1->setExploded();
                    slice1->setLabelVisible();
                    slice1->setBrush(QColor(Qt::cyan));
                }


                // Create the chart widget
                QChart *chart = new QChart();
                // Add data to chart with title and hide legend
                chart->legend()->show();
                chart->addSeries(series);
                chart->setTitle(" TOTAL: "+ QString::number(total)+"  en cours: "+ QString::number(countC)+"  fini: "+ QString::number(countEC));

                // Used to display the chart
                QChartView *chartView = new QChartView(chart);
                chartView->setRenderHint(QPainter::Antialiasing);
                chartView->resize(1000,500);
                for(auto slice : series->slices())
                    slice->setLabel(QString("%1%").arg(100*slice->percentage(),3,'f',1));
                chartView->show();
}

void MainWindow::on_pushButton_ajout_part_clicked()
{
    ptmp2.set_id_a(ui->comboBox_id_act->currentText().toInt());
    ptmp2.set_id_e(ui->comboBox_id_eleve->currentText().toInt());




    bool test=ptmp2.ajouter();
    if(test)
    {
        QSqlQuery q;

     QString rese =ui->comboBox_id_act->currentText();

        q.prepare("UPDATE activite SET nbrp=nbrp+1 WHERE id_a=:id_a");
        q.bindValue(":id_a",rese);
        q.exec();

        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                 QObject::tr("ajouté avec succes.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        ptmp2.notification();


    }
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                              QObject::tr("error.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tableView_particp->setModel(ptmp2.afficher());
}

void MainWindow::on_pushButton_Del_part_clicked()
{
    int id_del;
    id_del=ui->tableView_particp->model()->data(ui->tableView_particp->model()->index(ui->tableView_particp->currentIndex().row(),0)).toInt();
    bool test=ptmp2.supprimer(id_del);
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
    ui->tableView_particp->setModel(ptmp2.afficher());
}

void MainWindow::on_tableView_particp_doubleClicked(const QModelIndex &index)
{
    int id=ui->tableView_particp->model()->data(ui->tableView_particp->model()->index(ui->tableView_particp->currentIndex().row(),1)).toInt();
    QString res = QString::number(id);
    ui->comboBox_id_act->setCurrentText(res);
    int id2=ui->tableView_particp->model()->data(ui->tableView_particp->model()->index(ui->tableView_particp->currentIndex().row(),2)).toInt();
    QString res2 = QString::number(id2);
    ui->comboBox_id_eleve->setCurrentText(res2);
}

void MainWindow::on_pushButton_2_clicked()
{

    int id_up;
    id_up=ui->tableView_particp->model()->data(ui->tableView_particp->model()->index(ui->tableView_particp->currentIndex().row(),0)).toInt();
    ptmp2.set_id_a(ui->comboBox_id_act->currentText().toInt());
    ptmp2.set_id_e(ui->comboBox_id_eleve->currentText().toInt());


    bool test=ptmp2.modifier(id_up);
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
    ui->tableView_particp->setModel(ptmp2.afficher());
}

void MainWindow::on_pushButton_mod_part_clicked()
{
    int id_up;
    id_up=ui->tableView_particp->model()->data(ui->tableView_particp->model()->index(ui->tableView_particp->currentIndex().row(),0)).toInt();
    ptmp2.set_id_a(ui->comboBox_id_act->currentText().toInt());
    ptmp2.set_id_e(ui->comboBox_id_eleve->currentText().toInt());


    bool test=ptmp2.modifier(id_up);
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
    ui->tableView_particp->setModel(ptmp2.afficher());
}

void MainWindow::on_pushButton_tri_part_act_clicked()
{
    ui->tableView_particp->setModel(ptmp2.tri_id_a());
}

void MainWindow::on_pushButton_tri_part_eleve_clicked()
{
    ui->tableView_particp->setModel(ptmp2.tri_id_e());
}
