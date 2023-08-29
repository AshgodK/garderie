
#include "activite.h"

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
