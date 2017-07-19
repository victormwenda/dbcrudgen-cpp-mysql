//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 7/19/17.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_ORACLEDATABASECONNECTOR_H
#define DBCRUDGEN_CPP_ORACLEDATABASECONNECTOR_H


#include "DatabaseConnector.h"
#include "credentials/OracleDatabaseConnectionParams.h"

//
// OracleDatabaseConnector
// //
class OracleDatabaseConnector : public DatabaseConnector {

private:
    bool autoConnect;
    OracleDatabaseConnectionParams connectionParams;
public:
    OracleDatabaseConnector(bool autoConnect, const OracleDatabaseConnectionParams &connectionParams)
            : autoConnect(autoConnect), connectionParams(connectionParams) {

        if (autoConnect) {
            open();
        }
    }

    bool isAutoConnect() const {
        return autoConnect;
    }

    const OracleDatabaseConnectionParams &getConnectionParams() const {
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
};


#endif //DBCRUDGEN_CPP_ORACLEDATABASECONNECTOR_H
