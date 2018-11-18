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
            std::string proxy_only_connect = resultSet->getString(OracleDBAUsersColumns::PROXY_ONLY_CONNECT::INDEX);
            std::string common = resultSet->getString(OracleDBAUsersColumns::COMMON::INDEX);
            std::string last_login = resultSet->getString(OracleDBAUsersColumns::LAST_LOGIN::INDEX);
            std::string oracle_maintained = resultSet->getString(OracleDBAUsersColumns::ORACLE_MAINTAINED::INDEX);

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
                    authentication_type,
                    proxy_only_connect,
                    common,
                    last_login,
                    oracle_maintained
            });

        }

        statement->closeResultSet(resultSet);
        conn->terminateStatement(statement);

        return oracleUsers;
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
