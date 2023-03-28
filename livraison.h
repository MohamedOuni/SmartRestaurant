#ifndef livraison_H
#define livraison_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QTableView>

class livraison
{
public:
    livraison();
    livraison(QString,QString,QString,QString,QString,QString);
     QString getcommande();
    QString getregion();
    QString gettel();
    QString getnom();
    QString getville();
    QString getadresse();


    void setcommande(QString);
    void setregion(QString);
    void settel(QString);
    void setnom(QString);
    void setville(QString);
    void setadresse(QString);

    bool ajouter();
    QSqlTableModel * afficher();
    bool supprimer(QString commande);
    bool modifier();
    void cleartable(QTableView * table);
    void recherche(QTableView * tabl, QString);



private:
    QString tel,region,ville,adresse;
    QString commande, nom;
};

#endif // PERSONNEL_H
