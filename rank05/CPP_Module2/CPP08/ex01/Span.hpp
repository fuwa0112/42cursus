/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 10:54:31 by thitoe            #+#    #+#             */
/*   Updated: 2026/07/03 10:54:32 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span
{
    private:
        unsigned int N;
        std::vector<int> vect;
    public:
        Span();
        Span(unsigned int N);
        ~Span();
        Span(const Span &);
        Span &operator=(const Span &);
        void addNumber(const int &num);
        void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int shortest_span();
        int longest_span();
        class FullContainerException : public std::exception
        {
            const char *what() const throw();
        };
        class NotEnoughNumberInVector : public std::exception
        {
            const char *what() const throw();
        };
};

#endif
