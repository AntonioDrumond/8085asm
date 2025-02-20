#ifndef CLS_H
#define CLS_H

#include <stdlib.h>

int cls(){
    int ret = 1;
#if defined(_WIN32) || defined(_WIN64) || defined(__WINDOWS__)
    ret = system("cls");
#elif defined(__linux__)
    ret = system("clear");
#elif defined(__APPLE__) && defined(__MACH__)
    ret = system("clear");
#elif defined(unix) || defined(__unix__) || defined(__unix)
    ret = system("clear");
#else
    #error Unknown_OS
#endif
    return ret;
}

#endif
