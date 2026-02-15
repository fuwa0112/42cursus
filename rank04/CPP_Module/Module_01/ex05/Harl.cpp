/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 06:22:54 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/15 21:51:53 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl(void)
{
    mtd_ptr debug_ptr;
	
    debug_ptr.id = "DEBUG";
    debug_ptr.func_ptr = &Harl::debug;
    this->ptr_arr[0] = debug_ptr;

    debug_ptr.id = "INFO";
    debug_ptr.func_ptr = &Harl::info;
    this->ptr_arr[1] = debug_ptr;

    debug_ptr.id = "WARNING";
    debug_ptr.func_ptr = &Harl::warning;
    this->ptr_arr[2] = debug_ptr;

    debug_ptr.id = "ERROR";
    debug_ptr.func_ptr = &Harl::error;
    this->ptr_arr[3] = debug_ptr;
}
Harl::~Harl(void)
{
}

void Harl::complain(std::string level) const
{
    for (int i = 0; i < 4; i++)
    {
        if (this->ptr_arr[i].id.compare(level) == 0)
        {
            std::cout << "[" << this->ptr_arr[i].id << "]" << std::endl;
            (this->*ptr_arr[i].func_ptr)();
            return;
        }
    }
    std::cerr << "Wrong level identifier" << std::endl;
    return;
}

void Harl::debug(void) const
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) const
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void) const
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void) const
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
