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
#include "../../templates/cpp/CppVariableTemplate.h"
#include "../../templates/cpp/CppPropertyGetterTemplate.h"
#include "../../templates/cpp/CppStructTableColumnModelTemplate.h"

namespace dbcrudgen {
    namespace orm {

        class CppMYSQLProjectCodeGen : public CppProjectCodeGen {

        protected:
            CppMYSQLParser parser;
        public:
            CppMYSQLProjectCodeGen() = default;

            const CppMYSQLParser &getParser() const {
                return parser;
            }


            std::string createClassProperties(mysql::MYSQLDatabaseModel model, const mysql::Tables &table) {
                CppVariableTemplate sourceTemplate;

                std::string source;

                std::string tablename = table.getTableName();
                auto columnsMap = model.getTableColumns();
                auto mapIterator = columnsMap.find(tablename);

                std::vector<mysql::Columns> &tableColumns = mapIterator->second;

                for (auto column : tableColumns) {

                    std::string srcTmp = sourceTemplate.getTemplate();

                    std::string delimiter = ";";

                    source += parser.parseTableColumnVariables(sourceTemplate, column, delimiter);

                }


                return source;
            }

            std::string createConstructorParams(mysql::MYSQLDatabaseModel model, const mysql::Tables &table) {
                CppVariableTemplate sourceTemplate;

                std::string source;

                std::string tablename = table.getTableName();
                auto columnsMap = model.getTableColumns();
                auto mapIterator = columnsMap.find(tablename);
                int index = 0;

                std::vector<mysql::Columns> &tableColumns = mapIterator->second;

                for (auto column : tableColumns) {

                    std::string srcTmp = sourceTemplate.getTemplate();

                    std::string delimiter = "";

                    if (index < tableColumns.size() - 1) {
                        delimiter = ",";
                    }

                    index++;

                    source += parser.parseTableColumnVariables(sourceTemplate, column, delimiter);

                }


                return source;
            }

            /**
             * Create constructor param initializers
             * @param model
             * @param table
             * @return
             */
            std::string
            createConstructorParamInitializers(mysql::MYSQLDatabaseModel model, const mysql::Tables &table) {
                CppCtorInitializersTemplate sourceTemplate;

                std::string source;

                std::string tablename = table.getTableName();
                auto columnsMap = model.getTableColumns();
                auto mapIterator = columnsMap.find(tablename);
                int index = 0;

                std::vector<mysql::Columns> &tableColumns = mapIterator->second;

                for (auto column : tableColumns) {

                    std::string srcTmp = sourceTemplate.getTemplate();

                    std::string delimiter = "";

                    if (index < tableColumns.size() - 1) {
                        delimiter = ",";
                    }

                    index++;

                    source += parser.parseClassConstructorInitializerProperties(sourceTemplate, column, delimiter);

                }


                return source;
            }

            /**
                 * Create constructor param initializers
                 * @param model
                 * @param table
                 * @return
                 */
            std::string
            createColumnsMetaData(mysql::MYSQLDatabaseModel model, const mysql::Tables &table) {
                CppStructTableColumnModelTemplate sourceTemplate;

                std::string source;

                std::string tablename = table.getTableName();
                auto columnsMap = model.getTableColumns();
                auto mapIterator = columnsMap.find(tablename);
                int index = 1;

                std::vector<mysql::Columns> &tableColumns = mapIterator->second;

                for (auto column : tableColumns) {

                    std::string srcTmp = sourceTemplate.getTemplate();
                    source += parser.parseTableColumnsMetaData(sourceTemplate, column, index);
                    index++;

                }


                return source;
            }

        };

    }
}


#endif //DBCRUDGEN_CPP_CPPMYSQLPROJECTCODEGEN_H