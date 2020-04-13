#ifndef INFORMATION_SCHEMA_CPP_USER_H
#define INFORMATION_SCHEMA_CPP_USER_H

#include<string>

namespace dbcrudgen {
    namespace db {
        namespace mysql {
            class User {

            private:
                std::string host;
                std::string user;
                std::string selectPriv;
                std::string insertPriv;
                std::string updatePriv;
                std::string deletePriv;
                std::string createPriv;
                std::string dropPriv;
                std::string reloadPriv;
                std::string shutdownPriv;
                std::string processPriv;
                std::string filePriv;
                std::string grantPriv;
                std::string referencesPriv;
                std::string indexPriv;
                std::string alterPriv;
                std::string showDbPriv;
                std::string superPriv;
                std::string createTmpTablePriv;
                std::string lockTablesPriv;
                std::string executePriv;
                std::string replSlavePriv;
                std::string replClientPriv;
                std::string createViewPriv;
                std::string showViewPriv;
                std::string createRoutinePriv;
                std::string alterRoutinePriv;
                std::string createUserPriv;
                std::string eventPriv;
                std::string triggerPriv;
                std::string createTablespacePriv;
                std::string sslType;
                std::string sslCipher;
                std::string x509Issuer;
                std::string x509Subject;
                int maxQuestions;
                int maxUpdates;
                int maxConnections;
                int maxUserConnections;
                std::string plugin;
                std::string authenticationString;
                std::string passwordExpired;
                std::string passwordLastChanged;
                int passwordLifetime;
                std::string accountLocked;

            public:

                static constexpr const char *TABLE_NAME = "user";

