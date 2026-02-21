/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 08:44:16 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/22 08:44:17 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type("Animal")
{
    std::cout << CYAN << "Animal default constructor called" << NOCOL << std::endl;
}

Animal::Animal(Animal const &src)
{
    *this = src;
    std::cout << CYAN << "Animal copy constructor called" << NOCOL << std::endl;
}

Animal::~Animal(void)
{
    std::cout << CYAN << "Animal destructor called" << NOCOL << std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
    this->type = src.getType();
    std::cout << CYAN << "Animal assignation operator called" << NOCOL << std::endl;
    return *this;
}

std::string Animal::getType(void) const
{
    return this->type;
}

void Animal::makeSound(void) const
{
    std::cout << CYAN << "I'm a generic animal, I don't have a sound :(" << NOCOL << std::endl;
}
