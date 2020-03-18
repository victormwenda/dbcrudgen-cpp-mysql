#ifndef INFORMATION_SCHEMA_CPP_PLUGIN_H
#define INFORMATION_SCHEMA_CPP_PLUGIN_H

#include<string>

namespace dbcrudgen {
    namespace mysql {
        class Plugin {

        private:
            std::string name;
            std::string dl;

        public:

            static constexpr const char *TABLE_NAME = "plugin";

            struct COLUMNS {
                struct NAME {
                    static constexpr const char *_NAME = "name";
                    static const int INDEX = 1;
                };
                struct DL {
                    static constexpr const char *NAME = "dl";
                    static const int INDEX = 2;
                };
            };

            Plugin(std::string &name, std::string &dl) : name{name}, dl{dl} {}

            // Get the value of name
            const std::string &getName() const {
                return name;
            }

            // Get the value of dl
            const std::string &getDl() const {
                return dl;
            }


            /**
            * Returns the table name 'plugin';
            */
            static const char *getDatabaseTableName() {
                return TABLE_NAME;
            }
        };
    }
}
#endif //INFORMATION_SCHEMA_CPP_PLUGIN_H