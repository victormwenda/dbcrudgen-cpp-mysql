#include <iostream>
#include <string>
#include <vector>
#include "databases/mysql/scaffolding/entities/Schemata.h"
#include "databases/mysql/connectors/MYSQLDatabaseConnectionParams.h"
#include "databases/mysql/connectors/MYSQLDatabaseConnector.h"
#include "databases/mysql/decomposer/MYSQLDatabaseDecomposer.h"
#include "databases/mysql/parsers/MYSQLDatabaseFlattener.h"
#include "databases/generic/Database.h"
#include "databases/mysql/models/MYSQLDatabaseModel.h"
#include "orm/projects/CppMYSQLProjectModel.h"
#include "orm/creators/cpp/CppMYSQLProjectCreator.h"
#include "orm/creators/postman/PostmanProjectCreator.h"
#include "orm/creators/php/LaravelProjectCreator.h"
#include "orm/projects/LaravelProjectModel.h"

/**
 * Returns a MYSQL Database Model
 * @param database
 * @param username
 * @param password
 * @param host
 * @return
 */
dbcrudgen::mysql::MYSQLDatabaseModel
getMYSQLDatabaseModel(std::string database, std::string username, std::string password, std::string host);

/**
 * Create a Generic database from a MYSQL Database Model
 * @param databaseModel
 * @return
 */
dbcrudgen::db::generic::Database getGenericDatabase(dbcrudgen::mysql::MYSQLDatabaseModel &databaseModel);

/**
 * Create CPP Project
 */
void createCppProject();

/**
 * Create PHP Project
 */
void createPhpProject();

/**
 * Create Postman project
 */
void createPostmanProject();

int main(int argc, char **argv) {

    createPhpProject();

    return EXIT_SUCCESS;
}


/**
 * Returns a MYSQL Database Model
 * @param database
 * @param username
 * @param password
 * @param host
 * @return
 */
dbcrudgen::mysql::MYSQLDatabaseModel getMYSQLDatabaseModel(std::string database = "dbcrudgen",
                                                           std::string username = "root",
                                                           std::string password = "root3358",
                                                           std::string host = "tcp://127.0.0.1:3306") {

    MYSQLDatabaseConnectionParams params{host, username, password, database};
    MYSQLDatabaseConnector connector{params};
    connector.open();

    dbcrudgen::mysql::MYSQLDatabaseDecomposer decomposer{connector};

    std::map<std::string, std::vector<dbcrudgen::mysql::Columns>> tableColumns;

    auto tables = decomposer.getSchemaTables(database);

    for (dbcrudgen::mysql::Tables &table  : tables) {
        std::string tableName = table.getTableName();
        std::vector<dbcrudgen::mysql::Columns> columns = decomposer.getTableColumns(database, tableName);
        tableColumns.insert({tableName, columns});
    }

    dbcrudgen::mysql::MYSQLDatabaseModel databaseModel;
    databaseModel.setDatabaseName(database);
    databaseModel.setTables(tables);
    databaseModel.setTableColumns(tableColumns);

    return databaseModel;
}

/**
 * Create generic database model
 * @param databaseModel
 * @return
 */
dbcrudgen::db::generic::Database getGenericDatabase(dbcrudgen::mysql::MYSQLDatabaseModel &databaseModel) {
    return dbcrudgen::db::mysql::MYSQLDatabaseFlattener::flatten(databaseModel);
}

void createCppProject() {

    dbcrudgen::mysql::MYSQLDatabaseModel databaseModel = getMYSQLDatabaseModel("pesarika");

    std::string projectName = "pesarika-cpp";
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

    dbcrudgen::mysql::MYSQLDatabaseModel databaseModel = getMYSQLDatabaseModel("pesarika");
    dbcrudgen::db::generic::Database database = getGenericDatabase(databaseModel);

    std::string projectName = "pesarika-web";
    std::string workspaceDir = "/var/www/html";
    std::string controllersDir = "app/Http/Controllers";
    std::string modelsDir = "app/Http/Models";
    std::string viewsDir = "resources/views";
    std::string routesDir = "routes";
    std::string apiVersion = "v1";
    std::string webRouteFile = "web.php";
    std::string apiRouteFile = "api.php";

    dbcrudgen::orm::LaravelProjectModel projectModel{projectName, workspaceDir, controllersDir, modelsDir,
                                                     viewsDir, routesDir, webRouteFile, apiRouteFile,
                                                     apiVersion};

    dbcrudgen::orm::LaravelProjectCreator projectCreator{projectModel, database};
    projectCreator.createProject();

}


void createPostmanProject() {

    dbcrudgen::mysql::MYSQLDatabaseModel databaseModel = getMYSQLDatabaseModel("pesarika");

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
