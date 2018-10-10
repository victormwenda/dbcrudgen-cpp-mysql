#include <iostream>
#include <occi.h>

int main(int argc, char **argv) {


    const std::string userName = "victor";
    const std::string password = "root3358";
    const std::string connectionString = "//victor:1522/XE";


    oracle::occi::Environment *env = oracle::occi::Environment::createEnvironment();
    oracle::occi::Connection *conn = env->createConnection(userName, password, connectionString);

    env->terminateConnection(conn);
    oracle::occi::Environment::terminateEnvironment(env);

    return EXIT_SUCCESS;
}