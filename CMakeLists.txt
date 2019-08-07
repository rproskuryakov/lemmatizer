cmake_minimum_required(VERSION 3.1)

# Project options
project(Lemmatizer VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES src/Trie.cpp tests/trie_test.cpp)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  build/)

#find_package (Boost 1.70.0 COMPONENTS PYTHON REQUIRED)

#adding google_test
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)



include_directories("include" "src" "tests")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

add_executable(main ${SOURCE_FILES})
#add_library(mylib )
#target_link_libraries(main Boost::python) # ${PTHREAD_LIBRARY} ${PCRE_LIBRARY}
#linking google_test
target_link_libraries(main gtest)