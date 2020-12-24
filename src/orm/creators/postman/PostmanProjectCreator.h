//
// Created by victor on 3/21/20.
//

#ifndef DBCRUDGEN_CPP_POSTMANPROJECTCREATOR_H
#define DBCRUDGEN_CPP_POSTMANPROJECTCREATOR_H

#include "../ProjectCreator.h"
#include "../../codegen/Languages.h"
#include "../../../databases/generic/Database.h"
#include "../../../io/FilesWriter.h"
#include "../../projects/PostmanProjectModel.h"
#include "../../templates/postman/PostmanCollectionTemplate.h"
#include "../../templates/postman/PostmanRequestTemplate.h"
#include "../../codegen/postman/PostmanProjectCodeGen.h"
#include "../../templates/postman/PostmanFolderTemplate.h"

namespace dbcrudgen {
    namespace orm {

        using PostmanProjectCodeGen = PostmanProjectCodeGen;

        class PostmanProjectCreator : public ProjectCreator {

        private:
            PostmanProjectModel projectModel;
            dbcrudgen::db::generic::Database database;

        public:

            PostmanProjectCreator(PostmanProjectModel &projectModel, dbcrudgen::db::generic::Database &database)
                    : projectModel{projectModel}, database{database} {}

            const PostmanProjectModel &getProjectModel() const {
                return projectModel;
            }

            const db::generic::Database &getGenericDatabase() const {
                return database;
            }

            std::string getDatabase() override {
                return projectModel.getDatabaseType();
            }

            std::string getLanguage() override {
                return std::string{dbcrudgen::orm::Languages::JSON};
            }

            void createProjectDirs() override {
                std::string codeDir = projectModel.getGeneratedCodeDir();
                FilesWriter::createDirs(codeDir);
            }

            void createSourceFiles() override {

                PostmanCollectionTemplate collectionTemplate;
                PostmanFolderTemplate folderTemplate;
                PostmanRequestTemplate requestTemplate;

                std::string collectionSource = collectionTemplate.getTemplate();
                std::string foldersSource;


                auto tables = database.getTables();
                int tablesIndex = 0;
                for (const auto &table : tables) {

                    std::string folderSource = folderTemplate.getTemplate();
                    std::string requestSource = PostmanProjectCodeGen::createSource(projectModel, table,
                                                                                    requestTemplate);
                    std::string requestsSource;

                    std::string getSource = requestSource;
                    std::string searchSource = requestSource;
                    std::string listSource = requestSource;
                    std::string postSource = requestSource;
                    std::string putSource = requestSource;
                    std::string deleteSource = requestSource;

                    getSource = PostmanProjectCodeGen::createGetSource(projectModel, table, getSource);
                    searchSource = PostmanProjectCodeGen::createGetSourceSearch(projectModel, table, searchSource);
                    listSource = PostmanProjectCodeGen::createGetSourceList(projectModel, table, listSource);
                    postSource = PostmanProjectCodeGen::createPostSource(projectModel, table, postSource);
                    putSource = PostmanProjectCodeGen::createPutSource(projectModel, table, putSource);
                    deleteSource = PostmanProjectCodeGen::createDeleteSource(projectModel, table, deleteSource);


                    auto tableColumns = table.getTableColumns();
                    std::vector<dbcrudgen::db::generic::Column> mandatoryCols;

                    std::string requestParams;
                    std::string queryParams;

                    int columnsIndex = 0;
                    for (const auto &tableColumn : tableColumns) {
                        queryParams += PostmanProjectCodeGen::createQueryParams(tableColumn);
                        if (columnsIndex < tableColumns.size() - 1) {
                            queryParams.append(",");
                        }
                        if (!tableColumn.isNullable()) {
                            mandatoryCols.emplace_back(tableColumn);
                        }
                        columnsIndex++;
                    }

                    int mandatoryColsIndex = 0;
                    for (const auto &tableColumn : mandatoryCols) {
                        requestParams += PostmanProjectCodeGen::createRequestParams(tableColumn);
                        if (mandatoryColsIndex < mandatoryCols.size() - 1) {
                            requestParams.append(",");
                        }
                        mandatoryColsIndex++;
                    }

                    StringUtils::replace(getSource, "${REQUEST_DATA}", "");
                    StringUtils::replace(getSource, "${QUERY_PARAMS}", "");

                    StringUtils::replace(listSource, "${REQUEST_DATA}", "");
                    StringUtils::replace(listSource, "${QUERY_PARAMS}", "");

                    StringUtils::replace(searchSource, "${REQUEST_DATA}", "");
                    StringUtils::replace(searchSource, "${QUERY_PARAMS}", queryParams);

                    StringUtils::replace(postSource, "${REQUEST_DATA}", requestParams);
                    StringUtils::replace(postSource, "${QUERY_PARAMS}", "");

                    StringUtils::replace(putSource, "${REQUEST_DATA}", requestParams);
                    StringUtils::replace(putSource, "${QUERY_PARAMS}", "");

                    StringUtils::replace(deleteSource, "${REQUEST_DATA}", "");
                    StringUtils::replace(deleteSource, "${QUERY_PARAMS}", "");

                    requestsSource += getSource.append(",");
                    requestsSource += listSource.append(",");
                    requestsSource += searchSource.append(",");
                    requestsSource += postSource.append(",");
                    requestsSource += putSource.append(",");
                    requestsSource += deleteSource;

                    StringUtils::replace(folderSource, "${FOLDER_NAME}", table.getTableName());
                    StringUtils::replace(folderSource, "${REQUESTS}", requestsSource);
                    foldersSource += folderSource;

                    if (tablesIndex < tables.size() - 1) {
                        foldersSource.append(",");
                    }

                    tablesIndex++;
                }

                PostmanProjectCodeGen::parseProjectDetails(collectionSource, projectModel);

                StringUtils::replace(collectionSource, "${REQUESTS_FOLDERS}", foldersSource);

                std::string collectionFilename =
                        projectModel.getGeneratedCodeDir() + "/" + projectModel.getProjectName() +
                        ".postman_collection.json";
                FilesWriter::writeFile(collectionFilename, collectionSource);
            }

            void createProject() override {
                ProjectCreator::createProject();
            }
        };


    }
}

#endif //DBCRUDGEN_CPP_POSTMANPROJECTCREATOR_H
