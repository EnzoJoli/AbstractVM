#include <iostream>
#include <fstream>
#include <limits>
#include "Parser.hpp"
#include "Error.hpp"


abstract::Parser::Parser() : _StackSize(0)
{
    input[";"] = &abstract::Parser::null;
    input[""] = &abstract::Parser::null;
    input["push"] = &abstract::Parser::checkType;
    input["pop"] = &abstract::Parser::checkPop;
    input["clear"] = &abstract::Parser::null;
    input["dup"] = &abstract::Parser::null;
    input["swap"] = &abstract::Parser::null;
    input["dump"] = &abstract::Parser::null;
    input["assert"] = &abstract::Parser::checkType;
    input["add"] = &abstract::Parser::null;
    input["sub"] = &abstract::Parser::null;
    input["mul"] = &abstract::Parser::null;
    input["div"] = &abstract::Parser::null;
    input["mod"] = &abstract::Parser::null;
    input["load"] = &abstract::Parser::checkType;
    input["store"] = &abstract::Parser::checkType;
    input["print"] = &abstract::Parser::null;
    input["exit"] = &abstract::Parser::null;
    type["int8"] = &abstract::Parser::checkInt8;
    type["int16"] = &abstract::Parser::checkInt16;
    type["int32"] = &abstract::Parser::checkInt32;
    type["float"] = &abstract::Parser::null;
    type["double"] = &abstract::Parser::null;
    type["bigdecimal"] = &abstract::Parser::null;
}

abstract::Parser::~Parser() {}

void abstract::Parser::setSize(int size)
{
    _StackSize = size;
}

std::string abstract::clear_str(std::string str)
{
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == '\t')
            str[i] = '\n';
        if (i > 0) {
            if (str[i] == ' ' && str[i - 1] == ' ') {
                str.erase(i, 1);
                i--;
            }
            if (str[i] == ';') {
                str.erase(str.begin() + i, str.end());
                break;
            }
        }
        if (str[i] == '(' && str[i - 1] == ' ')
            str.erase(i - 1, 1);
    }
    return str;
}

std::vector<std::string> abstract::clean_str(std::string str, const char *separator)
{
    std::vector<std::string> ret;
    std::size_t buff, prev = 0;

    buff = str.find(separator);
    while (buff != std::string::npos) {
        ret.emplace_back(str.substr(prev, buff - prev));
        prev = buff + 1;
        buff = str.find(separator, prev);
        }
    ret.push_back(str.substr(prev, buff - prev));
    return ret;
}

bool abstract::Parser::checkInput(std::vector<std::string> line)
{
    try {
        if (line[0] != ";" && line.size() > 2)
            throw Lexical_Error("Too much instruction");
        for(const auto &it : input) {
            if (line[0] == it.first) {
                if (line.size() == 2 && (this->*(it.second))(line[1]) == true)
                    return true;
                else if ((this->*(it.second))("") == true) {
                    return true;
                }
            }
        }
        throw Lexical_Error("Unknow command");
    }
    catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
}

bool abstract::Parser::checkFilepath(std::string filepath)
{
    std::vector<std::string> path = clean_str(filepath, ".");

    if (path.size() == 2 && path[1] == "avm")
        return true;
    else return false;
}

bool abstract::Parser::null(std::string arg)
{
    arg = "";
    return true;
}

bool abstract::Parser::checkInt8(std::string arg)
{
    if (arg.find(".") == true || arg.find(",") == true)
        return false;
    int value = std::stoi(arg);
    if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
        return false;
    return true;
}

bool abstract::Parser::checkInt16(std::string arg)
{
    if (arg.find(".") == true || arg.find(",") == true)
        return false;
    int value = std::stoi(arg);
    if (value < std::numeric_limits<int16_t>::min() || value > std::numeric_limits<int16_t>::max())
        return false;
    return true;
}
bool abstract::Parser::checkInt32(std::string arg)
{
    if (arg.find(".") != std::string::npos || arg.find(",") != std::string::npos)
        return false;
    int value = std::stoi(arg);
    if (value < std::numeric_limits<int32_t>::min() || value > std::numeric_limits<int32_t>::max())
        return false;
    return true;
}

bool abstract::Parser::checkFloat(std::string arg)
{
    float value = std::stof(arg);
    if (value < std::numeric_limits<float>::min() || value > std::numeric_limits<float>::max())
        return false;
    return true;
}

bool abstract::Parser::checkDouble(std::string arg)
{
    double value = std::stod(arg);
    if (value < std::numeric_limits<double>::min() || value > std::numeric_limits<double>::max())
        return false;
    return true;
}

bool abstract::Parser::checkBigdecimal(std::string arg)
{
    long double value = std::stoi(arg);
    if (value < std::numeric_limits<long double>::min() || value > std::numeric_limits<long double>::max())
        return false;
    return true;
}

bool abstract::Parser::checkPop(std::string arg)
{
    arg = "";
    if (_StackSize == 0) {
        throw Pop_error("Pop on an empty Stack");
        return false;
    }
    return true;
}

bool abstract::Parser::checkType(std::string arg)
{
    try
    {
        if (arg.size() == 0)
            throw Not_enough_arg("missing value");
        std::vector<std::string> line = clean_str(arg, "(");
        for(const auto &it : type) {
            if (line[0] == it.first) {
                if (line.size() == 2 && (this->*(it.second))(clean_str(line[1], ")")[0]) == true)
                    return true;
                }
        }
        throw Bad_value("Bad value");
    }
    catch(const std::exception& e)
    {
        throw;
        return false;
    }
}
