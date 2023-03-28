#include <QMessageBox>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtCore/qglobal.h>
#include <string>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestion_reservation.h"
#include "reservation.h"
#include "table.h"
#include<QPrinter>
#include<QPrintDialog>
#include<QDebug>
#include<QDateTime>
#include<QMediaPlayer>
/*Gestion_reservation::Gestion_reservation(QWidget *parent) :
QWidget(parent),
ui(new Ui::Gestion_reservation)
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(myfunction_resrvation()));
    timer->start(1000);
ui->setupUi(this);
reservation R;
//R.tables(ui);
//R.afficher(ui);
//R.GRAPH(ui);
if(R.NOMBRE_TABLES()==0)
{ui->ajouter->setDisabled(true);
ui->table_msg->setText("pas de tables disponibles");
}
else
{
ui->ajouter->setDisabled(false);
ui->table_msg->setText("");
}
notifyicon=new QSystemTrayIcon(this);
notifyicon->setIcon(QIcon(":/images/Notification.jpg"));
notifyicon->setVisible(true);
ui->modifier->setDisabled(true);
ui->tabWidget->setCurrentIndex(1);
}

Gestion_reservation::~Gestion_reservation()
{
delete ui;
}
*/
void MainWindow::on_ajouter_reservation_clicked()
{
reservation R;
table T ;
QRegExp regex1 ("[a-z]$");
QRegExp regex2 ("^[a-z]");
QString msg_nom ="nom  invalide";
QString msg_nombre ="nombre invalide";
QString msg_tel ="numero telephone invalide";
QString msg_vide="";

QString table= ui->tables->currentText();
QString nom= ui->nom->text();
QString tel = ui->telephone->text();
int nombre = ui->nombre->text().toInt();
int ok=0;


if ((!nom.contains(regex1))||(!nom.contains(regex2)))
{
ui->nom_msg->setStyleSheet("QLabel { color: red;}");
ui->nom_msg->setText(msg_nom);

ok++;
}
else { ui->nom_msg->setStyleSheet("QLabel { color: black;}");

ui->nom_msg->setText(msg_vide);
}


if( ui->telephone->text().length()!=8)
{
ui->telephone_msg->setStyleSheet("QLabel { color: red;}");
ui->telephone_msg->setText(msg_tel);

ok++;
}
else {
ui->telephone_msg->setStyleSheet("QLabel { color: black;}");
ui->telephone_msg->setText(msg_vide);
}

if( nombre<=0 )
{
ui->nombre_places_msg->setStyleSheet("QLabel { color: red;}");
ui->nombre_places_msg->setText(msg_nombre);

ok++;
}
else {
ui->nombre_places_msg->setStyleSheet("QLabel { color: black;}");
ui->nombre_places_msg->setText(msg_vide);
}
if (ok==0)
{
reservation R(nom,tel,table,nombre);
if (R.ajouter())
{
ui->nom->setStyleSheet("QLineEdit { color: green;}");
ui->telephone->setStyleSheet("QLineEdit { color: green;}");
ui->nombre_places_msg->setStyleSheet("QLineEdit { color: green;}");
notifyicon->show();
notifyicon->showMessage("Success ","Votre reservation a été bien ajouté ",QSystemTrayIcon::Information,2000);
R.afficher(ui);
ui->tabWidget_5->setCurrentIndex(1);
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
{QMessageBox ::information(this,"","erreur d'ajout  ") ;}
}




void MainWindow::on_supprimer_reservation_clicked()
{
reservation R;
if(R.Supprimer(ui))
{
QMessageBox ::information(this,"","Reservation Supprimé")  ;
QMediaPlayer * music = new QMediaPlayer();
music->setMedia(QUrl("qrc:/sounds/supprime.mp3"));
music->play();

R.afficher(ui);

}
}

void MainWindow::on_tableView_reservation_doubleClicked()
{

ui->ID->setText(ui->tableView_reservation->model()->data(ui->tableView_reservation->model()->index(ui->tableView_reservation->selectionModel()->currentIndex().row(),0)).toString());
ui->nom_2->setText(ui->tableView_reservation->model()->data(ui->tableView_reservation->model()->index(ui->tableView_reservation->selectionModel()->currentIndex().row(),1)).toString());
ui->tables2_reservation->setCurrentText(ui->tableView_reservation->model()->data(ui->tableView_reservation->model()->index(ui->tableView_reservation->selectionModel()->currentIndex().row(),3)).toString());
ui->telephone2->setText(ui->tableView_reservation->model()->data(ui->tableView_reservation->model()->index(ui->tableView_reservation->selectionModel()->currentIndex().row(),2)).toString());
ui->nombre2->setText(ui->tableView_reservation->model()->data(ui->tableView_reservation->model()->index(ui->tableView_reservation->selectionModel()->currentIndex().row(),4)).toString());
ui->tabWidget_5->setCurrentIndex(2);
ui->modifier_reservation->setDisabled(false);
}

void MainWindow::on_reset_3_reservation_clicked()
{ui->ID->clear();
ui->nom_2->clear();
ui->tables2_reservation->clear();
ui->nombre2->clear();
ui->tabWidget_5->setCurrentIndex(1);
ui->modifier_reservation->setDisabled(true);
}
void MainWindow::on_recherche_reservation_textChanged(const QString &arg1)
{
QString result ;
reservation R;
R.Recherche(ui);
}
void MainWindow::on_retour_reservation_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::on_modifier_reservation_clicked()
{
reservation R;
table T ;
QRegExp regex1 ("[a-z]$");
QRegExp regex2 ("^[a-z]");
QString msg_nom ="nom  invalide";
QString msg_nombre ="nombre invalide";
QString msg_tel ="numero telephone invalide";
QString msg_vide="";
QString table= ui->tables2_reservation->currentText();
QString nom= ui->nom_2->text();
int ID= ui->ID->text().toInt();
QString tel = ui->telephone2->text();
int nombre = ui->nombre2->text().toInt();
int ok=0;


if ((!nom.contains(regex1))||(!nom.contains(regex2)))
{
ui->nom_msg->setStyleSheet("QLabel { color: red;}");
ui->nom_msg->setText(msg_nom);

ok++;
}
else { ui->nom_msg->setStyleSheet("QLabel { color: black;}");

ui->nom_msg->setText(msg_vide);
}


if( tel.length()!=8)
{
ui->telephone_msg->setStyleSheet("QLabel { color: red;}");
ui->telephone_msg->setText(msg_tel);

ok++;
}
else {
ui->telephone_msg->setStyleSheet("QLabel { color: black;}");
ui->telephone_msg->setText(msg_vide);
}

if( nombre<=0 )
{
ui->nombre_places_msg->setStyleSheet("QLabel { color: red;}");
ui->nombre_places_msg->setText(msg_nombre);

ok++;
}
else {
ui->nombre_places_msg->setStyleSheet("QLabel { color: black;}");
ui->nombre_places_msg->setText(msg_vide);
}
if (ok==0)
{
reservation R(ID,nom,tel,table,nombre);

if (R.modifier(ui))
{
ui->nom_2->setStyleSheet("QLineEdit { color: green;}");
ui->nombre2->setStyleSheet("QLineEdit { color: green;}");
ui->telephone2->setStyleSheet("QLineEdit { color: green;}");
{QMessageBox ::information(this,""," reservation modifié  ") ;}

R.afficher(ui);
ui->tabWidget_5->setCurrentIndex(1);
ui->ID->clear();
ui->nom_2->clear();
ui->tables2_reservation->clear();
ui->nombre2->clear();
ui->telephone2->clear();
ui->modifier_reservation->setDisabled(true);
QMediaPlayer * music = new QMediaPlayer();
music->setMedia(QUrl("qrc:/sounds/modifie.mp3"));
music->play();
}
else {
{QMessageBox ::critical(this,"","erreur de modification 1") ;

}
}
}

else
{QMessageBox ::information(this,"","erreur de modification 2 ") ;}
}

void MainWindow::on_retour_2_reservation_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_retour_3_reservation_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_retour_4_reservation_clicked()
{

    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_13_reservation_clicked()
{
    QPrinter printer;
         printer.setPrinterName("imprimer");
         QPrintDialog dialog(&printer, this);
         if (dialog.exec() == QDialog::Rejected) return;
         ui->tabWidget_5->render(&printer);
}
void MainWindow::myfunction_reservation()
{
QTime time = QTime::currentTime();
QString time_text = time.toString("hh : mm : ss");
if ((time.second() % 2) == 0){
    time_text[3] = ' ';
    time_text[8] = ' ';
}
ui->label_29->setText(time_text);

}
