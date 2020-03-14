//
// Created by victor on 3/14/20.
//

#ifndef DBCRUDGEN_CPP_MYSQLDATABASEMODEL_H
#define DBCRUDGEN_CPP_MYSQLDATABASEMODEL_H

#include <string>
#include <vector>
#include <map>
#include "../schema/Tables.h"
#include "../schema/Columns.h"

namespace dbcrudgen {

    namespace mysql {

        //MYSQL Database Model
        class MYSQLDatabaseModel {

        private:
            std::string databaseName;
            std::vector<Tables> tables;
            std::map<std::string, std::vector<Columns>> tableColumns;

        public:

            MYSQLDatabaseModel() = default;

            const std::string &getDatabaseName() const {
                return databaseName;
            }

            void setDatabaseName(std::string &schemas) {
                MYSQLDatabaseModel::databaseName = schemas;
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


#endif //DBCRUDGEN_CPP_MYSQLDATABASEMODEL_H
