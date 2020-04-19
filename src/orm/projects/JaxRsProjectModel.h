//
// Created by victor on 4/13/20.
//

#ifndef DBCRUDGEN_CPP_JAXRSPROJECTMODEL_H
#define DBCRUDGEN_CPP_JAXRSPROJECTMODEL_H

#include "JavaProjectModel.h"
#include "../utils/StringUtils.h"

namespace dbcrudgen {
    namespace orm {
        class JaxRsProjectModel : public JavaProjectModel {

            std::string webDir;

            std::string apisPkg;
            std::string dbConnPkg;
            std::string entitiesPkg;
            std::string transactionsPkg;
            std::string webAppPkg;
            std::string beansPkg;

            std::string apiClassSuffix;
            std::string entityClassSuffix;
            std::string trxClassSuffix;
            std::string beansClassSuffix;

            std::string webAppClassName;
            std::string dbConnClassName;

            std::string urlPattern;

        public:

            /**
             * JAX-RS Project Model
             * @param projectName
             * @param workspaceDir
             * @param srcDir
             * @param moduleDir
             * @param javaDir
             * @param libsDir
             * @param resourcesDir
             * @param packageName
             * @param webDir
             * @param apisPkg
             * @param dbConnPkg
             * @param entitiesPkg
             * @param transactionsPkg
             * @param webAppPkg
             * @param beansPkg
             * @param apiClassSuffix
             * @param entityClassSuffix
             * @param trxClassSuffix
             * @param beansClassSuffix
             * @param webAppClassName
             * @param dbConnClassName
             * @param urlPattern
             */
            JaxRsProjectModel(std::string &projectName, std::string &workspaceDir, std::string &srcDir,
                              std::string &moduleDir, std::string &javaDir, std::string &libsDir,
                              std::string &resourcesDir, std::string &packageName,

                              std::string &webDir,
                              std::string &apisPkg, std::string &dbConnPkg, std::string &entitiesPkg,
                              std::string &transactionsPkg, std::string &webAppPkg, std::string &beansPkg,

                              std::string &apiClassSuffix, std::string &entityClassSuffix, std::string &trxClassSuffix,
                              std::string &beansClassSuffix,

                              std::string &webAppClassName, std::string &dbConnClassName,

                              std::string &urlPattern)

                    : JavaProjectModel{projectName, workspaceDir, srcDir, moduleDir, javaDir,
                                       libsDir, resourcesDir, packageName},
                      webDir{webDir},

                      apisPkg{apisPkg}, dbConnPkg{dbConnPkg}, entitiesPkg{entitiesPkg},
                      transactionsPkg{transactionsPkg}, webAppPkg{webAppPkg}, beansPkg{beansPkg},

                      apiClassSuffix{apiClassSuffix}, entityClassSuffix{entityClassSuffix},
                      trxClassSuffix{trxClassSuffix}, beansClassSuffix{beansClassSuffix},

                      webAppClassName{webAppClassName}, dbConnClassName{dbConnClassName},
                      urlPattern{urlPattern} {}


            const std::string &getWebDir() const {
                return webDir;
            }

            const std::string &getApisPkg() const {
                return apisPkg;
            }

            const std::string &getDbConnPkg() const {
                return dbConnPkg;
            }

            const std::string &getEntitiesPkg() const {
                return entitiesPkg;
            }

            const std::string &getTransactionsPkg() const {
                return transactionsPkg;
            }

            const std::string &getWebAppPkg() const {
                return webAppPkg;
            }

            const std::string &getBeansPkg() const {
                return beansPkg;
            }

            const std::string &getApiClassSuffix() const {
                return apiClassSuffix;
            }

            const std::string &getEntityClassSuffix() const {
                return entityClassSuffix;
            }

            const std::string &getTrxClassSuffix() const {
                return trxClassSuffix;
            }

            const std::string &getBeansClassSuffix() const {
                return beansClassSuffix;
            }

