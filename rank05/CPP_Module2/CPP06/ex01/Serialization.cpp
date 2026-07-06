/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 16:05:06 by thitoe            #+#    #+#             */
/*   Updated: 2026/07/01 16:05:07 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

Serialization::Serialization()
{}

Serialization::~Serialization()
{}

Serialization::Serialization(const Serialization &obj)
{
    *this = obj;
}

Serialization &Serialization::operator=(const Serialization &obj)
{
    if (this != &obj)
        *this = obj;
    return (*this);
}

uintptr_t Serialization::serialize(Data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serialization::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}
