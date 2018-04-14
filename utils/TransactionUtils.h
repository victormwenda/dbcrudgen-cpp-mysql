//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 8/22/17.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_TRANSACTIONUTILS_H
#define DBCRUDGEN_CPP_TRANSACTIONUTILS_H


#include "ConnectorUtils.h"
#include "Tags.h"

#include "../core/database/columns/MYSQLTableColumn.h"
#include "../core/database/connectors/OracleDatabaseConnector.h"
#include "../core/database/connectors/MYSQLDatabaseConnector.h"
#include "../core/database/connectors/credentials/MYSQLDatabaseConnectionParams.h"
#include "../core/database/prepared/MYSQLStatements.h"
#include "../core/database/relations/MYSQLDatabaseTable.h"

#include "../lang/parser/mysql/MYSQLLangParser.h"
#include "../core/database/tables/MysqlRelationTypes.h"
#include "MysqlTags.h"

#include <cppconn/statement.h>
#include <cppconn/resultset.h>

//
// TransactionUtils
// //
class TransactionUtils {

public:
    /**
     * Get the list of all tables in a MYSQL Database
     *
     * @param connectionParams
     * @return
     */
    static std::vector<std::string>
    getMYSQLDatabaseNames(MYSQLDatabaseConnector &connector) {
        std::vector<std::string> schemaNames;
        std::string query = MYSQLStatements::SHOW_SCHEMAS_QUERY;
        sql::Statement *statement = &connector.createStatement();
        sql::ResultSet *resultSet = statement->executeQuery(query);

        while (resultSet->next()) {
            schemaNames.push_back(resultSet->getString(1));
        }
        resultSet->close();
        statement->close();
        return schemaNames;
    }

    /**
     * Get the list of all tables in a MYSQL Database
     *
     * @param connectionParams
     * @return
     */
    static std::vector<std::string>
    getMYSQLDatabaseTableNames(MYSQLDatabaseConnector &connector, const std::string &schemas) {
        std::vector<std::string> tablesNames;
        std::string showSchemasTablesQuery = MYSQLStatements::SCHEMAS_TABLES_QUERY;
        std::string query = StringUtils::parseTemplate(showSchemasTablesQuery, Tags::SCHEMA, schemas);
        sql::Statement *statement = &connector.createStatement();
        sql::ResultSet *resultSet = statement->executeQuery(query);

        while (resultSet->next()) {
            tablesNames.push_back(resultSet->getString(1));
        }
        resultSet->close();
        statement->close();
        return tablesNames;
    }

    /**
     * Get the list of all tables in a MYSQL Database
     *
     * @param connectionParams
     * @return
     */
    static std::vector<std::string>
    getMYSQLDatabaseTablesCreateStatements(MYSQLDatabaseConnector &connector, const std::string &schemas) {

        std::vector<std::string> tablesNames = getMYSQLDatabaseTableNames(connector, schemas);

        sql::Statement *statement = &connector.createStatement();

        std::vector<std::string> tableCreateStatements;

        for (std::string tableName : tablesNames) {

            std::string tablesCreateStatementQuery = MYSQLStatements::TABLES_CREATE_QUERY;
            std::string query = StringUtils::parseTemplate(tablesCreateStatementQuery, Tags::SCHEMAS, schemas);
            query = StringUtils::parseTemplate(tablesCreateStatementQuery, Tags::TABLE_NAME, tableName);

            sql::ResultSet *resultSet = statement->executeQuery(query);

            while (resultSet->next()) {
                tableCreateStatements.push_back(resultSet->getString(2));
            }
            resultSet->close();
        }

        statement->close();
        return tableCreateStatements;
    }

    /**
     * Get the create table statement for a MYSQL Database table
     *
     * @param connectionParams
     * @return
     */
    static std::string
    getMYSQLDatabaseTableCreateStatement(MYSQLDatabaseConnector &connector, const std::string &schemas,
                                         const std::string tableName) {

        std::string tableCreateStatement = "";

        std::string tablesCreateStatementQuery = MYSQLStatements::TABLES_CREATE_QUERY;
        std::string query = StringUtils::parseTemplate(tablesCreateStatementQuery, Tags::SCHEMAS, schemas);
        query = StringUtils::parseTemplate(tablesCreateStatementQuery, Tags::TABLE_NAME, tableName);

        sql::Statement *statement = &connector.createStatement();
        sql::ResultSet *resultSet = statement->executeQuery(query);

        while (resultSet->next()) {
            tableCreateStatement = resultSet->getString(2);
        }

        resultSet->close();
        statement->close();

        return tableCreateStatement;
    }

    /**
     * Returns a vector of MYSQLTableColumns found in the provided table
     *
     * @param connector
     * @param schemas
     * @param tableName
     * @return
     */
    static std::vector<MYSQLTableColumn>
    getMYSQLTableColumns(MYSQLDatabaseConnector &connector, const std::string &schemas, std::string tableName) {

        std::vector<MYSQLTableColumn> tableColumns;

        std::string absoluteTableName{MYSQLLangParser::toAbsolutePath(schemas, tableName)};
        std::string getTableColumnsQuery{MYSQLStatements::TABLE_COLUMNS_FULL};
        std::string query = StringUtils::parseTemplate(getTableColumnsQuery, Tags::TABLE_NAME, absoluteTableName);

        sql::Statement *statement = &connector.createStatement();
        sql::ResultSet *resultSet = statement->executeQuery(query);

        while (resultSet->next()) {
            std::string field = resultSet->getString("Field");
            std::string type = resultSet->getString("Type");
            std::string collation = resultSet->getString("Collation");
            std::string allowNull = resultSet->getString("Null");
            std::string key = resultSet->getString("Key");
            std::string defaultValue = resultSet->getString("Default");
            std::string extra = resultSet->getString("Extra");
            std::string privileges = resultSet->getString("Privileges");
            std::string comment = resultSet->getString("Comment");
            MYSQLTableColumn mysqlTable{field, type, collation, allowNull, key, defaultValue, extra, privileges,
                                        comment};
            tableColumns.push_back(mysqlTable);
        }
        resultSet->close();
        statement->close();

        return tableColumns;
    }

