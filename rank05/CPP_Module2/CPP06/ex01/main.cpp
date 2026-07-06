/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 16:04:47 by thitoe            #+#    #+#             */
/*   Updated: 2026/07/02 11:37:06 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

int main()
{
    Data my_data;
    my_data.age = 20;
    my_data.name = "salam";
    std::cout << "original data address : " << &my_data << std::endl;
    uintptr_t raw = Serialization::serialize(&my_data);
    std::cout << "Serialization value : " << raw << std::endl;
    Data *new_ptr = Serialization::deserialize(raw);
    std::cout << "Serialization Data process : " << new_ptr << std::endl;
    if (new_ptr == &my_data)
        std::cout << "Pointers are equal.\n";
    else
        std::cout << "Pointers are not equal.\n";
    std::cout << "Deserialize Data : age = " << new_ptr->age << ", name = " << new_ptr->name << std::endl;
    return (0);
}
