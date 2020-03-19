//
// Created by victor on 3/19/20.
//

#ifndef DBCRUDGEN_CPP_LARAVELPHPMYSQLPROJECTMODEL_H
#define DBCRUDGEN_CPP_LARAVELPHPMYSQLPROJECTMODEL_H

#include "PHPMYSQLProjectModel.h"
#include "../codegen/Frameworks.h"

namespace dbcrudgen {
    namespace orm {
        class LaravelPHPMYSQLProjectModel : public PHPMYSQLProjectModel {

        private:
            std::string controllersDir;
            std::string modelsDir;
            std::string viewsDir;
            std::string apiDir;
            std::string apiFile;

        public:

            /**
            * PHP MYSQL Project Model
            *
            * @param projectName
            * @param workspaceDir
            * @param generatedCodeDir
            */
            LaravelPHPMYSQLProjectModel(std::string &projectName, std::string &workspaceDir,
                                        std::string &controllersDir, std::string &modelsDir, std::string &viewsDir,
                                        std::string &apiDir, std::string &apiFile)
                    : PHPMYSQLProjectModel{projectName, workspaceDir},
                      controllersDir{controllersDir}, modelsDir{modelsDir}, viewsDir{viewsDir},
                      apiDir{apiDir}, apiFile{apiFile} {}

            std::string getFramework()   {
                return std::string{Frameworks::LARAVEL};
            }

            const std::string &getControllersDir() const {
                return controllersDir;
            }

            const std::string &getModelsDir() const {
                return modelsDir;
            }

            const std::string &getViewsDir() const {
                return viewsDir;
            }

            const std::string &getApiDir() const {
                return apiDir;
            }

            const std::string &getApiFile() const {
                return apiFile;
            }

            /**
             * Get the full path to Controllers directory
             * @return
             */
            std::string getControllersFullDir() {
                return getProjectDir() + "/" + getControllersDir();
            }

            /**
             * Get the full path to Models directory
             * @return
             */
            std::string getModelsFullDir() {
                return getProjectDir() + "/" + getModelsDir();
            }

            /**
            * Get the full path to Views directory
            * @return
            */
            std::string getViewsFullDir() {
                return getProjectDir() + "/" + getViewsDir();
            }

            /**
             * Get the full path to API's directory
             * @return
             */
            std::string getAPIsFullDir() {
                return getProjectDir() + "/" + getApiDir();
            }

        };
    }
}


#endif //DBCRUDGEN_CPP_LARAVELPHPMYSQLPROJECTMODEL_H
