/*
** EPITECH PROJECT, 2021
** BigDecimal
** File description:
** BigDecimal
*/

#ifndef BIGDECIMAL_HPP_
#define BIGDECIMAL_HPP_

#include "IOperand.hpp"

namespace Operand {
    class BigDecimal: public IOperand {
        public:
            BigDecimal(std::string value);
            long double getValue() {return _value;};
            std::string toString() const;
            eOperandType getType() const;
            IOperand* operator+(const IOperand &rhs) const;
            IOperand* operator-(const IOperand &rhs) const;
            IOperand* operator*(const IOperand &rhs) const;
            IOperand* operator/(const IOperand &rhs) const;
            IOperand* operator%(const IOperand &rhs) const;
            ~BigDecimal();
        protected:
        private:
            eOperandType _type;
            long double _value;
    };
};

#endif /* !BIGDECIMAL_HPP_ */
