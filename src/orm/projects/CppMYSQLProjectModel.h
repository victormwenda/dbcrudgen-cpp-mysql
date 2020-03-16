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
#include "CppProjectModel.h"

namespace dbcrudgen {

    namespace orm {

        class CppMYSQLProjectModel : public CppProjectModel {

        private:

            std::string projectName;
            std::string workspaceDir;
            std::string includesDir;
            std::string libsDir;
            std::string generatedCodeDir;

        public:
            CppMYSQLProjectModel(std::string &projectName, std::string &workspaceDir, std::string &includesDir,
                                 std::string &libsDir, std::string &generatedCodeDir)
                    : CppProjectModel{projectName, workspaceDir, includesDir, libsDir, generatedCodeDir},
                      projectName(projectName), workspaceDir(workspaceDir), includesDir(includesDir), libsDir(libsDir),
                      generatedCodeDir(generatedCodeDir) {}

        };
    }
}


#endif //DBCRUDGEN_CPP_CPPMYSQLPROJECTMODEL_H