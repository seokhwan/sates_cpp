project(sates)

add_definitions(-DSATES_NO_DEPLOY) 

file(GLOB sates_src ${CMAKE_SOURCE_DIR}/sates/*.h 
                   ${CMAKE_SOURCE_DIR}/sates/*.cpp)
source_group(sates FILES ${sates_src})

file(GLOB sates_internal_src ${CMAKE_SOURCE_DIR}/sates/internal_use/*.h 
                   ${CMAKE_SOURCE_DIR}/sates/internal_use/*.cpp)
source_group(sates\\internal_use FILES ${sates_internal_src})

add_library(${PROJECT_NAME} STATIC ${sates_src} ${sates_internal_src})
