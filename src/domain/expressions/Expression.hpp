//
// Created by robert on 12/13/15.
//

#ifndef INTERPRETER_CPP_EXPRESSION_HPP
#define INTERPRETER_CPP_EXPRESSION_HPP

#include <string>
#include <map>

class Expression {
public:
    virtual int evaluate(std::map<std::string, int>& symbolTable) = 0;
    virtual std::string toString() = 0;
};


#endif //INTERPRETER_CPP_EXPRESSION_HPP
