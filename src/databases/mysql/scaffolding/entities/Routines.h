//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_ROUTINES_H
#define DBCRUDGEN_CPP_ROUTINES_H

#include <string>

namespace dbcrudgen {
    namespace db {
        namespace mysql {
            class Routines {

            private:
                std::string specificName;
                std::string routineCatalog;
                std::string routineSchema;
                std::string routineName;
                std::string routineType;
                std::string dataType;
                int characterMaximumLength;
                int characterOctetLength;
                long numericPrecision;
                int numericScale;
                long datetimePrecision;
                std::string characterSetName;
                std::string collationName;
                std::string dtdIdentifier;
                std::string routineBody;
                std::string routineDefinition;
                std::string externalName;
                std::string externalLanguage;
                std::string parameterStyle;
                std::string isDeterministic;
                std::string sqlDataAccess;
                std::string sqlPath;
                std::string securityType;
                std::string created;
                std::string lastAltered;
                std::string sqlMode;
                std::string routineComment;
                std::string definer;
                std::string characterSetClient;
                std::string collationConnection;
                std::string databaseCollation;

            public:

                static constexpr const char *TABLE_NAME = "ROUTINES";

                struct COLUMNS {
                    struct SPECIFIC_NAME {
                        static constexpr const char *NAME = "SPECIFIC_NAME";
                        static const int INDEX = 1;
                    };
                    struct ROUTINE_CATALOG {
                        static constexpr const char *NAME = "ROUTINE_CATALOG";
                        static const int INDEX = 2;
                    };
                    struct ROUTINE_SCHEMA {
                        static constexpr const char *NAME = "ROUTINE_SCHEMA";
                        static const int INDEX = 3;
                    };
                    struct ROUTINE_NAME {
                        static constexpr const char *NAME = "ROUTINE_NAME";
                        static const int INDEX = 4;
                    };
                    struct ROUTINE_TYPE {
                        static constexpr const char *NAME = "ROUTINE_TYPE";
                        static const int INDEX = 5;
                    };
                    struct DATA_TYPE {
                        static constexpr const char *NAME = "DATA_TYPE";
                        static const int INDEX = 6;
                    };
                    struct CHARACTER_MAXIMUM_LENGTH {
                        static constexpr const char *NAME = "CHARACTER_MAXIMUM_LENGTH";
                        static const int INDEX = 7;
                    };
                    struct CHARACTER_OCTET_LENGTH {
                        static constexpr const char *NAME = "CHARACTER_OCTET_LENGTH";
                        static const int INDEX = 8;
                    };
                    struct NUMERIC_PRECISION {
                        static constexpr const char *NAME = "NUMERIC_PRECISION";
                        static const int INDEX = 9;
                    };
                    struct NUMERIC_SCALE {
                        static constexpr const char *NAME = "NUMERIC_SCALE";
                        static const int INDEX = 10;
                    };
                    struct DATETIME_PRECISION {
                        static constexpr const char *NAME = "DATETIME_PRECISION";
                        static const int INDEX = 11;
                    };
                    struct CHARACTER_SET_NAME {
                        static constexpr const char *NAME = "CHARACTER_SET_NAME";
                        static const int INDEX = 12;
                    };
                    struct COLLATION_NAME {
                        static constexpr const char *NAME = "COLLATION_NAME";
                        static const int INDEX = 13;
                    };
                    struct DTD_IDENTIFIER {
                        static constexpr const char *NAME = "DTD_IDENTIFIER";
                        static const int INDEX = 14;
                    };
                    struct ROUTINE_BODY {
                        static constexpr const char *NAME = "ROUTINE_BODY";
                        static const int INDEX = 15;
                    };
                    struct ROUTINE_DEFINITION {
                        static constexpr const char *NAME = "ROUTINE_DEFINITION";
                        static const int INDEX = 16;
                    };
                    struct EXTERNAL_NAME {
                        static constexpr const char *NAME = "EXTERNAL_NAME";
                        static const int INDEX = 17;
                    };
                    struct EXTERNAL_LANGUAGE {
                        static constexpr const char *NAME = "EXTERNAL_LANGUAGE";
                        static const int INDEX = 18;
                    };
                    struct PARAMETER_STYLE {
                        static constexpr const char *NAME = "PARAMETER_STYLE";
                        static const int INDEX = 19;
                    };
                    struct IS_DETERMINISTIC {
                        static constexpr const char *NAME = "IS_DETERMINISTIC";
                        static const int INDEX = 20;
                    };
                    struct SQL_DATA_ACCESS {
                        static constexpr const char *NAME = "SQL_DATA_ACCESS";
                        static const int INDEX = 21;
                    };
                    struct SQL_PATH {
                        static constexpr const char *NAME = "SQL_PATH";
                        static const int INDEX = 22;
                    };
                    struct SECURITY_TYPE {
                        static constexpr const char *NAME = "SECURITY_TYPE";
                        static const int INDEX = 23;
                    };
                    struct CREATED {
                        static constexpr const char *NAME = "CREATED";
                        static const int INDEX = 24;
                    };
                    struct LAST_ALTERED {
                        static constexpr const char *NAME = "LAST_ALTERED";
                        static const int INDEX = 25;
                    };
                    struct SQL_MODE {
                        static constexpr const char *NAME = "SQL_MODE";
                        static const int INDEX = 26;
                    };
                    struct ROUTINE_COMMENT {
                        static constexpr const char *NAME = "ROUTINE_COMMENT";
                        static const int INDEX = 27;
                    };
                    struct DEFINER {
                        static constexpr const char *NAME = "DEFINER";
                        static const int INDEX = 28;
                    };
                    struct CHARACTER_SET_CLIENT {
                        static constexpr const char *NAME = "CHARACTER_SET_CLIENT";
                        static const int INDEX = 29;
                    };
                    struct COLLATION_CONNECTION {
                        static constexpr const char *NAME = "COLLATION_CONNECTION";
                        static const int INDEX = 30;
                    };
                    struct DATABASE_COLLATION {
                        static constexpr const char *NAME = "DATABASE_COLLATION";
                        static const int INDEX = 31;
                    };
                };

