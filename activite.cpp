
#include "activite.h"
#include <QPainter>
#include <QPdfWriter>
#include <QDesktopServices>
#include<QMessageBox>
activite::activite()
{

}

activite::activite(int a,int b,QString c,QString d,QString e,QString f,QString g)
{
    id_a=a;
    nbrP=b;
    description=c;
    adresse=d;
    etat=e;
    type=f;
    nom=g;


}

bool activite::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(id_a);
    QString res1 = QString::number(nbrP);


    query.prepare("INSERT INTO activite(id_a,nom,description,adresse,type,etat,nbrP)""VALUES (:id_a,:nom,:description,:adresse,:type,:etat,:nbrP)");
    query.bindValue(":id_a",res);
    query.bindValue(":nom",nom);
    query.bindValue(":description",description);
    query.bindValue(":adresse",adresse);
    query.bindValue(":type",type);
    query.bindValue(":etat",etat);
    query.bindValue(":nbrP",res1);



    return query.exec();
}

QSqlQueryModel * activite::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM activite");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_a"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("description"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("etat"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("nbrP"));
    return model;
}

bool activite::supprimer(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("DELETE FROM activite WHERE id_a = :id");
    query.bindValue(":id",res);
    return query.exec();
}

bool activite::modifier(int id)
{
    QSqlQuery query;
    QString res = QString::number(id);
    QString res1 = QString::number(nbrP);

    query.prepare("UPDATE activite SET nom=:nom,description=:description,adresse=:adresse,type=:type,etat=:etat,nbrP=:nbrP WHERE id_a=:id");
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":description",description);
    query.bindValue(":adresse",adresse);
    query.bindValue(":type",type);
    query.bindValue(":etat",etat);
    query.bindValue(":nbrP",nbrP);

    return query.exec();

}

QSqlQueryModel * activite::tri_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * FROM activite ORDER BY ID_a ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_a"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("description"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("etat"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("nbrP"));
    return model;
}


QSqlQueryModel * activite::tri_nom()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * FROM activite ORDER BY nom ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_a"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("description"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("etat"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("nbrP"));
    return model;
}

QSqlQueryModel * activite::tri_nbrP()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * FROM activite ORDER BY nbrP ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_a"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("description"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("etat"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("nbrP"));
    return model;
}

QSqlQueryModel *activite::displayClause(QString cls)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM activite " +cls);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_a"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("description"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("etat"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("nbrP"));

    return model;
}

void activite::gen_pdf()
{
    QPdfWriter pdf("D:/UNI/QTP/credit/PDF/Pdfactivite.pdf");
        QPainter painter(&pdf);
        int i = 4000;
        painter.setPen(Qt::blue);
        painter.setFont(QFont("Arial", 30));
        painter.drawText(3300,1200,"Liste Des Activites");
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 50));
        // painter.drawText(1100,2000,afficheDC);
        painter.drawRect(1500,200,7300,2600);
        //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
        painter.drawRect(0,3000,9600,500);
        painter.setFont(QFont("Arial", 9));
        painter.drawText(1300,3300,"ID_a");
        painter.drawText(2300,3300,"NOM");
        painter.drawText(3300,3300,"desc");
        painter.drawText(4300,3300,"type");
        painter.drawText(5300,3300,"adr");
        painter.drawText(6300,3300,"etat");
        painter.drawText(7300,3300,"nbrP");




        QSqlQuery query;
        query.prepare("select * from activite");
        query.exec();
        while (query.next())
        {
            painter.drawText(1300,i,query.value(0).toString());
            painter.drawText(2300,i,query.value(1).toString());
            painter.drawText(3300,i,query.value(2).toString());
            painter.drawText(4300,i,query.value(3).toString());
            painter.drawText(5300,i,query.value(4).toString());
            painter.drawText(6300,i,query.value(5).toString());
            painter.drawText(7300,i,query.value(6).toString());




            i = i +500;
        }
        painter.end();

        //ptmp.notification_pdf();


}
