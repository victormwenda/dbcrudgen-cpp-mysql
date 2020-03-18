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

#include "../queries/MysqlQueries.h"

#include "../schema/CharacterSets.h"
#include "../schema/Collations.h"
#include "../schema/CollationCharacterSetApplicability.h"
#include "../schema/Columns.h"
#include "../schema/ColumnPrivileges.h"
#include "../schema/Engines.h"
#include "../schema/Events.h"
#include "../schema/Files.h"
#include "../schema/GlobalStatus.h"
#include "../schema/GlobalVariables.h"
#include "../schema/KeyColumnUsage.h"
#include "../schema/OptimizerTrace.h"
#include "../schema/Parameters.h"
#include "../schema/Partitions.h"
#include "../schema/Plugins.h"
#include "../schema/ProcessList.h"
#include "../schema/Profiling.h"
#include "../schema/ReferentialConstraints.h"
#include "../schema/Routines.h"
#include "../schema/Schemata.h"
#include "../schema/SchemaPrivileges.h"
#include "../schema/SessionStatus.h"
#include "../schema/SessionVariables.h"
#include "../schema/Statistics.h"
#include "../schema/Tables.h"
#include "../schema/TableSpaces.h"
#include "../schema/TableConstraints.h"
#include "../schema/TablePrivileges.h"
#include "../schema/Triggers.h"
#include "../schema/UserPrivileges.h"
#include "../schema/Views.h"
#include "../schema/InnoDbLocks.h"
#include "../schema/InnoDbTrx.h"
#include "../schema/InnoDbSysDataFiles.h"
#include "../schema/InnoDbFtConfig.h"
#include "../schema/InnoDbSysVirtual.h"
#include "../schema/InnoDbCmp.h"
#include "../schema/InnoDbFtBeingDeleted.h"
#include "../schema/InnoDbCmpReset.h"
#include "../schema/InnoDbCmpPerIndex.h"
#include "../schema/InnoDbCmpMemReset.h"
#include "../schema/InnoDbFtDeleted.h"
#include "../schema/InnoDbBufferPageLRU.h"
#include "../schema/InnoDbLockWaits.h"
#include "../schema/InnoDbTempTableInfo.h"
#include "../schema/InnoDbSysIndexes.h"
#include "../schema/InnoDbSysTables.h"
#include "../schema/InnoDbSysFields.h"
#include "../schema/InnoDbCmpPerIndexReset.h"
#include "../schema/InnoDbBufferPage.h"
#include "../schema/InnoDbFtDefaultStopWord.h"
#include "../schema/InnoDbFtIndexTable.h"
#include "../schema/InnoDbFtIndexCache.h"
#include "../schema/InnoDbSysTableSpaces.h"
#include "../schema/InnoDbMetrics.h"
#include "../schema/InnoDbSysForeignCols.h"
#include "../schema/InnoDbCmpMem.h"
#include "../schema/InnoDbBufferPoolStats.h"
#include "../schema/InnoDbSysColumns.h"
#include "../schema/InnoDbSysForeign.h"
#include "../schema/InnoDbSysTableStats.h"

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
* Get all CHARACTER_SETS
*/
            std::vector<CharacterSets> getCharacterSets() {

                std::vector<CharacterSets> characterSets;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_CHARACTER_SETS;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    std::string characterSetName = resultSet->getString(
                            CharacterSets::COLUMNS::CHARACTER_SET_NAME::INDEX);
                    std::string defaultCollateName = resultSet->getString(
                            CharacterSets::COLUMNS::DEFAULT_COLLATE_NAME::INDEX);
                    std::string description = resultSet->getString(CharacterSets::COLUMNS::DESCRIPTION::INDEX);
                    long maxlen = resultSet->getInt(CharacterSets::COLUMNS::MAXLEN::INDEX);

                    characterSets.emplace_back(
                            CharacterSets{characterSetName, defaultCollateName, description, maxlen});
                }

                resultSet->close();
                statement->close();

                return characterSets;
            }

/**
* Get all COLLATIONS
*/
            std::vector<Collations> getCollations() {

                std::vector<Collations> collations;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_COLLATIONS;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    std::string collationName = resultSet->getString(Collations::COLUMNS::COLLATION_NAME::INDEX);
                    std::string characterSetName = resultSet->getString(Collations::COLUMNS::CHARACTER_SET_NAME::INDEX);
                    long id = resultSet->getInt(Collations::COLUMNS::ID::INDEX);
                    std::string isDefault = resultSet->getString(Collations::COLUMNS::IS_DEFAULT::INDEX);
                    std::string isCompiled = resultSet->getString(Collations::COLUMNS::IS_COMPILED::INDEX);
                    long sortlen = resultSet->getInt(Collations::COLUMNS::SORTLEN::INDEX);

                    collations.emplace_back(
                            Collations{collationName, characterSetName, id, isDefault, isCompiled, sortlen});
                }

                resultSet->close();
                statement->close();

                return collations;
            }

/**
* Get all COLLATION_CHARACTER_SET_APPLICABILITY
*/
            std::vector<CollationCharacterSetApplicability> getCollationCharacterSetApplicability() {

                std::vector<CollationCharacterSetApplicability> collationCharacterSetApplicability;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_COLLATION_CHARACTER_SET_APPLICABILITY;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    std::string collationName = resultSet->getString(
                            CollationCharacterSetApplicability::COLUMNS::COLLATION_NAME::INDEX);
                    std::string characterSetName = resultSet->getString(
                            CollationCharacterSetApplicability::COLUMNS::CHARACTER_SET_NAME::INDEX);

                    collationCharacterSetApplicability.emplace_back(
                            CollationCharacterSetApplicability{collationName, characterSetName});
                }

                resultSet->close();
                statement->close();

                return collationCharacterSetApplicability;
            }

/**
* Get all COLUMNS
*/
            std::vector<Columns> getColumns() {

                std::vector<Columns> columns;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_COLUMNS;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    std::string tableCatalog = resultSet->getString(Columns::COLUMNS::TABLE_CATALOG::INDEX);
                    std::string tableSchema = resultSet->getString(Columns::COLUMNS::TABLE_SCHEMA::INDEX);
                    std::string tableName = resultSet->getString(Columns::COLUMNS::TABLE_NAME::INDEX);
                    std::string columnName = resultSet->getString(Columns::COLUMNS::COLUMN_NAME::INDEX);
                    long ordinalPosition = resultSet->getInt(Columns::COLUMNS::ORDINAL_POSITION::INDEX);
                    std::string columnDefault = resultSet->getString(Columns::COLUMNS::COLUMN_DEFAULT::INDEX);
                    std::string isNullable = resultSet->getString(Columns::COLUMNS::IS_NULLABLE::INDEX);
                    std::string dataType = resultSet->getString(Columns::COLUMNS::DATA_TYPE::INDEX);
                    long characterMaximumLength = resultSet->getInt(Columns::COLUMNS::CHARACTER_MAXIMUM_LENGTH::INDEX);
                    long characterOctetLength = resultSet->getInt(Columns::COLUMNS::CHARACTER_OCTET_LENGTH::INDEX);
                    long numericPrecision = resultSet->getInt(Columns::COLUMNS::NUMERIC_PRECISION::INDEX);
                    long numericScale = resultSet->getInt(Columns::COLUMNS::NUMERIC_SCALE::INDEX);
                    long datetimePrecision = resultSet->getInt(Columns::COLUMNS::DATETIME_PRECISION::INDEX);
                    std::string characterSetName = resultSet->getString(Columns::COLUMNS::CHARACTER_SET_NAME::INDEX);
                    std::string collationName = resultSet->getString(Columns::COLUMNS::COLLATION_NAME::INDEX);
                    std::string columnType = resultSet->getString(Columns::COLUMNS::COLUMN_TYPE::INDEX);
                    std::string columnKey = resultSet->getString(Columns::COLUMNS::COLUMN_KEY::INDEX);
                    std::string extra = resultSet->getString(Columns::COLUMNS::EXTRA::INDEX);
                    std::string privileges = resultSet->getString(Columns::COLUMNS::PRIVILEGES::INDEX);
                    std::string columnComment = resultSet->getString(Columns::COLUMNS::COLUMN_COMMENT::INDEX);
                    std::string generationExpression = resultSet->getString(
                            Columns::COLUMNS::GENERATION_EXPRESSION::INDEX);

                    columns.emplace_back(
                            Columns{tableCatalog, tableSchema, tableName, columnName, ordinalPosition, columnDefault,
                                    isNullable, dataType, characterMaximumLength, characterOctetLength,
                                    numericPrecision, numericScale, datetimePrecision, characterSetName, collationName,
                                    columnType, columnKey, extra, privileges, columnComment, generationExpression});
                }

                resultSet->close();
                statement->close();

                return columns;
            }

/**
* Get all COLUMN_PRIVILEGES
*/
            std::vector<ColumnPrivileges> getColumnPrivileges() {

                std::vector<ColumnPrivileges> columnPrivileges;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_COLUMN_PRIVILEGES;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    std::string grantee = resultSet->getString(ColumnPrivileges::COLUMNS::GRANTEE::INDEX);
                    std::string tableCatalog = resultSet->getString(ColumnPrivileges::COLUMNS::TABLE_CATALOG::INDEX);
                    std::string tableSchema = resultSet->getString(ColumnPrivileges::COLUMNS::TABLE_SCHEMA::INDEX);
                    std::string tableName = resultSet->getString(ColumnPrivileges::COLUMNS::TABLE_NAME::INDEX);
                    std::string columnName = resultSet->getString(ColumnPrivileges::COLUMNS::COLUMN_NAME::INDEX);
                    std::string privilegeType = resultSet->getString(ColumnPrivileges::COLUMNS::PRIVILEGE_TYPE::INDEX);
                    std::string isGrantable = resultSet->getString(ColumnPrivileges::COLUMNS::IS_GRANTABLE::INDEX);

                    columnPrivileges.emplace_back(
                            ColumnPrivileges{grantee, tableCatalog, tableSchema, tableName, columnName, privilegeType,
                                             isGrantable});
                }

                resultSet->close();
                statement->close();

                return columnPrivileges;
            }

/**
* Get all ENGINES
*/
            std::vector<Engines> getEngines() {

                std::vector<Engines> engines;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_ENGINES;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    std::string engine = resultSet->getString(Engines::COLUMNS::ENGINE::INDEX);
                    std::string support = resultSet->getString(Engines::COLUMNS::SUPPORT::INDEX);
                    std::string comment = resultSet->getString(Engines::COLUMNS::COMMENT::INDEX);
                    std::string transactions = resultSet->getString(Engines::COLUMNS::TRANSACTIONS::INDEX);
                    std::string xa = resultSet->getString(Engines::COLUMNS::XA::INDEX);
                    std::string savepoints = resultSet->getString(Engines::COLUMNS::SAVEPOINTS::INDEX);

                    engines.emplace_back(Engines{engine, support, comment, transactions, xa, savepoints});
                }

                resultSet->close();
                statement->close();

                return engines;
            }

/**
* Get all EVENTS
*/
            std::vector<Events> getEvents() {

                std::vector<Events> events;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_EVENTS;

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
                    std::string characterSetClient = resultSet->getString(Events::COLUMNS::CHARACTER_SET_CLIENT::INDEX);
                    std::string collationConnection = resultSet->getString(
                            Events::COLUMNS::COLLATION_CONNECTION::INDEX);
                    std::string databaseCollation = resultSet->getString(Events::COLUMNS::DATABASE_COLLATION::INDEX);

                    events.emplace_back(
                            Events{eventCatalog, eventSchema, eventName, definer, timeZone, eventBody, eventDefinition,
                                   eventType, executeAt, intervalValue, intervalField, sqlMode, starts, ends, status,
                                   onCompletion, created, lastAltered, lastExecuted, eventComment, originator,
                                   characterSetClient, collationConnection, databaseCollation});
                }

                resultSet->close();
                statement->close();

                return events;
            }

