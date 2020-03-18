//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_INNODBFTBEINGDELETED_H
#define DBCRUDGEN_CPP_INNODBFTBEINGDELETED_H

#include <string>

namespace dbcrudgen {
    namespace mysql {
        class InnoDbFtBeingDeleted {

        private:
            long docId;

        public:

            static constexpr const char *TABLE_NAME = "INNODB_FT_BEING_DELETED";

            struct COLUMNS {
                struct DOC_ID {
                    static constexpr const char *NAME = "DOC_ID";
                    static const int INDEX = 1;
                };
            };

            InnoDbFtBeingDeleted(long docId) : docId{docId} {}

            // Get the value of docId
            long getDocId() const {
                return docId;
            }


            /**
            * Returns the table name 'INNODB_FT_BEING_DELETED';
            */
            static const char *getDatabaseTableName() {
                return TABLE_NAME;
            }
        };
    }
}


#endif //DBCRUDGEN_CPP_INNODBFTBEINGDELETED_H
