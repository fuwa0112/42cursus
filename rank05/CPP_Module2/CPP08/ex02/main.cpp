/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 10:54:36 by thitoe            #+#    #+#             */
/*   Updated: 2026/07/03 16:56:13 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "MutantStack.hpp"

static void print_header(const std::string &title)
{
	std::cout << "\n---------------------------------------------\n";
	std::cout << title << "\n";
	std::cout << "---------------------------------------------\n";
}

int main()
{
	print_header("MutantStack basic behavior");

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Top: " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "Size after pop: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	print_header("Iteration (forward)");

	for (MutantStack<int>::iterator it = mstack.begin();
		it != mstack.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	print_header("Iteration (reverse)");

	for (MutantStack<int>::reverse_iterator rit = mstack.rbegin();
		rit != mstack.rend(); ++rit)
	{
		std::cout << *rit << " ";
	}
	std::cout << std::endl;

	print_header("Const iteration check");

	const MutantStack<int> const_stack(mstack);

	for (MutantStack<int>::const_iterator it = const_stack.begin();
		it != const_stack.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	print_header("Copy constructor test");

	MutantStack<int> copy_stack(mstack);

	for (MutantStack<int>::iterator it = copy_stack.begin();
		it != copy_stack.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	print_header("Assignment operator test");

	MutantStack<int> assigned;
	assigned = mstack;

	for (MutantStack<int>::iterator it = assigned.begin();
		it != assigned.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	print_header("std::list comparison");

	std::list<int> lst;

	lst.push_back(5);
	lst.push_back(17);

	std::cout << "Back: " << lst.back() << std::endl;

	lst.pop_back();

	std::cout << "Size after pop: " << lst.size() << std::endl;

	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::cout << "Iteration (list): ";

	for (std::list<int>::iterator it = lst.begin();
		it != lst.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	print_header("stack compatibility check");

	std::stack<int> s(mstack);

	std::cout << "Copied to std::stack, top: " << s.top() << std::endl;

	return 0;
}
