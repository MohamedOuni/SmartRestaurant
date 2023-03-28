#include "reservation.h"
#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextDocument>
#include <QFont>
#include "mainwindow.h"
#include "ui_mainwindow.h"
reservation::reservation()
{

}
reservation::reservation(int ID, QString NOM_CLIENT, QString NUM_TEL, QString TABLE_NUM,int NOMBRE_PERSONNES )
{
this->setID(ID);
this->setNOM_CLIENT(NOM_CLIENT);
this->setNUM_TEL(NUM_TEL);
this->setTABLE_NUM(TABLE_NUM);
this->setNOMBRE_PERSONNES(NOMBRE_PERSONNES);
}

reservation::reservation( QString NOM_CLIENT, QString NUM_TEL, QString TABLE_NUM,int NOMBRE_PERSONNES)
{
this->setNOM_CLIENT(NOM_CLIENT);
this->setNUM_TEL(NUM_TEL);
this->setTABLE_NUM(TABLE_NUM);
this->setNOMBRE_PERSONNES(NOMBRE_PERSONNES);
}

bool reservation::ajouter()
{
QSqlQuery query;

query.prepare("INSERT INTO reservation (NOM_CLIENT, NUM_TEL,TABLE_NUM,NOMBRE_PERSONNES) "
"VALUES (:NOM_CLIENT, :NUM_TEL,:TABLE_NUM, :NOMBRE_PERSONNES)");
query.bindValue(":NOM_CLIENT",getNOM_CLIENT());
query.bindValue(":NUM_TEL", getNUM_TEL());
query.bindValue(":TABLE_NUM",getTABLE_NUM());
query.bindValue(":NOMBRE_PERSONNES",getNOMBRE_PERSONNES());
query.exec();
}

void reservation::afficher(Ui::MainWindow *ui)
{
QSqlQuery query;
QSqlQueryModel *modal=new QSqlQueryModel();
query.prepare("select * from reservation");
query.exec();
modal->setQuery(query);
ui->tableView_reservation->setModel(modal);
}

bool reservation::Supprimer(Ui::MainWindow *ui)
{
QSqlQuery  query;
QString ID=ui->tableView_reservation->model()->data(ui->tableView_reservation->model()->index(ui->tableView_reservation->selectionModel()->currentIndex().row(),0)).toString();
query.prepare("DELETE FROM reservation WHERE ID ='"+ID+"'");
return query.exec();
}

bool reservation::modifier(Ui::MainWindow *ui)
{
QSqlQuery query;
QString ID=ui->ID->text();

query.prepare("UPDATE reservation set NOM_CLIENT=:NOM_CLIENT,NUM_TEL=:NUM_TEL ,TABLE_NUM=:TABLE_NUM , NOMBRE_PERSONNES=:NOMBRE_PERSONNES where ID ='"+ID+"'") ;

query.bindValue(":NOM_CLIENT",getNOM_CLIENT());
query.bindValue(":NUM_TEL", getNUM_TEL());
query.bindValue(":NOMBRE_PERSONNES",getNOMBRE_PERSONNES());
query.bindValue(":TABLE_NUM",getTABLE_NUM());
return query.exec();

}
void reservation::tables(Ui::MainWindow *ui)
{
QSqlQuery q;
QSqlQueryModel *modal=new QSqlQueryModel();
q.prepare("select NUM_TABLE from tables");
q.exec();
modal->setQuery(q);
ui->tables->setModel(modal);
ui->tables2_reservation->setModel(modal);
}


void reservation::Recherche(Ui::MainWindow *ui)
{
QSqlQuery q;
QSqlQueryModel *modal=new QSqlQueryModel();
QString reference =ui->recherche->text();
q.prepare("select * from reservation where (ID LIKE '%"+reference+"%' or NOM_CLIENT LIKE '%"+reference+"%' or NUM_TEL LIKE '%"+reference+"%' or NOMBRE_PERSONNES LIKE '%"+reference+"%' or TABLE_NUM LIKE '%"+reference+"%')");

if ( q.exec() )
{ modal->setQuery(q);
ui->tableView_reservation->setModel(modal);}
else
{
qWarning( "can't get value" ); }
}

int reservation::NOMBRE_TABLES()
{  int nb;
QSqlQuery q;

q.prepare("SELECT COUNT(NUM_TABLE) FROM TABLES  ");
q.exec();
if ( q.first() )
nb=q.value(0).toInt();
else
{
qWarning( "can't get value" ); }
return nb ;
}

