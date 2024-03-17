create database if not exists dbcrudgen;

use dbcrudgen;

create table if not exists test
(
    id     int primary key auto_increment,
    module text
);

create table if not exists packages
(
    id   int primary key auto_increment,
    name text,
    path text,
    index (id)
);
create table if not exists classes
(
    id         int primary key auto_increment,
    name       text,
    package_id int,
    index (id),
    foreign key (package_id)
        references packages (id)
);
create table if not exists class_methods
(
    id          int primary key auto_increment,
    name        text,
    return_type text,
    class_id    int,
    index (id),
    foreign key (class_id) references classes (id)
);
create table if not exists class_variables
(
    id        int primary key auto_increment,
    name      text,
    data_type text,
    class_id  int,
    index (id),
    foreign key (class_id) references classes (id)
);
create table if not exists method_variables
(
    id             int primary key auto_increment,
    name           text,
    data_type      text,
    method_id      int,
    variable_index int,
    index (id),
    foreign key (method_id) references class_methods (id)
);

-- Show Events
SELECT *
FROM information_schema.EVENTS;

CREATE EVENT IF NOT EXISTS monthly_db_cleanup ON SCHEDULE EVERY 1 MONTH DO TRUNCATE TABLE test;

-- Functions/Procedures - Routines
SHOW PROCEDURE STATUS;
SHOW FUNCTION STATUS;
select *
from mysql.procs_priv;

select *
from information_schema.ROUTINES;

select distinct ROUTINE_TYPE
from information_schema.ROUTINES;

select *
from information_schema.ROUTINES
where ROUTINE_TYPE = 'FUNCTION';

select *
from information_schema.ROUTINES
where ROUTINE_TYPE = 'PROCEDURE';

-- Resource Groups
show create table information_schema.RESOURCE_GROUPS;
select * from information_schema.RESOURCE_GROUPS;

