//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 8/5/17.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_ORACLEDATABASEMODEL_H
#define DBCRUDGEN_CPP_ORACLEDATABASEMODEL_H


#include <occiControl.h>
#include "OracleUser.h"
#include "../queries/OracleStatements.h"
#include "../tables/OracleDBAUser.h"
#include "../tables/OracleUserTables.h"
#include "../parsers/OracleTags.h"
#include "../tables/OracleDBATables.h"
#include "../tables/OracleTableColumn.h"

#include "../indices/OracleDBATablesColumns.h"
#include "../indices/OracleObject.h"
#include "../indices/OracleSchemaObject.h"
#include "../indices/OracleColsColumns.h"
#include "../indices/OracleDbaColsColumns.h"
#include "../tables/OracleTableColsDba.h"
#include "../indices/OracleAllTablesColumns.h"
#include "../../../orm/utils/StringUtils.h"
#include "../indices/OracleDBAUsersColumns.h"
#include "../indices/OracleUsersColumns.h"

#include <sstream>

//
// OracleDatabaseModel
// //
class OracleDatabaseModel {

private:
    oracle::occi::Environment *env;
    oracle::occi::Connection *conn;

    std::string username;
    std::string connectionString;
    std::string password;

public:

    /**
     * Create Oracle Database Environment and Open oracle database connection
     * @param username
     * @param password
     * @param connectionString
     */
    OracleDatabaseModel(std::string username, std::string password, std::string connectionString)
            : username(username), password(password), connectionString(connectionString) {
        env = oracle::occi::Environment::createEnvironment();
        conn = env->createConnection(username, password, connectionString);
    }

    /**
     * Get all the Oracle users
     * @return
     */
    std::vector<OracleUser> getAllUsers() {
        oracle::occi::Statement *statement = conn->createStatement(OracleStatements::GET_ALL_USERS);
        oracle::occi::ResultSet *resultSet = statement->executeQuery();

        std::vector<OracleUser> oracleUsers;

        while (resultSet->next()) {
            std::string username = resultSet->getString(OracleUsersColumns::USERNAME::INDEX);
            int userid = resultSet->getInt(OracleUsersColumns::USERID::INDEX);
            std::string created = resultSet->getString(OracleUsersColumns::CREATED::INDEX);

            oracleUsers.emplace_back(OracleUser{userid, username, created});

        }

        statement->closeResultSet(resultSet);
        conn->terminateStatement(statement);

        return oracleUsers;
    }

    /**
     * Get all the DBA Users
     * @return
     */
    std::vector<OracleDBAUser> getAllDBAUsers() {
        oracle::occi::Statement *statement = conn->createStatement(OracleStatements::GET_DBA_USERS);
        oracle::occi::ResultSet *resultSet = statement->executeQuery();

        std::vector<OracleDBAUser> oracleUsers;

        while (resultSet->next()) {

            std::string username = resultSet->getString(OracleDBAUsersColumns::USERNAME::INDEX);
            std::string user_id = resultSet->getString(OracleDBAUsersColumns::USER_ID::INDEX);
            std::string password = resultSet->getString(OracleDBAUsersColumns::PASSWORD::INDEX);
            std::string account_status = resultSet->getString(OracleDBAUsersColumns::ACCOUNT_STATUS::INDEX);
            std::string lock_date = resultSet->getString(OracleDBAUsersColumns::LOCK_DATE::INDEX);
            std::string expiry_date = resultSet->getString(OracleDBAUsersColumns::EXPIRY_DATE::INDEX);
            std::string default_tablespace = resultSet->getString(OracleDBAUsersColumns::DEFAULT_TABLESPACE::INDEX);
            std::string temporary_tablespace = resultSet->getString(OracleDBAUsersColumns::TEMPORARY_TABLESPACE::INDEX);
            std::string created = resultSet->getString(OracleDBAUsersColumns::CREATED::INDEX);
            std::string profile = resultSet->getString(OracleDBAUsersColumns::PROFILE::INDEX);
            std::string initial_rsrc_consumer_group = resultSet->getString(
                    OracleDBAUsersColumns::INITIAL_RSRC_CONSUMER_GROUP::INDEX);
            std::string external_name = resultSet->getString(OracleDBAUsersColumns::EXTERNAL_NAME::INDEX);
            std::string password_versions = resultSet->getString(OracleDBAUsersColumns::PASSWORD_VERSIONS::INDEX);
            std::string editions_enabled = resultSet->getString(OracleDBAUsersColumns::EDITIONS_ENABLED::INDEX);
            std::string authentication_type = resultSet->getString(OracleDBAUsersColumns::AUTHENTICATION_TYPE::INDEX);

            oracleUsers.emplace_back(OracleDBAUser{
                    username, user_id, password, account_status, lock_date, expiry_date, default_tablespace,
                    temporary_tablespace, created, profile, initial_rsrc_consumer_group, external_name,
                    password_versions, editions_enabled, authentication_type
            });

        }

        statement->closeResultSet(resultSet);
        conn->terminateStatement(statement);

        return oracleUsers;
    }

