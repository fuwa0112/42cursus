/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 08:45:07 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/22 08:45:08 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
    std::cout << CYAN << "Animal default constructor called" << NOCOL << std::endl;
}

Animal::~Animal(void)
{
    std::cout << CYAN << "Animal destructor called" << NOCOL << std::endl;
}

Animal::Animal(Animal const &src)
{
    std::cout << CYAN << "Animal copy constructor called" << NOCOL << std::endl;
    *this = src;
}

Animal &Animal::operator=(const Animal &src)
{
    std::cout << CYAN << "Animal assignation operator called" << NOCOL << std::endl;
    this->type = src.getType();
    return *this;
}