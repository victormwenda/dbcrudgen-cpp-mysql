#include <iostream>
#include <occi.h>
#include <algorithm>
#include "databases/oracle/models/OracleDatabaseModel.h"
#include "databases/mysql/connectors/MYSQLDatabaseConnectionParams.h"
#include "databases/mysql/connectors/MYSQLDatabaseConnector.h"
#include "orm/utils/TransactionUtils.h"
#include "databases/mysql/core/MYSQLIdentifierLengthLimits.h"
#include "databases/mysql/models/MYSQLDatabaseSchemas.h"

int main(int argc, char **argv) {

    std::string host = "tcp://127.0.0.1:3306";
    std::string username = "root";
    std::string password = "root3358";
    std::string database = "information_schema";

    MYSQLDatabaseConnectionParams params{host, username, password, database};
    MYSQLDatabaseConnector connector{params};

    connector.open();

    MYSQLDatabaseSchemas schemas{connector};
    auto schematas = schemas.getSchemas();

    for (const auto& schema : schematas) {
        std::cout << schema.getSchemaName() << " ----------- " << schema.getDefaultCollationName() << std::endl;
    }

    return EXIT_SUCCESS;
}