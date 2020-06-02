//
// Created by victor on 6/1/20.
//

#ifndef DBCRUDGEN_CPP_ANGULARPROJECTCREATOR_H
#define DBCRUDGEN_CPP_ANGULARPROJECTCREATOR_H

#include "../../projects/AngularProjectModel.h"
#include "../../../databases/generic/Database.h"
#include "../ProjectCreator.h"
#include "../../codegen/Databases.h"
#include "../../../io/FilesWriter.h"

namespace dbcrudgen {
    namespace orm {
        class AngularProjectCreator : public ProjectCreator {

        private:
            dbcrudgen::orm::AngularProjectModel projectModel;
            dbcrudgen::db::generic::Database databaseModel;

        public:
            AngularProjectCreator(dbcrudgen::orm::AngularProjectModel &projectModel,
                                  dbcrudgen::db::generic::Database &databaseModel)
                    : projectModel{projectModel},
                      databaseModel{databaseModel} {}

            const AngularProjectModel &getProjectModel() {
                return projectModel;
            }

            const db::generic::Database &getDatabaseModel() const {
                return databaseModel;
            }

        private:
            std::string getLanguage() override {
                return std::string{dbcrudgen::orm::Languages::Angular};
            }

            std::string getDatabase() override {
                return std::string{dbcrudgen::orm::Databases::GENERIC};
            }

            void createProjectDirs() override {

                //Create Project Dir
                const std::string projectDirFullPath = projectModel.getProjectDirFullPath();
                FilesWriter::createDirs(projectDirFullPath);

                //Create e2e Dir
                const std::string &e2EDirFullPath = projectModel.getE2EDirFullPath();
                FilesWriter::createDirs(e2EDirFullPath);

                //Create node module Dir
                const std::string &nodeModulesDirFullPath = projectModel.getNodeModulesDirFullPath();
                FilesWriter::createDirs(nodeModulesDirFullPath);

                //Create src dir
                const std::string &srcDirFullPath = projectModel.getSrcDirFullPath();
                FilesWriter::createDirs(srcDirFullPath);

                //Create app dir
                const std::string &appDirFullPath = projectModel.getAppDirFullPath();
                FilesWriter::createDirs(appDirFullPath);

                //Create assets dir
                const std::string &assetsDirFullPath = projectModel.getAssetsDirFullPath();
                FilesWriter::createDirs(assetsDirFullPath);

                //Create environments dir
                const std::string &environmentDirFullPath = projectModel.getEnvironmentDirFullPath();
                FilesWriter::createDirs(environmentDirFullPath);

                //Create module dir
                const std::string &moduleDirFullPath = projectModel.getModuleDirFullPath();
                FilesWriter::createDirs(moduleDirFullPath);

                const std::string& modelsDir = projectModel.getModelsDirFullPath();
                FilesWriter::createDirs(modelsDir, true);
            }

            void createSourceFiles() override {

            }
        };
    }
}
#endif //DBCRUDGEN_CPP_ANGULARPROJECTCREATOR_H
