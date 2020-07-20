project(sates)

add_definitions(-DSATES_NO_DEPLOY) 

file(GLOB sates_src ${CMAKE_SOURCE_DIR}/sates/*.h 
                   ${CMAKE_SOURCE_DIR}/sates/*.cpp)
source_group(sates FILES ${sates_src})

file(GLOB sates_common_src ${CMAKE_SOURCE_DIR}/sates/common/*.h 
                   ${CMAKE_SOURCE_DIR}/sates/common/*.cpp)
source_group(sates\\common FILES ${sates_common_src})

file(GLOB sates_report_src ${CMAKE_SOURCE_DIR}/sates/report/*.h 
                   ${CMAKE_SOURCE_DIR}/sates/report/*.cpp)
source_group(sates\\report FILES ${sates_report_src})

file(GLOB sates_tc_src ${CMAKE_SOURCE_DIR}/sates/tc/*.h 
                   ${CMAKE_SOURCE_DIR}/sates/tc/*.cpp)
source_group(sates\\tc FILES ${sates_tc_src})

file(GLOB sates_tester_src ${CMAKE_SOURCE_DIR}/sates/tester/*.h 
                   ${CMAKE_SOURCE_DIR}/sates/tester/*.cpp)
source_group(sates\\tester FILES ${sates_tester_src})


add_library(${PROJECT_NAME} STATIC ${sates_src} ${sates_internal_src} ${sates_common_src} ${sates_tc_src} ${sates_tester_src} ${sates_report_src})
