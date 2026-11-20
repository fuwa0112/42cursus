/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 10:55:30 by thitoe            #+#    #+#             */
/*   Updated: 2026/11/20 15:45:51 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <climits>
#include <stack>
#include <string>

class RPN
{
    private:
        std::stack<int> _stack;
    public:
        RPN();
        RPN(const RPN &);
        RPN &operator=(const RPN &);
        ~RPN();
        void solution(const std::string &input);
        int calculation(int number1, int number2, char c) const;
        class InvalidInput : public std::exception
        {
            public:
                const char *what() const throw();
        };
        class WrongOperands : public std::exception
        {
            public:
                const char *what() const throw();
        };
        class InvalidExpression : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

#endif
