# Author Jack
# Created 2019-04-23

cmake_minimum_required(VERSION 3.12)

# 查找当前目录下的所有源文件，并将名称保存到DIR_LIB_DIVIDE_SRCS变量中
aux_source_directory(. DIR_LIB_MATH_SRC)

# 指定生成目标
add_library(math ${DIR_LIB_MATH_SRC})