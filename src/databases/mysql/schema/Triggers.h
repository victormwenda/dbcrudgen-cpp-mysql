//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_TRIGGERS_H
#define DBCRUDGEN_CPP_TRIGGERS_H

#include <string>

namespace dbcrudgen {
    namespace mysql {
        class Triggers {

        private:
            std::string triggerCatalog;
            std::string triggerSchema;
            std::string triggerName;
            std::string eventManipulation;
            std::string eventObjectCatalog;
            std::string eventObjectSchema;
            std::string eventObjectTable;
            long actionOrder;
            std::string actionCondition;
            std::string actionStatement;
            std::string actionOrientation;
            std::string actionTiming;
            std::string actionReferenceOldTable;
            std::string actionReferenceNewTable;
            std::string actionReferenceOldRow;
            std::string actionReferenceNewRow;
            std::string created;
            std::string sqlMode;
            std::string definer;
            std::string characterSetClient;
            std::string collationConnection;
            std::string databaseCollation;

        public:

            static constexpr const char *TABLE_NAME = "TRIGGERS";

            struct COLUMNS {
                struct TRIGGER_CATALOG {
                    static constexpr const char *NAME = "TRIGGER_CATALOG";
                    static const int INDEX = 1;
                };
                struct TRIGGER_SCHEMA {
                    static constexpr const char *NAME = "TRIGGER_SCHEMA";
                    static const int INDEX = 2;
                };
                struct TRIGGER_NAME {
                    static constexpr const char *NAME = "TRIGGER_NAME";
                    static const int INDEX = 3;
                };
                struct EVENT_MANIPULATION {
                    static constexpr const char *NAME = "EVENT_MANIPULATION";
                    static const int INDEX = 4;
                };
                struct EVENT_OBJECT_CATALOG {
                    static constexpr const char *NAME = "EVENT_OBJECT_CATALOG";
                    static const int INDEX = 5;
                };
                struct EVENT_OBJECT_SCHEMA {
                    static constexpr const char *NAME = "EVENT_OBJECT_SCHEMA";
                    static const int INDEX = 6;
                };
                struct EVENT_OBJECT_TABLE {
                    static constexpr const char *NAME = "EVENT_OBJECT_TABLE";
                    static const int INDEX = 7;
                };
                struct ACTION_ORDER {
                    static constexpr const char *NAME = "ACTION_ORDER";
                    static const int INDEX = 8;
                };
                struct ACTION_CONDITION {
                    static constexpr const char *NAME = "ACTION_CONDITION";
                    static const int INDEX = 9;
                };
                struct ACTION_STATEMENT {
                    static constexpr const char *NAME = "ACTION_STATEMENT";
                    static const int INDEX = 10;
                };
                struct ACTION_ORIENTATION {
                    static constexpr const char *NAME = "ACTION_ORIENTATION";
                    static const int INDEX = 11;
                };
                struct ACTION_TIMING {
                    static constexpr const char *NAME = "ACTION_TIMING";
                    static const int INDEX = 12;
                };
                struct ACTION_REFERENCE_OLD_TABLE {
                    static constexpr const char *NAME = "ACTION_REFERENCE_OLD_TABLE";
                    static const int INDEX = 13;
                };
                struct ACTION_REFERENCE_NEW_TABLE {
                    static constexpr const char *NAME = "ACTION_REFERENCE_NEW_TABLE";
                    static const int INDEX = 14;
                };
                struct ACTION_REFERENCE_OLD_ROW {
                    static constexpr const char *NAME = "ACTION_REFERENCE_OLD_ROW";
                    static const int INDEX = 15;
                };
                struct ACTION_REFERENCE_NEW_ROW {
                    static constexpr const char *NAME = "ACTION_REFERENCE_NEW_ROW";
                    static const int INDEX = 16;
                };
                struct CREATED {
                    static constexpr const char *NAME = "CREATED";
                    static const int INDEX = 17;
                };
                struct SQL_MODE {
                    static constexpr const char *NAME = "SQL_MODE";
                    static const int INDEX = 18;
                };
                struct DEFINER {
                    static constexpr const char *NAME = "DEFINER";
                    static const int INDEX = 19;
                };
                struct CHARACTER_SET_CLIENT {
                    static constexpr const char *NAME = "CHARACTER_SET_CLIENT";
                    static const int INDEX = 20;
                };
                struct COLLATION_CONNECTION {
                    static constexpr const char *NAME = "COLLATION_CONNECTION";
                    static const int INDEX = 21;
                };
                struct DATABASE_COLLATION {
                    static constexpr const char *NAME = "DATABASE_COLLATION";
                    static const int INDEX = 22;
                };
            };

