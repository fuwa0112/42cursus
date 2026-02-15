/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 23:10:21 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/15 23:10:26 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

    bool  operator>(Fixed const &rhs) const;
    bool  operator<(Fixed const &rhs) const;
    bool  operator>=(Fixed const &rhs) const;
    bool  operator<=(Fixed const &rhs) const;
    bool  operator==(Fixed const &rhs) const;
    bool  operator!=(Fixed const &rhs) const;

    Fixed operator+(Fixed const &rhs) const;
    Fixed operator-(Fixed const &rhs) const;
    Fixed operator*(Fixed const &rhs) const;
    Fixed operator/(Fixed const &rhs) const;

    Fixed &operator++(void);
    Fixed  operator++(int);
    Fixed &operator--(void);
    Fixed  operator--(int);

    static Fixed       &min(Fixed &a, Fixed &b);
    static Fixed const &min(Fixed const &a, Fixed const &b);
    static Fixed       &max(Fixed &a, Fixed &b);
    static Fixed const &max(Fixed const &a, Fixed const &b);

    float toFloat(void) const;
    int   toInt(void) const;

    int   getRawBits(void) const;
    void  setRawBits(int const raw);

private:
    int              _raw;
    static const int _fractBits;
};

std::ostream &operator<<(std::ostream &os, Fixed const &rhs);

#endif