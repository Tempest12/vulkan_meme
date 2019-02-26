#ifndef _UTIL_PARSING_HPP
#define _UTIL_PARSING_HPP

#include <string>
#include <vector>

namespace Util
{
    class Parsing
    {
    //Variables:
    public:
    protected:
    private:

    //Functions:
    public:

        static void                       getNewLine(std::ifstream* file, std::string* line, int* lineNumber);
        static std::vector<std::string*>* getStringArray(std::string* fileName);

    protected:
    private:
    };
}

#endif