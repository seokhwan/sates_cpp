project(sates_main)
add_definitions(-DSATES_NO_DEPLOY) 
add_library(${PROJECT_NAME} STATIC sates_main.cpp)
