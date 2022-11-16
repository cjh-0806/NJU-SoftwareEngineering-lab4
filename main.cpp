#include <iostream>
#include "createInput.h"
#include "executeOJ.h"
using namespace std;

int main()
{
    vector<string> dirnames; //存放input下子文件夹的路径
    getDirPath("input", dirnames);
    for(int i = 0; i < dirnames.size(); ++i) //对每个子文件夹
    {
        string stdinPath = dirnames[i] + "/stdin_format.txt"; //标准输入格式文件
        string inputPath = dirnames[i] + "/input.txt"; //生成的输入文件
        TypeVec typeVec; //存放输入格式
        int m = typeVec.readInputFormat(stdinPath.c_str());
        Program p(dirnames[i].c_str(), inputPath.c_str(), m);
        p.executeOJ(typeVec);
    }
    return 0;
}