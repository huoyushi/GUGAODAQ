#ifndef _UDPSERVER_H
#define _UDPSERVER_H


#include<stdio.h>
#ifdef _WIN32
//define something for Windows (32-bit and 64-bit, this part is common)
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")
#ifdef _WIN64
//define something for Windows (64-bit only)
#endif
#elif __APPLE__
#include "TargetConditionals.h"
#if TARGET_IPHONE_SIMULATOR
// iOS Simulator
#elif TARGET_OS_IPHONE
// iOS device
#elif TARGET_OS_MAC
// Other kinds of Mac OS
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#else
#error "Unknown Apple platform"
#endif
#elif __linux__
// linux
#elif __unix__ // all unices not caught above
// Unix
#elif defined(_POSIX_VERSION)
// POSIX
#else
#error "Unknown compiler"
#endif

namespace huoyushi{
    class UDPServer;

}

class huoyushi::UDPServer{
protected:
    char RecvBuffer[65536];
    SOCKET sudpServer=INVALID_SOCKET;
    WSADATA wsaData;
    WSAEVENT wsaEvent=WSA_INVALID_EVENT;
    short port;
public:

     UDPServer(short port);
     bool Initialized();
     bool AsyncInitialized();
     void Work();
     void AsyncWork();
     void CloseSocket();
     void AsyncClose();
     void cleanupWSA();
};
#endif