#include <fstream>
#include <iostream>
#include <iomanip>
#include "Vm.hpp"
#include <cmath>

abstract::Vm::Vm() : stack()
{
    parse.setSize(0);
    _Print = false;
    _exit = false;
    _standart = false;
    _store = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    command[";"] = &abstract::Vm::Null;
    command["push"] = &abstract::Vm::Push;
    command["pop"] = &abstract::Vm::Pop;
    command["clear"] = &abstract::Vm::Clear;
    command["dup"] = &abstract::Vm::Dup;
    command["swap"] = &abstract::Vm::Swap;
    command["dump"] = &abstract::Vm::Dump;
    command["assert"] = &abstract::Vm::Assert;
    command["add"] = &abstract::Vm::Add;
    command["sub"] = &abstract::Vm::Sub;
    command["mul"] = &abstract::Vm::Mul;
    command["div"] = &abstract::Vm::Div;
    command["mod"] = &abstract::Vm::Mod;
    //command["load"] = &abstract::Vm::Load;
    //command["store"] = &abstract::Vm::Store;
    command["print"] = &abstract::Vm::Print;
    command["exit"] = &abstract::Vm::Exit;
    _type["int8"] = eOperandType::Int8;
    _type["int16"] = eOperandType::Int16;
    _type["int32"] = eOperandType::Int32;
    _type["float"] = eOperandType::Float;
    _type["double"] = eOperandType::Double;
    _type["bigdecimal"] = eOperandType::BigDecimal;
}

abstract::Vm::~Vm() {}

int abstract::Vm::getSize()
{
    return stack.size();
}

std::list<IOperand*> &abstract::Vm::getStack() 
{
    return stack;
}

int abstract::Vm::getInput(void)
{
    std::string buffer;
    _standart = true;
    while (getline(std::cin, buffer)) {
        if(parse.checkInput(clean_str(clear_str(buffer), " ")) == true) {
            try {
                execute(clear_str(buffer));
            } catch (std::exception const &e) {
                std::cout << e.what() << std::endl;
                return 84;
            }
            if (_exit == true)
                break;
            parse.setSize(stack.size());
        }
        else return 84;
    }
    return 0;
}

void abstract::Vm::execute(std::string input)
{
    std::vector<std::string> line = clean_str(input, " ");

    for (const auto &it : command) {
        if (line[0] == it.first) {
            if (line.size() == 2)
                (this->*(it.second))(line[1]);
            else if (line.size() == 1)
                (this->*(it.second))("");
        }
    }
}

int abstract::Vm::getInput(std::string filepath)
{
    std::ifstream file(filepath);
    std::string buffer;

    if (file.is_open() == false || parse.checkFilepath(filepath) == false)
        return 84;
    while (getline(file, buffer)) {
        if(parse.checkInput(clean_str(clear_str(buffer), " ")) == true) {
            execute(clear_str(buffer));
            parse.setSize(stack.size());
        } else return 84;
    }
    if (_exit == false)
        throw no_Exit("No exit at the end of the command");
    return 0;
}

std::string abstract::Vm::getValue(std::string value)
{
        return value;
}
eOperandType abstract::Vm::getType(std::string type)
{
    for(const auto &it : _type) {
        if (type == it.first) {
            return it.second;
        }
    }
    return eOperandType::Unknow;
}

bool abstract::Vm::checkType(std::string type)
{
    for (const auto &it : _type) {
        if (type == it.first) {
            return true;
        }
    }
    return false;
}

bool is_number(const std::string& value)
{
    auto it = value.begin();
    while (it != value.end() && std::isdigit(*it)) 
        ++it;
    if (value.empty() == true || it != value.end())
        return false;
    else return true;
}

bool abstract::Vm::checkValue(std::string value)
{
    if (is_number(value) == false)
        return false;
    int buff = atoi(value.c_str());
    if (buff < 0 || buff > 16)
        return false;
    return true;
}

void abstract::Vm::Push(std::string arg)
{
    std::vector<std::string> line = clean_str(clean_str(arg, " ")[0], "(");
    Factory buffer;
    stack.emplace_front(buffer.createOperand(getType(line[0]), getValue(line[1])));
    
}

void abstract::Vm::Dup(std::string arg)
{
    arg = "";
    if (stack.size() != 0) {
        stack.emplace_front(stack.front());
    }
}

void abstract::Vm::Swap(std::string arg)
{
    arg = "";
    if (stack.size() >= 2) {
        auto element1 = stack.begin();
        auto element2 = element1++;
        std::swap(*element1, *element2);
    }
}

void abstract::Vm::Add(std::string arg)
{
    arg = "";
    if (stack.size() >= 2) {
        IOperand *buff;
        IOperand *ret;
        buff = stack.front();
        stack.pop_front();
        ret = stack.front();
        stack.pop_front();
        stack.emplace_front(*buff + *ret);
    } else throw Bad_value("insufisiant value in stack");
}

void abstract::Vm::Sub(std::string arg)
{
    arg = "";
    if (stack.size() >= 2) {
        IOperand *buff;
        IOperand *ret;
        buff = stack.front();
        stack.pop_front();
        ret = stack.front();
        stack.pop_front();
        stack.emplace_front(*buff - *ret);
    } else throw Bad_value("insufisiant value in stack");
}

