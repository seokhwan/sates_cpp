CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

project(sates_cpp)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_DEBUG_POSTFIX d)
#set_property(GLOBAL PROPERTY USE_FOLDERS ON)


if(SATES_WIN)
	add_definitions(-DSATES_WIN) 
endif()

if(SATES_LINUX)
	add_definitions(-DSATES_LINUX)
endif()



set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(${CMAKE_SOURCE_DIR})

add_subdirectory(${CMAKE_SOURCE_DIR}/sates)
add_subdirectory(${CMAKE_SOURCE_DIR}/sates_main)

link_directories(${CMAKE_BINARY_DIR}/bin)

add_subdirectory(${CMAKE_SOURCE_DIR}/test_with_sates_main)
add_subdirectory(${CMAKE_SOURCE_DIR}/test_without_sates_main)
add_subdirectory(${CMAKE_SOURCE_DIR}/test_for_deploy)

