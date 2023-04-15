//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 7/19/17.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_ORACLEDATABASECONNECTOR_H
#define DBCRUDGEN_CPP_ORACLEDATABASECONNECTOR_H


#include <occiControl.h>
#include "../../sql/connectors/DatabaseConnector.h"
#include "OracleDatabaseConnectionParams.h"

namespace dbcrudgen {
    namespace db {
        namespace oracle {

            //
            // OracleDatabaseConnector
            // //
            class OracleDatabaseConnector : public DatabaseConnector {

            private:
                bool autoConnect;
                OracleDatabaseConnectionParams connectionParams;
                ::oracle::occi::Environment *environment;
                ::oracle::occi::Connection *connection;
            public:
                OracleDatabaseConnector(const OracleDatabaseConnectionParams &connectionParams, bool autoConnect)
                        : autoConnect(autoConnect), connectionParams(connectionParams) {

                    environment = ::oracle::occi::Environment::createEnvironment(::oracle::occi::Environment::DEFAULT);

                    connection = nullptr;

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

                    try {
                        auto connDesc = connectionParams.getConnDesc();

                        connection = environment->createConnection(
                                connectionParams.getUsername(),
                                connectionParams.getPassword()
                        );
                    } catch (::oracle::occi::SQLException &exception) {
                        onError("FATAL_ERROR", exception.getMessage(), true);
                    }

                    return connection != nullptr;
                }

                bool isOpen() override {
                    return connection != nullptr;
                }

                /**
                 * Creates a statement
                 * @param sql
                 * @return
                 */
                ::oracle::occi::Statement &getStatement(const std::string &sql = "") {
                    return *connection->createStatement(sql);
                }

                /**
                 * Executes query
                 * @param sql
                 * @return result set
                 */
                ::oracle::occi::ResultSet &executeQuery(const std::string &sql) {
                    return *getStatement(sql).executeQuery();
                }

                void onError(const std::string &errorLevel, const std::string &errorMessage, bool logError) override {

                }

                bool close() override {
                    if (connection != nullptr) {
                        environment->terminateConnection(connection);
                    }

                    return false;
                }

                ~OracleDatabaseConnector() {
                    if (isOpen()) {
                        close();
                    }

                    if (environment != nullptr) {
                        ::oracle::occi::Environment::terminateEnvironment(environment);
                    }
                }
            };
        }
    }
}


#endif //DBCRUDGEN_CPP_ORACLEDATABASECONNECTOR_H
