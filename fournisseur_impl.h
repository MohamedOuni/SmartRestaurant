#ifndef FOURNISSEUR_IMPL_H
#define FOURNISSEUR_IMPL_H
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QDate>
#include <QTableView>

class fournisseur_impl
{
    QString categorie,nom_f ;
    int tel;

public:
    fournisseur_impl();
    fournisseur_impl(QString,QString,int);
    QString getNom() {return nom_f;}
    QString getCategorie() {return categorie;}
     int getQuantite() {return tel;}

    //setters
    void setNom_f(QString nom){this->nom_f=nom;}
    void setCategorie(QString cat){this->categorie=cat;}
    void setTel(int tel){this->tel=tel;}



    bool ajouter(QString,QString,int);
    QSqlTableModel *supprimer();
    bool recherche();
    QSqlTableModel* afficher();
    void cleartable(QTableView * table);
    void recherche(QTableView * tabl, QString);
};

#endif // FOURNISSEUR_IMPL_H
