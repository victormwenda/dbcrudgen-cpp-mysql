//
// Created by victor on 2/24/21.
//

#ifndef DBCRUDGEN_CPP_DATABASEUTILS_H
#define DBCRUDGEN_CPP_DATABASEUTILS_H

#include "../generic/Flavor.h"

namespace dbcrudgen {
    namespace db {
        class DatabaseUtils {
        public:

            /**
             * Get database type
             * @param flavor
             * @return
             */
            static std::string
            getDbType(const db::generic::Flavor &flavor) {

                switch (flavor) {
                    case db::generic::Flavor::MSSQL:
                        return std::string{"MSSQL"};
                    case db::generic::Flavor::MYSQL:
                        return std::string{"MYSQL"};
                    case db::generic::Flavor::ORACLE:
                        return std::string{"ORACLE"};
                    case db::generic::Flavor::SQLITE:
                        return std::string{"SQLITE"};
                    case db::generic::Flavor::DB2:
                        return std::string{"DB2"};
                    case db::generic::Flavor::DB2_AS_400:
                        return std::string{"DB2_400"};
                    case db::generic::Flavor::DB2_OS390:
                        return std::string{"DB2_390"};
                    case db::generic::Flavor::INGRES:
                        return std::string{"DB2_390"};
                    case db::generic::Flavor::ORACLE_9I:
                        return std::string{"ORACLE"};
                    case db::generic::Flavor::ORACLE_10G:
                        return std::string{"ORACLE"};
                    case db::generic::Flavor::POSTGRESQL:
                        return std::string{"POSTGRESQL"};
                    case db::generic::Flavor::SAP_DB:
                        return std::string{"SAP"};
                    case db::generic::Flavor::SYBASE:
                        return std::string{"SYBASE"};
                    case db::generic::Flavor::SYBASE_ANYWHERE:
                        return std::string{"SYBASE_ANYWHERE"};
                }

                return std::string();
            }


            /**
             * Generate database connection string for use in java projects
             * @param flavor
             * @param host
             * @param port
             * @param user
             * @param password
             * @return
             */
            static std::string
            genDbConnStrJava(const db::generic::Flavor &flavor, const std::string &host, int port,
                             const std::string &user, const std::string &password, const std::string &dbName) {

                switch (flavor) {
                    case db::generic::Flavor::MSSQL:
                        return genMsSQLConnStrJava(host, port, user, password, dbName);
                    case db::generic::Flavor::MYSQL:
                        return genMySQLConnStrJava(host, port, dbName);
                    case db::generic::Flavor::ORACLE:
                        return genOracleConnStrJava(host, port, dbName);
                    case db::generic::Flavor::SQLITE:
                        return genSQLiteConnStrJava(dbName);
                    case db::generic::Flavor::DB2:
                        return std::string{};
                    case db::generic::Flavor::DB2_AS_400:
                        return std::string{};
                    case db::generic::Flavor::DB2_OS390:
                        return std::string{};
                    case db::generic::Flavor::INGRES:
                        return std::string{};
                    case db::generic::Flavor::ORACLE_9I:
                        return std::string{};
                    case db::generic::Flavor::ORACLE_10G:
                        return std::string{};
                    case db::generic::Flavor::POSTGRESQL:
                        return std::string{};
                    case db::generic::Flavor::SAP_DB:
                        return std::string{};
                    case db::generic::Flavor::SYBASE:
                        return std::string{};

                    case db::generic::Flavor::SYBASE_ANYWHERE:
                        return std::string{};
                }

                return std::string();
            }


            /**
             * Create MSSQL Connection String
             * @param host
             * @param port
             * @param user
             * @param password
             * @param dbName
             * @return
             */
            static std::string genMsSQLConnStrJava(const std::string &host, const int port, const std::string &user,
                                                   const std::string &password, const std::string &dbName) {
                std::string connStr =
                        "jdbc:sqlserver://" + host + ":" + std::to_string(port) + ";databaseName=" + dbName + ";user=" +
                        user + ";password=" + password;
                return connStr;
            }

            /**
             * Create MYSQL Connection String
             * @param host
             * @param port
             * @param dbName
             * @return
             */
            static std::string genMySQLConnStrJava(const std::string &host, const int port, const std::string &dbName) {
                std::string connStr = "jdbc:mysql://" + host + ":" + std::to_string(port) + "/" + dbName +
                                      "?autoReconnect=true&useSSL=false";
                return connStr;
            }

            /**
             * Create oracle connection string
             * @param host
             * @param port
             * @param dbName
             * @return
             */
            static std::string
            genOracleConnStrJava(const std::string &host, const int port, const std::string &dbName) {
                std::string connStr = "jdbc:oracle:thin:@" + host + ":" + std::to_string(port) + ":" + dbName;
                return connStr;
            }

            /**
             * Create SQLite Connection String
             * @param dbName
             * @return
             */
            static std::string genSQLiteConnStrJava(const std::string &dbName) {
                std::string connStr = "jdbc:sqlite:" + dbName;
                return connStr;
            }

            /**
             * Get database type
             * @param flavor
             * @return
             */
            static std::string
            getHibernateDialect(const db::generic::Flavor &flavor) {

                switch (flavor) {

                    case db::generic::Flavor::DB2:
                        return std::string{"org.hibernate.dialect.DB2Dialect"};
                    case db::generic::Flavor::DB2_AS_400:
                        return std::string{"org.hibernate.dialect.DB2400Dialect"};
                    case db::generic::Flavor::DB2_OS390:
                        return std::string{"org.hibernate.dialect.DB2390Dialect"};
                    case db::generic::Flavor::INGRES:
                        return std::string{"org.hibernate.dialect.IngresDialect"};
                    case db::generic::Flavor::MYSQL:
                        return std::string{"org.hibernate.dialect.MySQLDialect"};
                    case db::generic::Flavor::MSSQL:
                        return std::string{"org.hibernate.dialect.SQLServerDialect"};
                    case db::generic::Flavor::ORACLE:
                        return std::string{"org.hibernate.dialect.OracleDialect"};
                    case db::generic::Flavor::ORACLE_9I:
                        return std::string{"org.hibernate.dialect.Oracle9iDialect"};
                    case db::generic::Flavor::ORACLE_10G:
                        return std::string{"org.hibernate.dialect.Oracle10gDialect"};
                    case db::generic::Flavor::POSTGRESQL:
                        return std::string{"org.hibernate.dialect.PostgreSQLDialect"};
                    case db::generic::Flavor::SAP_DB:
                        return std::string{"org.hibernate.dialect.SAPDBDialect"};
                    case db::generic::Flavor::SYBASE:
                        return std::string{"org.hibernate.dialect.SybaseDialect"};
                    case db::generic::Flavor::SYBASE_ANYWHERE:
                        return std::string{"org.hibernate.dialect.SybaseAnywhereDialect"};
                    case db::generic::Flavor::SQLITE:
                        return std::string{"org.hibernate.dialect.SQLiteDialect"};

                }

                return std::string();
            }
        };
    }
}


#endif //DBCRUDGEN_CPP_DATABASEUTILS_H
