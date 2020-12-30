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
                            return false;
                        default:
                            std::cout << "FAILED :: " << allocReturn << std::endl;
                            return false;
                    }
                }

                void freeStatementHandle() {
                    SQLFreeHandle(SQL_HANDLE_STMT, hSmt);
                }
            };
        }
    }
}
#endif //DBCRUDGEN_CPP_MSSQLQUERYEXECUTOR_H
