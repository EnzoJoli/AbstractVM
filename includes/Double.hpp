/*
** EPITECH PROJECT, 2021
** Double
** File description:
** Double
*/

#ifndef DOUBLE_HPP_
#define DOUBLE_HPP_

#include "IOperand.hpp"

namespace Operand {
    class Double: public IOperand {
        public:
            Double(std::string value);
            double getValue() {return _value;};
            std::string toString() const;
            eOperandType getType() const;
            IOperand* operator+(const IOperand &rhs) const;
            IOperand* operator-(const IOperand &rhs) const;
            IOperand* operator*(const IOperand &rhs) const;
            IOperand* operator/(const IOperand &rhs) const;
            IOperand* operator%(const IOperand &rhs) const;
            ~Double();
        protected:
        private:
            eOperandType _type;
            double _value;
    };
};

#endif /* !DOUBLE_HPP_ */
