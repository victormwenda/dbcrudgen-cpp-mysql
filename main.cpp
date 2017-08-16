#include <iostream>
#include <occi.h>

using namespace oracle::occi;

int main(int argc, char **argv) {
    const std::string userName = "victor";
    const std::string password = "root3358";
    const std::string connectionString = "jdbc:oracle:thin:@//victor:1522/XE";


    Environment *env = Environment::createEnvironment();
    Connection *conn = env->createConnection(userName, password, connectionString);

    env->terminateConnection(conn);
    Environment::terminateEnvironment(env);


    return EXIT_SUCCESS;
}
