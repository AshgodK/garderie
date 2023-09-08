
#ifndef PARTICIPATION_H
#define PARTICIPATION_H

#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "eleve.h"
#include "activite.h"


class participation
{
public:
    participation();
    int get_id_p(){return id_p;}
    int get_id_e(){return id_e;}
    int get_id_a(){return id_a;}

    void set_id_p(int p){id_p=p;}
    void set_id_e(int e){id_e=e;}
    void set_id_a(int a){id_a=a;}

    QSqlQueryModel * afficher();
    bool ajouter();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel *tri_id_a();
    QSqlQueryModel *tri_id();
    QSqlQueryModel *tri_id_e();
    QSqlQueryModel *displayClause(QString cls);

    void notification();
    QVector<double> statistiques();
    void makePlot();


private:
    int id_p;
    int id_e;
    int id_a;
};

#endif // PARTICIPATION_H