                Routines(std::string &specificName, std::string &routineCatalog, std::string &routineSchema,
                         std::string &routineName, std::string &routineType, std::string &dataType,
                         int characterMaximumLength, int characterOctetLength, long numericPrecision, int numericScale,
                         long datetimePrecision, std::string &characterSetName, std::string &collationName,
                         std::string &dtdIdentifier, std::string &routineBody, std::string &routineDefinition,
                         std::string &externalName, std::string &externalLanguage, std::string &parameterStyle,
                         std::string &isDeterministic, std::string &sqlDataAccess, std::string &sqlPath,
                         std::string &securityType, std::string &created, std::string &lastAltered,
                         std::string &sqlMode,
                         std::string &routineComment, std::string &definer, std::string &characterSetClient,
                         std::string &collationConnection, std::string &databaseCollation)
                        : specificName{specificName}, routineCatalog{routineCatalog}, routineSchema{routineSchema},
                          routineName{routineName}, routineType{routineType}, dataType{dataType},
                          characterMaximumLength{characterMaximumLength}, characterOctetLength{characterOctetLength},
                          numericPrecision{numericPrecision}, numericScale{numericScale},
                          datetimePrecision{datetimePrecision}, characterSetName{characterSetName},
                          collationName{collationName}, dtdIdentifier{dtdIdentifier}, routineBody{routineBody},
                          routineDefinition{routineDefinition}, externalName{externalName},
                          externalLanguage{externalLanguage}, parameterStyle{parameterStyle},
                          isDeterministic{isDeterministic}, sqlDataAccess{sqlDataAccess}, sqlPath{sqlPath},
                          securityType{securityType}, created{created}, lastAltered{lastAltered}, sqlMode{sqlMode},
                          routineComment{routineComment}, definer{definer}, characterSetClient{characterSetClient},
                          collationConnection{collationConnection}, databaseCollation{databaseCollation} {}

                // Get the value of specificName
                const std::string &getSpecificName() const {
                    return specificName;
                }

                // Get the value of routineCatalog
                const std::string &getRoutineCatalog() const {
                    return routineCatalog;
                }

                // Get the value of routineSchema
                const std::string &getRoutineSchema() const {
                    return routineSchema;
                }

                // Get the value of routineName
                const std::string &getRoutineName() const {
                    return routineName;
                }

                // Get the value of routineType
                const std::string &getRoutineType() const {
                    return routineType;
                }

                // Get the value of dataType
                const std::string &getDataType() const {
                    return dataType;
                }

                // Get the value of characterMaximumLength
                int getCharacterMaximumLength() const {
                    return characterMaximumLength;
                }

                // Get the value of characterOctetLength
                int getCharacterOctetLength() const {
                    return characterOctetLength;
                }

                // Get the value of numericPrecision
                long getNumericPrecision() const {
                    return numericPrecision;
                }

                // Get the value of numericScale
                int getNumericScale() const {
                    return numericScale;
                }

                // Get the value of datetimePrecision
                long getDatetimePrecision() const {
                    return datetimePrecision;
                }

                // Get the value of characterSetName
                const std::string &getCharacterSetName() const {
                    return characterSetName;
                }

                // Get the value of collationName
                const std::string &getCollationName() const {
                    return collationName;
                }

                // Get the value of dtdIdentifier
                const std::string &getDtdIdentifier() const {
                    return dtdIdentifier;
                }

                // Get the value of routineBody
                const std::string &getRoutineBody() const {
                    return routineBody;
                }

                // Get the value of routineDefinition
                const std::string &getRoutineDefinition() const {
                    return routineDefinition;
                }

                // Get the value of externalName
                const std::string &getExternalName() const {
                    return externalName;
                }

                // Get the value of externalLanguage
                const std::string &getExternalLanguage() const {
                    return externalLanguage;
                }

                // Get the value of parameterStyle
                const std::string &getParameterStyle() const {
                    return parameterStyle;
                }

                // Get the value of isDeterministic
                const std::string &getIsDeterministic() const {
                    return isDeterministic;
                }

                // Get the value of sqlDataAccess
                const std::string &getSqlDataAccess() const {
                    return sqlDataAccess;
                }

                // Get the value of sqlPath
                const std::string &getSqlPath() const {
                    return sqlPath;
                }

                // Get the value of securityType
                const std::string &getSecurityType() const {
                    return securityType;
                }

                // Get the value of created
                const std::string &getCreated() const {
                    return created;
                }

                // Get the value of lastAltered
                const std::string &getLastAltered() const {
                    return lastAltered;
                }

                // Get the value of sqlMode
                const std::string &getSqlMode() const {
                    return sqlMode;
                }

                // Get the value of routineComment
                const std::string &getRoutineComment() const {
                    return routineComment;
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
                * Returns the table name 'ROUTINES';
                */
                static const char *getDatabaseTableName() {
                    return TABLE_NAME;
                }
            };

        }
    }

}


#endif //DBCRUDGEN_CPP_ROUTINES_H
