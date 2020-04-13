//
// Created by victor on 3/16/20.
//

#ifndef DBCRUDGEN_CPP_CPPMYSQLSCRUDCODEGEN_H
#define DBCRUDGEN_CPP_CPPMYSQLSCRUDCODEGEN_H


#include "../../parsers/cpp/CppMYSQLSCRUDParser.h"
#include "../../templates/cpp/CppClassTableSCRUDTemplate.h"
#include "../../templates/cpp/CppMYSQLTableInsertNativeTemplate.h"
#include "../../templates/cpp/CppMYSQLTableDeleteWithNativeTemplate.h"
#include "../../templates/cpp/CppMYSQLTableUpdateWithNativeTemplate.h"
#include "../../templates/cpp/CppMYSQLTableQueryRecordsNativeTemplate.h"
#include "../../templates/cpp/CppMYSQLTableQueryRecordsAllTemplate.h"

namespace dbcrudgen {
    namespace orm {

        class CppMYSQLSCRUDCodeGen : public CppMYSQLProjectCodeGen {

        private:
            CppMYSQLSCRUDParser scrudParser;

        public:

            CppMYSQLSCRUDCodeGen() = default;

            void createDatabaseSCRUD(CppMYSQLProjectModel projectModel, dbcrudgen::db::mysql::MYSQLDatabaseModel databaseModel,
                                     const std::string generatedCodeDir) {
                std::string projectName = projectModel.getProjectName();

                CppClassTableSCRUDTemplate sourceTemplate;


                auto tables = databaseModel.getTables();

                for (auto table : tables) {

                    const std::string &tableName = table.getTableName();

                    std::string source = sourceTemplate.getTemplate();


                    //Set the headers
                    projectName = parser.parseProjectNameToHeaderName(projectName);
                    source = StringUtils::replace(source, "${PROJECT_NAME}", projectName);

                    std::string classname = parser.toCppClassName(tableName);
                    source = parser.replace(source, "${CLASS_NAME}", classname);

                    std::string connectorFilename = classname + "Ops";
                    std::string classnameHeader = parser.parseClassNameToHeaderName(connectorFilename);
                    source = StringUtils::replace(source, "${CLASS_NAME_HEADER}", classnameHeader);

                    //Set the table name
                    source = StringUtils::replace(source, "${TABLE_NAME}", tableName);

                    //Set the table class include
                    source = StringUtils::replace(source, "${TABLE_CLASS}", parser.toCppClassName(tableName));

                    const auto tableColumnsMap = databaseModel.getTableColumns();
                    auto tableColumnsIterator = tableColumnsMap.find(tableName);

                    auto tableColumns = tableColumnsIterator->second;

                    //Insert Records template
                    CppMYSQLTableInsertNativeTemplate insertNativeTemplate;
                    std::string insertNativeSource = insertNativeTemplate.getTemplate();
                    std::string methodParams;
                    std::string columnNames;
                    std::string columnValues;


                    //Delete records template
                    CppMYSQLTableDeleteWithNativeTemplate deleteNativeTemplate;
                    std::string deleteNativeSource = deleteNativeTemplate.getTemplate();

                    //Update records template
                    CppMYSQLTableUpdateWithNativeTemplate updateNativeTemplate;
                    std::string updateNativeSource = updateNativeTemplate.getTemplate();

                    //Query records template native
                    CppMYSQLTableQueryRecordsNativeTemplate queryNativeTemplate;
                    std::string queryRecordsNativeSource = queryNativeTemplate.getTemplate();

                    //Query records all template
                    CppMYSQLTableQueryRecordsAllTemplate queryRecordsAllTemplate;
                    std::string queryRecordsAllSource = queryRecordsAllTemplate.getTemplate();
                    parser.replace(queryRecordsAllSource, "${TABLE_NAME}", tableName);
                    parser.replace(queryRecordsAllSource, "${TABLE_CLASS}", parser.toCppClassName(tableName));
                    parser.replace(queryRecordsAllSource, "${TABLE_CLASS_VARIABLE}",
                                   parser.toCppVariableName(tableName));
                    std::string queryColumnValues;
                    std::string queriedColumn;

                    int index = 0;

                    for (const auto &column : tableColumns) {

                        bool isBeforeLast = (index < tableColumns.size() - 1);

                        methodParams += scrudParser.createMethodParams(column, isBeforeLast);
                        columnNames += scrudParser.createColumnName(column, isBeforeLast);
                        columnValues += scrudParser.createColumnValue(column, isBeforeLast);

                        queryColumnValues += scrudParser.createQueriedColumnValues(tableName, column, isBeforeLast);
                        queriedColumn += scrudParser.createQueriedColumns(column, isBeforeLast);

                        index++;

                    }

                    //Insert Records template
                    parser.replace(insertNativeSource, "${METHOD_PARAMS}", methodParams);
                    parser.replace(insertNativeSource, "${COLUMN_NAMES}", columnNames);
                    parser.replace(insertNativeSource, "${COLUMN_VALUES}", columnValues);

                    //Add insert records native
                    source = parser.replace(source, "${INSERT_RECORDS_NATIVE}", insertNativeSource);
                    //Add insert records with model
                    source = parser.replace(source, "${INSERT_RECORDS_MODEL}", "");


                    //Add query all records
                    parser.replace(queryRecordsAllSource, " ${QUERY_COLUMN_VALUES}", queryColumnValues);
                    parser.replace(queryRecordsAllSource, "${QUERIED_COLUMNS}", queriedColumn);
                    parser.replace(source, "${QUERY_ALL_RECORDS}", queryRecordsAllSource);

                    //Add query one record with id
                    source = parser.replace(source, "${QUERY_ONE_RECORDS_WITH_ID}", "");
                    //Add query one record with model
                    source = parser.replace(source, "${QUERY_ONE_RECORDS_WITH_MODEL}", "");
                    //Add update all records
                    source = parser.replace(source, "${UPDATE_RECORDS}", "");
                    //Add delete records
                    source = parser.replace(source, "${DELETE_RECORDS}", "");


                    std::string filename = generatedCodeDir + "/" + connectorFilename + ".h";

                    FilesWriter::writeFile(filename, source);
                }
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_CPPMYSQLSCRUDCODEGEN_H
