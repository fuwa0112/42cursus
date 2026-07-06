/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 10:54:28 by thitoe            #+#    #+#             */
/*   Updated: 2026/07/03 15:46:48 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

const char *Span::FullContainerException::what() const throw()
{
    return ("Error, Span Is Full.");
}

const char *Span::NotEnoughNumberInVector::what() const throw()
{
    return ("Error, Span Does Not Have Enough Numbers.");
}

Span::Span()
{
    this->N = 0;
}

Span::Span(unsigned int N)
{
    this->N = N;
}

Span::~Span()
{}

Span::Span(const Span &obj)
{
    *this = obj;
}

Span &Span::operator=(const Span &obj)
{
    if (this != &obj)
    {
        this->N = obj.N;
        this->vect = obj.vect;
    }
    return (*this);
}

void Span::addNumber(const int &num)
{
    if (vect.size() >= N)
        throw FullContainerException();
    vect.push_back(num);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (vect.size() + std::distance(begin, end) > N)
        throw FullContainerException();
    vect.insert(vect.end(), begin, end);
}

int Span::shortest_span()
{
    if (vect.size() <= 1)
        throw NotEnoughNumberInVector();
    std::vector<int>temp = vect;
    std::sort(temp.begin(), temp.end());
    int min_number = temp[1] - temp[0];
    for (size_t i = 1; i < temp.size(); i++)
        if (temp[i] - temp[i - 1] < min_number)
            min_number = temp[i] - temp[i - 1];
    return (min_number);
}

int Span::longest_span()
{
    if (vect.size() <= 1)
        throw NotEnoughNumberInVector();
    std::vector<int>temp = vect;
    std::sort(temp.begin(), temp.end());
    return (temp[temp.size() - 1] - temp[0]);
}
