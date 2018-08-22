#include <iostream>
#include <occi.h>

int main(int argc, char **argv) {


    const std::string userName = "mwenda";
    const std::string password = "root3358";
    const std::string connectionString = "//mwenda:1521/xe";


    try {
        oracle::occi::Environment *env = oracle::occi::Environment::createEnvironment();
        oracle::occi::Connection *conn = env->createConnection(userName, password, connectionString);

        oracle::occi::Statement *statement = conn->createStatement();
        oracle::occi::ResultSet *resultSet = statement->executeQuery("select * from bug_logger");

        while (resultSet->next()) {
            std::cout << resultSet->getString(4) << std::endl;
        }

        env->terminateConnection(conn);
        oracle::occi::Environment::terminateEnvironment(env);
    } catch (oracle::occi::SQLException& exception) {
        std::cout << "ERROR : " << exception.getErrorCode() << " : " << exception.getMessage();
    }


    return EXIT_SUCCESS;
}