//
// Created by victor on 7/6/20.
//

#ifndef DBCRUDGEN_CPP_SPRINGBOOTPROJECTCREATOR_H
#define DBCRUDGEN_CPP_SPRINGBOOTPROJECTCREATOR_H

#include "JavaProjectCreator.h"
#include "../../projects/SpringBootProjectModel.h"
#include "../../../databases/generic/Database.h"
#include "../../parsers/java/JavaParser.h"
#include "../../codegen/java/JaxbCodeGen.h"
#include "../../parsers/java/HibernateEntitiesParser.h"
#include "../../parsers/java/HibernateConfigurationParser.h"
#include "../../templates/java/crud/hibernate/HibernateClassConfigurationTemplate.h"
#include "../../codegen/java/hibernate/HibernateAbstractableTransactionsCodeGen.h"
#include "../../codegen/java/hibernate/HibernateConfigCodeGen.h"
#include "../../codegen/java/hibernate/HibernateTransactionsCodeGen.h"
#include "../../codegen/java/hibernate/HibernateEntitiyCodeGen.h"
#include "../../codegen/java/spring-boot/SpringBootApplicationCodeGen.h"
#include "../../codegen/java/spring-boot/SpringBootHttpErrorCodeGen.h"
#include "../../codegen/java/spring-boot/SpringBootControllerCodeGen.h"
#include "../../codegen/java/spring-boot/SpringBootHttpCodeGen.h"
#include "../../codegen/java/spring-boot/SpringBootRepoCodeGen.h"
#include "../../codegen/java/spring-boot/SpringBootServiceDbCodeGen.h"
#include "../../codegen/java/spring-boot/SpringBootServiceBzLogicCodeGen.h"

namespace dbcrudgen {
    namespace orm {

        class SpringBootProjectCreator : public JavaProjectCreator {

        private:
            SpringBootProjectModel projectModel;
            dbcrudgen::db::generic::Database database;

        public:

            SpringBootProjectCreator(SpringBootProjectModel &projectModel, dbcrudgen::db::generic::Database &database)
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
                FilesWriter::createDirs(projectModel.getAbsoluteWebErrorDirPath());
                FilesWriter::createDirs(projectModel.getControllersAbsolutePath());
                FilesWriter::createDirs(projectModel.getBeansAbsolutePath());
                FilesWriter::createDirs(projectModel.getBzLogicAbsolutePath());
                FilesWriter::createDirs(projectModel.getDatabaseConnectionAbsolutePath());
                FilesWriter::createDirs(projectModel.getEntitiesAbsolutePath());
                FilesWriter::createDirs(projectModel.getHttpRequestsDirPath());
                FilesWriter::createDirs(projectModel.getHttpResponsesDirPath());
                FilesWriter::createDirs(projectModel.getModelsDirPath());
                FilesWriter::createDirs(projectModel.getRepositoriesDirPath());
                FilesWriter::createDirs(projectModel.getTransactionsAbsolutePath());
                FilesWriter::createDirs(projectModel.getWebApplicationAbsolutePath());
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

                std::string error400 = SpringBootHttpErrorCodeGen::createErrorPage(projectModel, "400");
                std::string error404 = SpringBootHttpErrorCodeGen::createErrorPage(projectModel, "404");
                std::string error500 = SpringBootHttpErrorCodeGen::createErrorPage(projectModel, "500");

                std::string applicationClass = SpringBootApplicationCodeGen::createApplicationClass(projectModel);
                std::string appPropertiesSource = SpringBootApplicationCodeGen::createApplicationPropertiesSource(
                        projectModel, database);

                std::vector<dbcrudgen::db::generic::Table> tables = database.getTables();

                createHibernateConnectionClass();
                createAbstractableTransactionsExecutorClassFile();

                std::string entityMappings;


