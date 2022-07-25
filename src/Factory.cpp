/*
** EPITECH PROJECT, 2021
** Factory
** File description:
** Factory
*/

#include "Factory.hpp"
#include <memory>

Factory::Factory()
{
}

Factory::~Factory()
{
}

IOperand *Factory::createInt8(const std::string &value)
{
    Operand::Int8 *result = new Operand::Int8(value);
    return result;
}

IOperand *Factory::createInt16(const std::string &value)
{
    Operand::Int16 *result = new Operand::Int16(value);
    return result;
}

IOperand *Factory::createInt32(const std::string &value)
{
    Operand::Int32 *result = new Operand::Int32(value);
    return result;
}

IOperand *Factory::createFloat(const std::string &value)
{
    Operand::Float *result = new Operand::Float(value);
    return result;
}

IOperand *Factory::createDouble(const std::string &value)
{
    Operand::Double *result = new Operand::Double(value);
    return result;
}

IOperand *Factory::createBigDecimal(const std::string& value)
{
    Operand::BigDecimal *result = new Operand::BigDecimal(value);
    return result;
}

const std::unordered_map<eOperandType, IOperand*(Factory::*)(const std::string&)> Factory::functions (
    {
        {Int8, &Factory::createInt8},
        {Int16, &Factory::createInt16},
        {Int32, &Factory::createInt32},
        {Float, &Factory::createFloat},
        {Double, &Factory::createDouble},
        {BigDecimal, &Factory::createBigDecimal}
    }
);

IOperand *Factory::createOperand(eOperandType type, const std::string &value)
{
    Factory test;

    for (const auto &it : test.functions)
        if (it.first == type)
            return (&test->*(it.second))(value);
    return NULL;
}