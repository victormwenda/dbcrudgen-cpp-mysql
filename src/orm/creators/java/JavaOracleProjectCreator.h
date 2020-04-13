//
// Created by victor on 3/14/20.
//

#ifndef DBCRUDGEN_CPP_JAVAORACLEPROJECTCREATOR_H
#define DBCRUDGEN_CPP_JAVAORACLEPROJECTCREATOR_H

#include <string>
#include "../../codegen/Languages.h"
#include "../../codegen/Databases.h"
#include "JavaProjectCreator.h"

namespace dbcrudgen {
    namespace orm {
        class JavaOracleProjectCreator : public JavaProjectCreator {

            JavaOracleProjectCreator() : JavaProjectCreator{} {}

            std::string getLanguage() override {
                return std::string{Languages::JAVA};
            }

            std::string getDatabase() override {
                return std::string{Databases::ORACLE};
            }

            void createProject() override {

            }
        };
    }
}


#endif //DBCRUDGEN_CPP_JAVAORACLEPROJECTCREATOR_H
