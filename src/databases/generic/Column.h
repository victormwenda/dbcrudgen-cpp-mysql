//
// Created by victor on 3/21/20.
//

#ifndef DBCRUDGEN_CPP_COLUMN_H
#define DBCRUDGEN_CPP_COLUMN_H

#include <string>

namespace dbcrudgen {
    namespace db {
        namespace generic {

            /**
             * A generic table column
             */
            class Column {

            private:
                std::string columnName;
                std::string tableName;
                std::string dataType;
                std::string defaultValue;
                bool nullable;
                long length;
                bool primary;
                bool autoIncrements;

            public:

                Column(std::string &columnName, std::string &tableName, std::string &dataType,
                       std::string &defaultValue, bool nullable, long length, bool primary = false,
                       bool autoIncrements = false)
                        : columnName(columnName), tableName(tableName), dataType(dataType), defaultValue(defaultValue),
                          nullable(nullable), length(length), primary(primary), autoIncrements(autoIncrements) {}

                const std::string &getColumnName() const {
                    return columnName;
                }

                void setColumnName(const std::string &columnName) {
                    Column::columnName = columnName;
                }

                const std::string &getTableName() const {
                    return tableName;
                }

                void setTableName(const std::string &tableName) {
                    Column::tableName = tableName;
                }

                const std::string &getDataType() const {
                    return dataType;
                }

                void setDataType(const std::string &dataType) {
                    Column::dataType = dataType;
                }

                const std::string &getDefaultValue() const {
                    return defaultValue;
                }

                void setDefaultValue(const std::string &defaultValue) {
                    Column::defaultValue = defaultValue;
                }

                bool isNullable() const {
                    return nullable;
                }

                void setNullable(bool nullable) {
                    Column::nullable = nullable;
                }

                long getLength() const {
                    return length;
                }

                void setLength(long length) {
                    Column::length = length;
                }

                bool isPrimary() const {
                    return primary;
                }

                void setPrimary(bool primary) {
                    Column::primary = primary;
                }

                bool isAutoIncrement() const {
                    return autoIncrements;
                }

                void setAutoIncrements(bool autoIncrements) {
                    Column::autoIncrements = autoIncrements;
                }
            };
        }
    }

}
#endif //DBCRUDGEN_CPP_COLUMN_H
