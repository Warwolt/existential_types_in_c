cmake_minimum_required(VERSION 3.16)
project(existential_types C CXX)

# Windows workaround for gtest
SET(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Include Google Test
add_subdirectory(external/googletest)

#
# Source files
#
set(SRC
    src/stack.c
)

add_executable(${CMAKE_PROJECT_NAME} src/main.c ${SRC})
set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY C_STANDARD 99)
if(MSVC)
  target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE /W4 /we4062 /WX)
else()
  target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()

#
# Unit test executable
#
set(TEST_SRC
  test/stack_tests.cpp
)

add_executable(tests
  ${TEST_SRC}
  ${SRC}
)

if(MSVC)
  target_compile_options(tests PRIVATE /W4 /we4062 /WX)
else()
  target_compile_options(tests PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()


target_include_directories(tests PUBLIC
  src
  external/googletest/googletest/include
)

target_link_libraries(tests
  gtest_main
)
