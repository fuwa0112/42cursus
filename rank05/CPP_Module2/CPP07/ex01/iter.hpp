/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 10:51:13 by thitoe            #+#    #+#             */
/*   Updated: 2026/07/03 11:23:45 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>
#include <cstdlib>

template <typename T>
void iter(T *array, int length, void (*function)(T &))
{
    if (!array || !function)
        return;

    for (int i = 0; i < length; i++)
        function(array[i]);
}

template <typename T>
void iter(const T *array, int length, void (*function)(const T &))
{
    if (!array || !function)
        return;

    for (int i = 0; i < length; i++)
        function(array[i]);
}

#endif
