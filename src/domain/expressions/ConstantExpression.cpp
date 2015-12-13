//
// Created by robert on 12/13/15.
//

#include "ConstantExpression.hpp"

int ConstantExpression::evaluate(std::map<std::string, int>& symbolTable) {
    return this->number;
}

std::string ConstantExpression::toString() {
    return std::to_string(this->number);
}
