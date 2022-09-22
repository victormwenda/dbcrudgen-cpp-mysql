# DbCrudGen-CPP

Database CRUD Generators written in C++

Generates Database CRUD codes for various Databases

## Supported databases
 - MYSQL
 - ORACLE
 - SQLITE
  
## Supported CRUD's
 - Android
 - Angular
 - C++
 - Java (J2SE, Jax-Rs)
 - Python
 - PHP (Laravel)
 - Swift
  
DbCrudGen helps to improve the whole developer workflow of embedding a database in your application.
  
It allows connecting to one of the supported Databases and creating CRUD code's for the target supported platforms.

## External libraries
- Googletest - Google C++ Unit testing library
- Benchmark - Google C++ benchmarking library


## Common Configuration Errors
### MacOs
- dyld: Library not loaded
  - Ensure the named library is added on /usr/local/lib or /usr/lib directory or other relevant lib directories
- ld symbol(s) not found for architecture x86_64 clang: error: linker command failed with exit code 1
  - The named shared library is not linked with the executable. Use cmake target_link_libraries function or add the linked library to the compiler command.
    
