CREATE TABLE bug_logger
  (
     id_bug                   NUMBER(10) NOT NULL,
     parent_error_code        NUMBER(10) NOT NULL,
     child_error_code         NUMBER(10) NOT NULL,
     stack_trace              VARCHAR2(1024) NOT NULL,
     message                  VARCHAR2(1024) NOT NULL,
     authenticated_email      VARCHAR2(128) NOT NULL,
     device_uuid              VARCHAR2(128) NOT NULL,
     application_version_name VARCHAR2(128) NOT NULL,
     application_version_code NUMBER(10) NOT NULL,
     local_event_time         TIMESTAMP NOT NULL
  );

INSERT INTO bug_logger (id_bug, parent_error_code, child_error_code, stack_trace, message, authenticated_email, device_uuid, application_version_name, application_version_code, local_event_time) VALUES (1, 1, 1, 'error: invalid initialization of reference of type ', 'error: invalid initialization of reference of type ', 'vmwenda.vm@gmail.com', 'ahUKEwia5oyV17DVAhXDJMAKHfR1BZ8QFggnMAA', 'alpha-01', 1, SYSDATE);

select * from user_tables;

select * from dba_tables where lower(owner) = 'victor';

select username from dba_users;

select * from victor.bug_logger;


SELECT DBMS_METADATA.GET_DDL('TABLE', 'BUG_LOGGER','VICTOR' ) FROM DUAL;

 SELECT object_type type, owner  owner, object_name, null column_name, null column_id, null data_type 
FROM all_objects ;

 SELECT *
FROM all_objects where object_name = 'BUG_LOGGER';


SELECT  LEVEL, 'VICTOR' FIRSTNAME, 'MWENDA' LASTNAME FROM DUAL
CONNECT BY LEVEL <=10;

SELECT LEVEL just_a_column
FROM dual
CONNECT BY LEVEL <= 365;

SELECT TRUNC(SYSDATE,'Y')+ROWNUM-1 THEDATE
FROM   ( SELECT 1 just_a_column
         FROM dual
         CONNECT BY LEVEL <= 366
       )
WHERE  ROWNUM <= ADD_MONTHS(TRUNC(SYSDATE,'Y'),12)-TRUNC(SYSDATE,'Y');
