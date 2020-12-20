//
// Created by victor on 12/20/20.
//

#ifndef DBCRUDGEN_CPP_SPRINGPROJECTCLASSES_H
#define DBCRUDGEN_CPP_SPRINGPROJECTCLASSES_H

#include <string>

namespace dbcrudgen {
    namespace orm {
        class SpringProjectClasses {

        private:
            std::string dbConnClass;
            std::string webAppClass;
        public:
            SpringProjectClasses(std::string &dbConnClass, std::string &webAppClass) :
                    dbConnClass(dbConnClass), webAppClass(webAppClass) {}

            const std::string &getDbConnClass() const {
                return dbConnClass;
            }

            const std::string &getWebAppClass() const {
                return webAppClass;
            }
        };
    }
}


#endif //DBCRUDGEN_CPP_SPRINGPROJECTCLASSES_H
