/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 08:44:26 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/25 11:53:56 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain())
{
    std::cout << BLUE << "Dog default constructor called" << NOCOL << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain))
{
    std::cout << BLUE << "Dog copy constructor called" << NOCOL << std::endl;
}

Dog::~Dog()
{
    std::cout << BLUE << "Dog destructor called" << NOCOL << std::endl;
    delete this->brain;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << BLUE << "Dog assignation operator called" << NOCOL << std::endl;

    if (this != &other)
    {
        Animal::operator=(other);
        *this->brain = *other.brain;
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << BLUE << "Woof woof" << NOCOL << std::endl;
}

void Dog::setIdea(int idx, const std::string& idea)
{
    this->brain->setIdea(idx, idea);
}

std::string Dog::getIdea(int idx) const
{
    return this->brain->getIdea(idx);
}