/**
* Get all FILES
*/
            std::vector<Files> getFiles() {

                std::vector<Files> files;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_FILES;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    long fileId = resultSet->getInt(Files::COLUMNS::FILE_ID::INDEX);
                    std::string fileName = resultSet->getString(Files::COLUMNS::FILE_NAME::INDEX);
                    std::string fileType = resultSet->getString(Files::COLUMNS::FILE_TYPE::INDEX);
                    std::string tablespaceName = resultSet->getString(Files::COLUMNS::TABLESPACE_NAME::INDEX);
                    std::string tableCatalog = resultSet->getString(Files::COLUMNS::TABLE_CATALOG::INDEX);
                    std::string tableSchema = resultSet->getString(Files::COLUMNS::TABLE_SCHEMA::INDEX);
                    std::string tableName = resultSet->getString(Files::COLUMNS::TABLE_NAME::INDEX);
                    std::string logfileGroupName = resultSet->getString(Files::COLUMNS::LOGFILE_GROUP_NAME::INDEX);
                    long logfileGroupNumber = resultSet->getInt(Files::COLUMNS::LOGFILE_GROUP_NUMBER::INDEX);
                    std::string engine = resultSet->getString(Files::COLUMNS::ENGINE::INDEX);
                    std::string fulltextKeys = resultSet->getString(Files::COLUMNS::FULLTEXT_KEYS::INDEX);
                    long deletedRows = resultSet->getInt(Files::COLUMNS::DELETED_ROWS::INDEX);
                    long updateCount = resultSet->getInt(Files::COLUMNS::UPDATE_COUNT::INDEX);
                    long freeExtents = resultSet->getInt(Files::COLUMNS::FREE_EXTENTS::INDEX);
                    long totalExtents = resultSet->getInt(Files::COLUMNS::TOTAL_EXTENTS::INDEX);
                    long extentSize = resultSet->getInt(Files::COLUMNS::EXTENT_SIZE::INDEX);
                    long initialSize = resultSet->getInt(Files::COLUMNS::INITIAL_SIZE::INDEX);
                    long maximumSize = resultSet->getInt(Files::COLUMNS::MAXIMUM_SIZE::INDEX);
                    long autoextendSize = resultSet->getInt(Files::COLUMNS::AUTOEXTEND_SIZE::INDEX);
                    std::string creationTime = resultSet->getString(Files::COLUMNS::CREATION_TIME::INDEX);
                    std::string lastUpdateTime = resultSet->getString(Files::COLUMNS::LAST_UPDATE_TIME::INDEX);
                    std::string lastAccessTime = resultSet->getString(Files::COLUMNS::LAST_ACCESS_TIME::INDEX);
                    long recoverTime = resultSet->getInt(Files::COLUMNS::RECOVER_TIME::INDEX);
                    long transactionCounter = resultSet->getInt(Files::COLUMNS::TRANSACTION_COUNTER::INDEX);
                    long version = resultSet->getInt(Files::COLUMNS::VERSION::INDEX);
                    std::string rowFormat = resultSet->getString(Files::COLUMNS::ROW_FORMAT::INDEX);
                    long tableRows = resultSet->getInt(Files::COLUMNS::TABLE_ROWS::INDEX);
                    long avgRowLength = resultSet->getInt(Files::COLUMNS::AVG_ROW_LENGTH::INDEX);
                    long dataLength = resultSet->getInt(Files::COLUMNS::DATA_LENGTH::INDEX);
                    long maxDataLength = resultSet->getInt(Files::COLUMNS::MAX_DATA_LENGTH::INDEX);
                    long indexLength = resultSet->getInt(Files::COLUMNS::INDEX_LENGTH::INDEX);
                    long dataFree = resultSet->getInt(Files::COLUMNS::DATA_FREE::INDEX);
                    std::string createTime = resultSet->getString(Files::COLUMNS::CREATE_TIME::INDEX);
                    std::string updateTime = resultSet->getString(Files::COLUMNS::UPDATE_TIME::INDEX);
                    std::string checkTime = resultSet->getString(Files::COLUMNS::CHECK_TIME::INDEX);
                    long checksum = resultSet->getInt(Files::COLUMNS::CHECKSUM::INDEX);
                    std::string status = resultSet->getString(Files::COLUMNS::STATUS::INDEX);
                    std::string extra = resultSet->getString(Files::COLUMNS::EXTRA::INDEX);

                    files.emplace_back(
                            Files{fileId, fileName, fileType, tablespaceName, tableCatalog, tableSchema, tableName,
                                  logfileGroupName, logfileGroupNumber, engine, fulltextKeys, deletedRows, updateCount,
                                  freeExtents, totalExtents, extentSize, initialSize, maximumSize, autoextendSize,
                                  creationTime, lastUpdateTime, lastAccessTime, recoverTime, transactionCounter,
                                  version, rowFormat, tableRows, avgRowLength, dataLength, maxDataLength, indexLength,
                                  dataFree, createTime, updateTime, checkTime, checksum, status, extra});
                }

                resultSet->close();
                statement->close();

                return files;
            }

/**
* Get all GLOBAL_STATUS
*/
            std::vector<GlobalStatus> getGlobalStatus() {

                std::vector<GlobalStatus> globalStatus;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_GLOBAL_STATUS;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    std::string variableName = resultSet->getString(GlobalStatus::COLUMNS::VARIABLE_NAME::INDEX);
                    std::string variableValue = resultSet->getString(GlobalStatus::COLUMNS::VARIABLE_VALUE::INDEX);

                    globalStatus.emplace_back(GlobalStatus{variableName, variableValue});
                }

                resultSet->close();
                statement->close();

                return globalStatus;
            }

/**
* Get all GLOBAL_VARIABLES
*/
            std::vector<GlobalVariables> getGlobalVariables() {

                std::vector<GlobalVariables> globalVariables;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_GLOBAL_VARIABLES;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    std::string variableName = resultSet->getString(GlobalVariables::COLUMNS::VARIABLE_NAME::INDEX);
                    std::string variableValue = resultSet->getString(GlobalVariables::COLUMNS::VARIABLE_VALUE::INDEX);

                    globalVariables.emplace_back(GlobalVariables{variableName, variableValue});
                }

                resultSet->close();
                statement->close();

                return globalVariables;
            }

/**
* Get all KEY_COLUMN_USAGE
*/
            std::vector<KeyColumnUsage> getKeyColumnUsage() {

                std::vector<KeyColumnUsage> keyColumnUsage;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_KEY_COLUMN_USAGE;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    std::string constraintCatalog = resultSet->getString(
                            KeyColumnUsage::COLUMNS::CONSTRAINT_CATALOG::INDEX);
                    std::string constraintSchema = resultSet->getString(
                            KeyColumnUsage::COLUMNS::CONSTRAINT_SCHEMA::INDEX);
                    std::string constraintName = resultSet->getString(KeyColumnUsage::COLUMNS::CONSTRAINT_NAME::INDEX);
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
* Get all OPTIMIZER_TRACE
*/
            std::vector<OptimizerTrace> getOptimizerTrace() {

                std::vector<OptimizerTrace> optimizerTrace;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_OPTIMIZER_TRACE;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    std::string query = resultSet->getString(OptimizerTrace::COLUMNS::QUERY::INDEX);
                    std::string trace = resultSet->getString(OptimizerTrace::COLUMNS::TRACE::INDEX);
                    int missingBytesBeyondMaxMemSize = resultSet->getInt(
                            OptimizerTrace::COLUMNS::MISSING_BYTES_BEYOND_MAX_MEM_SIZE::INDEX);
                    int insufficientPrivileges = resultSet->getInt(
                            OptimizerTrace::COLUMNS::INSUFFICIENT_PRIVILEGES::INDEX);

                    optimizerTrace.emplace_back(
                            OptimizerTrace{query, trace, missingBytesBeyondMaxMemSize, insufficientPrivileges});
                }

                resultSet->close();
                statement->close();

                return optimizerTrace;
            }

/**
* Get all PARAMETERS
*/
            std::vector<Parameters> getParameters() {

                std::vector<Parameters> parameters;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_PARAMETERS;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    std::string specificCatalog = resultSet->getString(Parameters::COLUMNS::SPECIFIC_CATALOG::INDEX);
                    std::string specificSchema = resultSet->getString(Parameters::COLUMNS::SPECIFIC_SCHEMA::INDEX);
                    std::string specificName = resultSet->getString(Parameters::COLUMNS::SPECIFIC_NAME::INDEX);
                    int ordinalPosition = resultSet->getInt(Parameters::COLUMNS::ORDINAL_POSITION::INDEX);
                    std::string parameterMode = resultSet->getString(Parameters::COLUMNS::PARAMETER_MODE::INDEX);
                    std::string parameterName = resultSet->getString(Parameters::COLUMNS::PARAMETER_NAME::INDEX);
                    std::string dataType = resultSet->getString(Parameters::COLUMNS::DATA_TYPE::INDEX);
                    int characterMaximumLength = resultSet->getInt(
                            Parameters::COLUMNS::CHARACTER_MAXIMUM_LENGTH::INDEX);
                    int characterOctetLength = resultSet->getInt(Parameters::COLUMNS::CHARACTER_OCTET_LENGTH::INDEX);
                    long numericPrecision = resultSet->getInt(Parameters::COLUMNS::NUMERIC_PRECISION::INDEX);
                    int numericScale = resultSet->getInt(Parameters::COLUMNS::NUMERIC_SCALE::INDEX);
                    long datetimePrecision = resultSet->getInt(Parameters::COLUMNS::DATETIME_PRECISION::INDEX);
                    std::string characterSetName = resultSet->getString(Parameters::COLUMNS::CHARACTER_SET_NAME::INDEX);
                    std::string collationName = resultSet->getString(Parameters::COLUMNS::COLLATION_NAME::INDEX);
                    std::string dtdIdentifier = resultSet->getString(Parameters::COLUMNS::DTD_IDENTIFIER::INDEX);
                    std::string routineType = resultSet->getString(Parameters::COLUMNS::ROUTINE_TYPE::INDEX);

                    parameters.emplace_back(
                            Parameters{specificCatalog, specificSchema, specificName, ordinalPosition, parameterMode,
                                       parameterName, dataType, characterMaximumLength, characterOctetLength,
                                       numericPrecision, numericScale, datetimePrecision, characterSetName,
                                       collationName, dtdIdentifier, routineType});
                }

                resultSet->close();
                statement->close();

                return parameters;
            }

/**
* Get all PARTITIONS
*/
            std::vector<Partitions> getPartitions() {

                std::vector<Partitions> partitions;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_PARTITIONS;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    std::string tableCatalog = resultSet->getString(Partitions::COLUMNS::TABLE_CATALOG::INDEX);
                    std::string tableSchema = resultSet->getString(Partitions::COLUMNS::TABLE_SCHEMA::INDEX);
                    std::string tableName = resultSet->getString(Partitions::COLUMNS::TABLE_NAME::INDEX);
                    std::string partitionName = resultSet->getString(Partitions::COLUMNS::PARTITION_NAME::INDEX);
                    std::string subpartitionName = resultSet->getString(Partitions::COLUMNS::SUBPARTITION_NAME::INDEX);
                    long partitionOrdinalPosition = resultSet->getInt(
                            Partitions::COLUMNS::PARTITION_ORDINAL_POSITION::INDEX);
                    long subpartitionOrdinalPosition = resultSet->getInt(
                            Partitions::COLUMNS::SUBPARTITION_ORDINAL_POSITION::INDEX);
                    std::string partitionMethod = resultSet->getString(Partitions::COLUMNS::PARTITION_METHOD::INDEX);
                    std::string subpartitionMethod = resultSet->getString(
                            Partitions::COLUMNS::SUBPARTITION_METHOD::INDEX);
                    std::string partitionExpression = resultSet->getString(
                            Partitions::COLUMNS::PARTITION_EXPRESSION::INDEX);
                    std::string subpartitionExpression = resultSet->getString(
                            Partitions::COLUMNS::SUBPARTITION_EXPRESSION::INDEX);
                    std::string partitionDescription = resultSet->getString(
                            Partitions::COLUMNS::PARTITION_DESCRIPTION::INDEX);
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
                    std::string partitionComment = resultSet->getString(Partitions::COLUMNS::PARTITION_COMMENT::INDEX);
                    std::string nodegroup = resultSet->getString(Partitions::COLUMNS::NODEGROUP::INDEX);
                    std::string tablespaceName = resultSet->getString(Partitions::COLUMNS::TABLESPACE_NAME::INDEX);

                    partitions.emplace_back(
                            Partitions{tableCatalog, tableSchema, tableName, partitionName, subpartitionName,
                                       partitionOrdinalPosition, subpartitionOrdinalPosition, partitionMethod,
                                       subpartitionMethod, partitionExpression, subpartitionExpression,
                                       partitionDescription, tableRows, avgRowLength, dataLength, maxDataLength,
                                       indexLength, dataFree, createTime, updateTime, checkTime, checksum,
                                       partitionComment, nodegroup, tablespaceName});
                }

                resultSet->close();
                statement->close();

                return partitions;
            }

