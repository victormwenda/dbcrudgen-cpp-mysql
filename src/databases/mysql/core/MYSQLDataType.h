//
// Created by vrwanda on 3/13/20.
//

#ifndef DBCRUDGEN_CPP_MYSQLDATATYPE_H
#define DBCRUDGEN_CPP_MYSQLDATATYPE_H

#include <string>
#include <vector>
#include "../models/DataType.h"

namespace dbcrudgen {
    namespace db {
        namespace mysql {
            /**
             * MYSQL Data Types
             */
            class MYSQLDataType {
                const char *name;
                DataType dataType;

            public:
                MYSQLDataType(const char *name, DataType dataType) : name(name), dataType(dataType) {}

                const char *getName() const {
                    return name;
                }

                const DataType getDataType() const {
                    return dataType;
                }

                static std::vector<dbcrudgen::db::mysql::MYSQLDataType> getMYSQLDataTypes() {
                    std::vector<dbcrudgen::db::mysql::MYSQLDataType> data_types;

                    //MySQL numeric data types
                    data_types.emplace_back(
                            dbcrudgen::db::mysql::MYSQLDataType{"TINYINT", dbcrudgen::db::mysql::DataType::NUMERICAL});
                    data_types.emplace_back(
                            dbcrudgen::db::mysql::MYSQLDataType{"SMALLINT", dbcrudgen::db::mysql::DataType::NUMERICAL});
                    data_types.emplace_back(
                            dbcrudgen::db::mysql::MYSQLDataType{"MEDIUMINT", dbcrudgen::db::mysql::DataType::NUMERICAL});
                    data_types.emplace_back(
                            dbcrudgen::db::mysql::MYSQLDataType{"INT", dbcrudgen::db::mysql::DataType::NUMERICAL});
                    data_types.emplace_back(
                            dbcrudgen::db::mysql::MYSQLDataType{"BIGINT", dbcrudgen::db::mysql::DataType::NUMERICAL});
                    data_types.emplace_back(
                            dbcrudgen::db::mysql::MYSQLDataType{"DECIMAL", dbcrudgen::db::mysql::DataType::NUMERICAL});
                    data_types.emplace_back(
                            dbcrudgen::db::mysql::MYSQLDataType{"FLOAT", dbcrudgen::db::mysql::DataType::NUMERICAL});
                    data_types.emplace_back(
                            dbcrudgen::db::mysql::MYSQLDataType{"DOUBLE", dbcrudgen::db::mysql::DataType::NUMERICAL});
                    data_types.emplace_back(
                            dbcrudgen::db::mysql::MYSQLDataType{"BIT", dbcrudgen::db::mysql::DataType::NUMERICAL});


                    //MySQL Boolean data type
                    data_types.emplace_back(
                            dbcrudgen::db::mysql::MYSQLDataType{"BOOLEAN", dbcrudgen::db::mysql::DataType::BOOLEAN});

                    //MySQL String data types
                    data_types.emplace_back(
                            dbcrudgen::db::mysql::MYSQLDataType{"CHAR", dbcrudgen::db::mysql::DataType::STRING});
                    data_types.emplace_back(
                            dbcrudgen::db::mysql::MYSQLDataType{"VARCHAR", dbcrudgen::db::mysql::DataType::STRING});
                    data_types.emplace_back(
                            dbcrudgen::db::mysql::MYSQLDataType{"BINARY", dbcrudgen::db::mysql::DataType::STRING});
                    data_types.emplace_back(
                            dbcrudgen::db::mysql::MYSQLDataType{"VARBINARY", dbcrudgen::db::mysql::DataType::STRING});
                    data_types.emplace_back(
                            dbcrudgen::db::mysql::MYSQLDataType{"TINYBLOB", dbcrudgen::db::mysql::DataType::STRING});
                    data_types.emplace_back(
                            dbcrudgen::db::mysql::MYSQLDataType{"BLOB", dbcrudgen::db::mysql::DataType::STRING});
                    data_types.emplace_back(
                            dbcrudgen::db::mysql::MYSQLDataType{"MEDIUMBLOB", dbcrudgen::db::mysql::DataType::STRING});
                    data_types.emplace_back(
                            dbcrudgen::db::mysql::MYSQLDataType{"LONGBLOB", dbcrudgen::db::mysql::DataType::STRING});
                    data_types.emplace_back(
                            dbcrudgen::db::mysql::MYSQLDataType{"TINYTEXT", dbcrudgen::db::mysql::DataType::STRING});
                    data_types.emplace_back(
                            dbcrudgen::db::mysql::MYSQLDataType{"TEXT", dbcrudgen::db::mysql::DataType::STRING});
                    data_types.emplace_back(
                            dbcrudgen::db::mysql::MYSQLDataType{"MEDIUMTEXT", dbcrudgen::db::mysql::DataType::STRING});
                    data_types.emplace_back(
                            dbcrudgen::db::mysql::MYSQLDataType{"LONGTEXT", dbcrudgen::db::mysql::DataType::STRING});
                    data_types.emplace_back(
                            dbcrudgen::db::mysql::MYSQLDataType{"ENUM", dbcrudgen::db::mysql::DataType::STRING});
                    data_types.emplace_back(dbcrudgen::db::mysql::MYSQLDataType{"SET", dbcrudgen::db::mysql::DataType::STRING});

                    //MySQL date and time data types
                    data_types.emplace_back(
                            dbcrudgen::db::mysql::MYSQLDataType{"DATE", dbcrudgen::db::mysql::DataType::DATE_TIME});
                    data_types.emplace_back(
                            dbcrudgen::db::mysql::MYSQLDataType{"TIME", dbcrudgen::db::mysql::DataType::DATE_TIME});
                    data_types.emplace_back(
                            dbcrudgen::db::mysql::MYSQLDataType{"DATETIME", dbcrudgen::db::mysql::DataType::DATE_TIME});
                    data_types.emplace_back(
                            dbcrudgen::db::mysql::MYSQLDataType{"TIMESTAMP", dbcrudgen::db::mysql::DataType::DATE_TIME});
                    data_types.emplace_back(
                            dbcrudgen::db::mysql::MYSQLDataType{"YEAR", dbcrudgen::db::mysql::DataType::DATE_TIME});

                    //MySQL spatial data types
                    data_types.emplace_back(
                            dbcrudgen::db::mysql::MYSQLDataType{"GEOMETRY", dbcrudgen::db::mysql::DataType::SPATIAL});
                    data_types.emplace_back(
                            dbcrudgen::db::mysql::MYSQLDataType{"POINT", dbcrudgen::db::mysql::DataType::SPATIAL});
                    data_types.emplace_back(
                            dbcrudgen::db::mysql::MYSQLDataType{"LINESTRING", dbcrudgen::db::mysql::DataType::SPATIAL});
                    data_types.emplace_back(
                            dbcrudgen::db::mysql::MYSQLDataType{"POLYGON", dbcrudgen::db::mysql::DataType::SPATIAL});
                    data_types.emplace_back(
                            dbcrudgen::db::mysql::MYSQLDataType{"GEOMETRYCOLLECCTION",
                                                            dbcrudgen::db::mysql::DataType::SPATIAL});
                    data_types.emplace_back(
                            dbcrudgen::db::mysql::MYSQLDataType{"MULTILINESTRING", dbcrudgen::db::mysql::DataType::SPATIAL});
                    data_types.emplace_back(
                            dbcrudgen::db::mysql::MYSQLDataType{"MULTIPOINT", dbcrudgen::db::mysql::DataType::SPATIAL});
                    data_types.emplace_back(
                            dbcrudgen::db::mysql::MYSQLDataType{"MULTIPOLYGON", dbcrudgen::db::mysql::DataType::SPATIAL});

                    //JSON data type
                    data_types.emplace_back(dbcrudgen::db::mysql::MYSQLDataType{"JSON", dbcrudgen::db::mysql::DataType::JSON});

                    return data_types;
                }

            };
        }
    }
}

#endif //DBCRUDGEN_CPP_MYSQLDATATYPE_H
