
#include "eleve.h"

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


