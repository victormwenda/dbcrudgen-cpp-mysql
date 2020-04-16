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
#include "orm/projects/JaxWsProjectModel.h"
#include "orm/creators/java/JaxWsProjectCreator.h"
#include "orm/creators/java/JaxRsProjectCreator.h"

/**
 * Returns a MYSQL Database Model
 * @param database
 * @param username
 * @param password
 * @param host
 * @return
 */
dbcrudgen::db::mysql::MYSQLDatabaseModel
getMYSQLDatabaseModel(std::string database, std::string username, std::string password, std::string host, int port);

/**
 * Create a Generic database from a MYSQL Database Model
 * @param databaseModel
 * @return
 */
dbcrudgen::db::generic::Database getGenericDatabase(dbcrudgen::db::mysql::MYSQLDatabaseModel &databaseModel);

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

void createJavaProject();

void createJaxRsHibernateProject();

int main(int argc, char **argv) {

    createJaxRsHibernateProject();

    return EXIT_SUCCESS;
}


/**
 * Returns a MYSQL Database Model
 * @param database
 * @param username
 * @param password
 * @param host
 * @param port
 * @return
 */
dbcrudgen::db::mysql::MYSQLDatabaseModel getMYSQLDatabaseModel(std::string database,
                                                               std::string username = "root",
                                                               std::string password = "root3358",
                                                               std::string host = "127.0.0.1", int port = 3306) {

    std::string connStr{"tcp://"};
    connStr = connStr.append(host).append(":").append(std::to_string(port));

    dbcrudgen::db::mysql::MYSQLDatabaseConnectionParams params{connStr, username, password, database};
    dbcrudgen::db::mysql::MYSQLDatabaseConnector connector{params};
    connector.open();

    dbcrudgen::db::mysql::MYSQLDatabaseDecomposer decomposer{connector};

    std::map<std::string, std::vector<dbcrudgen::db::mysql::Columns>> tableColumns;

    auto tables = decomposer.getSchemaTables(database);

    for (dbcrudgen::db::mysql::Tables &table  : tables) {
        std::string tableName = table.getTableName();
        std::vector<dbcrudgen::db::mysql::Columns> columns = decomposer.getTableColumns(database, tableName);
        tableColumns.insert({tableName, columns});
    }
    dbcrudgen::db::mysql::MYSQLDatabaseConnectionModel connectionModel{host, port, username, password, database};
    dbcrudgen::db::mysql::MYSQLDatabaseModel databaseModel{connectionModel};
    databaseModel.setTables(tables);
    databaseModel.setTableColumns(tableColumns);

    return databaseModel;
}

/**
 * Create generic database model
 * @param databaseModel
 * @return
 */
dbcrudgen::db::generic::Database getGenericDatabase(dbcrudgen::db::mysql::MYSQLDatabaseModel &databaseModel) {
    return dbcrudgen::db::mysql::MYSQLDatabaseFlattener::flatten(databaseModel);
}

void createCppProject() {

    dbcrudgen::db::mysql::MYSQLDatabaseModel databaseModel = getMYSQLDatabaseModel("pesarika");

    std::string projectName = "pesarika-cpp";
    std::string workspaceDir = "/opt/victor/workspace/cpp";
    std::string includesDir = "includes";
    std::string libsDir = "libs";
    std::string generatedCodeDir = "src/crud";
    std::string generatedModelCodeDir = "model";
    std::string generatedDbOpsCodeDir = "dao";

    dbcrudgen::orm::CppMYSQLProjectModel projectModel{projectName, workspaceDir, includesDir, libsDir,
                                                      generatedCodeDir, generatedModelCodeDir, generatedDbOpsCodeDir};

    dbcrudgen::orm::CppMYSQLProjectCreator projectCreator{projectModel, databaseModel};
    projectCreator.createProject();

}

void createPhpProject() {

    dbcrudgen::db::mysql::MYSQLDatabaseModel databaseModel = getMYSQLDatabaseModel("givewatts");
    dbcrudgen::db::generic::Database database = getGenericDatabase(databaseModel);

    std::string projectName = "givewatts-laravel";
    std::string workspaceDir = "/var/www/html";
    std::string assetsDir = "public";
    std::string jsDir = "js";
    std::string cssDir = "css";
    std::string controllersDir = "app/Http/Controllers";
    std::string modelsDir = "app/Http/Models";
    std::string viewsDir = "resources/views";
    std::string routesDir = "routes";
    std::string apiVersion = "v1";
    std::string webRouteFile = "web.php";
    std::string apiRouteFile = "api.php";

    dbcrudgen::orm::LaravelProjectModel projectModel{projectName, workspaceDir, controllersDir, modelsDir,
                                                     viewsDir, routesDir, assetsDir, jsDir, cssDir, webRouteFile,
                                                     apiRouteFile,
                                                     apiVersion};

    dbcrudgen::orm::LaravelProjectCreator projectCreator{projectModel, database};
    projectCreator.createProject();

}


void createPostmanProject() {

    dbcrudgen::db::mysql::MYSQLDatabaseModel databaseModel = getMYSQLDatabaseModel("pesarika");

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

void createJavaProject() {

    dbcrudgen::db::mysql::MYSQLDatabaseModel databaseModel = getMYSQLDatabaseModel("pesarika");
    auto genericDatabase = dbcrudgen::db::mysql::MYSQLDatabaseFlattener::flatten(databaseModel);

    std::string projectName = "pesarika-rs";
    std::string workspaceDir = "/opt/victor/workspace/java";
    std::string packageName = "com.database.mysql";

    std::string srcDir = "src";
    std::string moduleDir = "main";
    std::string javaDir = "java";
    std::string libsDir = "libs";
    std::string resourcesDir = "resources";

    std::string webDir = "webapp";
    std::string apisPkg = "web.apis";
    std::string entitiesPkg = "db.entities";
    std::string transactionsPkg = "db.transactions";

    std::string apiClassSuffix = "Resource";
    std::string entityClassSuffix = "Entity";
    std::string trxClassSuffix = "Transactions";


    dbcrudgen::orm::JaxWsProjectModel jaxWsModel{projectName, workspaceDir,
                                                 srcDir, moduleDir, javaDir, libsDir,
                                                 resourcesDir, packageName, webDir, apisPkg, entitiesPkg,
                                                 transactionsPkg, apiClassSuffix, entityClassSuffix, trxClassSuffix};
    dbcrudgen::orm::JaxWsProjectCreator jaxWsCreator{jaxWsModel, genericDatabase};
    //jaxWsCreator.createProject();


    dbcrudgen::orm::JaxRsProjectModel jaxRsModel{projectName, workspaceDir,
                                                 srcDir, moduleDir, javaDir, libsDir,
                                                 resourcesDir, packageName, webDir, apisPkg, entitiesPkg,
                                                 transactionsPkg, apiClassSuffix, entityClassSuffix, trxClassSuffix};
    dbcrudgen::orm::JaxRsProjectCreator jaxRsCreator{jaxRsModel, genericDatabase};
    jaxRsCreator.createProject();

}

void createJaxRsHibernateProject() {
    createJavaProject();
}