#include <iostream>
#include <string>
#include <vector>
#include "databases/mysql/scaffolding/entities/Schemata.h"
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
#include "databases/mysql/builder/MYSQLDatabaseModelBuilder.h"

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

void createMYSQLProjectBuilder();

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

    createPhpProject();

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

    dbcrudgen::db::mysql::MYSQLDatabaseModelBuilder builder{connStr, host, port, username, password, database};

    std::map<std::string, std::vector<dbcrudgen::db::mysql::Columns>> tableColumns;

    dbcrudgen::db::mysql::MYSQLDatabaseConnectionModel connectionModel{host, port, username, password, database};
    dbcrudgen::db::mysql::MYSQLDatabaseModel databaseModel{builder};

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

    dbcrudgen::db::mysql::MYSQLDatabaseModel databaseModel = getMYSQLDatabaseModel("corona_updates");
    dbcrudgen::db::generic::Database database = getGenericDatabase(databaseModel);

    std::string projectName = "corona-updates-ea-bot";
    std::string workspaceDir = "/var/www/html";
    std::string assetsDir = "public";
    std::string jsDir = "js";
    std::string cssDir = "css";
    std::string controllersDir = "app/Http/Controllers";
    std::string modelsDir = "app/Http/Models";
    std::string viewsDir = "resources/views";
    std::string routesDir = "routes";
    std::string apiVersion = "v1";
    std::string webRouteFile = "web2.php";
    std::string apiRouteFile = "api2.php";

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

    std::string projectName = "Pesarika";
    std::string storeDirectory = "/home/victor/Desktop";
    std::string protocol = "http";
    std::string apiHost = "localhost";
    int port = 8282;
    std::string pathSegments{"pesarika-rs-alpha/api/v1"};
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

    std::string projectName = "pesarika-rs-alpha";
    std::string workspaceDir = "/opt/victor/workspace/java";
    std::string packageName = "com.pesarika";

    std::string srcDir = "src";
    std::string moduleDir = "main";
    std::string javaDir = "java";
    std::string libsDir = "libs";
    std::string resourcesDir = "resources";

    std::string webDir = "webapp";
    std::string apisPkg = "web.apis";
    std::string dbConnPkg = "db.conn";
    std::string entitiesPkg = "db.entities";
    std::string transactionsPkg = "db.transactions";
    std::string webAppPkg = "web.application";
    std::string beansPkg = "web.beans";

    std::string apiClassSuffix = "Resource";
    std::string entityClassSuffix = "Entity";
    std::string trxClassSuffix = "Transactions";
    std::string beansClassSuffix = "Beans";

    std::string webAppClass = "WebApplication";
    std::string dbConnClass = "DatabaseConnectionHandler";
    std::string urlPattern = "/api/v1/*";

    dbcrudgen::orm::JaxWsProjectModel jaxWsModel{projectName, workspaceDir,
                                                 srcDir, moduleDir, javaDir, libsDir,
                                                 resourcesDir, packageName, webDir, apisPkg, dbConnPkg, entitiesPkg,
                                                 transactionsPkg, webAppPkg, beansPkg, apiClassSuffix,
                                                 entityClassSuffix,
                                                 trxClassSuffix, beansClassSuffix, webAppClass, dbConnClass,
                                                 urlPattern};
    dbcrudgen::orm::JaxWsProjectCreator jaxWsCreator{jaxWsModel, genericDatabase};
    //jaxWsCreator.createProject();


    dbcrudgen::orm::JaxRsProjectModel jaxRsModel{projectName, workspaceDir,
                                                 srcDir, moduleDir, javaDir, libsDir,
                                                 resourcesDir, packageName, webDir, apisPkg, dbConnPkg, entitiesPkg,
                                                 transactionsPkg, webAppPkg, beansPkg, apiClassSuffix,
                                                 entityClassSuffix,
                                                 trxClassSuffix, beansClassSuffix, webAppClass, dbConnClass,
                                                 urlPattern};

    dbcrudgen::orm::JaxRsProjectCreator jaxRsCreator{jaxRsModel, genericDatabase};
    jaxRsCreator.createProject();

}

void createMYSQLProjectBuilder() {
    std::string database = "pesarika";
    std::string user = "root";
    std::string password = "root3358";
    std::string host = "127.0.0.1";
    int port = 3306;
    std::string connStr{"tcp://"};
    connStr = connStr.append(host).append(":").append(std::to_string(port));
    dbcrudgen::db::mysql::MYSQLDatabaseModelBuilder builder{connStr, host, port, user, password, database};
    const std::vector<dbcrudgen::db::mysql::Tables> &tables = builder.getSchemaTables();

    std::cout << "--------------------------- TABLES ---------------------------------" << std::endl;
    for (const auto &table : tables) {
        std::cout << table.getTableName() << std::endl;
    }

    std::cout << "--------------------------- PRIMARY KEYS ---------------------------------" << std::endl;
    const std::vector<dbcrudgen::db::mysql::Columns> &primaryKeys = builder.getTablePrimaryKeyColumns("child");
    for (const auto &key : primaryKeys) {
        std::cout << key.getTableName() << "." << key.getColumnName() << std::endl;
    }

    std::cout << "--------------------------- TABLE KEYS ---------------------------------" << std::endl;
    const std::vector<dbcrudgen::db::mysql::Columns> &keys = builder.getTableKeysColumns("child");
    for (const auto &key : keys) {
        std::cout << key.getTableName() << "." << key.getColumnName() << std::endl;
    }

    std::cout << "--------------------------- FOREIGN KEYS ---------------------------------" << std::endl;
    const std::vector<dbcrudgen::db::mysql::Columns> &foreign = builder.getTableForeignKeyColumns("child");
    for (const auto &key : foreign) {
        std::cout << key.getTableName() << "." << key.getColumnName() << std::endl;
    }
}

void createJaxRsHibernateProject() {
    createJavaProject();
}