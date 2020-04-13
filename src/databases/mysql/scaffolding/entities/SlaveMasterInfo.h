#ifndef INFORMATION_SCHEMA_CPP_SLAVE_MASTER_INFO_H
#define INFORMATION_SCHEMA_CPP_SLAVE_MASTER_INFO_H

#include<string>

namespace dbcrudgen {
    namespace db {
        namespace mysql {
            class SlaveMasterInfo {

            private:
                int numberOfLines;
                std::string masterLogName;
                long masterLogPos;
                std::string host;
                std::string userName;
                std::string userPassword;
                int port;
                int connectRetry;
                int enabledSsl;
                std::string sslCa;
                std::string sslCapath;
                std::string sslCert;
                std::string sslCipher;
                std::string sslKey;
                int sslVerifyServerCert;
                long double heartbeat;
                std::string bind;
                std::string ignoredServerIds;
                std::string uuid;
                long retryCount;
                std::string sslCrl;
                std::string sslCrlpath;
                int enabledAutoPosition;
                std::string channelName;
                std::string tlsVersion;

            public:

                static constexpr const char *TABLE_NAME = "slave_master_info";

                struct COLUMNS {
                    struct NUMBER_OF_LINES {
                        static constexpr const char *NAME = "Number_of_lines";
                        static const int INDEX = 1;
                    };
                    struct MASTER_LOG_NAME {
                        static constexpr const char *NAME = "Master_log_name";
                        static const int INDEX = 2;
                    };
                    struct MASTER_LOG_POS {
                        static constexpr const char *NAME = "Master_log_pos";
                        static const int INDEX = 3;
                    };
                    struct HOST {
                        static constexpr const char *NAME = "Host";
                        static const int INDEX = 4;
                    };
                    struct USER_NAME {
                        static constexpr const char *NAME = "User_name";
                        static const int INDEX = 5;
                    };
                    struct USER_PASSWORD {
                        static constexpr const char *NAME = "User_password";
                        static const int INDEX = 6;
                    };
                    struct PORT {
                        static constexpr const char *NAME = "Port";
                        static const int INDEX = 7;
                    };
                    struct CONNECT_RETRY {
                        static constexpr const char *NAME = "Connect_retry";
                        static const int INDEX = 8;
                    };
                    struct ENABLED_SSL {
                        static constexpr const char *NAME = "Enabled_ssl";
                        static const int INDEX = 9;
                    };
                    struct SSL_CA {
                        static constexpr const char *NAME = "Ssl_ca";
                        static const int INDEX = 10;
                    };
                    struct SSL_CAPATH {
                        static constexpr const char *NAME = "Ssl_capath";
                        static const int INDEX = 11;
                    };
                    struct SSL_CERT {
                        static constexpr const char *NAME = "Ssl_cert";
                        static const int INDEX = 12;
                    };
                    struct SSL_CIPHER {
                        static constexpr const char *NAME = "Ssl_cipher";
                        static const int INDEX = 13;
                    };
                    struct SSL_KEY {
                        static constexpr const char *NAME = "Ssl_key";
                        static const int INDEX = 14;
                    };
                    struct SSL_VERIFY_SERVER_CERT {
                        static constexpr const char *NAME = "Ssl_verify_server_cert";
                        static const int INDEX = 15;
                    };
                    struct HEARTBEAT {
                        static constexpr const char *NAME = "Heartbeat";
                        static const int INDEX = 16;
                    };
                    struct BIND {
                        static constexpr const char *NAME = "Bind";
                        static const int INDEX = 17;
                    };
                    struct IGNORED_SERVER_IDS {
                        static constexpr const char *NAME = "Ignored_server_ids";
                        static const int INDEX = 18;
                    };
                    struct UUID {
                        static constexpr const char *NAME = "Uuid";
                        static const int INDEX = 19;
                    };
                    struct RETRY_COUNT {
                        static constexpr const char *NAME = "Retry_count";
                        static const int INDEX = 20;
                    };
                    struct SSL_CRL {
                        static constexpr const char *NAME = "Ssl_crl";
                        static const int INDEX = 21;
                    };
                    struct SSL_CRLPATH {
                        static constexpr const char *NAME = "Ssl_crlpath";
                        static const int INDEX = 22;
                    };
                    struct ENABLED_AUTO_POSITION {
                        static constexpr const char *NAME = "Enabled_auto_position";
                        static const int INDEX = 23;
                    };
                    struct CHANNEL_NAME {
                        static constexpr const char *NAME = "Channel_name";
                        static const int INDEX = 24;
                    };
                    struct TLS_VERSION {
                        static constexpr const char *NAME = "Tls_version";
                        static const int INDEX = 25;
                    };
                };

