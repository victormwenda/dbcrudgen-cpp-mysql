//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 8/5/17.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_JAVASQLITEPROJECTCREATOR_H
#define DBCRUDGEN_CPP_JAVASQLITEPROJECTCREATOR_H

#include "../ProjectCreator.h"
#include "../../codegen/Languages.h"
#include "../../codegen/Databases.h"

namespace dbcrudgen {

    namespace orm {

        class JavaSQLiteProjectCreator : ProjectCreator {

        public:

            JavaSQLiteProjectCreator() = default;

            /**
             *
             * Get the programming language used to develop the project
             * @return
             */
            std::string getLanguage() override {
                return std::string{Languages::JAVA};
            }

            /**
             * Get the database used for generating the project
             * @return
             */
            std::string getDatabase() override {
                return std::string{Databases::SQLite};
            }
        };

    }
}
#endif //DBCRUDGEN_CPP_JAVASQLITEPROJECTCREATOR_H
