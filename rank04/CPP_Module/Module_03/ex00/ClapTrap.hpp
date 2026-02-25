/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 08:42:29 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/25 21:54:05 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

#define CYAN "\033[1;36m"
#define NOCOL "\033[0m"

class ClapTrap
{
public:
    ClapTrap(void);
    ClapTrap(const std::string& name);
    ClapTrap(const ClapTrap& src);
    ~ClapTrap(void);

    ClapTrap& operator=(const ClapTrap& src);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    std::string getName(void) const;
    int getHitPoints(void) const;
    int getEnergyPoints(void) const;
    int getAttackDamage(void) const;

private:
    std::string Name;
    int         Hitpoints;
    int         EnergyPoints;
    int         AttackDamage;
};

std::ostream& operator<<(std::ostream& os, const ClapTrap& ct);

#endif