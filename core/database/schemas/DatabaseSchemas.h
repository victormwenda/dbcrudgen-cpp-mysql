/**
* @author Victor Mwenda
* @author vmwenda.vm@gmail.com
*
* Created by victor on 6/13/17.
* C/C++ Laptop
*/

#ifndef DBCRUDGEN_CPP_DATABASE_H
#define DBCRUDGEN_CPP_DATABASE_H

#include <iostream>
#include <vector>
#include "../connection/DatabaseConnection.h"
#include "../columns/TableColumn.h"

using namespace std;

template<typename T>
class DatabaseSchemas {

    //Ensure that the vector of table columns holds class of base table column
    static_assert(std::is_base_of<TableColumn, T>::value, "Table columns must be base of TableColumn");

private:
    std::string databaseName;
    std::vector<T> tableColumns;
    DatabaseConnection connection;
public:
    DatabaseSchemas(const std::string databaseName, const std::vector<T> tableColumns,
                    const DatabaseConnection connection) :
            databaseName(databaseName), tableColumns(tableColumns), connection(connection) {

    }

    const string &getDatabaseName() const {
        return databaseName;
    }

    const vector<T> &getTableColumns() const {
        return tableColumns;
    }

    const DatabaseConnection &getConnection() const {
        return connection;
    }
};


#endif //DBCRUDGEN_CPP_DATABASE_H
