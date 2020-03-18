//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_INNODBSYSFOREIGN_H
#define DBCRUDGEN_CPP_INNODBSYSFOREIGN_H

#include <string>

namespace dbcrudgen {
    namespace mysql {
        class InnoDbSysForeign {

        private:
            std::string id;
            std::string forName;
            std::string refName;
            int nCols;
            int type;

        public:

            static constexpr const char *TABLE_NAME = "INNODB_SYS_FOREIGN";

            struct COLUMNS {
                struct ID {
                    static constexpr const char *NAME = "ID";
                    static const int INDEX = 1;
                };
                struct FOR_NAME {
                    static constexpr const char *NAME = "FOR_NAME";
                    static const int INDEX = 2;
                };
                struct REF_NAME {
                    static constexpr const char *NAME = "REF_NAME";
                    static const int INDEX = 3;
                };
                struct N_COLS {
                    static constexpr const char *NAME = "N_COLS";
                    static const int INDEX = 4;
                };
                struct TYPE {
                    static constexpr const char *NAME = "TYPE";
                    static const int INDEX = 5;
                };
            };

            InnoDbSysForeign(std::string &id, std::string &forName, std::string &refName, int nCols, int type) : id{id},
                                                                                                                 forName{forName},
                                                                                                                 refName{refName},
                                                                                                                 nCols{nCols},
                                                                                                                 type{type} {}

            // Get the value of id
            const std::string &getId() const {
                return id;
            }

            // Get the value of forName
            const std::string &getForName() const {
                return forName;
            }

            // Get the value of refName
            const std::string &getRefName() const {
                return refName;
            }

            // Get the value of nCols
            int getNCols() const {
                return nCols;
            }

            // Get the value of type
            int getType() const {
                return type;
            }

            /**
            * Returns the table name 'INNODB_SYS_FOREIGN';
            */
            static const char *getDatabaseTableName() {
                return TABLE_NAME;
            }
        };
    }
}


#endif //DBCRUDGEN_CPP_INNODBSYSFOREIGN_H
