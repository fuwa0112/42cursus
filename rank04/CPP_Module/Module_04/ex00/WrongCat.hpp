/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 08:44:38 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/22 08:44:39 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __WRONGCAT_H__
#define __WRONGCAT_H__
#define YELLOW "\033[0;33m"
#define NOCOL "\033[0m"
#include <iostream>

#include "WrongAnimal.hpp"

class WrongCat : virtual public WrongAnimal
{
public:
    WrongCat(void);
    WrongCat(WrongCat const &src);

    ~WrongCat(void);

    WrongCat &operator=(WrongCat const &src);

    std::string getType(void) const;
    void makeSound(void) const;

private:
    std::string type;
};

#endif