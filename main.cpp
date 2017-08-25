#include <iostream>
#include <cppconn/connection.h>
#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <mysql_connection.h>
#include "core/database/connectors/MYSQLDatabaseConnector.h"
#include "utils/TransactionUtils.h"


int main(int argc, char **argv) {

    const std::vector<std::string> &databaseTables = TransactionUtils::getMYSQLDatabaseTables(MYSQLDatabaseConnectionParams{"tcp://127.0.0.1", "root", "root3358", "dbcrudgen"});

    for(std::string databaseTable : databaseTables){
        std::cout << databaseTable << std::endl;
    }

    return EXIT_SUCCESS;
}
