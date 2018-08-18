#include <iostream>
#include <occi.h>

int main(int argc, char **argv) {


    const std::string userName = "mwenda";
    const std::string password = "root3358";
    const std::string connectionString = "jdbc:oracle:thin:@//mwenda:1522/XE";


    oracle::occi::Environment *env = oracle::occi::Environment::createEnvironment();
    oracle::occi::Connection *conn = env->createConnection(userName, password, connectionString);

    env->terminateConnection(conn);
    oracle::occi::Environment::terminateEnvironment(env);

    return EXIT_SUCCESS;
}