/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 06:22:34 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/15 06:22:35 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __HUMANB_H__
#define __HUMANB_H__

#include "Weapon.hpp"
#include <iostream>

class HumanB
{

public:
    HumanB(std::string name);
    HumanB(std::string name, Weapon &weapon);
    ~HumanB(void);

    void attack(void) const;
    void setWeapon(Weapon &weapon);

private:
    std::string _name;
    Weapon *_weapon;
};

#endif
