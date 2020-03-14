//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 8/5/17.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_MYSQLDATABASEDECOMPOSER_H
#define DBCRUDGEN_CPP_MYSQLDATABASEDECOMPOSER_H


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
#include "../schema/Schemata.h"
#include "../schema/Tables.h"
#include "../schema/Columns.h"
#include "../queries/MysqlQueries.h"

//
// MYSQLDatabaseDecomposer
// //
namespace dbcrudgen {
    namespace mysql {

        class MYSQLDatabaseDecomposer {

        private:
            MYSQLDatabaseConnector &connector;


        public:
            explicit MYSQLDatabaseDecomposer(MYSQLDatabaseConnector &connector) : connector(connector) {}

            /**
             * Returns the list of all schemas or databases in a MYSQL database server
             * @return
             */
            std::vector<Schemata> getSchemas() {
                std::vector<Schemata> schematas;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_SCHEMAS;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(sql::SQLString{query});

                while (resultSet->next()) {
                    std::string catalogName = resultSet->getString(Schemata::Columns::CATALOG_NAME::INDEX);
                    std::string schemaName = resultSet->getString(Schemata::Columns::SCHEMA_NAME::INDEX);
                    std::string defaultCharacterSetName = resultSet->getString(
                            Schemata::Columns::DEFAULT_CHARACTER_SET_NAME::INDEX);
                    std::string defaultCollationName = resultSet->getString(
                            Schemata::Columns::DEFAULT_COLLATION_NAME::INDEX);
                    std::string sqlPath = resultSet->getString(Schemata::Columns::SQL_PATH::INDEX);

                    const Schemata &schemata = Schemata{catalogName, schemaName, defaultCharacterSetName,
                                                        defaultCollationName,
                                                        sqlPath};
                    schematas.emplace_back(schemata);
                }

                resultSet->close();
                statement->close();

                return schematas;
            };

            /**
             * Get all the tables in a schema
             * @param schema
             * @return
             */
            std::vector<Tables> getSchemaTables(std::string &schema) {

                std::vector<Tables> tables;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_SCHEMA_TABLES;
                query = StringUtils::parseTemplate(query, MYSQLQueries::Tags::TABLE_SCHEMA, schema);

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(sql::SQLString{query});

                while (resultSet->next()) {
                    std::string table_catalog = resultSet->getString(Tables::TABLE_CATALOG::INDEX);
                    std::string table_schema = resultSet->getString(Tables::TABLE_SCHEMA::INDEX);
                    std::string table_name = resultSet->getString(Tables::TABLE_NAME::INDEX);
                    std::string table_type = resultSet->getString(Tables::TABLE_TYPE::INDEX);
                    std::string engine = resultSet->getString(Tables::ENGINE::INDEX);
                    long version = resultSet->getInt64(Tables::VERSION::INDEX);
                    std::string row_format = resultSet->getString(Tables::ROW_FORMAT::INDEX);
                    long table_rows = resultSet->getInt64(Tables::TABLE_ROWS::INDEX);
                    std::string avg_row_length = resultSet->getString(Tables::AVG_ROW_LENGTH::INDEX);
                    std::string data_length = resultSet->getString(Tables::DATA_LENGTH::INDEX);
                    std::string max_data_length = resultSet->getString(Tables::MAX_DATA_LENGTH::INDEX);
                    std::string index_length = resultSet->getString(Tables::INDEX_LENGTH::INDEX);
                    std::string data_free = resultSet->getString(Tables::DATA_FREE::INDEX);
                    std::string auto_increment = resultSet->getString(Tables::AUTO_INCREMENT::INDEX);
                    std::string create_time = resultSet->getString(Tables::CREATE_TIME::INDEX);
                    std::string update_time = resultSet->getString(Tables::UPDATE_TIME::INDEX);
                    std::string check_time = resultSet->getString(Tables::CHECK_TIME::INDEX);
                    std::string table_collation = resultSet->getString(Tables::TABLE_COLLATION::INDEX);
                    long checksum = resultSet->getInt64(Tables::CHECKSUM::INDEX);
                    std::string create_options = resultSet->getString(Tables::CREATE_OPTIONS::INDEX);
                    std::string table_comment = resultSet->getString(Tables::TABLE_COMMENT::INDEX);

                    Tables table{table_catalog, table_schema, table_name, table_type, engine, version,
                                 row_format, table_rows, avg_row_length, data_length, max_data_length,
                                 index_length, data_free, auto_increment, create_time, update_time, check_time,
                                 table_collation, checksum, create_options, table_comment};

                    tables.emplace_back(table);
                }

                resultSet->close();
                statement->close();

                return tables;
            }

