/*
** EPITECH PROJECT, 2021
** Operand::Int32
** File description:
** Operand::Int32
*/

#include "Int32.hpp"
#include "Factory.hpp"
#include <cmath>

Operand::Int32::Int32(std::string value)
{
    _type = eOperandType::Int32;
    _value = stoi(value);
}

Operand::Int32::~Int32()
{
}

std::string Operand::Int32::toString() const
{
    return std::to_string(_value);
}

eOperandType Operand::Int32::getType() const
{
    return _type;
}

IOperand* Operand::Int32::operator+(const IOperand &rhs) const
{
    Factory tmp;
    long double new_value;

    new_value = stold(rhs.toString()) + _value;
    if (rhs.getType() > _type)
        return tmp.createOperand(rhs.getType(), std::to_string(new_value));
    return tmp.createOperand(getType(), std::to_string(new_value));
}

IOperand* Operand::Int32::operator-(const IOperand &rhs) const
{
    Factory tmp;
    long double new_value;

    new_value = stold(rhs.toString()) - _value;
    if (rhs.getType() > _type)
        return tmp.createOperand(rhs.getType(), std::to_string(new_value));
    return tmp.createOperand(getType(), std::to_string(new_value));
}

IOperand* Operand::Int32::operator*(const IOperand &rhs) const
{
    Factory tmp;
    long double new_value;

    new_value = stold(rhs.toString()) * _value;
    if (rhs.getType() > _type)
        return tmp.createOperand(rhs.getType(), std::to_string(new_value));
    return tmp.createOperand(getType(), std::to_string(new_value));
}

IOperand* Operand::Int32::operator/(const IOperand &rhs) const
{
    Factory tmp;
    long double new_value;

    new_value = stold(rhs.toString()) / _value;
    if (rhs.getType() > _type)
        return tmp.createOperand(rhs.getType(), std::to_string(new_value));
    return tmp.createOperand(getType(), std::to_string(new_value));
}

IOperand* Operand::Int32::operator%(const IOperand &rhs) const
{
    Factory tmp;
    long double new_value;

    new_value = std::fmod(stold(rhs.toString()), _value);
    if (rhs.getType() > _type)
        return tmp.createOperand(rhs.getType(), std::to_string(new_value));
    return tmp.createOperand(getType(), std::to_string(new_value));
}