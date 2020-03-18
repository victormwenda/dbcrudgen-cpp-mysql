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
            std::string generatedTableModelCodeDir;
            std::string generatedTableDbOpsCodeDir;

        public:
            CppMYSQLProjectModel(std::string &projectName, std::string &workspaceDir, std::string &includesDir,
                                 std::string &libsDir, std::string &generatedCodeDir,
                                 std::string &generatedTableModelCodeDir,
                                 std::string &generatedTableDbOpsCodeDir)
                    : CppProjectModel{projectName, workspaceDir, includesDir, libsDir, generatedCodeDir},
                      projectName(projectName), workspaceDir(workspaceDir), includesDir(includesDir), libsDir(libsDir),
                      generatedCodeDir(generatedCodeDir), generatedTableModelCodeDir(generatedTableModelCodeDir),
                      generatedTableDbOpsCodeDir(generatedTableDbOpsCodeDir) {}

            const std::string &getProjectName() const {
                return projectName;
            }

            void setProjectName(const std::string &projectName) {
                CppMYSQLProjectModel::projectName = projectName;
            }

            const std::string &getWorkspaceDir() const {
                return workspaceDir;
            }

            void setWorkspaceDir(const std::string &workspaceDir) {
                CppMYSQLProjectModel::workspaceDir = workspaceDir;
            }

            const std::string &getIncludesDir() const {
                return includesDir;
            }

            void setIncludesDir(const std::string &includesDir) {
                CppMYSQLProjectModel::includesDir = includesDir;
            }

            const std::string &getLibsDir() const {
                return libsDir;
            }

            void setLibsDir(const std::string &libsDir) {
                CppMYSQLProjectModel::libsDir = libsDir;
            }

            const std::string &getGeneratedCodeDir() const {
                return generatedCodeDir;
            }

            /**
             * Get the full path for the generated code
             * @return
             */
            std::string getGeneratedCodeFullDir() {
                return std::string{getProjectDir() + "/" + generatedCodeDir};
            }

            void setGeneratedCodeDir(const std::string &generatedCodeDir) {
                CppMYSQLProjectModel::generatedCodeDir = generatedCodeDir;
            }

            const std::string &getGeneratedTableModelCodeDir() const {
                return generatedTableModelCodeDir;
            }

            /**
             * Get the full dir for generating the table model files
             * @return
             */
            std::string getGeneratedTableModelCodeFullDir() {
                return std::string{getGeneratedCodeFullDir() + "/" + getGeneratedTableModelCodeDir()};
            }

            void setGeneratedTableModelCodeDir(const std::string &generatedTableModelCodeDir) {
                CppMYSQLProjectModel::generatedTableModelCodeDir = generatedTableModelCodeDir;
            }

            const std::string &getGeneratedTableDbOpsCodeDir() const {
                return generatedTableDbOpsCodeDir;
            }

            /**
             * Get the full dir for saving the table dao files
             * @return
             */
            std::string getGeneratedTableDbOpsFullCodeDir() {
                return std::string{getGeneratedCodeFullDir() + "/" + getGeneratedTableDbOpsCodeDir()};
            }

            void setGeneratedTableDbOpsCodeDir(const std::string &generatedTableDbOpsCodeDir) {
                CppMYSQLProjectModel::generatedTableDbOpsCodeDir = generatedTableDbOpsCodeDir;
            }

        };


    }
}


#endif //DBCRUDGEN_CPP_CPPMYSQLPROJECTMODEL_H