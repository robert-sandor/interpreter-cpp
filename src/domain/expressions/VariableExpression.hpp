//
// Created by robert on 12/13/15.
//

#ifndef INTERPRETER_CPP_VARIABLEEXPRESSION_HPP
#define INTERPRETER_CPP_VARIABLEEXPRESSION_HPP

#include <string>
#include <map>

#include "Expression.hpp"

class VariableExpression : public Expression {

public:
    VariableExpression(const std::string &variableName) : variableName(variableName) { }

    virtual ~VariableExpression() { }


    virtual int evaluate(std::map<std::string, int> &symbolTable);

    virtual std::string toString();

private:
    std::string variableName;
};


#endif //INTERPRETER_CPP_VARIABLEEXPRESSION_HPP
