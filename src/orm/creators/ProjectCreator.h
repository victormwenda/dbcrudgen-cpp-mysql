//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 8/5/17.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_PROJECTCREATOR_H
#define DBCRUDGEN_CPP_PROJECTCREATOR_H


#include "../../databases/oracle/models/OracleDatabaseModel.h"
#include "java/JavaOracleProjectCreator.h"
#include "../../databases/mysql/models/MYSQLDatabaseModel.h"
#include "../../databases/sqlite/models/SQLiteDatabaseModel.h"


namespace dbcrudgen {

    namespace orm {
        //
        // ProjectCreator
        // //
        class ProjectCreator {

        public:
            /**
             * Get the programming language used for generating the project
             * @return
             */
            virtual std::string getLanguage() = 0;

            /**
             * Get the database used for generating the project
             * @return
             */
            virtual std::string getDatabase() = 0;

            /**
             * Creates a project
             */
            virtual void createProject() = 0;
        };
    }
}

#endif //DBCRUDGEN_CPP_PROJECTCREATOR_H
