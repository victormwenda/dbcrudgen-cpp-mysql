//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_SCHEMATA_H
#define DBCRUDGEN_CPP_SCHEMATA_H

#include <string>

namespace dbcrudgen {
    namespace db {
        namespace mysql {
            class Schemata {

            private:
                std::string catalogName;
                std::string schemaName;
                std::string defaultCharacterSetName;
                std::string defaultCollationName;
                std::string sqlPath;

            public:

                static constexpr const char *TABLE_NAME = "SCHEMATA";

                struct COLUMNS {
                    struct CATALOG_NAME {
                        static constexpr const char *NAME = "CATALOG_NAME";
                        static const int INDEX = 1;
                    };
                    struct SCHEMA_NAME {
                        static constexpr const char *NAME = "SCHEMA_NAME";
                        static const int INDEX = 2;
                    };
                    struct DEFAULT_CHARACTER_SET_NAME {
                        static constexpr const char *NAME = "DEFAULT_CHARACTER_SET_NAME";
                        static const int INDEX = 3;
                    };
                    struct DEFAULT_COLLATION_NAME {
                        static constexpr const char *NAME = "DEFAULT_COLLATION_NAME";
                        static const int INDEX = 4;
                    };
                    struct SQL_PATH {
                        static constexpr const char *NAME = "SQL_PATH";
                        static const int INDEX = 5;
                    };
                };

                Schemata(std::string &catalogName, std::string &schemaName, std::string &defaultCharacterSetName,
                         std::string &defaultCollationName, std::string &sqlPath)
                        : catalogName{catalogName}, schemaName{schemaName},
                          defaultCharacterSetName{defaultCharacterSetName},
                          defaultCollationName{defaultCollationName}, sqlPath{sqlPath} {}

                // Get the value of catalogName
                const std::string &getCatalogName() const {
                    return catalogName;
                }

                // Get the value of schemaName
                const std::string &getSchemaName() const {
                    return schemaName;
                }

                // Get the value of defaultCharacterSetName
                const std::string &getDefaultCharacterSetName() const {
                    return defaultCharacterSetName;
                }

                // Get the value of defaultCollationName
                const std::string &getDefaultCollationName() const {
                    return defaultCollationName;
                }

                // Get the value of sqlPath
                const std::string &getSqlPath() const {
                    return sqlPath;
                }

                /**
                * Returns the table name 'SCHEMATA';
                */
                static const char *getDatabaseTableName() {
                    return TABLE_NAME;
                }
            };
        }
    }
}


#endif //DBCRUDGEN_CPP_SCHEMATA_H
