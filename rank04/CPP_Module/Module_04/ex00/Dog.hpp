/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 08:44:27 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/24 16:54:28 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

#define BLUE "\033[1;34m"
#define NOCOL "\033[0m"

class Dog : public Animal
{
public:
    Dog();
    Dog(const Dog& other);
    virtual ~Dog();

    Dog& operator=(const Dog& other);

    virtual void makeSound() const;
};

#endif