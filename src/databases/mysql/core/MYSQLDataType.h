//
// Created by vrwanda on 3/13/20.
//

#ifndef DBCRUDGEN_CPP_MYSQLDATATYPE_H
#define DBCRUDGEN_CPP_MYSQLDATATYPE_H

#include <string>
#include <vector>
#include "../models/DataType.h"

namespace dbcrudgen {
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

            static std::vector<dbcrudgen::mysql::MYSQLDataType> getMYSQLDataTypes() {
                std::vector<dbcrudgen::mysql::MYSQLDataType> data_types;

                //MySQL numeric data types
                data_types.emplace_back(
                        dbcrudgen::mysql::MYSQLDataType{"TINYINT", dbcrudgen::mysql::DataType::NUMERICAL});
                data_types.emplace_back(
                        dbcrudgen::mysql::MYSQLDataType{"SMALLINT", dbcrudgen::mysql::DataType::NUMERICAL});
                data_types.emplace_back(
                        dbcrudgen::mysql::MYSQLDataType{"MEDIUMINT", dbcrudgen::mysql::DataType::NUMERICAL});
                data_types.emplace_back(dbcrudgen::mysql::MYSQLDataType{"INT", dbcrudgen::mysql::DataType::NUMERICAL});
                data_types.emplace_back(
                        dbcrudgen::mysql::MYSQLDataType{"BIGINT", dbcrudgen::mysql::DataType::NUMERICAL});
                data_types.emplace_back(
                        dbcrudgen::mysql::MYSQLDataType{"DECIMAL", dbcrudgen::mysql::DataType::NUMERICAL});
                data_types.emplace_back(
                        dbcrudgen::mysql::MYSQLDataType{"FLOAT", dbcrudgen::mysql::DataType::NUMERICAL});
                data_types.emplace_back(
                        dbcrudgen::mysql::MYSQLDataType{"DOUBLE", dbcrudgen::mysql::DataType::NUMERICAL});
                data_types.emplace_back(dbcrudgen::mysql::MYSQLDataType{"BIT", dbcrudgen::mysql::DataType::NUMERICAL});


                //MySQL Boolean data type
                data_types.emplace_back(
                        dbcrudgen::mysql::MYSQLDataType{"BOOLEAN", dbcrudgen::mysql::DataType::BOOLEAN});

                //MySQL String data types
                data_types.emplace_back(dbcrudgen::mysql::MYSQLDataType{"CHAR", dbcrudgen::mysql::DataType::STRING});
                data_types.emplace_back(dbcrudgen::mysql::MYSQLDataType{"VARCHAR", dbcrudgen::mysql::DataType::STRING});
                data_types.emplace_back(dbcrudgen::mysql::MYSQLDataType{"BINARY", dbcrudgen::mysql::DataType::STRING});
                data_types.emplace_back(
                        dbcrudgen::mysql::MYSQLDataType{"VARBINARY", dbcrudgen::mysql::DataType::STRING});
                data_types.emplace_back(
                        dbcrudgen::mysql::MYSQLDataType{"TINYBLOB", dbcrudgen::mysql::DataType::STRING});
                data_types.emplace_back(dbcrudgen::mysql::MYSQLDataType{"BLOB", dbcrudgen::mysql::DataType::STRING});
                data_types.emplace_back(
                        dbcrudgen::mysql::MYSQLDataType{"MEDIUMBLOB", dbcrudgen::mysql::DataType::STRING});
                data_types.emplace_back(
                        dbcrudgen::mysql::MYSQLDataType{"LONGBLOB", dbcrudgen::mysql::DataType::STRING});
                data_types.emplace_back(
                        dbcrudgen::mysql::MYSQLDataType{"TINYTEXT", dbcrudgen::mysql::DataType::STRING});
                data_types.emplace_back(dbcrudgen::mysql::MYSQLDataType{"TEXT", dbcrudgen::mysql::DataType::STRING});
                data_types.emplace_back(
                        dbcrudgen::mysql::MYSQLDataType{"MEDIUMTEXT", dbcrudgen::mysql::DataType::STRING});
                data_types.emplace_back(
                        dbcrudgen::mysql::MYSQLDataType{"LONGTEXT", dbcrudgen::mysql::DataType::STRING});
                data_types.emplace_back(dbcrudgen::mysql::MYSQLDataType{"ENUM", dbcrudgen::mysql::DataType::STRING});
                data_types.emplace_back(dbcrudgen::mysql::MYSQLDataType{"SET", dbcrudgen::mysql::DataType::STRING});

                //MySQL date and time data types
                data_types.emplace_back(dbcrudgen::mysql::MYSQLDataType{"DATE", dbcrudgen::mysql::DataType::DATE_TIME});
                data_types.emplace_back(dbcrudgen::mysql::MYSQLDataType{"TIME", dbcrudgen::mysql::DataType::DATE_TIME});
                data_types.emplace_back(
                        dbcrudgen::mysql::MYSQLDataType{"DATETIME", dbcrudgen::mysql::DataType::DATE_TIME});
                data_types.emplace_back(
                        dbcrudgen::mysql::MYSQLDataType{"TIMESTAMP", dbcrudgen::mysql::DataType::DATE_TIME});
                data_types.emplace_back(dbcrudgen::mysql::MYSQLDataType{"YEAR", dbcrudgen::mysql::DataType::DATE_TIME});

                //MySQL spatial data types
                data_types.emplace_back(
                        dbcrudgen::mysql::MYSQLDataType{"GEOMETRY", dbcrudgen::mysql::DataType::SPATIAL});
                data_types.emplace_back(dbcrudgen::mysql::MYSQLDataType{"POINT", dbcrudgen::mysql::DataType::SPATIAL});
                data_types.emplace_back(
                        dbcrudgen::mysql::MYSQLDataType{"LINESTRING", dbcrudgen::mysql::DataType::SPATIAL});
                data_types.emplace_back(
                        dbcrudgen::mysql::MYSQLDataType{"POLYGON", dbcrudgen::mysql::DataType::SPATIAL});
                data_types.emplace_back(
                        dbcrudgen::mysql::MYSQLDataType{"GEOMETRYCOLLECCTION", dbcrudgen::mysql::DataType::SPATIAL});
                data_types.emplace_back(
                        dbcrudgen::mysql::MYSQLDataType{"MULTILINESTRING", dbcrudgen::mysql::DataType::SPATIAL});
                data_types.emplace_back(
                        dbcrudgen::mysql::MYSQLDataType{"MULTIPOINT", dbcrudgen::mysql::DataType::SPATIAL});
                data_types.emplace_back(
                        dbcrudgen::mysql::MYSQLDataType{"MULTIPOLYGON", dbcrudgen::mysql::DataType::SPATIAL});

                //JSON data type
                data_types.emplace_back(dbcrudgen::mysql::MYSQLDataType{"JSON", dbcrudgen::mysql::DataType::JSON});

                return data_types;
            }

        };
    }
}

#endif //DBCRUDGEN_CPP_MYSQLDATATYPE_H
