/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 10:55:27 by thitoe            #+#    #+#             */
/*   Updated: 2026/11/20 15:45:21 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{}

RPN::RPN(const RPN &obj) : _stack(obj._stack)
{}

RPN &RPN::operator=(const RPN &obj)
{
    if (this != &obj)
        _stack = obj._stack;
    return (*this);
}

RPN::~RPN()
{}

const char *RPN::InvalidInput::what() const throw()
{
    return ("Error: Invalid Input!!!");
}

const char *RPN::WrongOperands::what() const throw()
{
    return ("Error: Insufficient Operands!!!");
}

const char *RPN::InvalidExpression::what() const throw()
{
    return ("Error: Invalid Expression!!!");
}

int RPN::calculation(int number1, int number2, char c) const
{
    switch (c)
    {
        case '+':
            if ((number2 > 0 && number1 > INT_MAX - number2)
                || (number2 < 0 && number1 < INT_MIN - number2))
                throw RPN::InvalidInput();
            return (number1 + number2);

        case '-':
            if ((number2 < 0 && number1 > INT_MAX + number2)
                || (number2 > 0 && number1 < INT_MIN + number2))
                throw RPN::InvalidInput();
            return (number1 - number2);

        case '*':
            if (number1 > 0)
            {
                if ((number2 > 0 && number1 > INT_MAX / number2)
                    || (number2 < 0 && number2 < INT_MIN / number1))
                    throw RPN::InvalidInput();
            }
            else if (number1 < 0)
            {
                if ((number2 > 0 && number1 < INT_MIN / number2)
                    || (number2 < 0 && number1 < INT_MAX / number2))
                    throw RPN::InvalidInput();
            }
            return (number1 * number2);

        case '/':
            if (number2 == 0
                || (number1 == INT_MIN && number2 == -1))
                throw RPN::InvalidInput();
            return (number1 / number2);

        default:
            throw RPN::InvalidInput();
    }
}

void RPN::solution(const std::string &input)
{
    _stack = std::stack<int>();

    std::istringstream iss(input);
    std::string token;

    while (iss >> token)
    {
        if (token.length() == 1
            && token[0] >= '0' && token[0] <= '9')
        {
            _stack.push(token[0] - '0');
        }
        else if (token == "+" || token == "-"
            || token == "*" || token == "/")
        {
            if (_stack.size() < 2)
                throw RPN::WrongOperands();

            int number2 = _stack.top();
            _stack.pop();

            int number1 = _stack.top();
            _stack.pop();

            int result = calculation(number1, number2, token[0]);
            _stack.push(result);
        }
        else
            throw RPN::InvalidInput();
    }

    if (_stack.size() != 1)
        throw RPN::InvalidExpression();

    std::cout << _stack.top() << std::endl;
}
