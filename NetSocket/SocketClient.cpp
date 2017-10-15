
#include "SocketClient.h"
void Show(){
    #ifdef __linux__
    cout<<"linux"<<endl;
    #elif __APPLE__
        #if TARGET_OS_MAC
        cout<<"mac os"<<endl;
        #elif TARGET_OS_IPHONE
        cout<<"iphone"<<endl;
        #endif
    #else
    cout<<"errror os"<<endl;
    #endif
}