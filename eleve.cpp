
#include "eleve.h"
#include <QPainter>
#include <QPdfWriter>
#include <QDesktopServices>
#include<QMessageBox>
eleve::eleve()
{

}

eleve::eleve(int a,QString b,QString c,QString d,QString e,QString f,QString g,QString h)
{
    id_e=a;
    nom=b;
    prenom=c;
    adresse=d;
    email=e;
    classe=f;
    num_tel=g;
    sexe=h;

}
bool eleve::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(id_e);


    query.prepare("INSERT INTO eleve(id_m,nom,prenom,adresse,email,classe,num_tel,sexe)""VALUES (:id_m,:nom,:prennom,:adresse,:email,:classe,:num_tel,:sexe)");
    query.bindValue(":id_m",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":email",email);
    query.bindValue(":classe",classe);
    query.bindValue(":num_tel",num_tel);
    query.bindValue(":sexe",sexe);


    return query.exec();
}


QSqlQueryModel * eleve::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM eleve");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_e"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("classe"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("email"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("num_tel"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("sexe"));

    return model;
}


bool eleve::supprimer(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("DELETE FROM eleve WHERE id_e = :id");
    query.bindValue(":id",res);
    return query.exec();
}

bool eleve::modifier(int id)
{
    QSqlQuery query;
    QString res = QString::number(id);

    query.prepare("UPDATE eleve SET nom=:nom,prenom=:prenom,adresse=:adresse,email=:email,classe=:classe,num_tel=:num_tel,sexe=:sexe WHERE id_e=:id");
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":email",email);
    query.bindValue(":classe",classe);
    query.bindValue(":num_tel",num_tel);
    query.bindValue(":sexe",sexe);

    return query.exec();

}

void eleve::genPdf()
{
    QPdfWriter pdf("D:/UNI/QTP/credit/PDF/PdfEleve.pdf");
        QPainter painter(&pdf);
        int i = 4000;
        painter.setPen(Qt::blue);
        painter.setFont(QFont("Arial", 30));
        painter.drawText(3300,1200,"Liste Des Eleves");
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 50));
        // painter.drawText(1100,2000,afficheDC);
        painter.drawRect(1500,200,7300,2600);
        //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
        painter.drawRect(0,3000,9600,500);
        painter.setFont(QFont("Arial", 9));
        painter.drawText(300,3300,"ID_e");
        painter.drawText(1300,3300,"NOM");
        painter.drawText(2300,3300,"prenom");
        painter.drawText(3300,3300,"adresse");
        painter.drawText(4300,3300,"classe");
        painter.drawText(5300,3300,"email");
        painter.drawText(6300,3300,"numTel");
        painter.drawText(7300,3300,"sexe");




        QSqlQuery query;
        query.prepare("select * from eleve");
        query.exec();
        while (query.next())
        {
            painter.drawText(300,i,query.value(0).toString());
            painter.drawText(1300,i,query.value(1).toString());
            painter.drawText(2300,i,query.value(2).toString());
            painter.drawText(3300,i,query.value(3).toString());
            painter.drawText(4300,i,query.value(4).toString());
            painter.drawText(5300,i,query.value(5).toString());
            painter.drawText(6300,i,query.value(6).toString());
            painter.drawText(7300,i,query.value(7).toString());




            i = i +500;
        }

        //notification_pdf();
        painter.end();

}

QSqlQueryModel * eleve::tri_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * FROM eleve ORDER BY ID_e ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_e"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("classe"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("email"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("num_tel"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("sexe"));
    return model;
}

QSqlQueryModel * eleve::tri_class()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * FROM eleve ORDER BY classe ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_e"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("classe"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("email"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("num_tel"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("sexe"));
    return model;
}

QSqlQueryModel * eleve::tri_sexe()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * FROM eleve ORDER BY sexe ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_e"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("classe"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("email"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("num_tel"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("sexe"));
    return model;
}

QSqlQueryModel *eleve::displayClause(QString cls)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM eleve " +cls);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_e"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("classe"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("email"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("num_tel"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("sexe"));

    return model;
}




