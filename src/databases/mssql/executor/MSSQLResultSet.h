//
// Created by victor on 8/31/21.
//

#ifndef DBCRUDGEN_CPP_MSSQLRESULTSET_H
#define DBCRUDGEN_CPP_MSSQLRESULTSET_H

#include <sqlext.h>
#include <autotest.h>
#include <string>

namespace dbcrudgen {
    namespace db {
        namespace mssql {
            /**
             * MSSQL Result Set
             *  - Contains the data returned from the database
             */
            class MSSQLResultSet {
            public:

                int columnIndex;
                std::string columnName;
                short dataType;

                char cColumnValue;
                bool bColumnValue;
                short shColumnValue;
                int iColumnValue;
                float fColumnValue;
                double dColumnValue;
                long lColumnValue;
                std::string strColumnValue;

                /**
                 * MSSQL Result Set
                 * - Contains the data returned from the database
                 * @param columnIndex
                 * @param columnName
                 * @param dataType
                 * @param columnValue
                 */
                MSSQLResultSet(int &columnIndex, std::string &columnName, SQLSMALLINT &dataType, SQLPOINTER columnValue)
                        : columnIndex(columnIndex), dataType(dataType), columnName(columnName) {
                    setColumnValue(columnValue);
                }

                int getColumnIndex() const {
                    return columnIndex;
                }

                void setColumnIndex(int &columnIndex) {
                    MSSQLResultSet::columnIndex = columnIndex;
                }

                const std::string &getColumnName() const {
                    return columnName;
                }

                void setColumnName(const std::string &columnName) {
                    MSSQLResultSet::columnName = columnName;
                }

                /**
                 * Get column value
                 * @return void* ptr of column value. user *reinterpret_cast<datatype>(pVoid) to get value of object
                 */
                void *getColumnValue() const {
                    switch (dataType) {
                        case SQL_C_BINARY:
                            break;
                        case SQL_C_BIT:
                            return const_cast<bool *>( reinterpret_cast<const bool *>(&bColumnValue));
                        case SQL_C_CHAR:
                            return (char *) &strColumnValue;
                        case SQL_C_DOUBLE:
                            break;
                        case SQL_C_FLOAT:
                            break;
                        case SQL_C_LONG:
                            return const_cast<long *>(reinterpret_cast<const long *>(&lColumnValue));
                            break;
                        case SQL_C_SHORT:
                            break;
                        case SQL_C_TYPE_DATE:
                            break;
                        case SQL_C_TYPE_TIME:
                            break;
                        case SQL_C_TYPE_TIMESTAMP:
                            break;
                        case SQL_C_TINYINT:
                            break;
                        case SQL_C_WCHAR:
                            break;
                    }
                    return nullptr;
                }

                /**
                 * Set column value
                 * @param ptrColumnValue
                 */
                void setColumnValue(SQLPOINTER ptrColumnValue) {

                    switch (dataType) {
                        case SQL_C_BINARY:
                            std::cout << "SQL_C_BINARY : " << dataType << std::endl;
                            break;
                        case SQL_C_BIT:
                            bColumnValue = *reinterpret_cast<bool *>(ptrColumnValue);
                            break;
                        case SQL_C_CHAR: //1
                            strColumnValue = std::string(
                                    reinterpret_cast<const char *>(reinterpret_cast<SQLCHAR *>(ptrColumnValue)));
                            break;
                        case SQL_C_DOUBLE:
                            std::cout << "SQL_C_DOUBLE : " << dataType << std::endl;
                            break;
                        case SQL_C_FLOAT:
                            std::cout << "SQL_C_FLOAT : " << dataType << std::endl;
                            break;
                        case SQL_C_LONG: //4
                            lColumnValue = *reinterpret_cast<SQLINTEGER *>(ptrColumnValue);
                            break;
                        case SQL_C_SHORT:
                            std::cout << "SQL_C_SHORT : " << dataType << std::endl;
                            break;
                        case SQL_C_TYPE_DATE:
                            std::cout << "SQL_C_TYPE_DATE : " << dataType << std::endl;
                            break;
                        case SQL_C_TYPE_TIME:
                            std::cout << "SQL_C_TYPE_TIME : " << dataType << std::endl;
                            break;
                        case SQL_C_TYPE_TIMESTAMP:
                            std::cout << "SQL_C_TYPE_TIMESTAMP : " << dataType << std::endl;
                            break;
                        case SQL_C_TINYINT:
                            std::cout << "SQL_C_TINYINT : " << dataType << std::endl;
                            break;
                        case SQL_C_WCHAR:
                            std::cout << "SQL_C_WCHAR : " << dataType << std::endl;
                            break;
                        default:
                            std::cout << "Cannot get value for column: " << columnName << " of data type : " << dataType
                                      << std::endl;
                            break;
                    }
                }
            };
        }
    }
}
#endif //DBCRUDGEN_CPP_MSSQLRESULTSET_H
