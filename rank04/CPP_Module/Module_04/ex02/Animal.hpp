/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 08:44:13 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/25 12:24:08 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

#define CYAN "\033[1;36m"
#define NOCOL "\033[0m"

class Animal
{
protected:
    std::string type;

public:
    Animal();
    Animal(const std::string& t);
    Animal(const Animal& other);
    virtual ~Animal();

    Animal& operator=(const Animal& other);

    std::string getType() const;

    virtual void makeSound() const = 0;
};

#endif