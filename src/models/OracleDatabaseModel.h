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
     * Terminate connection, Terminate environment
     */
    ~OracleDatabaseModel() {
        env->terminateConnection(conn);
        oracle::occi::Environment::terminateEnvironment(env);
    }
};


#endif //DBCRUDGEN_CPP_ORACLEDATABASEMODEL_H
