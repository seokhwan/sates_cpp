project(test_without_sates_main)
add_definitions(-DSATES_NO_DEPLOY) 
add_executable(${PROJECT_NAME} test_without_sates_main)

target_link_libraries(${PROJECT_NAME} 
    debug satesd
    optimized sates)
    