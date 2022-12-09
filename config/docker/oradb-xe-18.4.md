#### Installing oracle-xe-18.04

- [x] Clone the oracle docker images

    ```$ git clone https://github.com/oracle/docker-images.git```


- [x] Open the docker files dir

    ```$ cd /opt/oracle/docker-images/OracleDatabase/SingleInstance/dockerfiles```

- [x] Build oracle xe 18.4

    ```$ ./buildDockerImage.sh -v 18.4.0 -x```
    
    
- [x] use Docker run to start an Oracle Database Express Edition container

    ```$ docker run --name dbcrdugen \
             -d \
             -p 1521:1521 \
             -p 5500:5500 \
             -e ORACLE_PWD=Root@3358 \
             -e ORACLE_CHARACTERSET=AL32UTF8 \
             oracle/database:18.4.0-xe  ```