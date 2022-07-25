/*
** EPITECH PROJECT, 2021
** Int32
** File description:
** Int32
*/

#ifndef INT32_HPP_
#define INT32_HPP_

#include "IOperand.hpp"

namespace Operand {
    class Int32: public IOperand {
        public:
            Int32(std::string value);
            int getValue() {return _value;};
            std::string toString() const;
            eOperandType getType() const;
            IOperand* operator+(const IOperand &rhs) const;
            IOperand* operator-(const IOperand &rhs) const;
            IOperand* operator*(const IOperand &rhs) const;
            IOperand* operator/(const IOperand &rhs) const;
            IOperand* operator%(const IOperand &rhs) const;
            ~Int32();
        protected:
        private:
            eOperandType _type;
            int _value;
    };
};

#endif /* !INT32_HPP_ */
