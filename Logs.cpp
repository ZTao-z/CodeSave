#include "Logs.hpp"

shared_ptr<myLog> myLog::myLog_instance = nullptr;

shared_ptr<myLog> myLog::getInstance(void){
    if(myLog::myLog_instance == nullptr){
        myLog::myLog_instance = shared_ptr<myLog>(new myLog);
    }
    return myLog::myLog_instance;
}
