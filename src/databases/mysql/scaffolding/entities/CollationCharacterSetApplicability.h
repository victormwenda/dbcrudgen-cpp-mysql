//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_COLLATIONCHARACTERSETAPPLICABILITY_H
#define DBCRUDGEN_CPP_COLLATIONCHARACTERSETAPPLICABILITY_H

#include <string>

namespace dbcrudgen {
    namespace mysql {
        class CollationCharacterSetApplicability {

        private:
            std::string collationName;
            std::string characterSetName;

        public:

            static constexpr const char *TABLE_NAME = "COLLATION_CHARACTER_SET_APPLICABILITY";

            struct COLUMNS {
                struct COLLATION_NAME {
                    static constexpr const char *NAME = "COLLATION_NAME";
                    static const int INDEX = 1;
                };
                struct CHARACTER_SET_NAME {
                    static constexpr const char *NAME = "CHARACTER_SET_NAME";
                    static const int INDEX = 2;
                };
            };

            CollationCharacterSetApplicability(std::string &collationName, std::string &characterSetName)
                    : collationName{collationName}, characterSetName{characterSetName} {}

            // Get the value of collationName
            const std::string &getCollationName() const {
                return collationName;
            }

            // Get the value of characterSetName
            const std::string &getCharacterSetName() const {
                return characterSetName;
            }


            /**
            * Returns the table name 'COLLATION_CHARACTER_SET_APPLICABILITY';
            */
            static const char *getDatabaseTableName() {
                return TABLE_NAME;
            }
        };
    }
}

#endif //DBCRUDGEN_CPP_COLLATIONCHARACTERSETAPPLICABILITY_H
