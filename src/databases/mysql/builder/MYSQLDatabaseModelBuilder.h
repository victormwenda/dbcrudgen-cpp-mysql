//
// Created by victor on 4/18/20.
//

#ifndef DBCRUDGEN_CPP_MYSQLDATABASEMODELBUILDER_H
#define DBCRUDGEN_CPP_MYSQLDATABASEMODELBUILDER_H

#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include "../connectors/MYSQLDatabaseConnectionParams.h"
#include "../connectors/MYSQLDatabaseConnector.h"
#include "../decomposer/MYSQLDatabasePreparedDecomposer.h"

namespace dbcrudgen {
    namespace db {
        namespace mysql {
            class MYSQLDatabaseModelBuilder {

            private:
                std::string host;
                int port;
                std::string user;
                std::string password;
                std::string schemas;

                dbcrudgen::db::mysql::MYSQLDatabaseConnectionParams params;
                dbcrudgen::db::mysql::MYSQLDatabaseConnector connector;
                dbcrudgen::db::mysql::MYSQLDatabasePreparedDecomposer deComposer;

            public:
                /**
                 * MYSQL Database Model Creator
                 * @param host
                 * @param port
                 * @param user
                 * @param password
                 * @param schemas
                 */
                MYSQLDatabaseModelBuilder(std::string connStr, std::string &host, int port, std::string &user,
                                          std::string &password, std::string &schemas)
                        : host(host), port(port), user(user), password(password), schemas(schemas),
                          params{connStr, user, password, schemas}, //Init MYSQLDatabaseConnectionParams
                          connector{params}, // Init MYSQLDatabaseConnector
                          deComposer{connector} //Init MYSQLDatabaseDecomposer
                {
                    connector.open();
                }

                const std::string &getHost() const {
                    return host;
                }

                int getPort() const {
                    return port;
                }

                const std::string &getUser() const {
                    return user;
                }

                const std::string &getPassword() const {
                    return password;
                }

                const std::string &getSchemas() const {
                    return schemas;
                }

                virtual ~MYSQLDatabaseModelBuilder() {
                    connector.close();
                }

                /**
                 * Get all the tables in a schema
                 * @param schema
                 * @return
                 */
                std::vector<db::mysql::Tables> getSchemaTables() {
                    return deComposer.getSchemaTables(getSchemas());
                }

                /**
                 * Get all the columns in a table
                 * @param tableName
                 * @return
                 */
                std::vector<db::mysql::Columns> getTableColumns(const std::string &tableName) {
                    return deComposer.getColumns(getSchemas(), tableName);
                }

                /**
                 * Get all the primary key columns in a table
                 * @param tableName
                 * @return
                 */
                std::vector<db::mysql::Columns> getTablePrimaryKeyColumns(const std::string &tableName) {

                    std::vector<dbcrudgen::db::mysql::Columns> columns;

                    const std::vector<Statistics> statistics = deComposer.getTablePrimaryKeys(getSchemas(), tableName);

                    for (const Statistics &stats : statistics) {
                        db::mysql::Columns column = deComposer.getColumn(getSchemas(), tableName,
                                                                         stats.getColumnName());
                        columns.emplace_back(column);
                    }
                    return columns;
                }

                /**
                 * Get all the primary key columns in a table
                 * @param tableName
                 * @return
                 */
                std::vector<db::mysql::Columns> getTableKeysColumns(const std::string &tableName) {

                    std::vector<dbcrudgen::db::mysql::Columns> columns;

                    const std::vector<Statistics> statistics = deComposer.getTableKeyColumns(getSchemas(), tableName);

                    for (const Statistics &stats : statistics) {
                        db::mysql::Columns column = deComposer.getColumn(getSchemas(), tableName,
                                                                         stats.getColumnName());
                        columns.emplace_back(column);
                    }
                    return columns;
                }

                /**
                 * Get all the foreign key columns in a table
                 * @param tableName
                 * @return
                 */
                std::vector<db::mysql::Columns> getTableForeignKeyColumns(const std::string &tableName) {

                    std::vector<dbcrudgen::db::mysql::Columns> columns;

                    const std::vector<KeyColumnUsage> keyColumns = deComposer.getTableForeignKeyColumns(getSchemas(),
                                                                                                        tableName);

                    for (const KeyColumnUsage &keyColumn : keyColumns) {
                        db::mysql::Columns column =
                                deComposer.getColumn(getSchemas(), tableName, keyColumn.getColumnName());
                        columns.emplace_back(column);
                    }
                    return columns;
                }
            };
        }
    }
}
#endif //DBCRUDGEN_CPP_MYSQLDATABASEMODELBUILDER_H
