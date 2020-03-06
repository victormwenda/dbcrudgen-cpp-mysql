//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_SCHEMATA_H
#define DBCRUDGEN_CPP_SCHEMATA_H

#include <string>

class Schemata {
private:
    std::string catalogName;
    std::string schemaName;
    std::string defaultCharacterSetName;
    std::string defaultCollationName;
    std::string sqlPath;

public:
    static constexpr const char *TABLE_NAME = "SCHEMATA";

    struct Columns {
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
             std::string &defaultCollationName,
             std::string &sqlPath) :

            catalogName(catalogName), schemaName(schemaName), defaultCharacterSetName(defaultCharacterSetName),
            defaultCollationName(defaultCollationName), sqlPath(sqlPath) {}

    const std::string &getCatalogName() const {
        return catalogName;
    }

    void setCatalogName(const std::string &catalogName) {
        Schemata::catalogName = catalogName;
    }

    const std::string &getSchemaName() const {
        return schemaName;
    }

    void setSchemaName(const std::string &schemaName) {
        Schemata::schemaName = schemaName;
    }

    const std::string &getDefaultCharacterSetName() const {
        return defaultCharacterSetName;
    }

    void setDefaultCharacterSetName(const std::string &defaultCharacterSetName) {
        Schemata::defaultCharacterSetName = defaultCharacterSetName;
    }

    const std::string &getDefaultCollationName() const {
        return defaultCollationName;
    }

    void setDefaultCollationName(const std::string &defaultCollationName) {
        Schemata::defaultCollationName = defaultCollationName;
    }

    const std::string &getSqlPath() const {
        return sqlPath;
    }

    void setSqlPath(const std::string &sqlPath) {
        Schemata::sqlPath = sqlPath;
    }

    static const char *const getTableName() {
        return TABLE_NAME;
    }
};


#endif //DBCRUDGEN_CPP_SCHEMATA_H
