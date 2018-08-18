#include <iostream>
#include <cppconn/connection.h>
#include <mysql_connection.h>
#include "core/database/connectors/MYSQLDatabaseConnector.h"
#include "utils/TransactionUtils.h"
#include "models/MYSQLDatabaseModel.h"

void showMYSQLDatabaseNames(MYSQLDatabaseConnector &mysqlDatabaseConnector);

void showMYSQLDatabaseTableNames(MYSQLDatabaseConnector &mysqlDatabaseConnector);

void showMYSQLDatabaseViewNames(MYSQLDatabaseConnector &mysqlDatabaseConnector);

void showMYSQLDatabaseTableColumns(MYSQLDatabaseConnector &mysqlDatabaseConnector);

void getMYSQLDatabaseTablesCreateStatements(MYSQLDatabaseConnector &mysqlDatabaseConnector);

void getMYSQLDatabaseTableCreateStatement(MYSQLDatabaseConnector &mysqlDatabaseConnector);

void getMYSQLDatabaseViewCreateStatement(MYSQLDatabaseConnector &mysqlDatabaseConnector);

void showMYSQLDatabaseColumnsUsages(MYSQLDatabaseConnector &mysqlDatabaseConnector);

void showMYSQLUsers(MYSQLDatabaseConnector &mysqlDatabaseConnector);

int main(int argc, char **argv) {

    std::string host = "tcp://127.0.0.1";
    std::string user = "root";
    std::string auth_string = "root3358";
    std::string schemas = "cscart";

    MYSQLDatabaseConnectionParams connectionParams = MYSQLDatabaseConnectionParams{host, user, auth_string,
                                                                                   schemas};

    MYSQLDatabaseConnector connector = ConnectorUtils::openMYSQLDatabase(connectionParams);


    MYSQLDatabaseModel dbModel{connector};
    std::vector<MysqlTable> items = dbModel.getTables(schemas);


    int index = 0;

    for (const MysqlTable &item : items) {
        std::cout << ++index << " ";
        std::cout << item.getName() << " " << item.getType() << std::endl;

        auto&& tableName = item.getName();

        std::string createStatement = MYSQLDatabaseModel::getMYSQLDatabaseTableCreateStatement(connector, schemas,tableName);
        std::cout << "\n" << createStatement<< "\n\n";

        std::vector<MYSQLTableColumn> tableColumns = MYSQLDatabaseModel::getMYSQLTableColumns(connector,schemas,  tableName);
        std::cout <<" ------------------------------------------------------------------------- " << std::endl;
        for(const MYSQLTableColumn &column : tableColumns) {
            std::cout << column.getField() <<" : " << column.getType() << ",";
        }
        std::cout << "\n------------------------------------------------------------------------- \n\n\n\n" ;
    }

    return EXIT_SUCCESS;
}

void showMYSQLDatabaseViewNames(MYSQLDatabaseConnector &mysqlDatabaseConnector) {
    const std::vector<std::string> &viewNames =
            TransactionUtils::getMYSQLDatabaseViewNames(mysqlDatabaseConnector, "dbcrudgen");
    for (const std::string &viewName : viewNames) {
        std::cout << viewName << std::endl;
    }
}

void getMYSQLDatabaseTableCreateStatement(MYSQLDatabaseConnector &mysqlDatabaseConnector) {
    std::string createStatement = TransactionUtils::getMYSQLDatabaseTableCreateStatement(mysqlDatabaseConnector,
                                                                                         "dbcrudgen", "bug_logger");
    std::cout << createStatement << std::endl;
}

void getMYSQLDatabaseTablesCreateStatements(MYSQLDatabaseConnector &mysqlDatabaseConnector) {
    const std::vector<std::string> &tableNames =
            TransactionUtils::getMYSQLDatabaseTablesCreateStatements(mysqlDatabaseConnector, "dbcrudgen");
    for (const std::string &tableName : tableNames) {
        std::cout << tableName << std::endl;
    }
}

void showMYSQLDatabaseTableNames(MYSQLDatabaseConnector &mysqlDatabaseConnector) {
    const std::vector<std::string> &tableNames =
            TransactionUtils::getMYSQLDatabaseTableNames(mysqlDatabaseConnector, "dbcrudgen");
    for (const std::string &tableName : tableNames) {
        std::cout << tableName << std::endl;
    }
}

void showMYSQLDatabaseTableColumns(MYSQLDatabaseConnector &mysqlDatabaseConnector) {
    const std::vector<MYSQLDatabaseTable> &tables
            = TransactionUtils::getMYSQLDatabaseTables(mysqlDatabaseConnector, "dbcrudgen");

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

void showMYSQLDatabaseNames(MYSQLDatabaseConnector &mysqlDatabaseConnector) {
    const std::vector<std::string> &databaseNames =
            TransactionUtils::getMYSQLDatabaseNames(mysqlDatabaseConnector);
    for (const std::string &databaseName : databaseNames) {
        std::cout << databaseName << std::endl;
    }
}

void getMYSQLDatabaseViewCreateStatement(MYSQLDatabaseConnector &mysqlDatabaseConnector) {
    std::string createStatement = TransactionUtils::getMYSQLDatabaseViewCreateStatement(mysqlDatabaseConnector,
                                                                                        "dbcrudgen", "bug_logger_view");
    std::cout << createStatement << std::endl;
}

void showMYSQLDatabaseColumnsUsages(MYSQLDatabaseConnector &mysqlDatabaseConnector) {
    std::vector<MysqlKeyColumnUsage> columnsUsages
            = TransactionUtils::getMYSQLDatabaseColumnsUsages(mysqlDatabaseConnector, "dbcrudgen");

    for (MysqlKeyColumnUsage &columnUsage : columnsUsages) {
        std::cout << columnUsage.getTableName() << "." << columnUsage.getColumnName() << " -> ";
        std::cout << columnUsage.getReferencedTableName() << "." << columnUsage.getReferencedColumnName() << "\n";
    }
}

void showMYSQLUsers(MYSQLDatabaseConnector &mysqlDatabaseConnector) {
    std::vector<MysqlUser> users
            = TransactionUtils::getMYSQLUsers(mysqlDatabaseConnector);

    for (MysqlUser &user : users) {
        std::cout << user.getUser() << "@" << user.getHost() << "\n";
    }
}