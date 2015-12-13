//
// Created by robert on 12/13/15.
//

#ifndef INTERPRETER_CPP_EXPRESSIONPARSER_H
#define INTERPRETER_CPP_EXPRESSIONPARSER_H


#include "../domain/expressions/Expression.hpp"
#include "../domain/expressions/ConstantExpression.hpp"
#include "../domain/expressions/VariableExpression.hpp"
#include "../domain/expressions/ArithmeticExpression.hpp"

class ExpressionParser {
public:
    Expression * parse(std::string expression);

private:
    ConstantExpression * parseConstantExpression(std::string expression);
    VariableExpression * parseVariableExpression(std::string expression);
    ArithmeticExpression * parseArithmeticExpression(std::string expression);
};


#endif //INTERPRETER_CPP_EXPRESSIONPARSER_H
