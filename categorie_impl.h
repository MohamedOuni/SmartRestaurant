#ifndef CATEGORIE_IMPL_H
#define CATEGORIE_IMPL_H
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QDate>
#include <QTableView>
class Categorie_Impl
{

   QString nom ;
public:
    Categorie_Impl();
      Categorie_Impl(QString);
      QString getNom() {return nom;}
QStringList getNames();
      //setters
      void setNom(QString nom){this->nom=nom;}
      bool ajouter(QString);
      QSqlTableModel *supprimer();
      bool recherche();
      QSqlTableModel* afficher();
      void cleartable(QTableView * table);
      void recherche(QTableView * tabl, QString);
};

#endif // CATEGORIE_IMPL_H
