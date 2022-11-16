#ifndef _EXECUTEOJH_
#define _EXECUTEOJH_

#include <iostream>
#include <vector>
#include "createInput.h"
using namespace std;

class Program
{
    string dirname; //文件夹路径
    string inputfile; //输入文件路径
    int count; //执行次数
    vector<string> filenames; //文件夹中的.cpp文件的路径
public:
    Program(const char* _dirname, const char* _inputfile, int _count);
    void getCppFilePath(const char* src); //获取文件夹中的.cpp文件的路径
    void executeOJ(TypeVec typeVec); //自动执行文件夹中的.cpp文件m次
};

#endif