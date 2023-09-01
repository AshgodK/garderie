
#ifndef ACTIVITE_H
#define ACTIVITE_H

#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>




class activite
{
public:
    activite();

    activite(int,int,QString,QString,QString,QString,QString);
    int get_id(){return id_a;}
    QString get_nom(){return nom;}
    QString get_description(){return description;}
    QString get_type(){return type;}
    QString get_etat(){return etat;}
    QString get_adresse(){return adresse;}
    int get_nbrP(){return nbrP;}


    //Setters


    /*
     *         int id_a;

    QString nom;
    QString description;
    QString type;
    QString etat;
    int nbrP;
    QString adresse;
      */
    void set_id(int a){id_a=a;}
    void set_nom(QString b){nom=b;}
    void set_adr(QString f){adresse=f;}
    void set_description(QString a){description=a;}
    void set_type(QString e){type=e;}
    void set_etat(QString c){etat=c;}
    void set_nbrP(int s){nbrP=s;}



    //other functions
    QSqlQueryModel * afficher();
    bool ajouter();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel *tri_nbrP();
    QSqlQueryModel *tri_id();
    QSqlQueryModel *tri_nom();
    QSqlQueryModel *displayClause(QString cls);
    void notification_ajoutActivite();
    void notification_suppActivite();
    void notification_modifActivite();
    void notification_pdf();
    QVector<double> statistiques();
    void makePlot();
    void gen_pdf();



private:
    int id_a;

    QString nom;
    QString description;
    QString type;
    QString etat;
    int nbrP;
    QString adresse;




};
#endif // ACTIVITE_H
