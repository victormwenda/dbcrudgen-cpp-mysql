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
drop table test;
create table test (username varchar(128));
select * from test;
truncate table test;
while 1 = 1
insert into test values ( convert(varchar, getdate(),13)  );
select convert(varchar,getdate(),13);