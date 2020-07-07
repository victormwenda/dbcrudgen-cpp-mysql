//
// Created by victor on 7/6/20.
//

#ifndef DBCRUDGEN_CPP_SPRINGBOOTPROJECTMODEL_H
#define DBCRUDGEN_CPP_SPRINGBOOTPROJECTMODEL_H

#include "JavaProjectModel.h"
#include "../utils/StringUtils.h"

namespace dbcrudgen {
    namespace orm {
        class SpringBootProjectModel : public JavaProjectModel {

            std::string webDir;

            std::string apisPkg;
            std::string dbConnPkg;
            std::string entitiesPkg;
            std::string transactionsPkg;
            std::string sbAppPkg;
            std::string beansPkg;

            std::string apiClassSuffix;
            std::string entityClassSuffix;
            std::string trxClassSuffix;
            std::string beansClassSuffix;

            std::string sbAppClassName;
            std::string dbConnClassName;

            std::string urlPattern;

        public:

            /**
             * SpringBoot Project Model
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
             * @param sbAppPkg
             * @param beansPkg
             * @param apiClassSuffix
             * @param entityClassSuffix
             * @param trxClassSuffix
             * @param beansClassSuffix
             * @param sbAppClassName
             * @param dbConnClassName
             * @param urlPattern
             */
            SpringBootProjectModel(std::string &projectName, std::string &workspaceDir, std::string &srcDir,
                                   std::string &moduleDir, std::string &javaDir, std::string &libsDir,
                                   std::string &resourcesDir, std::string &packageName,

                                   std::string &webDir,
                                   std::string &apisPkg, std::string &dbConnPkg, std::string &entitiesPkg,
                                   std::string &transactionsPkg, std::string &sbAppPkg, std::string &beansPkg,

                                   std::string &apiClassSuffix, std::string &entityClassSuffix,
                                   std::string &trxClassSuffix,
                                   std::string &beansClassSuffix,

                                   std::string &sbAppClassName, std::string &dbConnClassName,

                                   std::string &urlPattern)

                    : JavaProjectModel{projectName, workspaceDir, srcDir, moduleDir, javaDir,
                                       libsDir, resourcesDir, packageName},
                      webDir{webDir},

                      apisPkg{apisPkg}, dbConnPkg{dbConnPkg}, entitiesPkg{entitiesPkg},
                      transactionsPkg{transactionsPkg}, sbAppPkg{sbAppPkg}, beansPkg{beansPkg},

                      apiClassSuffix{apiClassSuffix}, entityClassSuffix{entityClassSuffix},
                      trxClassSuffix{trxClassSuffix}, beansClassSuffix{beansClassSuffix},

                      sbAppClassName{sbAppClassName}, dbConnClassName{dbConnClassName},
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

            const std::string &getSBAppClassPkg() const {
                return sbAppPkg;
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

            const std::string &getSBAppClassName() const {
                return sbAppClassName;
            }

            const std::string &getDbConnClassName() const {
                return dbConnClassName;
            }

            const std::string &getUrlPattern() const {
                return urlPattern;
            }

            /**
            * Get the absolute path to the project webdir files
             * This is resources/public
            * @return
            */
            const std::string getAbsoluteWebDirPath() {
                return getAbsoluteResourcesPath() + "/" + getWebDir();
            }

            /**
            * Get the absolute path to the project error files dir
            * @return
            */
            const std::string getAbsoluteWebErrorDirPath() {
                return getAbsoluteWebDirPath() + "/error";
            }

            /**
             * Get the absolute path for a web error
             * @param filename
             * @return
             */
            const std::string getAbsoluteWebErrorFilePath(std::string error) {
                return getAbsoluteWebErrorDirPath() + "/" + error + ".html";
            }

            const std::string getAbsoluteWebError404FilePath() {
                return getAbsoluteWebErrorFilePath("404");
            }

            const std::string getAbsoluteWebError400FilePath() {
                return getAbsoluteWebErrorFilePath("400");
            }

            const std::string getAbsoluteWebError500FilePath() {
                return getAbsoluteWebErrorFilePath("500");
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
                std::string pkgName = getSBAppClassPkg();
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
                return getWebApplicationAbsolutePath() + "/" + getSBAppClassName() + ".java";
            }

            /**
            * Get absolute path to database connection file
            * @return
            */
            const std::string getDatabaseConnectionFileAbsolutePath() {
                return getWebApplicationAbsolutePath() + "/" + getDbConnClassName() + ".java";
            }

            /**
            * Get absolute path to database connection file
            * @return
            */
            const std::string getAbstractableTransactionsExecutorFileAbsolutePath() {
                return getTransactionsAbsolutePath() + "/AbstractableTransactionsExecutor.java";
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_SPRINGBOOTPROJECTMODEL_H
