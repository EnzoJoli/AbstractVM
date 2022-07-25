/*
** EPITECH PROJECT, 2021
** Int16
** File description:
** Int16
*/

#ifndef INT16_HPP_
#define INT16_HPP_

#include "IOperand.hpp"

namespace Operand {
    class Int16: public IOperand {
        public:
            Int16(std::string value);
            int getValue() {return _value;};
            std::string toString() const;
            eOperandType getType() const;
            IOperand* operator+(const IOperand &rhs) const;
            IOperand* operator-(const IOperand &rhs) const;
            IOperand* operator*(const IOperand &rhs) const;
            IOperand* operator/(const IOperand &rhs) const;
            IOperand* operator%(const IOperand &rhs) const;
            ~Int16();
        protected:
        private:
            eOperandType _type;
            int _value;
    };
};

#endif /* !INT16_HPP_ */