                for (const dbcrudgen::db::generic::Table &table : tables) {

                    const std::string &tableName = table.getTableName();
                    dbcrudgen::db::generic::Column *pkColumn = nullptr;

                    std::string tmpClassName = JavaParser::toJavaClassName(tableName);
                    std::string tablePkgName = StringUtils::to_lower(tmpClassName);

                    FilesWriter::createDirs(projectModel.getHttpRequestsDirPath() + "/" + tablePkgName);
                    FilesWriter::createDirs(projectModel.getHttpResponsesDirPath() + "/" + tablePkgName);

                    std::string beansSuffix = projectModel.getBeansClassSuffix();
                    std::string bzLogicSuffix = projectModel.getBzLogicClassSuffix();
                    std::string ctlSuffix = projectModel.getCtlClassSuffix();
                    std::string entitySuffix = projectModel.getEntityClassSuffix();
                    std::string httpReqSuffix = projectModel.getHttpReqClassSuffix();
                    std::string httpResSuffix = projectModel.getHttpResClassSuffix();
                    std::string modelSuffix = projectModel.getModelClassSuffix();
                    std::string reposSuffix = projectModel.getRepoClassSuffix();
                    std::string trxSuffix = projectModel.getTrxClassSuffix();


                    std::string beansClass = tmpClassName;
                    std::string bzLogicClass = tmpClassName;
                    std::string ctlClass = tmpClassName;
                    std::string entityClass = tmpClassName;
                    std::string httpReqClass = tmpClassName;
                    std::string httpResClass = tmpClassName;
                    std::string repoClass = tmpClassName;
                    std::string trxClass = tmpClassName;
                    std::string modelClass = tmpClassName;

                    std::string httpReqPostClass = tmpClassName + "PostRequest";
                    std::string httpReqPutClass = tmpClassName + "PutRequest";
                    std::string httpResGetClass = tmpClassName + "GetResponse";
                    std::string httpResDelClass = tmpClassName + "DelResponse";
                    std::string httpResPostClass = tmpClassName + "PostResponse";
                    std::string httpResPutClass = tmpClassName + "PutResponse";

                    beansClass.append(beansSuffix);
                    bzLogicClass.append(bzLogicSuffix);
                    ctlClass.append(ctlSuffix);
                    entityClass.append(entitySuffix);
                    httpReqClass.append(httpReqSuffix);
                    httpResClass.append(httpResSuffix);
                    modelClass.append(modelSuffix);
                    repoClass.append(reposSuffix);
                    trxClass.append(trxSuffix);

                    std::string beansSource = JaxbCodeGen::createBeansSource(projectModel, beansClass);
                    std::string bzLogicSource =
                            SpringBootServiceBzLogicCodeGen::createBzLogicSource(projectModel, table, bzLogicClass,
                                                                                 trxClass, modelClass, entityClass, httpReqPostClass,
                                                                                 httpReqPutClass);
                    std::string ctlSource =
                            SpringBootControllerCodeGen::createControllerSource(projectModel, table, ctlClass,
                                                                                entityClass, bzLogicClass, modelClass);
                    std::string entitySource =
                            HibernateEntityCodeGen::createHibernateEntitySource(projectModel, tableName, entityClass);

                    std::string httpPostReqSrc = SpringBootHttpCodeGen::createReqPostSrc(projectModel, tablePkgName,
                                                                                         httpReqPostClass,
                                                                                         modelClass);
                    std::string httpPutReqSrc = SpringBootHttpCodeGen::createReqPutSrc(projectModel, tablePkgName,
                                                                                       httpReqPutClass,
                                                                                       modelClass);
                    std::string httpGetResSrc = SpringBootHttpCodeGen::createResGetSrc(projectModel, table,
                                                                                       httpResGetClass,
                                                                                       modelClass);
                    std::string httpResDelSrc = SpringBootHttpCodeGen::createResDelSrc(projectModel, table,
                                                                                       httpResDelClass,
                                                                                       modelClass);
                    std::string httpPostResSrc = SpringBootHttpCodeGen::createResPostSrc(projectModel, table,
                                                                                         httpResPostClass,
                                                                                         modelClass);
                    std::string httpResPutSrc = SpringBootHttpCodeGen::createResPutSrc(projectModel, table,
                                                                                       httpResPutClass,
                                                                                       modelClass);
                    std::string modelSource =
                            SpringBootHttpCodeGen::createModelSource(projectModel, modelClass);

                    std::string repoSource = SpringBootRepoCodeGen::createRepositorySource(projectModel,
                                                                                           repoClass, entityClass);
                    std::string trxSrc =
                            SpringBootServiceDbCodeGen::createTrxSource(projectModel, table,
                                                                        entityClass, trxClass, modelClass,
                                                                        repoClass, httpReqPostClass,
                                                                        httpReqPutClass);

                    std::string mappingSource = HibernateConfigCodeGen::createEntityTableMappingSource();


                    entityMappings += HibernateParser::parseEntityClassMapping(mappingSource,
                                                                               projectModel.getPackageName(),
                                                                               projectModel.getEntitiesPkg(),
                                                                               entityClass);

                    std::string entityInstanceVars;
                    std::string entityGetterSetters;

                    std::string beansInstanceVars;
                    std::string beansGetterSetters;
                    std::string beanCtorVariables;
                    std::string beanInstanceVariablesInit;
                    std::string beanDefaultCtorVariablesInit;

                    std::string httpReqInstanceVars;
                    std::string httpParamsGetters;

                    std::string modelGetterSetters;
                    std::string modelInstanceVars;

                    std::string entityDataFromPostRequest;
                    std::string entityDataFromPutRequest;
                    std::string modelDataFromEntity;

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

                        if (!column.isNullable()) {
                            httpReqInstanceVars += SpringBootRepoCodeGen::createColumnInstanceVariable(column);
                            httpParamsGetters += SpringBootRepoCodeGen::createHttpParamsGetter(column);

                            modelInstanceVars += SpringBootRepoCodeGen::createColumnInstanceVariable(column);
                            modelGetterSetters += SpringBootRepoCodeGen::createModelGetterSetters(column);

                            entityDataFromPostRequest += SpringBootRepoCodeGen::createEntityDataFromRequest(
                                    entityClass, httpReqPostClass, column);

                            entityDataFromPutRequest += SpringBootRepoCodeGen::createEntityDataFromRequest(
                                    entityClass, httpReqPutClass, column);

                            modelDataFromEntity += SpringBootRepoCodeGen::createModelDataFromEntity(entityClass,
                                                                                                    modelClass,
                                                                                                    column);
                        }

                        if (column.isPrimary()) {
                            pkColumn = const_cast<dbcrudgen::db::generic::Column *>(&column);
                        }
                        index++;
                    }

