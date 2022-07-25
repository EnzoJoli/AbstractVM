/*
** EPITECH PROJECT, 2021
** Operand.hpp
** File description:
** Operand
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include "IOperand.hpp"
#include <unordered_map>
#include <iostream>
#include "BigDecimal.hpp"
#include "Double.hpp"
#include "Float.hpp"
#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"

class IOperand;

class Factory {
    public:
        Factory();
        ~Factory();
        static IOperand* createOperand(eOperandType type, const std::string &value);
    protected:
    private:
        static const std::unordered_map<eOperandType, IOperand*(Factory::*)(const std::string&)> functions;
        IOperand *createInt8(const std::string &value);
        IOperand *createInt16(const std:: string &value);
        IOperand *createInt32(const std:: string &value);
        IOperand *createFloat(const std:: string &value);
        IOperand *createDouble(const std:: string &value);
        IOperand *createBigDecimal(const std:: string& value);
};

#endif