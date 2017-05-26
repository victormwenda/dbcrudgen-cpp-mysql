cmake_minimum_required(VERSION 3.7)

project(dbcrudgen_cpp)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lsqlite3")

set(SOURCE_FILES main.cpp core/cli/CliParser.h core/crud/actions/DatabaseCrudActions.h core/io/FilesReader.h core/io/FilesWriter.h core/io/FilesManager.h)

add_executable(dbcrudgen_cpp ${SOURCE_FILES})



