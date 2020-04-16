//
// Created by victor on 3/19/20.
//

#ifndef DBCRUDGEN_CPP_PHPMYSQLPROJECTCREATOR_H
#define DBCRUDGEN_CPP_PHPMYSQLPROJECTCREATOR_H

#include "../ProjectCreator.h"
#include "../../codegen/Languages.h"
#include "../../codegen/Databases.h"
#include "../../../io/FilesWriter.h"
#include "../../projects/PHPMYSQLProjectModel.h"
#include "../../../databases/mysql/models/MYSQLDatabaseModel.h"

namespace dbcrudgen {
    namespace orm {
        class PHPMYSQLProjectCreator : public ProjectCreator {

        private:
            PHPMYSQLProjectModel projectModel;
            db::mysql::MYSQLDatabaseModel databaseModel;

        public:

            explicit PHPMYSQLProjectCreator(PHPMYSQLProjectModel &projectModel,
                                            db::mysql::MYSQLDatabaseModel &databaseModel)
                    : projectModel{projectModel}, databaseModel{databaseModel} {

            }

            /**
             * Return database model
             * @return
             */
            const db::mysql::MYSQLDatabaseModel &getDatabaseModel() {
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

                FilesWriter::createDirs(projectModel.getWorkspaceDir());
                FilesWriter::createDirs(projectModel.getProjectDir());
            }

            void createProjectDirs() override {

            }

            void createSourceFiles() override {

            }
        };
    }
}
#endif //DBCRUDGEN_CPP_PHPMYSQLPROJECTCREATOR_H
