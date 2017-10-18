#ifndef _JSONUTILS_H
#define _JSONUTILS_H

#include<string.h>
using namespace std;
namespace huoyushi{
    class JsonUtils;
}
class huoyushi::JsonUtils{
public:
    static bool checkJsonPattern(char* Buffer,short offset); 
    //static int  String2Hex(string strCmd,char *Buffer,short offset);
    //static string Hex2String(char *Buffer,int len,short offset);
};
#endif