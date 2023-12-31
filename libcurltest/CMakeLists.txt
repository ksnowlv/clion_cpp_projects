cmake_minimum_required(VERSION 3.16)
project(libcurltest)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# curl lib
find_path(CURL_INCLUDE_DIR curl/curl.h)
find_library(CURL_LIBRARY NAMES curl)
include_directories(${CURL_INCLUDE_DIR}
                    lib)

add_executable(libcurltest main.cpp
        CurlTest.h
        CurlTest.cpp)

# curl lib
target_link_libraries(${PROJECT_NAME} ${CURL_LIBRARY})

# 添加rapidjson库
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib/rapidjson)
