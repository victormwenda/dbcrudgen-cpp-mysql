//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_INNODBSYSFIELDS_H
#define DBCRUDGEN_CPP_INNODBSYSFIELDS_H

#include <string>

namespace dbcrudgen {
    namespace db {
        namespace mysql {
            class InnoDbSysFields {

            private:
                long indexId;
                std::string name;
                int pos;

            public:

                static constexpr const char *TABLE_NAME = "INNODB_SYS_FIELDS";

                struct COLUMNS {
                    struct INDEX_ID {
                        static constexpr const char *NAME = "INDEX_ID";
                        static const int INDEX = 1;
                    };
                    struct NAME {
                        static constexpr const char *_NAME = "NAME";
                        static const int INDEX = 2;
                    };
                    struct POS {
                        static constexpr const char *NAME = "POS";
                        static const int INDEX = 3;
                    };
                };

                InnoDbSysFields(long indexId, std::string &name, int pos) : indexId{indexId}, name{name}, pos{pos} {}

                // Get the value of indexId
                long getIndexId() const {
                    return indexId;
                }

                // Get the value of name
                const std::string &getName() const {
                    return name;
                }

                // Get the value of pos
                int getPos() const {
                    return pos;
                }


                /**
                * Returns the table name 'INNODB_SYS_FIELDS';
                */
                static const char *getDatabaseTableName() {
                    return TABLE_NAME;
                }
            };

        }
    }

}


#endif //DBCRUDGEN_CPP_INNODBSYSFIELDS_H
