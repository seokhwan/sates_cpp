project(test_without_sates_main)
add_definitions(-DSATES_NO_DEPLOY) 
add_executable(${PROJECT_NAME} test_without_sates_main)

if (CMAKE_BUILD_TYPE EQUAL "Debug")
target_link_libraries(${PROJECT_NAME} 
	satesd)
else()
target_link_libraries(${PROJECT_NAME} 
	sates)
endif()
