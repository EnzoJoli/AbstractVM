/*
** EPITECH PROJECT, 2021
** Float
** File description:
** Float
*/

#ifndef FLOAT_HPP_
#define FLOAT_HPP_

#include "IOperand.hpp"

namespace Operand {
    class Float: public IOperand {
        public:
            Float(std::string value);
            float getValue() {return _value;};
            std::string toString() const;
            eOperandType getType() const;
            IOperand* operator+(const IOperand &rhs) const;
            IOperand* operator-(const IOperand &rhs) const;
            IOperand* operator*(const IOperand &rhs) const;
            IOperand* operator/(const IOperand &rhs) const;
            IOperand* operator%(const IOperand &rhs) const;
            ~Float();
        protected:
        private:
            eOperandType _type;
            float _value;
    };
};

#endif /* !FLOAT_HPP_ */
