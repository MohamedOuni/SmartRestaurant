#include "absence.h"
#include <QSqlTableModel>
#include <QDate>
#include "mainwindow.h"
#include "ui_mainwindow.h"


Absence::Absence(int id,QString nom,QString motif,QString daate )
{
    this->id=id;
    this->nom=nom;
    this->motif=motif;
    this->daate=daate;

}

bool Absence::ajouterAB()
 {
 QSqlQuery query;

 query.prepare("INSERT INTO absence (id,nom,motif,daate) "
                     "VALUES (:id,:nom, :motif, :daate)");

     query.bindValue(":id",id);
     query.bindValue(":nom",nom);
     query.bindValue(":motif",motif);
     query.bindValue(":daate",daate);

     return    query.exec();
}

/*QSqlQueryModel * Absence ::afficher_tab()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from absence");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MOTIF "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE "));

        return model;
}*/
QSqlTableModel *Absence::afficher()
{
   QSqlTableModel *mmodel = new QSqlTableModel();
    mmodel->setTable("ABSENCE");
    mmodel->select();
    return mmodel;

}

bool Absence :: supprimerAB(int id)
{

    QSqlQuery query;
    query.prepare("Delete from absence where id=:id");
    query.bindValue(0, id);
    return query.exec();


}

QSqlQueryModel * Absence ::afficher_ID()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select id from absence");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));

        return model;
}

void  Absence::telechargerPDF(){

                     QPdfWriter pdf("C:\\Users\\Ahmed\\OneDrive\\Bureau\\PROJET C++\\gestion personnel\\liste_d'absences.pdf");
                     QPainter painter(&pdf);
                    int i = 4000;
                         painter.setPen(Qt::blue);
                         painter.setFont(QFont("Arial", 30));
                         painter.drawText(1100,1200,"Liste Des absences");
                         painter.setPen(Qt::black);
                         painter.setFont(QFont("Arial", 15));
                         painter.drawRect(100,100,7300,2600);
                         painter.drawRect(0,3000,9600,500);
                         painter.setFont(QFont("Arial", 9));
                         painter.drawText(200,3300,"NOM");
                         painter.drawText(1300,3300,"MOTIF");
                         painter.drawText(2100,3300,"DATE");


                         QSqlQuery query;
                         query.prepare("select * from absence");
                         query.exec();
                         while (query.next())
                         {
                             painter.drawText(200,i,query.value(0).toString());
                             painter.drawText(1300,i,query.value(1).toString());
                             painter.drawText(2200,i,query.value(2).toString());


                            i = i + 500;
                         }}

QSqlQueryModel * Absence::triernom()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM absence ORDER BY NOM");
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("MOTIF"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("DATE"));
    return model;
}

QSqlQueryModel * Absence::triermotif()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM absence ORDER BY MOTIF");
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("MOTIF"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("DATE"));
    return model;
}

QSqlQueryModel * Absence::trierdate()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM absence ORDER BY DAATE");
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("MOTIF"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("DATE"));
    return model;
}
