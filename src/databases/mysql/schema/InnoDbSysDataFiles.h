//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_INNODBSYSDATAFILES_H
#define DBCRUDGEN_CPP_INNODBSYSDATAFILES_H

#include <string>

namespace dbcrudgen {
    namespace mysql {
        class InnoDbSysDataFiles {

        private:
            int space;
            std::string path;

        public:

            static constexpr const char *TABLE_NAME = "INNODB_SYS_DATAFILES";

            struct COLUMNS {
                struct SPACE {
                    static constexpr const char *NAME = "SPACE";
                    static const int INDEX = 1;
                };
                struct PATH {
                    static constexpr const char *NAME = "PATH";
                    static const int INDEX = 2;
                };
            };

            InnoDbSysDataFiles(int space, std::string &path) : space{space}, path{path} {}

            // Get the value of space
            int getSpace() const {
                return space;
            }

            // Get the value of path
            const std::string &getPath() const {
                return path;
            }

            /**
            * Returns the table name 'INNODB_SYS_DATAFILES';
            */
            static const char *getDatabaseTableName() {
                return TABLE_NAME;
            }
        };
    }
}


#endif //DBCRUDGEN_CPP_INNODBSYSDATAFILES_H
