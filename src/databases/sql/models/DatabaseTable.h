/**
* @author Victor Mwenda
* @author vmwenda.vm@gmail.com
*
* Created by victor on 6/15/17.
* C/C++ Laptop
*/



#ifndef DBCRUDGEN_CPP_DATABASETABLE_H
#define DBCRUDGEN_CPP_DATABASETABLE_H

#include <iostream>
#include <vector>
#include "../columns/TableColumn.h"


/**
* DatabaseTable
* */

class DatabaseTable {

    //Ensure that the vector of tables columns holds objects of base table column
//    static_assert(std::is_base_of<TableColumn,T>::value,"Table columns must be base of TableColumn");


private:
    std::string tableName;
    std::vector<TableColumn> tableColumns;
public:

    DatabaseTable(const std::string &tableName, const std::vector<TableColumn> &tableColumns)
            : tableName(tableName), tableColumns(tableColumns) {}

    const std::string &getTableName() const {
        return tableName;
    }

    const std::vector<TableColumn> &getTableColumns() const {
        return tableColumns;
    }
};


#endif //DBCRUDGEN_CPP_DATABASETABLE_H