/**
* Get all PLUGINS
*/
            std::vector<Plugins> getPlugins() {

                std::vector<Plugins> plugins;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_PLUGINS;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    std::string pluginName = resultSet->getString(Plugins::COLUMNS::PLUGIN_NAME::INDEX);
                    std::string pluginVersion = resultSet->getString(Plugins::COLUMNS::PLUGIN_VERSION::INDEX);
                    std::string pluginStatus = resultSet->getString(Plugins::COLUMNS::PLUGIN_STATUS::INDEX);
                    std::string pluginType = resultSet->getString(Plugins::COLUMNS::PLUGIN_TYPE::INDEX);
                    std::string pluginTypeVersion = resultSet->getString(Plugins::COLUMNS::PLUGIN_TYPE_VERSION::INDEX);
                    std::string pluginLibrary = resultSet->getString(Plugins::COLUMNS::PLUGIN_LIBRARY::INDEX);
                    std::string pluginLibraryVersion = resultSet->getString(
                            Plugins::COLUMNS::PLUGIN_LIBRARY_VERSION::INDEX);
                    std::string pluginAuthor = resultSet->getString(Plugins::COLUMNS::PLUGIN_AUTHOR::INDEX);
                    std::string pluginDescription = resultSet->getString(Plugins::COLUMNS::PLUGIN_DESCRIPTION::INDEX);
                    std::string pluginLicense = resultSet->getString(Plugins::COLUMNS::PLUGIN_LICENSE::INDEX);
                    std::string loadOption = resultSet->getString(Plugins::COLUMNS::LOAD_OPTION::INDEX);

                    plugins.emplace_back(Plugins{pluginName, pluginVersion, pluginStatus, pluginType, pluginTypeVersion,
                                                 pluginLibrary, pluginLibraryVersion, pluginAuthor, pluginDescription,
                                                 pluginLicense, loadOption});
                }

                resultSet->close();
                statement->close();

                return plugins;
            }

/**
* Get all PROCESSLIST
*/
            std::vector<ProcessList> getProcessList() {

                std::vector<ProcessList> processlist;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_PROCESSLIST;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    long id = resultSet->getInt(ProcessList::COLUMNS::ID::INDEX);
                    std::string user = resultSet->getString(ProcessList::COLUMNS::USER::INDEX);
                    std::string host = resultSet->getString(ProcessList::COLUMNS::HOST::INDEX);
                    std::string db = resultSet->getString(ProcessList::COLUMNS::DB::INDEX);
                    std::string command = resultSet->getString(ProcessList::COLUMNS::COMMAND::INDEX);
                    int time = resultSet->getInt(ProcessList::COLUMNS::TIME::INDEX);
                    std::string state = resultSet->getString(ProcessList::COLUMNS::STATE::INDEX);
                    std::string info = resultSet->getString(ProcessList::COLUMNS::INFO::INDEX);

                    processlist.emplace_back(ProcessList{id, user, host, db, command, time, state, info});
                }

                resultSet->close();
                statement->close();

                return processlist;
            }

            /**
            * Get all PROFILING
            */
            std::vector<Profiling> getProfiling() {

                std::vector<Profiling> profiling;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_PROFILING;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    int queryId = resultSet->getInt(Profiling::COLUMNS::QUERY_ID::INDEX);
                    int seq = resultSet->getInt(Profiling::COLUMNS::SEQ::INDEX);
                    std::string state = resultSet->getString(Profiling::COLUMNS::STATE::INDEX);
                    long duration = resultSet->getInt(Profiling::COLUMNS::DURATION::INDEX);
                    long cpuUser = resultSet->getInt(Profiling::COLUMNS::CPU_USER::INDEX);
                    long cpuSystem = resultSet->getInt(Profiling::COLUMNS::CPU_SYSTEM::INDEX);
                    int contextVoluntary = resultSet->getInt(Profiling::COLUMNS::CONTEXT_VOLUNTARY::INDEX);
                    int contextInvoluntary = resultSet->getInt(Profiling::COLUMNS::CONTEXT_INVOLUNTARY::INDEX);
                    int blockOpsIn = resultSet->getInt(Profiling::COLUMNS::BLOCK_OPS_IN::INDEX);
                    int blockOpsOut = resultSet->getInt(Profiling::COLUMNS::BLOCK_OPS_OUT::INDEX);
                    int messagesSent = resultSet->getInt(Profiling::COLUMNS::MESSAGES_SENT::INDEX);
                    int messagesReceived = resultSet->getInt(Profiling::COLUMNS::MESSAGES_RECEIVED::INDEX);
                    int pageFaultsMajor = resultSet->getInt(Profiling::COLUMNS::PAGE_FAULTS_MAJOR::INDEX);
                    int pageFaultsMinor = resultSet->getInt(Profiling::COLUMNS::PAGE_FAULTS_MINOR::INDEX);
                    int swaps = resultSet->getInt(Profiling::COLUMNS::SWAPS::INDEX);
                    std::string sourceFunction = resultSet->getString(Profiling::COLUMNS::SOURCE_FUNCTION::INDEX);
                    std::string sourceFile = resultSet->getString(Profiling::COLUMNS::SOURCE_FILE::INDEX);
                    int sourceLine = resultSet->getInt(Profiling::COLUMNS::SOURCE_LINE::INDEX);

                    profiling.emplace_back(
                            Profiling{queryId, seq, state, duration, cpuUser, cpuSystem, contextVoluntary,
                                      contextInvoluntary, blockOpsIn, blockOpsOut, messagesSent, messagesReceived,
                                      pageFaultsMajor, pageFaultsMinor, swaps, sourceFunction, sourceFile, sourceLine});
                }

                resultSet->close();
                statement->close();

                return profiling;
            }

/**
* Get all REFERENTIAL_CONSTRAINTS
*/
            std::vector<ReferentialConstraints> getReferentialConstraints() {

                std::vector<ReferentialConstraints> referentialConstraints;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_REFERENTIAL_CONSTRAINTS;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    std::string constraintCatalog = resultSet->getString(
                            ReferentialConstraints::COLUMNS::CONSTRAINT_CATALOG::INDEX);
                    std::string constraintSchema = resultSet->getString(
                            ReferentialConstraints::COLUMNS::CONSTRAINT_SCHEMA::INDEX);
                    std::string constraintName = resultSet->getString(
                            ReferentialConstraints::COLUMNS::CONSTRAINT_NAME::INDEX);
                    std::string uniqueConstraintCatalog = resultSet->getString(
                            ReferentialConstraints::COLUMNS::UNIQUE_CONSTRAINT_CATALOG::INDEX);
                    std::string uniqueConstraintSchema = resultSet->getString(
                            ReferentialConstraints::COLUMNS::UNIQUE_CONSTRAINT_SCHEMA::INDEX);
                    std::string uniqueConstraintName = resultSet->getString(
                            ReferentialConstraints::COLUMNS::UNIQUE_CONSTRAINT_NAME::INDEX);
                    std::string matchOption = resultSet->getString(
                            ReferentialConstraints::COLUMNS::MATCH_OPTION::INDEX);
                    std::string updateRule = resultSet->getString(ReferentialConstraints::COLUMNS::UPDATE_RULE::INDEX);
                    std::string deleteRule = resultSet->getString(ReferentialConstraints::COLUMNS::DELETE_RULE::INDEX);
                    std::string tableName = resultSet->getString(ReferentialConstraints::COLUMNS::TABLE_NAME::INDEX);
                    std::string referencedTableName = resultSet->getString(
                            ReferentialConstraints::COLUMNS::REFERENCED_TABLE_NAME::INDEX);

                    referentialConstraints.emplace_back(
                            ReferentialConstraints{constraintCatalog, constraintSchema, constraintName,
                                                   uniqueConstraintCatalog, uniqueConstraintSchema,
                                                   uniqueConstraintName, matchOption, updateRule, deleteRule, tableName,
                                                   referencedTableName});
                }

                resultSet->close();
                statement->close();

                return referentialConstraints;
            }

/**
* Get all ROUTINES
*/
            std::vector<Routines> getRoutines() {

                std::vector<Routines> routines;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_ROUTINES;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    std::string specificName = resultSet->getString(Routines::COLUMNS::SPECIFIC_NAME::INDEX);
                    std::string routineCatalog = resultSet->getString(Routines::COLUMNS::ROUTINE_CATALOG::INDEX);
                    std::string routineSchema = resultSet->getString(Routines::COLUMNS::ROUTINE_SCHEMA::INDEX);
                    std::string routineName = resultSet->getString(Routines::COLUMNS::ROUTINE_NAME::INDEX);
                    std::string routineType = resultSet->getString(Routines::COLUMNS::ROUTINE_TYPE::INDEX);
                    std::string dataType = resultSet->getString(Routines::COLUMNS::DATA_TYPE::INDEX);
                    int characterMaximumLength = resultSet->getInt(Routines::COLUMNS::CHARACTER_MAXIMUM_LENGTH::INDEX);
                    int characterOctetLength = resultSet->getInt(Routines::COLUMNS::CHARACTER_OCTET_LENGTH::INDEX);
                    long numericPrecision = resultSet->getInt(Routines::COLUMNS::NUMERIC_PRECISION::INDEX);
                    int numericScale = resultSet->getInt(Routines::COLUMNS::NUMERIC_SCALE::INDEX);
                    long datetimePrecision = resultSet->getInt(Routines::COLUMNS::DATETIME_PRECISION::INDEX);
                    std::string characterSetName = resultSet->getString(Routines::COLUMNS::CHARACTER_SET_NAME::INDEX);
                    std::string collationName = resultSet->getString(Routines::COLUMNS::COLLATION_NAME::INDEX);
                    std::string dtdIdentifier = resultSet->getString(Routines::COLUMNS::DTD_IDENTIFIER::INDEX);
                    std::string routineBody = resultSet->getString(Routines::COLUMNS::ROUTINE_BODY::INDEX);
                    std::string routineDefinition = resultSet->getString(Routines::COLUMNS::ROUTINE_DEFINITION::INDEX);
                    std::string externalName = resultSet->getString(Routines::COLUMNS::EXTERNAL_NAME::INDEX);
                    std::string externalLanguage = resultSet->getString(Routines::COLUMNS::EXTERNAL_LANGUAGE::INDEX);
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
                    std::string databaseCollation = resultSet->getString(Routines::COLUMNS::DATABASE_COLLATION::INDEX);

                    routines.emplace_back(
                            Routines{specificName, routineCatalog, routineSchema, routineName, routineType, dataType,
                                     characterMaximumLength, characterOctetLength, numericPrecision, numericScale,
                                     datetimePrecision, characterSetName, collationName, dtdIdentifier, routineBody,
                                     routineDefinition, externalName, externalLanguage, parameterStyle, isDeterministic,
                                     sqlDataAccess, sqlPath, securityType, created, lastAltered, sqlMode,
                                     routineComment, definer, characterSetClient, collationConnection,
                                     databaseCollation});
                }

                resultSet->close();
                statement->close();

                return routines;
            }

/**
* Get all SCHEMATA
*/
            std::vector<Schemata> getSchemata() {

                std::vector<Schemata> schemata;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_SCHEMATA;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    std::string catalogName = resultSet->getString(Schemata::COLUMNS::CATALOG_NAME::INDEX);
                    std::string schemaName = resultSet->getString(Schemata::COLUMNS::SCHEMA_NAME::INDEX);
                    std::string defaultCharacterSetName = resultSet->getString(
                            Schemata::COLUMNS::DEFAULT_CHARACTER_SET_NAME::INDEX);
                    std::string defaultCollationName = resultSet->getString(
                            Schemata::COLUMNS::DEFAULT_COLLATION_NAME::INDEX);
                    std::string sqlPath = resultSet->getString(Schemata::COLUMNS::SQL_PATH::INDEX);

                    schemata.emplace_back(
                            Schemata{catalogName, schemaName, defaultCharacterSetName, defaultCollationName, sqlPath});
                }

                resultSet->close();
                statement->close();

                return schemata;
            }

/**
* Get all SCHEMA_PRIVILEGES
*/
            std::vector<SchemaPrivileges> getSchemaPrivileges() {

                std::vector<SchemaPrivileges> schemaPrivileges;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_SCHEMA_PRIVILEGES;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    std::string grantee = resultSet->getString(SchemaPrivileges::COLUMNS::GRANTEE::INDEX);
                    std::string tableCatalog = resultSet->getString(SchemaPrivileges::COLUMNS::TABLE_CATALOG::INDEX);
                    std::string tableSchema = resultSet->getString(SchemaPrivileges::COLUMNS::TABLE_SCHEMA::INDEX);
                    std::string privilegeType = resultSet->getString(SchemaPrivileges::COLUMNS::PRIVILEGE_TYPE::INDEX);
                    std::string isGrantable = resultSet->getString(SchemaPrivileges::COLUMNS::IS_GRANTABLE::INDEX);

                    schemaPrivileges.emplace_back(
                            SchemaPrivileges{grantee, tableCatalog, tableSchema, privilegeType, isGrantable});
                }

                resultSet->close();
                statement->close();

                return schemaPrivileges;
            }

/**
* Get all SESSION_STATUS
*/
            std::vector<SessionStatus> getSessionStatus() {

                std::vector<SessionStatus> sessionStatus;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_SESSION_STATUS;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    std::string variableName = resultSet->getString(SessionStatus::COLUMNS::VARIABLE_NAME::INDEX);
                    std::string variableValue = resultSet->getString(SessionStatus::COLUMNS::VARIABLE_VALUE::INDEX);

                    sessionStatus.emplace_back(SessionStatus{variableName, variableValue});
                }

                resultSet->close();
                statement->close();

                return sessionStatus;
            }

