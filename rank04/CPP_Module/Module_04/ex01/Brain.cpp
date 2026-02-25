/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 08:44:52 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/25 11:46:15 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << GREEN << "Brain default constructor called" << NOCOL << std::endl;
}

Brain::Brain(const Brain& other)
{
    std::cout << GREEN << "Brain copy constructor called" << NOCOL <<  std::endl;
    *this = other;
}

Brain::~Brain()
{
    std::cout << GREEN << "Brain destructor called" << NOCOL <<  std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 100; ++i)
            this->ideas[i] = other.ideas[i];
    }
    return *this;
}

void Brain::setIdea(int idx, const std::string& idea)
{
    if (idx < 0 || idx >= 100)
        return;
    this->ideas[idx] = idea;
}

std::string Brain::getIdea(int idx) const
{
    if (idx < 0 || idx >= 100)
        return "";
    return this->ideas[idx];
}