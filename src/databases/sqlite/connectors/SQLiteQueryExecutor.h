//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 7/11/17.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_SQLITEQUERYEXECUTOR_H
#define DBCRUDGEN_CPP_SQLITEQUERYEXECUTOR_H

#include <sqlite3.h>

#include "../../sql/connectors/DatabaseConnector.h"
#include "SQLiteDatabaseConnector.h"

//
// SQLiteQueryExecutor
// //
class SQLiteQueryExecutor {
private:
    std::string schema;
    SQLiteDatabaseConnector *connector;
public:
    SQLiteQueryExecutor(SQLiteDatabaseConnector *connector, const std::string schema)
            : connector(connector), schema(schema) {
        setSchema(schema);
    }

    /**
     * Change the database
     * @param schema
     */
    void setSchema(const std::string schema) {
        SQLiteQueryExecutor::schema = schema;
        connector->changeSchema(schema);
    }

    void executeQuery(const char *query) {
        connector->exec(query);
    }
};


#endif //DBCRUDGEN_CPP_SQLITEQUERYEXECUTOR_H
