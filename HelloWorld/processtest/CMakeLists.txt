

#1.将本目录中的.c文件加入到PROCESS_TEST_SRC_LIST
aux_source_directory(. PROCESS_TEST_SRC_LIST)
aux_source_directory(./src PROCESS_TEST_SRC_LIST)

# set(PROCESS_TEST_INC_DIR
#     $(CMAKE_CURRENT_SOURCE_DIR) #当前源文件路径
#     CACHE INTERNAL "processtest include dir"
# )


# include_directories(
#     ${PROCESS_TEST_INC_DIR}#上层头文件
#     ${PROCESS_TEST_INC_DIR}/inc#上层头文件
# )

MESSAGE(STATUS "processtest头文件路径 :${PROCESS_TEST_INC_DIR}")


#生成静态库
add_library(processtest ${PROCESS_TEST_SRC_LIST})

