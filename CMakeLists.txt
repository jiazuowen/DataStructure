# Author Jack
# Created 2019-04-23

# cmake版本要求
cmake_minimum_required(VERSION 3.12)

# 项目名称
project(DataStructureLearn)

# 打开测试功能
include(CTest)
enable_testing()

# 添加子目录
add_subdirectory(math)
add_subdirectory(datastructure)
add_subdirectory(mytest)