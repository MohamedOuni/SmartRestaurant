#ifndef PERSONNEL_H
#define PERSONNEL_H
#include <QString>
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlTableModel>

class Personnel
{
public:
//test   
Personnel();
    Personnel(QString,QString,QString,QString,QString,QString);
    QString getcin();
    QString gettel();
    QString getservice();
    QString getnom();
    QString getmail();
    QString getmot_de_passe();
    void setcin(QString);
    void settel(QString);
    void setservice(QString);
    void setnom(QString);
    void setmail(QString);
    void setmot_de_passe(QString);
    bool ajouter();
    //QSqlQueryModel * afficher();
    QSqlTableModel * afficher();
    QSqlQueryModel * afficher_CIN();
    QSqlQueryModel * afficher_NOM();
    bool supprimer(QString);
    void cleartable(QTableView * table);
    void recherche(QTableView * tabl, QString);


private:
    QString tel,cin;
    QString nom, mail, service,mot_de_passe;
};

#endif // PERSONNEL_H
