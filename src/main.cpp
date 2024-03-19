#include <iostream>
#include <string>
#include <vector>
#include "databases/mysql/scaffolding/entities/Schemata.h"
#include "databases/mysql/connectors/MYSQLDatabaseConnector.h"
#include "databases/mysql/decomposer/MYSQLDatabaseDecomposer.h"
#include "databases/mysql/parsers/MYSQLDatabaseFlattener.h"
#include "databases/generic/Database.h"
#include "databases/mysql/models/MYSQLDatabaseModel.h"

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
 * Create Postman project
 */
void createPostmanProject(std::string &projectName, std::string &storeDirectory, std::string &protocol,
                          std::string &apiHost, int port, std::string &pathSegments, std::string &databaseType,
                          std::string &databaseName);

dbcrudgen::db::mysql::MYSQLDatabaseModel getMYSQLDatabaseModel(std::string database,
                                                               std::string username,
                                                               std::string password,
                                                               std::string host, int port);


int main(int argc, char **argv) {

    createMYSQLProjectBuilder();

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

void createMYSQLProjectBuilder() {
    std::string database = "dbcrudgen";
    std::string user = "root";
    std::string password = "Root@3358";
    std::string host = "127.0.0.1";
    int port = 13306;
    std::string connStr{"tcp://"};
    connStr = connStr.append(host).append(":").append(std::to_string(port));
    dbcrudgen::db::mysql::MYSQLDatabaseModelBuilder builder{connStr, host, port, user, password, database};
    const std::vector<dbcrudgen::db::mysql::Tables> &tables = builder.getSchemaTables();

    std::cout << "--------------------------- TABLES ---------------------------------" << std::endl;
    for (const auto &table: tables) {
        std::cout << table.getTableName() << std::endl;
    }

    std::cout << "--------------------------- PRIMARY KEYS ---------------------------------" << std::endl;

    for (auto &table: tables) {
        std::cout << " - - ::::::: - " << table.getTableName() << " - ::::::: - - " << std::endl;
        auto primaryKeys = builder.getTablePrimaryKeyColumns(table.getTableName());
        for (const auto &key: primaryKeys) {
            std::cout << key.getTableName() << "." << key.getColumnName() << std::endl;
        }
    }

    std::cout << "--------------------------- TABLE KEYS ---------------------------------" << std::endl;
    for (auto &table: tables) {
        std::cout << " - - ::::::: - " << table.getTableName() << " - ::::::: - - " << std::endl;
        auto keys = builder.getTableKeysColumns(table.getTableName());
        for (const auto &key: keys) {
            std::cout << key.getTableName() << "." << key.getColumnName() << std::endl;
        }
    }

    std::cout << "--------------------------- FOREIGN KEYS ---------------------------------" << std::endl;
    for (auto &table: tables) {
        std::cout << " - - ::::::: - " << table.getTableName() << " - ::::::: - - " << std::endl;
        auto foreign = builder.getTableForeignKeyColumns(table.getTableName());
        for (const auto &key: foreign) {
            std::cout << key.getTableName() << "." << key.getColumnName() << std::endl;
        }
    }

    std::cout << "--------------------------- EVENTS ---------------------------------" << std::endl;
    auto events = builder.getEvents();
    for (auto &event: events) {
        std::cout << event.getEventSchema() << "." << event.getEventName() << std::endl;
    }
    std::cout << "--------------------------- ROUTINES ---------------------------------" << std::endl;
    auto routines = builder.getRoutines();
    for (auto &routine: routines) {
        std::cout << routine.getRoutineSchema() << "." << routine.getRoutineName() << std::endl;
    }
    std::cout << "--------------------------- FUNCTIONS ---------------------------------" << std::endl;
    auto functions = builder.getFunctions();
    for (auto &function: functions) {
        std::cout << function.getRoutineSchema() << "." << function.getRoutineName() << std::endl;
    }
    std::cout << "--------------------------- PROCEDURES ---------------------------------" << std::endl;
    auto procedures = builder.getProcedures();
    for (auto &procedure: procedures) {
        std::cout << procedure.getRoutineSchema() << "." << procedure.getRoutineName() << std::endl;
    }
    std::cout << "--------------------------- RESOURCE GROUPS ---------------------------------" << std::endl;
    auto resourceGroups = builder.getResourceGroups();
    for (auto &group: resourceGroups) {
        std::cout << group.getResourceGroupType() << "." << group.getResourceGroupName() << std::endl;
    }
}