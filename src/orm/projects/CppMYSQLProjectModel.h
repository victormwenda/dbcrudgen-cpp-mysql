//
// Created by vrwanda on 3/5/20.
//

/**
 * CPP MSYQL Project Model
 */


#ifndef DBCRUDGEN_CPP_CPPMYSQLPROJECTMODEL_H
#define DBCRUDGEN_CPP_CPPMYSQLPROJECTMODEL_H

#include <string>
#include "ProjectModel.h"
#include "../codegen/Languages.h"

namespace dbcrudgen {

    namespace orm {

        class CppMYSQLProjectModel : public ProjectModel {

        private:

            std::string projectName;
            std::string workspaceDir;
            std::string includesDir;
            std::string libsDir;
            std::string generatedCodeDir;

        public:
            CppMYSQLProjectModel(std::string &projectName, std::string &workspaceDir, std::string &includesDir,
                                 std::string &libsDir, std::string &generatedCodeDir)
                    : projectName(projectName), workspaceDir(workspaceDir), includesDir(includesDir), libsDir(libsDir),
                      generatedCodeDir(generatedCodeDir) {}

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
                return std::string{Languages::CPP};
            }

            const std::string &getIncludesDir() const {
                return includesDir;
            }

            const std::string &getLibsDir() const {
                return libsDir;
            }
        };
    }
}


#endif //DBCRUDGEN_CPP_CPPMYSQLPROJECTMODEL_H