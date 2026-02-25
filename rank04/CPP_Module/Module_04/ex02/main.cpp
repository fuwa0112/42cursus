/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 08:45:22 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/25 12:27:51 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    std::cout << "Polymorphism test:" << std::endl;

    const Animal* a1 = new Dog();
    const Animal* a2 = new Cat();

    std::cout << a1->getType() << ": ";
    a1->makeSound();

    std::cout << a2->getType() << ": ";
    a2->makeSound();

    delete a1;
    delete a2;

    std::cout << "\nAbstract class compile-time test:" << std::endl;
    std::cout << "Uncommenting the next lines must fail to compile." << std::endl;

    // Animal x;
    // const Animal* y = new Animal();

    return 0;
}