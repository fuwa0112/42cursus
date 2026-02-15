/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 23:01:13 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/15 23:01:14 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iosfwd>

class Fixed
{
public:
    Fixed(void);
    Fixed(int const n);
    Fixed(float const f);
    Fixed(Fixed const &src);
    ~Fixed(void);

    Fixed &operator=(Fixed const &rhs);

    int   getRawBits(void) const;
    void  setRawBits(int const raw);

    float toFloat(void) const;
    int   toInt(void) const;

private:
    int              _fixedPointValue;
    static const int _numFractBits;
};

std::ostream &operator<<(std::ostream &os, Fixed const &rhs);

#endif