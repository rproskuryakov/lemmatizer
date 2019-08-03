cmake_minimum_required(VERSION 3.1)

# Задать характеристики проекта "MyProject":
project(Lemmatizer VERSION 1.0 LANGUAGES CXX)


find_package (Boost 1.70.0 COMPONENTS PYTHON REQUIRED)


include_directories("include" "src")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

add_executable(main src/main.cpp src/trie.cpp src/wrap.cpp)

target_link_libraries(main Boost::python) # ${PTHREAD_LIBRARY} ${PCRE_LIBRARY}