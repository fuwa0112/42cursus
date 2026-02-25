/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 08:42:40 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/24 13:24:10 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __FRAGTRAP_H__
#define __FRAGTRAP_H__

#include "ClapTrap.hpp"
#include <string>

#define MAGENTA "\033[1;35m"

class FragTrap : public ClapTrap
{
public:
    FragTrap(void);
    FragTrap(const std::string& name);
    FragTrap(const FragTrap& src);
    ~FragTrap(void);

    FragTrap& operator=(const FragTrap& src);

    void attack(const std::string& target);
    void highFivesGuys(void) const;
};

#endif