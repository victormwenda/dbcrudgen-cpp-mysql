//
// Created by victor on 3/14/20.
//

#ifndef DBCRUDGEN_CPP_MYSQLDATABASEMODEL_H
#define DBCRUDGEN_CPP_MYSQLDATABASEMODEL_H

#include <string>
#include <vector>
#include <map>
#include "../scaffolding/entities/Tables.h"
#include "../scaffolding/entities/Columns.h"
#include "MYSQLDatabaseConnectionModel.h"
#include "../builder/MYSQLDatabaseModelBuilder.h"

namespace dbcrudgen {
    namespace db {
        namespace mysql {

            //MYSQL Database Model
            class MYSQLDatabaseModel {

            private:
                MYSQLDatabaseModelBuilder modelBuilder;
                std::vector<db::mysql::Tables> tables;
                std::map<std::string, std::vector<Columns>> tableColumns;
                std::map<std::string, std::vector<Columns>> primaryKeyColumns;
                std::map<std::string, std::vector<Columns>> foreignKeyColumns;
                std::map<std::string, std::vector<Columns>> keysColumns;

            public:

                /**
                 * MYSQL Database Model
                 * @param modelBuilder
                 */
                explicit MYSQLDatabaseModel(MYSQLDatabaseModelBuilder &modelBuilder)
                        : modelBuilder{modelBuilder} {

                    //Set tables
                    std::vector<db::mysql::Tables> databaseTables = modelBuilder.getSchemaTables();

                    setTables(databaseTables);

                    //Set table columns

                }

                const MYSQLDatabaseModelBuilder &getModelBuilder() const {
                    return modelBuilder;
                }


                const std::string &getDatabaseName() const {
                    return getModelBuilder().getSchemas();
                }

                const std::vector<Tables> &getTables() const {
                    return tables;
                }

                const std::map<std::string, std::vector<Columns>> &getTableColumns() const {
                    return tableColumns;
                }


                const std::map<std::string, std::vector<Columns>> &getPrimaryKeyColumns() const {
                    return primaryKeyColumns;
                }


                const std::map<std::string, std::vector<Columns>> &getForeignKeyColumns() const {
                    return foreignKeyColumns;
                }


                const std::map<std::string, std::vector<Columns>> &getKeyColumns() const {
                    return keysColumns;
                }


            private:
                void setTables(std::vector<db::mysql::Tables> &databaseTables) {

                    MYSQLDatabaseModel::tables = databaseTables;

                    for (const auto table : tables) {

                        //Bind table columns
                        const std::vector<db::mysql::Columns> &columns = modelBuilder.getTableColumns(
                                table.getTableName());
                        tableColumns.insert({table.getTableName(), columns});


                        //Bind primary key cols
                        const std::vector<db::mysql::Columns> &primaryKeys = modelBuilder.getTablePrimaryKeyColumns(
                                table.getTableName());
                        primaryKeyColumns.insert({table.getTableName(), primaryKeys});

                        //Bind foreign keys
                        const std::vector<db::mysql::Columns> &foreignKeys = modelBuilder.getTablePrimaryKeyColumns(
                                table.getTableName());
                        foreignKeyColumns.insert({table.getTableName(), foreignKeys});

                        //Bind keys columns
                        const std::vector<db::mysql::Columns> &keyColumns = modelBuilder.getTableKeysColumns(
                                table.getTableName());
                        keysColumns.insert({table.getTableName(), keyColumns});
                    }

                }


            };
        }
    }

}


#endif //DBCRUDGEN_CPP_MYSQLDATABASEMODEL_H
