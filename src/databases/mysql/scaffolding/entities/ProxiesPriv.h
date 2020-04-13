#ifndef INFORMATION_SCHEMA_CPP_PROXIES_PRIV_H
#define INFORMATION_SCHEMA_CPP_PROXIES_PRIV_H

#include<string>

namespace dbcrudgen {
    namespace db {
        namespace mysql {
            class ProxiesPriv {

            private:
                std::string host;
                std::string user;
                std::string proxiedHost;
                std::string proxiedUser;
                int withGrant;
                std::string grantor;
                std::string timestamp;

            public:

                static constexpr const char *TABLE_NAME = "proxies_priv";

                struct COLUMNS {
                    struct HOST {
                        static constexpr const char *NAME = "Host";
                        static const int INDEX = 1;
                    };
                    struct USER {
                        static constexpr const char *NAME = "User";
                        static const int INDEX = 2;
                    };
                    struct PROXIED_HOST {
                        static constexpr const char *NAME = "Proxied_host";
                        static const int INDEX = 3;
                    };
                    struct PROXIED_USER {
                        static constexpr const char *NAME = "Proxied_user";
                        static const int INDEX = 4;
                    };
                    struct WITH_GRANT {
                        static constexpr const char *NAME = "With_grant";
                        static const int INDEX = 5;
                    };
                    struct GRANTOR {
                        static constexpr const char *NAME = "Grantor";
                        static const int INDEX = 6;
                    };
                    struct TIMESTAMP {
                        static constexpr const char *NAME = "Timestamp";
                        static const int INDEX = 7;
                    };
                };

                ProxiesPriv(std::string &host, std::string &user, std::string &proxiedHost, std::string &proxiedUser,
                            int withGrant, std::string &grantor, std::string &timestamp)
                        : host{host}, user{user}, proxiedHost{proxiedHost}, proxiedUser{proxiedUser},
                          withGrant{withGrant},
                          grantor{grantor}, timestamp{timestamp} {}

                // Get the value of host
                const std::string &getHost() const {
                    return host;
                }

                // Get the value of user
                const std::string &getUser() const {
                    return user;
                }

                // Get the value of proxiedHost
                const std::string &getProxiedHost() const {
                    return proxiedHost;
                }

                // Get the value of proxiedUser
                const std::string &getProxiedUser() const {
                    return proxiedUser;
                }

                // Get the value of withGrant
                int getWithGrant() const {
                    return withGrant;
                }

                // Get the value of grantor
                const std::string &getGrantor() const {
                    return grantor;
                }

                // Get the value of timestamp
                const std::string &getTimestamp() const {
                    return timestamp;
                }


                /**
                * Returns the table name 'proxies_priv';
                */
                static const char *getDatabaseTableName() {
                    return TABLE_NAME;
                }
            };
        }
    }

}
#endif //INFORMATION_SCHEMA_CPP_PROXIES_PRIV_H