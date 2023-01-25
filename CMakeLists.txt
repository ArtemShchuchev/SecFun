cmake_minimum_required(VERSION 3.5)
project(SecFun VERSION 1.0 LANGUAGES CXX)

set(HEADERS SecondFunk/SecondaryFunction.h)
set(SOURCES SecondFunk/SecondaryFunction.cpp)

add_library(${PROJECT_NAME}_lib SHARED ${HEADERS} ${SOURCES})

#add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

#target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}_lib)

#set(CMAKE_CXX_FLAGS_RELEASE_INIT "-Wall")
set(CMAKE_CONFIGURATION_TYPES "Release" CACHE STRING "" FORCE)

# if (Visual Studio)
# настраиваю в качестве запускаемого проекта
# настройка на стандарт с++17
if(MSVC)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME}_lib)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
else()
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
endif()




### add_subdirectory(../Catch2 Catch2-build)
#find_package(Catch2 3 REQUIRED)
## 		These tests need their own main
#add_executable(test test/test.cpp BigInteger/big_integer.h BigInteger/big_integer.cpp)
#target_link_libraries(test PRIVATE Catch2::Catch2)
