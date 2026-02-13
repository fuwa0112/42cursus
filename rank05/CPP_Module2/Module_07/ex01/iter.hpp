/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:44:47 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/12 13:44:48 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template < typename T >
void    iter( T *arr, size_t size, void (*f)(T &) )
{
    for ( size_t i = 0; i < size; i++ )
        f( arr[i] );
}

template < typename T >
void    print( T &i )
{
    std::cout << i << std::endl;
}