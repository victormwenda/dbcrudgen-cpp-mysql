//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 4/14/18.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_MYSQLKEYCOLUMNUSAGE_H
#define DBCRUDGEN_CPP_MYSQLKEYCOLUMNUSAGE_H

#include <string>

//
// MysqlKeyColumnUsage
//
// Constains the key column usage of all the database table columns //
class MysqlKeyColumnUsage {

public:
    std::string constraintCatalog;
    std::string constraintSchema;
    std::string constraintName;
    std::string tableCatalog;
    std::string tableSchema;
    std::string tableName;
    std::string columnName;
    long int ordinalPosition;
    long int positionInUniqueConstraint;
    std::string referencedTableSchema;
    std::string referencedTableName;
    std::string referencedColumnName;


    MysqlKeyColumnUsage(std::string &constraintCatalog, std::string &constraintSchema, std::string &constraintName,
                        std::string &tableCatalog, std::string &tableSchema, std::string &tableName,
                        std::string &columnName, long int &ordinalPosition, long int &positionInUniqueConstraint,
                        std::string &referencedTableSchema, std::string &referencedTableName,
                        std::string &referencedColumnName) : constraintCatalog(constraintCatalog),
                                                             constraintSchema(constraintSchema),
                                                             constraintName(constraintName), tableCatalog(tableCatalog),
                                                             tableSchema(tableSchema), tableName(tableName),
                                                             columnName(columnName), ordinalPosition(ordinalPosition),
                                                             positionInUniqueConstraint(positionInUniqueConstraint),
                                                             referencedTableSchema(referencedTableSchema),
                                                             referencedTableName(referencedTableName),
                                                             referencedColumnName(referencedColumnName) {}
    const std::string &getConstraintCatalog() const {
        return constraintCatalog;
    }

    void setConstraintCatalog(const std::string &constraintCatalog) {
        MysqlKeyColumnUsage::constraintCatalog = constraintCatalog;
    }

    const std::string &getConstraintSchema() const {
        return constraintSchema;
    }

    void setConstraintSchema(const std::string &constraintSchema) {
        MysqlKeyColumnUsage::constraintSchema = constraintSchema;
    }

    const std::string &getConstraintName() const {
        return constraintName;
    }

    void setConstraintName(const std::string &constraintName) {
        MysqlKeyColumnUsage::constraintName = constraintName;
    }

    const std::string &getTableCatalog() const {
        return tableCatalog;
    }

    void setTableCatalog(const std::string &tableCatalog) {
        MysqlKeyColumnUsage::tableCatalog = tableCatalog;
    }

    const std::string &getTableSchema() const {
        return tableSchema;
    }

    void setTableSchema(const std::string &tableSchema) {
        MysqlKeyColumnUsage::tableSchema = tableSchema;
    }

    const std::string &getTableName() const {
        return tableName;
    }

    void setTableName(const std::string &tableName) {
        MysqlKeyColumnUsage::tableName = tableName;
    }

    const std::string &getColumnName() const {
        return columnName;
    }

    void setColumnName(const std::string &columnName) {
        MysqlKeyColumnUsage::columnName = columnName;
    }

    long getOrdinalPosition() const {
        return ordinalPosition;
    }

    void setOrdinalPosition(long ordinalPosition) {
        MysqlKeyColumnUsage::ordinalPosition = ordinalPosition;
    }

    long getPositionInUniqueConstraint() const {
        return positionInUniqueConstraint;
    }

    void setPositionInUniqueConstraint(long positionInUniqueConstraint) {
        MysqlKeyColumnUsage::positionInUniqueConstraint = positionInUniqueConstraint;
    }

    const std::string &getReferencedTableSchema() const {
        return referencedTableSchema;
    }

    void setReferencedTableSchema(const std::string &referencedTableSchema) {
        MysqlKeyColumnUsage::referencedTableSchema = referencedTableSchema;
    }

    const std::string &getReferencedTableName() const {
        return referencedTableName;
    }

    void setReferencedTableName(const std::string &referencedTableName) {
        MysqlKeyColumnUsage::referencedTableName = referencedTableName;
    }

    const std::string &getReferencedColumnName() const {
        return referencedColumnName;
    }

    void setReferencedColumnName(const std::string &referencedColumnName) {
        MysqlKeyColumnUsage::referencedColumnName = referencedColumnName;
    }
};


#endif //DBCRUDGEN_CPP_MYSQLKEYCOLUMNUSAGE_H
