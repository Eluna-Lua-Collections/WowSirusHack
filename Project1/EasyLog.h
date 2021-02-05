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

            struct tm t;   //tm�ṹָ��
            time_t now;  //����time_t���ͱ���
            time(&now);      //��ȡϵͳ���ں�ʱ��
            localtime_s(&t, &now);   //��ȡ�������ں�ʱ��


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