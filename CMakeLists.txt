cmake_minimum_required(VERSION 3.23)
project(Tests)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(include)
add_library(${PROJECT_NAME} src/library.cpp)

# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(unitTests
        test/LibraryTest.cpp
        test/UnionTest.cpp
        )
target_link_libraries(unitTests ${PROJECT_NAME} gtest gtest_main)
