#include <iostream>
#include <occi.h>
#include <algorithm>
#include "databases/oracle/models/OracleDatabaseModel.h"
#include "databases/mysql/connectors/MYSQLDatabaseConnectionParams.h"
#include "databases/mysql/connectors/MYSQLDatabaseConnector.h"
#include "orm/utils/TransactionUtils.h"

int main(int argc, char **argv) {

    std::string host = "tcp://127.0.0.1:3306";
    std::string username = "root";
    std::string password = "root3358";
    std::string schemas = "pesarika";
    MYSQLDatabaseConnectionParams params{host, username, password, schemas};
    MYSQLDatabaseConnector connector{params, false};
    connector.open();
     auto users = TransactionUtils::getMYSQLUsers(connector);

    for (auto& user : users) {

        std::cout << user.getUser() << std::endl;


    }

    return EXIT_SUCCESS;
}