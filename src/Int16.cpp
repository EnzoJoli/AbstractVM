/*
** EPITECH PROJECT, 2021
** Int32
** File description:
**Operand::Int16
*/

#include "Int16.hpp"
#include "Factory.hpp"
#include <cmath>

Operand::Int16::Int16(std::string value)
{
    _type = eOperandType::Int16;
    _value = stoi(value);
}

Operand::Int16::~Int16()
{
}

std::string Operand::Int16::toString() const
{
    return std::to_string(_value);
}

eOperandType Operand::Int16::getType() const
{
    return _type;
}

IOperand *Operand::Int16::operator+(const IOperand &rhs) const
{
    Factory tmp;
    long double new_value;

    new_value = stold(rhs.toString()) + _value;
    if (rhs.getType() > _type)
        return tmp.createOperand(rhs.getType(), std::to_string(new_value));
    return tmp.createOperand(getType(), std::to_string(new_value));
}

IOperand *Operand::Int16::operator-(const IOperand &rhs) const
{
    Factory tmp;
    long double new_value;

    new_value = stold(rhs.toString()) - _value;
    if (rhs.getType() > _type)
        return tmp.createOperand(rhs.getType(), std::to_string(new_value));
    return tmp.createOperand(getType(), std::to_string(new_value));
}

IOperand *Operand::Int16::operator*(const IOperand &rhs) const
{
    Factory tmp;
    long double new_value;

    new_value = stold(rhs.toString()) * _value;
    if (rhs.getType() > _type)
        return tmp.createOperand(rhs.getType(), std::to_string(new_value));
    return tmp.createOperand(getType(), std::to_string(new_value));
}

IOperand *Operand::Int16::operator/(const IOperand &rhs) const
{
    Factory tmp;
    long double new_value;

    new_value = stold(rhs.toString()) / _value;
    if (rhs.getType() > _type)
        return tmp.createOperand(rhs.getType(), std::to_string(new_value));
    return tmp.createOperand(getType(), std::to_string(new_value));
}

IOperand *Operand::Int16::operator%(const IOperand &rhs) const
{
    Factory tmp;
    long double new_value;

    new_value = std::fmod(stold(rhs.toString()), _value);
    if (rhs.getType() > _type)
        return tmp.createOperand(rhs.getType(), std::to_string(new_value));
    return tmp.createOperand(getType(), std::to_string(new_value));
}