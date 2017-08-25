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
    std::string columnName;
public:

public:
    explicit TableColumn(const std::string &columnName) : columnName(columnName) {}

    bool operator==(const TableColumn &rhs) const;

    bool operator!=(const TableColumn &rhs) const;

};

bool TableColumn::operator==(const TableColumn &rhs) const {
    return columnName == rhs.columnName;
}

bool TableColumn::operator!=(const TableColumn &rhs) const {
    return !(rhs == *this);
}

#endif //DBCRUDGEN_CPP_TABLECOLUMN_H
