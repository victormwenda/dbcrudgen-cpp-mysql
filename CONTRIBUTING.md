# Contribution

Unfortunately this is a personal project and am not actively accepting any good contributions at the moment until the whole MVP is done!

#How to build.

Checkout the project

Go to CMakeLists.txt

    1) Add the path to your gcc-4.8 install dir

    2) Add the path to your mysql-connector-cpp libs

    3) Add the path to your oracle instant client libs

    4) Add the path to your OCI libs both libocci and libclntsh

    5) Include the MYSQL header files to your project

    6) Include the Oracle header files to your project

    7) Install Sqlite3 to your PC (sudo apt-get install libsqlite3-dev)

    8) Add libnnz11.so to your environment variables

    9) Add other required libs to your LD_LIBRARY_PATH

    10) Set your project path on CMakeLists ==> set(PROJECT_DIR PROJECT _PATH) #Replace with the path to your project
Build your project