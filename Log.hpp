#ifndef _UTIL_LOG_H
#define _UTIL_LOG_H

namespace Util
{
    enum LogLevel : unsigned int
    {
        DEBUG,
        INFO,
        ERROR,
        FATAL,
        SPECIAL
    };

    class Log
    {
    //Variables:
    public:
    protected:
    private:

    //Functions
    public:
        static void init(unsigned int log_level);
        static void uninit(void);

        static void setLevel(LogLevel level);

        static void writeDebug  (const char* message, ...);
        static void writeInfo   (const char* message, ...);
        static void writeError  (const char* message, ...);
        static void writeFatal  (const char* message, ...);
        static void writeSpecial(const char* message, ...);

    protected:
    private:
        static void writeMessage(const char* prefix, const char* message, va_list argList);
    };
}

#endif