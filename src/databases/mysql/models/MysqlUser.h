//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 4/14/18.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_MYSQLUSER_H
#define DBCRUDGEN_CPP_MYSQLUSER_H

#include <string>

//
// MysqlUser
// //
class MysqlUser {
public :
    std::string host;
    std::string user;
    std::string select_priv;
    std::string insert_priv;
    std::string update_priv;
    std::string delete_priv;
    std::string create_priv;
    std::string drop_priv;
    std::string reload_priv;
    std::string shutdown_priv;
    std::string process_priv;
    std::string file_priv;
    std::string grant_priv;
    std::string references_priv;
    std::string index_priv;
    std::string alter_priv;
    std::string show_db_priv;
    std::string super_priv;
    std::string create_tmp_table_priv;
    std::string lock_tables_priv;
    std::string execute_priv;
    std::string repl_slave_priv;
    std::string repl_client_priv;
    std::string create_view_priv;
    std::string show_view_priv;
    std::string create_routine_priv;
    std::string alter_routine_priv;
    std::string create_user_priv;
    std::string event_priv;
    std::string trigger_priv;
    std::string create_tablespace_priv;
    std::string ssl_type;
    std::string ssl_cipher;
    std::string x509_issuer;
    std::string x509_subject;
    std::string max_questions;
    std::string max_updates;
    std::string max_connections;
    std::string max_user_connections;
    std::string plugin;
    std::string authentication_string;
    std::string password_expired;
    std::string password_last_changed;
    std::string password_lifetime;
    std::string account_locked;

    MysqlUser(const std::string &host, const std::string &user, const std::string &select_priv,
              const std::string &insert_priv, const std::string &update_priv, const std::string &delete_priv,
              const std::string &create_priv, const std::string &drop_priv, const std::string &reload_priv,
              const std::string &shutdown_priv, const std::string &process_priv, const std::string &file_priv,
              const std::string &grant_priv, const std::string &references_priv, const std::string &index_priv,
              const std::string &alter_priv, const std::string &show_db_priv, const std::string &super_priv,
              const std::string &create_tmp_table_priv, const std::string &lock_tables_priv,
              const std::string &execute_priv, const std::string &repl_slave_priv, const std::string &repl_client_priv,
              const std::string &create_view_priv, const std::string &show_view_priv,
              const std::string &create_routine_priv, const std::string &alter_routine_priv,
              const std::string &create_user_priv, const std::string &event_priv, const std::string &trigger_priv,
              const std::string &create_tablespace_priv, const std::string &ssl_type, const std::string &ssl_cipher,
              const std::string &x509_issuer, const std::string &x509_subject, const std::string &max_questions,
              const std::string &max_updates, const std::string &max_connections,
              const std::string &max_user_connections, const std::string &plugin,
              const std::string &authentication_string, const std::string &password_expired,
              const std::string &password_last_changed, const std::string &password_lifetime,
              const std::string &account_locked) : host(host), user(user), select_priv(select_priv),
                                                   insert_priv(insert_priv), update_priv(update_priv),
                                                   delete_priv(delete_priv), create_priv(create_priv),
                                                   drop_priv(drop_priv), reload_priv(reload_priv),
                                                   shutdown_priv(shutdown_priv), process_priv(process_priv),
                                                   file_priv(file_priv), grant_priv(grant_priv),
                                                   references_priv(references_priv), index_priv(index_priv),
                                                   alter_priv(alter_priv), show_db_priv(show_db_priv),
                                                   super_priv(super_priv), create_tmp_table_priv(create_tmp_table_priv),
                                                   lock_tables_priv(lock_tables_priv), execute_priv(execute_priv),
                                                   repl_slave_priv(repl_slave_priv), repl_client_priv(repl_client_priv),
                                                   create_view_priv(create_view_priv), show_view_priv(show_view_priv),
                                                   create_routine_priv(create_routine_priv),
                                                   alter_routine_priv(alter_routine_priv),
                                                   create_user_priv(create_user_priv), event_priv(event_priv),
                                                   trigger_priv(trigger_priv),
                                                   create_tablespace_priv(create_tablespace_priv), ssl_type(ssl_type),
                                                   ssl_cipher(ssl_cipher), x509_issuer(x509_issuer),
                                                   x509_subject(x509_subject), max_questions(max_questions),
                                                   max_updates(max_updates), max_connections(max_connections),
                                                   max_user_connections(max_user_connections), plugin(plugin),
                                                   authentication_string(authentication_string),
                                                   password_expired(password_expired),
                                                   password_last_changed(password_last_changed),
                                                   password_lifetime(password_lifetime),
                                                   account_locked(account_locked) {}

