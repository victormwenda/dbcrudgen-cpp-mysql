//
// Created by vrwanda on 3/5/20.
//



#ifndef DBCRUDGEN_CPP_JAVAPROJECTCODEGEN_H
#define DBCRUDGEN_CPP_JAVAPROJECTCODEGEN_H

#include "../ProjectCodeGen.h"
#include "../../templates/java/JavaVariableInstanceTemplate.h"

namespace dbcrudgen {
    namespace orm {
        class JavaProjectCodeGen : public ProjectCodeGen {

        public:
            /**
              * Create an instance variable
              * @param column
              * @param visibility
              * @return
              */
            static std::string
            createInstanceVariable(const std::string &dataType, const std::string &objectName,
                                   std::string visibility = "private") {
                JavaVariableInstanceTemplate javaVarTemplate;
                std::string srcTemplate = javaVarTemplate.getTemplate();

                StringUtils::replace(srcTemplate, "${VISIBILITY}", visibility);
                StringUtils::replace(srcTemplate, "${DATA_TYPE}", dataType);
                StringUtils::replace(srcTemplate, "${OBJECT_NAME}", objectName);

                return srcTemplate;
            }

            /**
             * Create a private instance variable
             * @param column
             * @return
             */
            static std::string
            createPrivateInstanceVariable(const std::string &dataType, const std::string &objectName) {
                return createInstanceVariable(dataType, objectName, "private");
            }

            /**
             * Create a public instance variable
             * @param column
             * @return
             */
            static std::string
            createPublicInstanceVariable(const std::string &dataType, const std::string &objectName) {
                return createInstanceVariable(dataType, objectName, "public");
            }
        };

    }
}


#endif //DBCRUDGEN_CPP_JAVAPROJECTCODEGEN_H