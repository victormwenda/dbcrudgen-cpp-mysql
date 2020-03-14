//
// Created by vrwanda on 3/5/20.
//

/**
 * CPP Oracle Project Model
 */


#ifndef DBCRUDGEN_CPP_CPPORACLEPROJECTMODEL_H
#define DBCRUDGEN_CPP_CPPORACLEPROJECTMODEL_H

#include <string>
#include "CppProjectModel.h"

namespace dbcrudgen {
    namespace orm {

        class CppOracleProjectModel : public CppProjectModel {

        private:

            std::string projectName;
            std::string workspaceDir;
            std::string includesDir;
            std::string libsDir;
            std::string generatedCodeDir;

        public:
            CppOracleProjectModel(std::string &projectName, std::string &workspaceDir, std::string &includesDir,
                                  std::string &libsDir, std::string &generatedCodeDir)
                    : CppProjectModel{projectName, workspaceDir, includesDir, libsDir, generatedCodeDir},
                      projectName(projectName), workspaceDir(workspaceDir), includesDir(includesDir), libsDir(libsDir),
                      generatedCodeDir(generatedCodeDir) {}


        };
    }
}


#endif //DBCRUDGEN_CPP_CPPORACLEPROJECTMODEL_H