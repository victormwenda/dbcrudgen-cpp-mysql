-- Select all databases
select * from sys.databases;
select * from sys.tables;
select * from sys.columns;
select * from sys.syscerts;
SELECT * FROM INFORMATION_SCHEMA.COLUMNS;
select * from INFORMATION_SCHEMA.TABLES;
SELECT OBJECT_DEFINITION(OBJECT_ID('INFORMATION_SCHEMA.TABLES'));
create database dbcrudgen;
use dbcrudgen;
create table test (username varchar);
drop table test;