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
                            std::cout << " ALLOCATE ENVIRONMENT SUCCESS" << std::endl;
                            return true;
                        case SQL_SUCCESS_WITH_INFO:
                            std::cout << " ALLOCATE ENVIRONMENT SUCCESS WITH INFO" << std::endl;
                            return true;
                        case SQL_INVALID_HANDLE:
                            std::cout << " ALLOCATE ENVIRONMENT FAILED INVALID HANDLE" << std::endl;
                            return false;
                        case SQL_ERROR:
                            std::cout << " ALLOCATE ENVIRONMENT FAILED SQL ERROR" << std::endl;
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
                            std::cout << " ALLOCATE ENVIRONMENT SUCCESS" << std::endl;
                            return true;
                        case SQL_SUCCESS_WITH_INFO:
                            std::cout << " ALLOCATE ENVIRONMENT SUCCESS WITH INFO" << std::endl;
                            return true;
                        case SQL_INVALID_HANDLE:
                            std::cout << " ALLOCATE ENVIRONMENT FAILED INVALID HANDLE" << std::endl;
                            return false;
                        case SQL_ERROR:
                            std::cout << " ALLOCATE ENVIRONMENT FAILED SQL ERROR" << std::endl;
                            return false;
                        default:
                            std::cout << "FAILED :: " << setEnvReturn << std::endl;
                            return false;
                    }
                }

                /**
                 * Allocate connection handle
                 * @return
                 */
                SQLRETURN allocateConnectionHandle() {
                    return SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
                }

                bool createConnection() {
                    std::string dbConnStr = getConnParams().getConnStr();
                    SQLCHAR *connStr = (SQLCHAR *) dbConnStr.c_str();
                    SQLRETURN conn = SQLDriverConnect(hDbc, nullptr, connStr, SQL_NTS, nullptr,
                                                      0, nullptr, SQL_DRIVER_COMPLETE);
                    switch (conn) {
                        case SQL_SUCCESS:
                            std::cout << " DB CONN SUCCESS" << std::endl;
                        case SQL_SUCCESS_WITH_INFO:
                            std::cout << " DB CONN WITH INFO" << std::endl;
                            return true;
                        case SQL_INVALID_HANDLE:
                            std::cout << " INVALID DB CONN HANDLE" << std::endl;
                        default:
                            return false;

                    }
                }

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

                void openConnection() {

                    if (allocateEnvironmentHandle()) {
                        std::cout << "allocated env handle" << std::endl;

                        if (allocateEnvironment()) {
                            std::cout << "allocated env" << std::endl;
                        } else {
                            std::cout << "could not allocate env";
                        }

                    } else {
                        std::cerr << " could not allocate env handle" << std::endl;
                    }


                }
            };

        }
    }
}
#endif //DBCRUDGEN_CPP_MSSQLDBCONNECTOR_H
