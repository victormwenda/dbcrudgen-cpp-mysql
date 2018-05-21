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
#include "TableColumn.h"

//
// MYSQLTableColumn
// //
class MYSQLTableColumn : public TableColumn {
private:
    std::string field;
    std::string type;
    std::string collation;
    std::string allowNull;
    std::string key;
    std::string defaultValue;
    std::string extra;
    std::string privileges;
    std::string comment;
public:
    MYSQLTableColumn(const std::string &field, const std::string &type, const std::string &collation,
                     const std::string &allowNull, const std::string &key, const std::string &defaultValue,
                     const std::string &extra, const std::string &privileges, const std::string &comment) :
            TableColumn(field),
            field(field), type(type), collation(collation), allowNull(allowNull), key(key),
            defaultValue(defaultValue), extra(extra), privileges(privileges), comment(comment) {}

    const std::string &getField() const {
        return field;
    }

    void setField(const std::string &field) {
        MYSQLTableColumn::field = field;
    }

    const std::string &getType() const {
        return type;
    }

    void setType(const std::string &type) {
        MYSQLTableColumn::type = type;
    }

    const std::string &getCollation() const {
        return collation;
    }

    void setCollation(const std::string &collation) {
        MYSQLTableColumn::collation = collation;
    }

    const std::string &getAllowNull() const {
        return allowNull;
    }

    void setAllowNull(const std::string &allowNull) {
        MYSQLTableColumn::allowNull = allowNull;
    }

    const std::string &getKey() const {
        return key;
    }

    void setKey(const std::string &key) {
        MYSQLTableColumn::key = key;
    }

    const std::string &getDefaultValue() const {
        return defaultValue;
    }

    void setDefaultValue(const std::string &defaultValue) {
        MYSQLTableColumn::defaultValue = defaultValue;
    }

    const std::string &getExtra() const {
        return extra;
    }

    void setExtra(const std::string &extra) {
        MYSQLTableColumn::extra = extra;
    }

    const std::string &getPrivileges() const {
        return privileges;
    }

    void setPrivileges(const std::string &privileges) {
        MYSQLTableColumn::privileges = privileges;
    }

    const std::string &getComment() const {
        return comment;
    }

    void setComment(const std::string &comment) {
        MYSQLTableColumn::comment = comment;
    }
};


#endif //DBCRUDGEN_CPP_MYSQLTABLECOLUMN_H
