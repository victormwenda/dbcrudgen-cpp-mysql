//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 8/5/17.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_CPPMYSQLPROJECTCREATOR_H
#define DBCRUDGEN_CPP_CPPMYSQLPROJECTCREATOR_H


#include <vector>
#include "../../../databases/mysql/models/MYSQLDatabaseModel.h"
#include "../../../databases/mysql/connectors/MYSQLDatabaseConnector.h"
#include "../../../databases/mysql/models/MYSQLDatabaseTable.h"
#include "../../utils/TransactionUtils.h"
#include "../ProjectCreator.h"

//
// JavaMYSQLDatabaseModelCreator
// //
class CppMYSQLProjectCreator : ProjectCreator {

public:

    CppMYSQLProjectCreator() = default;

    /**
     *
     * Get the programming language used to develop the project
     * @return
     */
    std::string getLanguage() override {
        return std::string{"cpp"};
    }

    /**
     * Get the database used for generating the project
     * @return
     */
    std::string getDatabase() override {
        return std::string{"mysql"};
    }
};


#endif //DBCRUDGEN_CPP_CPPMYSQLPROJECTCREATOR_H
