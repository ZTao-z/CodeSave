#ifndef myLog_HPP
#define myLog_HPP

#include <iostream>
#include <fstream>
#include <windows.h>
#include <time.h>
#include <functional>
#include <iomanip>
#include <memory>
#include <string>
using namespace std;

#define MAX_SIZE 1024*1024

class myLog {
private:
    static shared_ptr<myLog> myLog_instance;
    const int max_size;
    string filename;
    int size;
public:
    myLog(): max_size(MAX_SIZE){
        size = 0;
        filename = "data/Logs1.txt";
    }
    ~myLog();
    static shared_ptr<myLog> getInstance(void);
    void Split(void){
        int a;
        unsigned int i = 0;
        char temp[20];
        while(i < filename.length()){
            temp[i] = filename[i];
            i++;
        }
        sscanf(temp, "data/Logs%d.txt",&a);
        a++;
        sprintf(temp, "data/Logs%d.txt",a);
        filename = temp;
        ifstream p(filename);
        if(!p.is_open()){
            ofstream q(filename);
            q.close();
        }
    }

    int fileSize(ifstream& source){
        source.seekg(0,ios::end);
        streampos ps = source.tellg();
        return ps;
    }

    string getTime(void){
        time_t t = time(0);
        char temp[64];
        strftime(temp, sizeof(temp), "%Y-%m-%d/%X",localtime(&t));
        string res = temp;
        return res;
    }

    void writeToFile(const string& name, const string& thing, const string& condition){
        ofstream file;
        ifstream fin;
        int size0 = MAX_SIZE;
        fin.open(filename);
        while(size0 >= max_size){
            size0 = fileSize(fin);
            fin.close();
            if(size0 >= max_size){
                Split();
                fin.open(filename);
            }
        }
        fin.close();
        size = size0;
        file.open(filename, ios::app);
        if(file.is_open()){
            file << left << "<" << getTime() << ">" << "  <" << name << ">  <" << left << setw(7) << condition << ">  " << thing << endl;
        }
        file.close();
    }
};

#endif // myLog_HPP
