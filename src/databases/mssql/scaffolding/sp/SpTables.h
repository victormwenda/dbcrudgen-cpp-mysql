//
// Created by victor on 9/7/21.
//

#ifndef DBCRUDGEN_CPP_SPTABLES_H
#define DBCRUDGEN_CPP_SPTABLES_H

#include <string>

namespace dbcrudgen {
    namespace db {
        namespace mssql {
            /**
             * Returns a list of objects that can be queried in the current environment.
             * This means any table or view, except synonym objects.
             * sp_tables [ [ @table_name = ] 'name' ]
             *   [ , [ @table_owner = ] 'owner' ]
             *   [ , [ @table_qualifier = ] 'qualifier' ]
             *   [ , [ @table_type = ] "type" ]
             *   [ , [@fUsePattern = ] 'fUsePattern'];
             *   https://docs.microsoft.com/en-us/sql/relational-databases/system-stored-procedures/sp-tables-transact-sql?view=sql-server-ver15
             */
            class SpTables {

            private:
                std::string table_qualifier;
                std::string table_owner;
                std::string table_name;
                std::string table_type;
                std::string remarks;
            public:
                static constexpr const char *TABLE_NAME = "sp_tables";

                struct COLUMNS {
                    struct TABLE_QUALIFIER {
                        static constexpr const int INDEX = 1;
                        static constexpr const char *NAME = "table_qualifier";
                        static constexpr const char *DATA_TYPE = "varchar";
                    };
                    struct TABLE_OWNER {
                        static constexpr const int INDEX = 2;
                        static constexpr const char *NAME = "table_owner";
                        static constexpr const char *DATA_TYPE = "varchar";
                    };
                    struct TABLE_NAME {
                        static constexpr const int INDEX = 3;
                        static constexpr const char *NAME = "table_name";
                        static constexpr const char *DATA_TYPE = "varchar";
                    };
                    struct TABLE_TYPE {
                        static constexpr const int INDEX = 4;
                        static constexpr const char *NAME = "table_type";
                        static constexpr const char *DATA_TYPE = "varchar";
                    };
                    struct REMARKS {
                        static constexpr const int INDEX = 5;
                        static constexpr const char *NAME = "remarks";
                        static constexpr const char *DATA_TYPE = "varchar";
                    };
                };

                SpTables(std::string &tableQualifier, std::string &tableOwner, std::string &tableName,
                         std::string &tableType, std::string &remarks)
                        : table_qualifier(tableQualifier), table_owner(tableOwner), table_name(tableName),
                          table_type(tableType), remarks(remarks) {}

                const std::string &getTableQualifier() const {
                    return table_qualifier;
                }

                void setTableQualifier(const std::string &tableQualifier) {
                    table_qualifier = tableQualifier;
                }

                const std::string &getTableOwner() const {
                    return table_owner;
                }

                void setTableOwner(const std::string &tableOwner) {
                    table_owner = tableOwner;
                }

                const std::string &getTableName() const {
                    return table_name;
                }

                void setTableName(const std::string &tableName) {
                    table_name = tableName;
                }

                const std::string &getTableType() const {
                    return table_type;
                }

                void setTableType(const std::string &tableType) {
                    table_type = tableType;
                }

                const std::string &getRemarks() const {
                    return remarks;
                }

                void setRemarks(const std::string &remarks) {
                    SpTables::remarks = remarks;
                }
            };
        }
    }
}
#endif //DBCRUDGEN_CPP_SPTABLES_H
