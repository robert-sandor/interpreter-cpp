//
// Created by robert on 12/13/15.
//

#include "ArithmeticExpression.hpp"
#include "../exceptions/DivisionByZeroException.hpp"

int ArithmeticExpression::evaluate(std::map<std::string, int> &symbolTable) {
    int val;
    int left = this->leftExpression->evaluate(symbolTable);
    int right = this->rightExpression->evaluate(symbolTable);
    switch (this->op) {
        case ADD:
            val = left + right;
            break;
        case SUB:
            val = left - right;
            break;
        case MUL:
            val = left * right;
            break;
        case DIV:
            if (0 == right) {
                throw new DivisionByZeroException();
            }
            val = left / right;
            break;
    }
    return val;
}

std::string ArithmeticExpression::toString() {
    std::string op = "";
    switch (this->op) {
        case ADD: op = " + "; break;
        case SUB: op = " - "; break;
        case MUL: op = " * "; break;
        case DIV: op = " / "; break;
    }
    return this->leftExpression->toString() + op + this->rightExpression->toString();
}
