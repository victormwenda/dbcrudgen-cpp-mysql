#include <iostream>
#include "core/database/connectors/MYSQLDatabaseConnector.h"
#include "core/database/executors/MYSQLQueryExecutor.h"

#include <cppconn/statement.h>
#include <cppconn/resultset.h>

using namespace std;

int main(void) {

    MYSQLDatabaseConnectionParams connectionParams{"tcp://127.0.0.1:3306",
                                                   "root", "root3358"};

    MYSQLDatabaseConnector connector{connectionParams, true};

    if (connector.isOpen()) {
        cout << "Database is open " << endl;
    }

    MYSQLQueryExecutor executor{&connector, "dbcrudgen"};

    sql::ResultSet *resultSet = &executor.exec("SELECT * FROM bug_logger;");

    while (resultSet->next()) {
        std::string stackTrace = resultSet->getString("stack_trace");
        cout << "Stack trace : " << stackTrace << endl;
    }
    delete (resultSet);
    return EXIT_SUCCESS;
}