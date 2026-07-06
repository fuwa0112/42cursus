/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 10:53:40 by thitoe            #+#    #+#             */
/*   Updated: 2026/07/03 12:33:40 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

#define MAX_VAL 750

int main()
{
    std::cout << "[TEST 1] Default Constructor" << std::endl;
    Array<int> empty;

    if (empty.size() == 0)
        std::cout << "PASS : Empty array created." << std::endl;
    else
        std::cout << "FAIL : Size = " << empty.size() << std::endl;

    std::cout << std::endl;

    std::cout << "[TEST 2] Constructor(size)" << std::endl;

    Array<int> numbers(MAX_VAL);
    int *mirror = new int[MAX_VAL];

    std::cout << "Expected size : " << MAX_VAL << std::endl;
    std::cout << "Actual size   : " << numbers.size() << std::endl;

    if (numbers.size() == MAX_VAL)
        std::cout << "PASS" << std::endl;
    else
        std::cout << "FAIL" << std::endl;

    std::cout << std::endl;

    std::cout << "[TEST 3] operator[] (Read / Write)" << std::endl;

    srand(time(NULL));

    for (int i = 0; i < MAX_VAL; i++)
    {
        int value = rand();

        numbers[i] = value;
        mirror[i] = value;
    }

    bool ok = true;

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (numbers[i] != mirror[i])
        {
            ok = false;
            break;
        }
    }

    if (ok)
        std::cout << "PASS : Every value matches." << std::endl;
    else
        std::cout << "FAIL" << std::endl;

    std::cout << std::endl;

    std::cout << "[TEST 4] Copy Constructor (Deep Copy)" << std::endl;

    Array<int> copy(numbers);

    std::cout << "Original first value : " << numbers[0] << std::endl;

    copy[0] = -42;

    std::cout << "Modified copy value  : " << copy[0] << std::endl;
    std::cout << "Original value       : " << numbers[0] << std::endl;

    if (numbers[0] != copy[0])
        std::cout << "PASS : Deep Copy confirmed." << std::endl;
    else
        std::cout << "FAIL : Shallow Copy detected." << std::endl;

    std::cout << std::endl;

    std::cout << "[TEST 5] Assignment Operator (Deep Copy)" << std::endl;

    Array<int> assign(MAX_VAL);

    assign = numbers;

    assign[1] = -999;

    std::cout << "Original second value : " << numbers[1] << std::endl;
    std::cout << "Assigned second value : " << assign[1] << std::endl;

    if (numbers[1] != assign[1])
        std::cout << "PASS : Deep Copy confirmed." << std::endl;
    else
        std::cout << "FAIL : Shallow Copy detected." << std::endl;

    std::cout << std::endl;

    std::cout << "[TEST 6] Destructor Safety" << std::endl;

    {
        Array<int> tmp(numbers);
        Array<int> tmp2(tmp);
    }

    std::cout << "Temporary copies destroyed." << std::endl;
    std::cout << "Original first value : " << numbers[0] << std::endl;
    std::cout << "PASS : No crash after destructors." << std::endl;

    std::cout << std::endl;

    std::cout << "[TEST 7] Exception (-2)" << std::endl;

    try
    {
        numbers[-2] = 0;
        std::cout << "FAIL : Exception not thrown." << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "PASS : " << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "[TEST 8] Exception (index == size)" << std::endl;

    try
    {
        numbers[MAX_VAL] = 0;
        std::cout << "FAIL : Exception not thrown." << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "PASS : " << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "[TEST 9] Rewrite Whole Array" << std::endl;

    for (int i = 0; i < MAX_VAL; i++)
        numbers[i] = rand();

    std::cout << "PASS : Every element rewritten successfully." << std::endl;

    delete[] mirror;

    return (0);
}