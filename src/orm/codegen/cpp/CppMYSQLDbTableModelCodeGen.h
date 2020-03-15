//
// Created by victor on 3/15/20.
//

#ifndef DBCRUDGEN_CPP_CPPMYSQLDBTABLEMODELCODEGEN_H
#define DBCRUDGEN_CPP_CPPMYSQLDBTABLEMODELCODEGEN_H

#include "CppMYSQLProjectCodeGen.h"
#include "../../../databases/mysql/models/MYSQLDatabaseModel.h"

namespace dbcrudgen {
    namespace orm {
        class CppMYSQLDbTableModelCodeGen : public CppMYSQLProjectCodeGen {

        public:

            /**
                        * Create database table model
                        * @param databaseModel
                        * @param generatedCodeDir
                        */
            void createDatabaseTableModel(CppMYSQLProjectModel projectModel, mysql::MYSQLDatabaseModel databaseModel,
                                          std::string generatedCodeDir) {

                CppClassTableModelTemplate sourceTemplate;

                std::vector<dbcrudgen::mysql::Tables> tables = databaseModel.getTables();

                for (const auto &table : tables) {

                    std::string tableName = table.getTableName();

                    //Get the source template
                    std::string content = sourceTemplate.getTemplate();

                    //Set the headers
                    std::string projectName = projectModel.getProjectName();
                    content = StringUtils::parseTemplate(content, "${PROJECT_NAME}", projectName);
                    content = StringUtils::parseTemplate(content, "${PROJECT_NAME}", projectName);
                    content = StringUtils::parseTemplate(content, "${PROJECT_NAME}", projectName);


                    //Set the class name
                    std::string class_name = parser.toCppClassName(tableName);
                    content = StringUtils::parseTemplate(content, "${CLASS_NAME_HEADER}", class_name);
                    content = StringUtils::parseTemplate(content, "${CLASS_NAME_HEADER}", class_name);
                    content = StringUtils::parseTemplate(content, "${CLASS_NAME_HEADER}", class_name);
                    content = StringUtils::parseTemplate(content, "${CLASS_NAME}", class_name);




                    //Set the table name
                    content = StringUtils::parseTemplate(content, "${TABLE_NAME}", tableName);


                    //create class properties
                    std::string ctorParams = createClassProperties(databaseModel, table);
                    content = StringUtils::parseTemplate(content, "${COLUMNS_VARS}", ctorParams);

                    //create constructor variables
                    std::string ctorVars = createConstructorParams(databaseModel, table);
                    content = StringUtils::parseTemplate(content, "${CTOR_VARIABLES}", ctorVars);

                    //Create constructor initializers
                    std::string ctorInitializers = createConstructorParamInitializers(databaseModel, table);
                    content = StringUtils::parseTemplate(content, "${INSTANCE_VARIABLES_INITIALIZERS}",
                                                         ctorInitializers);

                    //Create column getters
                    std::string columnGetters = createColumnGetters(databaseModel, table);
                    content = StringUtils::parseTemplate(content, "${COLUMNS_GETTERS}", columnGetters);


                    //Create columns meta data
                    std::string columnsMetaData = createColumnsMetaData(databaseModel, table);
                    content = StringUtils::parseTemplate(content, "${COLUMNS_METADATA}", columnsMetaData);


                    std::string tablename = table.getTableName();
                    std::cout << "Writing code for table " << tablename << std::endl;

                    std::string classname = StringUtils::createClassNameCamelCase(tablename);

                    std::string filename{generatedCodeDir.append("/").append(classname) + ".cpp"};

                    std::cout << "Temp file name " << filename << std::endl;

                    FilesWriter::writeFile(filename, content);
                }

            }

            /**
             * Create column getters
             * @param model
             * @param table
             * @return
             */
            std::string createColumnGetters(mysql::MYSQLDatabaseModel &model, const mysql::Tables &table) {

                std::string getters;

                CppPropertyGetterTemplate getterTemplate;

                const auto &columnsMap = model.getTableColumns();
                const auto &iterator
                        = columnsMap.find(table.getTableName());

                auto &tableColumns = iterator->second;

                for (auto column : tableColumns) {
                    std::string getterTmp = getterTemplate.getTemplate();

                    std::string dataType = column.getDataType();
                    std::string columnName = column.getColumnName();

                    getterTmp = parser.parseTableColumnsGetters(getterTemplate, column);


                    getters += getterTmp;
                }

                return getters;
            }


        };

    }
}


#endif //DBCRUDGEN_CPP_CPPMYSQLDBTABLEMODELCODEGEN_H
