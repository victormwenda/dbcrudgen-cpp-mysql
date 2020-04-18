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
                static dbcrudgen::db::generic::Database
                flatten(const dbcrudgen::db::mysql::MYSQLDatabaseModel &mysqlDatabase) {

                    std::vector<dbcrudgen::db::generic::Table> genericTables{};
                    std::map<std::string, std::vector<dbcrudgen::db::generic::Column>> genericColumns;

                    std::string databaseName = mysqlDatabase.getDatabaseName();
                    const auto &mysqlTables = mysqlDatabase.getTables();
                    const auto &mysqlTablesColumns = mysqlDatabase.getTableColumns();

                    for (const auto &mysqlTable : mysqlTables) {

                        std::string tableName = mysqlTable.getTableName();

                        auto mysqlTableColumnsIterator = mysqlTablesColumns.find(tableName);

                        auto mysqlTableColumns = mysqlTableColumnsIterator->second;

                        std::map<std::string, std::vector<dbcrudgen::db::generic::Column>> genericTableColumnsMap;
                        std::vector<dbcrudgen::db::generic::Column> genericColumns;

                        for (const auto &mysqlColumn : mysqlTableColumns) {

                            std::string columnName = mysqlColumn.getColumnName();
                            std::string dataType = mysqlColumn.getDataType();
                            std::string defaultValue = mysqlColumn.getColumnDefault();
                            bool nullable = mysqlColumn.getIsNullable() == "YES";
                            long length = mysqlColumn.getCharacterMaximumLength();
                            bool primary = false;

                            dbcrudgen::db::generic::Column column{columnName, tableName, dataType, defaultValue,
                                                                  nullable, length, primary};

                            genericColumns.emplace_back(column);

                        }

                        genericTableColumnsMap.insert(
                                std::pair<std::string, std::vector<dbcrudgen::db::generic::Column>>(tableName,
                                                                                                    genericColumns));

                        dbcrudgen::db::generic::Table genericTable{databaseName, tableName, genericColumns};
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
            };
        }
    }
}
#endif //DBCRUDGEN_CPP_MYSQLDATABASEFLATTENER_H