                struct COLUMNS {
                    struct HOST {
                        static constexpr const char *NAME = "Host";
                        static const int INDEX = 1;
                    };
                    struct USER {
                        static constexpr const char *NAME = "User";
                        static const int INDEX = 2;
                    };
                    struct SELECT_PRIV {
                        static constexpr const char *NAME = "Select_priv";
                        static const int INDEX = 3;
                    };
                    struct INSERT_PRIV {
                        static constexpr const char *NAME = "Insert_priv";
                        static const int INDEX = 4;
                    };
                    struct UPDATE_PRIV {
                        static constexpr const char *NAME = "Update_priv";
                        static const int INDEX = 5;
                    };
                    struct DELETE_PRIV {
                        static constexpr const char *NAME = "Delete_priv";
                        static const int INDEX = 6;
                    };
                    struct CREATE_PRIV {
                        static constexpr const char *NAME = "Create_priv";
                        static const int INDEX = 7;
                    };
                    struct DROP_PRIV {
                        static constexpr const char *NAME = "Drop_priv";
                        static const int INDEX = 8;
                    };
                    struct RELOAD_PRIV {
                        static constexpr const char *NAME = "Reload_priv";
                        static const int INDEX = 9;
                    };
                    struct SHUTDOWN_PRIV {
                        static constexpr const char *NAME = "Shutdown_priv";
                        static const int INDEX = 10;
                    };
                    struct PROCESS_PRIV {
                        static constexpr const char *NAME = "Process_priv";
                        static const int INDEX = 11;
                    };
                    struct FILE_PRIV {
                        static constexpr const char *NAME = "File_priv";
                        static const int INDEX = 12;
                    };
                    struct GRANT_PRIV {
                        static constexpr const char *NAME = "Grant_priv";
                        static const int INDEX = 13;
                    };
                    struct REFERENCES_PRIV {
                        static constexpr const char *NAME = "References_priv";
                        static const int INDEX = 14;
                    };
                    struct INDEX_PRIV {
                        static constexpr const char *NAME = "Index_priv";
                        static const int INDEX = 15;
                    };
                    struct ALTER_PRIV {
                        static constexpr const char *NAME = "Alter_priv";
                        static const int INDEX = 16;
                    };
                    struct SHOW_DB_PRIV {
                        static constexpr const char *NAME = "Show_db_priv";
                        static const int INDEX = 17;
                    };
                    struct SUPER_PRIV {
                        static constexpr const char *NAME = "Super_priv";
                        static const int INDEX = 18;
                    };
                    struct CREATE_TMP_TABLE_PRIV {
                        static constexpr const char *NAME = "Create_tmp_table_priv";
                        static const int INDEX = 19;
                    };
                    struct LOCK_TABLES_PRIV {
                        static constexpr const char *NAME = "Lock_tables_priv";
                        static const int INDEX = 20;
                    };
                    struct EXECUTE_PRIV {
                        static constexpr const char *NAME = "Execute_priv";
                        static const int INDEX = 21;
                    };
                    struct REPL_SLAVE_PRIV {
                        static constexpr const char *NAME = "Repl_slave_priv";
                        static const int INDEX = 22;
                    };
                    struct REPL_CLIENT_PRIV {
                        static constexpr const char *NAME = "Repl_client_priv";
                        static const int INDEX = 23;
                    };
                    struct CREATE_VIEW_PRIV {
                        static constexpr const char *NAME = "Create_view_priv";
                        static const int INDEX = 24;
                    };
                    struct SHOW_VIEW_PRIV {
                        static constexpr const char *NAME = "Show_view_priv";
                        static const int INDEX = 25;
                    };
                    struct CREATE_ROUTINE_PRIV {
                        static constexpr const char *NAME = "Create_routine_priv";
                        static const int INDEX = 26;
                    };
                    struct ALTER_ROUTINE_PRIV {
                        static constexpr const char *NAME = "Alter_routine_priv";
                        static const int INDEX = 27;
                    };
                    struct CREATE_USER_PRIV {
                        static constexpr const char *NAME = "Create_user_priv";
                        static const int INDEX = 28;
                    };
                    struct EVENT_PRIV {
                        static constexpr const char *NAME = "Event_priv";
                        static const int INDEX = 29;
                    };
                    struct TRIGGER_PRIV {
                        static constexpr const char *NAME = "Trigger_priv";
                        static const int INDEX = 30;
                    };
                    struct CREATE_TABLESPACE_PRIV {
                        static constexpr const char *NAME = "Create_tablespace_priv";
                        static const int INDEX = 31;
                    };
                    struct SSL_TYPE {
                        static constexpr const char *NAME = "ssl_type";
                        static const int INDEX = 32;
                    };
                    struct SSL_CIPHER {
                        static constexpr const char *NAME = "ssl_cipher";
                        static const int INDEX = 33;
                    };
                    struct X509_ISSUER {
                        static constexpr const char *NAME = "x509_issuer";
                        static const int INDEX = 34;
                    };
                    struct X509_SUBJECT {
                        static constexpr const char *NAME = "x509_subject";
                        static const int INDEX = 35;
                    };
                    struct MAX_QUESTIONS {
                        static constexpr const char *NAME = "max_questions";
                        static const int INDEX = 36;
                    };
                    struct MAX_UPDATES {
                        static constexpr const char *NAME = "max_updates";
                        static const int INDEX = 37;
                    };
                    struct MAX_CONNECTIONS {
                        static constexpr const char *NAME = "max_connections";
                        static const int INDEX = 38;
                    };
                    struct MAX_USER_CONNECTIONS {
                        static constexpr const char *NAME = "max_user_connections";
                        static const int INDEX = 39;
                    };
                    struct PLUGIN {
                        static constexpr const char *NAME = "plugin";
                        static const int INDEX = 40;
                    };
                    struct AUTHENTICATION_STRING {
                        static constexpr const char *NAME = "authentication_string";
                        static const int INDEX = 41;
                    };
                    struct PASSWORD_EXPIRED {
                        static constexpr const char *NAME = "password_expired";
                        static const int INDEX = 42;
                    };
                    struct PASSWORD_LAST_CHANGED {
                        static constexpr const char *NAME = "password_last_changed";
                        static const int INDEX = 43;
                    };
                    struct PASSWORD_LIFETIME {
                        static constexpr const char *NAME = "password_lifetime";
                        static const int INDEX = 44;
                    };
                    struct ACCOUNT_LOCKED {
                        static constexpr const char *NAME = "account_locked";
                        static const int INDEX = 45;
                    };
                };