int reservation::NOMBRE_RESERVATION()
{  int nb;
QSqlQuery q;

q.prepare("SELECT COUNT(ID) FROM reservation ");
q.exec();
if ( q.first() )
nb=q.value(0).toInt();
else
{
qWarning( "can't get value" ); }
return nb ;
}
void reservation::GRAPH(Ui::MainWindow *ui)
{

int reserv=NOMBRE_RESERVATION();
int  tables= NOMBRE_TABLES();


// set dark background gradient:
QLinearGradient gradient(0, 0, 0, 400);
gradient.setColorAt(0, QColor(90, 90, 90));
gradient.setColorAt(0.38, QColor(105, 105, 105));
gradient.setColorAt(1, QColor(70, 70, 70));
ui->GRAPH->setBackground(QBrush(gradient));

// create empty bar chart objects:

QCPBars *T = new QCPBars(ui->GRAPH->xAxis, ui->GRAPH->yAxis);
QCPBars *R = new QCPBars(ui->GRAPH->xAxis, ui->GRAPH->yAxis);
QCPBars *Pourcentage = new QCPBars(ui->GRAPH->xAxis, ui->GRAPH->yAxis);
T->setAntialiased(false);
R->setAntialiased(false);
Pourcentage->setAntialiased(false);
T->setStackingGap(1);
R->setStackingGap(1);
Pourcentage->setStackingGap(1);
// set names and colors:
T->setName("NOMBRE DES TABLES");
T->setPen(QPen(QColor(0, 125, 2).lighter(170)));
T->setBrush(QColor(0, 125, 2));
R->setName("NOMBRE DES RESERVATION");
R->setPen(QPen(QColor(174, 0, 0).lighter(150)));
R->setBrush(QColor(174, 0, 0));
Pourcentage->setName("NOMBRE DES TABLES DIPONIBLES");
Pourcentage->setPen(QPen(QColor(150, 125, 2).lighter(170)));
Pourcentage->setBrush(QColor(150, 125, 2));



// prepare x axis :
QVector<double> ticks;
QVector<QString> labels;
ticks << 1 << 2 << 3     ;

QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
textTicker->addTicks(ticks, labels);
ui->GRAPH->xAxis->setTicker(textTicker);
ui->GRAPH->xAxis->setTickLabelRotation(60);
ui->GRAPH->xAxis->setSubTicks(false);
ui->GRAPH->xAxis->setTickLength(0, 4);
ui->GRAPH->xAxis->setRange(0, 4);
ui->GRAPH->xAxis->setBasePen(QPen(Qt::white));
ui->GRAPH->xAxis->setTickPen(QPen(Qt::white));
ui->GRAPH->xAxis->grid()->setVisible(true);
ui->GRAPH->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
ui->GRAPH->xAxis->setTickLabelColor(Qt::white);
ui->GRAPH->xAxis->setLabelColor(Qt::white);

// prepare y axis:
ui->GRAPH->yAxis->setRange(0, tables);
ui->GRAPH->yAxis->setPadding(1);// a bit more space to the left border
ui->GRAPH->yAxis->setBasePen(QPen(Qt::white));
ui->GRAPH->yAxis->setTickPen(QPen(Qt::white));
ui->GRAPH->yAxis->setSubTickPen(QPen(Qt::white));


ui->GRAPH->yAxis->grid()->setSubGridVisible(true);
ui->GRAPH->yAxis->setTickLabelColor(Qt::white);
ui->GRAPH->yAxis->setLabelColor(Qt::white);
ui->GRAPH->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
ui->GRAPH->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

// Add data:
QVector<double> RESERVATIONDATA, TABLEDATA , RAPPORTDATA;
TABLEDATA  << tables <<0 <<0 ;
RESERVATIONDATA << 00 << reserv <<0;
RAPPORTDATA  << 0 << 0 << tables-reserv ;
T->setData(ticks, TABLEDATA);
R->setData(ticks, RESERVATIONDATA);
Pourcentage->setData(ticks, RAPPORTDATA);
// setup legend:
ui->GRAPH->legend->setVisible(true);
ui->GRAPH->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
ui->GRAPH->legend->setBrush(QColor(255, 255, 255, 100));
ui->GRAPH->legend->setBorderPen(Qt::NoPen);

ui->GRAPH->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

}

int reservation::getID()
{
return ID;
}

void reservation::setID( int &value)
{
ID = value;
}


QString reservation::getNOM_CLIENT()
{
return NOM_CLIENT;
}

void reservation::setNOM_CLIENT( QString &value)
{
NOM_CLIENT = value;
}

QString reservation::getTABLE_NUM()
{
return TABLE_NUM;
}

void reservation::setTABLE_NUM( QString &value)
{
TABLE_NUM = value;
}

QString reservation::getNUM_TEL()
{
return NUM_TEL;
}

void reservation::setNUM_TEL( QString &value)
{
NUM_TEL = value;
}

int reservation::getNOMBRE_PERSONNES()
{
return NOMBRE_PERSONNES;
}

void reservation::setNOMBRE_PERSONNES( int &value)
{
NOMBRE_PERSONNES = value;
}




