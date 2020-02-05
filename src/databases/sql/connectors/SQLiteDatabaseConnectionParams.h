//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 6/29/17.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_SQLITEDATABASECONNECTION_H
#define DBCRUDGEN_CPP_SQLITEDATABASECONNECTION_H

#include "DatabaseConnection.h"

//
// SQLiteDatabaseConnectionParams
// //
class SQLiteDatabaseConnectionParams {

private:
    std::string filePath;

public:
    /**
     * SQLiteDatabase Connection
     * Handles SQLite Database connection
     * @param filePath
     */
    SQLiteDatabaseConnectionParams(const std::string &filePath)
            : filePath(filePath) {}

    /**
     * Returns the file path to the SQLite database
     * @return
     */
    const std::string &getFilePath() const {
        return filePath;
    }

    /**
     * Sets the file path to the SQLite database
     * @param filePath
     */
    void setFilepath(const std::string filePath) {
        SQLiteDatabaseConnectionParams::filePath = filePath;
    }
};


#endif //DBCRUDGEN_CPP_SQLITEDATABASECONNECTION_H
