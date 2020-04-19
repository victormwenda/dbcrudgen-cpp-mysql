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
#include "../../codegen/java/JaxRsWebXMLCodeGen.h"
#include "../../codegen/java/JaxRSWebApplicationCodeGen.h"
#include "../../codegen/java/JaxbCodeGen.h"

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
                FilesWriter::createDirs(projectModel.getAbsoluteWebInfDirPath());
                FilesWriter::createDirs(projectModel.getEntitiesAbsolutePath());
                FilesWriter::createDirs(projectModel.getApisAbsolutePath());
                FilesWriter::createDirs(projectModel.getTransactionsAbsolutePath());
                FilesWriter::createDirs(projectModel.getWebApplicationAbsolutePath());
                FilesWriter::createDirs(projectModel.getDatabaseConnectionAbsolutePath());
                FilesWriter::createDirs(projectModel.getBeansAbsolutePath());
            }

            /**
             * Create a java jax-ws project
             */
            void createProject() override {
                JavaProjectCreator::createProject();
            }

            /**
             * Create project source files
             */
            void createSourceFiles() override {
                JavaProjectCreator::createSourceFiles();

                std::string webXMLSource = JaxRsWebXMLCodeGen::createWebXML(projectModel);
                std::string webAppSource = JaxRsWebApplicationCodeGen::createWebApplication(projectModel);

                std::vector<dbcrudgen::db::generic::Table> tables = database.getTables();

                JaxRsClassResourcesTemplate rsClassResourcesTemplate;
                HibernateClassEntityTemplate hEntityTemplate;
                HibernateClassTransactionsTemplate hTrxTemplate;
                HibernateParameterEntityMappingTemplate hEntityParamTemplate;

                createHibernateConnectionClass();

                std::string entityMappings;
                std::string webApiClassesImports;
                std::string webApiClasses;


                for (const dbcrudgen::db::generic::Table &table : tables) {

                    const std::string &tableName = table.getTableName();

                    std::string apiSuffix = projectModel.getApiClassSuffix();
                    std::string entitySuffix = projectModel.getEntityClassSuffix();
                    std::string trxSuffix = projectModel.getTrxClassSuffix();
                    std::string beansSuffix = projectModel.getBeansClassSuffix();

                    std::string tmpClassName = JavaParser::toJavaClassName(tableName);

                    std::string apiClass = tmpClassName;
                    std::string entityClass = tmpClassName;
                    std::string trxClass = tmpClassName;
                    std::string beansClass = tmpClassName;

                    apiClass.append(apiSuffix);
                    entityClass.append(entitySuffix);
                    trxClass.append(trxSuffix);
                    beansClass.append(beansSuffix);

                    std::string apiSource = rsClassResourcesTemplate.getTemplate();
                    std::string entitySource = hEntityTemplate.getTemplate();
                    std::string trxSource = hTrxTemplate.getTemplate();
                    std::string beansSource = JaxbCodeGen::createBeansSource(projectModel, beansClass);
                    std::string mappingSource = hEntityParamTemplate.getTemplate();


                    JaxRsResourcesParser::parseClassDetails(projectModel, apiSource, tableName, apiClass);
                    HibernateEntitiesParser::parseClassDetails(projectModel, entitySource, tableName, entityClass);
                    HibernateTransactionsParser::parseClassDetails(projectModel, trxSource, trxClass);

                    entityMappings += HibernateParser::parseEntityClassMapping(mappingSource,
                                                                               projectModel.getPackageName(),
                                                                               projectModel.getEntitiesPkg(),
                                                                               entityClass);

                    webApiClassesImports += JaxRsWebApplicationCodeGen::parseWebAPIResourceClassImport(
                            projectModel.getPackageName(), projectModel.getApisPkg(), apiClass);

                    webApiClasses += JaxRsWebApplicationCodeGen::parseWebAPIResourceClass(apiClass);

                    std::string entityInstanceVars;
                    std::string entityGetterSetters;

                    std::string beansInstanceVars;
                    std::string beansGetterSetters;
                    std::string beanCtorVariables;
                    std::string beanInstanceVariablesInit;
                    std::string beanDefaultCtorVariablesInit;

                    const std::vector<dbcrudgen::db::generic::Column> &columns = table.getTableColumns();

                    int index = 0;
                    for (const dbcrudgen::db::generic::Column &column : columns) {

                        entityInstanceVars += HibernateEntitiesParser::createInstanceVariable(column);
                        entityGetterSetters += HibernateEntitiesParser::createGetterSetter(column);

                        beansInstanceVars += JaxbCodeGen::createInstanceVariable(column);
                        beansGetterSetters += JaxbCodeGen::createGetterSetter(column);
                        beanCtorVariables += JaxbCodeGen::createConstructorVariable(column, index < columns.size() - 1);
                        beanInstanceVariablesInit += JaxbCodeGen::createInstanceVariableConstructorInitialization(
                                column);
                        beanDefaultCtorVariablesInit += JaxbCodeGen::createInstanceVariableDefaultBeanConstructorInitialization(
                                column);

                        index++;
                    }

                    HibernateEntitiesParser::parseColumnInstanceVariables(entitySource, entityInstanceVars);
                    HibernateEntitiesParser::parseColumnGetterSetters(entitySource, entityGetterSetters);

                    JaxbCodeGen::addInstanceVariables(beansSource, beansInstanceVars);
                    JaxbCodeGen::addGetterSetters(beansSource, beansGetterSetters);
                    JaxbCodeGen::addConstructorVariables(beansSource, beanCtorVariables);
                    JaxbCodeGen::addConstructorVariablesInitialization(beansSource, beanInstanceVariablesInit);
                    JaxbCodeGen::addDefaultInstanceVariablesInitialization(beansSource, beanDefaultCtorVariablesInit);

                    std::string apiFile =
                            projectModel.getApisAbsolutePath() + "/" + apiClass + ".java";

                    std::string entityFile =
                            projectModel.getEntitiesAbsolutePath() + "/" + entityClass + ".java";

                    std::string trxFile =
                            projectModel.getTransactionsAbsolutePath() + "/" + trxClass + ".java";

                    std::string beanFile =
                            projectModel.getBeansAbsolutePath() + "/" + beansClass + ".java";

                    FilesWriter::writeFile(apiFile, apiSource);
                    FilesWriter::writeFile(entityFile, entitySource);
                    FilesWriter::writeFile(trxFile, trxSource);
                    FilesWriter::writeFile(beanFile, beansSource);
                }


                //Add API classes to application class
                JaxRsWebApplicationCodeGen::addApisResources(webAppSource, webApiClassesImports, webApiClasses);


                createWebXMLFile(webXMLSource);
                createWebApplicationClassFile(webAppSource);
                createHibernateConnectionScript(entityMappings);

            }

            /**
             * Create the hibernate connection class
             */
            void createHibernateConnectionClass() {
                HibernateClassConfigurationTemplate hConnConfigTemplate;
                std::string connPath = projectModel.getDatabaseConnectionAbsolutePath();
                std::string connConfigFile = connPath + "/" + projectModel.getDbConnClassName() + ".java";

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
             * Writes the Web XML Source on disk
             * @param webXmlSource
             */
            void createWebXMLFile(const std::string &webXmlSource) {
                FilesWriter::writeFile(projectModel.getAbsoluteWebXMLFilePathSrc(), webXmlSource);
                //FilesWriter::writeFile(projectModel.getAbsoluteWebXMLFilePathRes(), webXmlSource);
            }

            /**
            * Writes the Web XML Source on disk
            * @param webAppSource
            */
            void createWebApplicationClassFile(const std::string &webAppSource) {
                std::string filename = projectModel.getWebApplicationFileAbsolutePath();
                FilesWriter::writeFile(filename, webAppSource);
            }

        };
    }
}
#endif //DBCRUDGEN_CPP_JAXRSPROJECTCREATOR_H
