//
// Created by victor on 4/18/20.
//

#ifndef DBCRUDGEN_CPP_MYSQLDATABASEPREPAREDDECOMPOSER_H
#define DBCRUDGEN_CPP_MYSQLDATABASEPREPAREDDECOMPOSER_H


#include <string>
#include <vector>
#include "../connectors/MYSQLDatabaseConnector.h"
#include "../queries/MysqlFullTablesColumns.h"
#include "../queries/MysqlCreateTableColumns.h"
#include "../queries/MYSQLStatements.h"
#include "../../../orm/utils/StringUtils.h"
#include "../../sql/parsers/Tags.h"
#include "../objects/MysqlRelationTypes.h"
#include "../parsers/MYSQLLangParser.h"

#include "../scaffolding/queries/MysqlQueries.h"

// Information schema tables
#include "../scaffolding/entities/CharacterSets.h"
#include "../scaffolding/entities/Collations.h"
#include "../scaffolding/entities/CollationCharacterSetApplicability.h"
#include "../scaffolding/entities/Columns.h"
#include "../scaffolding/entities/ColumnPrivileges.h"
#include "../scaffolding/entities/Engines.h"
#include "../scaffolding/entities/Events.h"
#include "../scaffolding/entities/Files.h"
#include "../scaffolding/entities/GlobalStatus.h"
#include "../scaffolding/entities/GlobalVariables.h"
#include "../scaffolding/entities/KeyColumnUsage.h"
#include "../scaffolding/entities/OptimizerTrace.h"
#include "../scaffolding/entities/Parameters.h"
#include "../scaffolding/entities/Partitions.h"
#include "../scaffolding/entities/Plugins.h"
#include "../scaffolding/entities/ProcessList.h"
#include "../scaffolding/entities/Profiling.h"
#include "../scaffolding/entities/ReferentialConstraints.h"
#include "../scaffolding/entities/Routines.h"
#include "../scaffolding/entities/Schemata.h"
#include "../scaffolding/entities/SchemaPrivileges.h"
#include "../scaffolding/entities/SessionStatus.h"
#include "../scaffolding/entities/SessionVariables.h"
#include "../scaffolding/entities/Statistics.h"
#include "../scaffolding/entities/Tables.h"
#include "../scaffolding/entities/TableSpaces.h"
#include "../scaffolding/entities/TableConstraints.h"
#include "../scaffolding/entities/TablePrivileges.h"
#include "../scaffolding/entities/Triggers.h"
#include "../scaffolding/entities/UserPrivileges.h"
#include "../scaffolding/entities/Views.h"
#include "../scaffolding/entities/InnoDbLocks.h"
#include "../scaffolding/entities/InnoDbTrx.h"
#include "../scaffolding/entities/InnoDbSysDataFiles.h"
#include "../scaffolding/entities/InnoDbFtConfig.h"
#include "../scaffolding/entities/InnoDbSysVirtual.h"
#include "../scaffolding/entities/InnoDbCmp.h"
#include "../scaffolding/entities/InnoDbFtBeingDeleted.h"
#include "../scaffolding/entities/InnoDbCmpReset.h"
#include "../scaffolding/entities/InnoDbCmpPerIndex.h"
#include "../scaffolding/entities/InnoDbCmpMemReset.h"
#include "../scaffolding/entities/InnoDbFtDeleted.h"
#include "../scaffolding/entities/InnoDbBufferPageLRU.h"
#include "../scaffolding/entities/InnoDbLockWaits.h"
#include "../scaffolding/entities/InnoDbTempTableInfo.h"
#include "../scaffolding/entities/InnoDbSysIndexes.h"
#include "../scaffolding/entities/InnoDbSysTables.h"
#include "../scaffolding/entities/InnoDbSysFields.h"
#include "../scaffolding/entities/InnoDbCmpPerIndexReset.h"
#include "../scaffolding/entities/InnoDbBufferPage.h"
#include "../scaffolding/entities/InnoDbFtDefaultStopWord.h"
#include "../scaffolding/entities/InnoDbFtIndexTable.h"
#include "../scaffolding/entities/InnoDbFtIndexCache.h"
#include "../scaffolding/entities/InnoDbSysTableSpaces.h"
#include "../scaffolding/entities/InnoDbMetrics.h"
#include "../scaffolding/entities/InnoDbSysForeignCols.h"
#include "../scaffolding/entities/InnoDbCmpMem.h"
#include "../scaffolding/entities/InnoDbBufferPoolStats.h"
#include "../scaffolding/entities/InnoDbSysColumns.h"
#include "../scaffolding/entities/InnoDbSysForeign.h"
#include "../scaffolding/entities/InnoDbSysTableStats.h"

//mysql tables
#include "../scaffolding/entities/ColumnsPriv.h"
#include "../scaffolding/entities/Db.h"
#include "../scaffolding/entities/EngineCost.h"
#include "../scaffolding/entities/Event.h"
#include "../scaffolding/entities/Func.h"
#include "../scaffolding/entities/GeneralLog.h"
#include "../scaffolding/entities/GtidExecuted.h"
#include "../scaffolding/entities/HelpCategory.h"
#include "../scaffolding/entities/HelpKeyword.h"
#include "../scaffolding/entities/HelpRelation.h"
#include "../scaffolding/entities/HelpTopic.h"
#include "../scaffolding/entities/InnoDbIndexStats.h"
#include "../scaffolding/entities/InnoDbTableStats.h"
#include "../scaffolding/entities/NdbBinlogIndex.h"
#include "../scaffolding/entities/Plugin.h"
#include "../scaffolding/entities/Proc.h"
#include "../scaffolding/entities/ProcsPriv.h"
#include "../scaffolding/entities/ProxiesPriv.h"
#include "../scaffolding/entities/ServerCost.h"
#include "../scaffolding/entities/Servers.h"
#include "../scaffolding/entities/SlaveMasterInfo.h"
#include "../scaffolding/entities/SlaveRelayLogInfo.h"
#include "../scaffolding/entities/SlaveWorkerInfo.h"
#include "../scaffolding/entities/SlowLog.h"
#include "../scaffolding/entities/TablesPriv.h"
#include "../scaffolding/entities/TimeZone.h"
#include "../scaffolding/entities/TimeZoneLeapSecond.h"
#include "../scaffolding/entities/TimeZoneName.h"
#include "../scaffolding/entities/TimeZoneTransition.h"
#include "../scaffolding/entities/TimeZoneTransitionType.h"
#include "../scaffolding/entities/User.h"
#include "../scaffolding/entities/ResourceGroups.h"

