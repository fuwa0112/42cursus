/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 08:42:31 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/24 13:13:23 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
    std::cout << "ClapTrap with default constructor:" << std::endl;
    ClapTrap defaultTrap;
    std::cout << defaultTrap << std::endl;

    std::cout << "ClapTrap with name:" << std::endl;
    ClapTrap namedTrap("Clappy");
    std::cout << namedTrap << std::endl;

    std::cout << "Copycat ClapTrap (copy constructor):" << std::endl;
    ClapTrap copycat(namedTrap);
    std::cout << copycat << std::endl;

    std::cout << "Copycat ClapTrap (assignment operator):" << std::endl;
    ClapTrap copycat2;
    copycat2 = namedTrap;
    std::cout << copycat2 << std::endl;

    std::cout << "\n--- Basic attack / damage ---" << std::endl;
    defaultTrap.attack(namedTrap.getName());
    namedTrap.takeDamage(defaultTrap.getAttackDamage());
    std::cout << namedTrap << std::endl;

    std::cout << "\n--- EP depletion test (attack/repair costs 1 EP) ---" << std::endl;
    for (int i = 0; i < 12; i++)
    {
        std::cout << "Try repair #" << i + 1 << std::endl;
        namedTrap.beRepaired(1);
    }
    std::cout << namedTrap << std::endl;

    std::cout << "\n--- HP to zero test (should clamp at 0) ---" << std::endl;
    namedTrap.takeDamage(1000);
    std::cout << namedTrap << std::endl;

    std::cout << "\n--- Actions when HP=0 or EP=0 ---" << std::endl;
    namedTrap.attack("someone");
    namedTrap.beRepaired(10);
    namedTrap.takeDamage(1);

    std::cout << "\n--- End of main (destructors) ---" << std::endl;
    return 0;
}
