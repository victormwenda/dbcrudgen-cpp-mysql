//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_INNODBFTINDEXCACHE_H
#define DBCRUDGEN_CPP_INNODBFTINDEXCACHE_H

#include <string>

namespace dbcrudgen {
    namespace db {
        namespace mysql {
            class InnoDbFtIndexCache {

            private:
                std::string word;
                long firstDocId;
                long lastDocId;
                long docCount;
                long docId;
                long position;

            public:

                static constexpr const char *TABLE_NAME = "INNODB_FT_INDEX_CACHE";

                struct COLUMNS {
                    struct WORD {
                        static constexpr const char *NAME = "WORD";
                        static const int INDEX = 1;
                    };
                    struct FIRST_DOC_ID {
                        static constexpr const char *NAME = "FIRST_DOC_ID";
                        static const int INDEX = 2;
                    };
                    struct LAST_DOC_ID {
                        static constexpr const char *NAME = "LAST_DOC_ID";
                        static const int INDEX = 3;
                    };
                    struct DOC_COUNT {
                        static constexpr const char *NAME = "DOC_COUNT";
                        static const int INDEX = 4;
                    };
                    struct DOC_ID {
                        static constexpr const char *NAME = "DOC_ID";
                        static const int INDEX = 5;
                    };
                    struct POSITION {
                        static constexpr const char *NAME = "POSITION";
                        static const int INDEX = 6;
                    };
                };

                InnoDbFtIndexCache(std::string &word, long firstDocId, long lastDocId, long docCount, long docId,
                                   long position) : word{word}, firstDocId{firstDocId}, lastDocId{lastDocId},
                                                    docCount{docCount}, docId{docId}, position{position} {}

                // Get the value of word
                const std::string &getWord() const {
                    return word;
                }

                // Get the value of firstDocId
                long getFirstDocId() const {
                    return firstDocId;
                }

                // Get the value of lastDocId
                long getLastDocId() const {
                    return lastDocId;
                }

                // Get the value of docCount
                long getDocCount() const {
                    return docCount;
                }

                // Get the value of docId
                long getDocId() const {
                    return docId;
                }

                // Get the value of position
                long getPosition() const {
                    return position;
                }


                /**
                * Returns the table name 'INNODB_FT_INDEX_CACHE';
                */
                static const char *getDatabaseTableName() {
                    return TABLE_NAME;
                }
            };
        }
    }

}


#endif //DBCRUDGEN_CPP_INNODBFTINDEXCACHE_H
