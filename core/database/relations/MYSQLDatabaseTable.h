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

/**
* MYSQLDatabaseTable
* */
class MYSQLDatabaseTable : public DatabaseTable {

    std::string name;
    std::string engine;
    std::string version;
    MYSQLRowFormats row_format;
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

public:

    MYSQLDatabaseTable(const std::string &name, const std::string &engine,
                       const std::string &version, MYSQLRowFormats row_format, const std::string &rows,
                       const std::string &avg_row_length, const std::string &data_length,
                       const std::string &max_data_length, const std::string &index_length,
                       const std::string &data_free, const std::string &auto_increment, const std::string &create_time,
                       const std::string &update_time, const std::string &check_time, const std::string &collation,
                       const std::string &checksum, const std::string &create_options, const std::string &comment)
            : DatabaseTable(name), name(name), engine(engine), version(version), row_format(row_format),
              rows(rows), avg_row_length(avg_row_length), data_length(data_length), max_data_length(max_data_length),
              index_length(index_length), data_free(data_free), auto_increment(auto_increment),
              create_time(create_time), update_time(update_time), check_time(check_time), collation(collation),
              checksum(checksum), create_options(create_options), comment(comment) {}

    const std::string &getName() const {
        return name;
    }

    const std::string &getEngine() const {
        return engine;
    }

    const std::string &getVersion() const {
        return version;
    }

    const MYSQLRowFormats &getRow_format() const {
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

};

#endif //DBCRUDGEN_CPP_MYSQLDATABASETABLE_H
