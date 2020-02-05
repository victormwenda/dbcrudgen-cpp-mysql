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
#include "../../databases/sql/parsers/Tags.h"

#include "../../databases/oracle/connectors/OracleDatabaseConnector.h"
#include "../../databases/mysql/connectors/MYSQLDatabaseConnector.h"
#include "../../databases/mysql/connectors/MYSQLDatabaseConnectionParams.h"
#include "../../databases/mysql/queries/MYSQLStatements.h"
#include "../../databases/mysql/models/MYSQLDatabaseTable.h"
#include "../../databases/mysql/models/MysqlKeyColumnUsage.h"

#include "../../databases/mysql/parsers/MYSQLLangParser.h"
#include "../../databases/oracle/parsers/MysqlTags.h"
#include "../../databases/mysql/models/MysqlUser.h"
#include "../../databases/mysql/objects/tables/MysqlUserColumn.h"
#include "../../databases/mysql/objects/tables/MysqlKeyColumnUsageTableColumns.h"
#include "../../databases/mysql/objects/MysqlRelationTypes.h"

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

        for (const std::string& tableName : tablesNames) {

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
                                         const std::string &tableName) {

        std::string tableCreateStatement;

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
    getMYSQLTableColumns(MYSQLDatabaseConnector &connector, const std::string &schemas, const std::string &tableName) {

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

                dbTables.emplace_back(MYSQLDatabaseTable{table_catalog,
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
                                        const std::string& viewName) {

        std::string tableCreateStatement;

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

    /**
     * Returns all the references used in a MYSQL table schema
     *
     * @param connector
     * @param schemas
     * @return
     */
    static std::vector<MysqlKeyColumnUsage>
    getMYSQLDatabaseColumnsUsages(MYSQLDatabaseConnector &connector, const std::string& schemas) {
        std::vector<MysqlKeyColumnUsage> references;

        std::string columnsUsageQuery = MYSQLStatements::KEY_COLUMN_USAGES;
        std::string query = StringUtils::parseTemplate(columnsUsageQuery, Tags::SCHEMA, schemas);

        sql::Statement *statement = &connector.createStatement();
        sql::ResultSet *resultSet = statement->executeQuery(query);

        while (resultSet->next()) {

            std::string constraintCatalog = resultSet->getString(
                    MysqlKeyColumnUsageTableColumns::COLUMN_CONSTRAINT_CATALOG);
            std::string constraintSchema = resultSet->getString(
                    MysqlKeyColumnUsageTableColumns::COLUMN_CONSTRAINT_SCHEMA);
            std::string constraintName = resultSet->getString(MysqlKeyColumnUsageTableColumns::COLUMN_CONSTRAINT_NAME);
            std::string tableCatalog = resultSet->getString(MysqlKeyColumnUsageTableColumns::COLUMN_TABLE_CATALOG);
            std::string tableSchema = resultSet->getString(MysqlKeyColumnUsageTableColumns::COLUMN_TABLE_SCHEMA);
            std::string tableName = resultSet->getString(MysqlKeyColumnUsageTableColumns::COLUMN_TABLE_NAME);
            std::string columnName = resultSet->getString(MysqlKeyColumnUsageTableColumns::COLUMN_COLUMN_NAME);
            long int ordinalPosition = resultSet->getInt(MysqlKeyColumnUsageTableColumns::COLUMN_ORDINAL_POSITION);
            long int positionInUniqueConstraint = resultSet->getInt(
                    MysqlKeyColumnUsageTableColumns::COLUMN_POSITION_IN_UNIQUE_CONSTRAINT);
            std::string referencedTableSchema = resultSet->getString(
                    MysqlKeyColumnUsageTableColumns::COLUMN_REFERENCED_TABLE_SCHEMA);
            std::string referencedTableName = resultSet->getString(
                    MysqlKeyColumnUsageTableColumns::COLUMN_REFERENCED_TABLE_NAME);
            std::string referencedColumnName = resultSet->getString(
                    MysqlKeyColumnUsageTableColumns::COLUMN_REFERENCED_COLUMN_NAME);

            references.emplace_back(MysqlKeyColumnUsage{constraintCatalog, constraintSchema, constraintName,
                                                        tableCatalog, tableSchema, tableName,
                                                        columnName, ordinalPosition,
                                                        positionInUniqueConstraint,
                                                        referencedTableSchema, referencedTableName,
                                                        referencedColumnName});
        }

        resultSet->close();
        statement->close();

        return references;
    }

    /**
     * Returns all the mysql users on the server
     *
     * @param connector
     * @param schemas
     * @return
     */
    static std::vector<MysqlUser>
    getMYSQLUsers(MYSQLDatabaseConnector &connector) {
        std::vector<MysqlUser> users;

        std::string query = MYSQLStatements::GET_USERS;

        sql::Statement *statement = &connector.createStatement();
        sql::ResultSet *resultSet = statement->executeQuery(query);

        while (resultSet->next()) {

            std::string host = resultSet->getString(MysqlUserColumn::HOST);
            std::string user = resultSet->getString(MysqlUserColumn::USER);
            std::string select_priv = resultSet->getString(MysqlUserColumn::SELECT_PRIV);
            std::string insert_priv = resultSet->getString(MysqlUserColumn::INSERT_PRIV);
            std::string update_priv = resultSet->getString(MysqlUserColumn::UPDATE_PRIV);
            std::string delete_priv = resultSet->getString(MysqlUserColumn::DELETE_PRIV);
            std::string create_priv = resultSet->getString(MysqlUserColumn::CREATE_PRIV);
            std::string drop_priv = resultSet->getString(MysqlUserColumn::DROP_PRIV);
            std::string reload_priv = resultSet->getString(MysqlUserColumn::RELOAD_PRIV);
            std::string shutdown_priv = resultSet->getString(MysqlUserColumn::SHUTDOWN_PRIV);
            std::string process_priv = resultSet->getString(MysqlUserColumn::PROCESS_PRIV);
            std::string file_priv = resultSet->getString(MysqlUserColumn::FILE_PRIV);
            std::string grant_priv = resultSet->getString(MysqlUserColumn::GRANT_PRIV);
            std::string references_priv = resultSet->getString(MysqlUserColumn::REFERENCES_PRIV);
            std::string index_priv = resultSet->getString(MysqlUserColumn::INDEX_PRIV);
            std::string alter_priv = resultSet->getString(MysqlUserColumn::ALTER_PRIV);
            std::string show_db_priv = resultSet->getString(MysqlUserColumn::SHOW_DB_PRIV);
            std::string super_priv = resultSet->getString(MysqlUserColumn::SUPER_PRIV);
            std::string create_tmp_table_priv = resultSet->getString(MysqlUserColumn::CREATE_TMP_TABLE_PRIV);
            std::string lock_tables_priv = resultSet->getString(MysqlUserColumn::LOCK_TABLES_PRIV);
            std::string execute_priv = resultSet->getString(MysqlUserColumn::EXECUTE_PRIV);
            std::string repl_slave_priv = resultSet->getString(MysqlUserColumn::REPL_SLAVE_PRIV);
            std::string repl_client_priv = resultSet->getString(MysqlUserColumn::REPL_CLIENT_PRIV);
            std::string create_view_priv = resultSet->getString(MysqlUserColumn::CREATE_VIEW_PRIV);
            std::string show_view_priv = resultSet->getString(MysqlUserColumn::SHOW_VIEW_PRIV);
            std::string create_routine_priv = resultSet->getString(MysqlUserColumn::CREATE_ROUTINE_PRIV);
            std::string alter_routine_priv = resultSet->getString(MysqlUserColumn::ALTER_ROUTINE_PRIV);
            std::string create_user_priv = resultSet->getString(MysqlUserColumn::CREATE_USER_PRIV);
            std::string event_priv = resultSet->getString(MysqlUserColumn::EVENT_PRIV);
            std::string trigger_priv = resultSet->getString(MysqlUserColumn::TRIGGER_PRIV);
            std::string create_tablespace_priv = resultSet->getString(MysqlUserColumn::CREATE_TABLESPACE_PRIV);
            std::string ssl_type = resultSet->getString(MysqlUserColumn::SSL_TYPE);
            std::string ssl_cipher = resultSet->getString(MysqlUserColumn::SSL_CIPHER);
            std::string x509_issuer = resultSet->getString(MysqlUserColumn::X509_ISSUER);
            std::string x509_subject = resultSet->getString(MysqlUserColumn::X509_SUBJECT);
            std::string max_questions = resultSet->getString(MysqlUserColumn::MAX_QUESTIONS);
            std::string max_updates = resultSet->getString(MysqlUserColumn::MAX_UPDATES);
            std::string max_connections = resultSet->getString(MysqlUserColumn::MAX_CONNECTIONS);
            std::string max_user_connections = resultSet->getString(MysqlUserColumn::MAX_USER_CONNECTIONS);
            std::string plugin = resultSet->getString(MysqlUserColumn::PLUGIN);
            std::string authentication_string = resultSet->getString(MysqlUserColumn::AUTHENTICATION_STRING);
            std::string password_expired = resultSet->getString(MysqlUserColumn::PASSWORD_EXPIRED);
            std::string password_last_changed = resultSet->getString(MysqlUserColumn::PASSWORD_LAST_CHANGED);
            std::string password_lifetime = resultSet->getString(MysqlUserColumn::PASSWORD_LIFETIME);
            std::string account_locked = resultSet->getString(MysqlUserColumn::ACCOUNT_LOCKED);


            users.emplace_back(MysqlUser{host, user, select_priv,
                                         insert_priv, update_priv, delete_priv,
                                         create_priv, drop_priv, reload_priv,
                                         shutdown_priv, process_priv, file_priv,
                                         grant_priv, references_priv, index_priv,
                                         alter_priv, show_db_priv, super_priv,
                                         create_tmp_table_priv, lock_tables_priv,
                                         execute_priv, repl_slave_priv, repl_client_priv,
                                         create_view_priv, show_view_priv,
                                         create_routine_priv, alter_routine_priv,
                                         create_user_priv, event_priv, trigger_priv,
                                         create_tablespace_priv, ssl_type, ssl_cipher,
                                         x509_issuer, x509_subject, max_questions,
                                         max_updates, max_connections,
                                         max_user_connections, plugin,
                                         authentication_string, password_expired,
                                         password_last_changed, password_lifetime,
                                         account_locked});
        }

        resultSet->close();
        statement->close();

        return users;
    }
};


#endif //DBCRUDGEN_CPP_TRANSACTIONUTILS_H
