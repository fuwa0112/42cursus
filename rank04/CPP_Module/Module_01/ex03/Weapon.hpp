/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:28:56 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/12 12:28:57 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
private:
    std::string type;

public:
    Weapon( std::string type );
    ~Weapon();

    const std::string&  getType( void );
    void                setType( std::string newType );
};

#endif // WEAPON_HPP
