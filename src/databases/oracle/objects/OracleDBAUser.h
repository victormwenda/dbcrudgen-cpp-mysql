//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 11/18/18.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_ORACLEDBAUSER_H
#define DBCRUDGEN_CPP_ORACLEDBAUSER_H

#include <string>

namespace dbcrudgen {
    namespace db {
        namespace oracle {

        //
        // OracleDBAUser
        // //
            class OracleDBAUser {

            public:
                struct Status {
                    static constexpr const char * OPEN  = "OPEN";
                    static constexpr const char * EXPIRED  = "EXPIRED";
                    static constexpr const char * EXPIRED_GRACE  = "EXPIRED(GRACE)";
                    static constexpr const char * EXPIRED_TIMED  = "EXPIRED(TIMED)";
                    static constexpr const char * LOCKED  = "LOCKED";
                    static constexpr const char * EXPIRED_LOCKED_TIMED  = "EXPIRED & LOCKED(TIMED)";
                    static constexpr const char * EXPIRED_GRACE_LOCKED_TIMED  = "EXPIRED(GRACE) & LOCKED(TIMED)";
                    static constexpr const char * EXPIRED_LOCKED  = "EXPIRED & LOCKED";
                    static constexpr const char * EXPIRED_GRACE_LOCKED  = "EXPIRED(GRACE) & LOCKED";
                };


                std::string username ;
                std::string user_id ;
                std::string password ;
                std::string account_status ;
                std::string lock_date ;
                std::string expiry_date ;
                std::string default_tablespace ;
                std::string temporary_tablespace ;
                std::string created ;
                std::string profile ;
                std::string initial_rsrc_consumer_group ;
                std::string external_name ;
                std::string password_versions ;
                std::string editions_enabled ;
                std::string authentication_type ;

                OracleDBAUser(const std::string &username, const std::string &user_id, const std::string &password,
                              const std::string &account_status, const std::string &lock_date, const std::string &expiry_date,
                              const std::string &default_tablespace, const std::string &temporary_tablespace,
                              const std::string &created, const std::string &profile,
                              const std::string &initial_rsrc_consumer_group, const std::string &external_name,
                              const std::string &password_versions, const std::string &editions_enabled,
                              const std::string &authentication_type)
                        : username(username), user_id(user_id), password(password), account_status(account_status),
                          lock_date(lock_date), expiry_date(expiry_date), default_tablespace(default_tablespace),
                          temporary_tablespace(temporary_tablespace), created(created), profile(profile),
                          initial_rsrc_consumer_group(initial_rsrc_consumer_group), external_name(external_name),
                          password_versions(password_versions), editions_enabled(editions_enabled),
                          authentication_type(authentication_type) {}

                const std::string &getUsername() const {
                    return username;
                }

                void setUsername(const std::string &username) {
                    OracleDBAUser::username = username;
                }

                const std::string &getUser_id() const {
                    return user_id;
                }

                void setUser_id(const std::string &user_id) {
                    OracleDBAUser::user_id = user_id;
                }

                const std::string &getPassword() const {
                    return password;
                }

                void setPassword(const std::string &password) {
                    OracleDBAUser::password = password;
                }

                const std::string &getAccount_status() const {
                    return account_status;
                }

                void setAccount_status(const std::string &account_status) {
                    OracleDBAUser::account_status = account_status;
                }

                const std::string &getLock_date() const {
                    return lock_date;
                }

                void setLock_date(const std::string &lock_date) {
                    OracleDBAUser::lock_date = lock_date;
                }

                const std::string &getExpiry_date() const {
                    return expiry_date;
                }

                void setExpiry_date(const std::string &expiry_date) {
                    OracleDBAUser::expiry_date = expiry_date;
                }

                const std::string &getDefault_tablespace() const {
                    return default_tablespace;
                }

                void setDefault_tablespace(const std::string &default_tablespace) {
                    OracleDBAUser::default_tablespace = default_tablespace;
                }

                const std::string &getTemporary_tablespace() const {
                    return temporary_tablespace;
                }

                void setTemporary_tablespace(const std::string &temporary_tablespace) {
                    OracleDBAUser::temporary_tablespace = temporary_tablespace;
                }

                const std::string &getCreated() const {
                    return created;
                }

                void setCreated(const std::string &created) {
                    OracleDBAUser::created = created;
                }

                const std::string &getProfile() const {
                    return profile;
                }

                void setProfile(const std::string &profile) {
                    OracleDBAUser::profile = profile;
                }

                const std::string &getInitial_rsrc_consumer_group() const {
                    return initial_rsrc_consumer_group;
                }

                void setInitial_rsrc_consumer_group(const std::string &initial_rsrc_consumer_group) {
                    OracleDBAUser::initial_rsrc_consumer_group = initial_rsrc_consumer_group;
                }

                const std::string &getExternal_name() const {
                    return external_name;
                }

                void setExternal_name(const std::string &external_name) {
                    OracleDBAUser::external_name = external_name;
                }

                const std::string &getPassword_versions() const {
                    return password_versions;
                }

                void setPassword_versions(const std::string &password_versions) {
                    OracleDBAUser::password_versions = password_versions;
                }

                const std::string &getEditions_enabled() const {
                    return editions_enabled;
                }

                void setEditions_enabled(const std::string &editions_enabled) {
                    OracleDBAUser::editions_enabled = editions_enabled;
                }

                const std::string &getAuthentication_type() const {
                    return authentication_type;
                }

                void setAuthentication_type(const std::string &authentication_type) {
                    OracleDBAUser::authentication_type = authentication_type;
                }
            };
        }
    }
}




#endif //DBCRUDGEN_CPP_ORACLEDBAUSER_H
