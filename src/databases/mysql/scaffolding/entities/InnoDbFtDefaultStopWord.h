//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_INNODBFTDEFAULTSTOPWORD_H
#define DBCRUDGEN_CPP_INNODBFTDEFAULTSTOPWORD_H

#include <string>

namespace dbcrudgen {
    namespace db {
        namespace mysql {
            class InnoDbFtDefaultStopWord {

            private:
                std::string value;

            public:

                static constexpr const char *TABLE_NAME = "INNODB_FT_DEFAULT_STOPWORD";

                struct COLUMNS {
                    struct VALUE {
                        static constexpr const char *NAME = "value";
                        static const int INDEX = 1;
                    };
                };

                explicit InnoDbFtDefaultStopWord(std::string &value) : value{value} {}

                // Get the value of value
                const std::string &getValue() const {
                    return value;
                }


                /**
                * Returns the table name 'INNODB_FT_DEFAULT_STOPWORD';
                */
                static const char *getDatabaseTableName() {
                    return TABLE_NAME;
                }
            };
        }
    }

}


#endif //DBCRUDGEN_CPP_INNODBFTDEFAULTSTOPWORD_H
