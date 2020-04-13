//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_INNODBSYSTABLESPACES_H
#define DBCRUDGEN_CPP_INNODBSYSTABLESPACES_H

#include <string>

namespace dbcrudgen {
    namespace db {
        namespace mysql {
            class InnoDbSysTableSpaces {

            private:
                int space;
                std::string name;
                int flag;
                std::string fileFormat;
                std::string rowFormat;
                int pageSize;
                int zipPageSize;
                std::string spaceType;
                int fsBlockSize;
                long fileSize;
                long allocatedSize;

            public:

                static constexpr const char *TABLE_NAME = "INNODB_SYS_TABLESPACES";

                struct COLUMNS {
                    struct SPACE {
                        static constexpr const char *NAME = "SPACE";
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
                    struct FILE_FORMAT {
                        static constexpr const char *NAME = "FILE_FORMAT";
                        static const int INDEX = 4;
                    };
                    struct ROW_FORMAT {
                        static constexpr const char *NAME = "ROW_FORMAT";
                        static const int INDEX = 5;
                    };
                    struct PAGE_SIZE {
                        static constexpr const char *NAME = "PAGE_SIZE";
                        static const int INDEX = 6;
                    };
                    struct ZIP_PAGE_SIZE {
                        static constexpr const char *NAME = "ZIP_PAGE_SIZE";
                        static const int INDEX = 7;
                    };
                    struct SPACE_TYPE {
                        static constexpr const char *NAME = "SPACE_TYPE";
                        static const int INDEX = 8;
                    };
                    struct FS_BLOCK_SIZE {
                        static constexpr const char *NAME = "FS_BLOCK_SIZE";
                        static const int INDEX = 9;
                    };
                    struct FILE_SIZE {
                        static constexpr const char *NAME = "FILE_SIZE";
                        static const int INDEX = 10;
                    };
                    struct ALLOCATED_SIZE {
                        static constexpr const char *NAME = "ALLOCATED_SIZE";
                        static const int INDEX = 11;
                    };
                };

                InnoDbSysTableSpaces(int space, std::string &name, int flag, std::string &fileFormat,
                                     std::string &rowFormat, int pageSize, int zipPageSize, std::string &spaceType,
                                     int fsBlockSize, long fileSize, long allocatedSize) : space{space}, name{name},
                                                                                           flag{flag},
                                                                                           fileFormat{fileFormat},
                                                                                           rowFormat{rowFormat},
                                                                                           pageSize{pageSize},
                                                                                           zipPageSize{zipPageSize},
                                                                                           spaceType{spaceType},
                                                                                           fsBlockSize{fsBlockSize},
                                                                                           fileSize{fileSize},
                                                                                           allocatedSize{
                                                                                                   allocatedSize} {}

                // Get the value of space
                int getSpace() const {
                    return space;
                }

                // Get the value of name
                const std::string &getName() const {
                    return name;
                }

                // Get the value of flag
                int getFlag() const {
                    return flag;
                }

                // Get the value of fileFormat
                const std::string &getFileFormat() const {
                    return fileFormat;
                }

                // Get the value of rowFormat
                const std::string &getRowFormat() const {
                    return rowFormat;
                }

                // Get the value of pageSize
                int getPageSize() const {
                    return pageSize;
                }

                // Get the value of zipPageSize
                int getZipPageSize() const {
                    return zipPageSize;
                }

                // Get the value of spaceType
                const std::string &getSpaceType() const {
                    return spaceType;
                }

                // Get the value of fsBlockSize
                int getFsBlockSize() const {
                    return fsBlockSize;
                }

                // Get the value of fileSize
                long getFileSize() const {
                    return fileSize;
                }

                // Get the value of allocatedSize
                long getAllocatedSize() const {
                    return allocatedSize;
                }


                /**
                * Returns the table name 'INNODB_SYS_TABLESPACES';
                */
                static const char *getDatabaseTableName() {
                    return TABLE_NAME;
                }
            };
        }
    }

}


#endif //DBCRUDGEN_CPP_INNODBSYSTABLESPACES_H
