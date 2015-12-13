cmake_minimum_required(VERSION 3.3)
project(interpreter_cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/parser/ExpressionParser.cpp src/parser/ExpressionParser.hpp src/domain/expressions/Expression.hpp src/domain/expressions/ConstantExpression.cpp src/domain/expressions/ConstantExpression.hpp src/domain/Program.cpp src/domain/Program.hpp src/domain/expressions/VariableExpression.cpp src/domain/expressions/VariableExpression.hpp src/domain/exceptions/VariableNotFoundException.cpp src/domain/exceptions/VariableNotFoundException.hpp src/domain/expressions/ArithmeticExpression.cpp src/domain/expressions/ArithmeticExpression.hpp src/domain/exceptions/DivisionByZeroException.cpp src/domain/exceptions/DivisionByZeroException.hpp)
add_executable(interpreter_cpp ${SOURCE_FILES})