//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 8/5/17.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_DATABASEMODELCREATOR_H
#define DBCRUDGEN_CPP_DATABASEMODELCREATOR_H


#include "../models/OracleDatabaseModel.h"
#include "OracleDatabaseModelCreator.h"
#include "../models/MYSQLDatabaseModel.h"
#include "../models/SQLiteDatabaseModel.h"

//
// DatabaseModelCreator
// //
class DatabaseModelCreator {

public:
    static MYSQLDatabaseModel createMYSQLDatabaseModel() {
        return nullptr;
    }

    static OracleDatabaseModel createOracleDatabaseModel() {
        return nullptr;
    }

    static SQLiteDatabaseModel createSQLiteDatabaseModel() { return nullptr; }
};


#endif //DBCRUDGEN_CPP_DATABASEMODELCREATOR_H
