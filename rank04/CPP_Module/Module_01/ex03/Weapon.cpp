/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 06:22:38 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/15 06:22:39 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

#include <iomanip>
#include <iostream>

Weapon::Weapon(void)
{
}
Weapon::Weapon(std::string type) : _type(type)
{
}

Weapon::~Weapon(void)
{
}

std::string const &Weapon::getType(void) const
{
    const std::string &typeRef = this->_type;
    return typeRef;
}

void Weapon::setType(std::string type)
{
    this->_type = type;
}