/**
* Get all SESSION_VARIABLES
*/
            std::vector<SessionVariables> getSessionVariables() {

                std::vector<SessionVariables> sessionVariables;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_SESSION_VARIABLES;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    std::string variableName = resultSet->getString(SessionVariables::COLUMNS::VARIABLE_NAME::INDEX);
                    std::string variableValue = resultSet->getString(SessionVariables::COLUMNS::VARIABLE_VALUE::INDEX);

                    sessionVariables.emplace_back(SessionVariables{variableName, variableValue});
                }

                resultSet->close();
                statement->close();

                return sessionVariables;
            }

/**
* Get all STATISTICS
*/
            std::vector<Statistics> getStatistics() {

                std::vector<Statistics> statistics;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_STATISTICS;

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
* Get all TABLES
*/
            std::vector<Tables> getTables() {

                std::vector<Tables> tables;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_TABLES;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

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

                    tables.emplace_back(
                            Tables{tableCatalog, tableSchema, tableName, tableType, engine, version, rowFormat,
                                   tableRows, avgRowLength, dataLength, maxDataLength, indexLength, dataFree,
                                   autoIncrement, createTime, updateTime, checkTime, tableCollation, checksum,
                                   createOptions, tableComment});
                }

                resultSet->close();
                statement->close();

                return tables;
            }

/**
* Get all TABLESPACES
*/
            std::vector<TableSpaces> getTableSpaces() {

                std::vector<TableSpaces> tablespaces;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_TABLESPACES;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    std::string tablespaceName = resultSet->getString(TableSpaces::COLUMNS::TABLESPACE_NAME::INDEX);
                    std::string engine = resultSet->getString(TableSpaces::COLUMNS::ENGINE::INDEX);
                    std::string tablespaceType = resultSet->getString(TableSpaces::COLUMNS::TABLESPACE_TYPE::INDEX);
                    std::string logfileGroupName = resultSet->getString(
                            TableSpaces::COLUMNS::LOGFILE_GROUP_NAME::INDEX);
                    long extentSize = resultSet->getInt(TableSpaces::COLUMNS::EXTENT_SIZE::INDEX);
                    long autoextendSize = resultSet->getInt(TableSpaces::COLUMNS::AUTOEXTEND_SIZE::INDEX);
                    long maximumSize = resultSet->getInt(TableSpaces::COLUMNS::MAXIMUM_SIZE::INDEX);
                    long nodegroupId = resultSet->getInt(TableSpaces::COLUMNS::NODEGROUP_ID::INDEX);
                    std::string tablespaceComment = resultSet->getString(
                            TableSpaces::COLUMNS::TABLESPACE_COMMENT::INDEX);

                    tablespaces.emplace_back(
                            TableSpaces{tablespaceName, engine, tablespaceType, logfileGroupName, extentSize,
                                        autoextendSize, maximumSize, nodegroupId, tablespaceComment});
                }

                resultSet->close();
                statement->close();

                return tablespaces;
            }

/**
* Get all TABLE_CONSTRAINTS
*/
            std::vector<TableConstraints> getTableConstraints() {

                std::vector<TableConstraints> tableConstraints;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_TABLE_CONSTRAINTS;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    std::string constraintCatalog = resultSet->getString(
                            TableConstraints::COLUMNS::CONSTRAINT_CATALOG::INDEX);
                    std::string constraintSchema = resultSet->getString(
                            TableConstraints::COLUMNS::CONSTRAINT_SCHEMA::INDEX);
                    std::string constraintName = resultSet->getString(
                            TableConstraints::COLUMNS::CONSTRAINT_NAME::INDEX);
                    std::string tableSchema = resultSet->getString(TableConstraints::COLUMNS::TABLE_SCHEMA::INDEX);
                    std::string tableName = resultSet->getString(TableConstraints::COLUMNS::TABLE_NAME::INDEX);
                    std::string constraintType = resultSet->getString(
                            TableConstraints::COLUMNS::CONSTRAINT_TYPE::INDEX);

                    tableConstraints.emplace_back(
                            TableConstraints{constraintCatalog, constraintSchema, constraintName, tableSchema,
                                             tableName, constraintType});
                }

                resultSet->close();
                statement->close();

                return tableConstraints;
            }

/**
* Get all TABLE_PRIVILEGES
*/
            std::vector<TablePrivileges> getTablePrivileges() {

                std::vector<TablePrivileges> tablePrivileges;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_TABLE_PRIVILEGES;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    std::string grantee = resultSet->getString(TablePrivileges::COLUMNS::GRANTEE::INDEX);
                    std::string tableCatalog = resultSet->getString(TablePrivileges::COLUMNS::TABLE_CATALOG::INDEX);
                    std::string tableSchema = resultSet->getString(TablePrivileges::COLUMNS::TABLE_SCHEMA::INDEX);
                    std::string tableName = resultSet->getString(TablePrivileges::COLUMNS::TABLE_NAME::INDEX);
                    std::string privilegeType = resultSet->getString(TablePrivileges::COLUMNS::PRIVILEGE_TYPE::INDEX);
                    std::string isGrantable = resultSet->getString(TablePrivileges::COLUMNS::IS_GRANTABLE::INDEX);

                    tablePrivileges.emplace_back(
                            TablePrivileges{grantee, tableCatalog, tableSchema, tableName, privilegeType, isGrantable});
                }

                resultSet->close();
                statement->close();

                return tablePrivileges;
            }

/**
* Get all TRIGGERS
*/
            std::vector<Triggers> getTriggers() {

                std::vector<Triggers> triggers;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_TRIGGERS;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    std::string triggerCatalog = resultSet->getString(Triggers::COLUMNS::TRIGGER_CATALOG::INDEX);
                    std::string triggerSchema = resultSet->getString(Triggers::COLUMNS::TRIGGER_SCHEMA::INDEX);
                    std::string triggerName = resultSet->getString(Triggers::COLUMNS::TRIGGER_NAME::INDEX);
                    std::string eventManipulation = resultSet->getString(Triggers::COLUMNS::EVENT_MANIPULATION::INDEX);
                    std::string eventObjectCatalog = resultSet->getString(
                            Triggers::COLUMNS::EVENT_OBJECT_CATALOG::INDEX);
                    std::string eventObjectSchema = resultSet->getString(Triggers::COLUMNS::EVENT_OBJECT_SCHEMA::INDEX);
                    std::string eventObjectTable = resultSet->getString(Triggers::COLUMNS::EVENT_OBJECT_TABLE::INDEX);
                    long actionOrder = resultSet->getInt(Triggers::COLUMNS::ACTION_ORDER::INDEX);
                    std::string actionCondition = resultSet->getString(Triggers::COLUMNS::ACTION_CONDITION::INDEX);
                    std::string actionStatement = resultSet->getString(Triggers::COLUMNS::ACTION_STATEMENT::INDEX);
                    std::string actionOrientation = resultSet->getString(Triggers::COLUMNS::ACTION_ORIENTATION::INDEX);
                    std::string actionTiming = resultSet->getString(Triggers::COLUMNS::ACTION_TIMING::INDEX);
                    std::string actionReferenceOldTable = resultSet->getString(
                            Triggers::COLUMNS::ACTION_REFERENCE_OLD_TABLE::INDEX);
                    std::string actionReferenceNewTable = resultSet->getString(
                            Triggers::COLUMNS::ACTION_REFERENCE_NEW_TABLE::INDEX);
                    std::string actionReferenceOldRow = resultSet->getString(
                            Triggers::COLUMNS::ACTION_REFERENCE_OLD_ROW::INDEX);
                    std::string actionReferenceNewRow = resultSet->getString(
                            Triggers::COLUMNS::ACTION_REFERENCE_NEW_ROW::INDEX);
                    std::string created = resultSet->getString(Triggers::COLUMNS::CREATED::INDEX);
                    std::string sqlMode = resultSet->getString(Triggers::COLUMNS::SQL_MODE::INDEX);
                    std::string definer = resultSet->getString(Triggers::COLUMNS::DEFINER::INDEX);
                    std::string characterSetClient = resultSet->getString(
                            Triggers::COLUMNS::CHARACTER_SET_CLIENT::INDEX);
                    std::string collationConnection = resultSet->getString(
                            Triggers::COLUMNS::COLLATION_CONNECTION::INDEX);
                    std::string databaseCollation = resultSet->getString(Triggers::COLUMNS::DATABASE_COLLATION::INDEX);

                    triggers.emplace_back(
                            Triggers{triggerCatalog, triggerSchema, triggerName, eventManipulation, eventObjectCatalog,
                                     eventObjectSchema, eventObjectTable, actionOrder, actionCondition, actionStatement,
                                     actionOrientation, actionTiming, actionReferenceOldTable, actionReferenceNewTable,
                                     actionReferenceOldRow, actionReferenceNewRow, created, sqlMode, definer,
                                     characterSetClient, collationConnection, databaseCollation});
                }

                resultSet->close();
                statement->close();

                return triggers;
            }

/**
* Get all USER_PRIVILEGES
*/
            std::vector<UserPrivileges> getUserPrivileges() {

                std::vector<UserPrivileges> userPrivileges;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_USER_PRIVILEGES;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    std::string grantee = resultSet->getString(UserPrivileges::COLUMNS::GRANTEE::INDEX);
                    std::string tableCatalog = resultSet->getString(UserPrivileges::COLUMNS::TABLE_CATALOG::INDEX);
                    std::string privilegeType = resultSet->getString(UserPrivileges::COLUMNS::PRIVILEGE_TYPE::INDEX);
                    std::string isGrantable = resultSet->getString(UserPrivileges::COLUMNS::IS_GRANTABLE::INDEX);

                    userPrivileges.emplace_back(UserPrivileges{grantee, tableCatalog, privilegeType, isGrantable});
                }

                resultSet->close();
                statement->close();

                return userPrivileges;
            }

/**
* Get all VIEWS
*/
            std::vector<Views> getViews() {

                std::vector<Views> views;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_VIEWS;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    std::string tableCatalog = resultSet->getString(Views::COLUMNS::TABLE_CATALOG::INDEX);
                    std::string tableSchema = resultSet->getString(Views::COLUMNS::TABLE_SCHEMA::INDEX);
                    std::string tableName = resultSet->getString(Views::COLUMNS::TABLE_NAME::INDEX);
                    std::string viewDefinition = resultSet->getString(Views::COLUMNS::VIEW_DEFINITION::INDEX);
                    std::string checkOption = resultSet->getString(Views::COLUMNS::CHECK_OPTION::INDEX);
                    std::string isUpdatable = resultSet->getString(Views::COLUMNS::IS_UPDATABLE::INDEX);
                    std::string definer = resultSet->getString(Views::COLUMNS::DEFINER::INDEX);
                    std::string securityType = resultSet->getString(Views::COLUMNS::SECURITY_TYPE::INDEX);
                    std::string characterSetClient = resultSet->getString(Views::COLUMNS::CHARACTER_SET_CLIENT::INDEX);
                    std::string collationConnection = resultSet->getString(Views::COLUMNS::COLLATION_CONNECTION::INDEX);

                    views.emplace_back(
                            Views{tableCatalog, tableSchema, tableName, viewDefinition, checkOption, isUpdatable,
                                  definer, securityType, characterSetClient, collationConnection});
                }

                resultSet->close();
                statement->close();

                return views;
            }

/**
* Get all INNODB_LOCKS
*/
            std::vector<InnoDbLocks> getInnoDbLocks() {

                std::vector<InnoDbLocks> innodbLocks;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_INNODB_LOCKS;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    std::string lockId = resultSet->getString(InnoDbLocks::COLUMNS::LOCK_ID::INDEX);
                    std::string lockTrxId = resultSet->getString(InnoDbLocks::COLUMNS::LOCK_TRX_ID::INDEX);
                    std::string lockMode = resultSet->getString(InnoDbLocks::COLUMNS::LOCK_MODE::INDEX);
                    std::string lockType = resultSet->getString(InnoDbLocks::COLUMNS::LOCK_TYPE::INDEX);
                    std::string lockTable = resultSet->getString(InnoDbLocks::COLUMNS::LOCK_TABLE::INDEX);
                    std::string lockIndex = resultSet->getString(InnoDbLocks::COLUMNS::LOCK_INDEX::INDEX);
                    long lockSpace = resultSet->getInt(InnoDbLocks::COLUMNS::LOCK_SPACE::INDEX);
                    long lockPage = resultSet->getInt(InnoDbLocks::COLUMNS::LOCK_PAGE::INDEX);
                    long lockRec = resultSet->getInt(InnoDbLocks::COLUMNS::LOCK_REC::INDEX);
                    std::string lockData = resultSet->getString(InnoDbLocks::COLUMNS::LOCK_DATA::INDEX);

                    innodbLocks.emplace_back(
                            InnoDbLocks{lockId, lockTrxId, lockMode, lockType, lockTable, lockIndex, lockSpace,
                                        lockPage, lockRec, lockData});
                }

                resultSet->close();
                statement->close();

                return innodbLocks;
            }

