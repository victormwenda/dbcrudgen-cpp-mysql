#ifndef INFORMATION_SCHEMA_CPP_DB_H
#define INFORMATION_SCHEMA_CPP_DB_H

#include<string>

namespace dbcrudgen {
    namespace mysql {
        class Db {

        private:
            std::string host;
            std::string db;
            std::string user;
            std::string selectPriv;
            std::string insertPriv;
            std::string updatePriv;
            std::string deletePriv;
            std::string createPriv;
            std::string dropPriv;
            std::string grantPriv;
            std::string referencesPriv;
            std::string indexPriv;
            std::string alterPriv;
            std::string createTmpTablePriv;
            std::string lockTablesPriv;
            std::string createViewPriv;
            std::string showViewPriv;
            std::string createRoutinePriv;
            std::string alterRoutinePriv;
            std::string executePriv;
            std::string eventPriv;
            std::string triggerPriv;

        public:

            static constexpr const char *TABLE_NAME = "db";

            struct COLUMNS {
                struct HOST {
                    static constexpr const char *NAME = "Host";
                    static const int INDEX = 1;
                };
                struct DB {
                    static constexpr const char *NAME = "Db";
                    static const int INDEX = 2;
                };
                struct USER {
                    static constexpr const char *NAME = "User";
                    static const int INDEX = 3;
                };
                struct SELECT_PRIV {
                    static constexpr const char *NAME = "Select_priv";
                    static const int INDEX = 4;
                };
                struct INSERT_PRIV {
                    static constexpr const char *NAME = "Insert_priv";
                    static const int INDEX = 5;
                };
                struct UPDATE_PRIV {
                    static constexpr const char *NAME = "Update_priv";
                    static const int INDEX = 6;
                };
                struct DELETE_PRIV {
                    static constexpr const char *NAME = "Delete_priv";
                    static const int INDEX = 7;
                };
                struct CREATE_PRIV {
                    static constexpr const char *NAME = "Create_priv";
                    static const int INDEX = 8;
                };
                struct DROP_PRIV {
                    static constexpr const char *NAME = "Drop_priv";
                    static const int INDEX = 9;
                };
                struct GRANT_PRIV {
                    static constexpr const char *NAME = "Grant_priv";
                    static const int INDEX = 10;
                };
                struct REFERENCES_PRIV {
                    static constexpr const char *NAME = "References_priv";
                    static const int INDEX = 11;
                };
                struct INDEX_PRIV {
                    static constexpr const char *NAME = "Index_priv";
                    static const int INDEX = 12;
                };
                struct ALTER_PRIV {
                    static constexpr const char *NAME = "Alter_priv";
                    static const int INDEX = 13;
                };
                struct CREATE_TMP_TABLE_PRIV {
                    static constexpr const char *NAME = "Create_tmp_table_priv";
                    static const int INDEX = 14;
                };
                struct LOCK_TABLES_PRIV {
                    static constexpr const char *NAME = "Lock_tables_priv";
                    static const int INDEX = 15;
                };
                struct CREATE_VIEW_PRIV {
                    static constexpr const char *NAME = "Create_view_priv";
                    static const int INDEX = 16;
                };
                struct SHOW_VIEW_PRIV {
                    static constexpr const char *NAME = "Show_view_priv";
                    static const int INDEX = 17;
                };
                struct CREATE_ROUTINE_PRIV {
                    static constexpr const char *NAME = "Create_routine_priv";
                    static const int INDEX = 18;
                };
                struct ALTER_ROUTINE_PRIV {
                    static constexpr const char *NAME = "Alter_routine_priv";
                    static const int INDEX = 19;
                };
                struct EXECUTE_PRIV {
                    static constexpr const char *NAME = "Execute_priv";
                    static const int INDEX = 20;
                };
                struct EVENT_PRIV {
                    static constexpr const char *NAME = "Event_priv";
                    static const int INDEX = 21;
                };
                struct TRIGGER_PRIV {
                    static constexpr const char *NAME = "Trigger_priv";
                    static const int INDEX = 22;
                };
            };

            Db(std::string &host, std::string &db, std::string &user, std::string &selectPriv, std::string &insertPriv,
               std::string &updatePriv, std::string &deletePriv, std::string &createPriv, std::string &dropPriv,
               std::string &grantPriv, std::string &referencesPriv, std::string &indexPriv, std::string &alterPriv,
               std::string &createTmpTablePriv, std::string &lockTablesPriv, std::string &createViewPriv,
               std::string &showViewPriv, std::string &createRoutinePriv, std::string &alterRoutinePriv,
               std::string &executePriv, std::string &eventPriv, std::string &triggerPriv)
                    : host{host}, db{db}, user{user}, selectPriv{selectPriv}, insertPriv{insertPriv},
                      updatePriv{updatePriv}, deletePriv{deletePriv}, createPriv{createPriv}, dropPriv{dropPriv},
                      grantPriv{grantPriv}, referencesPriv{referencesPriv}, indexPriv{indexPriv}, alterPriv{alterPriv},
                      createTmpTablePriv{createTmpTablePriv}, lockTablesPriv{lockTablesPriv},
                      createViewPriv{createViewPriv}, showViewPriv{showViewPriv}, createRoutinePriv{createRoutinePriv},
                      alterRoutinePriv{alterRoutinePriv}, executePriv{executePriv}, eventPriv{eventPriv},
                      triggerPriv{triggerPriv} {}

            // Get the value of host
            const std::string &getHost() const {
                return host;
            }

            // Get the value of db
            const std::string &getDb() const {
                return db;
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

            // Get the value of createTmpTablePriv
            const std::string &getCreateTmpTablePriv() const {
                return createTmpTablePriv;
            }

            // Get the value of lockTablesPriv
            const std::string &getLockTablesPriv() const {
                return lockTablesPriv;
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

            // Get the value of executePriv
            const std::string &getExecutePriv() const {
                return executePriv;
            }

            // Get the value of eventPriv
            const std::string &getEventPriv() const {
                return eventPriv;
            }

            // Get the value of triggerPriv
            const std::string &getTriggerPriv() const {
                return triggerPriv;
            }


            /**
            * Returns the table name 'db';
            */
            static const char *getDatabaseTableName() {
                return TABLE_NAME;
            }
        };
    }
}

#endif //INFORMATION_SCHEMA_CPP_DB_H