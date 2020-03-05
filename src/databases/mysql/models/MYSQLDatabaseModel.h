//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 8/5/17.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_MYSQLDATABASEMODEL_H
#define DBCRUDGEN_CPP_MYSQLDATABASEMODEL_H


#include <string>
#include <vector>
#include "../connectors/MYSQLDatabaseConnector.h"
#include "../symbols/MysqlTable.h"
#include "../queries/MysqlFullTablesColumns.h"
#include "../queries/MysqlCreateTableColumns.h"
#include "../columns/MysqlUserColumn.h"
#include "../queries/MYSQLStatements.h"
#include "../../../orm/utils/StringUtils.h"
#include "../../sql/parsers/Tags.h"
#include "../../oracle/parsers/MysqlTags.h"
#include "../objects/MysqlRelationTypes.h"
#include "../columns/MysqlTableColumnColumns.h"
#include "../columns/MYSQLTableColumn.h"
#include "../parsers/MYSQLLangParser.h"
#include "MysqlUser.h"

//
// MYSQLDatabaseModel
// //
class MYSQLDatabaseModel {
private:
    MYSQLDatabaseConnector &connector;


public:
    explicit MYSQLDatabaseModel(MYSQLDatabaseConnector &connector) : connector(connector) {}

    /**
   * Returns all the mysql users on the server
   *
   * @param connector
   * @param schemas
   * @return
   */
    std::vector<MysqlUser> getMYSQLUsers() {
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

    /**
   * Get the list of all databases
   *
   * @param connectionParams
   * @return
   */
    std::vector<std::string> getSchemas() {
        std::vector<std::string> schemas;
        std::string query = MYSQLStatements::SHOW_SCHEMAS_QUERY;
        sql::Statement *statement = &connector.createStatement();
        sql::ResultSet *resultSet = statement->executeQuery(query);

        while (resultSet->next()) {
            schemas.emplace_back(resultSet->getString(1));
        }
        resultSet->close();
        statement->close();
        return schemas;
    }

    /**
     * Get all the table names in the schema
     * @param schemas
     * @return
     */
    std::vector<std::string> getTableNames(std::string &schemas) {
        std::vector<std::string> tableNames;
        std::string showSchemasTablesQuery = MYSQLStatements::SCHEMAS_TABLES_QUERY;
        std::string query = StringUtils::parseTemplate(showSchemasTablesQuery, Tags::SCHEMA, schemas);
        sql::Statement *statement = &connector.createStatement();
        sql::ResultSet *resultSet = statement->executeQuery(query);

        while (resultSet->next()) {
            tableNames.emplace_back(resultSet->getString(1));
        }
        resultSet->close();
        statement->close();


        return tableNames;
    }

    /**
     * Get all the tables in the schema
     * @param schemas
     * @return
     */
    std::vector<MysqlTable> getTables(std::string &schemas) {

        std::vector<MysqlTable> tables;
        std::string showSchemasTablesQuery = MYSQLStatements::SCHEMAS_FULL_TABLES_QUERY;
        std::string query = StringUtils::parseTemplate(showSchemasTablesQuery, Tags::SCHEMA, schemas);

        sql::Statement *statement = &connector.createStatement();
        sql::ResultSet *resultSet = statement->executeQuery(query);

        std::string tableName = MysqlFullTablesColumns::TABLE_NAME;
        std::string tableNameColumnName = StringUtils::parseTemplate(tableName, Tags::SCHEMA, schemas);

        while (resultSet->next()) {
            std::string name = resultSet->getString(tableNameColumnName);
            std::string type = resultSet->getString(MysqlFullTablesColumns::TABLE_TYPE);
            tables.emplace_back(MysqlTable{name, type});
        }
        resultSet->close();
        statement->close();


        return tables;
    }

    /**
     * Get all the views in the schema
     * @param schemas
     * @return
     */
    std::vector<std::string> getViewNames(std::string &schemas) {
        std::vector<std::string> viewNames;
        std::string showSchemasTablesQuery = MYSQLStatements::SCHEMAS_VIEWS_QUERY;
        std::string query = StringUtils::parseTemplate(showSchemasTablesQuery, Tags::SCHEMA, schemas);
        query = StringUtils::parseTemplate(showSchemasTablesQuery, MysqlTags::TABLE_TYPE_VIEW,
                                           MysqlRelationTypes::TABLE_TYPE_VIEW);
        sql::Statement *statement = &connector.createStatement();
        sql::ResultSet *resultSet = statement->executeQuery(query);

        while (resultSet->next()) {
            viewNames.emplace_back(resultSet->getString(1));
        }
        resultSet->close();
        statement->close();


        return viewNames;
    }

    /**
     * Get all the CREATE STATEMENTS for the database tables
     * @param schemas
     * @param tablesNames
     * @return
     */
    std::vector<std::string>
    getMYSQLDatabaseTablesCreateStatements(std::string &schemas, std::vector<std::string> tablesNames) {

        std::vector<std::string> tableCreateStatements;

        sql::Statement *statement = &connector.createStatement();

        for (const std::string &tableName : tablesNames) {

            std::string tablesCreateStatementQuery = MYSQLStatements::TABLES_CREATE_QUERY;
            std::string query = StringUtils::parseTemplate(tablesCreateStatementQuery, Tags::SCHEMAS, schemas);
            query = StringUtils::parseTemplate(tablesCreateStatementQuery, Tags::TABLE_NAME, tableName);

            sql::ResultSet *resultSet = statement->executeQuery(query);

            while (resultSet->next()) {
                tableCreateStatements.emplace_back(resultSet->getString(MysqlCreateTableColumns::CREATE_TABLE));
            }
            resultSet->close();
        }

        statement->close();
        return tableCreateStatements;
    }

    /**
     * Get all the CREATE STATEMENT for a database table
     * @param schemas
     * @param tablesNames
     * @return
     */
    static std::string
    getMYSQLDatabaseTableCreateStatement(MYSQLDatabaseConnector &connector, const std::string &schemas,
                                         const std::string &tableName) {

        sql::Statement *statement = &connector.createStatement();


        std::string tablesCreateStatementQuery = MYSQLStatements::TABLES_CREATE_QUERY;
        std::string query = StringUtils::parseTemplate(tablesCreateStatementQuery, Tags::SCHEMAS, schemas);
        query = StringUtils::parseTemplate(tablesCreateStatementQuery, Tags::TABLE_NAME, tableName);

        sql::ResultSet *resultSet = statement->executeQuery(query);
        resultSet->first();
        std::string createTable = resultSet->getString(MysqlCreateTableColumns::CREATE_TABLE);

        resultSet->close();
        statement->close();

        return createTable;
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
    getMYSQLTableColumns(MYSQLDatabaseConnector &connector, const std::string &schemas, std::string &tableName) {

        std::vector<MYSQLTableColumn> tableColumns;

        std::string absoluteTableName{MYSQLLangParser::toAbsolutePath(schemas, tableName)};
        std::string getTableColumnsQuery{MYSQLStatements::TABLE_COLUMNS_FULL};
        std::string query = StringUtils::parseTemplate(getTableColumnsQuery, Tags::TABLE_NAME, absoluteTableName);

        sql::Statement *statement = &connector.createStatement();
        sql::ResultSet *resultSet = statement->executeQuery(query);

        while (resultSet->next()) {
            std::string field = resultSet->getString(MysqlTableColumnColumns::FIELD);
            std::string type = resultSet->getString(MysqlTableColumnColumns::TYPE);
            std::string collation = resultSet->getString(MysqlTableColumnColumns::COLLATION);
            std::string allowNull = resultSet->getString(MysqlTableColumnColumns::ALLOW_NULL);
            std::string key = resultSet->getString(MysqlTableColumnColumns::KEY);
            std::string defaultValue = resultSet->getString(MysqlTableColumnColumns::DEFAULT_VALUE);
            std::string extra = resultSet->getString(MysqlTableColumnColumns::EXTRA);
            std::string privileges = resultSet->getString(MysqlTableColumnColumns::PRIVILEGES);
            std::string comment = resultSet->getString(MysqlTableColumnColumns::COMMENT);

            MYSQLTableColumn mysqlTable{field, type, collation, allowNull, key, defaultValue, extra, privileges,
                                        comment};
            
            tableColumns.push_back(mysqlTable);
        }
        resultSet->close();
        statement->close();

        return tableColumns;
    }
};


#endif //DBCRUDGEN_CPP_MYSQLDATABASEMODEL_H
