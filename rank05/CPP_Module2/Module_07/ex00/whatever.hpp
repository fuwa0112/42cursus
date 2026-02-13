/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:44:41 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/12 13:44:41 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template< typename T >
void    swap( T& a, T& b ) {
    T tmp = a;
    a = b;
    b = tmp;
}

template< typename T >
T       min( T& a, T& b ) {
    return ( a < b ? a : b );
}

template< typename T >
T       max( T& a, T& b ) {
    return ( a > b ? a : b );
}