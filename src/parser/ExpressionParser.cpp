//
// Created by robert on 12/13/15.
//

#include <iostream>
#include "ExpressionParser.hpp"

Expression *ExpressionParser::parse(std::string expression) {
    // if the string is empty, return null
    if (0 == expression.length()) {
        return nullptr;
    }

    Expression *exp;
    exp = parseArithmeticExpression(expression);
    if (nullptr == exp) {
        exp = parseVariableExpression(expression);
        if (nullptr == exp) {
            exp = parseConstantExpression(expression);
        }
    }

    return exp;
}

ConstantExpression *ExpressionParser::parseConstantExpression(std::string expression) {
//    std::cout << "cexp : " << expression << std::endl;
    int value;
    try {
        value = std::stoi(expression);
    } catch (std::invalid_argument) {
        return nullptr;
    } catch (std::out_of_range) {
        return nullptr;
    }
    return new ConstantExpression(value);
}

VariableExpression *ExpressionParser::parseVariableExpression(std::string expression) {
//    std::cout << "vexp : " << expression << std::endl;

    if (isdigit(expression[0])) {
        return nullptr;
    }

    return new VariableExpression(expression);
}

ArithmeticExpression *ExpressionParser::parseArithmeticExpression(std::string expression) {
//    std::cout << "aexp : " << expression << std::endl;

    // try to find an operator
    std::size_t foundOperator = expression.find_first_of("+-*/");
    std::size_t foundParantheses = expression.find_first_of("(");

    if (foundOperator > foundParantheses) {
        int open = 1;
        int closed = 0;
        std::size_t index = foundParantheses;

        while (open > closed) {
            index++;
            if (index >= expression.length()) {
                return nullptr;
            }

            if (expression[index] == '(') {
                open++;
            } else if (expression[index] == ')') {
                closed++;
            }
        }

        expression.erase(foundParantheses, 1);
        expression.erase(index - 1, 1);
        foundOperator = expression.find_first_of("+-*/", index - 1);
    }

    if (foundOperator == std::string::npos) {
        // if the operator was not found
        std::size_t x = expression.find_first_of("+-*/");
        if (x == std::string::npos) {
            return nullptr;
        }
        else {
            foundOperator = x;
        }
    }

    ArithmeticExpression::Operator op;

    switch (expression[foundOperator]) {
        case '+':
            op = ArithmeticExpression::Operator::ADD;
            break;
        case '-':
            op = ArithmeticExpression::Operator::SUB;
            break;
        case '*':
            op = ArithmeticExpression::Operator::MUL;
            break;
        case '/':
            op = ArithmeticExpression::Operator::DIV;
            break;
        default:
            return nullptr;
    }

    Expression *left = parse(expression.substr(0, foundOperator));
    Expression *right = parse(expression.substr(foundOperator + 1, expression.length() - 1));

    return new ArithmeticExpression(op, left, right);
}