//
// MYSQLDatabaseDecomposer
// //
namespace dbcrudgen {
    namespace db {
        namespace mysql {

            class MYSQLDatabasePreparedDecomposer : public MYSQLDatabaseDecomposer {

            private:
                MYSQLDatabaseConnector &connector;


            public:
                explicit MYSQLDatabasePreparedDecomposer(MYSQLDatabaseConnector &connector)
                        : MYSQLDatabaseDecomposer{connector}, connector(connector) {}


                std::vector<Tables> getSchemaTableType(const std::string &schema, const std::string &type) {

                    std::vector<Tables> tables;

                    std::string query = mysql::MYSQLQueries::Prepared::GET_SCHEMA_TABLE_TYPE;
                    query = StringUtils::replace(query, mysql::MYSQLQueries::Tags::TABLE_SCHEMA, schema);
                    query = StringUtils::replace(query, mysql::MYSQLQueries::Tags::TABLE_TYPE, type);

                    sql::Statement *statement = &connector.createStatement();
                    sql::ResultSet *resultSet = statement->executeQuery(sql::SQLString{query});

                    while (resultSet->next()) {

                        std::string tableCatalog = resultSet->getString(Tables::COLUMNS::TABLE_CATALOG::INDEX);
                        std::string tableSchema = resultSet->getString(Tables::COLUMNS::TABLE_SCHEMA::INDEX);
                        std::string tableName = resultSet->getString(Tables::COLUMNS::TABLE_NAME::INDEX);
                        std::string tableType = resultSet->getString(Tables::COLUMNS::TABLE_TYPE::INDEX);
                        std::string engine = resultSet->getString(Tables::COLUMNS::ENGINE::INDEX);
                        long version = resultSet->getInt(Tables::COLUMNS::VERSION::INDEX);
                        std::string rowFormat = resultSet->getString(Tables::COLUMNS::ROW_FORMAT::INDEX);
                        long tableRows = resultSet->getInt(Tables::COLUMNS::TABLE_ROWS::INDEX);
                        long avgRowLength = resultSet->getInt(Tables::COLUMNS::AVG_ROW_LENGTH::INDEX);
                        long dataLength = resultSet->getInt(Tables::COLUMNS::DATA_LENGTH::INDEX);
                        long maxDataLength = resultSet->getInt(Tables::COLUMNS::MAX_DATA_LENGTH::INDEX);
                        long indexLength = resultSet->getInt(Tables::COLUMNS::INDEX_LENGTH::INDEX);
                        long dataFree = resultSet->getInt(Tables::COLUMNS::DATA_FREE::INDEX);
                        long autoIncrement = resultSet->getInt(Tables::COLUMNS::AUTO_INCREMENT::INDEX);
                        std::string createTime = resultSet->getString(Tables::COLUMNS::CREATE_TIME::INDEX);
                        std::string updateTime = resultSet->getString(Tables::COLUMNS::UPDATE_TIME::INDEX);
                        std::string checkTime = resultSet->getString(Tables::COLUMNS::CHECK_TIME::INDEX);
                        std::string tableCollation = resultSet->getString(Tables::COLUMNS::TABLE_COLLATION::INDEX);
                        long checksum = resultSet->getInt(Tables::COLUMNS::CHECKSUM::INDEX);
                        std::string createOptions = resultSet->getString(Tables::COLUMNS::CREATE_OPTIONS::INDEX);
                        std::string tableComment = resultSet->getString(Tables::COLUMNS::TABLE_COMMENT::INDEX);

                        Tables table{tableCatalog, tableSchema, tableName, tableType, engine, version, rowFormat,
                                     tableRows,
                                     avgRowLength, dataLength, maxDataLength, indexLength, dataFree, autoIncrement,
                                     createTime, updateTime, checkTime, tableCollation, checksum, createOptions,
                                     tableComment};

                        tables.emplace_back(table);
                    }

                    resultSet->close();
                    statement->close();

                    return tables;
                }

                std::vector<Tables> getSchemaTables(const std::string &schema) {

                    std::vector<Tables> tables;

                    std::string query = mysql::MYSQLQueries::Prepared::GET_SCHEMA_TABLES;
                    query = StringUtils::replace(query, mysql::MYSQLQueries::Tags::TABLE_SCHEMA, schema);

                    sql::Statement *statement = &connector.createStatement();
                    sql::ResultSet *resultSet = statement->executeQuery(sql::SQLString{query});

                    while (resultSet->next()) {

                        std::string tableCatalog = resultSet->getString(Tables::COLUMNS::TABLE_CATALOG::INDEX);
                        std::string tableSchema = resultSet->getString(Tables::COLUMNS::TABLE_SCHEMA::INDEX);
                        std::string tableName = resultSet->getString(Tables::COLUMNS::TABLE_NAME::INDEX);
                        std::string tableType = resultSet->getString(Tables::COLUMNS::TABLE_TYPE::INDEX);
                        std::string engine = resultSet->getString(Tables::COLUMNS::ENGINE::INDEX);
                        long version = resultSet->getInt(Tables::COLUMNS::VERSION::INDEX);
                        std::string rowFormat = resultSet->getString(Tables::COLUMNS::ROW_FORMAT::INDEX);
                        long tableRows = resultSet->getInt(Tables::COLUMNS::TABLE_ROWS::INDEX);
                        long avgRowLength = resultSet->getInt(Tables::COLUMNS::AVG_ROW_LENGTH::INDEX);
                        long dataLength = resultSet->getInt(Tables::COLUMNS::DATA_LENGTH::INDEX);
                        long maxDataLength = resultSet->getInt(Tables::COLUMNS::MAX_DATA_LENGTH::INDEX);
                        long indexLength = resultSet->getInt(Tables::COLUMNS::INDEX_LENGTH::INDEX);
                        long dataFree = resultSet->getInt(Tables::COLUMNS::DATA_FREE::INDEX);
                        long autoIncrement = resultSet->getInt(Tables::COLUMNS::AUTO_INCREMENT::INDEX);
                        std::string createTime = resultSet->getString(Tables::COLUMNS::CREATE_TIME::INDEX);
                        std::string updateTime = resultSet->getString(Tables::COLUMNS::UPDATE_TIME::INDEX);
                        std::string checkTime = resultSet->getString(Tables::COLUMNS::CHECK_TIME::INDEX);
                        std::string tableCollation = resultSet->getString(Tables::COLUMNS::TABLE_COLLATION::INDEX);
                        long checksum = resultSet->getInt(Tables::COLUMNS::CHECKSUM::INDEX);
                        std::string createOptions = resultSet->getString(Tables::COLUMNS::CREATE_OPTIONS::INDEX);
                        std::string tableComment = resultSet->getString(Tables::COLUMNS::TABLE_COMMENT::INDEX);

                        Tables table{tableCatalog, tableSchema, tableName, tableType, engine, version, rowFormat,
                                     tableRows,
                                     avgRowLength, dataLength, maxDataLength, indexLength, dataFree, autoIncrement,
                                     createTime, updateTime, checkTime, tableCollation, checksum, createOptions,
                                     tableComment};

                        tables.emplace_back(table);
                    }

                    resultSet->close();
                    statement->close();

                    return tables;
                }