            Triggers(std::string &triggerCatalog, std::string &triggerSchema, std::string &triggerName,
                     std::string &eventManipulation, std::string &eventObjectCatalog, std::string &eventObjectSchema,
                     std::string &eventObjectTable, long actionOrder, std::string &actionCondition,
                     std::string &actionStatement, std::string &actionOrientation, std::string &actionTiming,
                     std::string &actionReferenceOldTable, std::string &actionReferenceNewTable,
                     std::string &actionReferenceOldRow, std::string &actionReferenceNewRow, std::string &created,
                     std::string &sqlMode, std::string &definer, std::string &characterSetClient,
                     std::string &collationConnection, std::string &databaseCollation)
                    : triggerCatalog{triggerCatalog}, triggerSchema{triggerSchema}, triggerName{triggerName},
                      eventManipulation{eventManipulation}, eventObjectCatalog{eventObjectCatalog},
                      eventObjectSchema{eventObjectSchema}, eventObjectTable{eventObjectTable},
                      actionOrder{actionOrder}, actionCondition{actionCondition}, actionStatement{actionStatement},
                      actionOrientation{actionOrientation}, actionTiming{actionTiming},
                      actionReferenceOldTable{actionReferenceOldTable},
                      actionReferenceNewTable{actionReferenceNewTable}, actionReferenceOldRow{actionReferenceOldRow},
                      actionReferenceNewRow{actionReferenceNewRow}, created{created}, sqlMode{sqlMode},
                      definer{definer}, characterSetClient{characterSetClient},
                      collationConnection{collationConnection}, databaseCollation{databaseCollation} {}

            // Get the value of triggerCatalog
            const std::string &getTriggerCatalog() const {
                return triggerCatalog;
            }

            // Get the value of triggerSchema
            const std::string &getTriggerSchema() const {
                return triggerSchema;
            }

            // Get the value of triggerName
            const std::string &getTriggerName() const {
                return triggerName;
            }

            // Get the value of eventManipulation
            const std::string &getEventManipulation() const {
                return eventManipulation;
            }

            // Get the value of eventObjectCatalog
            const std::string &getEventObjectCatalog() const {
                return eventObjectCatalog;
            }

            // Get the value of eventObjectSchema
            const std::string &getEventObjectSchema() const {
                return eventObjectSchema;
            }

            // Get the value of eventObjectTable
            const std::string &getEventObjectTable() const {
                return eventObjectTable;
            }

            // Get the value of actionOrder
            long getActionOrder() const {
                return actionOrder;
            }

            // Get the value of actionCondition
            const std::string &getActionCondition() const {
                return actionCondition;
            }

            // Get the value of actionStatement
            const std::string &getActionStatement() const {
                return actionStatement;
            }

            // Get the value of actionOrientation
            const std::string &getActionOrientation() const {
                return actionOrientation;
            }

            // Get the value of actionTiming
            const std::string &getActionTiming() const {
                return actionTiming;
            }

            // Get the value of actionReferenceOldTable
            const std::string &getActionReferenceOldTable() const {
                return actionReferenceOldTable;
            }

            // Get the value of actionReferenceNewTable
            const std::string &getActionReferenceNewTable() const {
                return actionReferenceNewTable;
            }

            // Get the value of actionReferenceOldRow
            const std::string &getActionReferenceOldRow() const {
                return actionReferenceOldRow;
            }

            // Get the value of actionReferenceNewRow
            const std::string &getActionReferenceNewRow() const {
                return actionReferenceNewRow;
            }

            // Get the value of created
            const std::string &getCreated() const {
                return created;
            }

            // Get the value of sqlMode
            const std::string &getSqlMode() const {
                return sqlMode;
            }

            // Get the value of definer
            const std::string &getDefiner() const {
                return definer;
            }

            // Get the value of characterSetClient
            const std::string &getCharacterSetClient() const {
                return characterSetClient;
            }

            // Get the value of collationConnection
            const std::string &getCollationConnection() const {
                return collationConnection;
            }

            // Get the value of databaseCollation
            const std::string &getDatabaseCollation() const {
                return databaseCollation;
            }

            /**
            * Returns the table name 'TRIGGERS';
            */
            static const char *getDatabaseTableName() {
                return TABLE_NAME;
            }
        };

    }
}


#endif //DBCRUDGEN_CPP_TRIGGERS_H
