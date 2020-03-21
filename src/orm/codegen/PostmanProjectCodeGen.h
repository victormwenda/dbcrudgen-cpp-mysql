//
// Created by victor on 3/21/20.
//

#ifndef DBCRUDGEN_CPP_POSTMANPROJECTCODEGEN_H
#define DBCRUDGEN_CPP_POSTMANPROJECTCODEGEN_H

#include <string>
#include "../../orm/projects/PostmanProjectModel.h"
#include "../../databases/generic/Database.h"
#include "../../databases/generic/Table.h"
#include "../../databases/generic/Column.h"
#include "../utils/StringUtils.h"
#include "../templates/postman/PostmanRequestTemplate.h"

namespace dbcrudgen {
    namespace orm {
        class PostmanProjectCodeGen {

        public:

            /**
             * Set the collection name and the collection id
             * @param collectionSourceCode
             * @param model
             * @return
             */
            static std::string
            parseProjectDetails(std::string &collectionSourceCode, dbcrudgen::orm::PostmanProjectModel model) {
                StringUtils::replace(collectionSourceCode, "${COLLECTION_NAME}", model.getProjectName());
                StringUtils::replace(collectionSourceCode, "${POSTMAN_ID}", "");
                return collectionSourceCode;
            }

            /**
             * Create the source code for a get request
             * @param table
             * @param getReqSource
             * @return
             */
            static std::string
            createGetSource(const dbcrudgen::db::generic::Table &table, std::string getReqSource) {
                std::string apiName = StringUtils::toSnakeCase(table.getTableName());
                StringUtils::replace(getReqSource, "${REQUEST_NAME}", std::string{apiName + "-get"});
                StringUtils::replace(getReqSource, "${REQUEST_METHOD}", "GET");
                return getReqSource;
            }

            /**
             * Creates the source code for a post request
             * @param table
             * @param postReqSource
             * @return
             */
            static std::string
            createPostSource(const dbcrudgen::db::generic::Table &table, std::string postReqSource) {
                std::string apiName = StringUtils::toSnakeCase(table.getTableName());
                StringUtils::replace(postReqSource, "${REQUEST_NAME}", std::string{apiName + "-post"});
                StringUtils::replace(postReqSource, "${REQUEST_METHOD}", "POST");
                return postReqSource;
            }

            /**
             * Creates the source code for a put request
             *
             * @param table
             * @param putReqSource
             * @return
             */
            static std::string
            createPutSource(const dbcrudgen::db::generic::Table &table, std::string putReqSource) {
                std::string apiName = StringUtils::toSnakeCase(table.getTableName());
                StringUtils::replace(putReqSource, "${REQUEST_NAME}", std::string{apiName + "-put"});
                StringUtils::replace(putReqSource, "${REQUEST_METHOD}", "PUT");
                return putReqSource;
            }

            /**
             * Creates the source code for a delete request
             * @param table
             * @param delReqSource
             * @return
             */
            static std::string
            createDeleteSource(const dbcrudgen::db::generic::Table &table, std::string delReqSource) {
                std::string apiName = StringUtils::toSnakeCase(table.getTableName());
                StringUtils::replace(delReqSource, "${REQUEST_NAME}", std::string{apiName + "-delete"});
                StringUtils::replace(delReqSource, "${REQUEST_METHOD}", "DELETE");
                return delReqSource;
            }

            /**
             * Creates the source code for a request
             * @param projectModel
             * @param table
             * @param reqTemplate
             * @return
             */
            static std::string
            createSource(PostmanProjectModel &projectModel, const dbcrudgen::db::generic::Table &table,
                         PostmanRequestTemplate reqTemplate) {
                std::string source = reqTemplate.getTemplate();
                std::string apiName = StringUtils::toSnakeCase(table.getTableName());
                std::string baseURL = projectModel.getBaseURL();
                std::string rawURL = std::string{baseURL + "/" + apiName};
                StringUtils::replace(source, "${RAW_URL}", rawURL);

                StringUtils::replace(source, "${PROTOCOL}", projectModel.getProtocol());
                StringUtils::replace(source, "${HOST}", projectModel.getHost());

                std::string segments = createPathSegments(projectModel.getPathSegments());
                StringUtils::replace(source, "${PATH_SEGMENTS}", segments);

                std::string headers = createHeaders(
                        const_cast<std::map<std::string, std::string> &>(projectModel.getHeaders()));
                StringUtils::replace(source, "${HEADERS}", headers);

                return source;
            }

            /**
             * Creates the path segments for a request
             * @param pathSegments
             * @return
             */
            static std::string createPathSegments(const std::string &pathSegments) {

                std::string segments;

                std::vector<std::string> parts = StringUtils::split(pathSegments, "/");

                int index = 0;

                for (std::string &segment : parts) {

                    segments.append("\"").append(segment).append("\"");

                    if (index < segment.length() - 1) {
                        segments.append(",");
                    }

                    index++;
                }

                return segments;
            }

            /**
             * Creates the headers for a request
             * @param headers
             * @return
             */
            static std::string createHeaders(std::map<std::string, std::string> &headers) {
                std::string headerList;

                std::map<std::string, std::string>::iterator iterator = headers.begin();

                int index = 0;
                while (iterator != headers.end()) {
                    std::string headerTemplate = "{\"key\":\"${KEY}\",\"value\":\"${VALUE}\",\"type\":\"text\"}";

                    StringUtils::replace(headerTemplate, "${KEY}", iterator->first);
                    StringUtils::replace(headerTemplate, "${VALUE}", iterator->second);

                    headerList.append(headerTemplate);

                    if (index < headers.size() - 1) {
                        headerList.append(",");
                    }
                    iterator++;
                    index++;
                }

                return headerList;
            }

            /**
             * Creates the form params for a request
             * @param column
             * @return
             */
            static std::string createFormParams(const db::generic::Column &column) {
                std::string paramsTemplate = "{\"key\":\"${KEY}\",\"value\":\"${VALUE}\",\"type\":\"text\"}";
                StringUtils::replace(paramsTemplate, "${KEY}", column.getColumnName());
                StringUtils::replace(paramsTemplate, "${VALUE}", "");
                return paramsTemplate;
            }

            /**
             * Creates the query params for a request
             * @param column
             * @return
             */
            static std::string createQueryParams(const db::generic::Column &column) {
                std::string paramsTemplate = "{\"key\":\"${KEY}\",\"value\":\"${VALUE}\",\"type\":\"text\"}";
                StringUtils::replace(paramsTemplate, "${KEY}", column.getColumnName());
                StringUtils::replace(paramsTemplate, "${VALUE}", "");
                return paramsTemplate;
            }
        };
    }
}

#endif //DBCRUDGEN_CPP_POSTMANPROJECTCODEGEN_H
