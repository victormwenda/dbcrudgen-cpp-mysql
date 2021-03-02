//
// Created by victor on 7/6/20.
//

#ifndef DBCRUDGEN_CPP_SPRINGBOOTPROJECTMODEL_H
#define DBCRUDGEN_CPP_SPRINGBOOTPROJECTMODEL_H

#include "JavaProjectModel.h"
#include "../utils/StringUtils.h"
#include "../dslmodels/java/springboot/SpringProjectClasses.h"
#include "../dslmodels/java/springboot/SpringProjectDirs.h"
#include "../dslmodels/java/springboot/SpringProjectPackages.h"
#include "../dslmodels/java/springboot/SpringProjectSuffixes.h"

namespace dbcrudgen {
    namespace orm {
        class SpringBootProjectModel : public JavaProjectModel {

            std::string projectName;
            std::string workspaceDir;
            std::string packageName;

            dbcrudgen::orm::SpringProjectDirs sbDirs;
            dbcrudgen::orm::SpringProjectPackages sbPkgs;
            dbcrudgen::orm::SpringProjectClasses sbClasses;
            dbcrudgen::orm::SpringProjectSuffixes sbClsSuffxs;

            std::string urlPattern;
            int serverPort;

        public:


            SpringBootProjectModel(std::string &projectName, std::string &workspaceDir, std::string &packageName,
                                   dbcrudgen::orm::SpringProjectDirs &sbDirs,
                                   dbcrudgen::orm::SpringProjectPackages &sbPkgs,
                                   dbcrudgen::orm::SpringProjectClasses &sbClasses,
                                   dbcrudgen::orm::SpringProjectSuffixes &sbClsSuffxs,
                                   std::string &urlPattern, int &serverPort)
                    : JavaProjectModel{projectName, workspaceDir, sbDirs.getSrcDir(), sbDirs.getModuleDir(),
                                       sbDirs.getJavaDir(),
                                       sbDirs.getLibsDir(), sbDirs.getResourcesDir(), packageName},

                      projectName(projectName),
                      workspaceDir(workspaceDir),
                      packageName(packageName),

                      sbDirs(sbDirs),
                      sbPkgs(sbPkgs),
                      sbClasses(sbClasses),
                      sbClsSuffxs(sbClsSuffxs),

                      urlPattern{urlPattern},
                      serverPort{serverPort} {}


            const std::string &getWebDir() {
                return sbDirs.getWebDir();
            }

            const std::string &getControllersPkg() const {
                return sbPkgs.getCtlsPkg();
            }

            const std::string &getDbConnPkg() const {
                return sbPkgs.getDbConnPkg();
            }

            const std::string &getEntitiesPkg() const {
                return sbPkgs.getEntitiesPkg();
            }

            const std::string &getHttpReqPkg() const {
                return sbPkgs.getHttpReqPkg();
            }

            const std::string &getHttpResPkg() const {
                return sbPkgs.getHttpResPkg();
            }

            const std::string &getModelsPkg() const {
                return sbPkgs.getModelsPkg();
            }

            const std::string &getRepositoriesPkg() const {
                return sbPkgs.getReposPkg();
            }

            const std::string &getTransactionsPkg() const {
                return sbPkgs.getTransactionsPkg();
            }

            const std::string &getSBAppClassPkg() const {
                return sbPkgs.getWebAppPkg();
            }

            const std::string &getBeansPkg() const {
                return sbPkgs.getBeansPkg();
            }

            const std::string &getBzLogicPkg() const {
                return sbPkgs.getBzLogicPkg();
            }

            const std::string &getCtlClassSuffix() const {
                return sbClsSuffxs.getCtlClassSuffix();
            }

            const std::string &getEntityClassSuffix() const {
                return sbClsSuffxs.getEntityClassSuffix();
            }

            const std::string &getHttpReqClassSuffix() const {
                return sbClsSuffxs.getHttpReqClassSuffix();
            }

            const std::string &getHttpResClassSuffix() const {
                return sbClsSuffxs.getHttpResClassSuffix();
            }

            const std::string &getRepoClassSuffix() const {
                return sbClsSuffxs.getRepoClassSuffix();
            }

            const std::string &getTrxClassSuffix() const {
                return sbClsSuffxs.getTrxClassSuffix();
            }

            const std::string &getModelClassSuffix() const {
                return sbClsSuffxs.getModelClassSuffix();
            }

            const std::string &getBeansClassSuffix() const {
                return sbClsSuffxs.getBeansClassSuffix();
            }

            const std::string &getBzLogicClassSuffix() const {
                return sbClsSuffxs.getBzLogicClassSuffix();
            }

            const std::string &getSBAppClassName() const {
                return sbClasses.getWebAppClass();
            }

            const std::string &getSBApplicationPropertiesFileName() const {
                return sbClasses.getApplicationPropertiesFile();
            }

            const std::string &getDbConnClassName() const {
                return sbClasses.getDbConnClass();
            }

            const std::string &getUrlPattern() const {
                return urlPattern;
            }

            int getServerPort() const {
                return serverPort;
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
            * Get absolute path to beans package dir
            * @return
            */
            const std::string getBzLogicAbsolutePath() {
                std::string pkgName = getBzLogicPkg();
                std::string beansPackage = StringUtils::replace(pkgName, ".", "/");
                const std::string &baseCodePath = getAbsoluteBaseCodePath();
                return baseCodePath + "/" + beansPackage;
            }

            /**
            * Get absolute path to apis dir
            * @return
            */
            const std::string getControllersAbsolutePath() {
                std::string pkgName = getControllersPkg();
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
            }/**
             * Get absolute path to http requests dir
             * @return
             */
            const std::string getHttpRequestsDirPath() {
                std::string pkgName = getHttpReqPkg();
                std::string httpReqPkg = StringUtils::replace(pkgName, ".", "/");
                return getAbsoluteBaseCodePath() + "/" + httpReqPkg;
            }

            /**
             * Get absolute path to http responses dir
             * @return
             */
            const std::string getHttpResponsesDirPath() {
                std::string pkgName = getHttpResPkg();
                std::string httpResPkg = StringUtils::replace(pkgName, ".", "/");
                return getAbsoluteBaseCodePath() + "/" + httpResPkg;
            }

            /**
           * Get absolute path to models dir
           * @return
           */
            const std::string getModelsDirPath() {
                std::string pkgName = getModelsPkg();
                std::string modelsPkg = StringUtils::replace(pkgName, ".", "/");
                return getAbsoluteBaseCodePath() + "/" + modelsPkg;
            }

            /**
             * Get absolute path to http responses dir
             * @return
             */
            const std::string getRepositoriesDirPath() {
                std::string pkgName = getRepositoriesPkg();
                std::string reposPkg = StringUtils::replace(pkgName, ".", "/");
                return getAbsoluteBaseCodePath() + "/" + reposPkg;
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

            /**
             * Create HTTP Request/Response File
             * @param httpPkgDir
             * @param tablePackage
             * @param className
             * @return
             */
            std::string
            createHttpRqRsFile(const std::string &httpPkgDir, const std::string &tablePackage,
                               const std::string &className) {
                return std::string{}.append(httpPkgDir)
                        .append("/")
                        .append(tablePackage)
                        .append("/")
                        .append(className)
                        .append(".java");
            }

        };
    }
}
#endif //DBCRUDGEN_CPP_SPRINGBOOTPROJECTMODEL_H
