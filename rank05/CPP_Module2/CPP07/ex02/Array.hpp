/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 10:53:44 by thitoe            #+#    #+#             */
/*   Updated: 2026/07/03 11:33:41 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <cstdlib>

template <typename T>
class Array
{
    private:
        T* array;
        unsigned int length;
    public:
        Array()
        {
            array = new T[0];
            length = 0;
        }
        Array(unsigned int n)
        {
            this->array = new T[n];
            this->length = n;
        }
        Array(const Array &obj)
        {
            this->array = new T[obj.length];
            this->length = obj.length;
            for (unsigned int i = 0; i < obj.length; i++)
                this->array[i] = obj.array[i];
        }
        Array &operator=(const Array &obj)
        {
            if (this != &obj)
            {
                delete []this->array;
                length = obj.length;
                array = new T[length];
                for (unsigned int i = 0; i < length; i++)
                    array[i] = obj.array[i];
            }
            return (*this);
        }
        ~Array()
        {
            delete []array;
        }
        unsigned int size() const
        {
            return (length);
        }
        T &operator[](unsigned int index)
        {
            if (index >= length)
                throw std::out_of_range("Index Out Of Range");
            return (array[index]);
        }
        const T& operator[](unsigned int index) const
        {
            if (index >= length)
                throw std::out_of_range("Index Out Of Range");
            return (array[index]);
        }
};

#endif
