/**
* @author Victor Mwenda
* @author vmwenda.vm@gmail.com
*
* Created by victor on 6/14/17.
* C/C++ Laptop
*/



#ifndef DBCRUDGEN_CPP_TABLECOLUMN_H
#define DBCRUDGEN_CPP_TABLECOLUMN_H

#include <iostream>

/**
* TableColumn
* */
class TableColumn {

private:
    std::string field;
public:
    const std::string &getField() const {
        return field;
    }

    const std::string &getType() const {
        return type;
    }

    const std::string &getNullValue() const {
        return nullValue;
    }

    const std::string &getKeyType() const {
        return keyType;
    }

    const std::string &getDefaultValue() const {
        return defaultValue;
    }

    const std::string &getExtra() const {
        return extra;
    }

private:
    std::string type;
    std::string nullValue;
    std::string keyType;
    std::string defaultValue;
    std::string extra;
public:
    TableColumn(const std::string &field, const std::string &type, const std::string &nullValue,
                const std::string &keyType, const std::string &defaultValue, const std::string &extra)
            : field(field), type(type), nullValue(nullValue), keyType(keyType), defaultValue(defaultValue),
              extra(extra) {}

    bool operator==(const TableColumn &rhs) const;

    bool operator!=(const TableColumn &rhs) const;

};

bool TableColumn::operator==(const TableColumn &rhs) const {
    return field == rhs.field &&
           type == rhs.type &&
           nullValue == rhs.nullValue &&
           keyType == rhs.keyType &&
           defaultValue == rhs.defaultValue &&
           extra == rhs.extra;
}

bool TableColumn::operator!=(const TableColumn &rhs) const {
    return !(rhs == *this);
}

#endif //DBCRUDGEN_CPP_TABLECOLUMN_H
