#include "SocketClient.h"
#include "AsyncSocketClient.h"
#include "UDPServer.h"
using namespace huoyushi;
int main(int, char**)
{
//    SocktClient *client=new SocktClient(16,"192.168.3.12",1700);
//    if(client->Initialized(false)){
//         client->Work();
//         client->close();
//         client->cleanup();
//    }


       UDPServer *udpserver=new UDPServer(1700);
       if(udpserver->Initialized()){
           udpserver->Work();
           udpserver->CloseSocket();
           udpserver->cleanupWSA();
       }
   
   printf("false\n");
}