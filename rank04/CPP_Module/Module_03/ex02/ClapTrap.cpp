/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 08:42:28 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/22 20:50:15 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iomanip>

ClapTrap::ClapTrap(void)
    : Name(""), Hitpoints(10), EnergyPoints(10), AttackDamage(0)
{
    std::cout << CYAN << "ClapTrap default constructor called" << NOCOL << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
    : Name(name), Hitpoints(10), EnergyPoints(10), AttackDamage(0)
{
    std::cout << CYAN << "ClapTrap parameter constructor called (" << this->Name << ")" << NOCOL << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
    : Name(src.Name),
      Hitpoints(src.Hitpoints),
      EnergyPoints(src.EnergyPoints),
      AttackDamage(src.AttackDamage)
{
    std::cout << CYAN << "ClapTrap copy constructor called (" << this->Name << ")" << NOCOL << std::endl;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << CYAN << "ClapTrap destructor called (" 
              << (this->Name.length() ? this->Name : "without name")
              << ")" << NOCOL << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
    if (this != &src)
    {
        this->Name = src.Name;
        this->Hitpoints = src.Hitpoints;
        this->EnergyPoints = src.EnergyPoints;
        this->AttackDamage = src.AttackDamage;
    }
    std::cout << CYAN << "Assignment operator overload called" << NOCOL << std::endl;
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->Hitpoints <= 0)
    {
        std::cout << CYAN << "ClapTrap "
                  << (this->Name.length() ? this->Name : "without name")
                  << " can't attack because it has no hit points left!" << NOCOL << std::endl;
        return;
    }
    if (this->EnergyPoints <= 0)
    {
        std::cout << CYAN << "ClapTrap "
                  << (this->Name.length() ? this->Name : "without name")
                  << " can't attack because it has no energy points left!" << NOCOL << std::endl;
        return;
    }

    this->EnergyPoints--;
    std::cout << CYAN << "ClapTrap " << (this->Name.length() ? this->Name : "without name")
              << " attacks " << (target.length() ? target : "Unnamed trap")
              << ", causing " << this->AttackDamage << " points of damage!" << NOCOL << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->Hitpoints <= 0)
    {
        std::cout << CYAN << "ClapTrap "
                  << (this->Name.length() ? this->Name : "without name")
                  << " is already destroyed and can't take more damage!" << NOCOL << std::endl;
        return;
    }

    if (amount >= static_cast<unsigned int>(this->Hitpoints))
        this->Hitpoints = 0;
    else
        this->Hitpoints -= static_cast<int>(amount);

    std::cout << CYAN << "ClapTrap " << (this->Name.length() ? this->Name : "without name")
              << " takes " << amount << " points of damage! "
              << "HP is now " << this->Hitpoints << "." << NOCOL << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->Hitpoints <= 0)
    {
        std::cout << CYAN << "ClapTrap "
                  << (this->Name.length() ? this->Name : "without name")
                  << " can't be repaired because it has no hit points left!" << NOCOL << std::endl;
        return;
    }
    if (this->EnergyPoints <= 0)
    {
        std::cout << CYAN << "ClapTrap "
                  << (this->Name.length() ? this->Name : "without name")
                  << " can't be repaired because it has no energy points left!" << NOCOL << std::endl;
        return;
    }

    this->EnergyPoints--;
    this->Hitpoints += static_cast<int>(amount);

    std::cout << CYAN << "ClapTrap " << (this->Name.length() ? this->Name : "without name")
              << " repairs itself, regaining " << amount << " hit points! "
              << "HP is now " << this->Hitpoints << "." << NOCOL << std::endl;
}

std::string ClapTrap::getName(void) const { return this->Name; }
int ClapTrap::getHitPoints(void) const { return this->Hitpoints; }
int ClapTrap::getEnergyPoints(void) const { return this->EnergyPoints; }
int ClapTrap::getAttackDamage(void) const { return this->AttackDamage; }

std::ostream &operator<<(std::ostream &os, ClapTrap const &ct)
{
    os << "_______________________________" << std::endl;
    os << "| Name            | " << std::setw(10) << (ct.getName().length() ? ct.getName() : "n/a") << "|" << std::endl;
    os << "| Hit points      | " << std::setw(10) << ct.getHitPoints() << "|" << std::endl;
    os << "| Damage points   | " << std::setw(10) << ct.getAttackDamage() << "|" << std::endl;
    os << "| Energy points   | " << std::setw(10) << ct.getEnergyPoints() << "|" << std::endl;
    os << "-------------------------------" << std::endl;
    return os;
}
