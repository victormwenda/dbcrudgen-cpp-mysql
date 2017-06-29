#include <stdio.h>
#include <sqlite3.h>
#include <iostream>
int main(int argc, char* argv[]) {

    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;

    std::string dbFile = "/home/victor/Documents/workspace/c++/dbcrudgen-cpp/res/test/databases/dbcrudgen-db-sqlite.db";
    rc = sqlite3_open(dbFile.c_str(), &db);

    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }
    sqlite3_close(db);
}