//
// Created by victor on 3/17/20.
//

#ifndef DBCRUDGEN_CPP_CPPMYSQLSCRUDPARSER_H
#define DBCRUDGEN_CPP_CPPMYSQLSCRUDPARSER_H

namespace dbcrudgen {
    namespace orm {

        class CppMYSQLSCRUDParser : public CppMYSQLParser {

        public:
            std::string createMethodParams(const mysql::Columns &columns, bool isBeforeLast) {

                const std::string datatype = toCppDataType(columns.getDataType().c_str());

                std::string name{datatype + " " + columns.getColumnName()};

                name = toCppVariableName(name);

                if (isBeforeLast) {
                    name.append(",");
                }

                return name;
            }

            std::string createColumnName(const mysql::Columns &columns, bool isBeforeLast) {

                std::string name = {"`" + columns.getColumnName() + "`"};

                if (isBeforeLast) {
                    name.append(",");
                }

                return name;
            }

            std::string createColumnValue(const mysql::Columns &columns, bool isBeforeLast) {

                std::string name = columns.getColumnName();

                name = toCppVariableName(name);

                std::string dataType = columns.getDataType();

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
        };
    }
}


#endif //DBCRUDGEN_CPP_CPPMYSQLSCRUDPARSER_H
