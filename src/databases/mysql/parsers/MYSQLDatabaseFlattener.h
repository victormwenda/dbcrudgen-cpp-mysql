//
// Created by victor on 3/21/20.
//

#ifndef DBCRUDGEN_CPP_MYSQLDATABASEFLATTENER_H
#define DBCRUDGEN_CPP_MYSQLDATABASEFLATTENER_H

#include "../models/MYSQLDatabaseModel.h"
#include "../../generic/Database.h"

namespace dbcrudgen {
    namespace db {
        namespace mysql {

            /**
             * Creates a generic database out of a MYSQL Database
             */
            class MYSQLDatabaseFlattener {

            public:

                /**
                 * Flatten a MYSQL Database to a Generic Database
                 * @param mysqlDatabase
                 * @return
                 */
                static dbcrudgen::db::generic::Database
                flatten(const dbcrudgen::db::mysql::MYSQLDatabaseModel &mysqlDatabase) {

                    std::vector<dbcrudgen::db::generic::Table> genericTables{};

                    std::string databaseName = mysqlDatabase.getDatabaseName();
                    const auto &mysqlTables = mysqlDatabase.getTables();
                    const auto &mysqlTablesColumns = mysqlDatabase.getTableColumns();

                    const auto &mysqlForeignKeyColumns = mysqlDatabase.getForeignKeyColumns();
                    const auto &mysqlKeyColumns = mysqlDatabase.getKeyColumns();
                    const auto &mysqlPrimaryKeyColumns = mysqlDatabase.getPrimaryKeyColumns();

                    for (const auto &mysqlTable : mysqlTables) {

                        std::string tableName = mysqlTable.getTableName();

                        auto mysqlTableColumnsIterator = mysqlTablesColumns.find(tableName);

                        auto mysqlTableColumns = mysqlTableColumnsIterator->second;

                        //All table columns
                        std::map<std::string, std::vector<dbcrudgen::db::generic::Column>> genericTableColumnsMap;
                        std::vector<dbcrudgen::db::generic::Column> genericColumns =
                                getAllColumns(mysqlDatabase, mysqlTable, mysqlTableColumns);

                        genericTableColumnsMap.insert(
                                std::pair<std::string, std::vector<dbcrudgen::db::generic::Column>>(tableName,
                                                                                                    genericColumns));


                        //Primary columns
                        std::vector<dbcrudgen::db::generic::Column> primaryCols;
                        auto mysqlPriColsIter = mysqlPrimaryKeyColumns.find(tableName);
                        if (mysqlPriColsIter != mysqlPrimaryKeyColumns.end()) {
                            auto mysqlPriCols = mysqlPriColsIter->second;
                            primaryCols = getPrimaryColumns(tableName, mysqlPriCols);
                        }


                        //Key Columns
                        std::vector<dbcrudgen::db::generic::Column> keyCols;
                        auto mysqlKeyColsIter = mysqlKeyColumns.find(tableName);
                        if (mysqlKeyColsIter != mysqlKeyColumns.end()) {
                            auto mysqlKeyCols = mysqlPriColsIter->second;
                            primaryCols = getKeyColumns(tableName, mysqlKeyCols);
                        }

                        //Foreign Columns
                        std::vector<dbcrudgen::db::generic::Column> foreignCols;
                        auto mysqlForeignColsIter = mysqlForeignKeyColumns.find(tableName);
                        if (mysqlForeignColsIter != mysqlForeignKeyColumns.end()) {
                            auto mysqlForeignCols = mysqlForeignColsIter->second;
                            foreignCols = getForeignColumns(tableName, mysqlForeignCols);
                        }

                        dbcrudgen::db::generic::Table genericTable{databaseName, tableName, genericColumns, primaryCols,
                                                                   keyCols, foreignCols};

                        genericTables.emplace_back(genericTable);
                    }


                    const MYSQLDatabaseModelBuilder &builder = mysqlDatabase.getModelBuilder();
                    std::string host = builder.getHost();
                    int port = builder.getPort();
                    std::string user = builder.getUser();
                    std::string password = builder.getPassword();
                    dbcrudgen::db::generic::Connection connection{host, port, user, password, databaseName};
                    dbcrudgen::db::generic::Flavor flavor = dbcrudgen::db::generic::Flavor::MYSQL;
                    dbcrudgen::db::generic::Database database{connection, flavor, genericTables};

                    return database;
                }