/**
* Get all INNODB_TRX
*/
            std::vector<InnoDbTrx> getInnoDbTrx() {

                std::vector<InnoDbTrx> innodbTrx;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_INNODB_TRX;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    std::string trxId = resultSet->getString(InnoDbTrx::COLUMNS::TRX_ID::INDEX);
                    std::string trxState = resultSet->getString(InnoDbTrx::COLUMNS::TRX_STATE::INDEX);
                    std::string trxStarted = resultSet->getString(InnoDbTrx::COLUMNS::TRX_STARTED::INDEX);
                    std::string trxRequestedLockId = resultSet->getString(
                            InnoDbTrx::COLUMNS::TRX_REQUESTED_LOCK_ID::INDEX);
                    std::string trxWaitStarted = resultSet->getString(InnoDbTrx::COLUMNS::TRX_WAIT_STARTED::INDEX);
                    long trxWeight = resultSet->getInt(InnoDbTrx::COLUMNS::TRX_WEIGHT::INDEX);
                    long trxMysqlThreadId = resultSet->getInt(InnoDbTrx::COLUMNS::TRX_MYSQL_THREAD_ID::INDEX);
                    std::string trxQuery = resultSet->getString(InnoDbTrx::COLUMNS::TRX_QUERY::INDEX);
                    std::string trxOperationState = resultSet->getString(
                            InnoDbTrx::COLUMNS::TRX_OPERATION_STATE::INDEX);
                    long trxTablesInUse = resultSet->getInt(InnoDbTrx::COLUMNS::TRX_TABLES_IN_USE::INDEX);
                    long trxTablesLocked = resultSet->getInt(InnoDbTrx::COLUMNS::TRX_TABLES_LOCKED::INDEX);
                    long trxLockStructs = resultSet->getInt(InnoDbTrx::COLUMNS::TRX_LOCK_STRUCTS::INDEX);
                    long trxLockMemoryBytes = resultSet->getInt(InnoDbTrx::COLUMNS::TRX_LOCK_MEMORY_BYTES::INDEX);
                    long trxRowsLocked = resultSet->getInt(InnoDbTrx::COLUMNS::TRX_ROWS_LOCKED::INDEX);
                    long trxRowsModified = resultSet->getInt(InnoDbTrx::COLUMNS::TRX_ROWS_MODIFIED::INDEX);
                    long trxConcurrencyTickets = resultSet->getInt(InnoDbTrx::COLUMNS::TRX_CONCURRENCY_TICKETS::INDEX);
                    std::string trxIsolationLevel = resultSet->getString(
                            InnoDbTrx::COLUMNS::TRX_ISOLATION_LEVEL::INDEX);
                    int trxUniqueChecks = resultSet->getInt(InnoDbTrx::COLUMNS::TRX_UNIQUE_CHECKS::INDEX);
                    int trxForeignKeyChecks = resultSet->getInt(InnoDbTrx::COLUMNS::TRX_FOREIGN_KEY_CHECKS::INDEX);
                    std::string trxLastForeignKeyError = resultSet->getString(
                            InnoDbTrx::COLUMNS::TRX_LAST_FOREIGN_KEY_ERROR::INDEX);
                    int trxAdaptiveHashLatched = resultSet->getInt(
                            InnoDbTrx::COLUMNS::TRX_ADAPTIVE_HASH_LATCHED::INDEX);
                    long trxAdaptiveHashTimeout = resultSet->getInt(
                            InnoDbTrx::COLUMNS::TRX_ADAPTIVE_HASH_TIMEOUT::INDEX);
                    int trxIsReadOnly = resultSet->getInt(InnoDbTrx::COLUMNS::TRX_IS_READ_ONLY::INDEX);
                    int trxAutocommitNonLocking = resultSet->getInt(
                            InnoDbTrx::COLUMNS::TRX_AUTOCOMMIT_NON_LOCKING::INDEX);

                    innodbTrx.emplace_back(
                            InnoDbTrx{trxId, trxState, trxStarted, trxRequestedLockId, trxWaitStarted, trxWeight,
                                      trxMysqlThreadId, trxQuery, trxOperationState, trxTablesInUse, trxTablesLocked,
                                      trxLockStructs, trxLockMemoryBytes, trxRowsLocked, trxRowsModified,
                                      trxConcurrencyTickets, trxIsolationLevel, trxUniqueChecks, trxForeignKeyChecks,
                                      trxLastForeignKeyError, trxAdaptiveHashLatched, trxAdaptiveHashTimeout,
                                      trxIsReadOnly, trxAutocommitNonLocking});
                }

                resultSet->close();
                statement->close();

                return innodbTrx;
            }

/**
* Get all INNODB_SYS_DATAFILES
*/
            std::vector<InnoDbSysDataFiles> getInnoDbSysDataFiles() {

                std::vector<InnoDbSysDataFiles> innodbSysDataFiles;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_INNODB_SYS_DATAFILES;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    int space = resultSet->getInt(InnoDbSysDataFiles::COLUMNS::SPACE::INDEX);
                    std::string path = resultSet->getString(InnoDbSysDataFiles::COLUMNS::PATH::INDEX);

                    innodbSysDataFiles.emplace_back(InnoDbSysDataFiles{space, path});
                }

                resultSet->close();
                statement->close();

                return innodbSysDataFiles;
            }

/**
* Get all INNODB_FT_CONFIG
*/
            std::vector<InnoDbFtConfig> getInnoDbFtConfig() {

                std::vector<InnoDbFtConfig> innodbFtConfig;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_INNODB_FT_CONFIG;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    std::string key = resultSet->getString(InnoDbFtConfig::COLUMNS::KEY::INDEX);
                    std::string value = resultSet->getString(InnoDbFtConfig::COLUMNS::VALUE::INDEX);

                    innodbFtConfig.emplace_back(InnoDbFtConfig{key, value});
                }

                resultSet->close();
                statement->close();

                return innodbFtConfig;
            }

/**
* Get all INNODB_SYS_VIRTUAL
*/
            std::vector<InnoDbSysVirtual> getInnoDbSysVirtual() {

                std::vector<InnoDbSysVirtual> innodbSysVirtual;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_INNODB_SYS_VIRTUAL;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    long tableId = resultSet->getInt(InnoDbSysVirtual::COLUMNS::TABLE_ID::INDEX);
                    int pos = resultSet->getInt(InnoDbSysVirtual::COLUMNS::POS::INDEX);
                    int basePos = resultSet->getInt(InnoDbSysVirtual::COLUMNS::BASE_POS::INDEX);

                    innodbSysVirtual.emplace_back(InnoDbSysVirtual{tableId, pos, basePos});
                }

                resultSet->close();
                statement->close();

                return innodbSysVirtual;
            }

/**
* Get all INNODB_CMP
*/
            std::vector<InnoDbCmp> getInnoDbCmp() {

                std::vector<InnoDbCmp> innodbCmp;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_INNODB_CMP;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    int pageSize = resultSet->getInt(InnoDbCmp::COLUMNS::PAGE_SIZE::INDEX);
                    int compressOps = resultSet->getInt(InnoDbCmp::COLUMNS::COMPRESS_OPS::INDEX);
                    int compressOpsOk = resultSet->getInt(InnoDbCmp::COLUMNS::COMPRESS_OPS_OK::INDEX);
                    int compressTime = resultSet->getInt(InnoDbCmp::COLUMNS::COMPRESS_TIME::INDEX);
                    int uncompressOps = resultSet->getInt(InnoDbCmp::COLUMNS::UNCOMPRESS_OPS::INDEX);
                    int uncompressTime = resultSet->getInt(InnoDbCmp::COLUMNS::UNCOMPRESS_TIME::INDEX);

                    innodbCmp.emplace_back(InnoDbCmp{pageSize, compressOps, compressOpsOk, compressTime, uncompressOps,
                                                     uncompressTime});
                }

                resultSet->close();
                statement->close();

                return innodbCmp;
            }

/**
* Get all INNODB_FT_BEING_DELETED
*/
            std::vector<InnoDbFtBeingDeleted> getInnoDbFtBeingDeleted() {

                std::vector<InnoDbFtBeingDeleted> innodbFtBeingDeleted;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_INNODB_FT_BEING_DELETED;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    long docId = resultSet->getInt(InnoDbFtBeingDeleted::COLUMNS::DOC_ID::INDEX);

                    innodbFtBeingDeleted.emplace_back(InnoDbFtBeingDeleted{docId});
                }

                resultSet->close();
                statement->close();

                return innodbFtBeingDeleted;
            }

/**
* Get all INNODB_CMP_RESET
*/
            std::vector<InnoDbCmpReset> getInnoDbCmpReset() {

                std::vector<InnoDbCmpReset> innodbCmpReset;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_INNODB_CMP_RESET;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    int pageSize = resultSet->getInt(InnoDbCmpReset::COLUMNS::PAGE_SIZE::INDEX);
                    int compressOps = resultSet->getInt(InnoDbCmpReset::COLUMNS::COMPRESS_OPS::INDEX);
                    int compressOpsOk = resultSet->getInt(InnoDbCmpReset::COLUMNS::COMPRESS_OPS_OK::INDEX);
                    int compressTime = resultSet->getInt(InnoDbCmpReset::COLUMNS::COMPRESS_TIME::INDEX);
                    int uncompressOps = resultSet->getInt(InnoDbCmpReset::COLUMNS::UNCOMPRESS_OPS::INDEX);
                    int uncompressTime = resultSet->getInt(InnoDbCmpReset::COLUMNS::UNCOMPRESS_TIME::INDEX);

                    innodbCmpReset.emplace_back(
                            InnoDbCmpReset{pageSize, compressOps, compressOpsOk, compressTime, uncompressOps,
                                           uncompressTime});
                }

                resultSet->close();
                statement->close();

                return innodbCmpReset;
            }

/**
* Get all INNODB_CMP_PER_INDEX
*/
            std::vector<InnoDbCmpPerIndex> getInnoDbCmpPerIndex() {

                std::vector<InnoDbCmpPerIndex> innodbCmpPerIndex;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_INNODB_CMP_PER_INDEX;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    std::string databaseName = resultSet->getString(InnoDbCmpPerIndex::COLUMNS::DATABASE_NAME::INDEX);
                    std::string tableName = resultSet->getString(InnoDbCmpPerIndex::COLUMNS::TABLE_NAME::INDEX);
                    std::string indexName = resultSet->getString(InnoDbCmpPerIndex::COLUMNS::INDEX_NAME::INDEX);
                    int compressOps = resultSet->getInt(InnoDbCmpPerIndex::COLUMNS::COMPRESS_OPS::INDEX);
                    int compressOpsOk = resultSet->getInt(InnoDbCmpPerIndex::COLUMNS::COMPRESS_OPS_OK::INDEX);
                    int compressTime = resultSet->getInt(InnoDbCmpPerIndex::COLUMNS::COMPRESS_TIME::INDEX);
                    int uncompressOps = resultSet->getInt(InnoDbCmpPerIndex::COLUMNS::UNCOMPRESS_OPS::INDEX);
                    int uncompressTime = resultSet->getInt(InnoDbCmpPerIndex::COLUMNS::UNCOMPRESS_TIME::INDEX);

                    innodbCmpPerIndex.emplace_back(
                            InnoDbCmpPerIndex{databaseName, tableName, indexName, compressOps, compressOpsOk,
                                              compressTime, uncompressOps, uncompressTime});
                }

                resultSet->close();
                statement->close();

                return innodbCmpPerIndex;
            }

/**
* Get all INNODB_CMPMEM_RESET
*/
            std::vector<InnoDbCmpMemReset> getInnoDbCmpMemReset() {

                std::vector<InnoDbCmpMemReset> innodbCmpMemReset;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_INNODB_CMPMEM_RESET;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    int pageSize = resultSet->getInt(InnoDbCmpMemReset::COLUMNS::PAGE_SIZE::INDEX);
                    int bufferPoolInstance = resultSet->getInt(InnoDbCmpMemReset::COLUMNS::BUFFER_POOL_INSTANCE::INDEX);
                    int pagesUsed = resultSet->getInt(InnoDbCmpMemReset::COLUMNS::PAGES_USED::INDEX);
                    int pagesFree = resultSet->getInt(InnoDbCmpMemReset::COLUMNS::PAGES_FREE::INDEX);
                    long relocationOps = resultSet->getInt(InnoDbCmpMemReset::COLUMNS::RELOCATION_OPS::INDEX);
                    int relocationTime = resultSet->getInt(InnoDbCmpMemReset::COLUMNS::RELOCATION_TIME::INDEX);

                    innodbCmpMemReset.emplace_back(
                            InnoDbCmpMemReset{pageSize, bufferPoolInstance, pagesUsed, pagesFree, relocationOps,
                                              relocationTime});
                }

                resultSet->close();
                statement->close();

                return innodbCmpMemReset;
            }

