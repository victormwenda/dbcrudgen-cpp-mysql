//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 8/5/17.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_JAVAMYSQLPROJECTCREATOR_H
#define DBCRUDGEN_CPP_JAVAMYSQLPROJECTCREATOR_H

#include "../../codegen/Languages.h"
#include "../../codegen/Databases.h"
#include "JavaProjectCreator.h"

namespace dbcrudgen {
    namespace orm {

        class JavaMYSQLProjectCreator : public JavaProjectCreator {

        public:

            JavaMYSQLProjectCreator() : JavaProjectCreator{} {}

        private:
            std::string getLanguage() override {
                return std::string{Languages::JAVA};
            }

            std::string getDatabase() override {
                return std::string{Databases::MYSQL};
            }

            void createProject() override {

            }
        };

    }
}


#endif //DBCRUDGEN_CPP_JAVAMYSQLPROJECTCREATOR_H
