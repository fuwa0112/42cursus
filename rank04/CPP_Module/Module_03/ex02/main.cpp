/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 08:42:41 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/24 13:27:21 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "=== FragTrap default constructor ===" << std::endl;
    FragTrap defaultTrap;
    std::cout << defaultTrap << std::endl;

    std::cout << "\n=== FragTrap with name ===" << std::endl;
    FragTrap* namedTrap = new FragTrap("Fraggy");
    std::cout << *namedTrap << std::endl;

    std::cout << "\n=== Copy constructor ===" << std::endl;
    FragTrap copyTrap(*namedTrap);
    std::cout << copyTrap << std::endl;

    std::cout << "\n=== Assignment operator ===" << std::endl;
    FragTrap assignedTrap;
    assignedTrap = *namedTrap;
    std::cout << assignedTrap << std::endl;

    std::cout << "\n=== Basic attack / damage ===" << std::endl;
    defaultTrap.attack(namedTrap->getName());
    namedTrap->takeDamage(defaultTrap.getAttackDamage());
    std::cout << *namedTrap << std::endl;

    std::cout << "\n=== Repair test ===" << std::endl;
    namedTrap->beRepaired(10);
    std::cout << *namedTrap << std::endl;

    std::cout << "\n=== High Five ability ===" << std::endl;
    namedTrap->highFivesGuys();

    std::cout << "\n=== EP depletion test ===" << std::endl;
    for (int i = 0; i < 105; i++)
        namedTrap->attack("dummy");

    std::cout << "\n=== HP to zero test ===" << std::endl;
    namedTrap->takeDamage(1000);
    namedTrap->attack("dummy");
    namedTrap->beRepaired(10);

    std::cout << "\n=== Destructor order check ===" << std::endl;
    delete namedTrap;

    std::cout << "\n=== End of main ===" << std::endl;
    return 0;
}
