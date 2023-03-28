#include "table.h"
#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextDocument>
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFont>
table::table()
{

}
table::table(QString num_table,int nombre )
{
    this->setNum_table(num_table);
    this->setNombre_places(nombre);


}


bool table::ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO tables (NUM_TABLE, NOMBRE_PLACES) "
                  "VALUES (:NUM_TABLE, :NOMBRE_PLACES)");
    query.bindValue(":NUM_TABLE",getNum_table());
    query.bindValue(":NOMBRE_PLACES", getNombre_places());


    query.exec();
}

void table::afficher(Ui::MainWindow *ui)
{
    QSqlQuery query;
    QSqlQueryModel *modal=new QSqlQueryModel();
     query.prepare("select * from tables");
     query.exec();
    modal->setQuery(query);
    ui->tableView->setModel(modal);
}


bool table::modifier(Ui::MainWindow *ui)
{
    QSqlQuery query;
    QString NUM_TABLE=ui->NUM_TABLE2->text();
     int nbre=ui->nbre_personnes2->text().toInt();
    query.prepare("UPDATE tables set NOMBRE_PLACES=:NOMBRE_PLACES where NUM_TABLE ='"+NUM_TABLE+"'") ;
    query.bindValue(":NOMBRE_PLACES",nbre);
    return query.exec();
}

bool table::Supprimer(Ui::MainWindow *ui)
{
    QSqlQuery  query;
    QString NUM_TABLE=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString();
    query.prepare("DELETE FROM reservation WHERE table_num ='"+NUM_TABLE+"'");
       if( query.exec() )
       {
    query.prepare("DELETE FROM tables WHERE num_table ='"+NUM_TABLE+"'");
           return  query.exec();
       }
}



void table::afficher_vide(Ui::MainWindow *ui)
{
    QSqlQuery query;
    QSqlQueryModel *modal=new QSqlQueryModel();
     query.prepare("select * from tables  where NUM_TABLE NOT IN ( select TABLE_NUM FROM RESERVATION )");
     query.exec();
    modal->setQuery(query);
    ui->tableView->setModel(modal);
}
void table::afficher_reserve(Ui::MainWindow *ui)
{
    QSqlQuery query;
    QSqlQueryModel *modal=new QSqlQueryModel();
     query.prepare("select * from tables  where NUM_TABLE  IN ( select TABLE_NUM FROM RESERVATION )");
     query.exec();
    modal->setQuery(query);
    ui->tableView->setModel(modal);
}

QString table::getNum_table()
{
    return num_table;
}

void table::setNum_table( QString &value)
{
    num_table = value;
}

int table::getNombre_places()
{
    return nombre_places;
}

void table::setNombre_places( int &value)
{
    nombre_places = value;
}
