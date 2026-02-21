/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 08:44:58 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/22 08:44:59 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CAT_H__
#define __CAT_H__
#define PURPLE "\033[0;35m"
#define NOCOL "\033[0m"
#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : virtual public Animal
{
public:
    Cat(void);
    Cat(Cat const &src);

    virtual ~Cat(void);

    Cat &operator=(Cat const &src);

    std::string getType(void) const;
    Brain *getBrain(void) const;

    void makeSound(void) const;

private:
    std::string type;
    Brain *brain;
};

#endif