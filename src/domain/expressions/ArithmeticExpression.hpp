//
// Created by robert on 12/13/15.
//

#ifndef INTERPRETER_CPP_ARITHMETICEXPRESSION_HPP
#define INTERPRETER_CPP_ARITHMETICEXPRESSION_HPP


#include "Expression.hpp"

class ArithmeticExpression : public Expression {
public:
    typedef enum {
        ADD, SUB, MUL, DIV
    } Operator;


    ArithmeticExpression(const Operator &op,
                         Expression *leftExpression,
                         Expression *rightExpression) : op(op),
                                                        leftExpression(leftExpression),
                                                        rightExpression(rightExpression) { }


    virtual ~ArithmeticExpression() { }


    virtual int evaluate(std::map<std::string, int> &symbolTable);

    virtual std::string toString();

private:
    Operator op;
    Expression *leftExpression;
    Expression *rightExpression;
};


#endif //INTERPRETER_CPP_ARITHMETICEXPRESSION_HPP
