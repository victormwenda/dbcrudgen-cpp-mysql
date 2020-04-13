//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_TABLESPACES_H
#define DBCRUDGEN_CPP_TABLESPACES_H

#include <string>

namespace dbcrudgen {
    namespace db {
        namespace mysql {
            class TableSpaces {

            private:
                std::string tablespaceName;
                std::string engine;
                std::string tablespaceType;
                std::string logfileGroupName;
                long extentSize;
                long autoextendSize;
                long maximumSize;
                long nodegroupId;
                std::string tablespaceComment;

            public:

                static constexpr const char *TABLE_NAME = "TABLESPACES";

                struct COLUMNS {
                    struct TABLESPACE_NAME {
                        static constexpr const char *NAME = "TABLESPACE_NAME";
                        static const int INDEX = 1;
                    };
                    struct ENGINE {
                        static constexpr const char *NAME = "ENGINE";
                        static const int INDEX = 2;
                    };
                    struct TABLESPACE_TYPE {
                        static constexpr const char *NAME = "TABLESPACE_TYPE";
                        static const int INDEX = 3;
                    };
                    struct LOGFILE_GROUP_NAME {
                        static constexpr const char *NAME = "LOGFILE_GROUP_NAME";
                        static const int INDEX = 4;
                    };
                    struct EXTENT_SIZE {
                        static constexpr const char *NAME = "EXTENT_SIZE";
                        static const int INDEX = 5;
                    };
                    struct AUTOEXTEND_SIZE {
                        static constexpr const char *NAME = "AUTOEXTEND_SIZE";
                        static const int INDEX = 6;
                    };
                    struct MAXIMUM_SIZE {
                        static constexpr const char *NAME = "MAXIMUM_SIZE";
                        static const int INDEX = 7;
                    };
                    struct NODEGROUP_ID {
                        static constexpr const char *NAME = "NODEGROUP_ID";
                        static const int INDEX = 8;
                    };
                    struct TABLESPACE_COMMENT {
                        static constexpr const char *NAME = "TABLESPACE_COMMENT";
                        static const int INDEX = 9;
                    };
                };

                TableSpaces(std::string &tablespaceName, std::string &engine, std::string &tablespaceType,
                            std::string &logfileGroupName, long extentSize, long autoextendSize, long maximumSize,
                            long nodegroupId, std::string &tablespaceComment)
                        : tablespaceName{tablespaceName},
                          engine{engine},
                          tablespaceType{tablespaceType},
                          logfileGroupName{logfileGroupName},
                          extentSize{extentSize},
                          autoextendSize{autoextendSize},
                          maximumSize{maximumSize},
                          nodegroupId{nodegroupId},
                          tablespaceComment{tablespaceComment} {}

                // Get the value of tablespaceName
                const std::string &getTablespaceName() const {
                    return tablespaceName;
                }

                // Get the value of engine
                const std::string &getEngine() const {
                    return engine;
                }

                // Get the value of tablespaceType
                const std::string &getTablespaceType() const {
                    return tablespaceType;
                }

                // Get the value of logfileGroupName
                const std::string &getLogfileGroupName() const {
                    return logfileGroupName;
                }

                // Get the value of extentSize
                long getExtentSize() const {
                    return extentSize;
                }

                // Get the value of autoextendSize
                long getAutoextendSize() const {
                    return autoextendSize;
                }

                // Get the value of maximumSize
                long getMaximumSize() const {
                    return maximumSize;
                }

                // Get the value of nodegroupId
                long getNodegroupId() const {
                    return nodegroupId;
                }

                // Get the value of tablespaceComment
                const std::string &getTablespaceComment() const {
                    return tablespaceComment;
                }

                /**
                * Returns the table name 'TABLESPACES';
                */
                static const char *getDatabaseTableName() {
                    return TABLE_NAME;
                }
            };

        }
    }

}


#endif //DBCRUDGEN_CPP_TABLESPACES_H