/**
* Get all INNODB_FT_DELETED
*/
            std::vector<InnoDbFtDeleted> getInnoDbFtDeleted() {

                std::vector<InnoDbFtDeleted> innodbFtDeleted;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_INNODB_FT_DELETED;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    long docId = resultSet->getInt(InnoDbFtDeleted::COLUMNS::DOC_ID::INDEX);

                    innodbFtDeleted.emplace_back(InnoDbFtDeleted{docId});
                }

                resultSet->close();
                statement->close();

                return innodbFtDeleted;
            }

            /**
            * Get all INNODB_BUFFER_PAGE_LRU
            */
            std::vector<InnoDbBufferPageLRU> getInnoDbBufferPageLRU() {

                std::vector<InnoDbBufferPageLRU> innodbBufferPageLRU;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_INNODB_BUFFER_PAGE_LRU;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    long poolId = resultSet->getInt(InnoDbBufferPageLRU::COLUMNS::POOL_ID::INDEX);
                    long lruPosition = resultSet->getInt(InnoDbBufferPageLRU::COLUMNS::LRU_POSITION::INDEX);
                    long space = resultSet->getInt(InnoDbBufferPageLRU::COLUMNS::SPACE::INDEX);
                    long pageNumber = resultSet->getInt(InnoDbBufferPageLRU::COLUMNS::PAGE_NUMBER::INDEX);
                    std::string pageType = resultSet->getString(InnoDbBufferPageLRU::COLUMNS::PAGE_TYPE::INDEX);
                    long flushType = resultSet->getInt(InnoDbBufferPageLRU::COLUMNS::FLUSH_TYPE::INDEX);
                    long fixCount = resultSet->getInt(InnoDbBufferPageLRU::COLUMNS::FIX_COUNT::INDEX);
                    std::string isHashed = resultSet->getString(InnoDbBufferPageLRU::COLUMNS::IS_HASHED::INDEX);
                    long newestModification = resultSet->getInt(
                            InnoDbBufferPageLRU::COLUMNS::NEWEST_MODIFICATION::INDEX);
                    long oldestModification = resultSet->getInt(
                            InnoDbBufferPageLRU::COLUMNS::OLDEST_MODIFICATION::INDEX);
                    long accessTime = resultSet->getInt(InnoDbBufferPageLRU::COLUMNS::ACCESS_TIME::INDEX);
                    std::string tableName = resultSet->getString(InnoDbBufferPageLRU::COLUMNS::TABLE_NAME::INDEX);
                    std::string indexName = resultSet->getString(InnoDbBufferPageLRU::COLUMNS::INDEX_NAME::INDEX);
                    long numberRecords = resultSet->getInt(InnoDbBufferPageLRU::COLUMNS::NUMBER_RECORDS::INDEX);
                    long dataSize = resultSet->getInt(InnoDbBufferPageLRU::COLUMNS::DATA_SIZE::INDEX);
                    long compressedSize = resultSet->getInt(InnoDbBufferPageLRU::COLUMNS::COMPRESSED_SIZE::INDEX);
                    std::string compressed = resultSet->getString(InnoDbBufferPageLRU::COLUMNS::COMPRESSED::INDEX);
                    std::string ioFix = resultSet->getString(InnoDbBufferPageLRU::COLUMNS::IO_FIX::INDEX);
                    std::string isOld = resultSet->getString(InnoDbBufferPageLRU::COLUMNS::IS_OLD::INDEX);
                    long freePageClock = resultSet->getInt(InnoDbBufferPageLRU::COLUMNS::FREE_PAGE_CLOCK::INDEX);

                    innodbBufferPageLRU.emplace_back(
                            InnoDbBufferPageLRU{poolId, lruPosition, space, pageNumber, pageType, flushType, fixCount,
                                                isHashed, newestModification, oldestModification, accessTime, tableName,
                                                indexName, numberRecords, dataSize, compressedSize, compressed, ioFix,
                                                isOld, freePageClock});
                }

                resultSet->close();
                statement->close();

                return innodbBufferPageLRU;
            }

/**
* Get all INNODB_LOCK_WAITS
*/
            std::vector<InnoDbLockWaits> getInnoDbLockWaits() {

                std::vector<InnoDbLockWaits> innodbLockWaits;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_INNODB_LOCK_WAITS;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    std::string requestingTrxId = resultSet->getString(
                            InnoDbLockWaits::COLUMNS::REQUESTING_TRX_ID::INDEX);
                    std::string requestedLockId = resultSet->getString(
                            InnoDbLockWaits::COLUMNS::REQUESTED_LOCK_ID::INDEX);
                    std::string blockingTrxId = resultSet->getString(InnoDbLockWaits::COLUMNS::BLOCKING_TRX_ID::INDEX);
                    std::string blockingLockId = resultSet->getString(
                            InnoDbLockWaits::COLUMNS::BLOCKING_LOCK_ID::INDEX);

                    innodbLockWaits.emplace_back(
                            InnoDbLockWaits{requestingTrxId, requestedLockId, blockingTrxId, blockingLockId});
                }

                resultSet->close();
                statement->close();

                return innodbLockWaits;
            }

/**
* Get all INNODB_TEMP_TABLE_INFO
*/
            std::vector<InnoDbTempTableInfo> getInnoDbTempTableInfo() {

                std::vector<InnoDbTempTableInfo> innodbTempTableInfo;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_INNODB_TEMP_TABLE_INFO;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    long tableId = resultSet->getInt(InnoDbTempTableInfo::COLUMNS::TABLE_ID::INDEX);
                    std::string name = resultSet->getString(InnoDbTempTableInfo::COLUMNS::NAME::INDEX);
                    int nCols = resultSet->getInt(InnoDbTempTableInfo::COLUMNS::N_COLS::INDEX);
                    int space = resultSet->getInt(InnoDbTempTableInfo::COLUMNS::SPACE::INDEX);
                    std::string perTableTablespace = resultSet->getString(
                            InnoDbTempTableInfo::COLUMNS::PER_TABLE_TABLESPACE::INDEX);
                    std::string isCompressed = resultSet->getString(InnoDbTempTableInfo::COLUMNS::IS_COMPRESSED::INDEX);

                    innodbTempTableInfo.emplace_back(
                            InnoDbTempTableInfo{tableId, name, nCols, space, perTableTablespace, isCompressed});
                }

                resultSet->close();
                statement->close();

                return innodbTempTableInfo;
            }

/**
* Get all INNODB_SYS_INDEXES
*/
            std::vector<InnoDbSysIndexes> getInnoDbSysIndexes() {

                std::vector<InnoDbSysIndexes> innodbSysIndexes;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_INNODB_SYS_INDEXES;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    long indexId = resultSet->getInt(InnoDbSysIndexes::COLUMNS::INDEX_ID::INDEX);
                    std::string name = resultSet->getString(InnoDbSysIndexes::COLUMNS::NAME::INDEX);
                    long tableId = resultSet->getInt(InnoDbSysIndexes::COLUMNS::TABLE_ID::INDEX);
                    int type = resultSet->getInt(InnoDbSysIndexes::COLUMNS::TYPE::INDEX);
                    int nFields = resultSet->getInt(InnoDbSysIndexes::COLUMNS::N_FIELDS::INDEX);
                    int pageNo = resultSet->getInt(InnoDbSysIndexes::COLUMNS::PAGE_NO::INDEX);
                    int space = resultSet->getInt(InnoDbSysIndexes::COLUMNS::SPACE::INDEX);
                    int mergeThreshold = resultSet->getInt(InnoDbSysIndexes::COLUMNS::MERGE_THRESHOLD::INDEX);

                    innodbSysIndexes.emplace_back(
                            InnoDbSysIndexes{indexId, name, tableId, type, nFields, pageNo, space, mergeThreshold});
                }

                resultSet->close();
                statement->close();

                return innodbSysIndexes;
            }

/**
* Get all INNODB_SYS_TABLES
*/
            std::vector<InnoDbSysTables> getInnoDbSysTables() {

                std::vector<InnoDbSysTables> innodbSysTables;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_INNODB_SYS_TABLES;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    long tableId = resultSet->getInt(InnoDbSysTables::COLUMNS::TABLE_ID::INDEX);
                    std::string name = resultSet->getString(InnoDbSysTables::COLUMNS::NAME::INDEX);
                    int flag = resultSet->getInt(InnoDbSysTables::COLUMNS::FLAG::INDEX);
                    int nCols = resultSet->getInt(InnoDbSysTables::COLUMNS::N_COLS::INDEX);
                    int space = resultSet->getInt(InnoDbSysTables::COLUMNS::SPACE::INDEX);
                    std::string fileFormat = resultSet->getString(InnoDbSysTables::COLUMNS::FILE_FORMAT::INDEX);
                    std::string rowFormat = resultSet->getString(InnoDbSysTables::COLUMNS::ROW_FORMAT::INDEX);
                    int zipPageSize = resultSet->getInt(InnoDbSysTables::COLUMNS::ZIP_PAGE_SIZE::INDEX);
                    std::string spaceType = resultSet->getString(InnoDbSysTables::COLUMNS::SPACE_TYPE::INDEX);

                    innodbSysTables.emplace_back(
                            InnoDbSysTables{tableId, name, flag, nCols, space, fileFormat, rowFormat, zipPageSize,
                                            spaceType});
                }

                resultSet->close();
                statement->close();

                return innodbSysTables;
            }

/**
* Get all INNODB_SYS_FIELDS
*/
            std::vector<InnoDbSysFields> getInnoDbSysFields() {

                std::vector<InnoDbSysFields> innodbSysFields;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_INNODB_SYS_FIELDS;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    long indexId = resultSet->getInt(InnoDbSysFields::COLUMNS::INDEX_ID::INDEX);
                    std::string name = resultSet->getString(InnoDbSysFields::COLUMNS::NAME::INDEX);
                    int pos = resultSet->getInt(InnoDbSysFields::COLUMNS::POS::INDEX);

                    innodbSysFields.emplace_back(InnoDbSysFields{indexId, name, pos});
                }

                resultSet->close();
                statement->close();

                return innodbSysFields;
            }

/**
* Get all INNODB_CMP_PER_INDEX_RESET
*/
            std::vector<InnoDbCmpPerIndexReset> getInnoDbCmpPerIndexReset() {

                std::vector<InnoDbCmpPerIndexReset> innodbCmpPerIndexReset;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_INNODB_CMP_PER_INDEX_RESET;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    std::string databaseName = resultSet->getString(
                            InnoDbCmpPerIndexReset::COLUMNS::DATABASE_NAME::INDEX);
                    std::string tableName = resultSet->getString(InnoDbCmpPerIndexReset::COLUMNS::TABLE_NAME::INDEX);
                    std::string indexName = resultSet->getString(InnoDbCmpPerIndexReset::COLUMNS::INDEX_NAME::INDEX);
                    int compressOps = resultSet->getInt(InnoDbCmpPerIndexReset::COLUMNS::COMPRESS_OPS::INDEX);
                    int compressOpsOk = resultSet->getInt(InnoDbCmpPerIndexReset::COLUMNS::COMPRESS_OPS_OK::INDEX);
                    int compressTime = resultSet->getInt(InnoDbCmpPerIndexReset::COLUMNS::COMPRESS_TIME::INDEX);
                    int uncompressOps = resultSet->getInt(InnoDbCmpPerIndexReset::COLUMNS::UNCOMPRESS_OPS::INDEX);
                    int uncompressTime = resultSet->getInt(InnoDbCmpPerIndexReset::COLUMNS::UNCOMPRESS_TIME::INDEX);

                    innodbCmpPerIndexReset.emplace_back(
                            InnoDbCmpPerIndexReset{databaseName, tableName, indexName, compressOps, compressOpsOk,
                                                   compressTime, uncompressOps, uncompressTime});
                }

                resultSet->close();
                statement->close();

                return innodbCmpPerIndexReset;
            }

