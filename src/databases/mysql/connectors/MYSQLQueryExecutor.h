//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 7/11/17.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_MYSQLQUERYEXECUTOR_H
#define DBCRUDGEN_CPP_MYSQLQUERYEXECUTOR_H

#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include "MYSQLDatabaseConnector.h"

namespace dbcrudgen {
    namespace db {
        namespace mysql {
            //
            // MYSQLQueryExecutor
            // //
            class MYSQLQueryExecutor {

            private:
                MYSQLDatabaseConnector *connector;
                sql::SQLString schema;

            public:
                /**
                 * MYSQL    Query Executor
                 * Performs MYSQL Queries
                 * @param connector the connection
                 * @param schema the database
                 */
                MYSQLQueryExecutor(MYSQLDatabaseConnector *connector, const sql::SQLString schema)
                        : connector(connector), schema(schema) {
                    connector->getConnection().setSchema(schema);
                }


                /**
                 * Change the database
                 * @param schema
                 */
                void setSchema(sql::SQLString schema) {
                    MYSQLQueryExecutor::schema = schema;
                    changeSchema(schema);
                }

                /**
                 * Change the database
                 * @param schema
                 */
                void changeSchema(sql::SQLString schema) {
                    connector->getConnection().setSchema(schema);
                }

                /**
                 * Get statement
                 * @return
                 */
                sql::Statement &getStatement() {
                    return *(connector->getConnection().createStatement());
                }

                /**
                 * Execute sql and return a result set
                 * @param sql
                 * @return
                 */
                sql::ResultSet &exec(sql::SQLString sql) {
                    return *(&getStatement())->executeQuery(sql);
                }
            };


        }
    }
}


#endif //DBCRUDGEN_CPP_MYSQLQUERYEXECUTOR_H
