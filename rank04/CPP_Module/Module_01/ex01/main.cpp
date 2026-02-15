/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 06:22:10 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/15 19:28:05 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int main(void)
{
    const int NUM_ZOMBIES = 10;
    Zombie *zombies = zombieHorde(NUM_ZOMBIES, "Chad");
    for (int i = 0; i < NUM_ZOMBIES; ++i)
    {
        zombies[i].announce();
    }
    delete[] zombies;
    return (0);
}
