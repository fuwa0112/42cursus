/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 06:22:31 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/15 06:22:32 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __HUMANA_H__
#define __HUMANA_H__

#include "Weapon.hpp"
#include <iostream>

class HumanA
{

public:
    HumanA(std::string name, Weapon &weapon);
    ~HumanA(void);

    void attack(void) const;

private:
    std::string _name;
    Weapon &_weapon;
};

#endif
