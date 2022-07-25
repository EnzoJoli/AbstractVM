#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include <functional>
#include <map>

namespace abstract
{
    class Parser
    {
    private:
        int _StackSize;
        std::map<std::string, bool (abstract::Parser::*)(std::string arg)> input;
        std::map<std::string, bool (abstract::Parser::*)(std::string arg)> type;
    public:
        bool checkInput(std::vector<std::string> line);
        void setSize(int size);

        bool checkFilepath(std::string filepath);
        bool null(std::string arg);
        bool checkType(std::string arg);
        bool checkPop(std::string arg);

        bool checkInt8(std::string arg);
        bool checkInt16(std::string arg);
        bool checkInt32(std::string arg);
        bool checkFloat(std::string arg);
        bool checkDouble(std::string arg);
        bool checkBigdecimal(std::string arg);
        Parser();
        ~Parser();
    };
    std::vector<std::string> clean_str(std::string str, const char *separator);
    std::string clear_str(std::string str);
}

#endif