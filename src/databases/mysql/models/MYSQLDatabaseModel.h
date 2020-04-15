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

namespace dbcrudgen {
    namespace db {
        namespace mysql {

            //MYSQL Database Model
            class MYSQLDatabaseModel {

            private:
                MYSQLDatabaseConnectionModel connectionModel;
                std::vector<Tables> tables;
                std::map<std::string, std::vector<Columns>> tableColumns;

            public:

                /**
                 * MYSQL Database Model
                 * @param connectionModel
                 */
                explicit MYSQLDatabaseModel(MYSQLDatabaseConnectionModel connectionModel)
                        : connectionModel{connectionModel} {}

                const MYSQLDatabaseConnectionModel &getConnectionModel() const {
                    return connectionModel;
                }

                void setConnectionModel(MYSQLDatabaseConnectionModel &connectionModel) {
                    MYSQLDatabaseModel::connectionModel = connectionModel;
                }

                const std::string &getDatabaseName() const {
                    return getConnectionModel().getDatabase();
                }

                const std::vector<Tables> &getTables() const {
                    return tables;
                }

                void setTables(std::vector<Tables> &databaseTables) {
                    MYSQLDatabaseModel::tables = databaseTables;
                }

                const std::map<std::string, std::vector<Columns>> &getTableColumns() const {
                    return tableColumns;
                }

                void setTableColumns(std::map<std::string, std::vector<Columns>> &databaseTableColumns) {
                    MYSQLDatabaseModel::tableColumns = databaseTableColumns;
                }
            };
        }
    }

}


#endif //DBCRUDGEN_CPP_MYSQLDATABASEMODEL_H
