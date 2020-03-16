//
// Created by victor on 3/16/20.
//

#ifndef DBCRUDGEN_CPP_CPPMYSQLSCRUDCODEGEN_H
#define DBCRUDGEN_CPP_CPPMYSQLSCRUDCODEGEN_H

#include "CppMYSQLProjectCodeGen.h"
#include "../../templates/cpp/CppClassTableSCRUDTemplate.h"

namespace dbcrudgen {
    namespace orm {

        class CppMYSQLSCRUDCodeGen : public CppMYSQLProjectCodeGen {

        public:

            CppMYSQLSCRUDCodeGen() = default;

            void createDatabaseSCRUD(CppMYSQLProjectModel projectModel, mysql::MYSQLDatabaseModel databaseModel,
                                     const std::string generatedCodeDir) {
                std::string projectName = projectModel.getProjectName();
                std::cout << "the project name is " << projectName << std::endl;

                CppClassTableSCRUDTemplate sourceTemplate;


                auto tables = databaseModel.getTables();

                for (auto table : tables) {
                    std::string source = sourceTemplate.getTemplate();

                    const std::string &tableName = table.getTableName();
                    const auto tableColumns = databaseModel.getTableColumns();
                    auto tableColumnsIterator = tableColumns.find(tableName);


                    //Set the headers
                    projectName = parser.parseProjectNameToHeaderName(projectName);
                    source = StringUtils::replace(source, "${PROJECT_NAME}", projectName);

                    std::string classname = parser.toCppClassName(tableName);
                    source = parser.replace(source, "${CLASS_NAME}", classname);

                    std::string connectorFilename = classname + "Ops";
                    std::string classnameHeader = parser.parseClassNameToHeaderName(connectorFilename);
                    source = StringUtils::replace(source, "${CLASS_NAME_HEADER}", classnameHeader);

                    std::string filename = generatedCodeDir + "/" + connectorFilename + ".h";
                    std::cout << "file name is : " << filename << std::endl;
                    FilesWriter::writeFile(filename, source);
                }
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_CPPMYSQLSCRUDCODEGEN_H
