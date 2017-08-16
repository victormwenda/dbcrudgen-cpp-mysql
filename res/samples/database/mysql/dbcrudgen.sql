CREATE TABLE `bug_logger` (
  `id_bug` int(11) NOT NULL,
  `parent_error_code` int(11) NOT NULL,
  `child_error_code` int(11) NOT NULL,
  `stack_trace` text NOT NULL,
  `message` text NOT NULL,
  `authenticated_email` text NOT NULL,
  `device_uuid` text NOT NULL,
  `application_version_name` text NOT NULL,
  `application_version_code` int(11) NOT NULL,
  `local_event_time` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1
InnoDB DEFAULT CHARSET=latin1