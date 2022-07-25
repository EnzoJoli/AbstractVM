#ifndef ERROR_H
#define ERROR_H

#include <exception>
#include <iostream>

class Too_much_arg : public std::exception
{
public:
    Too_much_arg(std::string const &descr) throw() : message(descr) {};
    virtual const char *what() const throw()
    {
        return message.c_str();
    }
private:
    std::string message;
};

class Lexical_Error : public std::exception
{
public:
    Lexical_Error(std::string const &descr) throw() : message(descr) {};
    virtual const char *what() const throw()
    {
        return message.c_str();
    }
private:
    std::string message;
};

class Not_enough_arg : public std::exception
{
public:
    Not_enough_arg(std::string const &descr) throw() : message(descr) {};
    virtual const char *what() const throw()
    {
        return message.c_str();
    }
private:
    std::string message;
};

class no_Exit : public std::exception
{
public:
    no_Exit(std::string const &descr) throw() : message(descr) {};
    virtual const char *what() const throw()
    {
        return message.c_str();
    }
private:
    std::string message;
};

class Bad_value : public std::exception
{
public:
   Bad_value(std::string const &descr) throw() : message(descr) {};
    virtual const char *what() const throw()
    {
        return message.c_str();
    }
private:
    std::string message;
};

class Pop_error : public std::exception
{
public:
   Pop_error(std::string const &descr) throw() : message(descr) {};
    virtual const char *what() const throw()
    {
        return message.c_str();
    }
private:
    std::string message;
};
#endif