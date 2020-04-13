//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_COLLATIONS_H
#define DBCRUDGEN_CPP_COLLATIONS_H

#include <string>

namespace dbcrudgen {
    namespace db {
        namespace mysql {

            class Collations {

            private:
                std::string collationName;
                std::string characterSetName;
                long id;
                std::string isDefault;
                std::string isCompiled;
                long sortlen;

            public:

                static constexpr const char *TABLE_NAME = "COLLATIONS";

                struct COLUMNS {
                    struct COLLATION_NAME {
                        static constexpr const char *NAME = "COLLATION_NAME";
                        static const int INDEX = 1;
                    };
                    struct CHARACTER_SET_NAME {
                        static constexpr const char *NAME = "CHARACTER_SET_NAME";
                        static const int INDEX = 2;
                    };
                    struct ID {
                        static constexpr const char *NAME = "ID";
                        static const int INDEX = 3;
                    };
                    struct IS_DEFAULT {
                        static constexpr const char *NAME = "IS_DEFAULT";
                        static const int INDEX = 4;
                    };
                    struct IS_COMPILED {
                        static constexpr const char *NAME = "IS_COMPILED";
                        static const int INDEX = 5;
                    };
                    struct SORTLEN {
                        static constexpr const char *NAME = "SORTLEN";
                        static const int INDEX = 6;
                    };
                };

                Collations(std::string &collationName, std::string &characterSetName, long id, std::string &isDefault,
                           std::string &isCompiled, long sortlen) : collationName{collationName},
                                                                    characterSetName{characterSetName}, id{id},
                                                                    isDefault{isDefault}, isCompiled{isCompiled},
                                                                    sortlen{sortlen} {}

                // Get the value of collationName
                const std::string &getCollationName() const {
                    return collationName;
                }

                // Get the value of characterSetName
                const std::string &getCharacterSetName() const {
                    return characterSetName;
                }

                // Get the value of id
                long getId() const {
                    return id;
                }

                // Get the value of isDefault
                const std::string &getIsDefault() const {
                    return isDefault;
                }

                // Get the value of isCompiled
                const std::string &getIsCompiled() const {
                    return isCompiled;
                }

                // Get the value of sortlen
                long getSortlen() const {
                    return sortlen;
                }

                /**
                * Returns the table name 'COLLATIONS';
                */
                static const char *getDatabaseTableName() {
                    return TABLE_NAME;
                }

            };

        }
    }

}


#endif //DBCRUDGEN_CPP_COLLATIONS_H
