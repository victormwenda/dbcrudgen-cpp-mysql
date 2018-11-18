#include <iostream>
#include <occi.h>
#include "core/database/relations/OracleUser.h"
#include "models/OracleDatabaseModel.h"

int main(int argc, char **argv) {


    const std::string userName = "victor";
    const std::string password = "root3358";
    const std::string connectionString = "//victor:1522/XE";


    oracle::occi::Environment *env = oracle::occi::Environment::createEnvironment();
    oracle::occi::Connection *conn = env->createConnection(userName, password, connectionString);

    OracleDatabaseModel databaseModel{userName, password, connectionString};
    std::vector<OracleDBAUser> oracleUsers = databaseModel.getAllDBAUsers();


    for (OracleDBAUser oracleUser : oracleUsers) {
        std::cout << "\tuser id " << oracleUser.getUser_id()
                  << "\tcreated : " << oracleUser.getCreated()
                  << "\tusername : " << oracleUser.getUsername()
                  << "\tpassword : " << oracleUser.getPassword()
                  << std::endl;
    }


    return EXIT_SUCCESS;
}