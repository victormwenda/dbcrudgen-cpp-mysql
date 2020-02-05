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
#include <cppconn/statement.h>
#include <cppconn/resultset.h>

#include "../../sql/connectors/DatabaseConnector.h"
#include "MYSQLDatabaseConnectionParams.h"

//
// MYSQLDatabaseConnector
// //
class MYSQLDatabaseConnector : public DatabaseConnector {

private:
    bool autoConnect;
    MYSQLDatabaseConnectionParams &connectionParams;
    sql::Driver *driver;
    sql::Connection *connection;
public:
    explicit MYSQLDatabaseConnector(MYSQLDatabaseConnectionParams &connectionParams,
                                    bool autoConnect)
            : connectionParams{connectionParams}, autoConnect{autoConnect} {

        connection = nullptr;

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

    /**
     * Create a statement
     * @return
     */
    sql::Statement &createStatement() {
        return *connection->createStatement();
    }

    /**
     * Executes the sql query
     * @param sql
     * @return result set
     */
    sql::ResultSet &executeQuery(const sql::SQLString sql) {
        return *createStatement().executeQuery(sql);
    }

    bool open() override {

        sql::SQLString host = connectionParams.getHost();
        sql::SQLString user = connectionParams.getUsername();
        sql::SQLString password = connectionParams.getPassword();
        sql::SQLString schemas = connectionParams.getSchemas();

        connection = driver->connect(host, user, password);

        if (schemas != "") {
            connection->setSchema(schemas);
        }


        return connection != nullptr;
    }

    bool isOpen() override {
        return connection != nullptr;
    }

    bool close() override {
        connection->close();
    }

    void onError(const std::string &errorLevel, const std::string &errorMessage, bool logError) override {
        DatabaseConnector::onError(errorLevel, errorMessage, logError);
    }

    MYSQLDatabaseConnectionParams &getConnectionParams() {
        return connectionParams;
    }

    ~MYSQLDatabaseConnector() {
        if (isOpen()) { close(); }
    }
};


#endif //DBCRUDGEN_CPP_MYSQLDATABASECONNECTOR_H
