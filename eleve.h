
#ifndef ELEVE_H
#define ELEVE_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>



class eleve
{
public:
    eleve();

    eleve(int,QString,QString,QString,QString,QString,QString,QString);
    int get_id(){return id_e;}
    QString get_nom(){return nom;}
    QString get_prenom(){return prenom;}
    QString get_class(){return classe;}
    QString get_sexe(){return sexe;}
    QString get_adresse(){return adresse;}
    QString get_num_tel(){return num_tel;}
    QString get_email(){return email;}

    //Setters
    void set_id(int a){id_e=a;}
    void set_nom(QString b){nom=b;}
    void set_adr(QString f){adresse=f;}
    void set_prenom(QString a){prenom=a;}
    void set_email(QString e){email=e;}
    void set_class(QString c){classe=c;}
    void set_sexe(QString s){sexe=s;}
    void set_tel(QString t){num_tel=t;}


    //other functions
    QSqlQueryModel * afficher();
    bool ajouter();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel *tri_class();
    QSqlQueryModel *tri_id();
    QSqlQueryModel *tri_nom();
    QSqlQueryModel *displayClause(QString cls);
    void notification_ajoutEleve();
    void notification_suppEleve();
    void notification_modifEleve();
    void notification_pdf();
    QVector<double> statistiques();
    void makePlot();



private:
    int id_e;

    QString nom;
    QString prenom;
    QString classe;
    QString email;
    QString num_tel;
    QString sexe;
    QString adresse;

};

#endif // ELEVE_H
