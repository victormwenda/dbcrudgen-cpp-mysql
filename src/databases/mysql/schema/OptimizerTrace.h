//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_OPTIMIZERTRACE_H
#define DBCRUDGEN_CPP_OPTIMIZERTRACE_H

#include <string>

namespace dbcrudgen {
    namespace mysql {
        class OptimizerTrace {

        private:
            std::string query;
            std::string trace;
            int missingBytesBeyondMaxMemSize;
            int insufficientPrivileges;

        public:

            static constexpr const char *TABLE_NAME = "OPTIMIZER_TRACE";

            struct COLUMNS {
                struct QUERY {
                    static constexpr const char *NAME = "QUERY";
                    static const int INDEX = 1;
                };
                struct TRACE {
                    static constexpr const char *NAME = "TRACE";
                    static const int INDEX = 2;
                };
                struct MISSING_BYTES_BEYOND_MAX_MEM_SIZE {
                    static constexpr const char *NAME = "MISSING_BYTES_BEYOND_MAX_MEM_SIZE";
                    static const int INDEX = 3;
                };
                struct INSUFFICIENT_PRIVILEGES {
                    static constexpr const char *NAME = "INSUFFICIENT_PRIVILEGES";
                    static const int INDEX = 4;
                };
            };

            OptimizerTrace(std::string &query, std::string &trace, int missingBytesBeyondMaxMemSize,
                           int insufficientPrivileges) : query{query}, trace{trace},
                                                         missingBytesBeyondMaxMemSize{missingBytesBeyondMaxMemSize},
                                                         insufficientPrivileges{insufficientPrivileges} {}

            // Get the value of query
            const std::string &getQuery() const {
                return query;
            }

            // Get the value of trace
            const std::string &getTrace() const {
                return trace;
            }

            // Get the value of missingBytesBeyondMaxMemSize
            int getMissingBytesBeyondMaxMemSize() const {
                return missingBytesBeyondMaxMemSize;
            }

            // Get the value of insufficientPrivileges
            int getInsufficientPrivileges() const {
                return insufficientPrivileges;
            }

            /**
            * Returns the table name 'OPTIMIZER_TRACE';
            */
            static const char *getDatabaseTableName() {
                return TABLE_NAME;
            }
        };
    }
}


#endif //DBCRUDGEN_CPP_OPTIMIZERTRACE_H
