//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_INNODBTEMPTABLEINFO_H
#define DBCRUDGEN_CPP_INNODBTEMPTABLEINFO_H

#include <string>

namespace dbcrudgen {
    namespace db {
        namespace mysql {
            class InnoDbTempTableInfo {

            private:
                long tableId;
                std::string name;
                int nCols;
                int space;
                std::string perTableTablespace;
                std::string isCompressed;

            public:

                static constexpr const char *TABLE_NAME = "INNODB_TEMP_TABLE_INFO";

                struct COLUMNS {
                    struct TABLE_ID {
                        static constexpr const char *NAME = "TABLE_ID";
                        static const int INDEX = 1;
                    };
                    struct NAME {
                        static constexpr const char *_NAME = "NAME";
                        static const int INDEX = 2;
                    };
                    struct N_COLS {
                        static constexpr const char *NAME = "N_COLS";
                        static const int INDEX = 3;
                    };
                    struct SPACE {
                        static constexpr const char *NAME = "SPACE";
                        static const int INDEX = 4;
                    };
                    struct PER_TABLE_TABLESPACE {
                        static constexpr const char *NAME = "PER_TABLE_TABLESPACE";
                        static const int INDEX = 5;
                    };
                    struct IS_COMPRESSED {
                        static constexpr const char *NAME = "IS_COMPRESSED";
                        static const int INDEX = 6;
                    };
                };

                InnoDbTempTableInfo(long tableId, std::string &name, int nCols, int space,
                                    std::string &perTableTablespace,
                                    std::string &isCompressed) : tableId{tableId}, name{name}, nCols{nCols},
                                                                 space{space},
                                                                 perTableTablespace{perTableTablespace},
                                                                 isCompressed{isCompressed} {}

                // Get the value of tableId
                long getTableId() const {
                    return tableId;
                }

                // Get the value of name
                const std::string &getName() const {
                    return name;
                }

                // Get the value of nCols
                int getNCols() const {
                    return nCols;
                }

                // Get the value of space
                int getSpace() const {
                    return space;
                }

                // Get the value of perTableTablespace
                const std::string &getPerTableTablespace() const {
                    return perTableTablespace;
                }

                // Get the value of isCompressed
                const std::string &getIsCompressed() const {
                    return isCompressed;
                }


                /**
                * Returns the table name 'INNODB_TEMP_TABLE_INFO';
                */
                static const char *getDatabaseTableName() {
                    return TABLE_NAME;
                }
            };
        }
    }

}


#endif //DBCRUDGEN_CPP_INNODBTEMPTABLEINFO_H
