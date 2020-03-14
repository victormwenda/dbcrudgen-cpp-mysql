//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 8/5/17.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_CPPSQLITEPROJECTCREATOR_H
#define DBCRUDGEN_CPP_CPPSQLITEPROJECTCREATOR_H

#include <string>
#include "../ProjectCreator.h"

namespace dbcrudgen {

    namespace orm {
        //
        // CppSQLiteProjectCreator
        // //
        class CppSQLiteProjectCreator : ProjectCreator {

        public:

            CppSQLiteProjectCreator() = default;


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
                return std::string{"oracle"};
            }
        };
    }
}

#endif //DBCRUDGEN_CPP_CPPSQLITEPROJECTCREATOR_H
