//
// Created by victor on 8/31/21.
//

#ifndef DBCRUDGEN_CPP_MSSQLDATABASEDECOMPOSER_H
#define DBCRUDGEN_CPP_MSSQLDATABASEDECOMPOSER_H

#include "../connectors/MSSQLDbConnParams.h"
#include "../connectors/MSSQLDbConnector.h"
#include "../executor/MSSQLQueryExecutor.h"
#include "../executor/MSSQLColBinder.h"
#include "../executor/MSSQLResultSet.h"
#include "../scaffolding/queries/MSSQLQueries.h"
#include "../scaffolding/entities/SysDatabases.h"
#include "SysDatabasesDecomposer.h"

namespace dbcrudgen {
    namespace db {
        namespace mssql {
            class MSSQLDatabaseDecomposer {
            private:
                dbcrudgen::db::mssql::MSSQLDbConnector connector;
                dbcrudgen::db::mssql::MSSQLQueryExecutor executor;
                SQLHDBC hDbc = nullptr;
            protected:
                dbcrudgen::db::mssql::SysDatabasesDecomposer sysDatabasesDecomposer;
            public:
                /**
                 * MSSQL Database Decomposer
                 * @param connector
                 */
                explicit MSSQLDatabaseDecomposer(dbcrudgen::db::mssql::MSSQLDbConnector connector)
                        : connector{connector} {
                    connector.openConnection();
                    hDbc = connector.getHDbc();
                    executor = dbcrudgen::db::mssql::MSSQLQueryExecutor{hDbc};
                    sysDatabasesDecomposer = dbcrudgen::db::mssql::SysDatabasesDecomposer{executor};
                }
                /**
                 * Get sys databases
                 * Executes SELECT * FROM SYS.DATABASES;
                 * @return
                 */
                std::vector<dbcrudgen::db::mssql::SysDatabases> getSysDatabases() {
                    return sysDatabasesDecomposer.getSysDatabases();
                }

                ~MSSQLDatabaseDecomposer() {
                    std::cout << "killing connections";
                    executor.freeStatementHandle();
                    connector.closeConnection();
                }

            };
        }
    }
}

#endif //DBCRUDGEN_CPP_MSSQLDATABASEDECOMPOSER_H
