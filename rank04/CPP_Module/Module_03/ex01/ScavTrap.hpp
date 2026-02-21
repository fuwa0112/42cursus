/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 08:42:24 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/22 08:42:25 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __SCAVTRAP_H__
#define __SCAVTRAP_H__
#include <iostream>
#include "ClapTrap.hpp"
#define YELLOW "\033[1;33m"
#define NOCOL "\033[0m"

class ScavTrap : public ClapTrap
{
public:
    ScavTrap(void);
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap &src);

    ~ScavTrap(void);

    ScavTrap &operator=(ScavTrap const &src);

    void attack(std::string const &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    void guardGate(void) const;

private:
    using ClapTrap::AttackDamage;
    using ClapTrap::EnergyPoints;
    using ClapTrap::Hitpoints;
    using ClapTrap::Name;
};

#endif