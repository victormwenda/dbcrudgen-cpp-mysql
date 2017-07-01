set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#Set the project source files
set(SOURCE_FILES main.cpp)

#Add the Google test directories
add_subdirectory(lib/googletest)

include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)

#Create the executable
add_executable(dbcrudgen_cpp ${SOURCE_FILES})

#Link with GoogleTest
target_link_libraries(dbcrudgen_cpp gtest gtest_main)

#Link with GoogleMock
target_link_libraries(dbcrudgen_cpp gmock gmock_main)
