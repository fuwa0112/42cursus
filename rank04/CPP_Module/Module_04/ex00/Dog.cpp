/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 08:44:26 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/22 08:44:27 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : type("Dog")
{
    std::cout << BLUE << "Dog default constructor called" << NOCOL << std::endl;
}

Dog::Dog(Dog const &src)
{
    *this = src;
    std::cout << BLUE << "Dog copy constructor called" << NOCOL << std::endl;
}

Dog::~Dog(void)
{
    std::cout << BLUE << "Dog destructor called" << NOCOL << std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
    this->type = src.getType();
    std::cout << BLUE << "Dog assignation operator called" << NOCOL << std::endl;
    return *this;
}

std::string Dog::getType(void) const
{
    return this->type;
}

void Dog::makeSound(void) const
{
    std::cout << BLUE << "Bau bau bau" << NOCOL << std::endl;
}