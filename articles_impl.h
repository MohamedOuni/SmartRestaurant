#ifndef ARTICLES_IMPL_H
#define ARTICLES_IMPL_H
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QDate>
#include <QTableView>

class articles_impl
{
    QString nom ;
    int quantite;

 public:
     articles_impl();
       articles_impl(QString,int);
       QString getNom() {return nom;}
        int getQuantite() {return quantite;}

       //setters
       void setNom(QString nom){this->nom=nom;}
       void setQuantite(int quantite){this->quantite=quantite;}



       bool ajouter(QString,int);
       QSqlTableModel *supprimer();
       bool recherche();
       QSqlTableModel* afficher();
       void cleartable(QTableView * table);
       void recherche(QTableView * tabl, QString);
       void verifier();
       void telecharger();


};

#endif // ARTICLES_IMPL_H
