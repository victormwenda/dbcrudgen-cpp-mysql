//
// Created by victor on 8/31/21.
//

#ifndef DBCRUDGEN_CPP_MSSQLCOLBINDER_H
#define DBCRUDGEN_CPP_MSSQLCOLBINDER_H

#include <autotest.h>

namespace dbcrudgen {
    namespace db {
        namespace mssql {
            class MSSQLColBinder {
            public:
                int columnIndex;
                SQLSMALLINT dataType;
                std::string columnName;
                SQLPOINTER columnValue;
                SQLLEN columnValueLength;
                SQLLEN *ptrLengthBufferOrIndicator;

                MSSQLColBinder(int columnIndex, SQLSMALLINT dataType, std::string &columnName, SQLPOINTER columnValue,
                               SQLLEN columnValueLength, SQLLEN *ptrLengthBufferOrIndicator)
                        : columnIndex(columnIndex), dataType(dataType), columnName(columnName),
                          columnValue(columnValue), columnValueLength(columnValueLength),
                          ptrLengthBufferOrIndicator(ptrLengthBufferOrIndicator) {}
            };
        }
    }
}

#endif //DBCRUDGEN_CPP_MSSQLCOLBINDER_H
