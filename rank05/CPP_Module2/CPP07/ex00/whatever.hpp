/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 10:50:34 by thitoe            #+#    #+#             */
/*   Updated: 2026/07/03 11:09:00 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>
#include <cstdlib>

template <typename T>
void swap(T &a, T &b)
{
    T sw = a;
    a = b;
    b = sw;
}

template <typename T>
const T &min(const T &a, const T &b)
{
    return (a < b ? a : b);
}

template <typename T>
const T &max(const T &a, const T &b)
{
    return (a > b ? a : b);
}

#endif
