/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 10:54:16 by thitoe            #+#    #+#             */
/*   Updated: 2026/07/03 16:00:35 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	std::cout << "---------------------------------------------\n";
	std::cout << "Test vector container\n";

	Span span = Span(5);
	span.addNumber(6);
	span.addNumber(2);
	span.addNumber(21);
	span.addNumber(9);
	span.addNumber(10);

	try
	{
		span.addNumber(11);
	}
	catch (const std::exception &e)
	{
		std::cout << "[overflow test] " << e.what() << std::endl;
	}

	std::cout << "---------------------\n";

	try
	{
		std::cout << "shortest_span: " << span.shortest_span() << std::endl;
		std::cout << "longest_span: " << span.longest_span() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "---------------------\n";

	std::cout << "Edge case: single element\n";
	Span sp1(10);
	sp1.addNumber(42);
	try
	{
		std::cout << sp1.shortest_span() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "[expected error] " << e.what() << std::endl;
	}

	std::cout << "---------------------\n";

	std::cout << "Edge case: same values\n";
	Span sp_same(5);
	sp_same.addNumber(7);
	sp_same.addNumber(7);
	sp_same.addNumber(7);
	try
	{
		std::cout << "shortest_span: " << sp_same.shortest_span() << std::endl;
		std::cout << "longest_span: " << sp_same.longest_span() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "---------------------\n";

	std::cout << "Test vector range\n";

	Span sp2 = Span(100);
	std::vector<int> v;

	std::srand(time(NULL));
	for (int i = 0; i < 100; i++)
		v.push_back(rand() % 1000000);

	try
	{
		sp2.addNumber(v.begin(), v.end());
		std::cout << "shortest_span: " << sp2.shortest_span() << std::endl;
		std::cout << "longest_span: " << sp2.longest_span() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "---------------------\n";

	std::cout << "Edge case: partial overflow range insert\n";

	Span sp4(5);
	std::vector<int> big;
	for (int i = 0; i < 10; i++)
		big.push_back(i);

	try
	{
		sp4.addNumber(big.begin(), big.end());
	}
	catch (const std::exception &e)
	{
		std::cout << "[expected overflow] " << e.what() << std::endl;
	}

	std::cout << "---------------------\n";

	std::cout << "Test vector large range\n";

	Span sp3 = Span(100000);
	std::vector<int> v2;

	std::srand(time(NULL));
	for (int i = 0; i < 100000; i++)
		v2.push_back(rand() % 1000000000);

	try
	{
		sp3.addNumber(v2.begin(), v2.end());
		std::cout << "shortest span: " << sp3.shortest_span() << std::endl;
		std::cout << "longest span: " << sp3.longest_span() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "---------------------------------------------" << std::endl;
	return 0;
}
