/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:37:02 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/12 12:37:03 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    // std::cout << "* Ice: materia is created *" << std::endl;
}

Ice::Ice( Ice const & src ) : AMateria("ice")
{
    *this = src;
    // std::cout << "* Ice: materia is copied *" << std::endl;
}

Ice&   Ice::operator=( const Ice& rhs ) {
    if (this != &rhs)
    {
        this->_type = rhs._type;
    }
    return *this;
}

Ice::~Ice()
{
    // std::cout << "* Ice: ice is destroyed *" << std::endl;
}

AMateria* Ice::clone() const
{
    return (new Ice(*this));
}

void    Ice::use( ICharacter& target )
{
    std::cout << "I shoots an ice bolt at " << target.getName() << std::endl;
}