                    HibernateEntitiesParser::parseColumnInstanceVariables(entitySource, entityInstanceVars);
                    HibernateEntitiesParser::parseColumnGetterSetters(entitySource, entityGetterSetters);

                    JaxbCodeGen::addInstanceVariables(beansSource, beansInstanceVars);
                    JaxbCodeGen::addGetterSetters(beansSource, beansGetterSetters);
                    JaxbCodeGen::addConstructorVariables(beansSource, beanCtorVariables);
                    JaxbCodeGen::addConstructorVariablesInitialization(beansSource, beanInstanceVariablesInit);
                    JaxbCodeGen::addDefaultInstanceVariablesInitialization(beansSource, beanDefaultCtorVariablesInit);

                    SpringBootHttpCodeGen::addHttpReqInstanceVariables(httpPostReqSrc, modelInstanceVars);
                    SpringBootHttpCodeGen::addHttpRequestParamsGetters(httpPostReqSrc, httpParamsGetters);
                    SpringBootHttpCodeGen::addHttpReqInstanceVariables(httpPutReqSrc, modelInstanceVars);
                    SpringBootHttpCodeGen::addHttpRequestParamsGetters(httpPutReqSrc, httpParamsGetters);

                    SpringBootHttpCodeGen::addModelInstanceVariables(modelSource, modelInstanceVars);
                    SpringBootHttpCodeGen::addModelGetterSetters(modelSource, modelGetterSetters);

                    SpringBootHttpCodeGen::addTrxServicePostRequestEntityData(trxSrc, entityDataFromPostRequest);
                    SpringBootHttpCodeGen::addTrxServicePutRequestEntityData(trxSrc, entityDataFromPutRequest);
                    SpringBootHttpCodeGen::addTrxServiceModelData(trxSrc, modelDataFromEntity);
                    SpringBootHttpCodeGen::addBzLogicServiceModelData(bzLogicSource, modelDataFromEntity);

                    SpringBootHttpCodeGen::addRepositoryPrimaryKey(repoSource, pkColumn);

                    std::string beanFile =
                            projectModel.getBeansAbsolutePath() + "/" + beansClass + ".java";
                    std::string bzLogicFile =
                            projectModel.getBzLogicAbsolutePath() + "/" + bzLogicClass + ".java";
                    std::string ctlFile =
                            projectModel.getControllersAbsolutePath() + "/" + ctlClass + ".java";
                    std::string entityFile =
                            projectModel.getEntitiesAbsolutePath() + "/" + entityClass + ".java";
                    std::string httpReqFile =
                            projectModel.getHttpRequestsDirPath() + "/" + httpReqClass + ".java";
                    std::string httpResFile =
                            projectModel.getHttpResponsesDirPath() + "/" + httpResClass + ".java";
                    std::string httpReqPostFile =
                            projectModel.createHttpRqRsFile(projectModel.getHttpRequestsDirPath(),
                                                            tablePkgName, httpReqPostClass);
                    std::string httpReqPutFile =
                            projectModel.createHttpRqRsFile(projectModel.getHttpRequestsDirPath(), tablePkgName,
                                                            httpReqPutClass);
                    std::string httpResGetFile =
                            projectModel.createHttpRqRsFile(projectModel.getHttpResponsesDirPath(), tablePkgName,
                                                            httpResGetClass);
                    std::string httpResPostFile =
                            projectModel.createHttpRqRsFile(projectModel.getHttpResponsesDirPath(), tablePkgName,
                                                            httpResPostClass);
                    std::string httpResPutFile =
                            projectModel.createHttpRqRsFile(projectModel.getHttpResponsesDirPath(), tablePkgName,
                                                            httpResPutClass);
                    std::string httpResDelFile =
                            projectModel.createHttpRqRsFile(projectModel.getHttpResponsesDirPath(), tablePkgName,
                                                            httpResDelClass);
                    std::string modelFile =
                            projectModel.getModelsDirPath() + "/" + modelClass + ".java";

