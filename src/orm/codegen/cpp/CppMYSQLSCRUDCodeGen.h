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

namespace dbcrudgen {
    namespace orm {

        class CppMYSQLSCRUDCodeGen : public CppMYSQLProjectCodeGen {

        private:
            CppMYSQLSCRUDParser scrudParser;

        public:

            CppMYSQLSCRUDCodeGen() = default;

            void createDatabaseSCRUD(CppMYSQLProjectModel projectModel, mysql::MYSQLDatabaseModel databaseModel,
                                     const std::string generatedCodeDir) {
                std::string projectName = projectModel.getProjectName();
                std::cout << "the project name is " << projectName << std::endl;

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

                    //Query records template
                    CppMYSQLTableQueryRecordsNativeTemplate queryNativeTemplate;
                    std::string queryRecordsNativeSource = queryNativeTemplate.getTemplate();

                    int index = 0;

                    for (const auto &column : tableColumns) {

                        bool isBeforeLast = (index < tableColumns.size() - 1);

                        methodParams += scrudParser.createMethodParams(column, isBeforeLast);
                        columnNames += scrudParser.createColumnName(column, isBeforeLast);
                        columnValues += scrudParser.createColumnValue(column, isBeforeLast);

                        index++;

                    }

                    parser.replace(insertNativeSource, "${METHOD_PARAMS}", methodParams);
                    parser.replace(insertNativeSource, "${COLUMN_NAMES}", columnNames);
                    parser.replace(insertNativeSource, "${COLUMN_VALUES}", columnValues);

                    //Add insert records native
                    source = parser.replace(source, "${INSERT_RECORDS_NATIVE}", insertNativeSource);

                    std::string filename = generatedCodeDir + "/" + connectorFilename + ".h";
                    std::cout << "file name is : " << filename << std::endl;
                    FilesWriter::writeFile(filename, source);
                }
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_CPPMYSQLSCRUDCODEGEN_H
