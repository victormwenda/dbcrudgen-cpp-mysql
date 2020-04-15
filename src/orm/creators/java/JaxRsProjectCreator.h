//
// Created by victor on 4/13/20.
//

#ifndef DBCRUDGEN_CPP_JAXRSPROJECTCREATOR_H
#define DBCRUDGEN_CPP_JAXRSPROJECTCREATOR_H

#include "JavaProjectCreator.h"
#include "../../projects/JaxRsProjectModel.h"
#include "../../../databases/generic/Database.h"
#include "../../templates/java/jax-rs/JaxRsClassResourcesTemplate.h"
#include "../../templates/java/crud/hibernate/HibernateClassConfigurationTemplate.h"
#include "../../templates/java/crud/hibernate/HibernateClassEntityTemplate.h"
#include "../../templates/java/crud/hibernate/HibernateClassTransactionsTemplate.h"
#include "../../parsers/java/HibernateConfigurationParser.h"
#include "../../parsers/java/HibernateTransactionsParser.h"
#include "../../parsers/java/HibernateEntitiesParser.h"
#include "../../parsers/java/JaxRsResourcesParser.h"
#include "../../templates/java/crud/hibernate/HibernateScriptConfigurationTemplate.h"
#include "../../templates/java/crud/hibernate/HibernateParameterEntityMappingTemplate.h"

namespace dbcrudgen {
    namespace orm {

        /**
         * JAX-RS Project Creator
         */
        class JaxRsProjectCreator : public JavaProjectCreator {

        private:
            JaxRsProjectModel projectModel;
            dbcrudgen::db::generic::Database database;
        public:

            JaxRsProjectCreator(JaxRsProjectModel &projectModel, dbcrudgen::db::generic::Database &database)
                    : projectModel{projectModel}, database{database}, JavaProjectCreator{projectModel} {}

            std::string getLanguage() override {
                return std::string{Languages::JAVA};
            }

            std::string getDatabase() override {
                return std::string{Databases::GENERIC};
            }

            /**
              * Create project Dirs
              */
            void createProjectDirs() override {
                JavaProjectCreator::createProjectDirs();

                FilesWriter::createDirs(projectModel.getAbsoluteWebDirPath());
                FilesWriter::createDirs(projectModel.getEntitiesAbsolutePath());
                FilesWriter::createDirs(projectModel.getApisAbsolutePath());
                FilesWriter::createDirs(projectModel.getTransactionsAbsolutePath());
            }

            /**
             * Create project source files
             */
            void createSourceFiles() override {
                JavaProjectCreator::createSourceFiles();

                std::vector<dbcrudgen::db::generic::Table> tables = database.getTables();

                JaxRsClassResourcesTemplate rsClassResourcesTemplate;
                HibernateClassEntityTemplate hEntityTemplate;
                HibernateClassTransactionsTemplate hTrxTemplate;
                HibernateParameterEntityMappingTemplate hEntityParamTemplate;

                //createHibernateConnectionClass();

                std::string entityMappings;


                for (const dbcrudgen::db::generic::Table &table : tables) {

                    std::string apiSource = rsClassResourcesTemplate.getTemplate();
                    std::string entitySource = hEntityTemplate.getTemplate();
                    std::string trxSource = hTrxTemplate.getTemplate();
                    std::string mappingSource = hEntityParamTemplate.getTemplate();

                    const std::string &tableName = table.getTableName();

                    std::string apiSuffix = projectModel.getApiClassSuffix();
                    std::string entitySuffix = projectModel.getEntityClassSuffix();
                    std::string trxSuffix = projectModel.getTransactionsClassSuffix();

                    std::string apiClass = JavaParser::toJavaClassName(tableName);
                    std::string entityClass = JavaParser::toJavaClassName(tableName);
                    std::string trxClass = JavaParser::toJavaClassName(tableName);

                    apiClass.append(apiSuffix);
                    entityClass.append(entitySuffix);
                    trxClass.append(trxSuffix);


                    JaxRsResourcesParser::parseClassDetails(projectModel, apiSource, tableName, apiClass);
                    HibernateEntitiesParser::parseClassDetails(projectModel, entitySource, tableName, entityClass);
                    HibernateTransactionsParser::parseClassDetails(projectModel, trxSource, trxClass);

                    entityMappings += HibernateParser::parseEntityClassMapping(mappingSource,
                                                                               projectModel.getPackageName(),
                                                                               projectModel.getEntitiesPkg(),
                                                                               entityClass);

                    std::string entityInstanceVars;
                    std::string entityGetterSetters;

                    const std::vector<dbcrudgen::db::generic::Column> &columns = table.getTableColumns();

                    for (const dbcrudgen::db::generic::Column &column : columns) {

                        entityInstanceVars += HibernateEntitiesParser::createInstanceVariable(column);
                        entityGetterSetters += HibernateEntitiesParser::createGetterSetter(column);
                    }

                    HibernateEntitiesParser::parseColumnInstanceVariables(entitySource, entityInstanceVars);
                    HibernateEntitiesParser::parseColumnGetterSetters(entitySource, entityGetterSetters);

                    std::string apiFile =
                            projectModel.getApisAbsolutePath() + "/" + apiClass + ".java";

                    std::string entityFile =
                            projectModel.getEntitiesAbsolutePath() + "/" + entityClass + ".java";

                    std::string trxFile =
                            projectModel.getTransactionsAbsolutePath() + "/" + trxClass + ".java";

                    //FilesWriter::writeFile(apiFile, apiSource);
                    //FilesWriter::writeFile(entityFile, entitySource);
                    //FilesWriter::writeFile(trxFile, trxSource);
                }


                createHibernateConnectionScript(entityMappings);

            }

            /**
             * Create the hibernate connection class
             */
            void createHibernateConnectionClass() {
                HibernateClassConfigurationTemplate hConnConfigTemplate;
                std::string trxPath = projectModel.getTransactionsAbsolutePath();
                std::string connConfigFile = trxPath + "/DatabaseConnection.java";

                std::string configSource = hConnConfigTemplate.getTemplate();
                HibernateConfigurationParser::parseConfigurationClass(projectModel, configSource);
                FilesWriter::writeFile(connConfigFile, configSource);
            }

            /**
             * Create the hibernate connection script
             * @param entityMappings
             */
            void createHibernateConnectionScript(std::string &entityMappings) {
                HibernateScriptConfigurationTemplate hConnConfigTemplate;
                std::string configSource = hConnConfigTemplate.getTemplate();

                configSource = HibernateParser::parseConnectionScript(configSource, projectModel, database,
                                                                      entityMappings);

                std::string javaPath = projectModel.getAbsoluteJavaPath();
                std::string connConfigFile = javaPath + "/hibernate.cfg.xml";

                HibernateConfigurationParser::parseConfigurationClass(projectModel, configSource);
                FilesWriter::writeFile(connConfigFile, configSource);
            }

            /**
             * Create a java jax-ws project
             */
            void createProject() override {
                JavaProjectCreator::createProject();
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_JAXRSPROJECTCREATOR_H
