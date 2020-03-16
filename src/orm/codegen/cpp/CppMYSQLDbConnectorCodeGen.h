//
// Created by victor on 3/15/20.
//

#ifndef DBCRUDGEN_CPP_CPPMYSQLDBCONNECTORCODEGEN_H
#define DBCRUDGEN_CPP_CPPMYSQLDBCONNECTORCODEGEN_H

#include "CppMYSQLProjectCodeGen.h"
#include "../../templates/cpp/CppMYSQLConnectorTemplate.h"

namespace dbcrudgen {
    namespace orm {
        class CppMYSQLDbConnectorCodeGen : public CppMYSQLProjectCodeGen {

        public:
            void createDatabaseConnector(CppMYSQLProjectModel &projectModel, std::string &srcDir) {
                std::string projectName = projectModel.getProjectName();

                CppMYSQLConnectorTemplate sourceTemplate;
                std::string source = sourceTemplate.getTemplate();

                //Set the headers
                projectName = parser.parseProjectNameToHeaderName(projectName);
                source = StringUtils::replace(source, "${PROJECT_NAME}", projectName);

                std::string connectorFilename = "MYSQLDatabaseConnector";
                std::string classnameHeader = parser.parseClassNameToHeaderName(connectorFilename);
                source = StringUtils::replace(source, "${CLASS_NAME_HEADER}", classnameHeader);

                std::string filename = srcDir.append("/").append(connectorFilename).append(".h");

                FilesWriter::writeFile(filename, source);

            }
        };

    }
}

#endif //DBCRUDGEN_CPP_CPPMYSQLDBCONNECTORCODEGEN_H
