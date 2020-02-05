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
#include <utility>

/**
* TableColumn
* */
class TableColumn {

private:
    const std::string columnName;
    const std::string dataType;
public:

public:
    explicit TableColumn(std::string columnName, std::string dataType)
            : columnName(std::move(columnName)), dataType(std::move(dataType)) {}

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
