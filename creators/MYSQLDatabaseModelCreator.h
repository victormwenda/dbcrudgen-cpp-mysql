//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 8/5/17.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_MYSQLDATABASEMODELCREATOR_H
#define DBCRUDGEN_CPP_MYSQLDATABASEMODELCREATOR_H


#include <vector>
#include "../models/MYSQLDatabaseModel.h"
#include "../core/database/connectors/MYSQLDatabaseConnector.h"
#include "../utils/TransactionUtils.h"
#include "../core/database/exceptions/MYSQLDatabaseException.h"
#include "../core/database/relations/MYSQLDatabaseTable.h"

//
// MYSQLDatabaseModelCreator
// //
class MYSQLDatabaseModelCreator {

public:
    /**
    * Creates a MYSQL database model
    * @return
    */
    MYSQLDatabaseModel createDatabaseModel(MYSQLDatabaseConnector &connector, const std::string &schemas) {

        if (schemas.empty()) {
            return nullptr;
        }

        //Get list of all the tables in the database
        std::vector<std::string> databaseTables = TransactionUtils::getMYSQLDatabaseTables(connector, schemas);


        //Get all the table structure
        for (std::string tableName : databaseTables) {
            std::vector<MYSQLTableColumn> tableColumns = TransactionUtils::getMYSQLTableColumns(connector, schemas, tableName);
        }

        return nullptr;

    }
};


#endif //DBCRUDGEN_CPP_MYSQLDATABASEMODELCREATOR_H
