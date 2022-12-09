create database dbcrudgen;

use dbcrudgen;

create table test
(
    id     INT NOT NULL IDENTITY (1,1) PRIMARY KEY,
    module varchar(255)
);