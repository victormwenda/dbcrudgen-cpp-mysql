#include <iostream>
#include <occi.h>
#include "core/database/connectors/credentials/OracleDatabaseConnectionParams.h"
#include "core/database/connectors/OracleDatabaseConnector.h"
#include "utils/TransactionUtils.h"

using namespace oracle::occi;

int main(int argc, char **argv) {
    /*const std::string userName = "victor";
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
*/
    std::string host = "victor";
    int port = 1522;
    std::string username = "victor";
    std::string password = "root3358";
    std::string serviceName = "xe";
    OracleDatabaseConnectionParams connectionParams{host, port, username, password, serviceName};


    OracleDatabaseConnector connector = TransactionUtils::openOracleDatabase(connectionParams) ;
    ResultSet &resultSet = connector.executeQuery("SELECT * FROM bug_logger");
    resultSet.next();
    std::string index =resultSet.getString(4);
    std::cout << index << std::endl;

    return EXIT_SUCCESS;
}
