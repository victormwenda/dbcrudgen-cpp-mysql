//
// Created by victor on 3/21/20.
//

#ifndef DBCRUDGEN_CPP_POSTMANPROJECTCODEGEN_H
#define DBCRUDGEN_CPP_POSTMANPROJECTCODEGEN_H

#include <string>
#include "../../projects/PostmanProjectModel.h"
#include "../../../databases/generic/Database.h"
#include "../../../databases/generic/Table.h"
#include "../../../databases/generic/Column.h"
#include "../../utils/StringUtils.h"
#include "../../templates/postman/PostmanRequestTemplate.h"
#include "../../templates/postman/PostmanRequestBodyTemplate.h"

namespace dbcrudgen {
    namespace orm {
        class PostmanProjectCodeGen : public ProjectCodeGen {

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
                std::string apiName = StringUtils::toKebabCase(table.getTableName());
                std::string baseURL = projectModel.getBaseURL();
                std::string rawURL = std::string{baseURL + "/" + apiName};
                StringUtils::replace(source, "${RAW_URL}", rawURL);

                StringUtils::replace(source, "${PROTOCOL}", projectModel.getProtocol());
                StringUtils::replace(source, "${HOST}", projectModel.getHost());
                StringUtils::replace(source, "${PORT}", std::to_string(projectModel.getPort()));

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

