#include <iostream>
#include "core/database/connection/MSSQLDatabaseConnection.h"

using namespace std;


int main(int argc, char *argv[]) {

    MSSQLDatabaseConnection mssqlDatabaseConnection{"127.0.0.1:8080", "root", "root3358"};
    cout << "Host " << mssqlDatabaseConnection.getHost() << endl;
    cout << "Port " << mssqlDatabaseConnection.getPort() << endl;
    return 0;
}