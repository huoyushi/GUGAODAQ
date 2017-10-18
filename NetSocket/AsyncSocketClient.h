#ifndef _ASYNCSOCKETCLIENT_H
#define _ASYNCSOCKETCLIENT_H

#include "SocketClient.h"
using namespace huoyushi;
namespace huoyushi{
    class AsyncSocketClient;
}
class huoyushi::AsyncSocketClient:SocktClient{
private:
    WSAEVENT wsaEvent;
public:
    //构造函数
    AsyncSocketClient(short offset,const string hostaddres, unsigned short port);
    AsyncSocketClient();
    bool AsyncInitialized();
    void AsyncWork();
    void AsyncClose();
    
};

#endif