    /**
     * Get all the tables created by users
     * @return
     */
    std::vector<OracleUserTables> getOracleUsersTables() {
        std::string oracleTablesQuery = OracleStatements::GET_ALL_TABLES;

        oracle::occi::Statement *statement = conn->createStatement(oracleTablesQuery);
        oracle::occi::ResultSet *resultSet = statement->executeQuery();

        std::vector<OracleUserTables> userTables;

        while (resultSet->next()) {
            std::string OWNER = resultSet->getString(OracleAllTablesColumns::OWNER::INDEX);
            std::string TABLE_NAME = resultSet->getString(OracleAllTablesColumns::TABLE_NAME::INDEX);
            std::string TABLESPACE_NAME = resultSet->getString(OracleAllTablesColumns::TABLESPACE_NAME::INDEX);
            std::string CLUSTER_NAME = resultSet->getString(OracleAllTablesColumns::CLUSTER_NAME::INDEX);
            std::string IOT_NAME = resultSet->getString(OracleAllTablesColumns::IOT_NAME::INDEX);
            std::string STATUS = resultSet->getString(OracleAllTablesColumns::STATUS::INDEX);
            std::string PCT_FREE = resultSet->getString(OracleAllTablesColumns::PCT_FREE::INDEX);
            std::string PCT_USED = resultSet->getString(OracleAllTablesColumns::PCT_USED::INDEX);
            std::string INI_TRANS = resultSet->getString(OracleAllTablesColumns::INI_TRANS::INDEX);
            std::string MAX_TRANS = resultSet->getString(OracleAllTablesColumns::MAX_TRANS::INDEX);
            std::string INITIAL_EXTENT = resultSet->getString(OracleAllTablesColumns::INITIAL_EXTENT::INDEX);
            std::string NEXT_EXTENT = resultSet->getString(OracleAllTablesColumns::NEXT_EXTENT::INDEX);
            std::string MIN_EXTENTS = resultSet->getString(OracleAllTablesColumns::MIN_EXTENTS::INDEX);
            std::string MAX_EXTENTS = resultSet->getString(OracleAllTablesColumns::MAX_EXTENTS::INDEX);
            std::string PCT_INCREASE = resultSet->getString(OracleAllTablesColumns::PCT_INCREASE::INDEX);
            std::string FREELISTS = resultSet->getString(OracleAllTablesColumns::FREELISTS::INDEX);
            std::string FREELIST_GROUPS = resultSet->getString(OracleAllTablesColumns::FREELIST_GROUPS::INDEX);
            std::string LOGGING = resultSet->getString(OracleAllTablesColumns::LOGGING::INDEX);
            std::string BACKED_UP = resultSet->getString(OracleAllTablesColumns::BACKED_UP::INDEX);
            std::string NUM_ROWS = resultSet->getString(OracleAllTablesColumns::NUM_ROWS::INDEX);
            std::string BLOCKS = resultSet->getString(OracleAllTablesColumns::BLOCKS::INDEX);
            std::string EMPTY_BLOCKS = resultSet->getString(OracleAllTablesColumns::EMPTY_BLOCKS::INDEX);
            std::string AVG_SPACE = resultSet->getString(OracleAllTablesColumns::AVG_SPACE::INDEX);
            std::string CHAIN_CNT = resultSet->getString(OracleAllTablesColumns::CHAIN_CNT::INDEX);
            std::string AVG_ROW_LEN = resultSet->getString(OracleAllTablesColumns::AVG_ROW_LEN::INDEX);
            std::string AVG_SPACE_FREELIST_BLOCKS = resultSet->getString(
                    OracleAllTablesColumns::AVG_SPACE_FREELIST_BLOCKS::INDEX);
            std::string NUM_FREELIST_BLOCKS = resultSet->getString(OracleAllTablesColumns::NUM_FREELIST_BLOCKS::INDEX);
            std::string DEGREE = resultSet->getString(OracleAllTablesColumns::DEGREE::INDEX);
            std::string INSTANCES = resultSet->getString(OracleAllTablesColumns::INSTANCES::INDEX);
            std::string CACHE = resultSet->getString(OracleAllTablesColumns::CACHE::INDEX);
            std::string TABLE_LOCK = resultSet->getString(OracleAllTablesColumns::TABLE_LOCK::INDEX);
            std::string SAMPLE_SIZE = resultSet->getString(OracleAllTablesColumns::SAMPLE_SIZE::INDEX);
            std::string LAST_ANALYZED = resultSet->getString(OracleAllTablesColumns::LAST_ANALYZED::INDEX);
            std::string PARTITIONED = resultSet->getString(OracleAllTablesColumns::PARTITIONED::INDEX);
            std::string IOT_TYPE = resultSet->getString(OracleAllTablesColumns::IOT_TYPE::INDEX);
            std::string TEMPORARY = resultSet->getString(OracleAllTablesColumns::TEMPORARY::INDEX);
            std::string SECONDARY = resultSet->getString(OracleAllTablesColumns::SECONDARY::INDEX);
            std::string NESTED = resultSet->getString(OracleAllTablesColumns::NESTED::INDEX);
            std::string BUFFER_POOL = resultSet->getString(OracleAllTablesColumns::BUFFER_POOL::INDEX);
            std::string FLASH_CACHE = resultSet->getString(OracleAllTablesColumns::FLASH_CACHE::INDEX);
            std::string CELL_FLASH_CACHE = resultSet->getString(OracleAllTablesColumns::CELL_FLASH_CACHE::INDEX);
            std::string ROW_MOVEMENT = resultSet->getString(OracleAllTablesColumns::ROW_MOVEMENT::INDEX);
            std::string GLOBAL_STATS = resultSet->getString(OracleAllTablesColumns::GLOBAL_STATS::INDEX);
            std::string USER_STATS = resultSet->getString(OracleAllTablesColumns::USER_STATS::INDEX);
            std::string DURATION = resultSet->getString(OracleAllTablesColumns::DURATION::INDEX);
            std::string SKIP_CORRUPT = resultSet->getString(OracleAllTablesColumns::SKIP_CORRUPT::INDEX);
            std::string MONITORING = resultSet->getString(OracleAllTablesColumns::MONITORING::INDEX);
            std::string CLUSTER_OWNER = resultSet->getString(OracleAllTablesColumns::CLUSTER_OWNER::INDEX);
            std::string DEPENDENCIES = resultSet->getString(OracleAllTablesColumns::DEPENDENCIES::INDEX);
            std::string COMPRESSION = resultSet->getString(OracleAllTablesColumns::COMPRESSION::INDEX);
            std::string COMPRESS_FOR = resultSet->getString(OracleAllTablesColumns::COMPRESS_FOR::INDEX);
            std::string DROPPED = resultSet->getString(OracleAllTablesColumns::DROPPED::INDEX);
            std::string READ_ONLY = resultSet->getString(OracleAllTablesColumns::READ_ONLY::INDEX);
            std::string SEGMENT_CREATED = resultSet->getString(OracleAllTablesColumns::SEGMENT_CREATED::INDEX);
            std::string RESULT_CACHE = resultSet->getString(OracleAllTablesColumns::RESULT_CACHE::INDEX);

            userTables.emplace_back(OracleUserTables{OWNER, TABLE_NAME, TABLESPACE_NAME,
                                                     CLUSTER_NAME, IOT_NAME,
                                                     STATUS, PCT_FREE, PCT_USED, INI_TRANS, MAX_TRANS, INITIAL_EXTENT,
                                                     NEXT_EXTENT, MIN_EXTENTS, MAX_EXTENTS, PCT_INCREASE,
                                                     FREELISTS, FREELIST_GROUPS, LOGGING, BACKED_UP,
                                                     NUM_ROWS, BLOCKS, EMPTY_BLOCKS,
                                                     AVG_SPACE, CHAIN_CNT,
                                                     AVG_ROW_LEN, AVG_SPACE_FREELIST_BLOCKS, NUM_FREELIST_BLOCKS,
                                                     DEGREE, INSTANCES, CACHE, TABLE_LOCK, SAMPLE_SIZE,
                                                     LAST_ANALYZED, PARTITIONED, IOT_TYPE, TEMPORARY,
                                                     SECONDARY, NESTED, BUFFER_POOL, FLASH_CACHE,
                                                     CELL_FLASH_CACHE, ROW_MOVEMENT, GLOBAL_STATS, USER_STATS,
                                                     DURATION, SKIP_CORRUPT, MONITORING, CLUSTER_OWNER,
                                                     DEPENDENCIES, COMPRESSION, COMPRESS_FOR, DROPPED,
                                                     READ_ONLY, SEGMENT_CREATED, RESULT_CACHE});
        }

        return userTables;
    }

