/*
** EPITECH PROJECT, 2021
** Int8
** File description:
** Int8
*/

#include "Int8.hpp"
#include "Factory.hpp"
#include <string.h>
#include <cmath>

Operand::Int8::Int8(std::string value)
{
    _type = eOperandType::Int8;
    _value = stoi(value);
}

Operand::Int8::~Int8()
{
}

std::string Operand::Int8::toString() const
{
    return std::to_string(_value);
}

eOperandType Operand::Int8::getType() const
{
    return _type;
}

IOperand* Operand::Int8::operator+(const IOperand &rhs) const
{
    Factory tmp;
    long double new_value;

    new_value = stold(rhs.toString()) + _value;
    if (rhs.getType() > _type)
        return tmp.createOperand(rhs.getType(), std::to_string(new_value));
    return tmp.createOperand(getType(), std::to_string(new_value));
}

IOperand* Operand::Int8::operator-(const IOperand &rhs) const
{
    Factory tmp;
    long double new_value;

    new_value = stold(rhs.toString()) - _value;
    if (rhs.getType() > _type)
        return tmp.createOperand(rhs.getType(), std::to_string(new_value));
    return tmp.createOperand(getType(), std::to_string(new_value));
}

IOperand* Operand::Int8::operator*(const IOperand &rhs) const
{
    Factory tmp;
    long double new_value;

    new_value = stold(rhs.toString()) * _value;
    if (rhs.getType() > _type)
        return tmp.createOperand(rhs.getType(), std::to_string(new_value));
    return tmp.createOperand(getType(), std::to_string(new_value));
}

IOperand* Operand::Int8::operator/(const IOperand &rhs) const
{
    Factory tmp;
    long double new_value;

    new_value = stold(rhs.toString()) / _value;
    if (rhs.getType() > _type)
        return tmp.createOperand(rhs.getType(), std::to_string(new_value));
    return tmp.createOperand(getType(), std::to_string(new_value));
}

IOperand* Operand::Int8::operator%(const IOperand &rhs) const
{
    Factory tmp;
    long double new_value;

    new_value = std::fmod(stold(rhs.toString()), _value);
    if (rhs.getType() > _type)
        return tmp.createOperand(rhs.getType(), std::to_string(new_value));
    return tmp.createOperand(getType(), std::to_string(new_value));
}