                    std::string repoFile =
                            projectModel.getRepositoriesDirPath() + "/" + repoClass + ".java";
                    std::string trxFile =
                            projectModel.getTransactionsAbsolutePath() + "/" + trxClass + ".java";

                    FilesWriter::writeFile(beanFile, beansSource);
                    FilesWriter::writeFile(bzLogicFile, bzLogicSource);
                    FilesWriter::writeFile(ctlFile, ctlSource);
                    FilesWriter::writeFile(entityFile, entitySource);
                    FilesWriter::writeFile(trxFile, trxSrc);

                    FilesWriter::writeFile(httpReqPostFile, httpPostReqSrc);
                    FilesWriter::writeFile(httpReqPutFile, httpPutReqSrc);
                    FilesWriter::writeFile(httpResGetFile, httpGetResSrc);
                    FilesWriter::writeFile(httpResPostFile, httpPostResSrc);
                    FilesWriter::writeFile(httpResPutFile, httpResPutSrc);
                    FilesWriter::writeFile(httpResDelFile, httpResDelSrc);


                    FilesWriter::writeFile(modelFile, modelSource);
                    FilesWriter::writeFile(repoFile, repoSource);
                }

                createHtmlErrorPages(error400, error404, error500);
                createApplicationClassFile(applicationClass);
                createHibernateConnectionScript(entityMappings);
                createApplicationPropertiesScript(appPropertiesSource);

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
             * Writes the abstractable transactions executor class file
             * @param absTrxSource
             */
            void createAbstractableTransactionsExecutorClassFile() {
                std::string absTrxSource = HibernateAbstractableTransactionsCodeGen::getAbstractableTransactionsSource(
                        projectModel);
                std::string filename = projectModel.getAbstractableTransactionsExecutorFileAbsolutePath();
                FilesWriter::writeFile(filename, absTrxSource);
            }

            /**
             * Create the hibernate connection script
             * @param entityMappings
             */
            void createHibernateConnectionScript(std::string &entityMappings) {

                std::string configSource =
                        HibernateConfigCodeGen::createHibernateConfigSource(projectModel, database, entityMappings);

                std::string javaPath = projectModel.getAbsoluteJavaPath();
                std::string resourcesPath = projectModel.getAbsoluteResourcesPath();

                std::string javaHibernateConfigFile = javaPath + "/hibernate.cfg.xml";
                std::string resourcesHibernateConfigFile = resourcesPath + "/hibernate.cfg.xml";

                HibernateConfigurationParser::parseConfigurationClass(projectModel, configSource);

                FilesWriter::writeFile(javaHibernateConfigFile, configSource);
                FilesWriter::writeFile(resourcesHibernateConfigFile, configSource);
            }

            /**
             * Writes the Web XML Source on disk
             * @param error400Html
             */
            void createHtmlErrorPages(const std::string &error400Html, const std::string &error404Html,
                                      const std::string &error500Html) {
                FilesWriter::writeFile(projectModel.getAbsoluteWebError400FilePath(), error400Html);
                FilesWriter::writeFile(projectModel.getAbsoluteWebError404FilePath(), error404Html);
                FilesWriter::writeFile(projectModel.getAbsoluteWebError500FilePath(), error500Html);
            }

            /**
            * Writes the Web XML Source on disk
            * @param applicationPropertiesSource
            */
            void createApplicationPropertiesScript(const std::string &applicationPropertiesSource) {
                const std::string &filename = projectModel.getApplicationPropertiesFilePath(
                        projectModel.getSBApplicationPropertiesFileName());
                FilesWriter::writeFile(filename, applicationPropertiesSource);
            }

            /**
            * Writes the Web XML Source on disk
            * @param appClassSource
            */
            void createApplicationClassFile(const std::string &appClassSource) {
                std::string filename = projectModel.getWebApplicationFileAbsolutePath();
                FilesWriter::writeFile(filename, appClassSource);
            }
        };
    }
}

#endif //DBCRUDGEN_CPP_SPRINGBOOTPROJECTCREATOR_H
