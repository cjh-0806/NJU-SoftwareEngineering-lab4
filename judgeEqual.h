#ifndef _JUDGEEQUALH_
#define _JUDGEEQUALH_

#include <iostream>
#include <vector>
using namespace std;

class Judge
{
    string dirname;
    vector<string> filenames; //文件夹中的output.txt文件的路径
public:
    Judge(const char* src);
    void getOutputFilePath(const char* src); //获取文件夹中的output.txt文件的路径
    void judgeEqual(); //两两比对文件夹内的输出文件
    void outputPairs(string file1, string file2, bool isEqual); //输出等价或不等价的程序对到csv文件中
};

#endif