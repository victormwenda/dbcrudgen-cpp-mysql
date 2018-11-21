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
        auto oracleUsers = databaseModel.getDBATables();


        for (OracleDBATables oracleUserTables : oracleUsers) {
            std::cout << "\towner " << oracleUserTables.getOwner()
            << "\ttablename " << oracleUserTables.getTable_name()
            << "\ttable space name " << oracleUserTables.getTablespace_name()

                      << std::endl;
        }

    for(int i =0; i< 0; i++){
        std::cout << i << std::endl;
    }


    return EXIT_SUCCESS;
}