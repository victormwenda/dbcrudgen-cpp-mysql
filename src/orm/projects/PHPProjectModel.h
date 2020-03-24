//
// Created by vrwanda on 3/5/20.
//

/**
 * PHP Project Model
 */

#ifndef DBCRUDGEN_CPP_PHPPROJECTMODEL_H
#define DBCRUDGEN_CPP_PHPPROJECTMODEL_H


#include "ProjectModel.h"
#include "../codegen/Languages.h"

namespace dbcrudgen {
    namespace orm {
        class PHPProjectModel : public ProjectModel {

        private:
            std::string projectName;
            std::string workspaceDir;
            std::string generatedCodeDir;
            std::string assetsDir;
            std::string jsDir;
            std::string cssDir;

        public:

            /**
             * PHP MYSQL Project Model
             *
             * @param projectName
             * @param workspaceDir
             * @param generatedCodeDir
             */
            PHPProjectModel(std::string &projectName, std::string &workspaceDir, std::string assetsDir,
                            std::string jsDir, std::string cssDir)
                    : projectName{projectName}, workspaceDir{workspaceDir}, assetsDir{assetsDir}, jsDir{jsDir},
                      cssDir{cssDir} {
                generatedCodeDir = getProjectDir();
            }

            const std::string &getProjectName() override {
                return projectName;
            }

            const std::string &getWorkspaceDir() override {
                return workspaceDir;
            }

            const std::string &getAssetsDir() const {
                return assetsDir;
            }

            const std::string &getJsDir() const {
                return jsDir;
            }

            const std::string &getCssDir() const {
                return cssDir;
            }

            const std::string &getGeneratedCodeDir() override {
                return generatedCodeDir;
            }

            std::string getSourceLang() override {
                return std::string{Languages::PHP};
            }

            /**
             * Get assets full dir
             * @return
             */
            const std::string getAssetsFullDir() { return getProjectDir() + "/" + getAssetsDir(); }

            /**
             * Get the Assets full dir
             * @return
             */
            const std::string getJSFullDir() { return getAssetsFullDir() + "/" + getJsDir(); }

            /**
             * Get the CSS Full dir
             * @return
             */
            const std::string getCSSFullDir() { return getAssetsFullDir() + "/" + getCssDir(); }

            /**
            * Get PHP Framework used to develop the project
            * @return
            */
            virtual std::string getFramework() { return std::string{}; };
        };

    }
}


#endif //DBCRUDGEN_CPP_PHPPROJECTMODEL_H