#ifndef INFORMATION_SCHEMA_CPP_FUNC_H
#define INFORMATION_SCHEMA_CPP_FUNC_H

#include<string>

namespace dbcrudgen {
    namespace mysql {
        class Func {

        private:
            std::string name;
            int ret;
            std::string dl;
            std::string type;

        public:

            static constexpr const char *TABLE_NAME = "func";

            struct COLUMNS {
                struct NAME {
                    static constexpr const char *_NAME = "name";
                    static const int INDEX = 1;
                };
                struct RET {
                    static constexpr const char *NAME = "ret";
                    static const int INDEX = 2;
                };
                struct DL {
                    static constexpr const char *NAME = "dl";
                    static const int INDEX = 3;
                };
                struct TYPE {
                    static constexpr const char *NAME = "type";
                    static const int INDEX = 4;
                };
            };

            Func(std::string &name, int ret, std::string &dl, std::string &type)
                    : name{name}, ret{ret}, dl{dl}, type{type} {}

            // Get the value of name
            const std::string &getName() const {
                return name;
            }

            // Get the value of ret
            int getRet() const {
                return ret;
            }

            // Get the value of dl
            const std::string &getDl() const {
                return dl;
            }

            // Get the value of type
            const std::string &getType() const {
                return type;
            }


            /**
            * Returns the table name 'func';
            */
            static const char *getDatabaseTableName() {
                return TABLE_NAME;
            }
        };
    }
}
#endif //INFORMATION_SCHEMA_CPP_FUNC_H