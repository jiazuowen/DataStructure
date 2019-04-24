# Author Jack
# Created 2019-04-23

cmake_minimum_required(VERSION 3.12)

# 项目名称
project(DataStructureLearn)

# 添加头文件目录
include_directories(
    ./datastructure
    ./math
)

# # 查找当前目录下的所有源文件，并将名称保存到DIR_SRCS变量中
# aux_source_directory(. DIR_SRCS)

# # 指定生成目标
# add_executable(test ${DIR_SRCS})

add_executable(test test.cpp)
add_executable(testjac testjac.cpp)

# 添加子目录
add_subdirectory(math)
add_subdirectory(datastructure)

# 添加连接库
target_link_libraries(test math)
target_link_libraries(test datastructure)
target_link_libraries(testjac math)
target_link_libraries(testjac datastructure)