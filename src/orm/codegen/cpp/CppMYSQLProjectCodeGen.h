//
// Created by vrwanda on 3/5/20.
//



#ifndef DBCRUDGEN_CPP_CPPMYSQLPROJECTCODEGEN_H
#define DBCRUDGEN_CPP_CPPMYSQLPROJECTCODEGEN_H

#include "../../projects/CppMYSQLProjectModel.h"
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
            static CppMYSQLParser parser;

        public:

            CppMYSQLProjectCodeGen() = default;

            static CppMYSQLParser getParser() {
                return parser;
            }

        };
    }
}


#endif //DBCRUDGEN_CPP_CPPMYSQLPROJECTCODEGEN_H