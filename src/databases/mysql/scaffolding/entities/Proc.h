#ifndef INFORMATION_SCHEMA_CPP_PROC_H
#define INFORMATION_SCHEMA_CPP_PROC_H

#include<string>

namespace dbcrudgen {
    namespace db {
        namespace mysql {
            class Proc {

            private:
                std::string db;
                std::string name;
                std::string type;
                std::string specificName;
                std::string language;
                std::string sqlDataAccess;
                std::string isDeterministic;
                std::string securityType;
                std::string paramList;
                std::string returns;
                std::string body;
                std::string definer;
                std::string created;
                std::string modified;
                std::string sqlMode;
                std::string comment;
                std::string characterSetClient;
                std::string collationConnection;
                std::string dbCollation;
                std::string bodyUtf8;

            public:

                static constexpr const char *TABLE_NAME = "proc";

                struct COLUMNS {
                    struct DB {
                        static constexpr const char *NAME = "db";
                        static const int INDEX = 1;
                    };
                    struct NAME {
                        static constexpr const char *_NAME = "name";
                        static const int INDEX = 2;
                    };
                    struct TYPE {
                        static constexpr const char *NAME = "type";
                        static const int INDEX = 3;
                    };
                    struct SPECIFIC_NAME {
                        static constexpr const char *NAME = "specific_name";
                        static const int INDEX = 4;
                    };
                    struct LANGUAGE {
                        static constexpr const char *NAME = "language";
                        static const int INDEX = 5;
                    };
                    struct SQL_DATA_ACCESS {
                        static constexpr const char *NAME = "sql_data_access";
                        static const int INDEX = 6;
                    };
                    struct IS_DETERMINISTIC {
                        static constexpr const char *NAME = "is_deterministic";
                        static const int INDEX = 7;
                    };
                    struct SECURITY_TYPE {
                        static constexpr const char *NAME = "security_type";
                        static const int INDEX = 8;
                    };
                    struct PARAM_LIST {
                        static constexpr const char *NAME = "param_list";
                        static const int INDEX = 9;
                    };
                    struct RETURNS {
                        static constexpr const char *NAME = "returns";
                        static const int INDEX = 10;
                    };
                    struct BODY {
                        static constexpr const char *NAME = "body";
                        static const int INDEX = 11;
                    };
                    struct DEFINER {
                        static constexpr const char *NAME = "definer";
                        static const int INDEX = 12;
                    };
                    struct CREATED {
                        static constexpr const char *NAME = "created";
                        static const int INDEX = 13;
                    };
                    struct MODIFIED {
                        static constexpr const char *NAME = "modified";
                        static const int INDEX = 14;
                    };
                    struct SQL_MODE {
                        static constexpr const char *NAME = "sql_mode";
                        static const int INDEX = 15;
                    };
                    struct COMMENT {
                        static constexpr const char *NAME = "comment";
                        static const int INDEX = 16;
                    };
                    struct CHARACTER_SET_CLIENT {
                        static constexpr const char *NAME = "character_set_client";
                        static const int INDEX = 17;
                    };
                    struct COLLATION_CONNECTION {
                        static constexpr const char *NAME = "collation_connection";
                        static const int INDEX = 18;
                    };
                    struct DB_COLLATION {
                        static constexpr const char *NAME = "db_collation";
                        static const int INDEX = 19;
                    };
                    struct BODY_UTF8 {
                        static constexpr const char *NAME = "body_utf8";
                        static const int INDEX = 20;
                    };
                };

                Proc(std::string &db, std::string &name, std::string &type, std::string &specificName,
                     std::string &language, std::string &sqlDataAccess, std::string &isDeterministic,
                     std::string &securityType, std::string &paramList, std::string &returns, std::string &body,
                     std::string &definer, std::string &created, std::string &modified, std::string &sqlMode,
                     std::string &comment, std::string &characterSetClient, std::string &collationConnection,
                     std::string &dbCollation, std::string &bodyUtf8)
                        : db{db}, name{name}, type{type}, specificName{specificName}, language{language},
                          sqlDataAccess{sqlDataAccess}, isDeterministic{isDeterministic}, securityType{securityType},
                          paramList{paramList}, returns{returns}, body{body}, definer{definer}, created{created},
                          modified{modified}, sqlMode{sqlMode}, comment{comment},
                          characterSetClient{characterSetClient},
                          collationConnection{collationConnection}, dbCollation{dbCollation}, bodyUtf8{bodyUtf8} {}

                // Get the value of db
                const std::string &getDb() const {
                    return db;
                }

                // Get the value of name
                const std::string &getName() const {
                    return name;
                }

                // Get the value of type
                const std::string &getType() const {
                    return type;
                }

                // Get the value of specificName
                const std::string &getSpecificName() const {
                    return specificName;
                }

                // Get the value of language
                const std::string &getLanguage() const {
                    return language;
                }

                // Get the value of sqlDataAccess
                const std::string &getSqlDataAccess() const {
                    return sqlDataAccess;
                }

                // Get the value of isDeterministic
                const std::string &getIsDeterministic() const {
                    return isDeterministic;
                }

                // Get the value of securityType
                const std::string &getSecurityType() const {
                    return securityType;
                }

                // Get the value of paramList
                const std::string &getParamList() const {
                    return paramList;
                }

                // Get the value of returns
                const std::string &getReturns() const {
                    return returns;
                }

                // Get the value of body
                const std::string &getBody() const {
                    return body;
                }

                // Get the value of definer
                const std::string &getDefiner() const {
                    return definer;
                }

                // Get the value of created
                const std::string &getCreated() const {
                    return created;
                }

                // Get the value of modified
                const std::string &getModified() const {
                    return modified;
                }

                // Get the value of sqlMode
                const std::string &getSqlMode() const {
                    return sqlMode;
                }

                // Get the value of comment
                const std::string &getComment() const {
                    return comment;
                }

                // Get the value of characterSetClient
                const std::string &getCharacterSetClient() const {
                    return characterSetClient;
                }

                // Get the value of collationConnection
                const std::string &getCollationConnection() const {
                    return collationConnection;
                }

                // Get the value of dbCollation
                const std::string &getDbCollation() const {
                    return dbCollation;
                }

                // Get the value of bodyUtf8
                const std::string &getBodyUtf8() const {
                    return bodyUtf8;
                }


                /**
                * Returns the table name 'proc';
                */
                static const char *getDatabaseTableName() {
                    return TABLE_NAME;
                }
            };
        }
    }

}
#endif //INFORMATION_SCHEMA_CPP_PROC_H