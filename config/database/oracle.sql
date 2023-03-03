create user dbcrudgen identified  by "Root@3358";

grant connect to dbcrudgen;

GRANT CONNECT, RESOURCE, DBA TO dbcrudgen;

GRANT CREATE SESSION TO dbcrudgen;

GRANT all PRIVILEGES TO dbcrudgen;

GRANT UNLIMITED TABLESPACE TO dbcrudgen;