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
                std::vector<dbcrudgen::db::generic::Column> primaryKeysColumns;
                std::vector<dbcrudgen::db::generic::Column> foreignKeysColumns;
                std::vector<dbcrudgen::db::generic::Column> indexKeysColumns;

            public:

                /**
                 * A Generic database table
                 * @param databaseName
                 * @param tableName
                 * @param tableColumns
                 */
                Table(std::string &databaseName, std::string &tableName,
                      std::vector<dbcrudgen::db::generic::Column> &tableColumns,
                      std::vector<dbcrudgen::db::generic::Column> &primaryKeysColumns,
                      std::vector<dbcrudgen::db::generic::Column> &indexKeysColumns,
                      std::vector<dbcrudgen::db::generic::Column> &foreignKeysColumns)
                        : databaseName(databaseName), tableName(tableName), tableColumns(tableColumns),
                          primaryKeysColumns(primaryKeysColumns), foreignKeysColumns(foreignKeysColumns),
                          indexKeysColumns(indexKeysColumns) {}

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

                const std::vector<dbcrudgen::db::generic::Column> &getPrimaryColumns() const {
                    return primaryKeysColumns;
                }

                void setPrimaryColumns(const std::vector<dbcrudgen::db::generic::Column> &primaryColumns) {
                    Table::primaryKeysColumns = primaryColumns;
                }

                const std::vector<dbcrudgen::db::generic::Column> &getForeignColumns() const {
                    return foreignKeysColumns;
                }

                void setForeignColumns(const std::vector<dbcrudgen::db::generic::Column> &foreignColumns) {
                    Table::foreignKeysColumns = foreignColumns;
                }

                const std::vector<dbcrudgen::db::generic::Column> &getIndexColumns() const {
                    return indexKeysColumns;
                }

                void setIndexColumns(const std::vector<dbcrudgen::db::generic::Column> &indexColumns) {
                    Table::indexKeysColumns = indexColumns;
                }
            };
        }
    }

}

#endif //DBCRUDGEN_CPP_TABLE_H
