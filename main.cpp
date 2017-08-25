#include <iostream>
#include <cppconn/connection.h>
#include <mysql_connection.h>
#include "core/database/connectors/MYSQLDatabaseConnector.h"
#include "utils/TransactionUtils.h"


int main(int argc, char **argv) {
    /*const std::vector<std::string> &databaseTables = TransactionUtils::getMYSQLDatabaseTables(mysqlDatabaseConnector, "dbcrudgen");

    for(std::string databaseTable : databaseTables){
        std::cout << databaseTable << std::endl;
    }
*/
    MYSQLDatabaseConnector mysqlDatabaseConnector = ConnectorUtils::openMYSQLDatabase(
            MYSQLDatabaseConnectionParams{"tcp://127.0.0.1", "root", "root3358"});

    const std::vector<MYSQLTableColumn> &tableColumns = TransactionUtils::getMYSQLTableColumns(mysqlDatabaseConnector, "dbcrudgen", "bug_logger");

    for(MYSQLTableColumn tableColumn : tableColumns){
        std::cout << tableColumn.getField() << " " <<tableColumn.getType() <<std::endl;
    }

    return EXIT_SUCCESS;
}
