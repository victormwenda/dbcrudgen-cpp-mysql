//
// Created by victor on 4/13/20.
//

#ifndef DBCRUDGEN_CPP_JAXWSPROJECTCREATOR_H
#define DBCRUDGEN_CPP_JAXWSPROJECTCREATOR_H


#include "JavaProjectCreator.h"
#include "../../projects/JaxWsProjectModel.h"
#include "../../../databases/generic/Database.h"
#include "../../parsers/java/JavaParser.h"

namespace dbcrudgen {
    namespace orm {

        class JaxWsProjectCreator : public JavaProjectCreator {

        private:
            JaxWsProjectModel projectModel;
            dbcrudgen::db::generic::Database database;
        public:

            /**
             * JAX-WS Project Creator
             * @param projectModel
             */
            explicit JaxWsProjectCreator(JaxWsProjectModel &projectModel, dbcrudgen::db::generic::Database &database)
                    : JavaProjectCreator{projectModel}, projectModel{projectModel}, database{database} {}

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
                FilesWriter::createDirs(projectModel.getDatabaseConnectionAbsolutePath());
                FilesWriter::createDirs(projectModel.getBeansAbsolutePath());
            }

            /**
             * Create project source files
             */
            void createSourceFiles() override {
                JavaProjectCreator::createSourceFiles();

                std::vector<dbcrudgen::db::generic::Table> tables = database.getTables();

                for (const dbcrudgen::db::generic::Table &table: tables) {

                    std::string tableName = table.getTableName();

                    std::string apiSuffix = projectModel.getApiClassSuffix();
                    std::string entitySuffix = projectModel.getEntityClassSuffix();
                    std::string trxSuffix = projectModel.getTrxClassSuffix();

                    std::string apiClass = JavaParser::toJavaClassName(tableName);
                    std::string entityClass = JavaParser::toJavaClassName(tableName);
                    std::string trxClass = JavaParser::toJavaClassName(tableName);

                    std::string apiFile =
                            projectModel.getApisAbsolutePath() + "/" + apiClass.append(apiSuffix) + ".java";

                    std::string entityFile =
                            projectModel.getEntitiesAbsolutePath() + "/" + entityClass.append(entitySuffix) + ".java";

                    std::string trxFile =
                            projectModel.getTransactionsAbsolutePath() + "/" + trxClass.append(trxSuffix) + ".java";

                    FilesWriter::writeFile(apiFile, "");
                    FilesWriter::writeFile(entityFile, "");
                    FilesWriter::writeFile(trxFile, "");
                }
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
#endif //DBCRUDGEN_CPP_JAXWSPROJECTCREATOR_H
