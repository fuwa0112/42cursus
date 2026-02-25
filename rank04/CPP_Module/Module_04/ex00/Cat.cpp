/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 08:44:19 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/24 16:59:05 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << PURPLE << "Cat default constructor called" << NOCOL << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << PURPLE << "Cat copy constructor called" << NOCOL << std::endl;
}

Cat::~Cat()
{
    std::cout << PURPLE << "Cat destructor called" << NOCOL << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << PURPLE << "Cat assignation operator called" << NOCOL << std::endl;
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

void Cat::makeSound() const
{
    std::cout << PURPLE << "Miao miao miao" << NOCOL << std::endl;
}