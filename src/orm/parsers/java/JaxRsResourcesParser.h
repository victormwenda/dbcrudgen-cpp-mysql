//
// Created by victor on 4/14/20.
//

#ifndef DBCRUDGEN_CPP_JAXRSRESOURCESPARSER_H
#define DBCRUDGEN_CPP_JAXRSRESOURCESPARSER_H

#include "JavaParser.h"
#include "../../projects/JaxRsProjectModel.h"

namespace dbcrudgen {
    namespace orm {
        class JaxRsResourcesParser : public JavaParser {

        public:

            /**
             * Create API Resource source code
             * @param model
             * @param apiSource
             * @param table
             * @param column
             * @param apiClass
             * @param entityClass
             * @param trxClass
             * @return
             */
            static std::string
            parseClassDetails(JaxRsProjectModel &model, std::string apiSource, const db::generic::Table &table,
                              const db::generic::Column &column, const std::string &apiClass,
                              const std::string &entityClass,
                              const std::string &trxClass) {
                StringUtils::replace(apiSource, "${PROJECT_PACKAGE}", model.getPackageName());
                StringUtils::replace(apiSource, "${RESOURCES_PACKAGE}", model.getApisPkg());
                StringUtils::replace(apiSource, "${CLASS_NAME}", apiClass);
                StringUtils::replace(apiSource, "${VISIBILITY}", "public");
                StringUtils::replace(apiSource, "${RESOURCE-NAME}", toKebabCase(table.getTableName()));

                StringUtils::replace(apiSource, "${TRX_PACKAGE}", model.getTransactionsPkg());
                StringUtils::replace(apiSource, "${TRX_CLASS}", trxClass);
                StringUtils::replace(apiSource, "${TRX_OBJECT}", toJavaVariableInstance(trxClass));

                StringUtils::replace(apiSource, "${ENTITY_PACKAGE}", model.getEntitiesPkg());
                StringUtils::replace(apiSource, "${ENTITY_CLASS}", entityClass);
                StringUtils::replace(apiSource, "${ENTITY_OBJECT}", toJavaVariableInstance(entityClass));

                StringUtils::replace(apiSource, "${PK_COLUMN_NAME}", column.getColumnName());
                StringUtils::replace(apiSource, "${PK_COLUMN_DATATYPE}", toJavaDataType(column.getDataType()));
                std::string methodGetter = "get";
                methodGetter = methodGetter.append(toJavaClassName(column.getColumnName()));
                StringUtils::replace(apiSource, "${PK_METHOD_GETTER}", methodGetter);

                return apiSource;
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_JAXRSRESOURCESPARSER_H