                /**
                 * Get Schema Views
                 * @param schema
                 * @return
                 */
                std::vector<Tables> getSchemaViews(const std::string &schema) {

                    std::vector<Tables> tables;

                    std::string query = mysql::MYSQLQueries::Prepared::GET_SCHEMA_VIEWS;
                    query = StringUtils::replace(query, mysql::MYSQLQueries::Tags::TABLE_SCHEMA, schema);

                    sql::Statement *statement = &connector.createStatement();
                    sql::ResultSet *resultSet = statement->executeQuery(sql::SQLString{query});

                    while (resultSet->next()) {

                        std::string tableCatalog = resultSet->getString(Tables::COLUMNS::TABLE_CATALOG::INDEX);
                        std::string tableSchema = resultSet->getString(Tables::COLUMNS::TABLE_SCHEMA::INDEX);
                        std::string tableName = resultSet->getString(Tables::COLUMNS::TABLE_NAME::INDEX);
                        std::string tableType = resultSet->getString(Tables::COLUMNS::TABLE_TYPE::INDEX);
                        std::string engine = resultSet->getString(Tables::COLUMNS::ENGINE::INDEX);
                        long version = resultSet->getInt(Tables::COLUMNS::VERSION::INDEX);
                        std::string rowFormat = resultSet->getString(Tables::COLUMNS::ROW_FORMAT::INDEX);
                        long tableRows = resultSet->getInt(Tables::COLUMNS::TABLE_ROWS::INDEX);
                        long avgRowLength = resultSet->getInt(Tables::COLUMNS::AVG_ROW_LENGTH::INDEX);
                        long dataLength = resultSet->getInt(Tables::COLUMNS::DATA_LENGTH::INDEX);
                        long maxDataLength = resultSet->getInt(Tables::COLUMNS::MAX_DATA_LENGTH::INDEX);
                        long indexLength = resultSet->getInt(Tables::COLUMNS::INDEX_LENGTH::INDEX);
                        long dataFree = resultSet->getInt(Tables::COLUMNS::DATA_FREE::INDEX);
                        long autoIncrement = resultSet->getInt(Tables::COLUMNS::AUTO_INCREMENT::INDEX);
                        std::string createTime = resultSet->getString(Tables::COLUMNS::CREATE_TIME::INDEX);
                        std::string updateTime = resultSet->getString(Tables::COLUMNS::UPDATE_TIME::INDEX);
                        std::string checkTime = resultSet->getString(Tables::COLUMNS::CHECK_TIME::INDEX);
                        std::string tableCollation = resultSet->getString(Tables::COLUMNS::TABLE_COLLATION::INDEX);
                        long checksum = resultSet->getInt(Tables::COLUMNS::CHECKSUM::INDEX);
                        std::string createOptions = resultSet->getString(Tables::COLUMNS::CREATE_OPTIONS::INDEX);
                        std::string tableComment = resultSet->getString(Tables::COLUMNS::TABLE_COMMENT::INDEX);

                        Tables table{tableCatalog, tableSchema, tableName, tableType, engine, version, rowFormat,
                                     tableRows,
                                     avgRowLength, dataLength, maxDataLength, indexLength, dataFree, autoIncrement,
                                     createTime, updateTime, checkTime, tableCollation, checksum, createOptions,
                                     tableComment};

                        tables.emplace_back(table);
                    }

                    resultSet->close();
                    statement->close();

                    return tables;
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

                    std::string query = mysql::MYSQLQueries::Prepared::GET_TABLE_CREATE_STATEMENT;
                    query = StringUtils::replace(query, mysql::MYSQLQueries::Tags::TABLE_SCHEMA, schema);
                    query = StringUtils::replace(query, mysql::MYSQLQueries::Tags::TABLE_NAME, table);

                    sql::Statement *statement = &connector.createStatement();
                    sql::ResultSet *resultSet = statement->executeQuery(sql::SQLString{query});

                    if (resultSet->next()) {
                        create_table = resultSet->getString(create_table_statement_index);
                    }

                    resultSet->close();
                    statement->close();

                    return create_table;
                }