                User(std::string &host, std::string &user, std::string &selectPriv, std::string &insertPriv,
                     std::string &updatePriv, std::string &deletePriv, std::string &createPriv, std::string &dropPriv,
                     std::string &reloadPriv, std::string &shutdownPriv, std::string &processPriv, std::string &filePriv,
                     std::string &grantPriv, std::string &referencesPriv, std::string &indexPriv, std::string &alterPriv,
                     std::string &showDbPriv, std::string &superPriv, std::string &createTmpTablePriv,
                     std::string &lockTablesPriv, std::string &executePriv, std::string &replSlavePriv,
                     std::string &replClientPriv, std::string &createViewPriv, std::string &showViewPriv,
                     std::string &createRoutinePriv, std::string &alterRoutinePriv, std::string &createUserPriv,
                     std::string &eventPriv, std::string &triggerPriv, std::string &createTablespacePriv,
                     std::string &sslType, std::string &sslCipher, std::string &x509Issuer, std::string &x509Subject,
                     int maxQuestions, int maxUpdates, int maxConnections, int maxUserConnections, std::string &plugin,
                     std::string &authenticationString, std::string &passwordExpired, std::string &passwordLastChanged,
                     int passwordLifetime, std::string &accountLocked)
                        : host{host}, user{user}, selectPriv{selectPriv},
                          insertPriv{insertPriv}, updatePriv{updatePriv},
                          deletePriv{deletePriv}, createPriv{createPriv},
                          dropPriv{dropPriv}, reloadPriv{reloadPriv},
                          shutdownPriv{shutdownPriv},
                          processPriv{processPriv}, filePriv{filePriv},
                          grantPriv{grantPriv},
                          referencesPriv{referencesPriv},
                          indexPriv{indexPriv}, alterPriv{alterPriv},
                          showDbPriv{showDbPriv}, superPriv{superPriv},
                          createTmpTablePriv{createTmpTablePriv},
                          lockTablesPriv{lockTablesPriv},
                          executePriv{executePriv},
                          replSlavePriv{replSlavePriv},
                          replClientPriv{replClientPriv},
                          createViewPriv{createViewPriv},
                          showViewPriv{showViewPriv},
                          createRoutinePriv{createRoutinePriv},
                          alterRoutinePriv{alterRoutinePriv},
                          createUserPriv{createUserPriv},
                          eventPriv{eventPriv}, triggerPriv{triggerPriv},
                          createTablespacePriv{createTablespacePriv},
                          sslType{sslType}, sslCipher{sslCipher},
                          x509Issuer{x509Issuer}, x509Subject{x509Subject},
                          maxQuestions{maxQuestions}, maxUpdates{maxUpdates},
                          maxConnections{maxConnections},
                          maxUserConnections{maxUserConnections},
                          plugin{plugin},
                          authenticationString{authenticationString},
                          passwordExpired{passwordExpired},
                          passwordLastChanged{passwordLastChanged},
                          passwordLifetime{passwordLifetime},
                          accountLocked{accountLocked} {}

                // Get the value of host
                const std::string &getHost() const {
                    return host;
                }

                // Get the value of user
                const std::string &getUser() const {
                    return user;
                }

                // Get the value of selectPriv
                const std::string &getSelectPriv() const {
                    return selectPriv;
                }

                // Get the value of insertPriv
                const std::string &getInsertPriv() const {
                    return insertPriv;
                }

                // Get the value of updatePriv
                const std::string &getUpdatePriv() const {
                    return updatePriv;
                }

                // Get the value of deletePriv
                const std::string &getDeletePriv() const {
                    return deletePriv;
                }

                // Get the value of createPriv
                const std::string &getCreatePriv() const {
                    return createPriv;
                }

                // Get the value of dropPriv
                const std::string &getDropPriv() const {
                    return dropPriv;
                }

                // Get the value of reloadPriv
                const std::string &getReloadPriv() const {
                    return reloadPriv;
                }

                // Get the value of shutdownPriv
                const std::string &getShutdownPriv() const {
                    return shutdownPriv;
                }

                // Get the value of processPriv
                const std::string &getProcessPriv() const {
                    return processPriv;
                }

