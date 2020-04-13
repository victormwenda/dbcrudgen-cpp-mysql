#ifndef INFORMATION_SCHEMA_CPP_NDB_BINLOG_INDEX_H
#define INFORMATION_SCHEMA_CPP_NDB_BINLOG_INDEX_H

#include<string>

namespace dbcrudgen {
    namespace db {
        namespace mysql {
            class NdbBinlogIndex {

            private:
                long position;
                std::string file;
                long epoch;
                int inserts;
                int updates;
                int deletes;
                int schemaops;
                int origServerId;
                long origEpoch;
                int gci;
                long nextPosition;
                std::string nextFile;

            public:

                static constexpr const char *TABLE_NAME = "ndb_binlog_index";

                struct COLUMNS {
                    struct POSITION {
                        static constexpr const char *NAME = "Position";
                        static const int INDEX = 1;
                    };
                    struct FILE {
                        static constexpr const char *NAME = "File";
                        static const int INDEX = 2;
                    };
                    struct EPOCH {
                        static constexpr const char *NAME = "epoch";
                        static const int INDEX = 3;
                    };
                    struct INSERTS {
                        static constexpr const char *NAME = "inserts";
                        static const int INDEX = 4;
                    };
                    struct UPDATES {
                        static constexpr const char *NAME = "updates";
                        static const int INDEX = 5;
                    };
                    struct DELETES {
                        static constexpr const char *NAME = "deletes";
                        static const int INDEX = 6;
                    };
                    struct SCHEMAOPS {
                        static constexpr const char *NAME = "schemaops";
                        static const int INDEX = 7;
                    };
                    struct ORIG_SERVER_ID {
                        static constexpr const char *NAME = "orig_server_id";
                        static const int INDEX = 8;
                    };
                    struct ORIG_EPOCH {
                        static constexpr const char *NAME = "orig_epoch";
                        static const int INDEX = 9;
                    };
                    struct GCI {
                        static constexpr const char *NAME = "gci";
                        static const int INDEX = 10;
                    };
                    struct NEXT_POSITION {
                        static constexpr const char *NAME = "next_position";
                        static const int INDEX = 11;
                    };
                    struct NEXT_FILE {
                        static constexpr const char *NAME = "next_file";
                        static const int INDEX = 12;
                    };
                };

                NdbBinlogIndex(long position, std::string &file, long epoch, int inserts, int updates, int deletes,
                               int schemaops, int origServerId, long origEpoch, int gci, long nextPosition,
                               std::string &nextFile)
                        : position{position}, file{file}, epoch{epoch}, inserts{inserts}, updates{updates},
                          deletes{deletes}, schemaops{schemaops}, origServerId{origServerId}, origEpoch{origEpoch},
                          gci{gci}, nextPosition{nextPosition}, nextFile{nextFile} {}

                // Get the value of position
                long getPosition() const {
                    return position;
                }

                // Get the value of file
                const std::string &getFile() const {
                    return file;
                }

                // Get the value of epoch
                long getEpoch() const {
                    return epoch;
                }

                // Get the value of inserts
                int getInserts() const {
                    return inserts;
                }

                // Get the value of updates
                int getUpdates() const {
                    return updates;
                }

                // Get the value of deletes
                int getDeletes() const {
                    return deletes;
                }

                // Get the value of schemaops
                int getSchemaops() const {
                    return schemaops;
                }

                // Get the value of origServerId
                int getOrigServerId() const {
                    return origServerId;
                }

                // Get the value of origEpoch
                long getOrigEpoch() const {
                    return origEpoch;
                }

                // Get the value of gci
                int getGci() const {
                    return gci;
                }

                // Get the value of nextPosition
                long getNextPosition() const {
                    return nextPosition;
                }

                // Get the value of nextFile
                const std::string &getNextFile() const {
                    return nextFile;
                }


                /**
                * Returns the table name 'ndb_binlog_index';
                */
                static const char *getDatabaseTableName() {
                    return TABLE_NAME;
                }
            };
        }
    }

}
#endif //INFORMATION_SCHEMA_CPP_NDB_BINLOG_INDEX_H