    /**
     * Get all the tables owned by a user
     * @param username
     * @return
     */
    std::vector<OracleUserTables> getOracleUserTables(std::string username) {

        std::string oracleTablesQuery = OracleStatements::GET_USER_ALL_TABLES;
        std::string query = StringUtils::parseTemplate(oracleTablesQuery, OracleTags::OWNER, username);

        oracle::occi::Statement *statement = conn->createStatement(query);
        oracle::occi::ResultSet *resultSet = statement->executeQuery();

        std::vector<OracleUserTables> userTables;

        while (resultSet->next()) {
            std::string OWNER = resultSet->getString(OracleAllTablesColumns::OWNER::INDEX);
            std::string TABLE_NAME = resultSet->getString(OracleAllTablesColumns::TABLE_NAME::INDEX);
            std::string TABLESPACE_NAME = resultSet->getString(OracleAllTablesColumns::TABLESPACE_NAME::INDEX);
            std::string CLUSTER_NAME = resultSet->getString(OracleAllTablesColumns::CLUSTER_NAME::INDEX);
            std::string IOT_NAME = resultSet->getString(OracleAllTablesColumns::IOT_NAME::INDEX);
            std::string STATUS = resultSet->getString(OracleAllTablesColumns::STATUS::INDEX);
            std::string PCT_FREE = resultSet->getString(OracleAllTablesColumns::PCT_FREE::INDEX);
            std::string PCT_USED = resultSet->getString(OracleAllTablesColumns::PCT_USED::INDEX);
            std::string INI_TRANS = resultSet->getString(OracleAllTablesColumns::INI_TRANS::INDEX);
            std::string MAX_TRANS = resultSet->getString(OracleAllTablesColumns::MAX_TRANS::INDEX);
            std::string INITIAL_EXTENT = resultSet->getString(OracleAllTablesColumns::INITIAL_EXTENT::INDEX);
            std::string NEXT_EXTENT = resultSet->getString(OracleAllTablesColumns::NEXT_EXTENT::INDEX);
            std::string MIN_EXTENTS = resultSet->getString(OracleAllTablesColumns::MIN_EXTENTS::INDEX);
            std::string MAX_EXTENTS = resultSet->getString(OracleAllTablesColumns::MAX_EXTENTS::INDEX);
            std::string PCT_INCREASE = resultSet->getString(OracleAllTablesColumns::PCT_INCREASE::INDEX);
            std::string FREELISTS = resultSet->getString(OracleAllTablesColumns::FREELISTS::INDEX);
            std::string FREELIST_GROUPS = resultSet->getString(OracleAllTablesColumns::FREELIST_GROUPS::INDEX);
            std::string LOGGING = resultSet->getString(OracleAllTablesColumns::LOGGING::INDEX);
            std::string BACKED_UP = resultSet->getString(OracleAllTablesColumns::BACKED_UP::INDEX);
            std::string NUM_ROWS = resultSet->getString(OracleAllTablesColumns::NUM_ROWS::INDEX);
            std::string BLOCKS = resultSet->getString(OracleAllTablesColumns::BLOCKS::INDEX);
            std::string EMPTY_BLOCKS = resultSet->getString(OracleAllTablesColumns::EMPTY_BLOCKS::INDEX);
            std::string AVG_SPACE = resultSet->getString(OracleAllTablesColumns::AVG_SPACE::INDEX);
            std::string CHAIN_CNT = resultSet->getString(OracleAllTablesColumns::CHAIN_CNT::INDEX);
            std::string AVG_ROW_LEN = resultSet->getString(OracleAllTablesColumns::AVG_ROW_LEN::INDEX);
            std::string AVG_SPACE_FREELIST_BLOCKS = resultSet->getString(
                    OracleAllTablesColumns::AVG_SPACE_FREELIST_BLOCKS::INDEX);
            std::string NUM_FREELIST_BLOCKS = resultSet->getString(OracleAllTablesColumns::NUM_FREELIST_BLOCKS::INDEX);
            std::string DEGREE = resultSet->getString(OracleAllTablesColumns::DEGREE::INDEX);
            std::string INSTANCES = resultSet->getString(OracleAllTablesColumns::INSTANCES::INDEX);
            std::string CACHE = resultSet->getString(OracleAllTablesColumns::CACHE::INDEX);
            std::string TABLE_LOCK = resultSet->getString(OracleAllTablesColumns::TABLE_LOCK::INDEX);
            std::string SAMPLE_SIZE = resultSet->getString(OracleAllTablesColumns::SAMPLE_SIZE::INDEX);
            std::string LAST_ANALYZED = resultSet->getString(OracleAllTablesColumns::LAST_ANALYZED::INDEX);
            std::string PARTITIONED = resultSet->getString(OracleAllTablesColumns::PARTITIONED::INDEX);
            std::string IOT_TYPE = resultSet->getString(OracleAllTablesColumns::IOT_TYPE::INDEX);
            std::string TEMPORARY = resultSet->getString(OracleAllTablesColumns::TEMPORARY::INDEX);
            std::string SECONDARY = resultSet->getString(OracleAllTablesColumns::SECONDARY::INDEX);
            std::string NESTED = resultSet->getString(OracleAllTablesColumns::NESTED::INDEX);
            std::string BUFFER_POOL = resultSet->getString(OracleAllTablesColumns::BUFFER_POOL::INDEX);
            std::string FLASH_CACHE = resultSet->getString(OracleAllTablesColumns::FLASH_CACHE::INDEX);
            std::string CELL_FLASH_CACHE = resultSet->getString(OracleAllTablesColumns::CELL_FLASH_CACHE::INDEX);
            std::string ROW_MOVEMENT = resultSet->getString(OracleAllTablesColumns::ROW_MOVEMENT::INDEX);
            std::string GLOBAL_STATS = resultSet->getString(OracleAllTablesColumns::GLOBAL_STATS::INDEX);
            std::string USER_STATS = resultSet->getString(OracleAllTablesColumns::USER_STATS::INDEX);
            std::string DURATION = resultSet->getString(OracleAllTablesColumns::DURATION::INDEX);
            std::string SKIP_CORRUPT = resultSet->getString(OracleAllTablesColumns::SKIP_CORRUPT::INDEX);
            std::string MONITORING = resultSet->getString(OracleAllTablesColumns::MONITORING::INDEX);
            std::string CLUSTER_OWNER = resultSet->getString(OracleAllTablesColumns::CLUSTER_OWNER::INDEX);
            std::string DEPENDENCIES = resultSet->getString(OracleAllTablesColumns::DEPENDENCIES::INDEX);
            std::string COMPRESSION = resultSet->getString(OracleAllTablesColumns::COMPRESSION::INDEX);
            std::string COMPRESS_FOR = resultSet->getString(OracleAllTablesColumns::COMPRESS_FOR::INDEX);
            std::string DROPPED = resultSet->getString(OracleAllTablesColumns::DROPPED::INDEX);
            std::string READ_ONLY = resultSet->getString(OracleAllTablesColumns::READ_ONLY::INDEX);
            std::string SEGMENT_CREATED = resultSet->getString(OracleAllTablesColumns::SEGMENT_CREATED::INDEX);
            std::string RESULT_CACHE = resultSet->getString(OracleAllTablesColumns::RESULT_CACHE::INDEX);

            userTables.emplace_back(OracleUserTables{OWNER, TABLE_NAME, TABLESPACE_NAME,
                                                     CLUSTER_NAME, IOT_NAME,
                                                     STATUS, PCT_FREE, PCT_USED, INI_TRANS, MAX_TRANS, INITIAL_EXTENT,
                                                     NEXT_EXTENT, MIN_EXTENTS, MAX_EXTENTS, PCT_INCREASE,
                                                     FREELISTS, FREELIST_GROUPS, LOGGING, BACKED_UP,
                                                     NUM_ROWS, BLOCKS, EMPTY_BLOCKS,
                                                     AVG_SPACE, CHAIN_CNT,
                                                     AVG_ROW_LEN, AVG_SPACE_FREELIST_BLOCKS, NUM_FREELIST_BLOCKS,
                                                     DEGREE, INSTANCES, CACHE, TABLE_LOCK, SAMPLE_SIZE,
                                                     LAST_ANALYZED, PARTITIONED, IOT_TYPE, TEMPORARY,
                                                     SECONDARY, NESTED, BUFFER_POOL, FLASH_CACHE,
                                                     CELL_FLASH_CACHE, ROW_MOVEMENT, GLOBAL_STATS, USER_STATS,
                                                     DURATION, SKIP_CORRUPT, MONITORING, CLUSTER_OWNER,
                                                     DEPENDENCIES, COMPRESSION, COMPRESS_FOR, DROPPED,
                                                     READ_ONLY, SEGMENT_CREATED, RESULT_CACHE});
        }

        return userTables;
    }

