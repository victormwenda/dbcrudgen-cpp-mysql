#ifndef INFORMATION_SCHEMA_CPP_COLUMNS_PRIV_H
#define INFORMATION_SCHEMA_CPP_COLUMNS_PRIV_H

#include<string>

namespace dbcrudgen {
    namespace db {
        namespace mysql {
            class ColumnsPriv {

            private:
                std::string host;
                std::string db;
                std::string user;
                std::string tableName;
                std::string columnName;
                std::string timestamp;
                std::string columnPriv;

            public:

                static constexpr const char *TABLE_NAME = "columns_priv";

                struct COLUMNS {
                    struct HOST {
                        static constexpr const char *NAME = "Host";
                        static const int INDEX = 1;
                    };
                    struct DB {
                        static constexpr const char *NAME = "Db";
                        static const int INDEX = 2;
                    };
                    struct USER {
                        static constexpr const char *NAME = "User";
                        static const int INDEX = 3;
                    };
                    struct TABLE_NAME {
                        static constexpr const char *NAME = "Table_name";
                        static const int INDEX = 4;
                    };
                    struct COLUMN_NAME {
                        static constexpr const char *NAME = "Column_name";
                        static const int INDEX = 5;
                    };
                    struct TIMESTAMP {
                        static constexpr const char *NAME = "Timestamp";
                        static const int INDEX = 6;
                    };
                    struct COLUMN_PRIV {
                        static constexpr const char *NAME = "Column_priv";
                        static const int INDEX = 7;
                    };
                };

                ColumnsPriv(std::string &host, std::string &db, std::string &user, std::string &tableName,
                            std::string &columnName,
                            std::string &timestamp, std::string &columnPriv)
                        : host{host}, db{db}, user{user}, tableName{tableName}, columnName{columnName},
                          timestamp{timestamp}, columnPriv{columnPriv} {}

                // Get the value of host
                const std::string &getHost() const {
                    return host;
                }

                // Get the value of db
                const std::string &getDb() const {
                    return db;
                }

                // Get the value of user
                const std::string &getUser() const {
                    return user;
                }

                // Get the value of tableName
                const std::string &getTableName() const {
                    return tableName;
                }

                // Get the value of columnName
                const std::string &getColumnName() const {
                    return columnName;
                }

                // Get the value of timestamp
                const std::string &getTimestamp() const {
                    return timestamp;
                }

                // Get the value of columnPriv
                const std::string &getColumnPriv() const {
                    return columnPriv;
                }


                /**
                * Returns the table name 'columns_priv';
                */
                static const char *getDatabaseTableName() {
                    return TABLE_NAME;
                }
            };
        }
    }


}
#endif //INFORMATION_SCHEMA_CPP_COLUMNS_PRIV_H