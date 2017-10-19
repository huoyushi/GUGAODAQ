#include  "UDPServer.h"
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
        printf("bind error\n");
        CloseSocket();
        cleanupWSA();
        return false;
    }
    return true;
#endif
}
bool  huoyushi::UDPServer::AsyncInitialized(){
    #ifdef _WIN32
    this->Initialized();
    this->wsaEvent = ::WSACreateEvent();
    ::WSAEventSelect(this->sudpServer, this->wsaEvent, FD_READ | FD_WRITE | FD_CLOSE);
    return true;
#endif
}
void huoyushi::UDPServer::Work()
{
#ifdef _WIN32
    sockaddr_in remoteAddr;
    int nAddrLen = sizeof(remoteAddr);
    
    for(int i=0;i<20;i++)
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
        for(int j=0;j<10;j++)
        {
            printf("%02X ",(unsigned char)RecvBuffer[j]);
            
        }
        printf("\n");
        for(int j=10;j<13;j++)
        {
           
          
            printf("%02X ",(unsigned char)RecvBuffer[j]);
            
        }


        printf("\n");

        for(int j=13;j<ret;j++)
        {
           if(j%16==0)
            printf("\n");
          printf("%02X ",(unsigned char)RecvBuffer[j]);
            
        }
        
        printf("\n\n\n");
        
    }

#endif
}
void huoyushi::UDPServer::AsyncWork(){
    #ifdef _WIN32
    
        sockaddr_in remoteAddr;
        int nAddrLen = sizeof(remoteAddr);
        int count=0;
        unsigned char old=0x00;
        while (true)
        {
            int nRet = ::WSAWaitForMultipleEvents(1, &wsaEvent, FALSE, 2000, FALSE);
            if (nRet == WAIT_FAILED) //失败
            {
                printf("faild WSAWaitForMultipleEvents\n");
                break;
            }
            else if (nRet == WSA_WAIT_TIMEOUT)
            {
                printf("WSA_WAIT_TIMEOUT\n");
                continue;
            }
            else
            {
                WSANETWORKEVENTS wsaNetEvent;
                ::WSAEnumNetworkEvents(this->sudpServer, wsaEvent, &wsaNetEvent);
                if (wsaNetEvent.lNetworkEvents & FD_READ)
                {
                    //printf("FD_READ\n");
                    int nRet = recvfrom(sudpServer, RecvBuffer, 65536, 0, (sockaddr *)&remoteAddr, &nAddrLen);
          
                    if (nRet > 0)
                    {
                        RecvBuffer[nRet] = '\0';
                        old+=1;
                       // printf("recv from: %s %d bytes\n", inet_ntoa(remoteAddr.sin_addr),nRet);
                        if(old!=(unsigned char)RecvBuffer[6]){
                            count++;
                            printf("lose %d\n",count-1);
                        }
                        old=(unsigned char)RecvBuffer[6];
                        //printf("%02x\n",(unsigned char)RecvBuffer[6]);
                        // for(int j=0;j<nRet;j++)
                        // {
                        //     if(j%20==0)
                        //     printf("\n");
                        //     printf("%02X ",(unsigned char)RecvBuffer[j]);
                            
                        // }
                        // printf("\n\n\n");
                    }
    
                    else
                    {
                        printf("something error! restart client\n");
                        AsyncClose();
                        AsyncInitialized();
                    }
                }
                //发送触发
                else if(wsaNetEvent.lNetworkEvents&FD_WRITE)
                {
                    printf("send data\n");
                   
                }
            }
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

void huoyushi::UDPServer::AsyncClose(){
    this->CloseSocket();
    if(this->wsaEvent!=WSA_INVALID_EVENT)
    WSACloseEvent(wsaEvent);
}