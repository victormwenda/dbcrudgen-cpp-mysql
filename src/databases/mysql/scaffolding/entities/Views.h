//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_VIEWS_H
#define DBCRUDGEN_CPP_VIEWS_H

#include <string>

namespace dbcrudgen {
    namespace mysql {
        class Views {

        private:
            std::string tableCatalog;
            std::string tableSchema;
            std::string tableName;
            std::string viewDefinition;
            std::string checkOption;
            std::string isUpdatable;
            std::string definer;
            std::string securityType;
            std::string characterSetClient;
            std::string collationConnection;

        public:

            static constexpr const char *TABLE_NAME = "VIEWS";

            struct COLUMNS {
                struct TABLE_CATALOG {
                    static constexpr const char *NAME = "TABLE_CATALOG";
                    static const int INDEX = 1;
                };
                struct TABLE_SCHEMA {
                    static constexpr const char *NAME = "TABLE_SCHEMA";
                    static const int INDEX = 2;
                };
                struct TABLE_NAME {
                    static constexpr const char *NAME = "TABLE_NAME";
                    static const int INDEX = 3;
                };
                struct VIEW_DEFINITION {
                    static constexpr const char *NAME = "VIEW_DEFINITION";
                    static const int INDEX = 4;
                };
                struct CHECK_OPTION {
                    static constexpr const char *NAME = "CHECK_OPTION";
                    static const int INDEX = 5;
                };
                struct IS_UPDATABLE {
                    static constexpr const char *NAME = "IS_UPDATABLE";
                    static const int INDEX = 6;
                };
                struct DEFINER {
                    static constexpr const char *NAME = "DEFINER";
                    static const int INDEX = 7;
                };
                struct SECURITY_TYPE {
                    static constexpr const char *NAME = "SECURITY_TYPE";
                    static const int INDEX = 8;
                };
                struct CHARACTER_SET_CLIENT {
                    static constexpr const char *NAME = "CHARACTER_SET_CLIENT";
                    static const int INDEX = 9;
                };
                struct COLLATION_CONNECTION {
                    static constexpr const char *NAME = "COLLATION_CONNECTION";
                    static const int INDEX = 10;
                };
            };

            Views(std::string &tableCatalog, std::string &tableSchema, std::string &tableName,
                  std::string &viewDefinition, std::string &checkOption, std::string &isUpdatable, std::string &definer,
                  std::string &securityType, std::string &characterSetClient, std::string &collationConnection)
                    : tableCatalog{tableCatalog}, tableSchema{tableSchema}, tableName{tableName},
                      viewDefinition{viewDefinition}, checkOption{checkOption}, isUpdatable{isUpdatable},
                      definer{definer}, securityType{securityType}, characterSetClient{characterSetClient},
                      collationConnection{collationConnection} {}

            // Get the value of tableCatalog
            const std::string &getTableCatalog() const {
                return tableCatalog;
            }

            // Get the value of tableSchema
            const std::string &getTableSchema() const {
                return tableSchema;
            }

            // Get the value of tableName
            const std::string &getTableName() const {
                return tableName;
            }

            // Get the value of viewDefinition
            const std::string &getViewDefinition() const {
                return viewDefinition;
            }

            // Get the value of checkOption
            const std::string &getCheckOption() const {
                return checkOption;
            }

            // Get the value of isUpdatable
            const std::string &getIsUpdatable() const {
                return isUpdatable;
            }

            // Get the value of definer
            const std::string &getDefiner() const {
                return definer;
            }

            // Get the value of securityType
            const std::string &getSecurityType() const {
                return securityType;
            }

            // Get the value of characterSetClient
            const std::string &getCharacterSetClient() const {
                return characterSetClient;
            }

            // Get the value of collationConnection
            const std::string &getCollationConnection() const {
                return collationConnection;
            }

            /**
            * Returns the table name 'VIEWS';
            */
            static const char *getDatabaseTableName() {
                return TABLE_NAME;
            }
        };

    }
}


#endif //DBCRUDGEN_CPP_VIEWS_H