/**
* Get all INNODB_BUFFER_PAGE
*/
            std::vector<InnoDbBufferPage> getInnoDbBufferPage() {

                std::vector<InnoDbBufferPage> innodbBufferPage;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_INNODB_BUFFER_PAGE;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    long poolId = resultSet->getInt(InnoDbBufferPage::COLUMNS::POOL_ID::INDEX);
                    long blockId = resultSet->getInt(InnoDbBufferPage::COLUMNS::BLOCK_ID::INDEX);
                    long space = resultSet->getInt(InnoDbBufferPage::COLUMNS::SPACE::INDEX);
                    long pageNumber = resultSet->getInt(InnoDbBufferPage::COLUMNS::PAGE_NUMBER::INDEX);
                    std::string pageType = resultSet->getString(InnoDbBufferPage::COLUMNS::PAGE_TYPE::INDEX);
                    long flushType = resultSet->getInt(InnoDbBufferPage::COLUMNS::FLUSH_TYPE::INDEX);
                    long fixCount = resultSet->getInt(InnoDbBufferPage::COLUMNS::FIX_COUNT::INDEX);
                    std::string isHashed = resultSet->getString(InnoDbBufferPage::COLUMNS::IS_HASHED::INDEX);
                    long newestModification = resultSet->getInt(InnoDbBufferPage::COLUMNS::NEWEST_MODIFICATION::INDEX);
                    long oldestModification = resultSet->getInt(InnoDbBufferPage::COLUMNS::OLDEST_MODIFICATION::INDEX);
                    long accessTime = resultSet->getInt(InnoDbBufferPage::COLUMNS::ACCESS_TIME::INDEX);
                    std::string tableName = resultSet->getString(InnoDbBufferPage::COLUMNS::TABLE_NAME::INDEX);
                    std::string indexName = resultSet->getString(InnoDbBufferPage::COLUMNS::INDEX_NAME::INDEX);
                    long numberRecords = resultSet->getInt(InnoDbBufferPage::COLUMNS::NUMBER_RECORDS::INDEX);
                    long dataSize = resultSet->getInt(InnoDbBufferPage::COLUMNS::DATA_SIZE::INDEX);
                    long compressedSize = resultSet->getInt(InnoDbBufferPage::COLUMNS::COMPRESSED_SIZE::INDEX);
                    std::string pageState = resultSet->getString(InnoDbBufferPage::COLUMNS::PAGE_STATE::INDEX);
                    std::string ioFix = resultSet->getString(InnoDbBufferPage::COLUMNS::IO_FIX::INDEX);
                    std::string isOld = resultSet->getString(InnoDbBufferPage::COLUMNS::IS_OLD::INDEX);
                    long freePageClock = resultSet->getInt(InnoDbBufferPage::COLUMNS::FREE_PAGE_CLOCK::INDEX);

                    innodbBufferPage.emplace_back(
                            InnoDbBufferPage{poolId, blockId, space, pageNumber, pageType, flushType, fixCount,
                                             isHashed, newestModification, oldestModification, accessTime, tableName,
                                             indexName, numberRecords, dataSize, compressedSize, pageState, ioFix,
                                             isOld, freePageClock});
                }

                resultSet->close();
                statement->close();

                return innodbBufferPage;
            }

/**
* Get all INNODB_FT_DEFAULT_STOPWORD
*/
            std::vector<InnoDbFtDefaultStopWord> getInnoDbFtDefaultStopWord() {

                std::vector<InnoDbFtDefaultStopWord> innodbFtDefaultStopword;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_INNODB_FT_DEFAULT_STOPWORD;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    std::string value = resultSet->getString(InnoDbFtDefaultStopWord::COLUMNS::VALUE::INDEX);

                    innodbFtDefaultStopword.emplace_back(InnoDbFtDefaultStopWord{value});
                }

                resultSet->close();
                statement->close();

                return innodbFtDefaultStopword;
            }

            /**
            * Get all INNODB_FT_INDEX_TABLE
            */
            std::vector<InnoDbFtIndexTable> getInnoDbFtIndexTable() {

                std::vector<InnoDbFtIndexTable> innodbFtIndexTable;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_INNODB_FT_INDEX_TABLE;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    std::string word = resultSet->getString(InnoDbFtIndexTable::COLUMNS::WORD::INDEX);
                    long firstDocId = resultSet->getInt(InnoDbFtIndexTable::COLUMNS::FIRST_DOC_ID::INDEX);
                    long lastDocId = resultSet->getInt(InnoDbFtIndexTable::COLUMNS::LAST_DOC_ID::INDEX);
                    long docCount = resultSet->getInt(InnoDbFtIndexTable::COLUMNS::DOC_COUNT::INDEX);
                    long docId = resultSet->getInt(InnoDbFtIndexTable::COLUMNS::DOC_ID::INDEX);
                    long position = resultSet->getInt(InnoDbFtIndexTable::COLUMNS::POSITION::INDEX);

                    innodbFtIndexTable.emplace_back(
                            InnoDbFtIndexTable{word, firstDocId, lastDocId, docCount, docId, position});
                }

                resultSet->close();
                statement->close();

                return innodbFtIndexTable;
            }

/**
* Get all INNODB_FT_INDEX_CACHE
*/
            std::vector<InnoDbFtIndexCache> getInnoDbFtIndexCache() {

                std::vector<InnoDbFtIndexCache> innodbFtIndexCache;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_INNODB_FT_INDEX_CACHE;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    std::string word = resultSet->getString(InnoDbFtIndexCache::COLUMNS::WORD::INDEX);
                    long firstDocId = resultSet->getInt(InnoDbFtIndexCache::COLUMNS::FIRST_DOC_ID::INDEX);
                    long lastDocId = resultSet->getInt(InnoDbFtIndexCache::COLUMNS::LAST_DOC_ID::INDEX);
                    long docCount = resultSet->getInt(InnoDbFtIndexCache::COLUMNS::DOC_COUNT::INDEX);
                    long docId = resultSet->getInt(InnoDbFtIndexCache::COLUMNS::DOC_ID::INDEX);
                    long position = resultSet->getInt(InnoDbFtIndexCache::COLUMNS::POSITION::INDEX);

                    innodbFtIndexCache.emplace_back(
                            InnoDbFtIndexCache{word, firstDocId, lastDocId, docCount, docId, position});
                }

                resultSet->close();
                statement->close();

                return innodbFtIndexCache;
            }

/**
* Get all INNODB_SYS_TABLESPACES
*/
            std::vector<InnoDbSysTableSpaces> getInnoDbSysTableSpaces() {

                std::vector<InnoDbSysTableSpaces> innodbSysTableSpaces;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_INNODB_SYS_TABLESPACES;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    int space = resultSet->getInt(InnoDbSysTableSpaces::COLUMNS::SPACE::INDEX);
                    std::string name = resultSet->getString(InnoDbSysTableSpaces::COLUMNS::NAME::INDEX);
                    int flag = resultSet->getInt(InnoDbSysTableSpaces::COLUMNS::FLAG::INDEX);
                    std::string fileFormat = resultSet->getString(InnoDbSysTableSpaces::COLUMNS::FILE_FORMAT::INDEX);
                    std::string rowFormat = resultSet->getString(InnoDbSysTableSpaces::COLUMNS::ROW_FORMAT::INDEX);
                    int pageSize = resultSet->getInt(InnoDbSysTableSpaces::COLUMNS::PAGE_SIZE::INDEX);
                    int zipPageSize = resultSet->getInt(InnoDbSysTableSpaces::COLUMNS::ZIP_PAGE_SIZE::INDEX);
                    std::string spaceType = resultSet->getString(InnoDbSysTableSpaces::COLUMNS::SPACE_TYPE::INDEX);
                    int fsBlockSize = resultSet->getInt(InnoDbSysTableSpaces::COLUMNS::FS_BLOCK_SIZE::INDEX);
                    long fileSize = resultSet->getInt(InnoDbSysTableSpaces::COLUMNS::FILE_SIZE::INDEX);
                    long allocatedSize = resultSet->getInt(InnoDbSysTableSpaces::COLUMNS::ALLOCATED_SIZE::INDEX);

                    innodbSysTableSpaces.emplace_back(
                            InnoDbSysTableSpaces{space, name, flag, fileFormat, rowFormat, pageSize, zipPageSize,
                                                 spaceType, fsBlockSize, fileSize, allocatedSize});
                }

                resultSet->close();
                statement->close();

                return innodbSysTableSpaces;
            }

/**
* Get all INNODB_METRICS
*/
            std::vector<InnoDbMetrics> getInnoDbMetrics() {

                std::vector<InnoDbMetrics> innodbMetrics;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_INNODB_METRICS;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    std::string name = resultSet->getString(InnoDbMetrics::COLUMNS::NAME::INDEX);
                    std::string subsystem = resultSet->getString(InnoDbMetrics::COLUMNS::SUBSYSTEM::INDEX);
                    long count = resultSet->getInt(InnoDbMetrics::COLUMNS::COUNT::INDEX);
                    long maxCount = resultSet->getInt(InnoDbMetrics::COLUMNS::MAX_COUNT::INDEX);
                    long minCount = resultSet->getInt(InnoDbMetrics::COLUMNS::MIN_COUNT::INDEX);
                    long double avgCount = resultSet->getDouble(InnoDbMetrics::COLUMNS::AVG_COUNT::INDEX);
                    long countReset = resultSet->getInt(InnoDbMetrics::COLUMNS::COUNT_RESET::INDEX);
                    long maxCountReset = resultSet->getInt(InnoDbMetrics::COLUMNS::MAX_COUNT_RESET::INDEX);
                    long minCountReset = resultSet->getInt(InnoDbMetrics::COLUMNS::MIN_COUNT_RESET::INDEX);
                    long double avgCountReset = resultSet->getDouble(InnoDbMetrics::COLUMNS::AVG_COUNT_RESET::INDEX);
                    std::string timeEnabled = resultSet->getString(InnoDbMetrics::COLUMNS::TIME_ENABLED::INDEX);
                    std::string timeDisabled = resultSet->getString(InnoDbMetrics::COLUMNS::TIME_DISABLED::INDEX);
                    long timeElapsed = resultSet->getInt(InnoDbMetrics::COLUMNS::TIME_ELAPSED::INDEX);
                    std::string timeReset = resultSet->getString(InnoDbMetrics::COLUMNS::TIME_RESET::INDEX);
                    std::string status = resultSet->getString(InnoDbMetrics::COLUMNS::STATUS::INDEX);
                    std::string type = resultSet->getString(InnoDbMetrics::COLUMNS::TYPE::INDEX);
                    std::string comment = resultSet->getString(InnoDbMetrics::COLUMNS::COMMENT::INDEX);

                    innodbMetrics.emplace_back(
                            InnoDbMetrics{name, subsystem, count, maxCount, minCount, avgCount, countReset,
                                          maxCountReset, minCountReset, avgCountReset, timeEnabled, timeDisabled,
                                          timeElapsed, timeReset, status, type, comment});
                }

                resultSet->close();
                statement->close();

                return innodbMetrics;
            }

/**
* Get all INNODB_SYS_FOREIGN_COLS
*/
            std::vector<InnoDbSysForeignCols> getInnoDbSysForeignCols() {

                std::vector<InnoDbSysForeignCols> innodbSysForeignCols;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_INNODB_SYS_FOREIGN_COLS;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    std::string id = resultSet->getString(InnoDbSysForeignCols::COLUMNS::ID::INDEX);
                    std::string forColName = resultSet->getString(InnoDbSysForeignCols::COLUMNS::FOR_COL_NAME::INDEX);
                    std::string refColName = resultSet->getString(InnoDbSysForeignCols::COLUMNS::REF_COL_NAME::INDEX);
                    int pos = resultSet->getInt(InnoDbSysForeignCols::COLUMNS::POS::INDEX);

                    innodbSysForeignCols.emplace_back(InnoDbSysForeignCols{id, forColName, refColName, pos});
                }

                resultSet->close();
                statement->close();

                return innodbSysForeignCols;
            }

/**
* Get all INNODB_CMPMEM
*/
            std::vector<InnoDbCmpMem> getInnoDbCmpMem() {

                std::vector<InnoDbCmpMem> innodbCmpMem;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_INNODB_CMPMEM;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    int pageSize = resultSet->getInt(InnoDbCmpMem::COLUMNS::PAGE_SIZE::INDEX);
                    int bufferPoolInstance = resultSet->getInt(InnoDbCmpMem::COLUMNS::BUFFER_POOL_INSTANCE::INDEX);
                    int pagesUsed = resultSet->getInt(InnoDbCmpMem::COLUMNS::PAGES_USED::INDEX);
                    int pagesFree = resultSet->getInt(InnoDbCmpMem::COLUMNS::PAGES_FREE::INDEX);
                    long relocationOps = resultSet->getInt(InnoDbCmpMem::COLUMNS::RELOCATION_OPS::INDEX);
                    int relocationTime = resultSet->getInt(InnoDbCmpMem::COLUMNS::RELOCATION_TIME::INDEX);

                    innodbCmpMem.emplace_back(
                            InnoDbCmpMem{pageSize, bufferPoolInstance, pagesUsed, pagesFree, relocationOps,
                                         relocationTime});
                }

                resultSet->close();
                statement->close();

                return innodbCmpMem;
            }

