#pragma once

#include <ctime>  
#include <iostream>  
#include <fstream>  
#include <direct.h>

using namespace std;

#ifndef __EASYLOG_PIPI_0813
#define __EASYLOG_PIPI_0813

class EasyLog
{
public:
    static void Write(std::string log) {
        try
        {
            std::ofstream ofs;

            struct tm t;   //tm结构指针
            time_t now;  //声明time_t类型变量
            time(&now);      //获取系统日期和时间
            localtime_s(&t, &now);   //获取当地日期和时间


            char tmp[64];
            strftime(tmp, sizeof(tmp), "[%Y-%m-%d %X]", &t);
            ofs.open("PipeLog.log", std::ofstream::app);

            ofs << tmp << " - ";
            ofs.write(log.c_str(), log.size());
            ofs << std::endl;
            ofs.close();
        }
        catch (...)
        {
        }
    }
};

#endif