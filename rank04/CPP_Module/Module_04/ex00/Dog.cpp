/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 08:44:26 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/24 16:54:42 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << BLUE << "Dog default constructor called" << NOCOL << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << BLUE << "Dog copy constructor called" << NOCOL << std::endl;
}

Dog::~Dog()
{
    std::cout << BLUE << "Dog destructor called" << NOCOL << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << BLUE << "Dog assignation operator called" << NOCOL << std::endl;
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

void Dog::makeSound() const
{
    std::cout << BLUE << "Woof woof" << NOCOL << std::endl;
}