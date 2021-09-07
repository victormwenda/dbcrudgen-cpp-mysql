//
// Created by victor on 9/7/21.
//

#ifndef DBCRUDGEN_CPP_SPTABLESDECOMPOSER_H
#define DBCRUDGEN_CPP_SPTABLESDECOMPOSER_H

#include "../scaffolding/sp/SpTables.h"
#include "../executor/MSSQLResultSet.h"

namespace dbcrudgen {
    namespace db {
        namespace mssql {
            class SpTablesDecomposer {
            private:
                dbcrudgen::db::mssql::MSSQLQueryExecutor executor;
            public:
                SpTablesDecomposer() = default;

                /**
                 * Invokes the stored procedure sp_tables
                 * @param executor
                 */
                explicit SpTablesDecomposer(dbcrudgen::db::mssql::MSSQLQueryExecutor &executor) : executor{executor} {}

                /**
                 * Get Tables
                 * @return
                 */
                std::vector<dbcrudgen::db::mssql::SpTables> getTables() {
                    std::vector<dbcrudgen::db::mssql::MSSQLColBinder> colBindings;
                    std::vector<dbcrudgen::db::mssql::SpTables> tables;

                    {
                        SQLCHAR table_qualifier[255];
                        std::string columnName{SpTables::COLUMNS::TABLE_QUALIFIER::NAME};
                        SQLLEN indicator;
                        colBindings.emplace_back(MSSQLColBinder{SpTables::COLUMNS::TABLE_QUALIFIER::INDEX,
                                                                SQL_C_CHAR, columnName, table_qualifier,
                                                                255, &indicator});

                    }
                    {
                        SQLCHAR table_owner[255];
                        std::string columnName{SpTables::COLUMNS::TABLE_OWNER::NAME};
                        SQLLEN indicator;
                        colBindings.emplace_back(MSSQLColBinder{SpTables::COLUMNS::TABLE_OWNER::INDEX,
                                                                SQL_C_CHAR, columnName, table_owner,
                                                                255, &indicator});

                    }
                    {
                        SQLCHAR table_name[255];
                        std::string columnName{SpTables::COLUMNS::TABLE_NAME::NAME};
                        SQLLEN indicator;
                        colBindings.emplace_back(MSSQLColBinder{SpTables::COLUMNS::TABLE_NAME::INDEX,
                                                                SQL_C_CHAR, columnName, table_name,
                                                                255, &indicator});

                    }
                    {
                        SQLCHAR table_type[255];
                        std::string columnName{SpTables::COLUMNS::TABLE_TYPE::NAME};
                        SQLLEN indicator;
                        colBindings.emplace_back(MSSQLColBinder{SpTables::COLUMNS::TABLE_TYPE::INDEX,
                                                                SQL_C_CHAR, columnName, table_type,
                                                                255, &indicator});

                    }
                    {
                        SQLCHAR remarks[255];
                        std::string columnName{SpTables::COLUMNS::REMARKS::NAME};
                        SQLLEN indicator;
                        colBindings.emplace_back(MSSQLColBinder{SpTables::COLUMNS::REMARKS::INDEX,
                                                                SQL_C_CHAR, columnName, remarks,
                                                                255, &indicator});

                    }

                    std::string table_qualifier;
                    std::string table_owner;
                    std::string table_name;
                    std::string table_type;
                    std::string remarks;

                    std::vector<MSSQLResultSet> resultSet{};
                    std::string query{MSSQLQueries::SP_TABLES};
                    executor.execQuery(query, colBindings, resultSet);

                    int loopTracker = 0;
                    for (const dbcrudgen::db::mssql::MSSQLResultSet &result: resultSet) {
                        loopTracker++;
                        void *colValue = result.getColumnValue();
                        switch (result.getColumnIndex()) {
                            case dbcrudgen::db::mssql::SpTables::COLUMNS::TABLE_QUALIFIER::INDEX:
                                table_qualifier = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case dbcrudgen::db::mssql::SpTables::COLUMNS::TABLE_OWNER::INDEX:
                                table_owner = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case dbcrudgen::db::mssql::SpTables::COLUMNS::TABLE_NAME::INDEX:
                                table_name = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case dbcrudgen::db::mssql::SpTables::COLUMNS::TABLE_TYPE::INDEX:
                                table_type = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case dbcrudgen::db::mssql::SpTables::COLUMNS::REMARKS::INDEX:
                                remarks = *reinterpret_cast<std::string *>(colValue);
                                break;
                        }

                        if (loopTracker == colBindings.size()) {
                            tables.emplace_back(
                                    SpTables{table_qualifier, table_owner, table_name, table_type, remarks});
                            loopTracker = 0;
                        }
                    }

                    return tables;
                }
            };
        }
    }
}

#endif //DBCRUDGEN_CPP_SPTABLESDECOMPOSER_H
