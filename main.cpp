#include <iostream>
#include "core/database/connectors/MYSQLDatabaseConnector.h"
#include "core/database/executors/MYSQLQueryExecutor.h"
#include "core/database/executors/SQLiteQueryExecutor.h"

#include <cppconn/statement.h>
#include <cppconn/resultset.h>

using namespace std;

int main(void) {
    std::string filename = "/home/victor/Documents/workspace/c++/dbcrudgen-cpp/res/test/databases/dbcrudgen-db-sqlite.db";
    SQLiteDatabaseConnectionParams connectionParams {filename};
    SQLiteDatabaseConnector connector {connectionParams,true};
    SQLiteQueryExecutor sqLiteQueryExecutor{&connector,filename};
    sqLiteQueryExecutor.executeQuery("SELECT * FROM bug_logger");
    return EXIT_SUCCESS;
}