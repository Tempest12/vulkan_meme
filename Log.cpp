#include <chrono>
#include <sstream>
#include <string>

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "Main.hpp"
#include "Log.hpp"

//Author Shane del Solar
//Version 2.00.ss

//Namespace this codes belongs to:
using namespace Util;

static unsigned int currentLevel;
static FILE* file;
static std::chrono::system_clock::time_point currentTime;

static const char* debugPrefix   = "DBUG                     : ";
static const char* infoPrefix    = "     INFO                : ";
static const char* errorPrefix   = "          EROR           : ";
static const char* fatalPrefix   = "               FATL      : ";
static const char* specialPrefix = "                    SPCL : ";

void Log::init(unsigned int level)
{
    currentLevel = level;

    file = fopen("log.txt", "w+");

    if(file == NULL)
    {
        Main::die("Unable to open log file for writing.");
    }
    else
    {
        va_list emptyList;
        writeMessage("Log ", "Opened.", emptyList);
    }

    fflush(file);
}

void Log::setLevel(LogLevel nextLevel)
{
    currentLevel = nextLevel;
}

void Log::writeDebug(const char* message, ...)
{
    va_list argList;
    va_start(argList, message);

    if(currentLevel <= DEBUG)
    {
        writeMessage(debugPrefix, message, argList);
    }

    va_end(argList);
}

void Log::writeError(const char* message, ...)
{
    va_list argList;
    va_start(argList, message);

    if(currentLevel <= ERROR)
    {
        writeMessage(errorPrefix, message, argList);
    }

    fflush(file);

    va_end(argList);
}

void Log::writeFatal(const char* message, ...)
{
    va_list argList;
    va_start(argList, message);

    if(currentLevel <= FATAL)
    {
        writeMessage(fatalPrefix, message, argList);
    }

    fflush(file);

    va_end(argList);
}

void Log::writeInfo(const char* message, ...)
{
    va_list argList;
    va_start(argList, message);

    if(currentLevel <= INFO)
    {
        writeMessage(infoPrefix, message, argList);
    }

    va_end(argList);
}

void Log::writeSpecial(const char* message, ...)
{
    va_list argList;
    va_start(argList, message);

    writeMessage(specialPrefix, message, argList);

    va_end(argList);
}

void Log::writeMessage(const char* prefix, const char* message, va_list argList)
{
    if(ferror(file) == 0)
    {
        currentTime       = std::chrono::system_clock::now();
        time_t time       = std::chrono::system_clock::to_time_t(currentTime);
        char*  tempString = ctime(&time);
        size_t tempLength = strlen(tempString);
        char*  timeString = (char*)malloc(tempLength * sizeof(char));

        if(timeString == NULL)
        {
            Main::die("Failed to allocate timeString while trying to write to log. Asked a string of length of: %u", tempLength);
        }

        memcpy(timeString, tempString, tempLength);
        timeString[tempLength - 1] = '\0';

        fprintf(file, "%s %s", timeString, prefix);
        vfprintf(file, message, argList);
        fprintf(file, "\n");
    }
}

void Log::uninit(void)
{
    if(ferror(file) == 0)
    {
        va_list emptyList;
        writeMessage("Log ", "Closed.", emptyList);

        fclose(file);
    }
} 
