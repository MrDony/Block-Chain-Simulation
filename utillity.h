#include <string>
#include <fstream>

void pl(std::string s)
{
    std::cout<<s<<"\n";
}

std::string readFile(std::string fileName, bool fl=false)
{
    std::ifstream fileToRead(fileName);
    std::string fileContents="";
    std::string line="";
    while(std::getline(fileToRead,line))
    {
        if(fl)
        {//leave first line if it is true
            fl=false;
            continue;
        }
        fileContents+=line+"\n";
    }

    //remove lthe last /n
    std::string ret="";
    for(int i=0;i<fileContents.length()-1;i++)
        ret+=fileContents[i];
    return ret;
}


void writeFile(std::string fileName, std::string data)
{
    std::ofstream fileToWrite(fileName,std::ios::trunc);
    fileToWrite<<data;
}

std::string hash(std::string text)
{
    int ret=0;
    for(int ch : text)
    {
        ret=ch+(ret << 4)+(ret<<10)-ret;
    }
    pl("\t\t\tHash created of <"+text+"> = "+std::to_string(ret));
    return std::to_string(ret);
}

