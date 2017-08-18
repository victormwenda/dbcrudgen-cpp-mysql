#include <iostream>
#include <occi.h>

using namespace oracle::occi;

int main(int argc, char **argv) {
    const std::string userName = "victor";
    const std::string password = "root3358";
    const std::string connectionString = "//victor:1522/xe";


    Environment *env = Environment::createEnvironment();
    try {
        Connection *conn = env->createConnection(userName, password,connectionString);

        Statement *statement = conn->createStatement("SELECT * FROM BUG_LOGGER");
        ResultSet *resultSet = statement->executeQuery();
        resultSet->next();
        std::string index =resultSet->getString(4);
        std::cout << index << std::endl;
        env->terminateConnection(conn);
    } catch (const SQLException& exception) {
        std::cout << exception.getMessage() << std::endl;
    }
    Environment::terminateEnvironment(env);


    return EXIT_SUCCESS;
}
