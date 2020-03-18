//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_ENGINES_H
#define DBCRUDGEN_CPP_ENGINES_H

#include <string>

namespace dbcrudgen {
    namespace mysql {
        class Engines {

        private:
            std::string engine;
            std::string support;
            std::string comment;
            std::string transactions;
            std::string xa;
            std::string savepoints;

        public:

            static constexpr const char *TABLE_NAME = "ENGINES";

            struct COLUMNS {
                struct ENGINE {
                    static constexpr const char *NAME = "ENGINE";
                    static const int INDEX = 1;
                };
                struct SUPPORT {
                    static constexpr const char *NAME = "SUPPORT";
                    static const int INDEX = 2;
                };
                struct COMMENT {
                    static constexpr const char *NAME = "COMMENT";
                    static const int INDEX = 3;
                };
                struct TRANSACTIONS {
                    static constexpr const char *NAME = "TRANSACTIONS";
                    static const int INDEX = 4;
                };
                struct XA {
                    static constexpr const char *NAME = "XA";
                    static const int INDEX = 5;
                };
                struct SAVEPOINTS {
                    static constexpr const char *NAME = "SAVEPOINTS";
                    static const int INDEX = 6;
                };
            };

            Engines(std::string &engine, std::string &support, std::string &comment, std::string &transactions,
                    std::string &xa, std::string &savepoints) : engine{engine}, support{support}, comment{comment},
                                                                transactions{transactions}, xa{xa},
                                                                savepoints{savepoints} {}

            // Get the value of engine
            const std::string &getEngine() const {
                return engine;
            }

            // Get the value of support
            const std::string &getSupport() const {
                return support;
            }

            // Get the value of comment
            const std::string &getComment() const {
                return comment;
            }

            // Get the value of transactions
            const std::string &getTransactions() const {
                return transactions;
            }

            // Get the value of xa
            const std::string &getXa() const {
                return xa;
            }

            // Get the value of savepoints
            const std::string &getSavepoints() const {
                return savepoints;
            }

            /**
            * Returns the table name 'ENGINES';
            */
            static const char *getDatabaseTableName() {
                return TABLE_NAME;
            }
        };
    }
}


#endif //DBCRUDGEN_CPP_ENGINES_H
