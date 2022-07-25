/*
** EPITECH PROJECT, 2021
** Float
** File description:
** Float
*/

#include "Float.hpp"
#include "Factory.hpp"
#include <cmath>

Operand::Float::Float(std::string value)
{
    _type = eOperandType::Float;
    _value = stof(value);
}

Operand::Float::~Float()
{
}

std::string Operand::Float::toString() const
{
    return std::to_string(_value);
}

eOperandType Operand::Float::getType() const
{
    return _type;
}

IOperand* Operand::Float::operator+(const IOperand &rhs) const
{
    Factory tmp;
    long double new_value;

    new_value = stold(rhs.toString()) + _value;
    if (rhs.getType() > _type)
        return tmp.createOperand(rhs.getType(), std::to_string(new_value));
    return tmp.createOperand(getType(), std::to_string(new_value));
}

IOperand* Operand::Float::operator-(const IOperand &rhs) const
{
    Factory tmp;
    long double new_value;

    new_value = stold(rhs.toString()) - _value;
    if (rhs.getType() > _type)
        return tmp.createOperand(rhs.getType(), std::to_string(new_value));
    return tmp.createOperand(getType(), std::to_string(new_value));
}

IOperand* Operand::Float::operator*(const IOperand &rhs) const
{
    Factory tmp;
    long double new_value;

    new_value = stold(rhs.toString()) * _value;
    if (rhs.getType() > _type)
        return tmp.createOperand(rhs.getType(), std::to_string(new_value));
    return tmp.createOperand(getType(), std::to_string(new_value));
}

IOperand* Operand::Float::operator/(const IOperand &rhs) const
{
    Factory tmp;
    long double new_value;

    new_value = stold(rhs.toString()) / _value;
    if (rhs.getType() > _type)
        return tmp.createOperand(rhs.getType(), std::to_string(new_value));
    return tmp.createOperand(getType(), std::to_string(new_value));
}

IOperand* Operand::Float::operator%(const IOperand &rhs) const
{
    Factory tmp;
    long double new_value;

    new_value = std::fmod(stold(rhs.toString()), _value);
    if (rhs.getType() > _type)
        return tmp.createOperand(rhs.getType(), std::to_string(new_value));
    return tmp.createOperand(getType(), std::to_string(new_value));
}