//
// Created by victor on 3/21/20.
//

#ifndef DBCRUDGEN_CPP_USER_H
#define DBCRUDGEN_CPP_USER_H

#include <string>

namespace dbcrudgen {
    namespace db {
        namespace generic {

            /**
             * A generic database user
             */
            class User {
            private:
                std::string username;
                std::string password;

            public:

                /**
                 * A generic database user
                 * @param username
                 * @param password
                 */
                User(std::string &username, std::string &password) : username(username), password(password) {}

                const std::string &getUsername() const {
                    return username;
                }

                void setUsername(const std::string &username) {
                    User::username = username;
                }

                const std::string &getPassword() const {
                    return password;
                }

                void setPassword(const std::string &password) {
                    User::password = password;
                }
            };
        }
    }

}
#endif //DBCRUDGEN_CPP_USER_H
