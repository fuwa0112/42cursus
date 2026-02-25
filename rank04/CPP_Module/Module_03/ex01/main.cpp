/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 08:42:19 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/24 13:18:17 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
    std::cout << "ScavTrap with default constructor:" << std::endl;
    ScavTrap defaultTrap;
    std::cout << defaultTrap << std::endl;

    std::cout << "ScavTrap with name:" << std::endl;
    ScavTrap *namedTrap = new ScavTrap("Scavvy");
    std::cout << *namedTrap << std::endl;

    std::cout << "Copycat ScavTrap (assignment operator):" << std::endl;
    ScavTrap copyTrap;
    copyTrap = *namedTrap;
    std::cout << copyTrap << std::endl;

    std::cout << "Copycat ScavTrap (copy constructor):" << std::endl;
    ScavTrap copyTrap2(copyTrap);
    std::cout << copyTrap2 << std::endl;

    std::cout << "\n--- Basic actions ---" << std::endl;
    defaultTrap.attack(namedTrap->getName());
    namedTrap->takeDamage(defaultTrap.getAttackDamage());
    std::cout << *namedTrap << std::endl;

    namedTrap->beRepaired(10);
    std::cout << *namedTrap << std::endl;

    namedTrap->guardGate();

    std::cout << "\n--- EP depletion test (should stop at EP=0) ---" << std::endl;
    for (int i = 0; i < 60; i++)
        namedTrap->attack("dummy");

	std::cout << *namedTrap << std::endl;

    std::cout << "\n--- HP to zero test (should stop at HP=0) ---" << std::endl;
    namedTrap->takeDamage(1000);
    namedTrap->attack("dummy");
    namedTrap->beRepaired(5);

    std::cout << "\n--- Destructor order check (delete) ---" << std::endl;
    delete namedTrap;

    std::cout << "\n--- End of main (stack objects destruct) ---" << std::endl;
    return 0;
}
