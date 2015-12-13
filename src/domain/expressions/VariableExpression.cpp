//
// Created by robert on 12/13/15.
//

#include "VariableExpression.hpp"
#include "../exceptions/VariableNotFoundException.hpp"

int VariableExpression::evaluate(std::map<std::string, int> &symbolTable) {
    int val;

    try {
        val = symbolTable.at(this->variableName);
    } catch (std::out_of_range) {
        throw new VariableNotFoundException();
    }

    return val;
}

std::string VariableExpression::toString() {
    return this->variableName;
}
