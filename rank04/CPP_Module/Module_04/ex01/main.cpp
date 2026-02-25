/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 08:45:02 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/25 12:18:44 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    std::cout << "Array of 4 animals:" << std::endl;

    const int N = 4;
    Animal* animals[N];

    for (int idx = 0; idx < N; ++idx)
    {
        if (idx < N / 2)
            animals[idx] = new Dog();
        else
            animals[idx] = new Cat();
    }

    std::cout << std::endl;

    for (int idx = 0; idx < N; ++idx)
    {
        std::cout << animals[idx]->getType() << ": ";
        animals[idx]->makeSound();
    }

    std::cout << "\nDeleting as Animal* (virtual destructor required):" << std::endl;
    for (int idx = 0; idx < N; ++idx)
    {
        delete animals[idx];
        std::cout << std::endl;
    }

    std::cout << "Deep copy tests (Cat):" << std::endl;
    Cat seed;
    seed.setIdea(0, "seed idea");
    std::cout << "seed idea[0]: " << seed.getIdea(0) << std::endl;

    Cat copy(seed);
    std::cout << "copy idea[0]: " << copy.getIdea(0) << std::endl;

    Cat copy2;
    copy2 = seed;
    std::cout << "copy2 idea[0]: " << copy2.getIdea(0) << std::endl;

    seed.setIdea(0, "changed in seed");

    std::cout << "\nAfter modifying seed:" << std::endl;
    std::cout << "seed  idea[0]: " << seed.getIdea(0) << std::endl;
    std::cout << "copy  idea[0]: " << copy.getIdea(0) << std::endl;
    std::cout << "copy2 idea[0]: " << copy2.getIdea(0) << std::endl;

    std::cout << "\nDeep copy tests (Dog):" << std::endl;
    Dog seedDog;
    seedDog.setIdea(0, "dog seed idea");
    std::cout << "seedDog idea[0]: " << seedDog.getIdea(0) << std::endl;

    Dog copyDog(seedDog);
    std::cout << "copyDog idea[0]: " << copyDog.getIdea(0) << std::endl;

    Dog copy2Dog;
    copy2Dog = seedDog;
    std::cout << "copy2Dog idea[0]: " << copy2Dog.getIdea(0) << std::endl;

    seedDog.setIdea(0, "changed in seedDog");

    std::cout << "\nAfter modifying seedDog:" << std::endl;
    std::cout << "seedDog  idea[0]: " << seedDog.getIdea(0) << std::endl;
    std::cout << "copyDog  idea[0]: " << copyDog.getIdea(0) << std::endl;
    std::cout << "copy2Dog idea[0]: " << copy2Dog.getIdea(0) << std::endl;

    std::cout << "\nScope test (destruction of temp shouldn't affect original):" << std::endl;
    Dog basic;
    basic.setIdea(1, "basic idea");
    {
        Dog tmp = basic;
        std::cout << "tmp   idea[1]: " << tmp.getIdea(1) << std::endl;
    }
    std::cout << "basic idea[1]: " << basic.getIdea(1) << std::endl;

    return 0;
}