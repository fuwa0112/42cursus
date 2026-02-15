/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 06:22:18 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/15 19:33:44 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
    Zombie *zombieHorde = new Zombie[N];

    for (int i = 0; i < N; ++i)
    {
        // std::string zombieName = name + " " + std::to_string(i + 1);
        // zombieHorde[i].setName(zombieName);
		zombieHorde[i].setName(name);
    }
    return zombieHorde;
}