                    if (index < parts.size() - 1) {
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
             * Create the source code for a get request
             * @param table
             * @param reqSource
             * @return
             */
            static std::string
            createGetSource(PostmanProjectModel &projectModel, const dbcrudgen::db::generic::Table &table,
                            std::string reqSource) {
                const std::string &tableName = table.getTableName();
                std::string apiName = std::string{StringUtils::toKebabCase(tableName) + "-get"};

                StringUtils::replace(reqSource, "${REQUEST_NAME}", apiName);
                StringUtils::replace(reqSource, "${REQUEST_METHOD}", "GET");
                StringUtils::replace(reqSource, "${REQUEST_BODY}", "");
                StringUtils::replace(reqSource, "${DESCRIPTION}", "Get a single item from the table " + tableName);

                std::string resSegment = std::string{StringUtils::toKebabCase(tableName) + "/get"};
                std::string segments = createPathSegments(
                        std::string{projectModel.getPathSegments() + "/" + resSegment});

                StringUtils::replace(reqSource, "${PATH_SEGMENTS}", segments);

                return reqSource;
            }

            /**
             * Create the source code for a get request
             * @param table
             * @param reqSource
             * @return
             */
            static std::string
            createGetSourceSearch(PostmanProjectModel &projectModel, const dbcrudgen::db::generic::Table &table,
                                  std::string reqSource) {
                const std::string &tableName = table.getTableName();
                std::string apiName = std::string{StringUtils::toKebabCase(tableName) + "-search"};

                StringUtils::replace(reqSource, "${REQUEST_NAME}", apiName);
                StringUtils::replace(reqSource, "${REQUEST_METHOD}", "GET");
                StringUtils::replace(reqSource, "${REQUEST_BODY}", "");
                StringUtils::replace(reqSource, "${DESCRIPTION}", "Search items from the table " + tableName);

                std::string resSegment = std::string{StringUtils::toKebabCase(tableName) + "/search"};
                std::string segments = createPathSegments(
                        std::string{projectModel.getPathSegments() + "/" + resSegment});

                StringUtils::replace(reqSource, "${PATH_SEGMENTS}", segments);

                return reqSource;
            }

            /**
             * Create the source code for a get request for listing items
             * @param table
             * @param reqSource
             * @return
             */
            static std::string
            createGetSourceList(PostmanProjectModel &projectModel, const dbcrudgen::db::generic::Table &table,
                                std::string reqSource) {
                const std::string &tableName = table.getTableName();
                std::string apiName = std::string{StringUtils::toKebabCase(tableName) + "-list"};

                StringUtils::replace(reqSource, "${REQUEST_NAME}", apiName);
                StringUtils::replace(reqSource, "${REQUEST_METHOD}", "GET");
                StringUtils::replace(reqSource, "${REQUEST_BODY}", "");
                StringUtils::replace(reqSource, "${DESCRIPTION}", "List items from the table " + tableName);

                std::string resSegment = std::string{StringUtils::toKebabCase(tableName) + "/list"};
                std::string segments = createPathSegments(
                        std::string{projectModel.getPathSegments() + "/" + resSegment});

                StringUtils::replace(reqSource, "${PATH_SEGMENTS}", segments);

                return reqSource;
            }

            /**
             * Creates the source code for a post request
             * @param table
             * @param reqSource
             * @return
             */
            static std::string
            createPostSource(PostmanProjectModel &projectModel, const dbcrudgen::db::generic::Table &table,
                             std::string reqSource) {

                const std::string &tableName = table.getTableName();
                std::string apiName = std::string{StringUtils::toKebabCase(tableName) + "-store"};

                StringUtils::replace(reqSource, "${REQUEST_NAME}", apiName);
                StringUtils::replace(reqSource, "${REQUEST_METHOD}", "POST");
                StringUtils::replace(reqSource, "${DESCRIPTION}", "Save a single item in the table " + tableName);

                PostmanRequestBodyTemplate requestBodyTemplate;
                StringUtils::replace(reqSource, "${REQUEST_BODY}", requestBodyTemplate.getTemplate());
                StringUtils::replace(reqSource, "${DATA_MODE}", "formdata");

                std::string resSegment = std::string{StringUtils::toKebabCase(tableName) + "/store"};
                std::string segments = createPathSegments(
                        std::string{projectModel.getPathSegments() + "/" + resSegment});

                StringUtils::replace(reqSource, "${PATH_SEGMENTS}", segments);

                return reqSource;
            }

            /**
             * Creates the source code for a put request
             *
             * @param table
             * @param reqSource
             * @return
             */
            static std::string
            createPutSource(PostmanProjectModel &projectModel, const dbcrudgen::db::generic::Table &table,
                            std::string reqSource) {
                const std::string &tableName = table.getTableName();
                std::string apiName = std::string{StringUtils::toKebabCase(tableName) + "-update/"};

                StringUtils::replace(reqSource, "${REQUEST_NAME}", apiName);;
                StringUtils::replace(reqSource, "${REQUEST_METHOD}", "PUT");
                StringUtils::replace(reqSource, "${DESCRIPTION}", "Update a single item in the table " + tableName);

                PostmanRequestBodyTemplate requestBodyTemplate;
                StringUtils::replace(reqSource, "${REQUEST_BODY}", requestBodyTemplate.getTemplate());
                StringUtils::replace(reqSource, "${DATA_MODE}", "urlencoded");

                std::string resSegment = std::string{StringUtils::toKebabCase(tableName) + "/update/"};
                std::string segments = createPathSegments(
                        std::string{projectModel.getPathSegments() + "/" + resSegment});
                StringUtils::replace(reqSource, "${PATH_SEGMENTS}", segments);

                return reqSource;
            }

            /**
             * Creates the source code for a delete request
             * @param table
             * @param reqSource
             * @return
             */
            static std::string
            createDeleteSource(PostmanProjectModel &projectModel, const dbcrudgen::db::generic::Table &table,
                               std::string reqSource) {

                const std::string &tableName = table.getTableName();
                std::string apiName = std::string{StringUtils::toKebabCase(tableName) + "-delete/"};

                StringUtils::replace(reqSource, "${REQUEST_NAME}", apiName);
                StringUtils::replace(reqSource, "${REQUEST_BODY}", "");
                StringUtils::replace(reqSource, "${REQUEST_METHOD}", "DELETE");
                StringUtils::replace(reqSource, "${DESCRIPTION}", "Delete a single item in the table " + tableName);

                std::string resSegment = std::string{StringUtils::toKebabCase(tableName) + "/delete"};
                std::string segments = createPathSegments(
                        std::string{projectModel.getPathSegments() + "/" + resSegment});
                StringUtils::replace(reqSource, "${PATH_SEGMENTS}", segments);

                return reqSource;
            }


            /**
             * Creates the form params for a request
             * @param column
             * @return
             */
            static std::string createRequestParams(const db::generic::Column &column) {
                std::string paramsTemplate = R"({"key":"${KEY}","value":"${VALUE}","type":"text"})";
                const std::string &columnName = column.getColumnName();
                std::string key = StringUtils::toCamelCase(columnName);
                StringUtils::replace(paramsTemplate, "${KEY}", key);
                StringUtils::replace(paramsTemplate, "${VALUE}", "");
                return paramsTemplate;
            }

            /**
             * Creates the query params for a request
             * @param column
             * @return
             */
            static std::string createQueryParams(const db::generic::Column &column) {
                std::string paramsTemplate = R"({"key":"${KEY}","value":"${VALUE}","type":"text"})";
                const std::string &columnName = column.getColumnName();
                std::string key = StringUtils::toCamelCase(columnName);
                StringUtils::replace(paramsTemplate, "${KEY}", key);
                StringUtils::replace(paramsTemplate, "${VALUE}", "");
                return paramsTemplate;
            }
        };
    }
}

#endif //DBCRUDGEN_CPP_POSTMANPROJECTCODEGEN_H
