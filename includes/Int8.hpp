/*
** EPITECH PROJECT, 2021
** Int8
** File description:
** Int8
*/

#ifndef INT8_HPP_
#define INT8_HPP_

#include "IOperand.hpp"

namespace Operand {
    class Int8: public IOperand {
        public:
            Int8(std::string value);
            int getValue() {return _value;};
            std::string toString() const;
            eOperandType getType() const;
            IOperand* operator+(const IOperand &rhs) const;
            IOperand* operator-(const IOperand &rhs) const;
            IOperand* operator*(const IOperand &rhs) const;
            IOperand* operator/(const IOperand &rhs) const;
            IOperand* operator%(const IOperand &rhs) const;
            ~Int8();
        protected:
        private:
            eOperandType _type;
            int _value;
    };
};

#endif /* !INT8_HPP_ */
