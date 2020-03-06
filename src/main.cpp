#include <iostream>
#include <occi.h>
#include <algorithm>
#include "databases/oracle/models/OracleDatabaseModel.h"
#include "databases/mysql/connectors/MYSQLDatabaseConnectionParams.h"
#include "databases/mysql/connectors/MYSQLDatabaseConnector.h"
#include "orm/utils/TransactionUtils.h"
#include "databases/mysql/core/MYSQLIdentifierLengthLimits.h"

int main(int argc, char **argv) {

    std::string host = "tcp://127.0.0.1:3306";
    std::string username = "root";
    std::string password = "root3358";
    std::string schemas = "givewatts";

    MYSQLDatabaseConnectionParams params{host, username, password, schemas};
    MYSQLDatabaseConnector connector{params};

    connector.open();

    auto tables = TransactionUtils::getMYSQLDatabaseTables(connector, "givewatts");

    for (const auto &table : tables) {
        std::cout << table.getTable_name() << "Rows " << table.getRows() << std::endl;
    }

    return EXIT_SUCCESS;
}