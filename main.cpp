#include <iostream>
#include <cppconn/connection.h>
#include <mysql_connection.h>
#include "core/database/connectors/MYSQLDatabaseConnector.h"
#include "utils/TransactionUtils.h"


void showMYSQLDatabaseTableColumns(MYSQLDatabaseConnector &mysqlDatabaseConnector);
void showMYSQLDatabaseTableNames(MYSQLDatabaseConnector &mysqlDatabaseConnector);

int main(int argc, char **argv) {

    MYSQLDatabaseConnector mysqlDatabaseConnector = ConnectorUtils::openMYSQLDatabase(
            MYSQLDatabaseConnectionParams{"tcp://127.0.0.1", "root", "root3358"});

    showMYSQLDatabaseTableNames(mysqlDatabaseConnector);

    return EXIT_SUCCESS;
}

void showMYSQLDatabaseTableColumns(MYSQLDatabaseConnector &mysqlDatabaseConnector) {
    const std::vector<MYSQLDatabaseTable> &tables
            = TransactionUtils::getMYSQLDatabaseTables(mysqlDatabaseConnector,"dbcrudgen");

    for (const MYSQLDatabaseTable &table : tables) {

        std::cout << table.getTable_name() << std::endl;

        const std::vector<MYSQLTableColumn> &tableColumns = table.getColumns();

        int index = 0;

        for (const MYSQLTableColumn &column : tableColumns) {
            index++;
            std::cout << "\t" << index << ". " << column.getField() << " " << column.getType() << std::endl;

        }

    }
}

void showMYSQLDatabaseTableNames(MYSQLDatabaseConnector &mysqlDatabaseConnector) {
    const std::vector<std::string> &tableNames =
            TransactionUtils::getMYSQLDatabaseTableNames(mysqlDatabaseConnector, "dbcrudgen");
    for (const std::string &tableName : tableNames) {
        std::cout << tableName << std::endl;
    }
}
