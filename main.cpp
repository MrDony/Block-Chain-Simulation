#include <iostream>
#include "utillity.h"
#include <fstream>

void getHashOfFileAndWriteToNext(std::string fileName)
{
    //std::string dateOfFile=readFile(fileName,true);
    std::string hashOfFile=hash(readFile(fileName,true));
    int nextFileDigit=std::stoi(fileName)+1;
    if(nextFileDigit>3)
        nextFileDigit=1;
    std::string nextFileName=std::to_string(nextFileDigit)+".txt";
    std::string nextFileData=readFile(nextFileName,true);
    pl("data of next file = "+nextFileData);
    nextFileData=hashOfFile+"\n"+nextFileData;

    pl("current file name = "+fileName+" ("+hashOfFile+")\tnext file = "+nextFileName+" {\n"+nextFileData+"\n}");
    writeFile(nextFileName,nextFileData);

}
void writeHashToFile()
{

}

void simulate()
{
    for(int i=1;i<4;i++)
    {
        std::string fileName=std::to_string(i)+".txt";
        std::cout<<"writing hash of file to next = "<<fileName<<"\n";
        getHashOfFileAndWriteToNext(fileName);
    }
}

int main()
{
    std::string fileName="1.txt";



    //std::cout<<hash("hellow")<<std::endl;
    //std::cout<<std::stoi("1.txt");
    pl("\n\n\n\n");
    simulate();
    return 0;
    
}