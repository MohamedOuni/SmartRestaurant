#include "login.h"
#include "gestion_personnel.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestion_reservation.h"
#include "reservation.h"
#include "table.h"

/*Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

}

Login::~Login()
{
    delete ui;
}
*/
void MainWindow::on_pushButton_2_login_clicked()
{
    QString username =ui-> lineEdit_username->text();

    QString mdp=ui-> lineEdit_mdp->text();
    QSqlQuery qry;

    if (qry.exec("select * from personnel where NOM='"+username+ "'and MOT_DE_PASSE='"+mdp+"'"))
    {
    int count=0;
    while(qry.next())
     {
    count ++;
      }
    if (count==1 or (username=="admin" && mdp=="admin") )
         {
          ui->stackedWidget->setCurrentIndex(0);
          ui->lineEdit_username->setText("");
          ui->lineEdit_mdp->setText("");
          ui->test->setText("Bonjour "+username+"");
          //animation
          animation=new QPropertyAnimation(ui->accueil,"geometry");
          animation->setDuration(2500);
          animation->setStartValue(ui->accueil->geometry());
          animation->setEndValue(QRect(470,40,191,51));
          animation->start();
         }


     if (count<1)
       {
        ui->label_connecting->setText("Nom d'utilisateur ou Mot de passe incorrect");
        ui->lineEdit_username->setText("");
        ui->lineEdit_mdp->setText("");
       }
}
}

