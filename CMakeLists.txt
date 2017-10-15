cmake_minimum_required(VERSION 3.0.0)
project(DAQ VERSION 0.0.0)

include(CTest)
enable_testing()

add_subdirectory(NetSocket)
include_directories(${PROJECT_SOURCE_DIR}/NetSocket)
add_executable(DAQ main.cpp)
target_link_libraries(DAQ NetSocket)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


