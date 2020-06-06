//
// Created by victor on 6/1/20.
//

#ifndef DBCRUDGEN_CPP_ANGULARPROJECTMODEL_H
#define DBCRUDGEN_CPP_ANGULARPROJECTMODEL_H

#include "ProjectModel.h"
#include "../codegen/Languages.h"

namespace dbcrudgen {
    namespace orm {
        class AngularProjectModel : public ProjectModel {

        private:
            std::string workspaceDir;
            std::string projectName;
            std::string distDir;
            std::string e2eDir;
            std::string nodeModulesDir;
            std::string srdDir;
            std::string appDir;
            std::string assetsDir;
            std::string environmentsDir;
            std::string moduleDir;
            std::string modelsDir;
            std::string baseUrl;

        public:
            //
            // Angular Project Model
            //
            AngularProjectModel(std::string &workspaceDir, std::string &projectName, std::string &distDir,
                                std::string &e2EDir, std::string &nodeModulesDir, std::string &srdDir,
                                std::string &appDir, std::string &assetsDir, std::string &environmentsDir,
                                std::string &moduleDir, std::string &modelsDir, std::string &baseUrl)
                    : workspaceDir(workspaceDir), projectName(projectName),
                      distDir(distDir), e2eDir(e2EDir),
                      nodeModulesDir(nodeModulesDir),
                      srdDir(srdDir),
                      appDir(appDir),
                      assetsDir(assetsDir),
                      environmentsDir(environmentsDir),
                      moduleDir(moduleDir), modelsDir(modelsDir),
                      baseUrl(baseUrl) {}

            const std::string &getProjectName() override {
                return projectName;
            }

            const std::string &getWorkspaceDir() override {
                return workspaceDir;
            }

            const std::string &getGeneratedCodeDir() override {
                return getSrdDir();
            }

            std::string getSourceLang() override {
                return std::string{orm::Languages::Angular};
            }

            const std::string &getDistDir() const {
                return distDir;
            }

            const std::string &getE2EDir() const {
                return e2eDir;
            }

            const std::string &getNodeModulesDir() const {
                return nodeModulesDir;
            }

            const std::string &getSrdDir() const {
                return srdDir;
            }

            const std::string &getAppDir() const {
                return appDir;
            }

            const std::string &getAssetsDir() const {
                return assetsDir;
            }

            const std::string &getEnvironmentsDir() const {
                return environmentsDir;
            }

            const std::string &getModuleDir() const {
                return moduleDir;
            }

            const std::string &getModelsDir() const {
                return modelsDir;
            }

            const std::string &getBaseUrl() const {
                return baseUrl;
            }

            //Gets evaluated module name. if the name of the module was empty, the app name will be used
            std::string getEvalModuleName() {

                if (getModuleDir().empty()) {
                    return getAppDir();
                }

                return getModuleDir();
            }

            //Get project dir full path
            std::string getProjectDirFullPath() {
                return getWorkspaceDir() + "/" + getProjectName();
            }

            //Get dist dir full path
            std::string getDistDirFullPath() {
                return getProjectDirFullPath() + "/" + getDistDir();
            }

            //Get End to End Test Cases Directory path
            std::string getE2EDirFullPath() {
                return getProjectDirFullPath() + "/" + getE2EDir();
            }

            //Get Node modules directory path
            std::string getNodeModulesDirFullPath() {
                return getProjectDirFullPath() + "/" + getNodeModulesDir();
            }

            //Get source code directory path
            std::string getSrcDirFullPath() {
                return getProjectDirFullPath() + "/" + getSrdDir();
            }

            //Get app dir
            std::string getAppDirFullPath() {
                return getSrcDirFullPath() + "/" + getAppDir();
            }

            //Get assets directory
            std::string getAssetsDirFullPath() {
                return getSrcDirFullPath() + "/" + getAssetsDir();
            }

            //Get Environment directory
            std::string getEnvironmentDirFullPath() {
                return getSrcDirFullPath() + "/" + getEnvironmentsDir();
            }

            //Get the directory of the module being created.
            //if the directory is empty, the app directory will be used
            std::string getModuleDirFullPath() {
                if (moduleDir.empty()) {
                    return getAppDirFullPath();
                }

                return getAppDirFullPath() + "/" + getModuleDir();
            }

            //Get the directory of the module models being created.
            std::string getModelsDirFullPath() {
                return getModuleDirFullPath() + "/" + getModelsDir();
            }


        };
    }
}
#endif //DBCRUDGEN_CPP_ANGULARPROJECTMODEL_H
