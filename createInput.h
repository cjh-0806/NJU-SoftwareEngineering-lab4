#ifndef _CREATEINPUTH_
#define _CREATEINPUTH_

#include <iostream>
#include <vector>
using namespace std;

class Type
{
    int _type; //0-int, 1-char, 2-string
    int minLen;
    int maxLen;
public:
    Type(int, int, int);
    int get_type() const { return _type; }
    int createInt(); //随机生成一个整数
    char createChar(); //随机生成一个字母
    string createString(); //随机生成一个字符串
};

class TypeVec
{
    vector<Type> _typeVec;
public:
    int readInputFormat(const char* src); //读取输入样式
    void createInput(const char* src); //随机生成一组输入
};

void getDirPath(const char* src, vector<string>& dirnames); //获取输入文件夹中的子文件夹的路径

#endif