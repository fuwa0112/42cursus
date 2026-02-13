/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:36:17 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/12 12:36:18 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : _type( "WrongAnimel" ) {
    std::cout << this->_type << " constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( std::string type ) : _type( type )
{
    std::cout << "WrongAnimal " << this->_type << " constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal( void )
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& src )
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = src;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& rhs )
{
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    if ( this != &rhs ) {
        this->_type = rhs._type;
    }
    return *this;
}

void WrongAnimal::makeSound( void ) const
{
    std::cout << "WrongAnimal makeSound called" << std::endl;
}

std::string    WrongAnimal::getType( void ) const
{
    return this->_type;
}