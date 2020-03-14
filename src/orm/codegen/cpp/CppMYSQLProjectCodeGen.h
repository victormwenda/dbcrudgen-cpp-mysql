//
// Created by vrwanda on 3/5/20.
//



#ifndef DBCRUDGEN_CPP_CPPMYSQLPROJECTCODEGEN_H
#define DBCRUDGEN_CPP_CPPMYSQLPROJECTCODEGEN_H

#include "../../projects/CppMYSQLProjectModel.h"
#include "../../creators/cpp/CppMYSQLProjectCreator.h"
#include "../../parsers/cpp/CppMYSQLParser.h"
#include "../../templates/cpp/CppClassTableModelTemplate.h"
#include "CppProjectCodeGen.h"

namespace dbcrudgen {
    namespace orm {

        class CppMYSQLProjectCodeGen : public CppProjectCodeGen {

        private:
            CppMYSQLParser parser;

        public:
            CppMYSQLProjectCodeGen() = default;

            const CppMYSQLParser &getParser() const {
                return parser;
            }

            void createDatabaseTableModel(mysql::MYSQLDatabaseModel model, std::string generatedCodeDir) {

                CppClassTableModelTemplate sourceTemplate;

                std::vector<dbcrudgen::mysql::Tables> tables = model.getTables();

                for (const auto &table : tables) {

                    std::string tablename = table.getTableName();
                    std::cout << "Writing code for table " << tablename << std::endl;

                    std::string classname = StringUtils::createClassNameCamelCase(tablename);

                    std::string filename{generatedCodeDir + "/" + classname + ".cpp"};
                    std::string content = sourceTemplate.getTemplate();

                    std::cout << "Temp file name " << filename << std::endl;

                    FilesWriter::writeFile(filename, content);
                }

            }
        };


    }
}


#endif //DBCRUDGEN_CPP_CPPMYSQLPROJECTCODEGEN_H