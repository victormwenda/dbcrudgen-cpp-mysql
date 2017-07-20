//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 7/4/17.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_SQLITEDATABASECONNECTOR_H
#define DBCRUDGEN_CPP_SQLITEDATABASECONNECTOR_H


#include <sqlite3.h>
#include <sstream>
#include "credentials/SQLiteDatabaseConnectionParams.h"
#include "DatabaseConnector.h"
#include "../error/DatabaseError.h"

//
// SQLiteDatabaseConnector
// //
class SQLiteDatabaseConnector : public DatabaseConnector {

private:
    bool opened;
    sqlite3 *database;
    SQLiteDatabaseConnectionParams connectionParams;
    bool autoConnect;
public:
    explicit SQLiteDatabaseConnector(SQLiteDatabaseConnectionParams connectionParams, bool autoConnect = false)
            : connectionParams{connectionParams}, autoConnect{autoConnect} {

        opened = false;

        if (autoConnect) {
            open();
        }
    }

    const SQLiteDatabaseConnectionParams &getConnectionParams() const {
        return connectionParams;
    }

    /**
     * Get a SQLite Database connection
     * @param autoConnect
     * @return
     */
    sqlite3 &getConnection(bool autoConnect = false) {
        if (!isOpen()) { open(); };
        return *database;
    }

    /**
     * Change the database
     * @param schema
     */
    void changeSchema(const std::string schema) {

        connectionParams.setFilepath(schema);

    }

    /**
     * Opens an sqlite database
     * @param filename
     * @return
     */
    int open_sqlite_database(const char *filename) {
        return sqlite3_open(filename, &database);
    }

    bool open() override {

        if (!opened) {

            const char *filename = getConnectionParams().getFilePath().c_str();

            int responseCode = open_sqlite_database(filename);

            if (responseCode) { // TODO This responseCode is mostly zero
                opened = false;
                std::stringstream errorMessage;
                errorMessage << sqlite3_errcode(database) << ":" << sqlite3_errmsg(database);
                onError("FATAL", errorMessage.str() , true);
            } else {
                opened = true;
            }
        }

        return opened;
    }

    bool isOpen() override {
        return opened;
    }

    bool close() override {
        if (isOpen()) {
            sqlite3_close(database);
            opened = false;
        } //TODO maybe throw exception trying to close a non open database
        return !opened;
    }

    void onError(std::string errorLevel, std::string errorMessage, bool logError) override {
        DatabaseConnector::onError(errorLevel, errorMessage, logError);
    }

    static int onDataFound(void *data, int argc, char **argv, char **azColName) {
      /*  int i;
        fprintf(stderr, "%s: ", (const char *) data);

        for (i = 0; i < argc; i++) {
            printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
        }

        printf("\n");*/

        for( int i =0;i < argc; i++){
            std::cout << azColName[i]<< " -> " << argv[i] << std::endl;
        }
        return 0;
    }

    /**
     * Execute a query
     * @param query
     * @return SQLITE_OK, SQLITE_ERROR among other defined constants
     */
    int exec(const char *query) {
        std::string data = "Calling callback function";
        char **errMessage = 0;

        return sqlite3_exec(database, query, onDataFound, (void *) data.c_str(), errMessage);
    }
};


#endif //DBCRUDGEN_CPP_SQLITEDATABASECONNECTOR_H
