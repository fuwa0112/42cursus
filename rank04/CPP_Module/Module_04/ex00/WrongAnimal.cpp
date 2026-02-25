/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 08:44:33 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/24 16:55:39 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << RED << "WrongAnimal default constructor called" << NOCOL << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type)
{
    std::cout << RED << "WrongAnimal copy constructor called" << NOCOL << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << RED << "WrongAnimal destructor called" << NOCOL << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout << RED << "WrongAnimal assignation operator called" << NOCOL << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}

void WrongAnimal::makeSound() const
{
    std::cout << RED << "WrongAnimal strange sound" << NOCOL << std::endl;
}
