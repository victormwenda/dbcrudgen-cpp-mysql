## Configuring the Oracle Development Environment

#### Install alien to help in installing .rpm files on Debian Linux.

- [x] ```sudo apt-get install alien```

#### Install the rpm files using alien
- [x] ```sudo alien -i oracle-instantclient*-basic*.rpm```
- [x] ```sudo alien -i oracle-instantclient*-sqlplus*.rpm```
- [x] ```sudo alien -i oracle-instantclient*-devel*.rpm```


#### Install libaio.so

- [x] ```sudo apt-get install libaio1```

#### Create Oracle configuration file:
- [x] ```sudo vi /etc/ld.so.conf.d/oracle.conf```

Put this line in that file:
- [x] ```/usr/lib/oracle/<your version>/client/lib/```

Note – for 64-bit installations, the path will be:
- [x] ```/usr/lib/oracle/<your version>/client64/lib/```

#### Update the configuration by running following command:
- [x] ```sudo ldconfig```


##### Shorthand
 - [x] ``` sudo sh -c "echo /usr/lib/oracle/XX.X/client64/lib > /etc/ld.so.conf.d/oracle-instantclient.conf" sudo ldconfig ```

#### Testing:
Try to connect using:

- [x] ```sqlplus username/password@//dbhost:1521/SID```

or:

- [x] ```sqlplus testuser/password```
