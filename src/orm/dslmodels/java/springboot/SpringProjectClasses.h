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
            std::string applicationProperties;
        public:
            SpringProjectClasses(std::string &dbConnClass, std::string &webAppClass, std::string &applicationProperties)
                    :
                    dbConnClass(dbConnClass), webAppClass(webAppClass), applicationProperties(applicationProperties) {}

            const std::string &getDbConnClass() const {
                return dbConnClass;
            }

            const std::string &getWebAppClass() const {
                return webAppClass;
            }

            const std::string &getApplicationPropertiesFile() const {
                return applicationProperties;
            }
        };
    }
}


#endif //DBCRUDGEN_CPP_SPRINGPROJECTCLASSES_H
