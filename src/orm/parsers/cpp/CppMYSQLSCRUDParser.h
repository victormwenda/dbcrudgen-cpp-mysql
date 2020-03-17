//
// Created by victor on 3/17/20.
//

#ifndef DBCRUDGEN_CPP_CPPMYSQLSCRUDPARSER_H
#define DBCRUDGEN_CPP_CPPMYSQLSCRUDPARSER_H

namespace dbcrudgen {
    namespace orm {

        class CppMYSQLSCRUDParser : public CppMYSQLParser {

        public:
            std::string createMethodParams(const mysql::Columns &column, bool isBeforeLast) {

                const std::string datatype = toCppDataType(column.getDataType().c_str());

                std::string name{datatype + " " + column.getColumnName()};

                name = toCppVariableName(name);

                if (isBeforeLast) {
                    name.append(",");
                }

                return name;
            }

            std::string createColumnName(const mysql::Columns &column, bool isBeforeLast) {

                std::string name = {"`" + column.getColumnName() + "`"};

                if (isBeforeLast) {
                    name.append(",");
                }

                return name;
            }

            std::string createColumnValue(const mysql::Columns &column, bool isBeforeLast) {

                std::string name = column.getColumnName();

                name = toCppVariableName(name);

                std::string dataType = column.getDataType();

                if (toCppDataType(dataType.c_str()) == "std::string") {
                    name = "'\"+  " + name + " +\"'";
                } else {
                    name = "'\"+ std::to_string(" + name + ")+\"'";
                }


                if (isBeforeLast) {
                    name.append(",");
                }

                return name;
            }

            std::string
            createQueriedColumnValues(std::string tableName, const mysql::Columns &column, bool isBeforeLast) {

                std::string datatype = toCppDataType(column.getDataType().c_str());

                std::string columnName = column.getColumnName();
                std::string columnNameVariable = toCppVariableName(columnName);

                std::string resultSetGetterSource = getResultSetGetterSource(datatype.c_str());

                std::string qualifiedTableClassName = toCppClassName(tableName);
                std::string qualifiedTableColumnName = StringUtils::to_upper(columnName);

                std::string qualified_column_name_accessor = std::string{qualifiedTableClassName + "::Columns::"
                                                                         + qualifiedTableColumnName +
                                                                         "::INDEX"};

                replace(resultSetGetterSource, "${COLUMN_LABEL}", qualified_column_name_accessor);

                std::string name{datatype + " " + columnNameVariable + " = " + resultSetGetterSource};

                return name;
            }

            std::string createQueriedColumns(const mysql::Columns &column, bool isBeforeLast) {
                const std::string datatype = toCppDataType(column.getDataType().c_str());

                std::string name = column.getColumnName();

                name = toCppVariableName(name);

                if (isBeforeLast) {
                    name.append(",");
                }

                return name;
            }
        };
    }
}


#endif //DBCRUDGEN_CPP_CPPMYSQLSCRUDPARSER_H
