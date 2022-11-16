#include "executeOJ.h"
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

void Program::getCppFilePath(const char* src) //获取文件夹中的.cpp文件的路径
{
	DIR *pDir;
    struct dirent* ptr;
    if(!(pDir = opendir(src))) //文件夹不存在
        return;
    while((ptr = readdir(pDir)) != 0) 
    {
        if (ptr->d_name[0] != '.' && strstr(ptr->d_name, ".cpp"))
        {    
            string name = src; name += "/"; name += ptr->d_name;
            filenames.push_back(name); //存放文件路径
        }
    }
    closedir(pDir);
}

void Program::executeOJ(const char* dirname, const char* inputfile, TypeVec typeVec, int m) //自动执行文件夹中的.cpp文件m次
{
    getCppFilePath(dirname);
    for(int i = 0; i < filenames.size(); ++i)
    {
        string command1 = "./generateExe.sh " + filenames[i]; //生成可执行文件
        system(command1.c_str());
    }
    for(int i = 0; i < m; ++i) //m次生成输入+执行
    {
        typeVec.createInput(inputfile);
        for(int j = 0; j < filenames.size(); ++j)
        {
            string command2 = "./execute.sh " + filenames[j] + " " + inputfile;
            system(command2.c_str());
        }
    }
}