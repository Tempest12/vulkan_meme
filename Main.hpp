#ifndef _MAIN_HPP
#define _MAIN_HPP

#include <string>

namespace Main
{
    void breakRunLoop(void);
    void die(const char* errorMessage, ...);
    void init(void);
    void runLoop(void);
    void uninit(void);
}

#endif
