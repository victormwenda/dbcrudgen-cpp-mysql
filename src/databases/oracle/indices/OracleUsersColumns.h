//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 11/18/18.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_ORACLEUSERSCOLUMNS_H
#define DBCRUDGEN_CPP_ORACLEUSERSCOLUMNS_H

namespace dbcrudgen {
    namespace db {
        namespace oracle {
            //
            // OracleUsersColumns
            // //
            class OracleUsersColumns {

            public:
                struct USERNAME {
                    static const unsigned int INDEX = 1;
                };
                struct USERID {
                    static const unsigned int INDEX = 2;
                };
                struct CREATED {
                    static const unsigned int INDEX = 3;
                };
            };

        }
    }
}


#endif //DBCRUDGEN_CPP_ORACLEUSERSCOLUMNS_H
