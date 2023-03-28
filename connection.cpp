#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

db.setDatabaseName("pro");//inserer le nom de la source de données ODBC
db.setUserName("mohamed");//inserer nom de l'utilisateur
db.setPassword("mohamed");//inserer mot de passe de cet utilisateur

/*aaaaaa*/
/*db.setDatabaseName("Projet_2A");//inserer le nom de la source de données ODBC
db.setUserName("ahmed");//inserer nom de l'utilisateur
db.setPassword("ahmed");//inserer mot de passe de cet utilisateur*/

/*db.setDatabaseName("source_projet2A");//inserer le nom de la source de données ODBC
db.setUserName("mahdi");//inserer nom de l'utilisateur
db.setPassword("esprit18");//inserer mot de passe de cet utilisateur*/
if (db.open())
test=true;





    return  test;
}
