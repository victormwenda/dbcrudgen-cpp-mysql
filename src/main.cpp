#include <iostream>
#include <occi.h>
#include <string>
#include <vector>
#include <regex>
#include "databases/mysql/schema/Schemata.h"
#include "databases/mysql/connectors/MYSQLDatabaseConnectionParams.h"
#include "databases/mysql/connectors/MYSQLDatabaseConnector.h"
#include "databases/mysql/decomposer/MYSQLDatabaseDecomposer.h"
#include "databases/mysql/models/MYSQLDatabaseModel.h"
#include "orm/projects/CppMYSQLProjectModel.h"
#include "orm/creators/cpp/CppMYSQLProjectCreator.h"

std::vector<Schemata> getSchemas(dbcrudgen::mysql::MYSQLDatabaseDecomposer &model) {
    return model.getSchemas();
}

std::vector<dbcrudgen::mysql::Tables> getTables(dbcrudgen::mysql::MYSQLDatabaseDecomposer &model, std::string &schema) {
    return model.getSchemaTables(schema);
}

std::string
getTableCreateStatement(dbcrudgen::mysql::MYSQLDatabaseDecomposer &model, std::string &schema, std::string &table) {
    return model.getTableCreateStatement(schema, table);
}

std::vector<dbcrudgen::mysql::Columns>
getColumns(dbcrudgen::mysql::MYSQLDatabaseDecomposer &model, std::string schema, std::string table) {
    return model.getTableColumns(schema, table);
}

void test() {
    std::string host = "tcp://127.0.0.1:3306";
    std::string username = "root";
    std::string password = "root3358";
    std::string database = "dbcrudgen";

    MYSQLDatabaseConnectionParams params{host, username, password, database};
    MYSQLDatabaseConnector connector{params};
    connector.open();

    dbcrudgen::mysql::MYSQLDatabaseDecomposer model{connector};
    std::vector<dbcrudgen::mysql::Tables> tables = getTables(model, database);

    for (const auto &table : tables) {

        std::string name = table.getTableName();

        std::cout << "Table name is : " << name << std::endl;

        auto columns = model.getTableColumns(database, name);

        for (const auto &column : columns) {
            std::cout << column.getColumnName() << " " << column.getDataType() << std::endl;
            const std::string &dataType = column.getDataType();
            std::cout << "Cpp data type : "
                      << dbcrudgen::orm::CppMYSQLParser::toCppDataType(dataType.c_str()) << std::endl;
        }

    }

}

void createCppProject() {
    std::string host = "tcp://127.0.0.1:3306";
    std::string username = "root";
    std::string password = "root3358";
    std::string database = "dbcrudgen";

    MYSQLDatabaseConnectionParams params{host, username, password, database};
    MYSQLDatabaseConnector connector{params};
    connector.open();
    dbcrudgen::mysql::MYSQLDatabaseDecomposer decomposer{connector};

    std::map<std::string, std::vector<dbcrudgen::mysql::Columns>> tableColumns;

    auto tables = decomposer.getSchemaTables(database);

    for (dbcrudgen::mysql::Tables &table : tables) {
        std::string tableName = table.getTableName();
        std::vector<dbcrudgen::mysql::Columns> columns = decomposer.getTableColumns(database, tableName);
        tableColumns.insert({tableName, columns});

        std::cout << "Adding columns for table " << tableName << std::endl;
    }

    dbcrudgen::mysql::MYSQLDatabaseModel databaseModel;
    databaseModel.setDatabaseName(database);
    databaseModel.setTables(tables);
    databaseModel.setTableColumns(tableColumns);


    std::string projectName = "information-schema-cpp";
    std::string workspaceDir = "/opt/victor/workspace/cpp";
    std::string includesDir = "includes";
    std::string libsDir = "libs";
    std::string generatedCodeDir = "src/orm/";

    dbcrudgen::orm::CppMYSQLProjectModel projectModel{projectName, workspaceDir, includesDir, libsDir,
                                                      generatedCodeDir};

    dbcrudgen::orm::CppMYSQLProjectCreator projectCreator{projectModel};
    projectCreator.setDatabaseModel(databaseModel);
    projectCreator.createProject();

}


int main(int argc, char **argv) {

    createCppProject();

    return EXIT_SUCCESS;
}