            const std::string &getWebAppClassName() const {
                return webAppClassName;
            }

            const std::string &getDbConnClassName() const {
                return dbConnClassName;
            }

            const std::string &getUrlPattern() const {
                return urlPattern;
            }

            /**
            * Get the absolute path to the project webdir files
            * @return
            */
            const std::string getAbsoluteWebDirPath() {
                return getAbsoluteModulePath() + "/" + getWebDir();
            }

            /**
            * Get the absolute path to the project WEB-INF files
            * @return
            */
            const std::string getAbsoluteWebInfDirPath() {
                return getAbsoluteWebDirPath() + "/WEB-INF";
            }

            /**
             * Get the absolute path to the web.xml file
             * @param filename
             * @return
             */
            const std::string getAbsoluteWebXMLFilePathSrc(std::string filename = "web.xml") {
                return getAbsoluteWebInfDirPath() + "/" + filename;
            }

            /**
             * TODO :: this method is not supposed to be there
             * Get the absolute path to the web.xml file
             * @param filename
             * @return
             */
            const std::string getAbsoluteWebXMLFilePathRes(std::string filename = "web.xml") {
                return getAbsoluteResourcesPath() + "/" + filename;
            }

            /**
             * Get absolute path to apis dir
             * @return
             */
            const std::string getApisAbsolutePath() {
                std::string pkgName = getApisPkg();
                std::string apisPackage = StringUtils::replace(pkgName, ".", "/");
                return getAbsoluteBaseCodePath() + "/" + apisPackage;
            }

            /**
             * Get absolute path to database connection dir
             * @return
             */
            const std::string getDatabaseConnectionAbsolutePath() {
                std::string pkgName = getDbConnPkg();
                std::string dbConnPackage = StringUtils::replace(pkgName, ".", "/");
                return getAbsoluteBaseCodePath() + "/" + dbConnPackage;
            }

            /**
             * Get absolute path to entities dir
             * @return
             */
            const std::string getEntitiesAbsolutePath() {
                std::string pkgName = getEntitiesPkg();
                std::string entitiesPackage = StringUtils::replace(pkgName, ".", "/");
                return getAbsoluteBaseCodePath() + "/" + entitiesPackage;
            }

            /**
            * Get absolute path to transactions dir
            * @return
            */
            const std::string getTransactionsAbsolutePath() {
                std::string pkgName = getTransactionsPkg();
                std::string trxPackage = StringUtils::replace(pkgName, ".", "/");
                const std::string &baseCodePath = getAbsoluteBaseCodePath();
                return baseCodePath + "/" + trxPackage;
            }

            /**
            * Get absolute path to web application dir
            * @return
            */
            const std::string getWebApplicationAbsolutePath() {
                std::string pkgName = getWebAppPkg();
                std::string webAppPackage = StringUtils::replace(pkgName, ".", "/");
                const std::string &baseCodePath = getAbsoluteBaseCodePath();
                return baseCodePath + "/" + webAppPackage;
            }

            /**
            * Get absolute path to beans package dir
            * @return
            */
            const std::string getBeansAbsolutePath() {
                std::string pkgName = getBeansPkg();
                std::string beansPackage = StringUtils::replace(pkgName, ".", "/");
                const std::string &baseCodePath = getAbsoluteBaseCodePath();
                return baseCodePath + "/" + beansPackage;
            }

            /**
            * Get absolute path to web application file
            * @return
            */
            const std::string getWebApplicationFileAbsolutePath() {
                return getWebApplicationAbsolutePath() + "/" + getWebAppClassName() + ".java";
            }

            /**
            * Get absolute path to database connection file
            * @return
            */
            const std::string getDatabaseConnectionFileAbsolutePath() {
                return getWebApplicationAbsolutePath() + "/" + getDbConnClassName() + ".java";
            }
        };

    }
}
#endif //DBCRUDGEN_CPP_JAXRSPROJECTMODEL_H
