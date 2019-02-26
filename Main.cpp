#include <iostream>

#include <stdarg.h>
#include <stdio.h>
#include <vulkan/vulkan.h>

#include "Config.hpp"
#include "Log.hpp"
#include "Main.hpp"
#include "VkCore.hpp"

using namespace Main;

static bool    stayALive = true;
static VkCore* vkCore    = NULL;

int main(int argc, char** argv)
{
    init();

    runLoop();

    uninit();
}

void Main::breakRunLoop(void)
{
    stayALive = false;
}

void Main::die(const char* errorMessage, ...)
{
    va_list argList;
    va_start(argList, errorMessage);
    vprintf(errorMessage, argList);
    printf("\n");
    exit(1);
}

void Main::init(void)
{
    Util::Config::init();
    Util::Log::init((Util::LogLevel)Util::Config::convertSettingToInt("Log", "log_level"));

    vkCore = new VkCore();
    vkCore->init();
}

void Main::runLoop(void)
{
    while(stayALive == true)
    {

    }
}

void Main::uninit(void)
{
    vkCore->uninit();

    Util::Log::uninit();
    Util::Config::uninit();
}