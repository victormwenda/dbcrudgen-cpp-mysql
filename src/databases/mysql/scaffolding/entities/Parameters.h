//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_PARAMETERS_H
#define DBCRUDGEN_CPP_PARAMETERS_H

#include <string>

namespace dbcrudgen {
    namespace db {
        namespace mysql {
            class Parameters {

            private:
                std::string specificCatalog;
                std::string specificSchema;
                std::string specificName;
                int ordinalPosition;
                std::string parameterMode;
                std::string parameterName;
                std::string dataType;
                int characterMaximumLength;
                int characterOctetLength;
                long numericPrecision;
                int numericScale;
                long datetimePrecision;
                std::string characterSetName;
                std::string collationName;
                std::string dtdIdentifier;
                std::string routineType;

            public:

                static constexpr const char *TABLE_NAME = "PARAMETERS";

                struct COLUMNS {
                    struct SPECIFIC_CATALOG {
                        static constexpr const char *NAME = "SPECIFIC_CATALOG";
                        static const int INDEX = 1;
                    };
                    struct SPECIFIC_SCHEMA {
                        static constexpr const char *NAME = "SPECIFIC_SCHEMA";
                        static const int INDEX = 2;
                    };
                    struct SPECIFIC_NAME {
                        static constexpr const char *NAME = "SPECIFIC_NAME";
                        static const int INDEX = 3;
                    };
                    struct ORDINAL_POSITION {
                        static constexpr const char *NAME = "ORDINAL_POSITION";
                        static const int INDEX = 4;
                    };
                    struct PARAMETER_MODE {
                        static constexpr const char *NAME = "PARAMETER_MODE";
                        static const int INDEX = 5;
                    };
                    struct PARAMETER_NAME {
                        static constexpr const char *NAME = "PARAMETER_NAME";
                        static const int INDEX = 6;
                    };
                    struct DATA_TYPE {
                        static constexpr const char *NAME = "DATA_TYPE";
                        static const int INDEX = 7;
                    };
                    struct CHARACTER_MAXIMUM_LENGTH {
                        static constexpr const char *NAME = "CHARACTER_MAXIMUM_LENGTH";
                        static const int INDEX = 8;
                    };
                    struct CHARACTER_OCTET_LENGTH {
                        static constexpr const char *NAME = "CHARACTER_OCTET_LENGTH";
                        static const int INDEX = 9;
                    };
                    struct NUMERIC_PRECISION {
                        static constexpr const char *NAME = "NUMERIC_PRECISION";
                        static const int INDEX = 10;
                    };
                    struct NUMERIC_SCALE {
                        static constexpr const char *NAME = "NUMERIC_SCALE";
                        static const int INDEX = 11;
                    };
                    struct DATETIME_PRECISION {
                        static constexpr const char *NAME = "DATETIME_PRECISION";
                        static const int INDEX = 12;
                    };
                    struct CHARACTER_SET_NAME {
                        static constexpr const char *NAME = "CHARACTER_SET_NAME";
                        static const int INDEX = 13;
                    };
                    struct COLLATION_NAME {
                        static constexpr const char *NAME = "COLLATION_NAME";
                        static const int INDEX = 14;
                    };
                    struct DTD_IDENTIFIER {
                        static constexpr const char *NAME = "DTD_IDENTIFIER";
                        static const int INDEX = 15;
                    };
                    struct ROUTINE_TYPE {
                        static constexpr const char *NAME = "ROUTINE_TYPE";
                        static const int INDEX = 16;
                    };
                };

                Parameters(std::string &specificCatalog, std::string &specificSchema, std::string &specificName,
                           int ordinalPosition, std::string &parameterMode, std::string &parameterName,
                           std::string &dataType, int characterMaximumLength, int characterOctetLength,
                           long numericPrecision, int numericScale, long datetimePrecision,
                           std::string &characterSetName,
                           std::string &collationName, std::string &dtdIdentifier, std::string &routineType)
                        : specificCatalog{specificCatalog}, specificSchema{specificSchema}, specificName{specificName},
                          ordinalPosition{ordinalPosition}, parameterMode{parameterMode}, parameterName{parameterName},
                          dataType{dataType}, characterMaximumLength{characterMaximumLength},
                          characterOctetLength{characterOctetLength}, numericPrecision{numericPrecision},
                          numericScale{numericScale}, datetimePrecision{datetimePrecision},
                          characterSetName{characterSetName}, collationName{collationName},
                          dtdIdentifier{dtdIdentifier},
                          routineType{routineType} {}

                // Get the value of specificCatalog
                const std::string &getSpecificCatalog() const {
                    return specificCatalog;
                }

                // Get the value of specificSchema
                const std::string &getSpecificSchema() const {
                    return specificSchema;
                }

                // Get the value of specificName
                const std::string &getSpecificName() const {
                    return specificName;
                }

                // Get the value of ordinalPosition
                int getOrdinalPosition() const {
                    return ordinalPosition;
                }

                // Get the value of parameterMode
                const std::string &getParameterMode() const {
                    return parameterMode;
                }

                // Get the value of parameterName
                const std::string &getParameterName() const {
                    return parameterName;
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

                // Get the value of routineType
                const std::string &getRoutineType() const {
                    return routineType;
                }

                /**
                * Returns the table name 'PARAMETERS';
                */
                static const char *getDatabaseTableName() {
                    return TABLE_NAME;
                }
            };
        }
    }

}


#endif //DBCRUDGEN_CPP_PARAMETERS_H
