//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_INNODBSYSVIRTUAL_H
#define DBCRUDGEN_CPP_INNODBSYSVIRTUAL_H

#include <string>

namespace dbcrudgen {
    namespace db {
        namespace mysql {
            class InnoDbSysVirtual {

            private:
                long tableId;
                int pos;
                int basePos;

            public:

                static constexpr const char *TABLE_NAME = "INNODB_SYS_VIRTUAL";

                struct COLUMNS {
                    struct TABLE_ID {
                        static constexpr const char *NAME = "TABLE_ID";
                        static const int INDEX = 1;
                    };
                    struct POS {
                        static constexpr const char *NAME = "POS";
                        static const int INDEX = 2;
                    };
                    struct BASE_POS {
                        static constexpr const char *NAME = "BASE_POS";
                        static const int INDEX = 3;
                    };
                };

                InnoDbSysVirtual(long tableId, int pos, int basePos) : tableId{tableId}, pos{pos}, basePos{basePos} {}

                // Get the value of tableId
                long getTableId() const {
                    return tableId;
                }

                // Get the value of pos
                int getPos() const {
                    return pos;
                }

                // Get the value of basePos
                int getBasePos() const {
                    return basePos;
                }

                /**
                * Returns the table name 'INNODB_SYS_VIRTUAL';
                */
                static const char *getDatabaseTableName() {
                    return TABLE_NAME;
                }
            };
        }
    }

}


#endif //DBCRUDGEN_CPP_INNODBSYSVIRTUAL_H
