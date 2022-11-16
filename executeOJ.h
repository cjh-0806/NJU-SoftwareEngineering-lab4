#ifndef _EXECUTEOJH_
#define _EXECUTEOJH_

#include <iostream>
#include <vector>
#include "createInput.h"
using namespace std;

class Program
{
    vector<string> filenames;
public:
    void getCppFilePath(const char* src); //获取文件夹中的.cpp文件的路径
    void executeOJ(const char* dirname, const char* inputfile, TypeVec typeVec, int m); //自动执行文件夹中的.cpp文件m次
};

#endif