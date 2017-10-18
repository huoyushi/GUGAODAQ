#include "UDPServer.h"
huoyushi::UDPServer::UDPServer(short port) : port(port) {}
bool huoyushi::UDPServer::Initialized()
{
#ifdef _WIN32
    /*加载Winsock DLL*/
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        printf("Winsock    初始化失败!\n");
        return false;
    }

    this->sudpServer = ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    int recvtimeout=5000;
    setsockopt(sudpServer,SOL_SOCKET,SO_RCVTIMEO,(char*)&recvtimeout, sizeof(int));
    /*指定服务器地址*/
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.S_un.S_addr = INADDR_ANY;
    if (bind(sudpServer, (sockaddr *)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
    {
        printf("bind error");
        CloseSocket();
        cleanupWSA();
        return false;
    }
    return true;
#endif
}

void huoyushi::UDPServer::Work()
{
#ifdef _WIN32
    sockaddr_in remoteAddr;
    int nAddrLen = sizeof(remoteAddr);
    
    for(int i=0;i<10;i++)
    {

        int ret = recvfrom(sudpServer, RecvBuffer, 65536, 0, (sockaddr *)&remoteAddr, &nAddrLen);
        if (ret == 0)
        {
            printf("0 bytes\n");
        }

        else if (ret == SOCKET_ERROR)
        {
            printf("recv() fail:%d\n ", WSAGetLastError());
            this->CloseSocket();
            this->Initialized();
            continue;
        }

        RecvBuffer[ret] = '\0';
        printf("recv from: %s %d bytes\n", inet_ntoa(remoteAddr.sin_addr),ret);
        for(int j=0;j<ret;j++)
        {
            if(j%20==0)printf("\n");
            printf("%02X ",(unsigned char)RecvBuffer[j]);
            
        }
        printf("\n");
        printf("%d end\n",i);
        
    }

#endif
}

void huoyushi::UDPServer::CloseSocket()
{
    if (sudpServer != INVALID_SOCKET)
        closesocket(sudpServer);
}

void huoyushi::UDPServer::cleanupWSA()
{
    WSACleanup(); //清理
}