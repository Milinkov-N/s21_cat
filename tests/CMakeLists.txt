cmake_minimum_required(VERSION 3.21)

project(S21CatLib-Tests)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF)

set(BUILD_SHARED_LIBS OFF)
FetchContent_MakeAvailable(googletest)

set(SOURCES main.cc ../src/s21_cat.c)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ../include)
target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
