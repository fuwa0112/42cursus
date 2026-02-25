/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 08:44:21 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/24 17:00:39 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

#define PURPLE "\033[0;35m"
#define NOCOL "\033[0m"

class Cat : public Animal
{
public:
    Cat();
    Cat(const Cat& other);
    virtual ~Cat();

    Cat& operator=(const Cat& other);

    virtual void makeSound() const;
};

#endif