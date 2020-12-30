//
// Created by victor on 12/26/20.
//

#ifndef DBCRUDGEN_CPP_MSSQLDBCONNECTOR_H
#define DBCRUDGEN_CPP_MSSQLDBCONNECTOR_H

#include "MSSQLDbConnParams.h"
#include <sql.h>
#include <sqlext.h>
#include <cstring>

namespace dbcrudgen {
    namespace db {
        namespace mssql {
            class MSSQLDbConnector {
            private:
                SQLHENV hEnv = nullptr;
                SQLHDBC hDbc = nullptr;
                dbcrudgen::db::mssql::MSSQLDbConnParams &connParams;
            public:
                explicit MSSQLDbConnector(dbcrudgen::db::mssql::MSSQLDbConnParams &params) : connParams(params) {

                }

                dbcrudgen::db::mssql::MSSQLDbConnParams &getConnParams() const {
                    return connParams;
                }

                /**
                 * Get database environment handle
                 * @return
                 */
                SQLHENV getHEnv() const {
                    return hEnv;
                }

                /**
                 * Get Database Connection Handle
                 * @return
                 */
                SQLHDBC getHDbc() const {
                    if (hDbc == nullptr) {
                        std::cout << "first check -- null" << std::endl;
                    }
                    return hDbc;
                }

                /**
                 * Allocate environment
                 * @return
                 */
                SQLRETURN allocateEnvironmentHandle() {

                    SQLRETURN allocReturn = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);

                    switch (allocReturn) {
                        case SQL_SUCCESS:
                            std::cout << "ALLOCATE ENVIRONMENT HANDLE SUCCESS" << std::endl;
                            return true;
                        case SQL_SUCCESS_WITH_INFO:
                            std::cout << "ALLOCATE ENVIRONMENT HANDLE  SUCCESS WITH INFO" << std::endl;
                            return true;
                        case SQL_INVALID_HANDLE:
                            std::cout << "ALLOCATE ENVIRONMENT HANDLE  FAILED INVALID HANDLE" << std::endl;
                            return false;
                        case SQL_ERROR:
                            std::cout << "ALLOCATE ENVIRONMENT HANDLE  FAILED SQL ERROR" << std::endl;
                            return false;
                        default:
                            std::cout << "FAILED :: " << allocReturn << std::endl;
                            return false;
                    }

                }

                /**
                 * Allocate environment handle
                 * https://docs.microsoft.com/en-us/sql/odbc/reference/syntax/sqlsetenvattr-function?view=sql-server-ver15
                 * @return
                 */
                bool allocateEnvironment() {

                    SQLRETURN setEnvReturn = SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER) SQL_OV_ODBC3, 0);

                    switch (setEnvReturn) {
                        case SQL_SUCCESS:
                            std::cout << "SET ENV ATTR SUCCESS" << std::endl;
                            return true;
                        case SQL_SUCCESS_WITH_INFO:
                            std::cout << "SET ENV ATTR  SUCCESS WITH INFO" << std::endl;
                            return true;
                        case SQL_INVALID_HANDLE:
                            std::cout << "SET ENV ATTR  FAILED INVALID HANDLE" << std::endl;
                            return false;
                        case SQL_ERROR:
                            std::cout << "SET ENV ATTR  FAILED SQL ERROR" << std::endl;
                            return false;
                        default:
                            std::cout << "ALLOCATE ENV FAILED :: ERROR CODE" << setEnvReturn << std::endl;
                            return false;
                    }
                }

                /**
                 * Allocate connection handle
                 * @return
                 */
                bool allocateConnectionHandle() {

                    SQLRETURN allocHandle = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);

                    switch (allocHandle) {
                        case SQL_SUCCESS:
                            std::cout << "SET CONN HANDLE SUCCESS" << std::endl;
                            return true;
                        case SQL_SUCCESS_WITH_INFO:
                            std::cout << "SET CONN HANDLE SUCCESS WITH INFO" << std::endl;
                            return true;
                        case SQL_INVALID_HANDLE:
                            std::cout << "SET CONN HANDLE FAILED INVALID HANDLE" << std::endl;
                            return false;
                        case SQL_ERROR:
                            std::cout << "SET CONN HANDLE FAILED SQL ERROR" << std::endl;
                            return false;
                        default:
                            std::cout << "CONNECTION HANDLE FAILED :: ERROR CODE" << allocHandle << std::endl;
                            return false;
                    }
                }

                bool createConnection() {
                    std::string dbConnStr = getConnParams().getConnStr();
                    SQLCHAR *connStr = (SQLCHAR *) dbConnStr.c_str();
                    SQLRETURN connResult = SQLDriverConnect(hDbc, nullptr, connStr, SQL_NTS, nullptr,
                                                            0, nullptr, SQL_DRIVER_COMPLETE);
                    std::cout << dbConnStr << std::endl;
                    switch (connResult) {
                        case SQL_SUCCESS:
                            std::cout << "DB CONN SUCCESS" << std::endl;
                        case SQL_SUCCESS_WITH_INFO:
                            std::cout << "DB CONN WITH INFO" << std::endl;
                            return true;
                        case SQL_INVALID_HANDLE:
                            std::cout << "INVALID DB CONN HANDLE" << std::endl;
                        default:
                            std::cout << "CONNECTION FAILED :: ERROR CODE : " << connResult << std::endl;
                            return false;

                    }
                }


                void openConnection() {

                    if (allocateEnvironmentHandle()) {
                        std::cout << "allocated env handle" << std::endl;

                        if (allocateEnvironment()) {
                            std::cout << "allocated env" << std::endl;


                            if (allocateConnectionHandle()) {
                                std::cout << "allocated conn handle" << std::endl;

                                if (createConnection()) {
                                    std::cout << "created conn" << std::endl;
                                } else {
                                    std::cout << "could not create conn" << std::endl;
                                }


                            } else {
                                std::cout << "could not allocate conn handle" << std::endl;
                            }


                        } else {
                            std::cout << "could not allocate env";
                        }

                    } else {
                        std::cerr << "could not allocate env handle" << std::endl;
                    }
                }

                /**
                 * Close SQL Server Connection
                 */
                void closeConnection() {
                    disconnect();
                    freeConnectionHandle();
                    freeEnvironmentHandle();
                }

            private:
                void disconnect() {
                    SQLDisconnect(hDbc);
                }

                bool freeConnectionHandle() {
                    if (hDbc != nullptr) {
                        SQLFreeHandle(SQL_HANDLE_DBC, hDbc);
                    }
                    return hDbc == nullptr;
                }

                bool freeEnvironmentHandle() {
                    if (hEnv != nullptr) {
                        SQLFreeHandle(SQL_HANDLE_ENV, hEnv);
                    }
                    return hEnv == nullptr;
                }
            };

        }
    }
}
#endif //DBCRUDGEN_CPP_MSSQLDBCONNECTOR_H