void abstract::Vm::Load(std::string arg)
{
    arg = "";
    std::vector<std::string> line = clean_str(arg, "(");
    line[1].pop_back();

    if (checkType(line[0]) == false)
        throw Bad_value("load unknow value");
    if (checkValue(line[1]) == false)
        throw Bad_value("Wrong index given");
    if (_store[atoi(line[1].c_str())]->getType() != getType(line[0]))
        throw Bad_value("Wrong type loaded");
    if (_store[atoi(line[1].c_str())] == 0)
        throw Bad_value("Index empty");
    //stack.push_front(_store[atoi(line[1].c_str())]);
}

void abstract::Vm::Store(std::string arg)
{
    arg = "";
    std::vector<std::string> line = clean_str(arg, "(");
    line[1].pop_back();

    if (stack.size() == 0)
        throw Pop_error("Store on en empty stack");
    if (checkType(line[0]) == false)
        throw Bad_value("Store unknow value");
    if (checkValue(line[1]) == false)
        throw Bad_value("Wrong index given");
    _store.insert(_store.begin() + atoi(line[1].c_str()), stack.front());
    stack.pop_front();
}

void abstract::Vm::Mul(std::string arg)
{
    arg = "";
    if (stack.size() >= 2) {
        IOperand *buff;
        IOperand *ret;
        buff = stack.front();
        stack.pop_front();
        ret = stack.front();
        stack.pop_front();
        stack.emplace_front(*buff * *ret);
    } else throw Bad_value("insufisiant value in stack");
}

void abstract::Vm::Mod(std::string arg)
{
    arg = "";
    if (stack.size() >= 2) {
        auto it = std::next(stack.begin());
        if ((*it)->toString() == "0")
            throw Bad_value("cant modulo by 0");
        if ((*it)->getType() == eOperandType::Double || (*it)->getType() == eOperandType::Float 
        || (*it)->getType() == eOperandType::BigDecimal)
            throw Bad_value("cant modulo by this type");
        IOperand *buff;
        IOperand *ret;
        buff = stack.front();
        stack.pop_front();
        ret = stack.front();
        stack.pop_front();
        stack.emplace_front(*buff % *ret);
    } else throw Bad_value("Bad Value");
}

void abstract::Vm::Div(std::string arg)
{
    arg = "";
    if (stack.size() >= 2) {
        auto it = std::next(stack.begin());
        if ((*it)->toString() == "0")
            throw Bad_value("cant divise by 0");
        IOperand *buff;
        IOperand *ret;
        buff = stack.front();
        stack.pop_front();
        ret = stack.front();
        stack.pop_front();
        stack.emplace_front(*buff / *ret);
    } else throw Bad_value("Bad value");
}

void abstract::Vm::Print(std::string arg)
{
    arg = "";
    if (stack.size() == 0)
        throw Pop_error("Print on en empty stack");
    if (stack.front()->getType() != eOperandType::Int8)
        throw Bad_value("Print a non 8-bit integer");
    _Print = true;
}

void abstract::Vm::Assert(std::string arg)
{
    std::vector<std::string> line = clean_str(arg, "(");
    line[1].pop_back();

    if (stack.size() == 0)
        throw Pop_error("Assert on en empty stack");
    if (checkType(line[0]) == false)
        throw Bad_value("Assert unknow value");
    if (stack.front()->toString() != line[1] || stack.front()->getType() != getType(line[0]))
        throw Bad_value("Assert value or type differ from stack value");
}

void abstract::Vm::Null(std::string arg)
{
    arg = "";
}

void abstract::Vm::Clear(std::string arg)
{
    arg = "";
    stack.clear();
}

void abstract::Vm::Dump(std::string arg)
{
    arg = "";
    _Dump = true;
}

void abstract::Vm::Exit(std::string arg)
{
    arg = "";
    _exit = true;
    if (_standart == true)
        std::cout << ";;" << std::endl;
    if (_Print == true)
        std::cout << atoi(stack.front()->toString().c_str()) << std::endl;
    if (_Dump == true)
        for (std::list<IOperand*>::iterator it = stack.begin(); it != stack.end(); it++) {
            Round((*it)->getType() , (*it)->toString());
    }
}

void  abstract::Vm::Round(eOperandType type, std::string arg)
{
    long double value = strtold(arg.c_str(), NULL);
    long double result;
    std::string tmp;

    if (type == eOperandType::Int8 || type == eOperandType::Int16 || type == eOperandType::Int32) {
        std::cout << arg << std::endl;
        return;
    }
    switch (type) {
        case eOperandType::Float:
            result = round(value * pow(10, 7) ) / pow(10, 7);
            std::cout << std::setprecision(7) << result << std::endl;
            break;
        case eOperandType::Double:
            result = round(value * pow(10, 15) ) / pow(10, 15);
            std::cout << std::setprecision(15) << result << std::endl;
            break;
        case eOperandType::BigDecimal:
            result = round(value * pow(10, 200) ) / pow(10, 200);
            std::cout << std::setprecision(200) << result << std::endl;
            break;
        default:
            break;
    }
}

void abstract::Vm::Pop(std::string arg)
{
    arg = "";
    stack.pop_front();
}