                // Get the value of filePriv
                const std::string &getFilePriv() const {
                    return filePriv;
                }

                // Get the value of grantPriv
                const std::string &getGrantPriv() const {
                    return grantPriv;
                }

                // Get the value of referencesPriv
                const std::string &getReferencesPriv() const {
                    return referencesPriv;
                }

                // Get the value of indexPriv
                const std::string &getIndexPriv() const {
                    return indexPriv;
                }

                // Get the value of alterPriv
                const std::string &getAlterPriv() const {
                    return alterPriv;
                }

                // Get the value of showDbPriv
                const std::string &getShowDbPriv() const {
                    return showDbPriv;
                }

                // Get the value of superPriv
                const std::string &getSuperPriv() const {
                    return superPriv;
                }

                // Get the value of createTmpTablePriv
                const std::string &getCreateTmpTablePriv() const {
                    return createTmpTablePriv;
                }

                // Get the value of lockTablesPriv
                const std::string &getLockTablesPriv() const {
                    return lockTablesPriv;
                }

                // Get the value of executePriv
                const std::string &getExecutePriv() const {
                    return executePriv;
                }

                // Get the value of replSlavePriv
                const std::string &getReplSlavePriv() const {
                    return replSlavePriv;
                }

                // Get the value of replClientPriv
                const std::string &getReplClientPriv() const {
                    return replClientPriv;
                }

                // Get the value of createViewPriv
                const std::string &getCreateViewPriv() const {
                    return createViewPriv;
                }

                // Get the value of showViewPriv
                const std::string &getShowViewPriv() const {
                    return showViewPriv;
                }

                // Get the value of createRoutinePriv
                const std::string &getCreateRoutinePriv() const {
                    return createRoutinePriv;
                }

                // Get the value of alterRoutinePriv
                const std::string &getAlterRoutinePriv() const {
                    return alterRoutinePriv;
                }

                // Get the value of createUserPriv
                const std::string &getCreateUserPriv() const {
                    return createUserPriv;
                }

                // Get the value of eventPriv
                const std::string &getEventPriv() const {
                    return eventPriv;
                }

                // Get the value of triggerPriv
                const std::string &getTriggerPriv() const {
                    return triggerPriv;
                }

                // Get the value of createTablespacePriv
                const std::string &getCreateTablespacePriv() const {
                    return createTablespacePriv;
                }

                // Get the value of sslType
                const std::string &getSslType() const {
                    return sslType;
                }

                // Get the value of sslCipher
                const std::string &getSslCipher() const {
                    return sslCipher;
                }

                // Get the value of x509Issuer
                const std::string &getX509Issuer() const {
                    return x509Issuer;
                }

                // Get the value of x509Subject
                const std::string &getX509Subject() const {
                    return x509Subject;
                }

                // Get the value of maxQuestions
                int getMaxQuestions() const {
                    return maxQuestions;
                }

                // Get the value of maxUpdates
                int getMaxUpdates() const {
                    return maxUpdates;
                }

                // Get the value of maxConnections
                int getMaxConnections() const {
                    return maxConnections;
                }

                // Get the value of maxUserConnections
                int getMaxUserConnections() const {
                    return maxUserConnections;
                }

                // Get the value of plugin
                const std::string &getPlugin() const {
                    return plugin;
                }

                // Get the value of authenticationString
                const std::string &getAuthenticationString() const {
                    return authenticationString;
                }

                // Get the value of passwordExpired
                const std::string &getPasswordExpired() const {
                    return passwordExpired;
                }

                // Get the value of passwordLastChanged
                const std::string &getPasswordLastChanged() const {
                    return passwordLastChanged;
                }

                // Get the value of passwordLifetime
                int getPasswordLifetime() const {
                    return passwordLifetime;
                }

                // Get the value of accountLocked
                const std::string &getAccountLocked() const {
                    return accountLocked;
                }


                /**
                * Returns the table name 'user';
                */
                static const char *getDatabaseTableName() {
                    return TABLE_NAME;
                }
            };
        }
    }

}
#endif //INFORMATION_SCHEMA_CPP_USER_H