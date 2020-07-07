//
// Created by victor on 4/14/20.
//

#ifndef DBCRUDGEN_CPP_HIBERNATETRANSACTIONSPARSER_H
#define DBCRUDGEN_CPP_HIBERNATETRANSACTIONSPARSER_H

#include "HibernateParser.h"
#include "../../projects/JaxRsProjectModel.h"

namespace dbcrudgen {
    namespace orm {
        class HibernateTransactionsParser : public HibernateParser {
        public:

            /**
              * Set the class name and other general class details
              * @param model
              * @param sourceTemplate
              * @param className
              */
            static std::string
            parseClassDetails(const dbcrudgen::orm::JaxRsProjectModel &model, std::string &sourceTemplate,
                              const std::string &className, const std::string &entityClass,
                              const db::generic::Column &primaryKeyColumn) {
                StringUtils::replace(sourceTemplate, "${PROJECT_PACKAGE}", model.getPackageName());
                StringUtils::replace(sourceTemplate, "${TRANSACTIONS_PACKAGE}", model.getTransactionsPkg());
                StringUtils::replace(sourceTemplate, "${DB_CONN_PACKAGE}", model.getDbConnPkg());
                StringUtils::replace(sourceTemplate, "${DB_CONN_CLASS}", model.getDbConnClassName());
                StringUtils::replace(sourceTemplate, "${VISIBILITY}", "public");
                StringUtils::replace(sourceTemplate, "${CLASS_NAME}", className);

                StringUtils::replace(sourceTemplate, "${ENTITY_PACKAGE}", model.getEntitiesPkg());
                StringUtils::replace(sourceTemplate, "${ENTITY_CLASS}", entityClass);
                StringUtils::replace(sourceTemplate, "${ENTITY_OBJECT}", toJavaVariableInstance(entityClass));

                StringUtils::replace(sourceTemplate, "${PRIMARY_KEY_DATATYPE}",
                                     toJavaDataType(primaryKeyColumn.getDataType()));
                StringUtils::replace(sourceTemplate, "${ENTITY_PRIMARY_KEY}",
                                     toJavaVariableInstance(primaryKeyColumn.getColumnName()));

                return sourceTemplate;
            }

            /**
              * Set the class name and other general class details
              * @param model
              * @param sourceTemplate
              * @param className
              */
            static std::string
            parseClassDetails(const dbcrudgen::orm::SpringBootProjectModel &model, std::string &sourceTemplate,
                              const std::string &className, const std::string &entityClass,
                              const db::generic::Column &primaryKeyColumn) {
                StringUtils::replace(sourceTemplate, "${PROJECT_PACKAGE}", model.getPackageName());
                StringUtils::replace(sourceTemplate, "${TRANSACTIONS_PACKAGE}", model.getTransactionsPkg());
                StringUtils::replace(sourceTemplate, "${DB_CONN_PACKAGE}", model.getDbConnPkg());
                StringUtils::replace(sourceTemplate, "${DB_CONN_CLASS}", model.getDbConnClassName());
                StringUtils::replace(sourceTemplate, "${VISIBILITY}", "public");
                StringUtils::replace(sourceTemplate, "${CLASS_NAME}", className);

                StringUtils::replace(sourceTemplate, "${ENTITY_PACKAGE}", model.getEntitiesPkg());
                StringUtils::replace(sourceTemplate, "${ENTITY_CLASS}", entityClass);
                StringUtils::replace(sourceTemplate, "${ENTITY_OBJECT}", toJavaVariableInstance(entityClass));

                StringUtils::replace(sourceTemplate, "${PRIMARY_KEY_DATATYPE}",
                                     toJavaDataType(primaryKeyColumn.getDataType()));
                StringUtils::replace(sourceTemplate, "${ENTITY_PRIMARY_KEY}",
                                     toJavaVariableInstance(primaryKeyColumn.getColumnName()));

                return sourceTemplate;
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_HIBERNATETRANSACTIONSPARSER_H