/**
* Get all INNODB_BUFFER_POOL_STATS
*/
            std::vector<InnoDbBufferPoolStats> getInnoDbBufferPoolStats() {

                std::vector<InnoDbBufferPoolStats> innodbBufferPoolStats;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_INNODB_BUFFER_POOL_STATS;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    long poolId = resultSet->getInt(InnoDbBufferPoolStats::COLUMNS::POOL_ID::INDEX);
                    long poolSize = resultSet->getInt(InnoDbBufferPoolStats::COLUMNS::POOL_SIZE::INDEX);
                    long freeBuffers = resultSet->getInt(InnoDbBufferPoolStats::COLUMNS::FREE_BUFFERS::INDEX);
                    long databasePages = resultSet->getInt(InnoDbBufferPoolStats::COLUMNS::DATABASE_PAGES::INDEX);
                    long oldDatabasePages = resultSet->getInt(
                            InnoDbBufferPoolStats::COLUMNS::OLD_DATABASE_PAGES::INDEX);
                    long modifiedDatabasePages = resultSet->getInt(
                            InnoDbBufferPoolStats::COLUMNS::MODIFIED_DATABASE_PAGES::INDEX);
                    long pendingDecompress = resultSet->getInt(
                            InnoDbBufferPoolStats::COLUMNS::PENDING_DECOMPRESS::INDEX);
                    long pendingReads = resultSet->getInt(InnoDbBufferPoolStats::COLUMNS::PENDING_READS::INDEX);
                    long pendingFlushLRU = resultSet->getInt(InnoDbBufferPoolStats::COLUMNS::PENDING_FLUSH_LRU::INDEX);
                    long pendingFlushList = resultSet->getInt(
                            InnoDbBufferPoolStats::COLUMNS::PENDING_FLUSH_LIST::INDEX);
                    long pagesMadeYoung = resultSet->getInt(InnoDbBufferPoolStats::COLUMNS::PAGES_MADE_YOUNG::INDEX);
                    long pagesNotMadeYoung = resultSet->getInt(
                            InnoDbBufferPoolStats::COLUMNS::PAGES_NOT_MADE_YOUNG::INDEX);
                    long double pagesMadeYoungRate = resultSet->getDouble(
                            InnoDbBufferPoolStats::COLUMNS::PAGES_MADE_YOUNG_RATE::INDEX);
                    long double pagesMadeNotYoungRate = resultSet->getDouble(
                            InnoDbBufferPoolStats::COLUMNS::PAGES_MADE_NOT_YOUNG_RATE::INDEX);
                    long numberPagesRead = resultSet->getInt(InnoDbBufferPoolStats::COLUMNS::NUMBER_PAGES_READ::INDEX);
                    long numberPagesCreated = resultSet->getInt(
                            InnoDbBufferPoolStats::COLUMNS::NUMBER_PAGES_CREATED::INDEX);
                    long numberPagesWritten = resultSet->getInt(
                            InnoDbBufferPoolStats::COLUMNS::NUMBER_PAGES_WRITTEN::INDEX);
                    long double pagesReadRate = resultSet->getDouble(
                            InnoDbBufferPoolStats::COLUMNS::PAGES_READ_RATE::INDEX);
                    long double pagesCreateRate = resultSet->getDouble(
                            InnoDbBufferPoolStats::COLUMNS::PAGES_CREATE_RATE::INDEX);
                    long double pagesWrittenRate = resultSet->getDouble(
                            InnoDbBufferPoolStats::COLUMNS::PAGES_WRITTEN_RATE::INDEX);
                    long numberPagesGet = resultSet->getInt(InnoDbBufferPoolStats::COLUMNS::NUMBER_PAGES_GET::INDEX);
                    long hitRate = resultSet->getInt(InnoDbBufferPoolStats::COLUMNS::HIT_RATE::INDEX);
                    long youngMakePerThousandGets = resultSet->getInt(
                            InnoDbBufferPoolStats::COLUMNS::YOUNG_MAKE_PER_THOUSAND_GETS::INDEX);
                    long notYoungMakePerThousandGets = resultSet->getInt(
                            InnoDbBufferPoolStats::COLUMNS::NOT_YOUNG_MAKE_PER_THOUSAND_GETS::INDEX);
                    long numberPagesReadAhead = resultSet->getInt(
                            InnoDbBufferPoolStats::COLUMNS::NUMBER_PAGES_READ_AHEAD::INDEX);
                    long numberReadAheadEvicted = resultSet->getInt(
                            InnoDbBufferPoolStats::COLUMNS::NUMBER_READ_AHEAD_EVICTED::INDEX);
                    long double readAheadRate = resultSet->getDouble(
                            InnoDbBufferPoolStats::COLUMNS::READ_AHEAD_RATE::INDEX);
                    long double readAheadEvictedRate = resultSet->getDouble(
                            InnoDbBufferPoolStats::COLUMNS::READ_AHEAD_EVICTED_RATE::INDEX);
                    long lruIoTotal = resultSet->getInt(InnoDbBufferPoolStats::COLUMNS::LRU_IO_TOTAL::INDEX);
                    long lruIoCurrent = resultSet->getInt(InnoDbBufferPoolStats::COLUMNS::LRU_IO_CURRENT::INDEX);
                    long uncompressTotal = resultSet->getInt(InnoDbBufferPoolStats::COLUMNS::UNCOMPRESS_TOTAL::INDEX);
                    long uncompressCurrent = resultSet->getInt(
                            InnoDbBufferPoolStats::COLUMNS::UNCOMPRESS_CURRENT::INDEX);

                    innodbBufferPoolStats.emplace_back(
                            InnoDbBufferPoolStats{poolId, poolSize, freeBuffers, databasePages, oldDatabasePages,
                                                  modifiedDatabasePages, pendingDecompress, pendingReads,
                                                  pendingFlushLRU, pendingFlushList, pagesMadeYoung, pagesNotMadeYoung,
                                                  pagesMadeYoungRate, pagesMadeNotYoungRate, numberPagesRead,
                                                  numberPagesCreated, numberPagesWritten, pagesReadRate,
                                                  pagesCreateRate, pagesWrittenRate, numberPagesGet, hitRate,
                                                  youngMakePerThousandGets, notYoungMakePerThousandGets,
                                                  numberPagesReadAhead, numberReadAheadEvicted, readAheadRate,
                                                  readAheadEvictedRate, lruIoTotal, lruIoCurrent, uncompressTotal,
                                                  uncompressCurrent});
                }

                resultSet->close();
                statement->close();

                return innodbBufferPoolStats;
            }

/**
* Get all INNODB_SYS_COLUMNS
*/
            std::vector<InnoDbSysColumns> getInnoDbSysColumns() {

                std::vector<InnoDbSysColumns> innodbSysColumns;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_INNODB_SYS_COLUMNS;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    long tableId = resultSet->getInt(InnoDbSysColumns::COLUMNS::TABLE_ID::INDEX);
                    std::string name = resultSet->getString(InnoDbSysColumns::COLUMNS::NAME::INDEX);
                    long pos = resultSet->getInt(InnoDbSysColumns::COLUMNS::POS::INDEX);
                    int mtype = resultSet->getInt(InnoDbSysColumns::COLUMNS::MTYPE::INDEX);
                    int prtype = resultSet->getInt(InnoDbSysColumns::COLUMNS::PRTYPE::INDEX);
                    int len = resultSet->getInt(InnoDbSysColumns::COLUMNS::LEN::INDEX);

                    innodbSysColumns.emplace_back(InnoDbSysColumns{tableId, name, pos, mtype, prtype, len});
                }

                resultSet->close();
                statement->close();

                return innodbSysColumns;
            }

/**
* Get all INNODB_SYS_FOREIGN
*/
            std::vector<InnoDbSysForeign> getInnoDbSysForeign() {

                std::vector<InnoDbSysForeign> innodbSysForeign;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_INNODB_SYS_FOREIGN;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    std::string id = resultSet->getString(InnoDbSysForeign::COLUMNS::ID::INDEX);
                    std::string forName = resultSet->getString(InnoDbSysForeign::COLUMNS::FOR_NAME::INDEX);
                    std::string refName = resultSet->getString(InnoDbSysForeign::COLUMNS::REF_NAME::INDEX);
                    int nCols = resultSet->getInt(InnoDbSysForeign::COLUMNS::N_COLS::INDEX);
                    int type = resultSet->getInt(InnoDbSysForeign::COLUMNS::TYPE::INDEX);

                    innodbSysForeign.emplace_back(InnoDbSysForeign{id, forName, refName, nCols, type});
                }

                resultSet->close();
                statement->close();

                return innodbSysForeign;
            }

/**
* Get all INNODB_SYS_TABLESTATS
*/
            std::vector<InnoDbSysTableStats> getInnoDbSysTableStats() {

                std::vector<InnoDbSysTableStats> innodbSysTablestats;

                std::string query = dbcrudgen::mysql::MYSQLQueries::GET_INNODB_SYS_TABLESTATS;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(query);

                while (resultSet->next()) {

                    long tableId = resultSet->getInt(InnoDbSysTableStats::COLUMNS::TABLE_ID::INDEX);
                    std::string name = resultSet->getString(InnoDbSysTableStats::COLUMNS::NAME::INDEX);
                    std::string statsInitialized = resultSet->getString(
                            InnoDbSysTableStats::COLUMNS::STATS_INITIALIZED::INDEX);
                    long numRows = resultSet->getInt(InnoDbSysTableStats::COLUMNS::NUM_ROWS::INDEX);
                    long clustIndexSize = resultSet->getInt(InnoDbSysTableStats::COLUMNS::CLUST_INDEX_SIZE::INDEX);
                    long otherIndexSize = resultSet->getInt(InnoDbSysTableStats::COLUMNS::OTHER_INDEX_SIZE::INDEX);
                    long modifiedCounter = resultSet->getInt(InnoDbSysTableStats::COLUMNS::MODIFIED_COUNTER::INDEX);
                    long autoinc = resultSet->getInt(InnoDbSysTableStats::COLUMNS::AUTOINC::INDEX);
                    int refCount = resultSet->getInt(InnoDbSysTableStats::COLUMNS::REF_COUNT::INDEX);

                    innodbSysTablestats.emplace_back(
                            InnoDbSysTableStats{tableId, name, statsInitialized, numRows, clustIndexSize,
                                                otherIndexSize, modifiedCounter, autoinc, refCount});
                }

                resultSet->close();
                statement->close();

                return innodbSysTablestats;
            }


            /**
             * Returns the list of all schemas or databases in a MYSQL database server
             * @return
             */
            std::vector<Schemata> getSchemas() {
                std::vector<Schemata> schematas;

                std::string query = ::dbcrudgen::mysql::MYSQLQueries::GET_SCHEMAS;

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(sql::SQLString{query});

                while (resultSet->next()) {
                    std::string catalogName = resultSet->getString(Schemata::COLUMNS::CATALOG_NAME::INDEX);
                    std::string schemaName = resultSet->getString(Schemata::COLUMNS::SCHEMA_NAME::INDEX);
                    std::string defaultCharacterSetName = resultSet->getString(
                            Schemata::COLUMNS::DEFAULT_CHARACTER_SET_NAME::INDEX);
                    std::string defaultCollationName = resultSet->getString(
                            Schemata::COLUMNS::DEFAULT_COLLATION_NAME::INDEX);
                    std::string sqlPath = resultSet->getString(Schemata::COLUMNS::SQL_PATH::INDEX);

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

                std::string query = mysql::MYSQLQueries::GET_SCHEMA_TABLES;
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

                    Tables table{tableCatalog, tableSchema, tableName, tableType, engine, version, rowFormat, tableRows,
                                 avgRowLength, dataLength, maxDataLength, indexLength, dataFree, autoIncrement,
                                 createTime,
                                 updateTime, checkTime, tableCollation, checksum, createOptions, tableComment};

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
            std::vector<mysql::Columns> getTableColumns(std::string &schema_name, std::string &table_name) {
                std::vector<mysql::Columns> columns;


                std::string query = ::dbcrudgen::mysql::MYSQLQueries::GET_SCHEMA_TABLE_COLUMNS;
                query = StringUtils::replace(query, MYSQLQueries::Tags::TABLE_SCHEMA, schema_name);
                query = StringUtils::replace(query, MYSQLQueries::Tags::TABLE_NAME, table_name);

                sql::Statement *statement = &connector.createStatement();
                sql::ResultSet *resultSet = statement->executeQuery(sql::SQLString{query});

                while (resultSet->next()) {
                    std::string table_catalog = resultSet->getString(
                            mysql::Columns::COLUMNS::TABLE_CATALOG::INDEX);
                    std::string table_schema = resultSet->getString(
                            mysql::Columns::COLUMNS::TABLE_SCHEMA::INDEX);
                    table_name = resultSet->getString(mysql::Columns::COLUMNS::TABLE_NAME::INDEX);
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
             * Get Table Create Statement
             * @param schema
             * @param table
             * @return
             */
            std::string getTableCreateStatement(std::string &schema, std::string &table) {

                std::string create_table;

                const int table_index = 1;
                const int create_table_statement_index = 2;

                std::string query = mysql::MYSQLQueries::GET_TABLE_CREATE_STATEMENT;
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
        };
    }
}


#endif //DBCRUDGEN_CPP_MYSQLDATABASEDECOMPOSER_H
