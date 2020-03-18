//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_CHARACTERSETS_H
#define DBCRUDGEN_CPP_CHARACTERSETS_H

#include <string>

namespace dbcrudgen {
    namespace mysql {
        class CharacterSets {

        private:
            std::string characterSetName;
            std::string defaultCollateName;
            std::string description;
            long maxlen;

        public:

            static constexpr const char *TABLE_NAME = "CHARACTER_SETS";

            struct COLUMNS {
                struct CHARACTER_SET_NAME {
                    static constexpr const char *NAME = "CHARACTER_SET_NAME";
                    static const int INDEX = 1;
                };
                struct DEFAULT_COLLATE_NAME {
                    static constexpr const char *NAME = "DEFAULT_COLLATE_NAME";
                    static const int INDEX = 2;
                };
                struct DESCRIPTION {
                    static constexpr const char *NAME = "DESCRIPTION";
                    static const int INDEX = 3;
                };
                struct MAXLEN {
                    static constexpr const char *NAME = "MAXLEN";
                    static const int INDEX = 4;
                };
            };

            CharacterSets(std::string &characterSetName, std::string &defaultCollateName, std::string &description,
                          long maxlen) : characterSetName{characterSetName}, defaultCollateName{defaultCollateName},
                                         description{description}, maxlen{maxlen} {}

            // Get the value of characterSetName
            const std::string &getCharacterSetName() const {
                return characterSetName;
            }

            // Get the value of defaultCollateName
            const std::string &getDefaultCollateName() const {
                return defaultCollateName;
            }

            // Get the value of description
            const std::string &getdescription() const {
                return description;
            }

            // Get the value of maxlen
            const long &getmaxlen() const {
                return maxlen;
            }


            /**
            * Returns the table name 'CHARACTER_SETS';
            */
            static const char *getDatabaseTableName() {
                return TABLE_NAME;
            }
        };
    }
}

#endif //DBCRUDGEN_CPP_CHARACTERSETS_H
