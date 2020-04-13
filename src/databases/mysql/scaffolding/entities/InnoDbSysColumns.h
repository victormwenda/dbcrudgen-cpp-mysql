//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_INNODBSYSCOLUMNS_H
#define DBCRUDGEN_CPP_INNODBSYSCOLUMNS_H

#include <string>

namespace dbcrudgen {
    namespace db {
        namespace mysql {
            class InnoDbSysColumns {

            private:
                long tableId;
                std::string name;
                long pos;
                int mtype;
                int prtype;
                int len;

            public:

                static constexpr const char *TABLE_NAME = "INNODB_SYS_COLUMNS";

                struct COLUMNS {
                    struct TABLE_ID {
                        static constexpr const char *NAME = "TABLE_ID";
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
                    struct MTYPE {
                        static constexpr const char *NAME = "MTYPE";
                        static const int INDEX = 4;
                    };
                    struct PRTYPE {
                        static constexpr const char *NAME = "PRTYPE";
                        static const int INDEX = 5;
                    };
                    struct LEN {
                        static constexpr const char *NAME = "LEN";
                        static const int INDEX = 6;
                    };
                };

                InnoDbSysColumns(long tableId, std::string &name, long pos, int mtype, int prtype, int len) : tableId{
                        tableId}, name{name}, pos{pos}, mtype{mtype}, prtype{prtype}, len{len} {}

                // Get the value of tableId
                long getTableId() const {
                    return tableId;
                }

                // Get the value of name
                const std::string &getName() const {
                    return name;
                }

                // Get the value of pos
                long getPos() const {
                    return pos;
                }

                // Get the value of mtype
                int getMtype() const {
                    return mtype;
                }

                // Get the value of prtype
                int getPrtype() const {
                    return prtype;
                }

                // Get the value of len
                int getLen() const {
                    return len;
                }

                /**
                * Returns the table name 'INNODB_SYS_COLUMNS';
                */
                static const char *getDatabaseTableName() {
                    return TABLE_NAME;
                }
            };
        }
    }

}


#endif //DBCRUDGEN_CPP_INNODBSYSCOLUMNS_H
