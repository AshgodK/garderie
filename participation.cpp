
#include "participation.h"
#include <QSystemTrayIcon>

participation::participation()
{

}

bool participation::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(id_a);
    QString res2 = QString::number(id_e);
    query.prepare("INSERT INTO participation(id_e,id_a)""VALUES (:id_e,:id_a)");
    query.bindValue(":id_a",res);
    query.bindValue(":id_e",res2);
    return query.exec();
}


QSqlQueryModel * participation::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM participation");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_p"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("id_a"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("id_e"));
    return model;
}


bool participation::supprimer(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("DELETE FROM participation WHERE id_p = :id");
    query.bindValue(":id",res);
    return query.exec();
}

bool participation::modifier(int id)
{
    QSqlQuery query;
    QString rese = QString::number(id);
    QString res = QString::number(id_a);
    QString res2 = QString::number(id_e);

    query.prepare("UPDATE participation SET id_a=:id_a,id_e=:id_e WHERE id_p=:id");
    query.bindValue(":id_a",res);
    query.bindValue(":id_e",res2);
    query.bindValue(":id",rese);

    return query.exec();

}


QSqlQueryModel * participation::tri_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * FROM participation ORDER BY ID_p ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_p"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("id_a"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("id_e"));

    return model;
}

QSqlQueryModel * participation::tri_id_a()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * FROM participation ORDER BY id_a ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_p"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("id_a"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("id_e"));

    return model;
}

QSqlQueryModel * participation::tri_id_e()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * FROM participation ORDER BY id_e ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_p"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("id_a"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("id_e"));

    return model;
}

QSqlQueryModel *participation::displayClause(QString cls)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM participation " +cls);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_p"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("id_a"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("id_e"));


    return model;
}


void participation::notification()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    //notifyIcon->setIcon()
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des participation ","participation effectue ",QSystemTrayIcon::Information,15000);
}


