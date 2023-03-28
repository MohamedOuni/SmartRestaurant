#ifndef MENU_IMPL_H
#define MENU_IMPL_H
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QDate>
#include <QTableView>
class Menu_Impl
{

   QString nom ;
   QString prix;
   int quantite;
public:
   //Constructeurs
      Menu_Impl();
      Menu_Impl(QString,QString);

   //Getters
      QString getNom() {return nom;}
      QString getPrix(){return prix;}

   //setters
      void setNom(QString nom){this->nom=nom;}
       void setPrix(QString p){this->prix=p;}
      bool ajouter(QString,QString);
      QSqlTableModel *supprimer();
      bool recherche();
      QSqlTableModel* afficher();
      void cleartable(QTableView * table);
      void recherche(QTableView * tabl, QString);
};

#endif // MENU_IMPL_H
