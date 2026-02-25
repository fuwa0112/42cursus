/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 08:44:16 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/24 16:51:54 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << CYAN << "Animal default constructor called" << NOCOL << std::endl;
}

Animal::Animal(const std::string& t) : type(t)
{
    std::cout << CYAN << "Animal type constructor called" << NOCOL << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type)
{
    std::cout << CYAN << "Animal copy constructor called" << NOCOL << std::endl;
}

Animal::~Animal()
{
    std::cout << CYAN << "Animal destructor called" << NOCOL << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << CYAN << "Animal assignation operator called" << NOCOL << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

std::string Animal::getType() const
{
    return this->type;
}

void Animal::makeSound() const
{
    std::cout << CYAN << "I'm a generic animal, I don't have a sound :(" << NOCOL << std::endl;
}
