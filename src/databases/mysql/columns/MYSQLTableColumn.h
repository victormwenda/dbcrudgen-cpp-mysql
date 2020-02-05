//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 8/25/17.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_MYSQLTABLECOLUMN_H
#define DBCRUDGEN_CPP_MYSQLTABLECOLUMN_H


#include <string>
#include <utility>
#include "../../sql/columns/TableColumn.h"

//
// MYSQLTableColumn
// //
class MYSQLTableColumn : public TableColumn {

private:
    const std::string field;
    const std::string type;
    const std::string collation;
    const std::string allowNull;
    const std::string key;
    const std::string defaultValue;
    const std::string extra;
    const std::string privileges;
    const std::string comment;
public:
    MYSQLTableColumn(std::string field, std::string type, std::string collation,
                     std::string allowNull, std::string key, std::string defaultValue,
                     std::string extra, std::string privileges, std::string comment) :
            TableColumn(field, type),
            field(std::move(field)), type(std::move(type)), collation(std::move(collation)),
            allowNull(std::move(allowNull)), key(
            std::move(key)),
            defaultValue(std::move(defaultValue)), extra(std::move(extra)), privileges(std::move(privileges)), comment(
            std::move(comment)) {}

    const std::string &getField() const {
        return field;
    }

    const std::string &getType() const {
        return type;
    }

    const std::string &getCollation() const {
        return collation;
    }

    const std::string &getAllowNull() const {
        return allowNull;
    }

    const std::string &getKey() const {
        return key;
    }

    const std::string &getDefaultValue() const {
        return defaultValue;
    }

    const std::string &getExtra() const {
        return extra;
    }

    const std::string &getPrivileges() const {
        return privileges;
    }

    const std::string &getComment() const {
        return comment;
    }
};


#endif //DBCRUDGEN_CPP_MYSQLTABLECOLUMN_H
