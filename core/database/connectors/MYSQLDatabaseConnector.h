//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 7/4/17.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_MYSQLDATABASECONNECTOR_H
#define DBCRUDGEN_CPP_MYSQLDATABASECONNECTOR_H


#include <cppconn/connection.h>
#include <cppconn/driver.h>

#include "DatabaseConnector.h"
#include "credentials/MYSQLDatabaseConnectionParams.h"

//
// MYSQLDatabaseConnector
// //
class MYSQLDatabaseConnector : public DatabaseConnector {

private:
    bool autoConnect;
    MYSQLDatabaseConnectionParams connectionParams;
    sql::Driver *driver;
    sql::Connection *connection;
public:
    explicit MYSQLDatabaseConnector(MYSQLDatabaseConnectionParams connectionParams,
                                    bool autoConnect)
            : connectionParams{connectionParams}, autoConnect{autoConnect} {

        driver = get_driver_instance();

        if (autoConnect) { open(); }
    }

    /**
       * Get the database driver
       * @return
       */
    sql::Driver &getDriver() {
        if (driver == nullptr) {
            driver = get_driver_instance();
        }
        return *driver;
    }

    /**
        * Get the connection
        * @return
        */
    sql::Connection &getConnection() {
        return *connection;
    }

    bool open() override {

        if (connection == nullptr) {
            sql::SQLString host = connectionParams.getHost();
            sql::SQLString user = connectionParams.getUsername();
            sql::SQLString password = connectionParams.getPassword();
            connection = driver->connect(host, user, password);
        }

        return connection != nullptr;
    }

    bool isOpen() override {
        return open();
    }

    bool close() override {
        delete connection;
        return connection == nullptr && driver == nullptr;
    }

    void onError(std::string errorLevel, std::string errorMessage, bool logError) override {
        DatabaseConnector::onError(errorLevel, errorMessage, logError);
    }

    ~MYSQLDatabaseConnector() {
        if (isOpen()) { close(); }
    }

};


#endif //DBCRUDGEN_CPP_MYSQLDATABASECONNECTOR_H
