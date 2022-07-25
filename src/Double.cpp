/*
** EPITECH PROJECT, 2021
** Double
** File description:
** Double
*/

#include "Double.hpp"
#include "Factory.hpp"
#include <cmath>

Operand::Double::Double(std::string value)
{
    _type = eOperandType::Double;
    _value = stod(value);
}

Operand::Double::~Double()
{
}

std::string Operand::Double::toString() const
{
    return std::to_string(_value);
}

eOperandType Operand::Double::getType() const
{
    return _type;
}

IOperand* Operand::Double::operator+(const IOperand &rhs) const
{
    Factory tmp;
    long double new_value;

    new_value = stold(rhs.toString()) + _value;
    if (rhs.getType() > _type)
        return tmp.createOperand(rhs.getType(), std::to_string(new_value));
    return tmp.createOperand(getType(), std::to_string(new_value));
}

IOperand* Operand::Double::operator-(const IOperand &rhs) const
{
    Factory tmp;
    long double new_value;

    new_value = stold(rhs.toString()) - _value;
    if (rhs.getType() > _type)
        return tmp.createOperand(rhs.getType(), std::to_string(new_value));
    return tmp.createOperand(getType(), std::to_string(new_value));
}

IOperand* Operand::Double::operator*(const IOperand &rhs) const
{
    Factory tmp;
    long double new_value;

    new_value = stold(rhs.toString()) * _value;
    if (rhs.getType() > _type)
        return tmp.createOperand(rhs.getType(), std::to_string(new_value));
    return tmp.createOperand(getType(), std::to_string(new_value));
}

IOperand* Operand::Double::operator/(const IOperand &rhs) const
{
    Factory tmp;
    long double new_value;

    new_value = stold(rhs.toString()) / _value;
    if (rhs.getType() > _type)
        return tmp.createOperand(rhs.getType(), std::to_string(new_value));
    return tmp.createOperand(getType(), std::to_string(new_value));
}

IOperand* Operand::Double::operator%(const IOperand &rhs) const
{
    Factory tmp;
    long double new_value;

    new_value = std::fmod(stold(rhs.toString()), _value);
    if (rhs.getType() > _type)
        return tmp.createOperand(rhs.getType(), std::to_string(new_value));
    return tmp.createOperand(getType(), std::to_string(new_value));
}