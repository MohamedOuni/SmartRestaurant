#ifndef LIVREUR_H
#define LIVREUR_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QTableView>

class livreur
{
public:
    livreur();
    livreur(QString,QString,QString,QString);
     QString getnom();
    QString getcin();
    QString gettel();
    QString getdisponibilite();


    void setnom(QString);
    void setcin(QString);
    void settel(QString);
    void setdisponibilite(QString);

    bool ajouter();
    QSqlTableModel * afficher();
    bool supprimer(QString cin);
    bool modifier();
    void cleartable(QTableView * table);
    void recherche(QTableView * tabl, QString);



private:
    QString tel,cin;
    QString nom, disponibilite;
};

#endif // PERSONNEL_H
