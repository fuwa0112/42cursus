/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 23:10:57 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/15 23:14:42 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>

const int Fixed::_fractBits = 8;

Fixed::Fixed(void) : _raw(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const n) : _raw(n << _fractBits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const f)
{
    // std::cout << "Float constructor called" << std::endl;
    _raw = static_cast<int>(roundf(f * static_cast<float>(1 << _fractBits)));
}

Fixed::Fixed(Fixed const &src) : _raw(src._raw)
{
    // std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
    // std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        _raw = rhs._raw;
    return *this;
}

int Fixed::getRawBits(void) const
{
    return _raw;
}

void Fixed::setRawBits(int const raw)
{
    _raw = raw;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(_raw) / static_cast<float>(1 << _fractBits);
}

int Fixed::toInt(void) const
{
    return _raw >> _fractBits;
}

bool Fixed::operator>(Fixed const &rhs) const { return _raw > rhs._raw; }
bool Fixed::operator<(Fixed const &rhs) const { return _raw < rhs._raw; }
bool Fixed::operator>=(Fixed const &rhs) const { return _raw >= rhs._raw; }
bool Fixed::operator<=(Fixed const &rhs) const { return _raw <= rhs._raw; }
bool Fixed::operator==(Fixed const &rhs) const { return _raw == rhs._raw; }
bool Fixed::operator!=(Fixed const &rhs) const { return _raw != rhs._raw; }

Fixed Fixed::operator+(Fixed const &rhs) const
{
    Fixed out;
    out._raw = _raw + rhs._raw;
    return out;
}

Fixed Fixed::operator-(Fixed const &rhs) const
{
    Fixed out;
    out._raw = _raw - rhs._raw;
    return out;
}

Fixed Fixed::operator*(Fixed const &rhs) const
{
    long a = static_cast<long>(_raw);
    long b = static_cast<long>(rhs._raw);
    long prod = (a * b) >> _fractBits;
    Fixed out;
    out._raw = static_cast<int>(prod);
    return out;
}

Fixed Fixed::operator/(Fixed const &rhs) const
{
    long a = static_cast<long>(_raw);
    long div = (a << _fractBits) / static_cast<long>(rhs._raw);
    Fixed out;
    out._raw = static_cast<int>(div);
    return out;
}

Fixed &Fixed::operator++(void)
{
    ++_raw;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    ++_raw;
    return tmp;
}

Fixed &Fixed::operator--(void)
{
    --_raw;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    --_raw;
    return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
    return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &os, Fixed const &rhs)
{
    os << rhs.toFloat();
    return os;
}