                static std::vector<dbcrudgen::db::generic::Column>
                getAllColumns(const dbcrudgen::db::mysql::MYSQLDatabaseModel &mysqlDatabase,
                              const dbcrudgen::db::mysql::Tables &mysqlTable,
                              std::vector<dbcrudgen::db::mysql::Columns> &mysqlTableColumns) {

                    std::vector<dbcrudgen::db::generic::Column> genericColumns;

                    std::string tableName = mysqlTable.getTableName();

                    for (const auto &mysqlColumn : mysqlTableColumns) {

                        std::string columnName = mysqlColumn.getColumnName();
                        std::string dataType = mysqlColumn.getDataType();
                        std::string defaultValue = mysqlColumn.getColumnDefault();
                        bool nullable = mysqlColumn.getIsNullable() == "YES";
                        long length = mysqlColumn.getCharacterMaximumLength();
                        bool primary = isPrimaryKeyColumn(mysqlDatabase, mysqlTable, mysqlColumn);

                        dbcrudgen::db::generic::Column column{columnName, tableName, dataType, defaultValue, nullable,
                                                              length, primary};

                        genericColumns.emplace_back(column);

                    }

                    return genericColumns;
                }

                /**
                 * Validates if a column is a primary key column
                 * @param databaseModel
                 * @param table
                 * @param column
                 * @return
                 */
                static bool isPrimaryKeyColumn(const dbcrudgen::db::mysql::MYSQLDatabaseModel &databaseModel,
                                               const dbcrudgen::db::mysql::Tables &table,
                                               const Columns &column) {

                    const std::map<std::string, std::vector<Columns>> &tablePrimaryKeys
                            = databaseModel.getPrimaryKeyColumns();

                    const std::map<std::string, std::vector<Columns>>::const_iterator &iterator
                            = tablePrimaryKeys.find(table.getTableName());

                    if (iterator == tablePrimaryKeys.end()) {
                        return false;
                    }

                    const std::vector<Columns> &columns = iterator->second;

                    for (const Columns &col : columns) {
                        if (col.getColumnName() == column.getColumnName()) {
                            return true;
                        }
                    }

                    return false;
                }

                static std::vector<dbcrudgen::db::generic::Column>
                getPrimaryColumns(std::string &tableName,
                                  const std::vector<dbcrudgen::db::mysql::Columns> &mysqlTablePrimaryCols) {

                    std::vector<dbcrudgen::db::generic::Column> genericPrimaryKeyCols;

                    for (const auto &mysqlColumn : mysqlTablePrimaryCols) {

                        std::string columnName = mysqlColumn.getColumnName();
                        std::string dataType = mysqlColumn.getDataType();
                        std::string defaultValue = mysqlColumn.getColumnDefault();
                        bool nullable = mysqlColumn.getIsNullable() == "YES";
                        long length = mysqlColumn.getCharacterMaximumLength();
                        bool primary = true;

                        dbcrudgen::db::generic::Column column{columnName, tableName, dataType, defaultValue, nullable,
                                                              length, primary};

                        genericPrimaryKeyCols.emplace_back(column);

                    }

                    return genericPrimaryKeyCols;
                }

                static std::vector<dbcrudgen::db::generic::Column>
                getForeignColumns(std::string &tableName,
                                  const std::vector<dbcrudgen::db::mysql::Columns> &mysqlTablePrimaryCols) {

                    std::vector<dbcrudgen::db::generic::Column> genericPrimaryKeyCols;

                    for (const auto &mysqlColumn : mysqlTablePrimaryCols) {

                        std::string columnName = mysqlColumn.getColumnName();
                        std::string dataType = mysqlColumn.getDataType();
                        std::string defaultValue = mysqlColumn.getColumnDefault();
                        bool nullable = mysqlColumn.getIsNullable() == "YES";
                        long length = mysqlColumn.getCharacterMaximumLength();
                        bool primary = false; //TODO Fix

                        dbcrudgen::db::generic::Column column{columnName, tableName, dataType, defaultValue, nullable,
                                                              length, primary};

                        genericPrimaryKeyCols.emplace_back(column);

                    }

                    return genericPrimaryKeyCols;
                }

                static std::vector<dbcrudgen::db::generic::Column>
                getKeyColumns(std::string &tableName,
                              const std::vector<dbcrudgen::db::mysql::Columns> &mysqlTablePrimaryCols) {

                    std::vector<dbcrudgen::db::generic::Column> genericPrimaryKeyCols;

                    for (const auto &mysqlColumn : mysqlTablePrimaryCols) {

                        std::string columnName = mysqlColumn.getColumnName();
                        std::string dataType = mysqlColumn.getDataType();
                        std::string defaultValue = mysqlColumn.getColumnDefault();
                        bool nullable = mysqlColumn.getIsNullable() == "YES";
                        long length = mysqlColumn.getCharacterMaximumLength();
                        bool primary = false;//TODO Fix

                        dbcrudgen::db::generic::Column column{columnName, tableName, dataType, defaultValue, nullable,
                                                              length, primary};

                        genericPrimaryKeyCols.emplace_back(column);

                    }

                    return genericPrimaryKeyCols;
                }
            };
        }
    }
}
#endif //DBCRUDGEN_CPP_MYSQLDATABASEFLATTENER_H
