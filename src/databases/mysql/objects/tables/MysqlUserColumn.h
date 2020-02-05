//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 4/14/18.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_MYSQLUSERCOLUMN_H
#define DBCRUDGEN_CPP_MYSQLUSERCOLUMN_H


//
// MysqlUserColumn
// //
class MysqlUserColumn {
public:
    constexpr static const char *HOST = "Host";
    constexpr static const char *USER = "User";
    constexpr static const char *SELECT_PRIV = "Select_priv";
    constexpr static const char *INSERT_PRIV = "Insert_priv";
    constexpr static const char *UPDATE_PRIV = "Update_priv";
    constexpr static const char *DELETE_PRIV = "Delete_priv";
    constexpr static const char *CREATE_PRIV = "Create_priv";
    constexpr static const char *DROP_PRIV = "Drop_priv";
    constexpr static const char *RELOAD_PRIV = "Reload_priv";
    constexpr static const char *SHUTDOWN_PRIV = "Shutdown_priv";
    constexpr static const char *PROCESS_PRIV = "Process_priv";
    constexpr static const char *FILE_PRIV = "File_priv";
    constexpr static const char *GRANT_PRIV = "Grant_priv";
    constexpr static const char *REFERENCES_PRIV = "References_priv";
    constexpr static const char *INDEX_PRIV = "Index_priv";
    constexpr static const char *ALTER_PRIV = "Alter_priv";
    constexpr static const char *SHOW_DB_PRIV = "Show_db_priv";
    constexpr static const char *SUPER_PRIV = "Super_priv";
    constexpr static const char *CREATE_TMP_TABLE_PRIV = "Create_tmp_table_priv";
    constexpr static const char *LOCK_TABLES_PRIV = "Lock_tables_priv";
    constexpr static const char *EXECUTE_PRIV = "Execute_priv";
    constexpr static const char *REPL_SLAVE_PRIV = "Repl_slave_priv";
    constexpr static const char *REPL_CLIENT_PRIV = "Repl_client_priv";
    constexpr static const char *CREATE_VIEW_PRIV = "Create_view_priv";
    constexpr static const char *SHOW_VIEW_PRIV = "Show_view_priv";
    constexpr static const char *CREATE_ROUTINE_PRIV = "Create_routine_priv";
    constexpr static const char *ALTER_ROUTINE_PRIV = "Alter_routine_priv";
    constexpr static const char *CREATE_USER_PRIV = "Create_user_priv";
    constexpr static const char *EVENT_PRIV = "Event_priv";
    constexpr static const char *TRIGGER_PRIV = "Trigger_priv";
    constexpr static const char *CREATE_TABLESPACE_PRIV = "Create_tablespace_priv";
    constexpr static const char *SSL_TYPE = "ssl_type";
    constexpr static const char *SSL_CIPHER = "ssl_cipher";
    constexpr static const char *X509_ISSUER = "x509_issuer";
    constexpr static const char *X509_SUBJECT = "x509_subject";
    constexpr static const char *MAX_QUESTIONS = "max_questions";
    constexpr static const char *MAX_UPDATES = "max_updates";
    constexpr static const char *MAX_CONNECTIONS = "max_connections";
    constexpr static const char *MAX_USER_CONNECTIONS = "max_user_connections";
    constexpr static const char *PLUGIN = "plugin";
    constexpr static const char *AUTHENTICATION_STRING = "authentication_string";
    constexpr static const char *PASSWORD_EXPIRED = "password_expired";
    constexpr static const char *PASSWORD_LAST_CHANGED = "password_last_changed";
    constexpr static const char *PASSWORD_LIFETIME = "password_lifetime";
    constexpr static const char *ACCOUNT_LOCKED = "account_locked";
};


#endif //DBCRUDGEN_CPP_MYSQLUSERCOLUMN_H
