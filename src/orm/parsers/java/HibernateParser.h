//
// Created by victor on 4/15/20.
//

#ifndef DBCRUDGEN_CPP_HIBERNATEPARSER_H
#define DBCRUDGEN_CPP_HIBERNATEPARSER_H

#include "JavaParser.h"


namespace dbcrudgen {
    namespace orm {
        class HibernateParser : public JavaParser {
        public:

            /**
             * Parse the hibernate connection script
             * @param configSource
             * @param model
             * @param database
             * @param entityMappings
             * @return
             */
            static std::string
            parseConnectionScript(std::string configSource, const JaxRsProjectModel &model,
                                  const db::generic::Database &database, const std::string &entityMappings) {

                db::generic::Flavor flavor = database.getFlavor();

                std::string connectorDriver = getDatabaseDriverManager(flavor);
                std::string connectionString = getDatabaseConnectionString(flavor);
                std::string hibernateDialect = getHibernateDialect(flavor);

                connectionString = parseConnectionString(database.getConnection(), connectionString);

                StringUtils::replace(configSource, "${USER}", database.getConnection().getUser());
                StringUtils::replace(configSource, "${PASSWORD}", database.getConnection().getPassword());


                StringUtils::replace(configSource, "${DRIVER_CLASS}", connectorDriver);
                StringUtils::replace(configSource, "${CONNECTION_STRING}", connectionString);
                StringUtils::replace(configSource, "${HIBERNATE_DIALECT}", hibernateDialect);

                StringUtils::replace(configSource, " ${ENTITY_MAPPINGS}", entityMappings);

                return configSource;
            }

            /**
             * Parse the connection string
             *
             * @param connection
             * @param connectionString
             * @return
             */
            static std::string parseConnectionString(db::generic::Connection connection, std::string connectionString) {

                connectionString = StringUtils::replace(connectionString, "${HOST}", connection.getHost());
                connectionString = StringUtils::replace(connectionString, "${PORT}",
                                                        std::to_string(connection.getPort()));
                connectionString = StringUtils::replace(connectionString, "${DATABASE}", connection.getDatabase());

                return connectionString;
            }

            /**
             * Get the hibernate Framework for a database
             * @param flavor
             * @return
             */
            static std::string getHibernateDialect(db::generic::Flavor flavor) {
                switch (flavor) {
                    case db::generic::Flavor::MYSQL:
                        return std::string{"org.hibernate.dialect.MySQLDialect"};
                    case db::generic::Flavor::MSSQL:
                        return std::string{"org.hibernate.dialect.SQLServerDialect"};
                    case db::generic::Flavor::ORACLE:
                        return std::string{"org.hibernate.dialect.Oracle12cDialect"};
                    case db::generic::Flavor::SQLITE:
                        return std::string{"org.hibernate.dialect.HSQLDialect"};
                }
            }

            /**
             * Parse the entity class mapping
             * @param mappingSource
             * @param projectPkg
             * @param entityPkg
             * @param entityClass
             * @return
             */
            static std::string
            parseEntityClassMapping(std::string mappingSource, const std::string projectPkg,
                                    const std::string entityPkg, std::string entityClass) {
                mappingSource = StringUtils::replace(mappingSource, "${PROJECT_PACKAGE}", projectPkg);
                mappingSource = StringUtils::replace(mappingSource, "${ENTITY_PACKAGE}", entityPkg);
                mappingSource = StringUtils::replace(mappingSource, "${ENTITY_CLASS}", entityClass);
                return mappingSource;
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_HIBERNATEPARSER_H
