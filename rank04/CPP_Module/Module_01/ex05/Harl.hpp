/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 06:22:56 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/15 06:22:57 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __Harl_H__
#define __Harl_H__

#include <iostream>

class Harl;

typedef struct MethodPointer
{
    std::string id;
    void (Harl::*func_ptr)(void) const;
} mtd_ptr;
class Harl
{

public:
    Harl(void);
    ~Harl(void);

    void complain(std::string level) const;

private:
    mtd_ptr ptr_arr[4];

    void debug(void) const;
    void info(void) const;
    void warning(void) const;
    void error(void) const;
};

#endif
