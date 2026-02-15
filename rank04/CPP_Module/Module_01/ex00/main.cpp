/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 06:21:56 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/15 06:21:57 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main(void)
{
    Zombie newZombieStack = Zombie("Stacky");
    newZombieStack.announce();

    Zombie* newZombieHeap = newZombie("Heapy");
    newZombieHeap->announce();

    randomChump("Stacky 2");

    Zombie* newZombieHeap2 = newZombie("Heapy 2");
    newZombieHeap2->announce();
    
    std::cout << "End of program" << std::endl;

    delete newZombieHeap;
    delete newZombieHeap2;
    return (0);
}
