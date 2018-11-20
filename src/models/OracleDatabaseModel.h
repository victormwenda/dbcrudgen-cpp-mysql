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
#include "../core/database/relations/OracleUser.h"
#include "../core/database/prepared/OracleStatements.h"
#include "../core/database/reserved/OracleUsersColumns.h"
#include "../core/database/reserved/OracleDBAUsersColumns.h"
#include "../core/database/relations/OracleDBAUser.h"
#include "../core/database/relations/OracleUserTables.h"
#include "../core/database/reserved/OracleAllTablesColumns.h"
#include "../utils/StringUtils.h"
#include "../utils/OracleTags.h"

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

            oracleUsers.emplace_back(OracleUser {userid, username, created});

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

            oracleUsers.emplace_back(OracleDBAUser {
                    username,
                    user_id,
                    password,
                    account_status,
                    lock_date,
                    expiry_date,
                    default_tablespace,
                    temporary_tablespace,
                    created,
                    profile,
                    initial_rsrc_consumer_group,
                    external_name,
                    password_versions,
                    editions_enabled,
                    authentication_type
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

            userTables.emplace_back(OracleUserTables {OWNER, TABLE_NAME, TABLESPACE_NAME,
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

            userTables.emplace_back(OracleUserTables {OWNER, TABLE_NAME, TABLESPACE_NAME,
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
     * Terminate connection, Terminate environment
     */
    ~OracleDatabaseModel() {
        env->terminateConnection(conn);
        oracle::occi::Environment::terminateEnvironment(env);
    }
};


#endif //DBCRUDGEN_CPP_ORACLEDATABASEMODEL_H
