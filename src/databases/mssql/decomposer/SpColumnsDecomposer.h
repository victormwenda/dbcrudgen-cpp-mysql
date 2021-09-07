//
// Created by victor on 9/4/21.
//

#ifndef DBCRUDGEN_CPP_SPCOLUMNSDECOMPOSER_H
#define DBCRUDGEN_CPP_SPCOLUMNSDECOMPOSER_H

#include "../executor/MSSQLQueryExecutor.h"
#include "../scaffolding/entities/SysDatabases.h"
#include "../scaffolding/sp/SpColumns.h"

namespace dbcrudgen {
    namespace db {
        namespace mssql {
            class SpColumnsDecomposer {
            private:
                dbcrudgen::db::mssql::MSSQLQueryExecutor executor;
            public:
                SpColumnsDecomposer() = default;

                /**
                 * Invokes the stored procedure sp_columns
                 * @param executor
                 */
                explicit SpColumnsDecomposer(dbcrudgen::db::mssql::MSSQLQueryExecutor
                                             &executor) : executor{executor} {

                }

                /**
                * Get table columns
                * @return
                */
                std::vector<SpColumns> getTableColumns(const std::string &tableName) {
                    std::vector<MSSQLColBinder> colBindings;
                    std::vector<SpColumns> tableCols;

                    {
                        SQLCHAR table_qualifier[255];
                        SQLLEN table_qualifier_indicator;
                        std::string columnName{SpColumns::COLUMNS::TABLE_QUALIFIER::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SpColumns::COLUMNS::TABLE_QUALIFIER::INDEX, SQL_C_CHAR, columnName,
                                               table_qualifier, 255, &table_qualifier_indicator});
                    }
                    {
                        SQLCHAR table_owner[255];
                        SQLLEN table_owner_indicator;
                        std::string columnName{SpColumns::COLUMNS::TABLE_OWNER::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SpColumns::COLUMNS::TABLE_OWNER::INDEX, SQL_C_CHAR, columnName,
                                               table_owner, 255, &table_owner_indicator});
                    }
                    {
                        SQLCHAR table_name[255];
                        SQLLEN table_name_indicator;
                        std::string columnName{SpColumns::COLUMNS::TABLE_NAME::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SpColumns::COLUMNS::TABLE_NAME::INDEX, SQL_C_CHAR, columnName,
                                               table_name, 255, &table_name_indicator});
                    }
                    {
                        SQLCHAR column_name[255];
                        SQLLEN column_name_indicator;
                        std::string columnName{SpColumns::COLUMNS::COLUMN_NAME::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SpColumns::COLUMNS::COLUMN_NAME::INDEX, SQL_C_CHAR, columnName,
                                               column_name, 255, &column_name_indicator});
                    }
                    {
                        SQLINTEGER data_type;
                        SQLLEN data_type_indicator;
                        std::string columnName{SpColumns::COLUMNS::DATA_TYPE::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SpColumns::COLUMNS::DATA_TYPE::INDEX, SQL_INTEGER, columnName,
                                               &data_type,
                                               sizeof(data_type), &data_type_indicator});
                    }
                    {
                        SQLCHAR type_name[255];
                        SQLLEN type_name_indicator;
                        std::string columnName{SpColumns::COLUMNS::TYPE_NAME::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SpColumns::COLUMNS::TYPE_NAME::INDEX, SQL_C_CHAR, columnName, type_name,
                                               255, &type_name_indicator});
                    }
                    {
                        SQLINTEGER precision;
                        SQLLEN precision_indicator;
                        std::string columnName{SpColumns::COLUMNS::PRECISION::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SpColumns::COLUMNS::PRECISION::INDEX, SQL_INTEGER, columnName,
                                               &precision,
                                               sizeof(precision), &precision_indicator});
                    }
                    {
                        SQLINTEGER length;
                        SQLLEN length_indicator;
                        std::string columnName{SpColumns::COLUMNS::LENGTH::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SpColumns::COLUMNS::LENGTH::INDEX, SQL_INTEGER, columnName, &length,
                                               sizeof(length),
                                               &length_indicator});
                    }
                    {
                        SQLINTEGER scale;
                        SQLLEN scale_indicator;
                        std::string columnName{SpColumns::COLUMNS::SCALE::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SpColumns::COLUMNS::SCALE::INDEX, SQL_INTEGER, columnName, &scale,
                                               sizeof(scale),
                                               &scale_indicator});
                    }
                    {
                        SQLINTEGER radix;
                        SQLLEN radix_indicator;
                        std::string columnName{SpColumns::COLUMNS::RADIX::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SpColumns::COLUMNS::RADIX::INDEX, SQL_INTEGER, columnName, &radix,
                                               sizeof(radix),
                                               &radix_indicator});
                    }
                    {
                        SQLINTEGER nullable;
                        SQLLEN nullable_indicator;
                        std::string columnName{SpColumns::COLUMNS::NULLABLE::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SpColumns::COLUMNS::NULLABLE::INDEX, SQL_INTEGER, columnName, &nullable,
                                               sizeof(nullable), &nullable_indicator});
                    }
                    {
                        SQLCHAR remarks[255];
                        SQLLEN remarks_indicator;
                        std::string columnName{SpColumns::COLUMNS::REMARKS::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SpColumns::COLUMNS::REMARKS::INDEX, SQL_C_CHAR, columnName, remarks, 255,
                                               &remarks_indicator});
                    }
                    {
                        SQLCHAR column_def[255];
                        SQLLEN column_def_indicator;
                        std::string columnName{SpColumns::COLUMNS::COLUMN_DEF::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SpColumns::COLUMNS::COLUMN_DEF::INDEX, SQL_C_CHAR, columnName,
                                               column_def, 255, &column_def_indicator});
                    }
                    {
                        SQLINTEGER sql_data_type;
                        SQLLEN sql_data_type_indicator;
                        std::string columnName{SpColumns::COLUMNS::SQL_DATA_TYPE::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SpColumns::COLUMNS::SQL_DATA_TYPE::INDEX, SQL_INTEGER, columnName,
                                               &sql_data_type, sizeof(sql_data_type), &sql_data_type_indicator});
                    }
                    {
                        SQLINTEGER sql_datetime_sub;
                        SQLLEN sql_datetime_sub_indicator;
                        std::string columnName{SpColumns::COLUMNS::SQL_DATETIME_SUB::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SpColumns::COLUMNS::SQL_DATETIME_SUB::INDEX, SQL_INTEGER, columnName,
                                               &sql_datetime_sub, sizeof(sql_datetime_sub),
                                               &sql_datetime_sub_indicator});
                    }
                    {
                        SQLINTEGER char_octet_length;
                        SQLLEN char_octet_length_indicator;
                        std::string columnName{SpColumns::COLUMNS::CHAR_OCTET_LENGTH::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SpColumns::COLUMNS::CHAR_OCTET_LENGTH::INDEX, SQL_INTEGER, columnName,
                                               &char_octet_length, sizeof(char_octet_length),
                                               &char_octet_length_indicator});
                    }
                    {
                        SQLINTEGER ordinal_position;
                        SQLLEN ordinal_position_indicator;
                        std::string columnName{SpColumns::COLUMNS::ORDINAL_POSITION::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SpColumns::COLUMNS::ORDINAL_POSITION::INDEX, SQL_INTEGER, columnName,
                                               &ordinal_position, sizeof(ordinal_position),
                                               &ordinal_position_indicator});
                    }
                    {
                        SQLCHAR is_nullable[255];
                        SQLLEN is_nullable_indicator;
                        std::string columnName{SpColumns::COLUMNS::IS_NULLABLE::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SpColumns::COLUMNS::IS_NULLABLE::INDEX, SQL_C_CHAR, columnName,
                                               is_nullable, 255, &is_nullable_indicator});
                    }
                    {
                        SQLINTEGER ss_data_type;
                        SQLLEN ss_data_type_indicator;
                        std::string columnName{SpColumns::COLUMNS::SS_DATA_TYPE::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SpColumns::COLUMNS::SS_DATA_TYPE::INDEX, SQL_INTEGER, columnName,
                                               &ss_data_type, sizeof(ss_data_type), &ss_data_type_indicator});
                    }

                    std::vector<MSSQLResultSet> resultSet{};
                    std::string query{MSSQLQueries::SP_COLUMNS};
                    query += tableName;
                    executor.execQuery(query, colBindings, resultSet);

                    std::string table_qualifier;
                    std::string table_owner;
                    std::string table_name;
                    std::string column_name;
                    signed int data_type;
                    std::string type_name;
                    int precision;
                    int length;
                    int scale;
                    int radix;
                    bool nullable;
                    std::string remarks;
                    std::string column_def;
                    int sql_data_type;
                    int sql_datetime_sub;
                    int char_octet_length;
                    int ordinal_position;
                    std::string is_nullable;
                    int ss_data_type;

                    int loopTracker = 0;
                    for (const dbcrudgen::db::mssql::MSSQLResultSet &data: resultSet) {
                        loopTracker++;
                        void *colValue = data.getColumnValue();

                        switch (data.getColumnIndex()) {
                            case dbcrudgen::db::mssql::SpColumns::COLUMNS::TABLE_QUALIFIER::INDEX:
                                table_qualifier = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case dbcrudgen::db::mssql::SpColumns::COLUMNS::TABLE_OWNER::INDEX:
                                table_owner = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case dbcrudgen::db::mssql::SpColumns::COLUMNS::TABLE_NAME::INDEX:
                                table_name = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case dbcrudgen::db::mssql::SpColumns::COLUMNS::COLUMN_NAME::INDEX:
                                column_name = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case dbcrudgen::db::mssql::SpColumns::COLUMNS::DATA_TYPE::INDEX:
                                data_type = *reinterpret_cast<int *>(colValue);
                                break;
                            case dbcrudgen::db::mssql::SpColumns::COLUMNS::TYPE_NAME::INDEX:
                                type_name = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case dbcrudgen::db::mssql::SpColumns::COLUMNS::PRECISION::INDEX:
                                precision = *reinterpret_cast<int *>(colValue);
                                break;
                            case dbcrudgen::db::mssql::SpColumns::COLUMNS::LENGTH::INDEX:
                                length = *reinterpret_cast<int *>(colValue);
                                break;
                            case dbcrudgen::db::mssql::SpColumns::COLUMNS::SCALE::INDEX:
                                scale = *reinterpret_cast<int *>(colValue);
                                break;
                            case dbcrudgen::db::mssql::SpColumns::COLUMNS::RADIX::INDEX:
                                radix = *reinterpret_cast<int *>(colValue);
                                break;
                            case dbcrudgen::db::mssql::SpColumns::COLUMNS::NULLABLE::INDEX:
                                nullable = *reinterpret_cast<int *>(colValue);
                                break;
                            case dbcrudgen::db::mssql::SpColumns::COLUMNS::REMARKS::INDEX:
                                remarks = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case dbcrudgen::db::mssql::SpColumns::COLUMNS::COLUMN_DEF::INDEX:
                                column_def = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case dbcrudgen::db::mssql::SpColumns::COLUMNS::SQL_DATA_TYPE::INDEX:
                                sql_data_type = *reinterpret_cast<int *>(colValue);
                                break;
                            case dbcrudgen::db::mssql::SpColumns::COLUMNS::SQL_DATETIME_SUB::INDEX:
                                sql_datetime_sub = *reinterpret_cast<int *>(colValue);
                                break;
                            case dbcrudgen::db::mssql::SpColumns::COLUMNS::CHAR_OCTET_LENGTH::INDEX:
                                char_octet_length = *reinterpret_cast<int *>(colValue);
                                break;
                            case dbcrudgen::db::mssql::SpColumns::COLUMNS::ORDINAL_POSITION::INDEX:
                                ordinal_position = *reinterpret_cast<int *>(colValue);
                                break;
                            case dbcrudgen::db::mssql::SpColumns::COLUMNS::IS_NULLABLE::INDEX:
                                is_nullable = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case dbcrudgen::db::mssql::SpColumns::COLUMNS::SS_DATA_TYPE::INDEX:
                                ss_data_type = *reinterpret_cast<int *>(colValue);
                                break;
                        }

                        if (loopTracker == colBindings.size()) {
                            SpColumns cols{
                                    table_qualifier,
                                    table_owner,
                                    table_name,
                                    column_name,
                                    data_type,
                                    type_name,
                                    precision,
                                    length,
                                    scale,
                                    radix,
                                    nullable,
                                    remarks,
                                    column_def,
                                    sql_data_type,
                                    sql_datetime_sub,
                                    char_octet_length,
                                    ordinal_position,
                                    is_nullable,
                                    ss_data_type
                            };
                            tableCols.emplace_back(cols);
                            loopTracker = 0;
                        }
                    }

                    return tableCols;
                }

                ~SpColumnsDecomposer() {

                }
            };
        }
    }
}


#endif //DBCRUDGEN_CPP_SPCOLUMNSDECOMPOSER_H
