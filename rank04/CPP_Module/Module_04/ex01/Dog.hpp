/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 08:45:01 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/22 08:45:02 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __DOG_H__
#define __DOG_H__
#define BLUE "\033[1;34m"
#define NOCOL "\033[0m"
#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : virtual public Animal
{
public:
    Dog(void);
    Dog(Dog const &src);

    virtual ~Dog(void);

    Dog &operator=(Dog const &src);

    std::string getType(void) const;
    Brain *getBrain(void) const;

    void makeSound(void) const;

private:
    std::string type;
    Brain *brain;
};

#endif