//
// Created by victor on 12/26/20.
//

#ifndef DBCRUDGEN_CPP_MSSQLQUERYEXECUTOR_H
#define DBCRUDGEN_CPP_MSSQLQUERYEXECUTOR_H

#include <autotest.h>

namespace dbcrudgen {
    namespace db {
        namespace mssql {
            class MSSQLQueryExecutor {
            private:
                SQLHDBC hDbc;
                SQLHSTMT hSmt = nullptr;
            public:
                explicit MSSQLQueryExecutor(const SQLHDBC &hDbc) : hDbc{hDbc} {
                    createStatementHandle();
                }

                /**
                 * Create statement handle
                 * @return
                 */
                bool createStatementHandle() {
                    SQLRETURN allocReturn = SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hSmt);
                    switch (allocReturn) {
                        case SQL_SUCCESS:
                            std::cout << " ALLOCATE STATEMENT HANDLE SUCCESS" << std::endl;
                            return true;
                        case SQL_SUCCESS_WITH_INFO:
                            std::cout << " ALLOCATE STATEMENT HANDLE  SUCCESS WITH INFO" << std::endl;
                            return true;
                        case SQL_INVALID_HANDLE:
                            std::cout << " ALLOCATE STATEMENT HANDLE  FAILED INVALID HANDLE" << std::endl;
                            return false;
                        case SQL_ERROR:
                            std::cout << " ALLOCATE STATEMENT HANDLE  FAILED SQL ERROR" << std::endl;
                            printErrorDiagInfo(SQL_HANDLE_STMT, hDbc, 1);
                            return false;
                        default:
                            std::cout << "FAILED :: " << allocReturn << std::endl;
                            return false;
                    }
                }

                /**
                 * Free statement handle
                 */
                void freeStatementHandle() {
                    SQLFreeHandle(SQL_HANDLE_STMT, hSmt);
                }

                /**
                 * Prepare statement
                 * @param statement
                 * @return
                 */
                bool prepareStatement(const std::string &statement) {
                    SQLCHAR *query = (SQLCHAR *) statement.c_str();
                    std::cout << query << std::endl;
                    SQLRETURN prepareStmt = SQLPrepare(hSmt, query, SQL_NTS);

                    switch (prepareStmt) {
                        case SQL_SUCCESS:
                            std::cout << " PREPARE STATEMENT   SUCCESS" << std::endl;
                            return true;
                        case SQL_SUCCESS_WITH_INFO:
                            std::cout << " PREPARE STATEMENT    SUCCESS WITH INFO" << std::endl;
                            return true;
                        case SQL_INVALID_HANDLE:
                            std::cout << " PREPARE STATEMENT    FAILED INVALID HANDLE" << std::endl;
                            return false;
                        case SQL_ERROR:
                            std::cout << " PREPARE STATEMENT    FAILED SQL ERROR" << std::endl;
                            printErrorDiagInfo(SQL_HANDLE_STMT, hSmt, 1);
                            return false;
                        default:
                            std::cout << "FAILED :: " << prepareStmt << std::endl;
                            return false;
                    }

                }

                /**
                 * Print SQL Error
                 * @param handleType
                 * @param sqlHandle
                 * @param recNumber
                 */
                static void printErrorDiagInfo(SQLSMALLINT handleType, SQLHANDLE sqlHandle, SQLSMALLINT recNumber = 1) {
                    SQLCHAR sqlState[10];
                    SQLINTEGER nativeError;
                    SQLCHAR messageTxt[256];
                    SQLSMALLINT length;
                    SQLGetDiagRec(handleType, sqlHandle, recNumber, sqlState, &nativeError, messageTxt,
                                  sizeof(messageTxt), &length);
                    printf("%s:%d:%d:%s\n", sqlState, 1, nativeError, messageTxt);
                }

                /**
                 * Execute query
                 * @param sqlQuery
                 */
                void execQuery(const std::string &sqlQuery) {
                    bool prepStmt = prepareStatement(sqlQuery);
                    if (prepStmt) {
                        std::cout << "prepare success" << std::endl;

                        unsigned long numRows;
                        SQLUSMALLINT rowStatus[20];
                        SQLRETURN fetchResponse = SQLExtendedFetch(hSmt, SQL_FETCH_NEXT, 0, &numRows, rowStatus);

                        switch (fetchResponse) {
                            case SQL_SUCCESS:
                                std::cout << "FETCH SUCCESS" << std::endl;
                                break;
                            case SQL_SUCCESS_WITH_INFO:
                                std::cout << "FETCH SUCCESS WITH INFO" << std::endl;
                                break;
                            case SQL_INVALID_HANDLE:
                                std::cout << "FETCH FAILED INVALID HANDLE" << std::endl;
                                break;
                            case SQL_ERROR:
                                std::cout << "FETCH FAILED SQL ERROR" << std::endl;
                                printErrorDiagInfo(SQL_HANDLE_STMT, hSmt, 1);
                                break;
                            default:
                                std::cout << "FAILED :: " << fetchResponse << std::endl;
                        }


                    } else {
                        std::cout << "prep stmt failed " << std::endl;
                    }
                }
            };
        }
    }
}
#endif //DBCRUDGEN_CPP_MSSQLQUERYEXECUTOR_H