    /**
     * Returns the names of the tables in a MYSQL Database
     *
     * @param connector
     * @param schemas
     * @return
     */
    static std::vector<MYSQLDatabaseTable>
    getMYSQLDatabaseTables(MYSQLDatabaseConnector &connector, const std::string &schemas) {

        std::vector<std::string> tableNames = TransactionUtils::getMYSQLDatabaseTableNames(connector, schemas);

        std::vector<MYSQLDatabaseTable> dbTables;

        for (const std::string &tableName : tableNames) {

            std::string getTableSchemasQuery{MYSQLStatements::TABLE_SCHEMA_STATEMENT};
            std::string query = StringUtils::parseTemplate(getTableSchemasQuery, Tags::TABLE_NAME, tableName);

            sql::Statement *statement = &connector.createStatement();
            sql::ResultSet *resultSet = statement->executeQuery(query);

            while (resultSet->next()) {

                std::string table_catalog = resultSet->getString("TABLE_CATALOG");
                std::string table_schema = resultSet->getString("TABLE_SCHEMA");
                std::string table_name = resultSet->getString("TABLE_NAME");
                std::string table_type = resultSet->getString("TABLE_TYPE");
                std::string engine = resultSet->getString("ENGINE");
                std::string version = resultSet->getString("VERSION");
                std::string row_format = resultSet->getString("ROW_FORMAT");
                std::string rows = resultSet->getString("TABLE_ROWS");
                std::string avg_row_length = resultSet->getString("AVG_ROW_LENGTH");
                std::string data_length = resultSet->getString("DATA_LENGTH");
                std::string max_data_length = resultSet->getString("MAX_DATA_LENGTH");
                std::string index_length = resultSet->getString("INDEX_LENGTH");
                std::string data_free = resultSet->getString("DATA_FREE");
                std::string auto_increment = resultSet->getString("AUTO_INCREMENT");
                std::string create_time = resultSet->getString("CREATE_TIME");
                std::string update_time = resultSet->getString("UPDATE_TIME");
                std::string check_time = resultSet->getString("CHECK_TIME");
                std::string collation = resultSet->getString("TABLE_COLLATION");
                std::string checksum = resultSet->getString("CHECKSUM");
                std::string create_options = resultSet->getString("TABLE_COMMENT");
                std::string comment = resultSet->getString("CREATE_OPTIONS");

                std::vector<MYSQLTableColumn> tableColumns =
                        TransactionUtils::getMYSQLTableColumns(connector, schemas, table_name);

                dbTables.push_back(MYSQLDatabaseTable {table_catalog,
                                                       table_schema, table_name, table_type, engine, version,
                                                       row_format, rows, avg_row_length,
                                                       data_length, max_data_length, index_length, data_free,
                                                       auto_increment, create_time, update_time, check_time,
                                                       collation, checksum, create_options, comment, tableColumns});

            }

            resultSet->close();
            statement->close();
        }


        return dbTables;
    }

    /**
     * Get the list of all tables in a MYSQL Database
     *
     * @param connectionParams
     * @return
     */
    static std::vector<std::string>
    getMYSQLDatabaseViewNames(MYSQLDatabaseConnector &connector, const std::string &schemas) {
        std::vector<std::string> viewNames;
        std::string showSchemasTablesQuery = MYSQLStatements::SCHEMAS_VIEWS_QUERY;
        std::string query = StringUtils::parseTemplate(showSchemasTablesQuery, Tags::SCHEMA, schemas);
        query = StringUtils::parseTemplate(showSchemasTablesQuery, MysqlTags::TABLE_TYPE_VIEW,
                                           MysqlRelationTypes::TABLE_TYPE_VIEW);
        sql::Statement *statement = &connector.createStatement();
        sql::ResultSet *resultSet = statement->executeQuery(query);

        while (resultSet->next()) {
            viewNames.push_back(resultSet->getString(1));
        }
        resultSet->close();
        statement->close();
        return viewNames;
    }

    /**
    * Get the create table statement for a MYSQL Database table
    *
    * @param connectionParams
    * @return
    */
    static std::string
    getMYSQLDatabaseViewCreateStatement(MYSQLDatabaseConnector &connector, const std::string &schemas,
                                         const std::string viewName) {

        std::string tableCreateStatement = "";

        std::string tablesCreateStatementQuery = MYSQLStatements::VIEW_CREATE_QUERY;
        std::string query = StringUtils::parseTemplate(tablesCreateStatementQuery, Tags::SCHEMAS, schemas);
        query = StringUtils::parseTemplate(tablesCreateStatementQuery, Tags::VIEW_NAME, viewName);

        sql::Statement *statement = &connector.createStatement();
        sql::ResultSet *resultSet = statement->executeQuery(query);

        while (resultSet->next()) {
            tableCreateStatement = resultSet->getString(2);
        }

        resultSet->close();
        statement->close();

        return tableCreateStatement;
    }
};


#endif //DBCRUDGEN_CPP_TRANSACTIONUTILS_H
