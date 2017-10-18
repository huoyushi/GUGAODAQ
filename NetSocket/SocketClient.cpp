#include "SocketClient.h"
#include "JsonUtils.h"
using namespace std;
using namespace huoyushi;
huoyushi::SocktClient::SocktClient(short offset,const string hostaddres, unsigned short port){
    this->offset=offset;
    this->hostaddres=hostaddres;
    this->port=port;

}
int  huoyushi::SocktClient::CaculateCheckSum()
{

    if(!huoyushi::JsonUtils::checkJsonPattern(this->SendBuffer,this->offset))
    {
       printf("error cmd\n");
        return -1;
    }
    short len=strlen(SendBuffer+offset)-1;
    printf("len:%d\n",len);
    header.Len[0]=len>>8;
    header.Len[1]=len&0xFF;
    char checksum=0;
    byte* p=(byte*)&header;
    for(int i=0;i<16;i++){
        checksum+=*p;
        p++;
    }
    header.Checksum=-checksum;
    memcpy(SendBuffer,(void*)&header,offset);
    return len+offset;
}
bool huoyushi::SocktClient::Initialized(bool isAsync){

    #ifdef _WIN32

    struct sockaddr_in server;
    struct hostent *host = NULL;
    /*加载Winsock DLL*/
    if (WSAStartup(MAKEWORD(2 , 2) , &wsd) != 0) {
        printf("Winsock    初始化失败!\n");
        return false;
    }
    /*创建Socket*/
    if(!isAsync)sClient = socket(AF_INET , SOCK_STREAM, IPPROTO_TCP);
    else sClient=WSASocket(AF_INET , this->sockettype,0,NULL,0,0);

    if (sClient == INVALID_SOCKET) {
        printf("socket() 失败:%d\n",WSAGetLastError);
        return false;
    }
    /*指定服务器地址*/
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(hostaddres.c_str());
    
    if (server.sin_addr.s_addr == INADDR_NONE) {
        host= gethostbyname(hostaddres.c_str());    //输入的地址可能是域名等
        if (host == NULL) {
            printf("无法解析服务端地址:%s\n",hostaddres);
            return false;
        }
        CopyMemory(&server.sin_addr ,
                    host->h_addr_list[0] ,
                    host->h_length);
    }
    /*与服务器建立连接*/
    int sendtimeout=2000;
    int recvtimeout=5000;
    setsockopt(sClient,SOL_SOCKET,SO_SNDTIMEO,(char*)&sendtimeout, sizeof(int));
    setsockopt(sClient,SOL_SOCKET,SO_RCVTIMEO,(char*)&recvtimeout, sizeof(int));
    if (connect(sClient , (struct sockaddr*)&server ,
                    sizeof(server)) == SOCKET_ERROR) {
        printf("connect faild:%d\n",WSAGetLastError());
        return false;
    }
    
    return true;
    #else 
    return false;
   #endif
   
}
void huoyushi::SocktClient::Work(){
     /*发送、接收消息*/
     #ifdef _WIN32
     printf("work in sync\n");
     int ret;
     for (;;) {
        //从标准输入读取要发送的数据
        //gets_s(Buffer,BUFSIZE);
        fill(SendBuffer,SendBuffer+SENDBUFSIZE,0);
        fgets(SendBuffer+offset,SENDBUFSIZE-this->offset,stdin);
      
        int len=this->CaculateCheckSum();
        //向服务器发送消息
        
       
        ret = send(sClient ,SendBuffer,len,0);
        
        if (ret == 0) {
           printf("break\n");
            break;
        }
        else if (ret == SOCKET_ERROR) {
            printf("send() fail:%d\n",WSAGetLastError());
            break;
        }
    
        //接收从服务器来的消息
        fill(RecvBuffer,RecvBuffer+RECVBUFSIZE,0);
        ret = recv(sClient , RecvBuffer , RECVBUFSIZE , 0);

        if (ret == 0) {
            printf("break\n");
            continue;
        }
        else if (ret == SOCKET_ERROR) {
            printf("recv() fail:%d\n ",WSAGetLastError());
            close();
            Initialized(false);
            continue;
        }
        RecvBuffer[ret]='\0';
        printf("%s\n",RecvBuffer+offset);
    }
      

    #endif
}

void huoyushi::SocktClient::close(){
    //用完了，关闭socket句柄(文件描述符)
    if(sClient!=INVALID_SOCKET)
    closesocket(sClient);
    return;
}

void huoyushi::SocktClient::cleanup(){
    WSACleanup();    //清理
}