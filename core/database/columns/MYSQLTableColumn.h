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

//
// MYSQLTableColumn
// //
class MYSQLTableColumn {
private:
    std::string field;
    std::string type;
    std::string allowNull;
    std::string defaultValue;
    std::string extra;
public:
    MYSQLTableColumn(const std::string field, const std::string type,
                       const std::string allowNull,
                       const std::string defaultValue, const std::string extra)
            : field(field), type(type), allowNull(allowNull), defaultValue(defaultValue), extra(extra) {}

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

    const std::string &getAllowNull() const {
        return allowNull;
    }

    void setAllowNull(const std::string &allowNull) {
        MYSQLTableColumn::allowNull = allowNull;
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
};


#endif //DBCRUDGEN_CPP_MYSQLTABLECOLUMN_H
