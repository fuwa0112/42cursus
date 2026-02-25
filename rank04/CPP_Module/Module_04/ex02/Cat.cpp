/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 08:44:19 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/25 11:47:07 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), brain(new Brain())
{
    std::cout << PURPLE << "Cat default constructor called" << NOCOL << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain))
{
    std::cout << PURPLE << "Cat copy constructor called" << NOCOL << std::endl;
}

Cat::~Cat()
{
    std::cout << PURPLE << "Cat destructor called" << NOCOL << std::endl;
    delete this->brain;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << PURPLE << "Cat assignation operator called" << NOCOL << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        *this->brain = *other.brain;
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << PURPLE << "Miao miao miao" << NOCOL << std::endl;
}

void Cat::setIdea(int idx, const std::string& idea)
{
    this->brain->setIdea(idx, idea);
}

std::string Cat::getIdea(int idx) const
{
    return this->brain->getIdea(idx);
}