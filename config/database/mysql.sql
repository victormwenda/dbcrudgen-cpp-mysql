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