                SlaveMasterInfo(int numberOfLines, std::string &masterLogName, long masterLogPos, std::string &host,
                                std::string &userName, std::string &userPassword, int port, int connectRetry,
                                int enabledSsl, std::string &sslCa, std::string &sslCapath, std::string &sslCert,
                                std::string &sslCipher, std::string &sslKey, int sslVerifyServerCert,
                                long double heartbeat,
                                std::string &bind, std::string &ignoredServerIds, std::string &uuid, long retryCount,
                                std::string &sslCrl, std::string &sslCrlpath, int enabledAutoPosition,
                                std::string &channelName, std::string &tlsVersion)
                        : numberOfLines{numberOfLines}, masterLogName{masterLogName}, masterLogPos{masterLogPos},
                          host{host}, userName{userName}, userPassword{userPassword}, port{port},
                          connectRetry{connectRetry}, enabledSsl{enabledSsl}, sslCa{sslCa}, sslCapath{sslCapath},
                          sslCert{sslCert}, sslCipher{sslCipher}, sslKey{sslKey},
                          sslVerifyServerCert{sslVerifyServerCert},
                          heartbeat{heartbeat}, bind{bind}, ignoredServerIds{ignoredServerIds}, uuid{uuid},
                          retryCount{retryCount}, sslCrl{sslCrl}, sslCrlpath{sslCrlpath},
                          enabledAutoPosition{enabledAutoPosition}, channelName{channelName}, tlsVersion{tlsVersion} {}

                // Get the value of numberOfLines
                int getNumberOfLines() const {
                    return numberOfLines;
                }

                // Get the value of masterLogName
                const std::string &getMasterLogName() const {
                    return masterLogName;
                }

                // Get the value of masterLogPos
                long getMasterLogPos() const {
                    return masterLogPos;
                }

                // Get the value of host
                const std::string &getHost() const {
                    return host;
                }

                // Get the value of userName
                const std::string &getUserName() const {
                    return userName;
                }

                // Get the value of userPassword
                const std::string &getUserPassword() const {
                    return userPassword;
                }

                // Get the value of port
                int getPort() const {
                    return port;
                }

                // Get the value of connectRetry
                int getConnectRetry() const {
                    return connectRetry;
                }

                // Get the value of enabledSsl
                int getEnabledSsl() const {
                    return enabledSsl;
                }

                // Get the value of sslCa
                const std::string &getSslCa() const {
                    return sslCa;
                }

                // Get the value of sslCapath
                const std::string &getSslCapath() const {
                    return sslCapath;
                }

                // Get the value of sslCert
                const std::string &getSslCert() const {
                    return sslCert;
                }

                // Get the value of sslCipher
                const std::string &getSslCipher() const {
                    return sslCipher;
                }

                // Get the value of sslKey
                const std::string &getSslKey() const {
                    return sslKey;
                }

                // Get the value of sslVerifyServerCert
                int getSslVerifyServerCert() const {
                    return sslVerifyServerCert;
                }

                // Get the value of heartbeat
                long double getHeartbeat() const {
                    return heartbeat;
                }

                // Get the value of bind
                const std::string &getBind() const {
                    return bind;
                }

                // Get the value of ignoredServerIds
                const std::string &getIgnoredServerIds() const {
                    return ignoredServerIds;
                }

                // Get the value of uuid
                const std::string &getUuid() const {
                    return uuid;
                }

                // Get the value of retryCount
                long getRetryCount() const {
                    return retryCount;
                }

                // Get the value of sslCrl
                const std::string &getSslCrl() const {
                    return sslCrl;
                }

                // Get the value of sslCrlpath
                const std::string &getSslCrlpath() const {
                    return sslCrlpath;
                }

                // Get the value of enabledAutoPosition
                int getEnabledAutoPosition() const {
                    return enabledAutoPosition;
                }

                // Get the value of channelName
                const std::string &getChannelName() const {
                    return channelName;
                }

                // Get the value of tlsVersion
                const std::string &getTlsVersion() const {
                    return tlsVersion;
                }


                /**
                * Returns the table name 'slave_master_info';
                */
                static const char *getDatabaseTableName() {
                    return TABLE_NAME;
                }
            };
        }
    }

}
#endif //INFORMATION_SCHEMA_CPP_SLAVE_MASTER_INFO_H