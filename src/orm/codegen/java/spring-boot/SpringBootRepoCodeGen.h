//
// Created by victor on 12/20/20.
//

#ifndef DBCRUDGEN_CPP_SPRINGBOOTREPOCODEGEN_H
#define DBCRUDGEN_CPP_SPRINGBOOTREPOCODEGEN_H


#include "../JavaProjectCodeGen.h"
#include "../../../projects/SpringBootProjectModel.h"
#include "../../../parsers/java/SpringBootApplicationParser.h"
#include "../../../templates/java/spring-boot/SpringBootClassRepoTemplate.h"
#include "../../../templates/java/JavaVariableInstanceTemplate.h"

namespace dbcrudgen {
    namespace orm {
        class SpringBootRepoCodeGen : public JavaProjectCodeGen {
        public:
            static std::string
            createRepositorySource(dbcrudgen::orm::SpringBootProjectModel &projectModel,
                                   const std::string &repoClass , const std::string &entityClass) {
                SpringBootClassRepoTemplate repoTemplate;
                std::string repoSource = repoTemplate.getTemplate();

                repoSource = SpringBootApplicationParser::substituteRepoClassDetails(projectModel, repoSource, repoClass,entityClass);
                return repoSource;
            }

            /**
             * Create an instance variable
             * @param column
             * @return
             */
            static std::string createInstanceVariable(const dbcrudgen::db::generic::Column &column) {
                JavaVariableInstanceTemplate javaVarTemplate;
                std::string srcTemplate = javaVarTemplate.getTemplate();

                StringUtils::replace(srcTemplate, "${VISIBILITY}", "private");
                StringUtils::replace(srcTemplate, "${DATA_TYPE}", JavaParser::toJavaDataType(column.getDataType()));
                StringUtils::replace(srcTemplate, "${OBJECT_NAME}",
                                     JavaParser::toJavaVariableInstance(column.getColumnName()));

                return srcTemplate;
            }
        };

    }
}
#endif //DBCRUDGEN_CPP_SPRINGBOOTREPOCODEGEN_H
