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
#include "SpColumnsDecomposer.h"
#include "../scaffolding/sp/SpTables.h"
#include "SpTablesDecomposer.h"

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
                dbcrudgen::db::mssql::SpColumnsDecomposer spColsDecomposer;
                dbcrudgen::db::mssql::SpTablesDecomposer spTablesDecomposer;
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
                    spColsDecomposer = dbcrudgen::db::mssql::SpColumnsDecomposer{executor};
                    spTablesDecomposer = dbcrudgen::db::mssql::SpTablesDecomposer{executor};
                }

                /**
                 * Get sys databases
                 * Executes SELECT * FROM SYS.DATABASES;
                 * @return
                 */
                std::vector<dbcrudgen::db::mssql::SysDatabases> getSysDatabases() {
                    return sysDatabasesDecomposer.getSysDatabases();
                }

                /**
                 * Get table columns
                 * Executes sp_columns(@table_name, @table_owner , @table_qualifier , @column_name , @ODBCVer )
                 * @return
                 */
                std::vector<dbcrudgen::db::mssql::SpColumns> getTableColumns(const std::string &tableName) {
                    return spColsDecomposer.getTableColumns(tableName);
                }

                /**
                 * Get tables
                 * Executes sp_tables (@table_name, @table_owner, @table_qualifier, @table_type, @fUsePattern);

                 * @return
                 */
                std::vector<dbcrudgen::db::mssql::SpTables> getTables() {
                    return spTablesDecomposer.getTables();
                }

                ~MSSQLDatabaseDecomposer() {
                    executor.freeStatementHandle();
                    connector.closeConnection();
                }
            };
        }
    }
}

#endif //DBCRUDGEN_CPP_MSSQLDATABASEDECOMPOSER_H
