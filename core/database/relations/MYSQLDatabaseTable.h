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
#include "../formats/RowFormats.h"
#include "DatabaseTable.h"
#include "../columns/MYSQLTableColumn.h"

/**
* MYSQLDatabaseTable
* */
class MYSQLDatabaseTable {

    std::string table_catalog;
    std::string table_schema;
    std::string table_name;
    std::string table_type;
    std::string engine;
    std::string version;
    std::string row_format;
    std::string rows;
    std::string avg_row_length;
    std::string data_length;
    std::string max_data_length;
    std::string index_length;
    std::string data_free;
    std::string auto_increment;
    std::string create_time;
    std::string update_time;
    std::string check_time;
    std::string collation;
    std::string checksum;
    std::string create_options;
    std::string comment;
    std::vector<MYSQLTableColumn> columns;
public:

    MYSQLDatabaseTable(const std::string &table_catalog,
                       const std::string &table_schema, const std::string &table_name, const std::string &table_type,
                       const std::string &engine, const std::string &version, const std::string &row_format,
                       const std::string &rows, const std::string &avg_row_length, const std::string &data_length,
                       const std::string &max_data_length, const std::string &index_length,
                       const std::string &data_free, const std::string &auto_increment, const std::string &create_time,
                       const std::string &update_time, const std::string &check_time, const std::string &collation,
                       const std::string &checksum, const std::string &create_options, const std::string &comment,
                       const std::vector<MYSQLTableColumn> &columns)
            : table_catalog(table_catalog), table_schema(table_schema), table_name(table_name), table_type(table_type),
              engine(engine), version(version), row_format(row_format), rows(rows), avg_row_length(avg_row_length),
              data_length(data_length), max_data_length(max_data_length), index_length(index_length),
              data_free(data_free), auto_increment(auto_increment), create_time(create_time), update_time(update_time),
              check_time(check_time), collation(collation), checksum(checksum), create_options(create_options),
              comment(comment), columns(columns) {}


    const std::string &getTable_catalog() const {
        return table_catalog;
    }

    void setTable_catalog(const std::string &table_catalog) {
        MYSQLDatabaseTable::table_catalog = table_catalog;
    }

    const std::string &getTable_schema() const {
        return table_schema;
    }

    void setTable_schema(const std::string &table_schema) {
        MYSQLDatabaseTable::table_schema = table_schema;
    }

    const std::string &getTable_name() const {
        return table_name;
    }

    void setTable_name(const std::string &table_name) {
        MYSQLDatabaseTable::table_name = table_name;
    }

    const std::string &getTable_type() const {
        return table_type;
    }

    void setTable_type(const std::string &table_type) {
        MYSQLDatabaseTable::table_type = table_type;
    }

    const std::string &getEngine() const {
        return engine;
    }

    void setEngine(const std::string &engine) {
        MYSQLDatabaseTable::engine = engine;
    }

    const std::string &getVersion() const {
        return version;
    }

    void setVersion(const std::string &version) {
        MYSQLDatabaseTable::version = version;
    }

    const std::string &getRow_format() const {
        return row_format;
    }

    void setRow_format(const std::string &row_format) {
        MYSQLDatabaseTable::row_format = row_format;
    }

    const std::string &getRows() const {
        return rows;
    }

    void setRows(const std::string &rows) {
        MYSQLDatabaseTable::rows = rows;
    }

    const std::string &getAvg_row_length() const {
        return avg_row_length;
    }

    void setAvg_row_length(const std::string &avg_row_length) {
        MYSQLDatabaseTable::avg_row_length = avg_row_length;
    }

    const std::string &getData_length() const {
        return data_length;
    }

    void setData_length(const std::string &data_length) {
        MYSQLDatabaseTable::data_length = data_length;
    }

    const std::string &getMax_data_length() const {
        return max_data_length;
    }

    void setMax_data_length(const std::string &max_data_length) {
        MYSQLDatabaseTable::max_data_length = max_data_length;
    }

    const std::string &getIndex_length() const {
        return index_length;
    }

    void setIndex_length(const std::string &index_length) {
        MYSQLDatabaseTable::index_length = index_length;
    }

    const std::string &getData_free() const {
        return data_free;
    }

    void setData_free(const std::string &data_free) {
        MYSQLDatabaseTable::data_free = data_free;
    }

    const std::string &getAuto_increment() const {
        return auto_increment;
    }

    void setAuto_increment(const std::string &auto_increment) {
        MYSQLDatabaseTable::auto_increment = auto_increment;
    }

    const std::string &getCreate_time() const {
        return create_time;
    }

    void setCreate_time(const std::string &create_time) {
        MYSQLDatabaseTable::create_time = create_time;
    }

    const std::string &getUpdate_time() const {
        return update_time;
    }

    void setUpdate_time(const std::string &update_time) {
        MYSQLDatabaseTable::update_time = update_time;
    }

    const std::string &getCheck_time() const {
        return check_time;
    }

    void setCheck_time(const std::string &check_time) {
        MYSQLDatabaseTable::check_time = check_time;
    }

    const std::string &getCollation() const {
        return collation;
    }

    void setCollation(const std::string &collation) {
        MYSQLDatabaseTable::collation = collation;
    }

    const std::string &getChecksum() const {
        return checksum;
    }

    void setChecksum(const std::string &checksum) {
        MYSQLDatabaseTable::checksum = checksum;
    }

    const std::string &getCreate_options() const {
        return create_options;
    }

    void setCreate_options(const std::string &create_options) {
        MYSQLDatabaseTable::create_options = create_options;
    }

    const std::string &getComment() const {
        return comment;
    }

    void setComment(const std::string &comment) {
        MYSQLDatabaseTable::comment = comment;
    }

    std::vector<MYSQLTableColumn> getColumns() const {
        return columns;
    }

    void setColumns(const std::vector<MYSQLTableColumn> &columns) {
        MYSQLDatabaseTable::columns = columns;
    }
};

#endif //DBCRUDGEN_CPP_MYSQLDATABASETABLE_H
