//
// Created by victor on 3/23/20.
//

#ifndef DBCRUDGEN_CPP_PHPPROJECTCREATOR_H
#define DBCRUDGEN_CPP_PHPPROJECTCREATOR_H

#include "../ProjectCreator.h"
#include "../../codegen/Languages.h"
#include "../../codegen/Databases.h"
#include "../../../io/FilesWriter.h"
#include "../../projects/PHPMYSQLProjectModel.h"
#include "../../../databases/generic/Database.h"
#include "../../projects/PHPOracleProjectModel.h"

namespace dbcrudgen {
    namespace orm {
        class PHPProjectCreator : public ProjectCreator {

        private:
            PHPProjectModel projectModel;
            dbcrudgen::db::generic::Database databaseModel;

        public:

            explicit PHPProjectCreator(PHPProjectModel &projectModel, dbcrudgen::db::generic::Database &databaseModel)
                    : projectModel{projectModel}, databaseModel{databaseModel} {}

            /**
             * Return database model
             * @return
             */
            const dbcrudgen::db::generic::Database &getDatabaseModel() {
                return databaseModel;
            }

            std::string getLanguage() override {
                return std::string{Languages::PHP};
            }

            std::string getDatabase() override {
                return std::string{Databases::MYSQL};
            }

            void createProject() override {
                createProjectDirs();


            }

            void createProjectDirs() override {
                FilesWriter::createDirs(projectModel.getWorkspaceDir());
                FilesWriter::createDirs(projectModel.getProjectDir());
                FilesWriter::createDirs(projectModel.getAssetsFullDir());
                FilesWriter::createDirs(projectModel.getCSSFullDir());
                FilesWriter::createDirs(projectModel.getJSFullDir());
            }

            void createSourceFiles() override {

            }
        };
    }
}
#endif //DBCRUDGEN_CPP_PHPPROJECTCREATOR_H
