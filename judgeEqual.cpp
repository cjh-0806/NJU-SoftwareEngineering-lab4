#include "judgeEqual.h"
#include <fstream>
#include <string>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

Judge::Judge(const char* src)
{
    dirname = src;
    getOutputFilePath(src);
}

void Judge::getOutputFilePath(const char* src) //获取文件夹中的output.txt文件的路径
{
	DIR *pDir;
    struct dirent* ptr;
    if(!(pDir = opendir(src))) //文件夹不存在
        return;
    while((ptr = readdir(pDir)) != 0) 
    {
        if (ptr->d_name[0] != '.' && strstr(ptr->d_name, ".txt") &&
        strcmp(ptr->d_name, "stdin_format.txt") != 0 && strcmp(ptr->d_name, "input.txt") != 0)
        {    
            string name = src; name += "/"; name += ptr->d_name;
            filenames.push_back(name); //存放文件路径
        }
    }
    closedir(pDir);
}

void Judge::judgeEqual()
{
    int i, j;
    for(i = 0; i < filenames.size(); ++i)
    {
        for(j = i + 1; j < filenames.size(); ++j)
        {
            ifstream fin1(filenames[i].c_str());
            if(!fin1) return;
            ifstream fin2(filenames[j].c_str());
            if(!fin2) return;
            string line1, line2;
            bool isEqual = true;
            while(!fin1.eof() && !fin2.eof())
            {
                getline(fin1, line1);
                getline(fin2, line2);
                if(line1 != line2)
                {
                    isEqual = false;
                    break;
                } 
            }
            if((fin1.eof() && !fin2.eof()) || (!fin1.eof() && fin2.eof()))
                isEqual = false;
            fin1.close();
            fin2.close();
            outputPairs(filenames[i], filenames[j], isEqual);
        }
    }
}

void Judge::outputPairs(string file1, string file2, bool isEqual) //输出等价或不等价的程序对到csv文件中
{
    ofstream fout;
    if(isEqual)
        fout.open("output/equal.csv", ios::app);
    else
        fout.open("output/inequal.csv", ios::app);
    int index1 = file1.find("_output");
    file1 = file1.substr(0, index1) + ".cpp";
    int index2 = file2.find("_output");
    file2 = file2.substr(0, index2) + ".cpp";
    fout << file1 << ',' << file2 << endl;
    fout.close();
}