//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_SESSIONSTATUS_H
#define DBCRUDGEN_CPP_SESSIONSTATUS_H

#include <string>

namespace dbcrudgen {
    namespace mysql {
        class SessionStatus {

        private:
            std::string variableName;
            std::string variableValue;

        public:

            static constexpr const char *TABLE_NAME = "SESSION_STATUS";

            struct COLUMNS {
                struct VARIABLE_NAME {
                    static constexpr const char *NAME = "VARIABLE_NAME";
                    static const int INDEX = 1;
                };
                struct VARIABLE_VALUE {
                    static constexpr const char *NAME = "VARIABLE_VALUE";
                    static const int INDEX = 2;
                };
            };

            SessionStatus(std::string &variableName, std::string &variableValue) : variableName{variableName},
                                                                                   variableValue{variableValue} {}

            // Get the value of variableName
            const std::string &getVariableName() const {
                return variableName;
            }

            // Get the value of variableValue
            const std::string &getVariableValue() const {
                return variableValue;
            }

            /**
            * Returns the table name 'SESSION_STATUS';
            */
            static const char *getDatabaseTableName() {
                return TABLE_NAME;
            }
        };

    }
}


#endif //DBCRUDGEN_CPP_SESSIONSTATUS_H