                /**
                * Get all the table columns
                * @param schema_name
                * @param table_name
                * @return
                */
                std::vector<mysql::Columns>
                getColumns(const std::string &schema_name, const std::string &tableName) {

                    std::vector<mysql::Columns> columns;

                    std::string query = ::dbcrudgen::db::mysql::MYSQLQueries::Prepared::GET_SCHEMA_TABLE_COLUMNS;
                    query = StringUtils::replace(query, MYSQLQueries::Tags::TABLE_SCHEMA, schema_name);
                    query = StringUtils::replace(query, MYSQLQueries::Tags::TABLE_NAME, tableName);

                    sql::Statement *statement = &connector.createStatement();
                    sql::ResultSet *resultSet = statement->executeQuery(sql::SQLString{query});

                    while (resultSet->next()) {
                        std::string table_catalog = resultSet->getString(
                                mysql::Columns::COLUMNS::TABLE_CATALOG::INDEX);
                        std::string table_schema = resultSet->getString(
                                mysql::Columns::COLUMNS::TABLE_SCHEMA::INDEX);
                        std::string table_name = resultSet->getString(mysql::Columns::COLUMNS::TABLE_NAME::INDEX);
                        std::string column_name = resultSet->getString(
                                mysql::Columns::COLUMNS::COLUMNS::COLUMN_NAME::INDEX);
                        long ordinal_position = resultSet->getInt64(
                                mysql::Columns::COLUMNS::ORDINAL_POSITION::INDEX);
                        std::string column_default = resultSet->getString(
                                mysql::Columns::COLUMNS::COLUMN_DEFAULT::INDEX);
                        std::string is_nullable = resultSet->getString(
                                mysql::Columns::COLUMNS::IS_NULLABLE::INDEX);
                        std::string data_type = resultSet->getString(mysql::Columns::COLUMNS::DATA_TYPE::INDEX);
                        long character_maximum_length = resultSet->getInt64(
                                mysql::Columns::COLUMNS::CHARACTER_MAXIMUM_LENGTH::INDEX);
                        long character_octet_length = resultSet->getInt64(
                                mysql::Columns::COLUMNS::CHARACTER_OCTET_LENGTH::INDEX);
                        long numeric_precision = resultSet->getInt64(
                                mysql::Columns::COLUMNS::NUMERIC_PRECISION::INDEX);
                        long numeric_scale = resultSet->getInt64(mysql::Columns::COLUMNS::NUMERIC_SCALE::INDEX);
                        long datetime_precision = resultSet->getInt64(
                                mysql::Columns::COLUMNS::DATETIME_PRECISION::INDEX);
                        std::string character_set_name = resultSet->getString(
                                mysql::Columns::COLUMNS::CHARACTER_SET_NAME::INDEX);
                        std::string collation_name = resultSet->getString(
                                mysql::Columns::COLUMNS::COLLATION_NAME::INDEX);
                        std::string column_type = resultSet->getString(
                                mysql::Columns::COLUMNS::COLUMN_TYPE::INDEX);
                        std::string column_key = resultSet->getString(
                                mysql::Columns::COLUMNS::COLUMN_KEY::INDEX);
                        std::string extra = resultSet->getString(mysql::Columns::COLUMNS::EXTRA::INDEX);
                        std::string privileges = resultSet->getString(
                                mysql::Columns::COLUMNS::PRIVILEGES::INDEX);
                        std::string column_comment = resultSet->getString(
                                mysql::Columns::COLUMNS::COLUMN_COMMENT::INDEX);
                        std::string generation_expression = resultSet->getString(
                                mysql::Columns::COLUMNS::GENERATION_EXPRESSION::INDEX);

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
                 * Get all the columns in the provided table in the provided schema
                 * @param schema_name
                 * @param tableName
                 * @param columnName
                 * @return
                 */
                mysql::Columns
                getColumn(const std::string &schema_name, const std::string &tableName, const std::string &columnName) {


                    std::string query = ::dbcrudgen::db::mysql::MYSQLQueries::Prepared::GET_SCHEMA_TABLE_COLUMN;
                    query = StringUtils::replace(query, MYSQLQueries::Tags::TABLE_SCHEMA, schema_name);
                    query = StringUtils::replace(query, MYSQLQueries::Tags::TABLE_NAME, tableName);
                    query = StringUtils::replace(query, MYSQLQueries::Tags::COLUMN_NAME, columnName);

                    sql::Statement *statement = &connector.createStatement();
                    sql::ResultSet *resultSet = statement->executeQuery(sql::SQLString{query});

                    resultSet->first();

                    std::string table_catalog = resultSet->getString(mysql::Columns::COLUMNS::TABLE_CATALOG::INDEX);
                    std::string table_schema = resultSet->getString(mysql::Columns::COLUMNS::TABLE_SCHEMA::INDEX);
                    std::string table_name = resultSet->getString(mysql::Columns::COLUMNS::TABLE_NAME::INDEX);
                    std::string column_name = resultSet->getString(
                            mysql::Columns::COLUMNS::COLUMNS::COLUMN_NAME::INDEX);
                    long ordinal_position = resultSet->getInt64(mysql::Columns::COLUMNS::ORDINAL_POSITION::INDEX);
                    std::string column_default = resultSet->getString(mysql::Columns::COLUMNS::COLUMN_DEFAULT::INDEX);
                    std::string is_nullable = resultSet->getString(mysql::Columns::COLUMNS::IS_NULLABLE::INDEX);
                    std::string data_type = resultSet->getString(mysql::Columns::COLUMNS::DATA_TYPE::INDEX);
                    long character_maximum_length = resultSet->getInt64(
                            mysql::Columns::COLUMNS::CHARACTER_MAXIMUM_LENGTH::INDEX);
                    long character_octet_length = resultSet->getInt64(
                            mysql::Columns::COLUMNS::CHARACTER_OCTET_LENGTH::INDEX);
                    long numeric_precision = resultSet->getInt64(mysql::Columns::COLUMNS::NUMERIC_PRECISION::INDEX);
                    long numeric_scale = resultSet->getInt64(mysql::Columns::COLUMNS::NUMERIC_SCALE::INDEX);
                    long datetime_precision = resultSet->getInt64(mysql::Columns::COLUMNS::DATETIME_PRECISION::INDEX);
                    std::string character_set_name = resultSet->getString(
                            mysql::Columns::COLUMNS::CHARACTER_SET_NAME::INDEX);
                    std::string collation_name = resultSet->getString(mysql::Columns::COLUMNS::COLLATION_NAME::INDEX);
                    std::string column_type = resultSet->getString(mysql::Columns::COLUMNS::COLUMN_TYPE::INDEX);
                    std::string column_key = resultSet->getString(mysql::Columns::COLUMNS::COLUMN_KEY::INDEX);
                    std::string extra = resultSet->getString(mysql::Columns::COLUMNS::EXTRA::INDEX);
                    std::string privileges = resultSet->getString(mysql::Columns::COLUMNS::PRIVILEGES::INDEX);
                    std::string column_comment = resultSet->getString(mysql::Columns::COLUMNS::COLUMN_COMMENT::INDEX);
                    std::string generation_expression = resultSet->getString(
                            mysql::Columns::COLUMNS::GENERATION_EXPRESSION::INDEX);

                    mysql::Columns column{table_catalog, table_schema, table_name, column_name, ordinal_position,
                                          column_default, is_nullable, data_type, character_maximum_length,
                                          character_octet_length, numeric_precision, numeric_scale, datetime_precision,
                                          character_set_name, collation_name, column_type, column_key, extra,
                                          privileges, column_comment, generation_expression};


                    resultSet->close();
                    statement->close();

                    return column;
                }

                /**
                 * Get all the keys in the provided schema
                 * @param schema_name
                 * @return
                 */
                std::vector<Statistics>
                getSchemaKeyColumns(const std::string &schema_name) {

                    std::vector<Statistics> statistics;

                    std::string query = dbcrudgen::db::mysql::MYSQLQueries::Prepared::GET_SCHEMA_KEYS;

                    query = StringUtils::replace(query, "${TABLE_SCHEMA}", schema_name);

                    sql::Statement *statement = &connector.createStatement();
                    sql::ResultSet *resultSet = statement->executeQuery(query);

                    while (resultSet->next()) {

                        std::string tableCatalog = resultSet->getString(Statistics::COLUMNS::TABLE_CATALOG::INDEX);
                        std::string tableSchema = resultSet->getString(Statistics::COLUMNS::TABLE_SCHEMA::INDEX);
                        std::string tableName = resultSet->getString(Statistics::COLUMNS::TABLE_NAME::INDEX);
                        long nonUnique = resultSet->getInt(Statistics::COLUMNS::NON_UNIQUE::INDEX);
                        std::string indexSchema = resultSet->getString(Statistics::COLUMNS::INDEX_SCHEMA::INDEX);
                        std::string indexName = resultSet->getString(Statistics::COLUMNS::INDEX_NAME::INDEX);
                        long seqInIndex = resultSet->getInt(Statistics::COLUMNS::SEQ_IN_INDEX::INDEX);
                        std::string columnName = resultSet->getString(Statistics::COLUMNS::COLUMN_NAME::INDEX);
                        std::string collation = resultSet->getString(Statistics::COLUMNS::COLLATION::INDEX);
                        long cardinality = resultSet->getInt(Statistics::COLUMNS::CARDINALITY::INDEX);
                        long subPart = resultSet->getInt(Statistics::COLUMNS::SUB_PART::INDEX);
                        std::string packed = resultSet->getString(Statistics::COLUMNS::PACKED::INDEX);
                        std::string nullable = resultSet->getString(Statistics::COLUMNS::NULLABLE::INDEX);
                        std::string indexType = resultSet->getString(Statistics::COLUMNS::INDEX_TYPE::INDEX);
                        std::string comment = resultSet->getString(Statistics::COLUMNS::COMMENT::INDEX);
                        std::string indexComment = resultSet->getString(Statistics::COLUMNS::INDEX_COMMENT::INDEX);

                        statistics.emplace_back(
                                Statistics{tableCatalog, tableSchema, tableName, nonUnique, indexSchema, indexName,
                                           seqInIndex, columnName, collation, cardinality, subPart, packed, nullable,
                                           indexType, comment, indexComment});
                    }

                    resultSet->close();
                    statement->close();

                    return statistics;
                }

                /**
                 * Get all the key/indexes in the provided table
                 * @param schema_name
                 * @param table_name
                 * @return
                 */
                std::vector<Statistics>
                getTableKeyColumns(const std::string &schema_name, const std::string &table_name) {

                    std::vector<Statistics> statistics;

                    std::string query = dbcrudgen::db::mysql::MYSQLQueries::Prepared::GET_TABLE_KEY_COLUMNS;

                    query = StringUtils::replace(query, "${TABLE_SCHEMA}", schema_name);
                    query = StringUtils::replace(query, "${TABLE_NAME}", table_name);

                    sql::Statement *statement = &connector.createStatement();
                    sql::ResultSet *resultSet = statement->executeQuery(query);

                    while (resultSet->next()) {

                        std::string tableCatalog = resultSet->getString(Statistics::COLUMNS::TABLE_CATALOG::INDEX);
                        std::string tableSchema = resultSet->getString(Statistics::COLUMNS::TABLE_SCHEMA::INDEX);
                        std::string tableName = resultSet->getString(Statistics::COLUMNS::TABLE_NAME::INDEX);
                        long nonUnique = resultSet->getInt(Statistics::COLUMNS::NON_UNIQUE::INDEX);
                        std::string indexSchema = resultSet->getString(Statistics::COLUMNS::INDEX_SCHEMA::INDEX);
                        std::string indexName = resultSet->getString(Statistics::COLUMNS::INDEX_NAME::INDEX);
                        long seqInIndex = resultSet->getInt(Statistics::COLUMNS::SEQ_IN_INDEX::INDEX);
                        std::string columnName = resultSet->getString(Statistics::COLUMNS::COLUMN_NAME::INDEX);
                        std::string collation = resultSet->getString(Statistics::COLUMNS::COLLATION::INDEX);
                        long cardinality = resultSet->getInt(Statistics::COLUMNS::CARDINALITY::INDEX);
                        long subPart = resultSet->getInt(Statistics::COLUMNS::SUB_PART::INDEX);
                        std::string packed = resultSet->getString(Statistics::COLUMNS::PACKED::INDEX);
                        std::string nullable = resultSet->getString(Statistics::COLUMNS::NULLABLE::INDEX);
                        std::string indexType = resultSet->getString(Statistics::COLUMNS::INDEX_TYPE::INDEX);
                        std::string comment = resultSet->getString(Statistics::COLUMNS::COMMENT::INDEX);
                        std::string indexComment = resultSet->getString(Statistics::COLUMNS::INDEX_COMMENT::INDEX);

                        statistics.emplace_back(
                                Statistics{tableCatalog, tableSchema, tableName, nonUnique, indexSchema, indexName,
                                           seqInIndex, columnName, collation, cardinality, subPart, packed, nullable,
                                           indexType, comment, indexComment});
                    }

                    resultSet->close();
                    statement->close();

                    return statistics;
                }

                /**
                 * Get all the table primary keys
                 * @param schema_name
                 * @param table_name
                 * @return
                 */
                std::vector<Statistics>
                getTablePrimaryKeys(const std::string &schema_name, const std::string &table_name) {

                    std::vector<Statistics> statistics;

                    std::string query = dbcrudgen::db::mysql::MYSQLQueries::Prepared::GET_TABLE_PRIMARY_KEY_COLUMNS;

                    query = StringUtils::replace(query, "${TABLE_SCHEMA}", schema_name);
                    query = StringUtils::replace(query, "${TABLE_NAME}", table_name);

                    sql::Statement *statement = &connector.createStatement();
                    sql::ResultSet *resultSet = statement->executeQuery(query);

                    while (resultSet->next()) {

                        std::string tableCatalog = resultSet->getString(Statistics::COLUMNS::TABLE_CATALOG::INDEX);
                        std::string tableSchema = resultSet->getString(Statistics::COLUMNS::TABLE_SCHEMA::INDEX);
                        std::string tableName = resultSet->getString(Statistics::COLUMNS::TABLE_NAME::INDEX);
                        long nonUnique = resultSet->getInt(Statistics::COLUMNS::NON_UNIQUE::INDEX);
                        std::string indexSchema = resultSet->getString(Statistics::COLUMNS::INDEX_SCHEMA::INDEX);
                        std::string indexName = resultSet->getString(Statistics::COLUMNS::INDEX_NAME::INDEX);
                        long seqInIndex = resultSet->getInt(Statistics::COLUMNS::SEQ_IN_INDEX::INDEX);
                        std::string columnName = resultSet->getString(Statistics::COLUMNS::COLUMN_NAME::INDEX);
                        std::string collation = resultSet->getString(Statistics::COLUMNS::COLLATION::INDEX);
                        long cardinality = resultSet->getInt(Statistics::COLUMNS::CARDINALITY::INDEX);
                        long subPart = resultSet->getInt(Statistics::COLUMNS::SUB_PART::INDEX);
                        std::string packed = resultSet->getString(Statistics::COLUMNS::PACKED::INDEX);
                        std::string nullable = resultSet->getString(Statistics::COLUMNS::NULLABLE::INDEX);
                        std::string indexType = resultSet->getString(Statistics::COLUMNS::INDEX_TYPE::INDEX);
                        std::string comment = resultSet->getString(Statistics::COLUMNS::COMMENT::INDEX);
                        std::string indexComment = resultSet->getString(Statistics::COLUMNS::INDEX_COMMENT::INDEX);

                        statistics.emplace_back(
                                Statistics{tableCatalog, tableSchema, tableName, nonUnique, indexSchema, indexName,
                                           seqInIndex, columnName, collation, cardinality, subPart, packed, nullable,
                                           indexType, comment, indexComment});
                    }

                    resultSet->close();
                    statement->close();

                    return statistics;
                }

                /**
                 * Get all foreign keys for a table
                 *
                 * @param schema_name
                 * @param table_name
                 * @return
                 */
                std::vector<KeyColumnUsage>
                getTableForeignKeyColumns(const std::string &schema_name, const std::string &table_name) {
                    std::vector<KeyColumnUsage> keyColumnUsage;

                    std::string query = dbcrudgen::db::mysql::MYSQLQueries::Prepared::GET_TABLE_FOREIGN_KEYS;

                    query = StringUtils::replace(query, "${TABLE_SCHEMA}", schema_name);
                    query = StringUtils::replace(query, "${TABLE_NAME}", table_name);

                    sql::Statement *statement = &connector.createStatement();
                    sql::ResultSet *resultSet = statement->executeQuery(query);

                    while (resultSet->next()) {

                        std::string constraintCatalog = resultSet->getString(
                                KeyColumnUsage::COLUMNS::CONSTRAINT_CATALOG::INDEX);
                        std::string constraintSchema = resultSet->getString(
                                KeyColumnUsage::COLUMNS::CONSTRAINT_SCHEMA::INDEX);
                        std::string constraintName = resultSet->getString(
                                KeyColumnUsage::COLUMNS::CONSTRAINT_NAME::INDEX);
                        std::string tableCatalog = resultSet->getString(KeyColumnUsage::COLUMNS::TABLE_CATALOG::INDEX);
                        std::string tableSchema = resultSet->getString(KeyColumnUsage::COLUMNS::TABLE_SCHEMA::INDEX);
                        std::string tableName = resultSet->getString(KeyColumnUsage::COLUMNS::TABLE_NAME::INDEX);
                        std::string columnName = resultSet->getString(KeyColumnUsage::COLUMNS::COLUMN_NAME::INDEX);
                        long ordinalPosition = resultSet->getInt(KeyColumnUsage::COLUMNS::ORDINAL_POSITION::INDEX);
                        long positionInUniqueConstraint = resultSet->getInt(
                                KeyColumnUsage::COLUMNS::POSITION_IN_UNIQUE_CONSTRAINT::INDEX);
                        std::string referencedTableSchema = resultSet->getString(
                                KeyColumnUsage::COLUMNS::REFERENCED_TABLE_SCHEMA::INDEX);
                        std::string referencedTableName = resultSet->getString(
                                KeyColumnUsage::COLUMNS::REFERENCED_TABLE_NAME::INDEX);
                        std::string referencedColumnName = resultSet->getString(
                                KeyColumnUsage::COLUMNS::REFERENCED_COLUMN_NAME::INDEX);

                        keyColumnUsage.emplace_back(
                                KeyColumnUsage{constraintCatalog, constraintSchema, constraintName, tableCatalog,
                                               tableSchema, tableName, columnName, ordinalPosition,
                                               positionInUniqueConstraint, referencedTableSchema, referencedTableName,
                                               referencedColumnName});
                    }

                    resultSet->close();
                    statement->close();

                    return keyColumnUsage;
                }

                /**
                 * Get all events
                 *
                 * @param name
                 * @param schema
                 * @return
                 */
                std::vector<Events> getEvents(const std::string &name = "", const std::string &schema = "") {

                    std::vector<Events> events;

                    std::string query = dbcrudgen::db::mysql::MYSQLQueries::GET_EVENTS;

                    std::map<std::string, std::string> whereFilters;
                    whereFilters[Events::COLUMNS::EVENT_SCHEMA::NAME] = schema;
                    whereFilters[Events::COLUMNS::EVENT_NAME::NAME] = name;
                    query = appendWhereClauseFilters(query, whereFilters);


                    sql::Statement *statement = &connector.createStatement();
                    sql::ResultSet *resultSet = statement->executeQuery(query);

                    while (resultSet->next()) {

                        std::string eventCatalog = resultSet->getString(Events::COLUMNS::EVENT_CATALOG::INDEX);
                        std::string eventSchema = resultSet->getString(Events::COLUMNS::EVENT_SCHEMA::INDEX);
                        std::string eventName = resultSet->getString(Events::COLUMNS::EVENT_NAME::INDEX);
                        std::string definer = resultSet->getString(Events::COLUMNS::DEFINER::INDEX);
                        std::string timeZone = resultSet->getString(Events::COLUMNS::TIME_ZONE::INDEX);
                        std::string eventBody = resultSet->getString(Events::COLUMNS::EVENT_BODY::INDEX);
                        std::string eventDefinition = resultSet->getString(Events::COLUMNS::EVENT_DEFINITION::INDEX);
                        std::string eventType = resultSet->getString(Events::COLUMNS::EVENT_TYPE::INDEX);
                        std::string executeAt = resultSet->getString(Events::COLUMNS::EXECUTE_AT::INDEX);
                        std::string intervalValue = resultSet->getString(Events::COLUMNS::INTERVAL_VALUE::INDEX);
                        std::string intervalField = resultSet->getString(Events::COLUMNS::INTERVAL_FIELD::INDEX);
                        std::string sqlMode = resultSet->getString(Events::COLUMNS::SQL_MODE::INDEX);
                        std::string starts = resultSet->getString(Events::COLUMNS::STARTS::INDEX);
                        std::string ends = resultSet->getString(Events::COLUMNS::ENDS::INDEX);
                        std::string status = resultSet->getString(Events::COLUMNS::STATUS::INDEX);
                        std::string onCompletion = resultSet->getString(Events::COLUMNS::ON_COMPLETION::INDEX);
                        std::string created = resultSet->getString(Events::COLUMNS::CREATED::INDEX);
                        std::string lastAltered = resultSet->getString(Events::COLUMNS::LAST_ALTERED::INDEX);
                        std::string lastExecuted = resultSet->getString(Events::COLUMNS::LAST_EXECUTED::INDEX);
                        std::string eventComment = resultSet->getString(Events::COLUMNS::EVENT_COMMENT::INDEX);
                        long originator = resultSet->getInt(Events::COLUMNS::ORIGINATOR::INDEX);
                        std::string characterSetClient = resultSet->getString(
                                Events::COLUMNS::CHARACTER_SET_CLIENT::INDEX);
                        std::string collationConnection = resultSet->getString(
                                Events::COLUMNS::COLLATION_CONNECTION::INDEX);
                        std::string databaseCollation = resultSet->getString(
                                Events::COLUMNS::DATABASE_COLLATION::INDEX);

                        events.emplace_back(
                                Events{eventCatalog, eventSchema, eventName, definer, timeZone, eventBody,
                                       eventDefinition,
                                       eventType, executeAt, intervalValue, intervalField, sqlMode, starts, ends,
                                       status,
                                       onCompletion, created, lastAltered, lastExecuted, eventComment, originator,
                                       characterSetClient, collationConnection, databaseCollation});
                    }

                    resultSet->close();
                    statement->close();

                    return events;
                }

                /**
                 * Get all routines
                 *
                 * @param type
                 * @param name
                 * @param schema
                 * @return
                 */
                std::vector<Routines> getRoutines(const std::string &type = "", const std::string &name = "",
                                                  const std::string &schema = "") {

                    std::vector<Routines> routines;

                    std::string query = dbcrudgen::db::mysql::MYSQLQueries::GET_ROUTINES;
                    std::map<std::string, std::string> whereFilters;
                    whereFilters[Routines::COLUMNS::ROUTINE_SCHEMA::NAME] = schema;
                    whereFilters[Routines::COLUMNS::ROUTINE_NAME::NAME] = name;
                    whereFilters[Routines::COLUMNS::ROUTINE_TYPE::NAME] = type;

                    query = appendWhereClauseFilters(query, whereFilters);

                    sql::Statement *statement = &connector.createStatement();
                    sql::ResultSet *resultSet = statement->executeQuery(query);

                    while (resultSet->next()) {

                        std::string specificName = resultSet->getString(Routines::COLUMNS::SPECIFIC_NAME::INDEX);
                        std::string routineCatalog = resultSet->getString(Routines::COLUMNS::ROUTINE_CATALOG::INDEX);
                        std::string routineSchema = resultSet->getString(Routines::COLUMNS::ROUTINE_SCHEMA::INDEX);
                        std::string routineName = resultSet->getString(Routines::COLUMNS::ROUTINE_NAME::INDEX);
                        std::string routineType = resultSet->getString(Routines::COLUMNS::ROUTINE_TYPE::INDEX);
                        std::string dataType = resultSet->getString(Routines::COLUMNS::DATA_TYPE::INDEX);
                        int characterMaximumLength = resultSet->getInt(
                                Routines::COLUMNS::CHARACTER_MAXIMUM_LENGTH::INDEX);
                        int characterOctetLength = resultSet->getInt(Routines::COLUMNS::CHARACTER_OCTET_LENGTH::INDEX);
                        long numericPrecision = resultSet->getInt(Routines::COLUMNS::NUMERIC_PRECISION::INDEX);
                        int numericScale = resultSet->getInt(Routines::COLUMNS::NUMERIC_SCALE::INDEX);
                        long datetimePrecision = resultSet->getInt(Routines::COLUMNS::DATETIME_PRECISION::INDEX);
                        std::string characterSetName = resultSet->getString(
                                Routines::COLUMNS::CHARACTER_SET_NAME::INDEX);
                        std::string collationName = resultSet->getString(Routines::COLUMNS::COLLATION_NAME::INDEX);
                        std::string dtdIdentifier = resultSet->getString(Routines::COLUMNS::DTD_IDENTIFIER::INDEX);
                        std::string routineBody = resultSet->getString(Routines::COLUMNS::ROUTINE_BODY::INDEX);
                        std::string routineDefinition = resultSet->getString(
                                Routines::COLUMNS::ROUTINE_DEFINITION::INDEX);
                        std::string externalName = resultSet->getString(Routines::COLUMNS::EXTERNAL_NAME::INDEX);
                        std::string externalLanguage = resultSet->getString(
                                Routines::COLUMNS::EXTERNAL_LANGUAGE::INDEX);
                        std::string parameterStyle = resultSet->getString(Routines::COLUMNS::PARAMETER_STYLE::INDEX);
                        std::string isDeterministic = resultSet->getString(Routines::COLUMNS::IS_DETERMINISTIC::INDEX);
                        std::string sqlDataAccess = resultSet->getString(Routines::COLUMNS::SQL_DATA_ACCESS::INDEX);
                        std::string sqlPath = resultSet->getString(Routines::COLUMNS::SQL_PATH::INDEX);
                        std::string securityType = resultSet->getString(Routines::COLUMNS::SECURITY_TYPE::INDEX);
                        std::string created = resultSet->getString(Routines::COLUMNS::CREATED::INDEX);
                        std::string lastAltered = resultSet->getString(Routines::COLUMNS::LAST_ALTERED::INDEX);
                        std::string sqlMode = resultSet->getString(Routines::COLUMNS::SQL_MODE::INDEX);
                        std::string routineComment = resultSet->getString(Routines::COLUMNS::ROUTINE_COMMENT::INDEX);
                        std::string definer = resultSet->getString(Routines::COLUMNS::DEFINER::INDEX);
                        std::string characterSetClient = resultSet->getString(
                                Routines::COLUMNS::CHARACTER_SET_CLIENT::INDEX);
                        std::string collationConnection = resultSet->getString(
                                Routines::COLUMNS::COLLATION_CONNECTION::INDEX);
                        std::string databaseCollation = resultSet->getString(
                                Routines::COLUMNS::DATABASE_COLLATION::INDEX);

                        routines.emplace_back(
                                Routines{specificName, routineCatalog, routineSchema, routineName, routineType,
                                         dataType,
                                         characterMaximumLength, characterOctetLength, numericPrecision, numericScale,
                                         datetimePrecision, characterSetName, collationName, dtdIdentifier, routineBody,
                                         routineDefinition, externalName, externalLanguage, parameterStyle,
                                         isDeterministic,
                                         sqlDataAccess, sqlPath, securityType, created, lastAltered, sqlMode,
                                         routineComment, definer, characterSetClient, collationConnection,
                                         databaseCollation});
                    }

                    resultSet->close();
                    statement->close();

                    return routines;
                }


                /**
                 * Get all routines
                 *
                 * @param type
                 * @param name
                 * @param schema
                 * @return
                 */
                std::vector<Partitions> getPartitions(const std::string &partitionName = "",
                                                      const std::string &tableName = "",
                                                      const std::string &tableSpaceName = "",
                                                      const std::string &schema = "") {

                    std::vector<Partitions> partitions;

                    std::string query = dbcrudgen::db::mysql::MYSQLQueries::GET_PARTITIONS;
                    std::map<std::string, std::string> whereFilters;
                    whereFilters[Partitions::COLUMNS::PARTITION_NAME::NAME] = partitionName;
                    whereFilters[Partitions::COLUMNS::TABLE_NAME::NAME] = tableName;
                    whereFilters[Partitions::COLUMNS::TABLESPACE_NAME::NAME] = tableSpaceName;
                    whereFilters[Partitions::COLUMNS::TABLE_SCHEMA::NAME] = schema;

                    query = appendWhereClauseFilters(query, whereFilters);

                    sql::Statement *statement = &connector.createStatement();
                    sql::ResultSet *resultSet = statement->executeQuery(query);

                    while (resultSet->next()) {

                        std::string tableCatalog = resultSet->getString(Partitions::COLUMNS::TABLE_CATALOG::INDEX);
                        std::string tableSchema = resultSet->getString(Partitions::COLUMNS::TABLE_SCHEMA::INDEX);
                        std::string tableName = resultSet->getString(Partitions::COLUMNS::TABLE_NAME::INDEX);
                        std::string partitionName = resultSet->getString(Partitions::COLUMNS::PARTITION_NAME::INDEX);
                        std::string subpartitionName = resultSet->getString(Partitions::COLUMNS::SUBPARTITION_NAME::INDEX);
                        long partitionOrdinalPosition = resultSet->getInt(Partitions::COLUMNS::PARTITION_ORDINAL_POSITION::INDEX);
                        long subpartitionOrdinalPosition = resultSet->getInt(Partitions::COLUMNS::SUBPARTITION_ORDINAL_POSITION::INDEX);
                        std::string partitionMethod = resultSet->getString(Partitions::COLUMNS::PARTITION_METHOD::INDEX);
                        std::string subpartitionMethod = resultSet->getString(Partitions::COLUMNS::SUBPARTITION_METHOD::INDEX);
                        std::string partitionExpression = resultSet->getString(Partitions::COLUMNS::PARTITION_EXPRESSION::INDEX);
                        std::string subpartitionExpression = resultSet->getString(Partitions::COLUMNS::SUBPARTITION_EXPRESSION::INDEX);
                        std::string partitionDescription = resultSet->getString(Partitions::COLUMNS::PARTITION_DESCRIPTION::INDEX);
                        long tableRows = resultSet->getInt(Partitions::COLUMNS::TABLE_ROWS::INDEX);
                        long avgRowLength = resultSet->getInt(Partitions::COLUMNS::AVG_ROW_LENGTH::INDEX);
                        long dataLength = resultSet->getInt(Partitions::COLUMNS::DATA_LENGTH::INDEX);
                        long maxDataLength = resultSet->getInt(Partitions::COLUMNS::MAX_DATA_LENGTH::INDEX);
                        long indexLength = resultSet->getInt(Partitions::COLUMNS::INDEX_LENGTH::INDEX);
                        long dataFree = resultSet->getInt(Partitions::COLUMNS::DATA_FREE::INDEX);
                        std::string createTime = resultSet->getString(Partitions::COLUMNS::CREATE_TIME::INDEX);
                        std::string updateTime = resultSet->getString(Partitions::COLUMNS::UPDATE_TIME::INDEX);
                        std::string checkTime = resultSet->getString(Partitions::COLUMNS::CHECK_TIME::INDEX);
                        long checksum = resultSet->getInt(Partitions::COLUMNS::CHECKSUM::INDEX);
                        std::string partitionComment = resultSet->getString(
                                Partitions::COLUMNS::PARTITION_COMMENT::INDEX);
                        std::string nodegroup = resultSet->getString(Partitions::COLUMNS::NODEGROUP::INDEX);
                        std::string tablespaceName = resultSet->getString(Partitions::COLUMNS::TABLESPACE_NAME::INDEX);

                        partitions.emplace_back(
                                Partitions{tableCatalog, tableSchema, tableName, partitionName, subpartitionName,
                                           partitionOrdinalPosition, subpartitionOrdinalPosition, partitionMethod,
                                           subpartitionMethod, partitionExpression, subpartitionExpression,
                                           partitionDescription,
                                           tableRows, avgRowLength, dataLength, maxDataLength, indexLength, dataFree,
                                           createTime, updateTime, checkTime, checksum, partitionComment, nodegroup,
                                           tablespaceName});
                    }

                    resultSet->close();
                    statement->close();

                    return partitions;
                }


            };
        }
    }
}


#endif //DBCRUDGEN_CPP_MYSQLDATABASEPREPAREDDECOMPOSER_H
