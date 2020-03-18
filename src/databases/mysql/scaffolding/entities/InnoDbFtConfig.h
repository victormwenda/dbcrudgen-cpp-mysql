//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_INNODBFTCONFIG_H
#define DBCRUDGEN_CPP_INNODBFTCONFIG_H

#include <string>

namespace dbcrudgen {
    namespace mysql {
        class InnoDbFtConfig {

        private:
            std::string key;
            std::string value;

        public:

            static constexpr const char *TABLE_NAME = "INNODB_FT_CONFIG";

            struct COLUMNS {
                struct KEY {
                    static constexpr const char *NAME = "KEY";
                    static const int INDEX = 1;
                };
                struct VALUE {
                    static constexpr const char *NAME = "VALUE";
                    static const int INDEX = 2;
                };
            };

            InnoDbFtConfig(std::string &key, std::string &value) : key{key}, value{value} {}

            // Get the value of key
            const std::string &getKey() const {
                return key;
            }

            // Get the value of value
            const std::string &getValue() const {
                return value;
            }


            /**
            * Returns the table name 'INNODB_FT_CONFIG';
            */
            static const char *getDatabaseTableName() {
                return TABLE_NAME;
            }
        };
    }
}


#endif //DBCRUDGEN_CPP_INNODBFTCONFIG_H
