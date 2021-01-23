cmake_minimum_required(VERSION 3.16)

project(lcsols-c VERSION 0.1 LANGUAGES C)

include(cmake/FetchCMocka.cmake)

add_library(lcsols SHARED Solution475.c)

add_executable(lcsols_test Solution475Test.c)
target_compile_features(lcsols_test PRIVATE c_std_99)
target_link_libraries(lcsols_test lcsols cmocka-static)

enable_testing()
add_test(lcsols_test lcsols_test)