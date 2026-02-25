/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 08:44:36 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/24 16:56:30 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->type = "WrongCat";
    std::cout << YELLOW << "WrongCat default constructor called" << NOCOL << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    std::cout << YELLOW << "WrongCat copy constructor called" << NOCOL << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << YELLOW << "WrongCat destructor called" << NOCOL << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout << YELLOW << "WrongCat assignation operator called" << NOCOL << std::endl;
    if (this != &other)
        WrongAnimal::operator=(other);
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << YELLOW << "WrongCat meow" << NOCOL << std::endl;
}