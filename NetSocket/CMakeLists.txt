project(DAQ VERSION 0.0.0)

link_directories(${PROJECT_SOURCE_DIR}/JsonUtils)
add_library(NetSocket SHARED SocketClient.cpp AsyncSocketClient.cpp UDPServer.cpp)
target_link_libraries(NetSocket JsonUtils)
IF(WIN32)
link_directories(C:/Program Files (x86)/Microsoft Visual Studio/2017/Community/SDK/ScopeCppSDK/SDK/lib)
target_link_libraries(NetSocket WS2_32.Lib)
ENDIF(WIN32)

