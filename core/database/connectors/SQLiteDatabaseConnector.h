//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 7/4/17.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_SQLITEDATABASECONNECTOR_H
#define DBCRUDGEN_CPP_SQLITEDATABASECONNECTOR_H


#include "credentials/SQLiteDatabaseConnectionParams.h"
#include "DatabaseConnector.h"

//
// SQLiteDatabaseConnector
// //
class SQLiteDatabaseConnector : public DatabaseConnector{

private:
    SQLiteDatabaseConnectionParams connectionParams;
    bool autoConnect;
public:
    explicit SQLiteDatabaseConnector(SQLiteDatabaseConnectionParams connectionParams, bool autoConnect = false)
            : connectionParams{connectionParams} , autoConnect{autoConnect}{

        if(autoConnect){
            open();
        }
    }

    const SQLiteDatabaseConnectionParams &getConnectionParams() const {
        return connectionParams;
    }

    bool open() override {
        return false;
    }

    bool isOpen() override {
        return false;
    }

    bool close() override {
        return false;
    }

    void onError(std::string errorLevel, std::string errorMessage, bool logError) override {
        DatabaseConnector::onError(errorLevel, errorMessage, logError);
    }
};


#endif //DBCRUDGEN_CPP_SQLITEDATABASECONNECTOR_H
