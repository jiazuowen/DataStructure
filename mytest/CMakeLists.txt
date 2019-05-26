# Author Jack
# Created 2019-04-25

cmake_minimum_required(VERSION 3.12)

# 添加头文件目录
include_directories(
    ../datastructure
    ../math
)

# 可执行项目
add_executable(testjac testjac.cpp)
# 添加连接库
target_link_libraries(testjac math)
target_link_libraries(testjac datastructure)

# 添加测试
add_test(test_jacstack testjac "1" "40000")
set_tests_properties(test_jacstack PROPERTIES PASS_REGULAR_EXPRESSION "ok")
add_test(test_jaclist testjac "2" "40000")
set_tests_properties(test_jaclist PROPERTIES PASS_REGULAR_EXPRESSION "ok")
add_test(test_jacqueue testjac "3" "40000")
set_tests_properties(test_jacqueue PROPERTIES PASS_REGULAR_EXPRESSION "ok")
add_test(test_jacarray testjac "4" "40000")
set_tests_properties(test_jacarray PROPERTIES PASS_REGULAR_EXPRESSION "ok")
add_test(test_jacstring testjac "5" "40000")
set_tests_properties(test_jacstring PROPERTIES PASS_REGULAR_EXPRESSION "ok")
add_test(test_array testjac "7" "40000")
set_tests_properties(test_array PROPERTIES PASS_REGULAR_EXPRESSION "ok")
add_test(test_glist testjac "8" "40000")
set_tests_properties(test_glist PROPERTIES PASS_REGULAR_EXPRESSION "ok")


