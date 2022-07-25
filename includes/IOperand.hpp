/*
** EPITECH PROJECT, 2021
** IOperand
** File description:
** IOperand
*/

#ifndef IOPERAND_HPP_
#define IOPERAND_HPP_

#include <iostream>

enum eOperandType {
    Int8,
    Int16,
    Int32,
    Float,
    Double,
    BigDecimal,
    Unknow
};

class IOperand {
    public:
        virtual std::string toString() const = 0;
        virtual eOperandType getType() const = 0;
        virtual IOperand* operator+(const IOperand &rhs) const = 0;
        virtual IOperand* operator-(const IOperand &rhs) const = 0;
        virtual IOperand* operator*(const IOperand &rhs) const = 0;
        virtual IOperand* operator/(const IOperand &rhs) const = 0;
        virtual IOperand* operator%(const IOperand &rhs) const = 0;
        virtual ~IOperand() {}
};

#endif /* !IOPERAND_HPP_ */
