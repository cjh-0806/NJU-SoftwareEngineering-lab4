#include <iostream>
#include "createInput.h"
using namespace std;

int main()
{
    vector<string> dirnames; //存放input下子文件夹的路径
    getDirPath("input", dirnames);
    return 0;
}