    /**
     * Get DBA_TABLES
     * @return
     */
    std::vector<OracleDBATables> getDBATables() {

        std::vector<OracleDBATables> dbaTables;

        std::string query = OracleStatements::GET_DBA_TABLES;
        oracle::occi::Statement *statement = conn->createStatement(query);
        oracle::occi::ResultSet *resultSet = statement->executeQuery();

        while (resultSet->next()) {
            std::string owner = resultSet->getString(OracleDBATablesColumns::OWNER::INDEX);
            std::string table_name = resultSet->getString(OracleDBATablesColumns::TABLE_NAME::INDEX);
            std::string tablespace_name = resultSet->getString(OracleDBATablesColumns::TABLESPACE_NAME::INDEX);
            std::string cluster_name = resultSet->getString(OracleDBATablesColumns::CLUSTER_NAME::INDEX);
            std::string iot_name = resultSet->getString(OracleDBATablesColumns::IOT_NAME::INDEX);
            std::string status = resultSet->getString(OracleDBATablesColumns::STATUS::INDEX);
            int pct_free = resultSet->getInt(OracleDBATablesColumns::PCT_FREE::INDEX);
            int pct_used = resultSet->getInt(OracleDBATablesColumns::PCT_USED::INDEX);
            int ini_trans = resultSet->getInt(OracleDBATablesColumns::INI_TRANS::INDEX);
            int max_trans = resultSet->getInt(OracleDBATablesColumns::MAX_TRANS::INDEX);
            int initial_extent = resultSet->getInt(OracleDBATablesColumns::INITIAL_EXTENT::INDEX);
            int next_extent = resultSet->getInt(OracleDBATablesColumns::NEXT_EXTENT::INDEX);
            int min_extents = resultSet->getInt(OracleDBATablesColumns::MIN_EXTENTS::INDEX);
            int max_extents = resultSet->getInt(OracleDBATablesColumns::MAX_EXTENTS::INDEX);
            std::string pct_increase = resultSet->getString(OracleDBATablesColumns::PCT_INCREASE::INDEX);
            int freelists = resultSet->getInt(OracleDBATablesColumns::FREELISTS::INDEX);
            int freelist_groups = resultSet->getInt(OracleDBATablesColumns::FREELIST_GROUPS::INDEX);
            std::string logging = resultSet->getString(OracleDBATablesColumns::LOGGING::INDEX);
            std::string backed_up = resultSet->getString(OracleDBATablesColumns::BACKED_UP::INDEX);
            int num_rows = resultSet->getInt(OracleDBATablesColumns::NUM_ROWS::INDEX);
            int blocks = resultSet->getInt(OracleDBATablesColumns::BLOCKS::INDEX);
            int empty_blocks = resultSet->getInt(OracleDBATablesColumns::EMPTY_BLOCKS::INDEX);
            int avg_space = resultSet->getInt(OracleDBATablesColumns::AVG_SPACE::INDEX);
            int chain_cnt = resultSet->getInt(OracleDBATablesColumns::CHAIN_CNT::INDEX);
            int avg_row_len = resultSet->getInt(OracleDBATablesColumns::AVG_ROW_LEN::INDEX);
            int avg_space_freelist_blocks = resultSet->getInt(OracleDBATablesColumns::AVG_SPACE_FREELIST_BLOCKS::INDEX);
            int num_freelist_blocks = resultSet->getInt(OracleDBATablesColumns::NUM_FREELIST_BLOCKS::INDEX);
            std::string degree = resultSet->getString(OracleDBATablesColumns::DEGREE::INDEX);
            std::string instances = resultSet->getString(OracleDBATablesColumns::INSTANCES::INDEX);
            std::string cache = resultSet->getString(OracleDBATablesColumns::CACHE::INDEX);
            std::string table_lock = resultSet->getString(OracleDBATablesColumns::TABLE_LOCK::INDEX);
            int sample_size = resultSet->getInt(OracleDBATablesColumns::SAMPLE_SIZE::INDEX);
            std::string last_analyzed = resultSet->getString(OracleDBATablesColumns::LAST_ANALYZED::INDEX);
            std::string partitioned = resultSet->getString(OracleDBATablesColumns::PARTITIONED::INDEX);
            std::string iot_type = resultSet->getString(OracleDBATablesColumns::IOT_TYPE::INDEX);
            std::string temporary = resultSet->getString(OracleDBATablesColumns::TEMPORARY::INDEX);
            std::string secondary = resultSet->getString(OracleDBATablesColumns::SECONDARY::INDEX);
            std::string nested = resultSet->getString(OracleDBATablesColumns::NESTED::INDEX);
            std::string buffer_pool = resultSet->getString(OracleDBATablesColumns::BUFFER_POOL::INDEX);
            std::string flash_cache = resultSet->getString(OracleDBATablesColumns::FLASH_CACHE::INDEX);
            std::string cell_flash_cache = resultSet->getString(OracleDBATablesColumns::CELL_FLASH_CACHE::INDEX);
            std::string row_movement = resultSet->getString(OracleDBATablesColumns::ROW_MOVEMENT::INDEX);
            std::string global_stats = resultSet->getString(OracleDBATablesColumns::GLOBAL_STATS::INDEX);
            std::string user_stats = resultSet->getString(OracleDBATablesColumns::USER_STATS::INDEX);
            std::string duration = resultSet->getString(OracleDBATablesColumns::DURATION::INDEX);
            std::string skip_corrupt = resultSet->getString(OracleDBATablesColumns::SKIP_CORRUPT::INDEX);
            std::string monitoring = resultSet->getString(OracleDBATablesColumns::MONITORING::INDEX);
            std::string cluster_owner = resultSet->getString(OracleDBATablesColumns::CLUSTER_OWNER::INDEX);
            std::string dependencies = resultSet->getString(OracleDBATablesColumns::DEPENDENCIES::INDEX);
            std::string compression = resultSet->getString(OracleDBATablesColumns::COMPRESSION::INDEX);
            std::string compress_for = resultSet->getString(OracleDBATablesColumns::COMPRESS_FOR::INDEX);
            std::string dropped = resultSet->getString(OracleDBATablesColumns::DROPPED::INDEX);
            std::string read_only = resultSet->getString(OracleDBATablesColumns::READ_ONLY::INDEX);
            std::string segment_created = resultSet->getString(OracleDBATablesColumns::SEGMENT_CREATED::INDEX);
            std::string result_cache = resultSet->getString(OracleDBATablesColumns::RESULT_CACHE::INDEX);

            dbaTables.emplace_back(OracleDBATables{
                    owner, table_name, tablespace_name, cluster_name, iot_name, status, pct_free, pct_used,
                    ini_trans, max_trans, initial_extent, next_extent, min_extents, max_extents, pct_increase,
                    freelists, freelist_groups, logging, backed_up, num_rows, blocks, empty_blocks, avg_space,
                    chain_cnt, avg_row_len, avg_space_freelist_blocks, num_freelist_blocks, degree, instances, cache,
                    table_lock, sample_size, last_analyzed, partitioned, iot_type, temporary, secondary, nested,
                    buffer_pool, flash_cache, cell_flash_cache, row_movement, global_stats, user_stats, duration,
                    skip_corrupt, monitoring, cluster_owner, dependencies, compression, compress_for, dropped,
                    read_only, segment_created, result_cache});
        }

        return dbaTables;
    }

