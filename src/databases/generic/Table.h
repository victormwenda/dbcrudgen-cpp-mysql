//
// Created by victor on 3/21/20.
//

#ifndef DBCRUDGEN_CPP_TABLE_H
#define DBCRUDGEN_CPP_TABLE_H

#include <string>
#include <vector>
#include "Column.h"

namespace dbcrudgen {
    namespace db {
        namespace generic {

            /**
             * A generic database table
             */
            class Table {
            private:
                std::string databaseName;
                std::string tableName;
                std::vector<dbcrudgen::db::generic::Column> tableColumns;

            public:

                /**
                 * A Generic database table
                 * @param databaseName
                 * @param tableName
                 * @param tableColumns
                 */
                Table(std::string &databaseName, std::string &tableName,
                      std::vector<dbcrudgen::db::generic::Column> &tableColumns)
                        : databaseName(databaseName), tableName(tableName), tableColumns(tableColumns) {}

                const std::string &getDatabaseName() const {
                    return databaseName;
                }

                void setDatabaseName(const std::string &databaseName) {
                    Table::databaseName = databaseName;
                }

                const std::string &getTableName() const {
                    return tableName;
                }

                void setTableName(const std::string &tableName) {
                    Table::tableName = tableName;
                }

                const std::vector<dbcrudgen::db::generic::Column> &getTableColumns() const {
                    return tableColumns;
                }

                void setTableColumns(const std::vector<dbcrudgen::db::generic::Column> &tableColumns) {
                    Table::tableColumns = tableColumns;
                }
            };
        }
    }

}

#endif //DBCRUDGEN_CPP_TABLE_H
