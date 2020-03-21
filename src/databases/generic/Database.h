//
// Created by victor on 3/21/20.
//

#ifndef DBCRUDGEN_CPP_DATABASE_H
#define DBCRUDGEN_CPP_DATABASE_H

#include <string>
#include <vector>

#include "Table.h"

namespace dbcrudgen {
    namespace db {
        namespace generic {
            /**
             * A generic database table
             */
            class Database {

            private:
                std::string databaseName;
                std::vector<dbcrudgen::db::generic::Table> tables;

            public:

                /**
                 * Create a generic database
                 * @param databaseName
                 * @param tables
                 */
                Database(std::string &databaseName, std::vector<dbcrudgen::db::generic::Table> &tables)
                        : databaseName(databaseName), tables(tables) {}

                const std::string &getDatabaseName() const {
                    return databaseName;
                }

                void setDatabaseName(const std::string &databaseName) {
                    Database::databaseName = databaseName;
                }

                const std::vector<dbcrudgen::db::generic::Table> &getTables() const {
                    return tables;
                }

                void setTables(const std::vector<dbcrudgen::db::generic::Table> &tables) {
                    Database::tables = tables;
                }
            };
        }
    }

}
#endif //DBCRUDGEN_CPP_DATABASE_H
