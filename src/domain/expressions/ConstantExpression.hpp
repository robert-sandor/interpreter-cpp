//
// Created by robert on 12/13/15.
//

#ifndef INTERPRETER_CPP_CONSTANTEXPRESSION_HPP
#define INTERPRETER_CPP_CONSTANTEXPRESSION_HPP

#include "Expression.hpp"

class ConstantExpression : public Expression {
public:

    ConstantExpression(int number) : number(number) { }

    virtual ~ConstantExpression() { }

    virtual int evaluate(std::map<std::string, int> &symbolTable);

    virtual std::string toString();

private:
    int number;
};


#endif //INTERPRETER_CPP_CONSTANTEXPRESSION_HPP
