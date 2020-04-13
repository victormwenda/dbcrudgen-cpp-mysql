//
// Created by victor on 4/13/20.
//

#ifndef DBCRUDGEN_CPP_JAXWSPROJECTMODEL_H
#define DBCRUDGEN_CPP_JAXWSPROJECTMODEL_H

#include "JavaProjectModel.h"
#include "../utils/StringUtils.h"

namespace dbcrudgen {
    namespace orm {
        class JaxWsProjectModel : public JavaProjectModel {

            std::string apisPkg;
            std::string entitiesPkg;
            std::string webDir;

        public:

            /**
             * JAX Ws project Model
             * @param projectName
             * @param workspaceDir
             * @param srcDir
             * @param moduleDir
             * @param javaDir
             * @param libsDir
             * @param resourcesDir
             * @param packageName
             * @param apisPkg
             * @param entitiesPkg
             * @param webDir
             */
            JaxWsProjectModel(std::string &projectName, std::string &workspaceDir, std::string &srcDir,
                              std::string &moduleDir, std::string &javaDir, std::string &libsDir,
                              std::string &resourcesDir, std::string &packageName,
                              std::string &apisPkg, std::string &entitiesPkg, std::string &webDir)
                    : JavaProjectModel{projectName, workspaceDir, srcDir, moduleDir, javaDir,
                                       libsDir, resourcesDir, packageName},
                      apisPkg{apisPkg}, entitiesPkg{entitiesPkg}, webDir{webDir} {}

            const std::string &getApisPkg() const {
                return apisPkg;
            }

            const std::string &getEntitiesPkg() const {
                return entitiesPkg;
            }

            const std::string &getWebDir() const {
                return webDir;
            }

            /**
            * Get the absolute path to the project webdir files
            * @return
            */
            std::string getAbsoluteWebDirPath() {
                return getAbsoluteModulePath() + "/" + getWebDir();
            }

            /**
            * Get absolute path to apis dir
            * @return
            */
            std::string getApisAbsolutePath() {
                std::string pkgName = getApisPkg();
                std::string apisPackage = StringUtils::replace(pkgName, ".", "/");
                return getAbsoluteJavaPath() + "/" + apisPackage;
            }

            /**
             * Get absolute path to entities dir
             * @return
             */
            std::string getEntitiesAbsolutePath() {
                std::string pkgName = getEntitiesPkg();
                std::string entitiesPackage = StringUtils::replace(pkgName, ".", "/");
                return getAbsoluteJavaPath() + "/" + entitiesPackage;
            }


        };

    }
}
#endif //DBCRUDGEN_CPP_JAXWSPROJECTMODEL_H
