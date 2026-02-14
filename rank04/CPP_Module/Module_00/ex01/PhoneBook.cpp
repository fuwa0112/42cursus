/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:25:35 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/14 22:25:36 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void    PhoneBook::start(void) const {
    std::cout << " thitoe Phonebook "<< std::endl;
    std::cout << "--------------USAGE---------------" << std::endl;
    std::cout << "ADD\t: To add a contact." << std::endl;
    std::cout << "SEARCH\t: To search for a contact." << std::endl;
    std::cout << "EXIT\t: to quite the PhoneBook." << std::endl;
    std::cout << "----------------------------------" << std::endl;
}

void    PhoneBook::addContact(void) {
    static int  i;
    this->_contacts[i % 8].init();
    this->_contacts[i % 8].setIndex(i % 8);
    i++;
}

void    PhoneBook::printContacts(void) const {
    std::cout << "------------- PHONBOOK CONTACTS -------------" << std::endl;
    for (size_t i = 0; i < 8; i++) {
        this->_contacts[i].view(i);
    }
    std::cout << std::endl;
}

static bool isBlankLine(const std::string& s) {
    for (size_t i = 0; i < s.size(); ++i) {
        unsigned char c = static_cast<unsigned char>(s[i]);
        if (!std::isspace(c))
            return false;
    }
    return true;
}

int PhoneBook::_readInput() const {
    std::string line;

    while (true) {
        std::cout << "Please enter the contact index: " << std::flush;
        if (!std::getline(std::cin, line)) {
            std::cout << "\nEOF detected. Search canceled.\n";
            return -1;
        }
        if (line.empty() || isBlankLine(line)) {
            std::cout << "Invalid index; please re-enter.\n";
            continue;
        }
        std::istringstream iss(line);
        int input;
        char extra;
        if (!(iss >> input) || (iss >> extra)) {
            std::cout << "Invalid index; please re-enter.\n";
            continue;
        }
        if (input < 0 || input > 7) {
            std::cout << "Invalid index; please re-enter.\n";
            continue;
        }
        return input;
    }
}

void PhoneBook::search(void) const {
    int i = this->_readInput();
    if (i < 0) {
        std::cout << "Search aborted.\n";
        return;
    }
    this->_contacts[i].display(i);
    std::cout << "Search completed.\n";
    std::cout << "----------------------------------" << std::endl;
}