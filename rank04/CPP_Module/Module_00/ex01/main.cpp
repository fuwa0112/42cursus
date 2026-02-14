/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:25:24 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/14 22:37:13 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <limits>
#include <iostream>

int main(void) {
	PhoneBook book;
    std::string line;
    book.start();
    while (true) {
        std::cout << "> ";
        if (!std::getline(std::cin, line))
            {
				std::cout << "\nEOF detected. PhoneBook ended." << std::endl;
				break ;
			}
        if (line == "EXIT")
            break;
        else if (line == "ADD")
            book.addContact();
        else if (line == "SEARCH") {
            book.printContacts();
            book.search();
        }
        else
            std::cout << "Invalid command." << std::endl;
    }
    return 0;
}