    /**
     * Returns the DDL for a table
     * @param schema
     * @param tableName
     * @return
     */
    std::string getTableDDL(const std::string &schema, const std::string &tableName) {
        return getDDL(std::string{OracleSchemaObject::TABLE::NAME}, schema, tableName);
    }

    /**
     * Get the DDL for and Oracle (Schemas) object
     * @param oracleObject
     * @param schema
     * @param objectName
     * @return
     */
    std::string getDDL(const std::string &oracleObject, const std::string &schema, const std::string &objectName) {

        std::string ddl;

        std::string query = OracleStatements::GET_OBJECT_DDL;
        query = StringUtils::parseTemplate(query, OracleTags::OBJECT, oracleObject);
        query = StringUtils::parseTemplate(query, OracleTags::SCHEMA, schema);
        query = StringUtils::parseTemplate(query, OracleTags::OBJECT_NAME, objectName);

        oracle::occi::Statement *statement = conn->createStatement(query);
        oracle::occi::ResultSet *resultSet = statement->executeQuery();

        if (resultSet->next()) {
            auto data = resultSet->getClob(1);

            unsigned int amount = data.length();
            std::vector<unsigned char> buffer(amount);
            unsigned int bufferSize = data.length();
            unsigned int offset = 1;

            unsigned int read = data.read(amount, buffer.data(), bufferSize, offset);

            std::stringstream builder;

            for (char output : buffer) {
                builder << output;
            }

            ddl = builder.str();
        }

        return ddl;
    }

