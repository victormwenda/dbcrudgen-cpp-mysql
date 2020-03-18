//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_INNODBSYSFOREIGNCOLS_H
#define DBCRUDGEN_CPP_INNODBSYSFOREIGNCOLS_H

#include <string>

namespace dbcrudgen {
    namespace mysql {
        class InnoDbSysForeignCols {

        private:
            std::string id;
            std::string forColName;
            std::string refColName;
            int pos;

        public:

            static constexpr const char *TABLE_NAME = "INNODB_SYS_FOREIGN_COLS";

            struct COLUMNS {
                struct ID {
                    static constexpr const char *NAME = "ID";
                    static const int INDEX = 1;
                };
                struct FOR_COL_NAME {
                    static constexpr const char *NAME = "FOR_COL_NAME";
                    static const int INDEX = 2;
                };
                struct REF_COL_NAME {
                    static constexpr const char *NAME = "REF_COL_NAME";
                    static const int INDEX = 3;
                };
                struct POS {
                    static constexpr const char *NAME = "POS";
                    static const int INDEX = 4;
                };
            };

            InnoDbSysForeignCols(std::string &id, std::string &forColName, std::string &refColName, int pos) :
                    id{id},
                    forColName{forColName},
                    refColName{refColName},
                    pos{pos} {}

            // Get the value of id
            const std::string &getId() const {
                return id;
            }

            // Get the value of forColName
            const std::string &getForColName() const {
                return forColName;
            }

            // Get the value of refColName
            const std::string &getRefColName() const {
                return refColName;
            }

            // Get the value of pos
            int getPos() const {
                return pos;
            }

            /**
            * Returns the table name 'INNODB_SYS_FOREIGN_COLS';
            */
            static const char *getDatabaseTableName() {
                return TABLE_NAME;
            }
        };
    }
}


#endif //DBCRUDGEN_CPP_INNODBSYSFOREIGNCOLS_H
