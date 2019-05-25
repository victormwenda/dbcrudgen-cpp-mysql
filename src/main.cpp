#include <iostream>
#include <occi.h>
#include "models/OracleDatabaseModel.h"

int main(int argc, char **argv) {


    const std::string userName = "mwenda";
    const std::string password = "root3358";
    const std::string connectionString = "//victor:1521/XE";


    oracle::occi::Environment *env = oracle::occi::Environment::createEnvironment();
    oracle::occi::Connection *conn = env->createConnection(userName, password, connectionString);

    oracle::occi::Statement *statement = conn->createStatement("SELECT * FROM BUG_LOGGER");

    oracle::occi::ResultSet *resultSet = statement->executeQuery("SELECT * FROM BUG_LOGGER");

    while (resultSet->next()) {
        std::string stack_trace = resultSet->getString(4);
        std::cout << stack_trace << std::endl;
    }

    /* OracleDatabaseModel databaseModel{userName, password, connectionString};
     auto ddl = databaseModel.getAllDBAUsers();

     for (const auto &username : ddl) {
         std::cout << username.username << std::endl;
     }


     for (int i = 0; i < 0; i++) {
         std::cout << i << std::endl;
     }*/

    env->terminateConnection(conn);
    oracle::occi::Environment::terminateEnvironment(env);

    return EXIT_SUCCESS;
}