    /**
     * Get all the columns of a table
     *
     * @param tableName
     * @return
     */
    std::vector<OracleTableColumn> getTableColumns(const std::string &tableName) {

        std::vector<OracleTableColumn> tableColumns;

        std::string query = OracleStatements::GET_TABLE_COLUMNS;
        query = StringUtils::parseTemplate(query, OracleTags::TABLE_NAME, tableName);

        oracle::occi::Statement *statement = conn->createStatement(query);
        oracle::occi::ResultSet *resultSet = statement->executeQuery();

        //Set max column size to corner :: ORA-32108: max column or parameter size not specified
        resultSet->setMaxColumnSize(OracleColsColumns::DATA_DEFAULT::INDEX, 128);

        while (resultSet->next()) {

            std::string table_name = resultSet->getString(OracleColsColumns::TABLE_NAME::INDEX);
            std::string column_name = resultSet->getString(OracleColsColumns::COLUMN_NAME::INDEX);
            std::string data_type = resultSet->getString(OracleColsColumns::DATA_TYPE::INDEX);
            std::string data_type_mod = resultSet->getString(OracleColsColumns::DATA_TYPE_MOD::INDEX);
            std::string data_type_owner = resultSet->getString(OracleColsColumns::DATA_TYPE_OWNER::INDEX);
            int data_length = resultSet->getInt(OracleColsColumns::DATA_LENGTH::INDEX);
            int data_precision = resultSet->getInt(OracleColsColumns::DATA_PRECISION::INDEX);
            int data_scale = resultSet->getInt(OracleColsColumns::DATA_SCALE::INDEX);
            std::string nullable = resultSet->getString(OracleColsColumns::NULLABLE::INDEX);
            int column_id = resultSet->getInt(OracleColsColumns::COLUMN_ID::INDEX);
            std::string default_length = resultSet->getString(OracleColsColumns::DEFAULT_LENGTH::INDEX);
            std::string data_default = resultSet->getString(OracleColsColumns::DATA_DEFAULT::INDEX);
            int num_distinct = resultSet->getInt(OracleColsColumns::NUM_DISTINCT::INDEX);
            std::string low_value = resultSet->getString(OracleColsColumns::LOW_VALUE::INDEX);
            std::string high_value = resultSet->getString(OracleColsColumns::HIGH_VALUE::INDEX);
            int density = resultSet->getInt(OracleColsColumns::DENSITY::INDEX);
            int num_nulls = resultSet->getInt(OracleColsColumns::NUM_NULLS::INDEX);
            int num_buckets = resultSet->getInt(OracleColsColumns::NUM_BUCKETS::INDEX);
            std::string last_analyzed = resultSet->getString(OracleColsColumns::LAST_ANALYZED::INDEX);
            int sample_size = resultSet->getInt(OracleColsColumns::SAMPLE_SIZE::INDEX);
            std::string character_set_name = resultSet->getString(OracleColsColumns::CHARACTER_SET_NAME::INDEX);
            std::string char_col_decl_length = resultSet->getString(OracleColsColumns::CHAR_COL_DECL_LENGTH::INDEX);
            std::string global_stats = resultSet->getString(OracleColsColumns::GLOBAL_STATS::INDEX);
            std::string user_stats = resultSet->getString(OracleColsColumns::USER_STATS::INDEX);
            int avg_col_len = resultSet->getInt(OracleColsColumns::AVG_COL_LEN::INDEX);
            int char_length = resultSet->getInt(OracleColsColumns::CHAR_LENGTH::INDEX);
            std::string char_used = resultSet->getString(OracleColsColumns::CHAR_USED::INDEX);
            std::string v80_fmt_image = resultSet->getString(OracleColsColumns::V80_FMT_IMAGE::INDEX);
            std::string data_upgraded = resultSet->getString(OracleColsColumns::DATA_UPGRADED::INDEX);
            std::string histogram = resultSet->getString(OracleColsColumns::HISTOGRAM::INDEX);

            tableColumns.emplace_back(OracleTableColumn{table_name, column_name, data_type,
                                                        data_type_mod, data_type_owner,
                                                        data_length, data_precision, data_scale, nullable,
                                                        column_id, default_length, data_default, num_distinct,
                                                        low_value, high_value, density, num_nulls, num_buckets,
                                                        last_analyzed, sample_size, character_set_name,
                                                        char_col_decl_length, global_stats, user_stats, avg_col_len,
                                                        char_length, char_used, v80_fmt_image, data_upgraded, histogram
            });
        }
        return tableColumns;
    }

