//
// Created by vrwanda on 3/5/20.
//

/**
 * PHP MYSQL Project Model
 */


#ifndef DBCRUDGEN_CPP_PHPMYSQLPROJECTMODEL_H
#define DBCRUDGEN_CPP_PHPMYSQLPROJECTMODEL_H

#include "ProjectModel.h"
#include "../codegen/Languages.h"
#include "PHPProjectModel.h"

namespace dbcrudgen {
    namespace orm {
        class PHPMYSQLProjectModel : public PHPProjectModel {

        private:
            std::string projectName;
            std::string workspaceDir;
            std::string generatedCodeDir;

        public:

            /**
             * PHP MYSQL Project Model
             *
             * @param projectName
             * @param workspaceDir
             * @param generatedCodeDir
             */
            [[deprecated]] PHPMYSQLProjectModel(std::string &projectName, std::string &workspaceDir)
                    : PHPProjectModel(projectName, workspaceDir), projectName(projectName),
                      workspaceDir(workspaceDir) {
                generatedCodeDir = getProjectDir();
            }

            const std::string &getProjectName() override {
                return projectName;
            }

            const std::string &getWorkspaceDir() override {
                return workspaceDir;
            }

            const std::string &getGeneratedCodeDir() override {
                return generatedCodeDir;
            }

            std::string getSourceLang() override {
                return std::string{Languages::PHP};
            }

            /**
            * Get PHP Framework used to develop the project
            * @return
            */
            virtual std::string getFramework() { return std::string{}; };
        };

    }
}


#endif //DBCRUDGEN_CPP_PHPMYSQLPROJECTMODEL_H