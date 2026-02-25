/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 08:42:23 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/24 15:54:20 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
    this->Hitpoints = 100;
    this->EnergyPoints = 50;
    this->AttackDamage = 20;
    std::cout << YELLOW << "ScavTrap default constructor called" << NOCOL << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    this->Hitpoints = 100;
    this->EnergyPoints = 50;
    this->AttackDamage = 20;
    std::cout << YELLOW << "ScavTrap parameter constructor called (" << this->Name << ")" << NOCOL << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src)
{
    std::cout << YELLOW << "ScavTrap copy constructor called (" << this->Name << ")" << NOCOL << std::endl;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << YELLOW << "ScavTrap destructor called (" 
              << (this->Name.length() ? this->Name : "without name")
              << ")" << NOCOL << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src)
{
    if (this != &src)
        ClapTrap::operator=(src);
    std::cout << YELLOW << "ScavTrap assignment operator overload called" << NOCOL << std::endl;
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->Hitpoints <= 0)
    {
        std::cout << YELLOW << "ScavTrap "
                  << (this->Name.length() ? this->Name : "without name")
                  << " can't attack because it has no hit points left!" << NOCOL << std::endl;
        return;
    }
    if (this->EnergyPoints <= 0)
    {
        std::cout << YELLOW << "ScavTrap "
                  << (this->Name.length() ? this->Name : "without name")
                  << " can't attack because it has no energy points left!" << NOCOL << std::endl;
        return;
    }

    this->EnergyPoints--;
    std::cout << YELLOW << "ScavTrap " << (this->Name.length() ? this->Name : "without name")
              << " attacks " << (target.length() ? target : "Unnamed trap")
              << ", causing " << this->AttackDamage << " points of damage!" << NOCOL << std::endl;
}

void ScavTrap::guardGate(void) const
{
    std::cout << YELLOW << "ScavTrap "
              << (this->Name.length() ? this->Name : "without name")
              << " is now in Gate keeper mode." << NOCOL << std::endl;
}
