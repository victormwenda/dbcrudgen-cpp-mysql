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
    OracleDatabaseConnector(const OracleDatabaseConnectionParams &connectionParams, bool autoConnect)
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
        const std::string userName = "victor";
        const std::string password = "root3358";
        const std::string connectString = "";

        Environment *env = Environment::createEnvironment();

        Connection *conn = env->createConnection(
                userName, password, connectString);
        Statement *stmt = conn->createStatement(
                "SELECT * FROM BUG_LOGGER;");
        ResultSet *rs = stmt->executeQuery();
        rs->next();
        Blob b = rs->getBlob(1);
        cout << "Length of BLOB : " << b.length();

        stmt->closeResultSet(rs);
        conn->terminateStatement(stmt);
        env->terminateConnection(conn);

        Environment::terminateEnvironment(env);
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
