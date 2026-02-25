/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 08:42:38 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/24 13:25:05 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
    this->Hitpoints = 100;
    this->EnergyPoints = 100;
    this->AttackDamage = 30;
    std::cout << MAGENTA << "FragTrap default constructor called" << NOCOL << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    this->Hitpoints = 100;
    this->EnergyPoints = 100;
    this->AttackDamage = 30;
    std::cout << MAGENTA << "FragTrap parameter constructor called (" << this->Name << ")" << NOCOL << std::endl;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src)
{
    std::cout << MAGENTA << "FragTrap copy constructor called (" << this->Name << ")" << NOCOL << std::endl;
}

FragTrap::~FragTrap(void)
{
    std::cout << MAGENTA << "FragTrap destructor called ("
              << (this->Name.length() ? this->Name : "without name")
              << ")" << NOCOL << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& src)
{
    if (this != &src)
        ClapTrap::operator=(src);
    std::cout << MAGENTA << "FragTrap assignment operator overload called" << NOCOL << std::endl;
    return *this;
}

void FragTrap::attack(const std::string& target)
{
    if (this->Hitpoints <= 0)
    {
        std::cout << MAGENTA << "FragTrap "
                  << (this->Name.length() ? this->Name : "without name")
                  << " can't attack because it has no hit points left!" << NOCOL << std::endl;
        return;
    }
    if (this->EnergyPoints <= 0)
    {
        std::cout << MAGENTA << "FragTrap "
                  << (this->Name.length() ? this->Name : "without name")
                  << " can't attack because it has no energy points left!" << NOCOL << std::endl;
        return;
    }

    this->EnergyPoints--;
    std::cout << MAGENTA << "FragTrap " << (this->Name.length() ? this->Name : "without name")
              << " attacks " << (target.length() ? target : "Unnamed trap")
              << ", causing " << this->AttackDamage << " points of damage!" << NOCOL << std::endl;
}

void FragTrap::highFivesGuys(void) const
{
    std::cout << MAGENTA << "FragTrap "
              << (this->Name.length() ? this->Name : "without name")
              << " requests a positive high five!" << NOCOL << std::endl;
}
