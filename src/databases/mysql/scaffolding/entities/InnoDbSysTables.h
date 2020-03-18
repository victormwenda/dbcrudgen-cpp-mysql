//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_INNODBSYSTABLES_H
#define DBCRUDGEN_CPP_INNODBSYSTABLES_H

#include <string>

namespace dbcrudgen {
    namespace mysql {
        class InnoDbSysTables {

        private:
            long tableId;
            std::string name;
            int flag;
            int nCols;
            int space;
            std::string fileFormat;
            std::string rowFormat;
            int zipPageSize;
            std::string spaceType;

        public:

            static constexpr const char *TABLE_NAME = "INNODB_SYS_TABLES";

            struct COLUMNS {
                struct TABLE_ID {
                    static constexpr const char *NAME = "TABLE_ID";
                    static const int INDEX = 1;
                };
                struct NAME {
                    static constexpr const char *_NAME = "NAME";
                    static const int INDEX = 2;
                };
                struct FLAG {
                    static constexpr const char *NAME = "FLAG";
                    static const int INDEX = 3;
                };
                struct N_COLS {
                    static constexpr const char *NAME = "N_COLS";
                    static const int INDEX = 4;
                };
                struct SPACE {
                    static constexpr const char *NAME = "SPACE";
                    static const int INDEX = 5;
                };
                struct FILE_FORMAT {
                    static constexpr const char *NAME = "FILE_FORMAT";
                    static const int INDEX = 6;
                };
                struct ROW_FORMAT {
                    static constexpr const char *NAME = "ROW_FORMAT";
                    static const int INDEX = 7;
                };
                struct ZIP_PAGE_SIZE {
                    static constexpr const char *NAME = "ZIP_PAGE_SIZE";
                    static const int INDEX = 8;
                };
                struct SPACE_TYPE {
                    static constexpr const char *NAME = "SPACE_TYPE";
                    static const int INDEX = 9;
                };
            };

            InnoDbSysTables(long tableId, std::string &name, int flag, int nCols, int space, std::string &fileFormat,
                            std::string &rowFormat, int zipPageSize, std::string &spaceType) : tableId{tableId},
                                                                                               name{name}, flag{flag},
                                                                                               nCols{nCols},
                                                                                               space{space},
                                                                                               fileFormat{fileFormat},
                                                                                               rowFormat{rowFormat},
                                                                                               zipPageSize{zipPageSize},
                                                                                               spaceType{spaceType} {}

            // Get the value of tableId
            long getTableId() const {
                return tableId;
            }

            // Get the value of name
            const std::string &getName() const {
                return name;
            }

            // Get the value of flag
            int getFlag() const {
                return flag;
            }

            // Get the value of nCols
            int getNCols() const {
                return nCols;
            }

            // Get the value of space
            int getSpace() const {
                return space;
            }

            // Get the value of fileFormat
            const std::string &getFileFormat() const {
                return fileFormat;
            }

            // Get the value of rowFormat
            const std::string &getRowFormat() const {
                return rowFormat;
            }

            // Get the value of zipPageSize
            int getZipPageSize() const {
                return zipPageSize;
            }

            // Get the value of spaceType
            const std::string &getSpaceType() const {
                return spaceType;
            }


            /**
            * Returns the table name 'INNODB_SYS_TABLES';
            */
            static const char *getDatabaseTableName() {
                return TABLE_NAME;
            }
        };
    }
}


#endif //DBCRUDGEN_CPP_INNODBSYSTABLES_H
