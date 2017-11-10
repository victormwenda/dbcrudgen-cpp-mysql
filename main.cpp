#include <iostream>
#include <cppconn/connection.h>
#include <mysql_connection.h>
#include "core/database/connectors/MYSQLDatabaseConnector.h"
#include "utils/TransactionUtils.h"


int main(int argc, char **argv) {

    MYSQLDatabaseConnector mysqlDatabaseConnector = ConnectorUtils::openMYSQLDatabase(
            MYSQLDatabaseConnectionParams{"tcp://127.0.0.1", "root", "root3358"});

    const std::vector<MYSQLDatabaseTable> &tables = TransactionUtils::getMYSQLDatabaseTables(mysqlDatabaseConnector,
                                                                                             "dbcrudgen");

    for (const MYSQLDatabaseTable &table : tables) {

        std::cout << table.getTable_name() << std::endl;

        const std::vector<MYSQLTableColumn> &tableColumns = table.getColumns();

        int index = 0;

        for (const MYSQLTableColumn &column : tableColumns) {
            index++;
            std::cout << "\t" << index << ". " << column.getField() << " " << column.getType() << std::endl;

        }

    }

    return EXIT_SUCCESS;
}
