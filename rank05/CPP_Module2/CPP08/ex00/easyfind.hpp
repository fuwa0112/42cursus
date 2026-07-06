/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 10:53:56 by thitoe            #+#    #+#             */
/*   Updated: 2026/07/03 10:53:57 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
#include <list>
#include <vector>

class NumberDoesNotFound : public std::exception
{
    public:
        const char *what() const throw()
        {
            return ("The Number Does Not Inside The Containter !!!");
        }
};

template <typename T>
typename T::iterator easyfind(T &container, int num)
{
    typename T::iterator it = std::find(container.begin(), container.end(), num);
    if (it == container.end())
        throw NumberDoesNotFound();
    return (it);
}

#endif
