#include <iostream>
#include <occi.h>
#include <algorithm>
#include "databases/oracle/models/OracleDatabaseModel.h"
#include "databases/mysql/connectors/MYSQLDatabaseConnectionParams.h"
#include "databases/mysql/connectors/MYSQLDatabaseConnector.h"
#include "orm/utils/TransactionUtils.h"
#include "orm/parsers/cpp/CppMYSQLParser.h"
#include "databases/mysql/core/MYSQLIdentifierLengthLimits.h"
#include "databases/mysql/models/MYSQLDatabaseSchemas.h"
#include "databases/mysql/models/MYSQLDatabaseModel.h"
#include "databases/mysql/core/MYSQLDataType.h"
#include "io/FilesReader.h"
#include "io/FilesWriter.h"
#include "orm/templates/cpp/CppClassTemplate.h"


std::vector<Schemata> getSchemas(dbcrudgen::mysql::MYSQLDatabaseModel &model) {
    return model.getSchemas();
}

std::vector<dbcrudgen::mysql::Tables> getTables(dbcrudgen::mysql::MYSQLDatabaseModel &model, std::string &schema) {
    return model.getSchemaTables(schema);
}

std::string
getTableCreateStatement(dbcrudgen::mysql::MYSQLDatabaseModel &model, std::string &schema, std::string &table) {
    return model.getTableCreateStatement(schema, table);
}

std::vector<dbcrudgen::mysql::Columns>
getColumns(dbcrudgen::mysql::MYSQLDatabaseModel &model, std::string schema, std::string table) {
    return model.getTableColumns(schema, table);
}

int main(int argc, char **argv) {

    if (true) {

        std::string host = "tcp://127.0.0.1:3306";
        std::string username = "root";
        std::string password = "root3358";
        std::string database = "dbcrudgen";

        MYSQLDatabaseConnectionParams params{host, username, password, database};
        MYSQLDatabaseConnector connector{params};
        connector.open();

        dbcrudgen::mysql::MYSQLDatabaseModel model{connector};
        std::vector<dbcrudgen::mysql::Tables> tables = getTables(model, database);

        for (const auto &table : tables) {

            std::string name = table.getTableName();

            std::cout << "Table name is : " << name << std::endl;

            auto columns = model.getTableColumns(database, name);

            for (const auto &column : columns) {
                std::cout << column.getColumnName() << " " << column.getDataType() << std::endl;
                const std::string &dataType = column.getDataType();
                std::cout << "Cpp data type : "
                          << dbcrudgen::mysql::CppMYSQLParser::toCppDataType(dataType.c_str()) << std::endl;
            }

        }

    }

    dbcrudgen::orm::templates::CppClassTemplate tmp;
    std::string content = tmp.getTemplate();

    std::cout << content << std::endl;

    if (false) {
        auto data_types = dbcrudgen::mysql::MYSQLDataType::getMYSQLDataTypes();

        int index = 0;


        for (const auto type  :data_types) {
        }
    }


    return EXIT_SUCCESS;
}