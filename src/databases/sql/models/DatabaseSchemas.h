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
#include "../columns/TableColumn.h"
#include "DatabaseTable.h"
#include "../connectors/DatabaseConnection.h"

using namespace std;

template<typename T>
class DatabaseSchemas {

    //Ensure that the vector of tables holds class of base database table
    static_assert(std::is_base_of<DatabaseTable, T>::value, "Table columns must be base of DatabaseTable");

private:
    std::string databaseName;
    std::vector<T> databaseTables;
    DatabaseConnection connection;

public:
    DatabaseSchemas(const std::string databaseName, const std::vector<T> databaseTables,
                    const DatabaseConnection connection) :
            databaseName(databaseName), databaseTables(databaseTables), connection(connection) {

    }

    const string &getDatabaseName() const {
        return databaseName;
    }

    const vector<T> &getDatabaseTables() const {
        return databaseTables;
    }

    const DatabaseConnection &getConnection() const {
        return connection;
    }
};


#endif //DBCRUDGEN_CPP_DATABASE_H
