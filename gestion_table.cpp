#include "gestion_table.h"
#include <QMessageBox>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QString>
#include<QDebug>
#include<QDateTime>
#include<QTime>
#include<qtimer.h>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtCore/qglobal.h>
#include <string>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "table.h"
#include<QPrinter>
#include<QPrintDialog>
#include<QMediaPlayer>

/*Gestion_table::Gestion_table(QWidget *parent) :
QWidget(parent),
ui(new Ui::Gestion_table)
{
ui->setupUi(this);
table t;
//t.afficher(ui);
ui->NUM_TABLE2->setDisabled(true);
ui->modifier->setDisabled(true);
ui->tabWidget->setCurrentIndex(1);

timer = new QTimer(this);
connect(timer, SIGNAL(timeout()),this,SLOT(myfunction()));
timer->start(1000);
}

Gestion_table::~Gestion_table()
{
delete ui;
}*/
void MainWindow::on_ajouter_table_clicked()
{
QString msg ="nombre des places doit etre sup à 0 ";
QString msg2 ="num de table ne doit etre vide";
QString msg_vide="";

QString NUM_TABLE= ui->NUM_TABLE->text();
int nombre = ui->nbre_personnes->text().toInt();

int ok=0;
table t;

if (nombre<=0)
{
ui->mesagenombre->setStyleSheet("QLabel { color: red;}");
ui->mesagenombre->setText(msg);

ok++;
}
else {
ui->mesagenombre->setStyleSheet("QLabel { color: black;}");
ui->mesagenombre->setText(msg_vide);
}

if (NUM_TABLE=="")
{
ui->messagenum->setStyleSheet("QLabel { color: red;}");
ui->messagenum->setText(msg2);

ok++;
}
else {
ui->messagenum->setStyleSheet("QLabel { color: black;}");
ui->messagenum->setText(msg_vide);
}
if (ok==0)
{
table t(NUM_TABLE,nombre);
if (t.ajouter())
{
{QMessageBox ::information(this,""," table ajoutée  ") ;}
t.afficher(ui);
ui->tabWidget_4->setCurrentIndex(1);
QMediaPlayer * music = new QMediaPlayer();
music->setMedia(QUrl("qrc:/sounds/ajout.mp3"));
music->play();
}
else {
{QMessageBox ::critical(this,"","erreur d'ajout") ;
}
}
}

else
{QMessageBox ::information(this,"","erreur , verifié les informations  ") ;}
}

void MainWindow::on_supprimer_table_clicked()
{
table t ;
if(t.Supprimer(ui))
{
QMessageBox ::information(this,"","table Supprimée")  ;
t.afficher(ui);
QMediaPlayer * music = new QMediaPlayer();
music->setMedia(QUrl("qrc:/sounds/supprime.mp3"));
music->play();
}
}

void MainWindow::on_tableView_doubleClicked()
{

ui->NUM_TABLE2->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString());
ui->nbre_personnes2->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),1)).toString());
ui->tabWidget_4->setCurrentIndex(2);
ui->modifier_table->setDisabled(false);
}

void MainWindow::on_reset_3_table_clicked()
{ui->NUM_TABLE->clear();
ui->nbre_personnes->clear();
ui->tabWidget_4->setCurrentIndex(1);
ui->modifier_table->setDisabled(true);
}

void MainWindow::on_modifier_table_clicked()
{
QString msg ="nombre des places doit etre sup à 0 ";
QString msg_vide="";

QString NUM_TABLE= ui->NUM_TABLE2->text();
int nombre = ui->nbre_personnes2->text().toInt();

int ok=0;
table t;

if (nombre<=0)
{
ui->mesagenombre_2->setStyleSheet("QLabel { color: red;}");
ui->mesagenombre_2->setText(msg);

ok++;
}
else {
ui->mesagenombre_2->setStyleSheet("QLabel { color: black;}");
ui->mesagenombre_2->setText(msg_vide);
}


if (ok==0)
{
if (t.modifier(ui))
{
ui->NUM_TABLE2->setStyleSheet("QLineEdit { color: green;}");
ui->nbre_personnes2->setStyleSheet("QLineEdit { color: green;}");

{QMessageBox ::information(this,""," table modifiée  ") ;}

t.afficher(ui);
ui->tabWidget_4->setCurrentIndex(1);
ui->NUM_TABLE2->clear();
ui->nbre_personnes2->clear();
ui->modifier_table->setDisabled(true);
QMediaPlayer * music = new QMediaPlayer();
music->setMedia(QUrl("qrc:/sounds/modifie.mp3"));
music->play();
}
else {
{QMessageBox ::critical(this,"","erreur de modification") ;

}
}
}

else
{QMessageBox ::information(this,"","erreur de modification  ") ;}
}

void MainWindow::on_radioButton_table_clicked()
{
table t;
t.afficher_vide(ui);
}

void MainWindow::on_radioButton_2_table_clicked()
{
table t;
t.afficher_reserve(ui);
}
void MainWindow::on_radioButton_3_table_clicked()
{
table t;
t.afficher(ui);
}

void MainWindow::on_retour_table_clicked()
{
ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_retour_2_table_clicked()
{
ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_retour_3_table_clicked()
{
ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_13_table_clicked()
{
    QPrinter printer;
         printer.setPrinterName("imprimer");
         QPrintDialog dialog(&printer, this);
         if (dialog.exec() == QDialog::Rejected) return;
         ui->tabWidget_4->render(&printer);
}

void MainWindow::myfunction()
{
QTime time = QTime::currentTime();
QString time_text = time.toString("hh : mm : ss");
if ((time.second() % 2) == 0){
    time_text[3] = ' ';
    time_text[8] = ' ';
}
ui->label->setText(time_text);
}
