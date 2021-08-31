#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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
#include "orm/projects/AngularProjectModel.h"
#include "orm/creators/angular/AngularProjectCreator.h"
#include "orm/projects/SpringBootProjectModel.h"
#include "orm/creators/java/SpringBootProjectCreator.h"
#include "databases/mssql/executor/MSSQLQueryExecutor.h"
#include "databases/mssql/connectors/MSSQLDbConnParams.h"
#include "databases/mssql/connectors/MSSQLDbConnector.h"
#include "databases/mssql/executor/MSSQLColBinder.h"

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
 * Create Angular Project
 */
void createAngularProject();

/**
 * Create Postman project
 */
void createPostmanProject(std::string &projectName, std::string &storeDirectory, std::string &protocol,
                          std::string &apiHost, int port, std::string &pathSegments, std::string &databaseType,
                          std::string &databaseName);

void createJavaProject();

void createJaxRsHibernateProject();

void createSpringBootHibernateProject();

void testPostmanProject();


int main(int argc, char **argv) {
/*
    std::string host = "localhost";
    int port = 1433;
    std::string database = "dbcrudgen";
    std::string user = "sa";
    std::string password = "Root@3358";
    dbcrudgen::db::mssql::MSSQLDbConnParams connParams{host, port, database, user, password};
    dbcrudgen::db::mssql::MSSQLDbConnector connector{connParams};
    connector.openConnection();
    SQLHDBC hDbc = connector.getHDbc();

    if (hDbc == nullptr) {
        std::cout << "second check -- null" << std::endl;
    }

    SQLCHAR username[255];
    SQLLEN username_indicator;
    std::string usernameColName = "username";

    SQLCHAR fullname[255];
    SQLLEN fullname_indicator;
    std::string fullnameColName = "fullname";

    dbcrudgen::db::mssql::MSSQLQueryExecutor executor{hDbc};
    std::vector<dbcrudgen::db::mssql::MSSQLColBinder> colBindings;
    colBindings.emplace_back(  dbcrudgen::db::mssql::MSSQLColBinder{1, SQL_C_CHAR,usernameColName, username, 255, &username_indicator});
    colBindings.emplace_back(  dbcrudgen::db::mssql::MSSQLColBinder{2, SQL_C_CHAR, fullnameColName, fullname, 255, &fullname_indicator});
    std::vector<dbcrudgen::db::mssql::MSSQLResultSet> resultSet{};
    executor.execQuery("SELECT * FROM test;", colBindings, resultSet);

    std::cout << "--------------PRINTING RESULTS -------" << std::endl;
    for (const dbcrudgen::db::mssql::MSSQLResultSet& data: resultSet) {
        void *colValue = data.getColumnValue();
        std::cout << " Column Index : " << data.columnIndex
                  << " : Column name : " << data.columnName
                  << " : Column Value : " << *reinterpret_cast<std::string *>(colValue) << std::endl;
    }

    executor.freeStatementHandle();
    connector.closeConnection();*/
    std::vector<std::string> items{std::string{"name"}, std::string{"database_id"}, std::string{"source_database_id"}, std::string{"owner_sid"}, std::string{"create_date"}, std::string{"compatibility_level"}, std::string{"collation_name"}, std::string{"user_access"}, std::string{"user_access_desc"}, std::string{"is_read_only"}, std::string{"is_auto_close_on"}, std::string{"is_auto_shrink_on"}, std::string{"state"}, std::string{"state_desc"}, std::string{"is_in_standby"}, std::string{"is_cleanly_shutdown"}, std::string{"is_supplemental_logging_enabled"}, std::string{"snapshot_isolation_state"}, std::string{"snapshot_isolation_state_desc"}, std::string{"is_read_committed_snapshot_on"}, std::string{"recovery_model"}, std::string{"recovery_model_desc"}, std::string{"page_verify_option"}, std::string{"page_verify_option_desc"}, std::string{"is_auto_create_stats_on"}, std::string{"is_auto_create_stats_incremental_on"}, std::string{"is_auto_update_stats_on"}, std::string{"is_auto_update_stats_async_on"}, std::string{"is_ansi_null_default_on"}, std::string{"is_ansi_nulls_on"}, std::string{"is_ansi_padding_on"}, std::string{"is_ansi_warnings_on"}, std::string{"is_arithabort_on"}, std::string{"is_concat_null_yields_null_on"}, std::string{"is_numeric_roundabort_on"}, std::string{"is_quoted_identifier_on"}, std::string{"is_recursive_triggers_on"}, std::string{"is_cursor_close_on_commit_on"}, std::string{"is_local_cursor_default"}, std::string{"is_fulltext_enabled"}, std::string{"is_trustworthy_on"}, std::string{"is_db_chaining_on"}, std::string{"is_parameterization_forced"}, std::string{"is_master_key_encrypted_by_server"}, std::string{"is_query_store_on"}, std::string{"is_published"}, std::string{"is_subscribed"}, std::string{"is_merge_published"}, std::string{"is_distributor"}, std::string{"is_sync_with_backup"}, std::string{"service_broker_guid"}, std::string{"is_broker_enabled"}, std::string{"log_reuse_wait"}, std::string{"log_reuse_wait_desc"}, std::string{"is_date_correlation_on"}, std::string{"is_cdc_enabled"}, std::string{"is_encrypted"}, std::string{"is_honor_broker_priority_on"}, std::string{"replica_id"}, std::string{"group_database_id"}, std::string{"resource_pool_id"}, std::string{"default_language_lcid"}, std::string{"default_language_name"}, std::string{"default_fulltext_language_lcid"}, std::string{"default_fulltext_language_name"}, std::string{"is_nested_triggers_on"}, std::string{"is_transform_noise_words_on"}, std::string{"two_digit_year_cutoff"}, std::string{"containment"}, std::string{"containment_desc"}, std::string{"target_recovery_time_in_seconds"}, std::string{"delayed_durability"}, std::string{"delayed_durability_desc"}, std::string{"is_memory_optimized_elevate_to_snapshot_on"}, std::string{"is_federation_member"}, std::string{"is_remote_data_archive_enabled"}, std::string{"is_mixed_page_allocation_on"}, std::string{"is_temporal_history_retention_enabled"},};


    for (int i = 0; i < items.size(); i++) {
        std::string item = items[i];
        std::string nameUpper = item;
        std::transform(nameUpper.begin(), nameUpper.end(), nameUpper.begin(), ::toupper);
std::cout <<
"SQLCHAR " << item << "[255];"
"SQLLEN " << item << "_indicator;"
        << std::endl
<< "colBindings.emplace_back(MSSQLColBinder{"<< "SQL_C_CHAR,SysDatabases::COLUMNS::" << nameUpper << "::INDEX , " << " SQL_C_CHAR,SysDatabases::COLUMNS::" << nameUpper << "::NAME , " << item  << ", 255, &" << item << "_indicator;" << "});"
 << std::endl
 << std::endl
;

    }
















































































    //createSpringBootHibernateProject();
    //createPhpProject();
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

void createAngularProject() {

    dbcrudgen::db::mysql::MYSQLDatabaseModel databaseModel = getMYSQLDatabaseModel("eqtr");
    dbcrudgen::db::generic::Database database = getGenericDatabase(databaseModel);

    std::string projectName = "eqtr-web";
    std::string workspaceDir = "/opt/workspace/javascript";
    std::string distDir = "dist";
    std::string e2eDir = "e2e";
    std::string nodeModulesDir = "node_modules";
    std::string srcDir = "src";
    std::string appDir = "app";
    std::string assetsDir = "assets";
    std::string environmentDir = "environments";
    std::string moduleDir = "admin";
    std::string modelsDir = "models";
    std::string baseUrl = "http://127.0.0.1:8000/api/v1";

    dbcrudgen::orm::AngularProjectModel projectModel{workspaceDir, projectName, distDir, e2eDir,
                                                     nodeModulesDir, srcDir, appDir, assetsDir,
                                                     environmentDir, moduleDir, modelsDir, baseUrl};

    dbcrudgen::orm::AngularProjectCreator projectCreator{projectModel, database};
    projectCreator.createProject();

}

void createPhpProject() {

    dbcrudgen::db::mysql::MYSQLDatabaseModel databaseModel = getMYSQLDatabaseModel("eqtr");
    dbcrudgen::db::generic::Database database = getGenericDatabase(databaseModel);

    std::string projectName = "eqtr-web-adm-laravel";
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

void testPostmanProject() {
    std::string projectName = "Digisoko";
    std::string storeDirectory = "/home/victor/Desktop";
    std::string protocol = "https";
    std::string apiHost = "localhost";
    int port = 443;
    std::string pathSegments = "/v1/";
    std::string databaseType = "mysql";
    std::string databaseName = "digisoko";
    createPostmanProject(projectName, storeDirectory, protocol, apiHost, port, pathSegments, databaseType,
                         databaseName);
}

void createPostmanProject(std::string &projectName, std::string &storeDirectory, std::string &protocol,
                          std::string &apiHost, int port, std::string &pathSegments, std::string &databaseType,
                          std::string &databaseName) {

    dbcrudgen::db::mysql::MYSQLDatabaseModel databaseModel = getMYSQLDatabaseModel(databaseName);

    auto genericDatabase = dbcrudgen::db::mysql::MYSQLDatabaseFlattener::flatten(databaseModel);

    std::map<std::string, std::string> headers;

    headers.insert(std::pair<std::string, std::string>(std::string{"Content-Type"}, std::string{"application/json"}));
    headers.insert(std::pair<std::string, std::string>(std::string{"Accept"}, std::string{"application/json"}));

    dbcrudgen::orm::PostmanProjectModel projectModel{projectName, storeDirectory, protocol, apiHost, port,
                                                     pathSegments, headers, databaseType};
    dbcrudgen::orm::PostmanProjectCreator projectCreator{projectModel, genericDatabase};
    projectCreator.createProject();
}

void createJavaProject() {

    dbcrudgen::db::mysql::MYSQLDatabaseModel databaseModel = getMYSQLDatabaseModel("eqtr");
    auto genericDatabase = dbcrudgen::db::mysql::MYSQLDatabaseFlattener::flatten(databaseModel);

    std::string projectName = "eqtr-apis";
    std::string workspaceDir = "/opt/workspace/java";
    std::string packageName = "com.eqtr.webservices";

    std::string srcDir = "src";
    std::string moduleDir = "main";
    std::string javaDir = "java";
    std::string libsDir = "libs";
    std::string resourcesDir = "resources";

    std::string webDir = "webapp";
    std::string apisPkg = "web.apis";
    std::string dbConnPkg = "database.conn";
    std::string entitiesPkg = "database.entities";
    std::string transactionsPkg = "database.transactions";
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
    for (const auto &table: tables) {
        std::cout << table.getTableName() << std::endl;
    }

    std::cout << "--------------------------- PRIMARY KEYS ---------------------------------" << std::endl;
    const std::vector<dbcrudgen::db::mysql::Columns> &primaryKeys = builder.getTablePrimaryKeyColumns("child");
    for (const auto &key: primaryKeys) {
        std::cout << key.getTableName() << "." << key.getColumnName() << std::endl;
    }

    std::cout << "--------------------------- TABLE KEYS ---------------------------------" << std::endl;
    const std::vector<dbcrudgen::db::mysql::Columns> &keys = builder.getTableKeysColumns("child");
    for (const auto &key: keys) {
        std::cout << key.getTableName() << "." << key.getColumnName() << std::endl;
    }

    std::cout << "--------------------------- FOREIGN KEYS ---------------------------------" << std::endl;
    const std::vector<dbcrudgen::db::mysql::Columns> &foreign = builder.getTableForeignKeyColumns("child");
    for (const auto &key: foreign) {
        std::cout << key.getTableName() << "." << key.getColumnName() << std::endl;
    }
}

void createJaxRsHibernateProject() {
    createJavaProject();
}

void createSpringBootHibernateProject() {
    dbcrudgen::db::mysql::MYSQLDatabaseModel databaseModel = getMYSQLDatabaseModel("nats");
    auto genericDatabase = dbcrudgen::db::mysql::MYSQLDatabaseFlattener::flatten(databaseModel);

    std::string projectName = "nats-java";
    std::string workspaceDir = "/opt/workspace/java";
    std::string packageName = "ke.co.nats";

    std::string srcDir = "src";
    std::string moduleDir = "main";
    std::string javaDir = "java";
    std::string libsDir = "libs";
    std::string resourcesDir = "resources";
    std::string webDir = "public";
    dbcrudgen::orm::SpringProjectDirs sbDirs{srcDir, moduleDir, javaDir, libsDir, resourcesDir, webDir};

    std::string beansPkg = "dblayer.beans";
    std::string dbConnPkg = "dblayer.conn";
    std::string reposPkg = "dblayer.repos";
    std::string entitiesPkg = "dblayer.entities";
    std::string modelPkg = "dblayer.models";

    std::string httpReqPkg = "entry.http.requests";
    std::string httpResPkg = "entry.http.responses";
    std::string ctlPkg = "entry.controllers";
    std::string transactionsPkg = "dblayer.dao";
    std::string bzLogicPkg = "service.business";
    std::string webAppPkg = "app";
    dbcrudgen::orm::SpringProjectPackages sbPkgs{beansPkg, bzLogicPkg, ctlPkg, dbConnPkg, entitiesPkg, httpReqPkg,
                                                 httpResPkg, modelPkg, reposPkg, transactionsPkg, webAppPkg};

    std::string webAppClass = "Application";
    std::string dbConnClass = "DatabaseConnectionHandler";
    std::string applicationProperties = "application.properties";
    dbcrudgen::orm::SpringProjectClasses sbClasses{dbConnClass, webAppClass, applicationProperties};

    std::string urlPattern = "/";
    int serverPort = 8080;

    std::string ctlClassSuffix = "Controller";
    std::string beansClassSuffix = "Beans";
    std::string bzLogicClassSuffix = "Service";
    std::string entityClassSuffix = "Entity";
    std::string httpReqClassSuffix = "Request";
    std::string httpResClassSuffix = "Response";
    std::string reposClassSuffix = "Repository";
    std::string trxClassSuffix = "Dao";
    std::string modelClassSuffix = "Model";

    dbcrudgen::orm::SpringProjectSuffixes sbClsSuffxs{beansClassSuffix, bzLogicClassSuffix, ctlClassSuffix,
                                                      entityClassSuffix, httpReqClassSuffix, httpResClassSuffix,
                                                      modelClassSuffix, reposClassSuffix, trxClassSuffix};

    dbcrudgen::orm::SpringBootProjectModel sbModel{projectName, workspaceDir, packageName, sbDirs, sbPkgs, sbClasses,
                                                   sbClsSuffxs, urlPattern, serverPort};

    dbcrudgen::orm::SpringBootProjectCreator sbCreator{sbModel, genericDatabase};
    sbCreator.createProject();
}