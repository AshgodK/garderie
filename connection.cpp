#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("data_base");
db.setUserName("system");//inserer nom de l'utilisateur
db.setPassword("rayensabri");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
