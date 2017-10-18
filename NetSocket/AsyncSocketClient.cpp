#include "AsyncSocketClient.h"
using namespace huoyushi;
huoyushi::AsyncSocketClient::AsyncSocketClient(short offset, const string hostaddres, unsigned short port) : SocktClient(offset, hostaddres, port) {}
bool huoyushi::AsyncSocketClient::AsyncInitialized()
{
#ifdef _WIN32
    Initialized(true);
    this->wsaEvent = ::WSACreateEvent();
    ::WSAEventSelect(this->sClient, this->wsaEvent, FD_READ | FD_WRITE | FD_CLOSE);
    return true;
#endif
}

void huoyushi::AsyncSocketClient::AsyncWork()
{
#ifdef _WIN32
    while (true)
    {
        int nRet = ::WSAWaitForMultipleEvents(1, &wsaEvent, FALSE, 100000, FALSE);
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
            ::WSAEnumNetworkEvents(sClient, wsaEvent, &wsaNetEvent);
            if (wsaNetEvent.lNetworkEvents & FD_READ)
            {
                printf("FD_READ\n");
                int nRet = recv(sClient, RecvBuffer, RECVBUFSIZE, 0);
                if (nRet > 0)
                {
                    RecvBuffer[nRet] = '\0';
                    printf("data:%s\n", RecvBuffer + offset);
                    int nSend=send(sClient,SendBuffer,SENDBUFSIZE,0);
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
                fgets(SendBuffer+offset,SENDBUFSIZE-this->offset,stdin);
                int len=this->CaculateCheckSum();
                send(sClient,SendBuffer,len,0);
            }
        }
    }

#endif
}

void huoyushi::AsyncSocketClient::AsyncClose()
{
    this->close();
    if (this->wsaEvent != WSA_INVALID_EVENT)
        WSACloseEvent(this->wsaEvent);
}