            /**
             * Get all the table columns
             * @param schema_name
             * @param table_name
             * @return
             */
            std::vector<dbcrudgen::mysql::Columns> getTableColumns(std::string &schema_name, std::string &table_name) {
                std::vector<dbcrudgen::mysql::Columns> columns;


                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_SCHEMA_TABLE_COLUMNS;
                query = StringUtils::parseTemplate(query, MYSQLQueries::Tags::TABLE_SCHEMA, schema_name);
                query = StringUtils::parseTemplate(query, MYSQLQueries::Tags::TABLE_NAME, table_name);

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(sql::SQLString{query});

                while (resultSet->next()) {
                    std::string table_catalog = resultSet->getString(dbcrudgen::mysql::Columns::TABLE_CATALOG::INDEX);
                    std::string table_schema = resultSet->getString(dbcrudgen::mysql::Columns::TABLE_SCHEMA::INDEX);
                    table_name = resultSet->getString(dbcrudgen::mysql::Columns::TABLE_NAME::INDEX);
                    std::string column_name = resultSet->getString(dbcrudgen::mysql::Columns::COLUMN_NAME::INDEX);
                    long ordinal_position = resultSet->getInt64(dbcrudgen::mysql::Columns::ORDINAL_POSITION::INDEX);
                    std::string column_default = resultSet->getString(dbcrudgen::mysql::Columns::COLUMN_DEFAULT::INDEX);
                    std::string is_nullable = resultSet->getString(dbcrudgen::mysql::Columns::IS_NULLABLE::INDEX);
                    std::string data_type = resultSet->getString(dbcrudgen::mysql::Columns::DATA_TYPE::INDEX);
                    long character_maximum_length = resultSet->getInt64(
                            dbcrudgen::mysql::Columns::CHARACTER_MAXIMUM_LENGTH::INDEX);
                    long character_octet_length = resultSet->getInt64(
                            dbcrudgen::mysql::Columns::CHARACTER_OCTET_LENGTH::INDEX);
                    long numeric_precision = resultSet->getInt64(dbcrudgen::mysql::Columns::NUMERIC_PRECISION::INDEX);
                    long numeric_scale = resultSet->getInt64(dbcrudgen::mysql::Columns::NUMERIC_SCALE::INDEX);
                    long datetime_precision = resultSet->getInt64(dbcrudgen::mysql::Columns::DATETIME_PRECISION::INDEX);
                    std::string character_set_name = resultSet->getString(
                            dbcrudgen::mysql::Columns::CHARACTER_SET_NAME::INDEX);
                    std::string collation_name = resultSet->getString(dbcrudgen::mysql::Columns::COLLATION_NAME::INDEX);
                    std::string column_type = resultSet->getString(dbcrudgen::mysql::Columns::COLUMN_TYPE::INDEX);
                    std::string column_key = resultSet->getString(dbcrudgen::mysql::Columns::COLUMN_KEY::INDEX);
                    std::string extra = resultSet->getString(dbcrudgen::mysql::Columns::EXTRA::INDEX);
                    std::string privileges = resultSet->getString(dbcrudgen::mysql::Columns::PRIVILEGES::INDEX);
                    std::string column_comment = resultSet->getString(dbcrudgen::mysql::Columns::COLUMN_COMMENT::INDEX);
                    std::string generation_expression = resultSet->getString(
                            dbcrudgen::mysql::Columns::GENERATION_EXPRESSION::INDEX);

                    Columns column{table_catalog, table_schema, table_name, column_name, ordinal_position,
                                   column_default, is_nullable, data_type, character_maximum_length,
                                   character_octet_length, numeric_precision, numeric_scale, datetime_precision,
                                   character_set_name, collation_name, column_type, column_key, extra, privileges,
                                   column_comment, generation_expression};

                    columns.emplace_back(column);
                }

                resultSet->close();
                statement->close();

                return columns;
            }

            /**
             * Get Table Create Statement
             * @param schema
             * @param table
             * @return
             */
            std::string getTableCreateStatement(std::string &schema, std::string &table) {

                std::string create_table;

                const int table_index = 1;
                const int create_table_statement_index = 2;

                std::string query = MYSQLQueries::GET_TABLE_CREATE_STATEMENT;
                query = StringUtils::parseTemplate(query, MYSQLQueries::Tags::TABLE_SCHEMA, schema);
                query = StringUtils::parseTemplate(query, MYSQLQueries::Tags::TABLE_NAME, table);

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(sql::SQLString{query});

                if (resultSet->next()) {
                    create_table = resultSet->getString(create_table_statement_index);
                }

                resultSet->close();
                statement->close();

                return create_table;
            }
        };
    }
}


#endif //DBCRUDGEN_CPP_MYSQLDATABASEDECOMPOSER_H
