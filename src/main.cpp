#include <iostream>
#include <occi.h>
#include <string>
#include <vector>
#include <regex>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "databases/mysql/scaffolding/entities/Schemata.h"
#include "databases/mysql/connectors/MYSQLDatabaseConnectionParams.h"
#include "databases/mysql/connectors/MYSQLDatabaseConnector.h"
#include "databases/mysql/decomposer/MYSQLDatabaseDecomposer.h"
#include "databases/mysql/parsers/MYSQLDatabaseFlattener.h"
#include "databases/generic/Database.h"
#include "databases/mysql/models/MYSQLDatabaseModel.h"
#include "orm/projects/CppMYSQLProjectModel.h"
#include "orm/creators/cpp/CppMYSQLProjectCreator.h"
#include "orm/projects/LaravelPHPMYSQLProjectModel.h"
#include "orm/creators/php/LaravelPHPMYSQLProjectCreator.h"
#include "databases/mysql/parsers/MYSQLDatabaseFlattener.h"
#include "orm/creators/postman/PostmanProjectCreator.h"
#include "orm/projects/PostmanProjectModel.h"

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
    std::string database = "mysql";

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
    }


    dbcrudgen::mysql::MYSQLDatabaseModel databaseModel;
    databaseModel.setDatabaseName(database);
    databaseModel.setTables(tables);
    databaseModel.setTableColumns(tableColumns);


    std::string projectName = "information-schema-cpp";
    std::string workspaceDir = "/opt/victor/workspace/cpp";
    std::string includesDir = "includes";
    std::string libsDir = "libs";
    std::string generatedCodeDir = "src/orm";
    std::string generatedModelCodeDir = "model";
    std::string generatedDbOpsCodeDir = "dao";

    dbcrudgen::orm::CppMYSQLProjectModel projectModel{projectName, workspaceDir, includesDir, libsDir,
                                                      generatedCodeDir, generatedModelCodeDir, generatedDbOpsCodeDir};

    dbcrudgen::orm::CppMYSQLProjectCreator projectCreator{projectModel};
    projectCreator.setDatabaseModel(databaseModel);
    projectCreator.createProject();

}

void createPhpProject() {

    std::string host = "tcp://127.0.0.1:3306";
    std::string username = "root";
    std::string password = "root3358";
    std::string database = "pesarika";

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
    }


    dbcrudgen::mysql::MYSQLDatabaseModel databaseModel;
    databaseModel.setDatabaseName(database);
    databaseModel.setTables(tables);
    databaseModel.setTableColumns(tableColumns);


    std::string projectName = "pesarika-web";
    std::string workspaceDir = "/var/www/html";
    std::string controllersDir = "app/Http/Controllers";
    std::string modelsDir = "app/Http/Models";
    std::string viewsDir = "resources/views";
    std::string routesDir = "routes";
    std::string apiVersion = "v1";
    std::string webRouteFile = "web.php";
    std::string apiRouteFile = "api.php";

    dbcrudgen::orm::LaravelPHPMYSQLProjectModel projectModel{projectName, workspaceDir, controllersDir, modelsDir,
                                                             viewsDir, routesDir, webRouteFile, apiRouteFile,
                                                             apiVersion};

    dbcrudgen::orm::LaravelPHPMYSQLProjectCreator projectCreator{projectModel, databaseModel};
    projectCreator.createProject();

}

void flattenMYSQLDatabase() {

    std::string host = "tcp://127.0.0.1:3306";
    std::string username = "root";
    std::string password = "root3358";
    std::string database = "pesarika";

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
    }

    dbcrudgen::mysql::MYSQLDatabaseModel databaseModel;
    databaseModel.setDatabaseName(database);
    databaseModel.setTables(tables);
    databaseModel.setTableColumns(tableColumns);

    auto genericDatabase = dbcrudgen::db::mysql::MYSQLDatabaseFlattener::flatten(databaseModel);

    std::cout << "Generic db name: " << genericDatabase.getDatabaseName() << std::endl;

    auto genericTables = genericDatabase.getTables();

    for (const auto &genericTable : genericTables) {
        std::cout << " ================== " << genericTable.getTableName() << " ================== " << std::endl;

        auto genericColumns = genericTable.getTableColumns();

        for (const auto &genericColumn : genericColumns) {
            std::cout << "Column name : " << genericColumn.getColumnName() << " Data type :: "
                      << genericColumn.getDataType() << std::endl;
        }
    }

}

void createPostmanProject() {

    std::string host = "tcp://127.0.0.1:3306";
    std::string username = "root";
    std::string password = "root3358";
    std::string database = "pesarika";

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
    }

    dbcrudgen::mysql::MYSQLDatabaseModel databaseModel;
    databaseModel.setDatabaseName(database);
    databaseModel.setTables(tables);
    databaseModel.setTableColumns(tableColumns);

    auto genericDatabase = dbcrudgen::db::mysql::MYSQLDatabaseFlattener::flatten(databaseModel);

    std::string projectName = "Test";
    std::string storeDirectory = "/home/victor/Desktop";
    std::string protocol = "http";
    std::string apiHost = "localhost";
    int port = 8000;
    std::string pathSegments{"api/v1"};
    std::map<std::string, std::string> headers;
    std::string databaseType{"mysql"};

    headers.insert(std::pair<std::string, std::string>(std::string{"Content-Type"}, std::string{"application/json"}));
    headers.insert(std::pair<std::string, std::string>(std::string{"Accept"}, std::string{"application/json"}));

    dbcrudgen::orm::PostmanProjectModel projectModel{projectName, storeDirectory, protocol, apiHost, port,
                                                     pathSegments, headers, databaseType};
    dbcrudgen::orm::PostmanProjectCreator projectCreator{projectModel, genericDatabase};
    projectCreator.createProject();
}

int main(int argc, char **argv) {

    createPhpProject();
    createPostmanProject();

    return EXIT_SUCCESS;
}