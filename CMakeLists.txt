cmake_minimum_required(VERSION 3.0.0)
project(DAQ VERSION 0.0.0)

include(CTest)
enable_testing()


include_directories(${PROJECT_SOURCE_DIR}/NetSocket)
include_directories(${PROJECT_SOURCE_DIR}/JsonUtils)
add_executable(DAQ main.cpp)
target_link_libraries(DAQ NetSocket)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_subdirectory(NetSocket)
add_subdirectory(JsonUtils)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)