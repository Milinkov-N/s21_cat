cmake_minimum_required(VERSION 3.21)

project(
    s21_cat
    VERSION 0.1.0
    LANGUAGES C CXX
)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(GCC_CXX "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(MSVC_CXX "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
set(SOURCES src/main.c src/s21_cat.c)

add_library(CompilerFlags INTERFACE)
target_compile_features(CompilerFlags INTERFACE c_std_11)
target_compile_options(CompilerFlags INTERFACE
  "$<${GCC_CXX}:$<BUILD_INTERFACE:-Wall;-Werror;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
  "$<${MSVC_CXX}:$<BUILD_INTERFACE:-Wall;-W4;-WX>>"
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} PRIVATE CompilerFlags)

add_subdirectory(tests)
