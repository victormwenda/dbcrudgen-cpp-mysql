//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 7/4/17.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_MYSQLDATABASECONNECTOR_H
#define DBCRUDGEN_CPP_MYSQLDATABASECONNECTOR_H


#include "DatabaseConnector.h"
#include "credentials/MYSQLDatabaseConnectionParams.h"

//
// MYSQLDatabaseConnector
// //
class MYSQLDatabaseConnector : public DatabaseConnector {

private:
    bool autoConnect;
    MYSQLDatabaseConnectionParams connectionParams;
public:
    explicit MYSQLDatabaseConnector(MYSQLDatabaseConnectionParams connectionParams,
                                    bool autoConnect)
            : connectionParams{connectionParams}, autoConnect{autoConnect} {}

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


#endif //DBCRUDGEN_CPP_MYSQLDATABASECONNECTOR_H