    const std::string &getHost() const {
        return host;
    }

    void setHost(const std::string &host) {
        MysqlUser::host = host;
    }

    const std::string &getUser() const {
        return user;
    }

    void setUser(const std::string &user) {
        MysqlUser::user = user;
    }

    const std::string &getSelect_priv() const {
        return select_priv;
    }

    void setSelect_priv(const std::string &select_priv) {
        MysqlUser::select_priv = select_priv;
    }

    const std::string &getInsert_priv() const {
        return insert_priv;
    }

    void setInsert_priv(const std::string &insert_priv) {
        MysqlUser::insert_priv = insert_priv;
    }

    const std::string &getUpdate_priv() const {
        return update_priv;
    }

    void setUpdate_priv(const std::string &update_priv) {
        MysqlUser::update_priv = update_priv;
    }

    const std::string &getDelete_priv() const {
        return delete_priv;
    }

    void setDelete_priv(const std::string &delete_priv) {
        MysqlUser::delete_priv = delete_priv;
    }

    const std::string &getCreate_priv() const {
        return create_priv;
    }

    void setCreate_priv(const std::string &create_priv) {
        MysqlUser::create_priv = create_priv;
    }

    const std::string &getDrop_priv() const {
        return drop_priv;
    }

    void setDrop_priv(const std::string &drop_priv) {
        MysqlUser::drop_priv = drop_priv;
    }

    const std::string &getReload_priv() const {
        return reload_priv;
    }

    void setReload_priv(const std::string &reload_priv) {
        MysqlUser::reload_priv = reload_priv;
    }

    const std::string &getShutdown_priv() const {
        return shutdown_priv;
    }

    void setShutdown_priv(const std::string &shutdown_priv) {
        MysqlUser::shutdown_priv = shutdown_priv;
    }

    const std::string &getProcess_priv() const {
        return process_priv;
    }

    void setProcess_priv(const std::string &process_priv) {
        MysqlUser::process_priv = process_priv;
    }

    const std::string &getFile_priv() const {
        return file_priv;
    }

    void setFile_priv(const std::string &file_priv) {
        MysqlUser::file_priv = file_priv;
    }

    const std::string &getGrant_priv() const {
        return grant_priv;
    }

    void setGrant_priv(const std::string &grant_priv) {
        MysqlUser::grant_priv = grant_priv;
    }

    const std::string &getReferences_priv() const {
        return references_priv;
    }

    void setReferences_priv(const std::string &references_priv) {
        MysqlUser::references_priv = references_priv;
    }

    const std::string &getIndex_priv() const {
        return index_priv;
    }

    void setIndex_priv(const std::string &index_priv) {
        MysqlUser::index_priv = index_priv;
    }

    const std::string &getAlter_priv() const {
        return alter_priv;
    }

    void setAlter_priv(const std::string &alter_priv) {
        MysqlUser::alter_priv = alter_priv;
    }

    const std::string &getShow_db_priv() const {
        return show_db_priv;
    }

    void setShow_db_priv(const std::string &show_db_priv) {
        MysqlUser::show_db_priv = show_db_priv;
    }

    const std::string &getSuper_priv() const {
        return super_priv;
    }

    void setSuper_priv(const std::string &super_priv) {
        MysqlUser::super_priv = super_priv;
    }

    const std::string &getCreate_tmp_table_priv() const {
        return create_tmp_table_priv;
    }

    void setCreate_tmp_table_priv(const std::string &create_tmp_table_priv) {
        MysqlUser::create_tmp_table_priv = create_tmp_table_priv;
    }

    const std::string &getLock_tables_priv() const {
        return lock_tables_priv;
    }

    void setLock_tables_priv(const std::string &lock_tables_priv) {
        MysqlUser::lock_tables_priv = lock_tables_priv;
    }

    const std::string &getExecute_priv() const {
        return execute_priv;
    }

    void setExecute_priv(const std::string &execute_priv) {
        MysqlUser::execute_priv = execute_priv;
    }

    const std::string &getRepl_slave_priv() const {
        return repl_slave_priv;
    }

    void setRepl_slave_priv(const std::string &repl_slave_priv) {
        MysqlUser::repl_slave_priv = repl_slave_priv;
    }

    const std::string &getRepl_client_priv() const {
        return repl_client_priv;
    }

    void setRepl_client_priv(const std::string &repl_client_priv) {
        MysqlUser::repl_client_priv = repl_client_priv;
    }

