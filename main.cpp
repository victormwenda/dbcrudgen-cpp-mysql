#include <iostream>
#include <occi.h>

using namespace oracle::occi;

int main(int argc, char **argv) {
    const std::string userName = "victor";
    const std::string password = "root3358";
    const std::string connectionString = "//localhost:1521/xe";

    Environment *env = Environment::createEnvironment();

    Connection *conn = env->createConnection(
            userName, password, connectionString);
    Statement *stmt = conn->createStatement(
            "SELECT * FROM BUG_LOGGER;");
    ResultSet *rs = stmt->executeQuery();
    rs->next();
    int bugId = rs->getInt(1);
    std::cout << "Bug id : " << bugId << std::endl;

    stmt->closeResultSet(rs);
    conn->terminateStatement(stmt);
    env->terminateConnection(conn);

    Environment::terminateEnvironment(env);

    return EXIT_SUCCESS;
}
