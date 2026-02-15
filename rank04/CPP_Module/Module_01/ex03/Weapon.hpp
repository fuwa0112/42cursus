/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 06:22:40 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/15 06:22:41 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __WEAPON_H__
#define __WEAPON_H__

#include <iostream>

class Weapon
{
public:
    Weapon(void);
    Weapon(std::string type);
    ~Weapon(void);

    std::string const &getType(void) const;
    void setType(std::string type);

private:
    std::string _type;
};

#endif
