/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 06:22:14 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/15 19:29:44 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <iomanip>
#include <iostream>

Zombie::Zombie(void)
{
    std::cout << "Zombie initialized without name" << std::endl;
    return;
}
Zombie::Zombie(std::string name) : _name(name)
{
    std::cout << name << " initialized" << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << this->_name << " is dead" << std::endl;
}

void Zombie::announce(void) const
{
    std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    this->_name = name;
}
