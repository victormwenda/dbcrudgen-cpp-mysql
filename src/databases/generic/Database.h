//
// Created by victor on 3/21/20.
//

#ifndef DBCRUDGEN_CPP_DATABASE_H
#define DBCRUDGEN_CPP_DATABASE_H

#include <string>
#include <vector>

#include "Table.h"
#include "Connection.h"
#include "Flavor.h"

namespace dbcrudgen {
    namespace db {
        namespace generic {

            /**
             * A generic database table
             */
            class Database {

            private:
                Connection connection;
                Flavor flavor;
                std::vector<dbcrudgen::db::generic::Table> tables;
            public:


                /**
                 * Create a generic database
                 * @param connection
                 * @param flavor
                 * @param tables
                 */
                Database(Connection connection, Flavor flavor, std::vector<dbcrudgen::db::generic::Table> &tables)
                        : connection{connection}, flavor{flavor}, tables(tables) {}

                Connection getConnection() const {
                    return connection;
                }

                void setConnection(const Connection &connection) {
                    Database::connection = connection;
                }

                const Flavor getFlavor() const {
                    return flavor;
                }

                const std::string &getDatabaseName() const {
                    return getConnection().getDatabase();
                }

                void setDatabaseName(const std::string &databaseName) {
                    getConnection().setDatabase(databaseName);
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
