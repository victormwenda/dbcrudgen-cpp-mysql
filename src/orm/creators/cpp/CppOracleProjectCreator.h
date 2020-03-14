//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 8/5/17.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_CPPORACLEPROJECTCREATOR_H
#define DBCRUDGEN_CPP_CPPORACLEPROJECTCREATOR_H

#include <string>
#include "../ProjectCreator.h"

namespace dbcrudgen {

    namespace orm {
//
// CppOracleProjectCreator
// //
        class CppOracleProjectCreator : ProjectCreator {

        public:
            CppOracleProjectCreator() = default;


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
#endif //DBCRUDGEN_CPP_CPPORACLEPROJECTCREATOR_H
