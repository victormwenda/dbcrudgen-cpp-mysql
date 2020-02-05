/**
* @author Victor Mwenda
* @author vmwenda.vm@gmail.com
*
* Created by victor on 6/15/17.
* C/C++ Laptop
*/



#ifndef DBCRUDGEN_CPP_MYSQLDATABASETABLE_H
#define DBCRUDGEN_CPP_MYSQLDATABASETABLE_H

#include <iostream>
#include <utility> #include "../formats/RowFormats.h"
#include "../../sql/models/DatabaseTable.h"
#include "../columns/MYSQLTableColumn.h"

/**
* MYSQLDatabaseTable
* */
class MYSQLDatabaseTable {

    const std::string table_catalog;
    const std::string table_schema;
    const std::string table_name;
    const std::string table_type;
    const std::string engine;
    const std::string version;
    const std::string row_format;
    const std::string rows;
    const std::string avg_row_length;
    const std::string data_length;
    const std::string max_data_length;
    const std::string index_length;
    const std::string data_free;
    const std::string auto_increment;
    const std::string create_time;
    const std::string update_time;
    const std::string check_time;
    const std::string collation;
    const std::string checksum;
    const std::string create_options;
    const std::string comment;
    const std::vector<MYSQLTableColumn> columns;
public:

    MYSQLDatabaseTable(std::string table_catalog,
                       std::string table_schema, std::string table_name, std::string table_type,
                       std::string engine, std::string version, std::string row_format,
                       std::string rows, std::string avg_row_length, std::string data_length,
                       std::string max_data_length, std::string index_length,
                       std::string data_free, std::string auto_increment, std::string create_time,
                       std::string update_time, std::string check_time, std::string collation,
                       std::string checksum, std::string create_options, std::string comment,
                       std::vector<MYSQLTableColumn> columns)
            : table_catalog(std::move(table_catalog)), table_schema(std::move(table_schema)),
              table_name(std::move(table_name)), table_type(std::move(table_type)),
              engine(std::move(engine)), version(std::move(version)), row_format(std::move(row_format)),
              rows(std::move(rows)), avg_row_length(std::move(avg_row_length)),
              data_length(std::move(data_length)), max_data_length(std::move(max_data_length)),
              index_length(std::move(index_length)), data_free(std::move(data_free)),
              auto_increment(std::move(auto_increment)), create_time(std::move(create_time)),
              update_time(std::move(update_time)),
              check_time(std::move(check_time)), collation(std::move(collation)), checksum(std::move(checksum)),
              create_options(std::move(create_options)),
              comment(std::move(comment)), columns(std::move(columns)) {}

    const std::string &getTable_catalog() const {
        return table_catalog;
    }

    const std::string &getTable_schema() const {
        return table_schema;
    }

    const std::string &getTable_name() const {
        return table_name;
    }

    const std::string &getTable_type() const {
        return table_type;
    }

    const std::string &getEngine() const {
        return engine;
    }

    const std::string &getVersion() const {
        return version;
    }

    const std::string &getRow_format() const {
        return row_format;
    }

    const std::string &getRows() const {
        return rows;
    }

    const std::string &getAvg_row_length() const {
        return avg_row_length;
    }

    const std::string &getData_length() const {
        return data_length;
    }

    const std::string &getMax_data_length() const {
        return max_data_length;
    }

    const std::string &getIndex_length() const {
        return index_length;
    }

    const std::string &getData_free() const {
        return data_free;
    }

    const std::string &getAuto_increment() const {
        return auto_increment;
    }

    const std::string &getCreate_time() const {
        return create_time;
    }

    const std::string &getUpdate_time() const {
        return update_time;
    }

    const std::string &getCheck_time() const {
        return check_time;
    }

    const std::string &getCollation() const {
        return collation;
    }

    const std::string &getChecksum() const {
        return checksum;
    }

    const std::string &getCreate_options() const {
        return create_options;
    }

    const std::string &getComment() const {
        return comment;
    }

    const std::vector<MYSQLTableColumn> &getColumns() const {
        return columns;
    }
};

#endif //DBCRUDGEN_CPP_MYSQLDATABASETABLE_H
