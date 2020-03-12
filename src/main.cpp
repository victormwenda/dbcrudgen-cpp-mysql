#include <iostream>
#include <occi.h>
#include <algorithm>
#include "databases/oracle/models/OracleDatabaseModel.h"
#include "databases/mysql/connectors/MYSQLDatabaseConnectionParams.h"
#include "databases/mysql/connectors/MYSQLDatabaseConnector.h"
#include "orm/utils/TransactionUtils.h"
#include "databases/mysql/core/MYSQLIdentifierLengthLimits.h"
#include "databases/mysql/models/MYSQLDatabaseSchemas.h"
#include "databases/mysql/models/MYSQLDatabaseModel.h"


void getSchemas(dbcrudgen::mysql::MYSQLDatabaseModel &model) {
    auto schematas = model.getSchemas();

    for (const auto &schema : schematas) {
        std::cout << schema.getSchemaName() << std::endl;
    }

}

void getTables(dbcrudgen::mysql::MYSQLDatabaseModel &model) {
    std::string schema = "information_schema";
    auto tables = model.getSchemaTables(schema);
    for (const auto &table  : tables) {
        std::cout << table.getTableName() << std::endl;

        std::string createTable = model.getTableCreateStatement(schema,
                                                                const_cast<std::string &> (   table.getTableName()));

        std::cout << createTable << std::endl;
    }

}

void getColumns(dbcrudgen::mysql::MYSQLDatabaseModel &model, std::string schema, std::string table) {

    auto columns = model.getTableColumns(schema, table);

    for (const auto &column : columns) {
        std::cout << column.getColumnName() + " " << column.getDataType() << std::endl;
    }
}


int main(int argc, char **argv) {

    std::string host = "tcp://127.0.0.1:3306";
    std::string username = "root";
    std::string password = "root3358";
    std::string database = "information_schema";

    MYSQLDatabaseConnectionParams params{host, username, password, database};
    MYSQLDatabaseConnector connector{params};
    connector.open();

    dbcrudgen::mysql::MYSQLDatabaseModel model{connector};
    getTables(model);

    return EXIT_SUCCESS;
}