    /**
     * Get all the dba columns of a table
     *
     * @param tableName
     * @return
     */
    std::vector<OracleTAbleColsDba> getTableColumnsDba(const std::string &tableName) {

        std::vector<OracleTAbleColsDba> tableColumns;

        std::string query = OracleStatements::GET_TABLE_COLUMNS_DBA;
        query = StringUtils::parseTemplate(query, OracleTags::TABLE_NAME, tableName);

        oracle::occi::Statement *statement = conn->createStatement(query);
        oracle::occi::ResultSet *resultSet = statement->executeQuery();

        //Set max column size to corner :: ORA-32108: max column or parameter size not specified
        resultSet->setMaxColumnSize(OracleDbaColsColumns::OWNER::INDEX, 30);
        resultSet->setMaxColumnSize(OracleDbaColsColumns::TABLE_NAME::INDEX, 30);
        resultSet->setMaxColumnSize(OracleDbaColsColumns::COLUMN_NAME::INDEX, 30);
        resultSet->setMaxColumnSize(OracleDbaColsColumns::DATA_TYPE::INDEX, 106);
        resultSet->setMaxColumnSize(OracleDbaColsColumns::DATA_TYPE_MOD::INDEX, 3);
        resultSet->setMaxColumnSize(OracleDbaColsColumns::DATA_TYPE_OWNER::INDEX, 120);
        resultSet->setMaxColumnSize(OracleDbaColsColumns::DATA_LENGTH::INDEX, 38);
        resultSet->setMaxColumnSize(OracleDbaColsColumns::DATA_PRECISION::INDEX, 38);
        resultSet->setMaxColumnSize(OracleDbaColsColumns::DATA_SCALE::INDEX, 38);
        resultSet->setMaxColumnSize(OracleDbaColsColumns::NULLABLE::INDEX, 128);
        resultSet->setMaxColumnSize(OracleDbaColsColumns::COLUMN_ID::INDEX, 38);
        resultSet->setMaxColumnSize(OracleDbaColsColumns::DEFAULT_LENGTH::INDEX, 38);
        resultSet->setMaxColumnSize(OracleDbaColsColumns::DATA_DEFAULT::INDEX, 128);
        resultSet->setMaxColumnSize(OracleDbaColsColumns::NUM_DISTINCT::INDEX, 10);
        resultSet->setMaxColumnSize(OracleDbaColsColumns::LOW_VALUE::INDEX, 32);
        resultSet->setMaxColumnSize(OracleDbaColsColumns::HIGH_VALUE::INDEX, 32);
        resultSet->setMaxColumnSize(OracleDbaColsColumns::DENSITY::INDEX, 38);
        resultSet->setMaxColumnSize(OracleDbaColsColumns::NUM_NULLS::INDEX, 38);
        resultSet->setMaxColumnSize(OracleDbaColsColumns::NUM_BUCKETS::INDEX, 38);
        resultSet->setMaxColumnSize(OracleDbaColsColumns::LAST_ANALYZED::INDEX, 128);
        resultSet->setMaxColumnSize(OracleDbaColsColumns::SAMPLE_SIZE::INDEX, 38);
        resultSet->setMaxColumnSize(OracleDbaColsColumns::CHARACTER_SET_NAME::INDEX, 44);
        resultSet->setMaxColumnSize(OracleDbaColsColumns::CHAR_COL_DECL_LENGTH::INDEX, 38);
        resultSet->setMaxColumnSize(OracleDbaColsColumns::GLOBAL_STATS::INDEX, 3);
        resultSet->setMaxColumnSize(OracleDbaColsColumns::USER_STATS::INDEX, 3);
        resultSet->setMaxColumnSize(OracleDbaColsColumns::AVG_COL_LEN::INDEX, 38);
        resultSet->setMaxColumnSize(OracleDbaColsColumns::CHAR_LENGTH::INDEX, 38);
        resultSet->setMaxColumnSize(OracleDbaColsColumns::CHAR_USED::INDEX, 1);
        resultSet->setMaxColumnSize(OracleDbaColsColumns::V80_FMT_IMAGE::INDEX, 3);
        resultSet->setMaxColumnSize(OracleDbaColsColumns::DATA_UPGRADED::INDEX, 3);
        resultSet->setMaxColumnSize(OracleDbaColsColumns::HIDDEN_COLUMN::INDEX, 3);
        resultSet->setMaxColumnSize(OracleDbaColsColumns::VIRTUAL_COLUMN::INDEX, 3);
        resultSet->setMaxColumnSize(OracleDbaColsColumns::SEGMENT_COLUMN_ID::INDEX, 38);
        resultSet->setMaxColumnSize(OracleDbaColsColumns::INTERNAL_COLUMN_ID::INDEX, 38);
        resultSet->setMaxColumnSize(OracleDbaColsColumns::HISTOGRAM::INDEX, 15);
        resultSet->setMaxColumnSize(OracleDbaColsColumns::QUALIFIED_COL_NAME::INDEX, 128);

        while (resultSet->next()) {
            std::string owner = resultSet->getString(OracleDbaColsColumns::OWNER::INDEX);
            std::string table_name = resultSet->getString(OracleDbaColsColumns::TABLE_NAME::INDEX);
            std::string column_name = resultSet->getString(OracleDbaColsColumns::COLUMN_NAME::INDEX);
            std::string data_type = resultSet->getString(OracleDbaColsColumns::DATA_TYPE::INDEX);
            std::string data_type_mod = resultSet->getString(OracleDbaColsColumns::DATA_TYPE_MOD::INDEX);
            std::string data_type_owner = resultSet->getString(OracleDbaColsColumns::DATA_TYPE_OWNER::INDEX);
            int data_length = resultSet->getInt(OracleDbaColsColumns::DATA_LENGTH::INDEX);
            int data_precision = resultSet->getInt(OracleDbaColsColumns::DATA_PRECISION::INDEX);
            int data_scale = resultSet->getInt(OracleDbaColsColumns::DATA_SCALE::INDEX);
            std::string nullable = resultSet->getString(OracleDbaColsColumns::NULLABLE::INDEX);
            int column_id = resultSet->getInt(OracleDbaColsColumns::COLUMN_ID::INDEX);
            std::string default_length = resultSet->getString(OracleDbaColsColumns::DEFAULT_LENGTH::INDEX);
            std::string data_default = resultSet->getString(OracleDbaColsColumns::DATA_DEFAULT::INDEX);
            int num_distinct = resultSet->getInt(OracleDbaColsColumns::NUM_DISTINCT::INDEX);
            std::string low_value = resultSet->getString(OracleDbaColsColumns::LOW_VALUE::INDEX);
            std::string high_value = resultSet->getString(OracleDbaColsColumns::HIGH_VALUE::INDEX);
            int density = resultSet->getInt(OracleDbaColsColumns::DENSITY::INDEX);
            int num_nulls = resultSet->getInt(OracleDbaColsColumns::NUM_NULLS::INDEX);
            int num_buckets = resultSet->getInt(OracleDbaColsColumns::NUM_BUCKETS::INDEX);
            std::string last_analyzed = resultSet->getString(OracleDbaColsColumns::LAST_ANALYZED::INDEX);
            int sample_size = resultSet->getInt(OracleDbaColsColumns::SAMPLE_SIZE::INDEX);
            std::string character_set_name = resultSet->getString(OracleDbaColsColumns::CHARACTER_SET_NAME::INDEX);
            std::string char_col_decl_length = resultSet->getString(OracleDbaColsColumns::CHAR_COL_DECL_LENGTH::INDEX);
            std::string global_stats = resultSet->getString(OracleDbaColsColumns::GLOBAL_STATS::INDEX);
            std::string user_stats = resultSet->getString(OracleDbaColsColumns::USER_STATS::INDEX);
            int avg_col_len = resultSet->getInt(OracleDbaColsColumns::AVG_COL_LEN::INDEX);
            int char_length = resultSet->getInt(OracleDbaColsColumns::CHAR_LENGTH::INDEX);
            std::string char_used = resultSet->getString(OracleDbaColsColumns::CHAR_USED::INDEX);
            std::string v80_fmt_image = resultSet->getString(OracleDbaColsColumns::V80_FMT_IMAGE::INDEX);
            std::string data_upgraded = resultSet->getString(OracleDbaColsColumns::DATA_UPGRADED::INDEX);
            std::string hidden_column = resultSet->getString(OracleDbaColsColumns::HIDDEN_COLUMN::INDEX);
            std::string virtual_column = resultSet->getString(OracleDbaColsColumns::VIRTUAL_COLUMN::INDEX);
            int segment_column_id = resultSet->getInt(OracleDbaColsColumns::SEGMENT_COLUMN_ID::INDEX);
            int internal_column_id = resultSet->getInt(OracleDbaColsColumns::INTERNAL_COLUMN_ID::INDEX);
            std::string histogram = resultSet->getString(OracleDbaColsColumns::HISTOGRAM::INDEX);
            std::string qualified_col_name = resultSet->getString(OracleDbaColsColumns::QUALIFIED_COL_NAME::INDEX);

            tableColumns.emplace_back(OracleTAbleColsDba{owner, table_name, column_name, data_type,
                                                         data_type_mod, data_type_owner,
                                                         data_length, data_precision, data_scale, nullable,
                                                         column_id, default_length, data_default, num_distinct,
                                                         low_value, high_value, density, num_nulls, num_buckets,
                                                         last_analyzed, sample_size, character_set_name,
                                                         char_col_decl_length, global_stats, user_stats, avg_col_len,
                                                         char_length, char_used, v80_fmt_image, data_upgraded,
                                                         hidden_column, virtual_column, segment_column_id,
                                                         internal_column_id,
                                                         histogram, qualified_col_name
            });
        }
        return tableColumns;
    }

    /**
     * Terminate connection, Terminate environment
     */
    ~OracleDatabaseModel() {
        env->terminateConnection(conn);
        oracle::occi::Environment::terminateEnvironment(env);
    }
};


#endif //DBCRUDGEN_CPP_ORACLEDATABASEMODEL_H
