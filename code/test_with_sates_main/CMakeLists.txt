project(test_with_sates_main)
add_definitions(-DSATES_NO_DEPLOY) 
add_executable(${PROJECT_NAME} test_with_sates_main)

target_link_libraries(${PROJECT_NAME}
    debug sates_maind
    optimized sates_main
    optimized sates
    debug satesd)