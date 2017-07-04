<<<<<<< HEAD
#include <stdio.h>
#include <sqlite3.h>
#include <iostream>
<<<<<<< HEAD
=======
int main(int argc, char* argv[]) {
>>>>>>> db-connector-sqlite

    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;

<<<<<<< HEAD
int main(int argc, char *argv[]) {

    return 0;
=======
    std::string dbFile = "/home/victor/Documents/workspace/c++/dbcrudgen-cpp/res/test/databases/dbcrudgen-db-sqlite.db";
    rc = sqlite3_open(dbFile.c_str(), &db);

    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }
    sqlite3_close(db);
>>>>>>> db-connector-sqlite
=======
/* Standard C++ includes */
#include <stdlib.h>
#include <iostream>

/*
  Include directly the different
  headers from cppconn/ and mysql_driver.h + mysql_util.h
  (and mysql_connection.h). This will reduce your build time!
*/
#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

int main(void)
{
    cout << endl;
    cout << "Running 'SELECT 'Hello World!'     AS _message'..." << endl;

    try {
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;

        /* Create a connection */
        driver = get_driver_instance();

        con = driver->connect("tcp://127.0.0.1:3306", "root", "root3358");

        /* Connect to the MySQL test database */
        con->setSchema("dbcrudgen");

        stmt = con->createStatement();
        res = stmt->executeQuery("SELECT 'Hello World!' AS _message");
        while (res->next()) {
            cout << "\t... MySQL replies: ";
            /* Access column data by alias or column name */
            cout << res->getString("_message") << endl;
            cout << "\t... MySQL says it again: ";
            /* Access column data by numeric offset, 1 is the first column */
            cout << res->getString(1) << endl;
        }
        delete res;
        delete stmt;
        delete con;

    } catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line "         << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }

    cout << endl;

    return EXIT_SUCCESS;

>>>>>>> db-connector-mysql
}