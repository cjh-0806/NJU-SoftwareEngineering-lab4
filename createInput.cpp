#include "createInput.h"
#include <fstream>
#include <sstream>
#include <string>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

Type::Type(int t, int minL, int maxL)
{
    _type = t; minLen = minL; maxLen = maxL;
}

int Type::createInt()
{
    return minLen + rand() % (maxLen - minLen + 1);
}

char Type::createChar()
{
    return 'a' + rand() % ('z'-'a'+1);
}

string Type::createString()
{
    string str;
    int num = minLen + rand() % (maxLen - minLen + 1);
    for(int i = 0; i < num; ++i)
    {
        int flag; //flag为1是大写，为0是小写
        flag = rand()%2;
        if(flag == 1)
            str += 'A' + rand() % ('Z'-'A'+1);
        else 
            str += 'a' + rand() % ('z'-'a'+1); 
    }
    return str;
}

int TypeVec::readInputFormat(const char* src) //读取输入样式
{
    ifstream fin(src);
    if(!fin)
        return -1;
    string line;
    getline(fin, line);
    if(fin.fail())
        return -1;
    fin.close();
    stringstream ss(line);
    string tmp;
    srand((unsigned)time(NULL));
    int res = 1; //返回值是生成随机输入的组数
    while(getline(ss, tmp, ' ')) //按空格分割，存放到tmp变量中
    {
        int index = tmp.find('(');
        if(index == -1) //char
        {
            _typeVec.push_back(new Type(1, 1, 1));
            res = res > 4 ? res : 4;
        }
        else //int&string
        {
            string type = tmp.substr(0, index);
            int comma_index = tmp.find(',');
            int a = stoi(tmp.substr(index+1, comma_index-index-1));
            int b = stoi(tmp.substr(comma_index+1, tmp.length()-comma_index-2));
            if(type == "int")
                _typeVec.push_back(new Type(0, a, b));
            else if(type == "string")
                _typeVec.push_back(new Type(2, a, b));
            res = res > (b-a+1) ? res : (b-a+1);
        }
    }
    return res;
}

void TypeVec::createInput(const char* src) //随机生成一组输入
{
    ofstream fout(src);
    if(!fout)
        return;
    for(int i = 0; i < _typeVec.size(); ++i)
    {
        int type = _typeVec[i]->get_type();
        switch(type)
        {
            case 0: fout << _typeVec[i]->createInt() << ' '; break;
            case 1: fout << _typeVec[i]->createChar() << ' '; break;
            case 2: fout << _typeVec[i]->createString() << ' '; break;
        }
    }
    fout.close();
}

void getDirPath(const char* src, vector<string>& dirnames) //获取输入文件夹中的子文件夹路径
{
	DIR *pDir;
    struct dirent* ptr;
    if(!(pDir = opendir(src))) //输入文件夹不存在
        return;
    while((ptr = readdir(pDir)) != 0) 
    {
        if (ptr->d_name[0] != '.')
        {    
            string name = src; name += "/"; name += ptr->d_name;
            dirnames.push_back(name); //存放子文件夹路径
        }
    }
    closedir(pDir);
}
