/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 08:42:24 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/24 13:05:54 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __SCAVTRAP_H__
#define __SCAVTRAP_H__

#include "ClapTrap.hpp"
#include <string>

#define YELLOW "\033[1;33m"
#define NOCOL "\033[0m"

class ScavTrap : public ClapTrap
{
public:
    ScavTrap(void);
    ScavTrap(const std::string& name);
    ScavTrap(const ScavTrap& src);
    ~ScavTrap(void);

    ScavTrap& operator=(const ScavTrap& src);

    void attack(const std::string& target) ;
    void guardGate(void) const;
};

#endif