    const std::string &getCreate_view_priv() const {
        return create_view_priv;
    }

    void setCreate_view_priv(const std::string &create_view_priv) {
        MysqlUser::create_view_priv = create_view_priv;
    }

    const std::string &getShow_view_priv() const {
        return show_view_priv;
    }

    void setShow_view_priv(const std::string &show_view_priv) {
        MysqlUser::show_view_priv = show_view_priv;
    }

    const std::string &getCreate_routine_priv() const {
        return create_routine_priv;
    }

    void setCreate_routine_priv(const std::string &create_routine_priv) {
        MysqlUser::create_routine_priv = create_routine_priv;
    }

    const std::string &getAlter_routine_priv() const {
        return alter_routine_priv;
    }

    void setAlter_routine_priv(const std::string &alter_routine_priv) {
        MysqlUser::alter_routine_priv = alter_routine_priv;
    }

    const std::string &getCreate_user_priv() const {
        return create_user_priv;
    }

    void setCreate_user_priv(const std::string &create_user_priv) {
        MysqlUser::create_user_priv = create_user_priv;
    }

    const std::string &getEvent_priv() const {
        return event_priv;
    }

    void setEvent_priv(const std::string &event_priv) {
        MysqlUser::event_priv = event_priv;
    }

    const std::string &getTrigger_priv() const {
        return trigger_priv;
    }

    void setTrigger_priv(const std::string &trigger_priv) {
        MysqlUser::trigger_priv = trigger_priv;
    }

    const std::string &getCreate_tablespace_priv() const {
        return create_tablespace_priv;
    }

    void setCreate_tablespace_priv(const std::string &create_tablespace_priv) {
        MysqlUser::create_tablespace_priv = create_tablespace_priv;
    }

    const std::string &getSsl_type() const {
        return ssl_type;
    }

    void setSsl_type(const std::string &ssl_type) {
        MysqlUser::ssl_type = ssl_type;
    }

    const std::string &getSsl_cipher() const {
        return ssl_cipher;
    }

    void setSsl_cipher(const std::string &ssl_cipher) {
        MysqlUser::ssl_cipher = ssl_cipher;
    }

    const std::string &getX509_issuer() const {
        return x509_issuer;
    }

    void setX509_issuer(const std::string &x509_issuer) {
        MysqlUser::x509_issuer = x509_issuer;
    }

    const std::string &getX509_subject() const {
        return x509_subject;
    }

    void setX509_subject(const std::string &x509_subject) {
        MysqlUser::x509_subject = x509_subject;
    }

    const std::string &getMax_questions() const {
        return max_questions;
    }

    void setMax_questions(const std::string &max_questions) {
        MysqlUser::max_questions = max_questions;
    }

    const std::string &getMax_updates() const {
        return max_updates;
    }

    void setMax_updates(const std::string &max_updates) {
        MysqlUser::max_updates = max_updates;
    }

    const std::string &getMax_connections() const {
        return max_connections;
    }

    void setMax_connections(const std::string &max_connections) {
        MysqlUser::max_connections = max_connections;
    }

    const std::string &getMax_user_connections() const {
        return max_user_connections;
    }

    void setMax_user_connections(const std::string &max_user_connections) {
        MysqlUser::max_user_connections = max_user_connections;
    }

    const std::string &getPlugin() const {
        return plugin;
    }

    void setPlugin(const std::string &plugin) {
        MysqlUser::plugin = plugin;
    }

    const std::string &getAuthentication_string() const {
        return authentication_string;
    }

    void setAuthentication_string(const std::string &authentication_string) {
        MysqlUser::authentication_string = authentication_string;
    }

    const std::string &getPassword_expired() const {
        return password_expired;
    }

    void setPassword_expired(const std::string &password_expired) {
        MysqlUser::password_expired = password_expired;
    }

    const std::string &getPassword_last_changed() const {
        return password_last_changed;
    }

    void setPassword_last_changed(const std::string &password_last_changed) {
        MysqlUser::password_last_changed = password_last_changed;
    }

    const std::string &getPassword_lifetime() const {
        return password_lifetime;
    }

    void setPassword_lifetime(const std::string &password_lifetime) {
        MysqlUser::password_lifetime = password_lifetime;
    }

    const std::string &getAccount_locked() const {
        return account_locked;
    }

    void setAccount_locked(const std::string &account_locked) {
        MysqlUser::account_locked = account_locked;
    }
};


#endif //DBCRUDGEN_CPP_MYSQLUSER_H
