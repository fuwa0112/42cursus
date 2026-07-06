/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 10:54:00 by thitoe            #+#    #+#             */
/*   Updated: 2026/07/03 16:00:40 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::cout << "---------------------------------------------\n";
	std::cout << "Test list container\n";
	std::list<int> _list;
	for (int i = 0; i <= 20; i++)
		_list.push_front(i);
	try
	{
		std::cout << *easyfind(_list, 15) << std::endl;
		std::cout << *easyfind(_list, 1000) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "---------------------------------------------\n";
	std::cout << "Test vector container\n";
	std::vector<int> _vector;
	for (int i = 1; i <= 10; i++)
		_vector.push_back(i);
	try
	{
		std::cout << *easyfind(_vector, 5) << std::endl;
		std::cout << *easyfind(_vector, 20) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "---------------------------------------------\n";
	std::cout << "Test deque container\n";
	std::deque<int> _deque;
	for (int i = 0; i <= 500; i++)
		_deque.push_back(i);
	try
	{
		std::cout << *easyfind(_deque, 349) << std::endl;
		std::cout << *easyfind(_deque, 501) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	return (0);
}
