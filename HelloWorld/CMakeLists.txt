

cmake_minimum_required(VERSION 3.0) #cmake最低版本需求，不加入此行会受到警告信息

project(HELLOWORLD VERSION 1.0.0) #HELLO 项目名称 1.0.0 工程版本号 LANGUAGE CXX为C++

# 使用C++ 14 标准
set(CMAKE_CXX_STANDARD 14)

# default is "Debug"
set(CMAKE_BUILD_TYPE "Debug")
#set(CMAKE_BUILD_TYPE "Release")


if (!CMAKE_BUILD_TYPE STREQUAL "RELEASE")
		add_definitions("-g")
endif()

IF("${CMAKE_BUILD_TYPE}" MATCHES "Debug")
    message(STATUS "building for: debugging")

    ## unfortunately these produce errors
    #include(CheckCXXCompilerFlag)
    #CHECK_CXX_COMPILER_FLAG("-Wformat-signedness" CXX_FORMAT_SIGNEDNESS)
    #CHECK_CXX_COMPILER_FLAG("-Werror=format-security" CXX_FORMAT_SECURITY)
    #CHECK_CXX_COMPILER_FLAG("-fstack-protector-all" CXX_STACK_PROTECTOR)
    set(CXX_FORMAT_SIGNEDNESS "-Wformat-signedness")
    set(CXX_FORMAT_SECURITY "-Werror=format-security")
    set(CXX_STACK_PROTECTOR "-fstack-protector-all")
    set(CXX_FLAGS_DEBUG "-O0")
    set(CMAKE_C_STANDARD 99)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O1 -ggdb -Wall -Wextra -DNETDATA_INTERNAL_CHECKS=1 -DNETDATA_VERIFY_LOCKS=1 ${CXX_FORMAT_SIGNEDNESS} ${CXX_FORMAT_SECURITY} ${CXX_STACK_PROTECTOR} ${CXX_FLAGS_DEBUG}")
ELSE()
    message(STATUS "building for: release")
    cmake_policy(SET CMP0069 "NEW")
    include(CheckIPOSupported)
    check_ipo_supported(RESULT ipo_supported OUTPUT error)
    IF(${ipo_supported})
        message(STATUS "link time optimization: supported")
        set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
    ELSE()
        message(STATUS "link time optimization: not supported")
    ENDIF()
ENDIF()

find_package(Threads REQUIRED)

#include_directories(${INC_LIST})
#include_directories(${PROJECT_SOURCE_DIR}/inc)
include_directories(
    ./inc #CMakeLists.txt同级目录的头文件
    ./processtest/inc #processtest目录头文件
    ./stltest #stltest目录头文件
    ./threadtest #threadtest目录头文件
)

MESSAGE(STATUS "root cmakelist.txt processtest头文件路径 :${PROCESS_TEST_INC_DIR}")

#把当前目录(.)下所有源代码文件和头文件加入变量SRC_LIST
aux_source_directory(.  SRC_LIST)
aux_source_directory(./src SRC_LIST)
aux_source_directory(./stltest  SRC_LIST)
aux_source_directory(./threadtest  SRC_LIST)

#生成应用程序 helloworld
add_executable(${PROJECT_NAME} ${SRC_LIST})

#target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/inc)
#include_directories(${PROJECT_SOURCE_DIR}/inc)与target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/inc)效果相同

#设置编译时依赖的静态库
target_link_libraries(${PROJECT_NAME}
    processtest#
)

#设置编译时依赖的静态库线程库
target_link_libraries(${PROJECT_NAME}
        Threads::Threads
)

#调用processtest子目录中的CMakeLists.txt，生成静态库而不生成新目标，目标与主CMakeLists.txt中设定的一致
add_subdirectory(processtest)
