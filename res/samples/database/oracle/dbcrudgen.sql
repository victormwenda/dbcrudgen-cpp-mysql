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

INSERT INTO bug_logger (ID_BUG, PARENT_ERROR_CODE, CHILD_ERROR_CODE, STACK_TRACE, MESSAGE, AUTHENTICATED_EMAIL, DEVICE_UUID, APPLICATION_VERSION_NAME, APPLICATION_VERSION_CODE, LOCAL_EVENT_TIME) VALUES ('1', '1', '1', 'terminate called after throwing an instance of ''oracle::occi::SQLException''', 'terminate called after throwing an instance of ''oracle::occi::SQLException''', 'vmwenda.vm@gmail.com', 'ahUKEwia5oyV17DVAhXDJMAKHfR1BZ8QFggnMAA', 'alpha-01', '1', TO_TIMESTAMP('2019-07-14 18:25:35.000000000', 'YYYY-MM-DD HH24:MI:SS.FF'))

