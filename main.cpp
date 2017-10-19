#include "SocketClient.h"
#include "AsyncSocketClient.h"
#include "UDPServer.h"
using namespace huoyushi;
int main(int argc, char **argv)
{
    //    SocktClient *client=new SocktClient(16,"192.168.3.12",1700);
    //    if(client->Initialized(false)){
    //         client->Work();
    //         client->close();
    //         client->cleanup();
    //    }
   

    printf("header size: %d\n",sizeof(huoyushi::MsgHeader));
    if (argc < 2)
    {
        printf("please input work mode 1/tcp;  2/tcp async;  3/udp  ; 4/udp async\n");
        return -1;
    }

    int choice = atoi(argv[1]);
    switch (choice)
    {
    case 1:
    {
        SocktClient *client = new SocktClient(16, "192.168.3.12", 1700);
        if (client->Initialized(false))
        {
            client->Work();
            client->close();
            client->cleanup();
        }
        break;
    }
    case 2:
    {
        break;
    }

    case 3:
    {
        UDPServer *udpserver = new UDPServer(1700);
        if (udpserver->Initialized())
        {
            udpserver->Work();
            udpserver->CloseSocket();
            udpserver->cleanupWSA();
        }
        break;
    }
    case 4:
    {
        UDPServer *udpserver = new UDPServer(1700);
        if (udpserver->AsyncInitialized())
        {
            udpserver->AsyncWork();
            udpserver->AsyncClose();
            udpserver->cleanupWSA();
        }
        break;
    }
    default:
    {
        printf("cccc\n");
        break;
    }
    }

    return 0;
}