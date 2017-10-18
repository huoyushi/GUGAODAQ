#ifndef _SOCKETCLIENT_H
#define _SOCKETCLIENT_H

#include<string>
#include<stdio.h>
#include<string.h>
using namespace std;
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
namespace huoyushi
{
  const int RECVBUFSIZE = 65536;
  const int SENDBUFSIZE=4096;
struct MsgHeader
{
  char Address[8] = {0};
  char Cmd[2] = {0};
  char Len[2] = {0};
  char CmdType = 0x06;
  char Checksum = 0x00;
  char Sure = 0xD5;
  char Rsv = 0x00;
};
class SocktClient;
}
class huoyushi::SocktClient
{
  protected:

  MsgHeader header;
  short offset;
  string hostaddres;
  short port;
  char SendBuffer[SENDBUFSIZE];
  char RecvBuffer[RECVBUFSIZE];
  #ifdef _WIN32
  WSADATA wsd;
  SOCKET sClient;
  int sockettype;
  #endif
public:
  SocktClient(short offset,const string hostaddres, unsigned short port);
  SocktClient();
  bool Initialized(bool isAsync);
  int CaculateCheckSum();
  void Work();
  void close();
  void cleanup();
};
#endif