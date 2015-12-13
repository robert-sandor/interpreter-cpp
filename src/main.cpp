#include <iostream>

#include "parser/ExpressionParser.hpp"

int main() {
    std::string expression = "((2+1)-(3/2))*(4-2)";
    std::map<std::string, int> st;
    ExpressionParser * p = new ExpressionParser();
    Expression * exp = p->parse(expression);
    std::cout << exp->evaluate(st) << std::endl;
    return 0;
}