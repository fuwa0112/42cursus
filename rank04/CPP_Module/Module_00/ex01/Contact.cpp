/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:25:08 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/14 23:04:15 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Contact.hpp"


Contact::Contact()
{
}

Contact::~Contact()
{
}

static bool isBlank(const std::string& s) {
    if (s.empty())
        return true;
    for (size_t i = 0; i < s.size(); ++i) {
        unsigned char c = static_cast<unsigned char>(s[i]);
        if (!std::isspace(c))
            return false;
    }
    return true;
}

bool Contact::_getInput(const std::string& prompt, std::string& out) const {
    while (true) {
        std::cout << prompt << std::flush;
        if (!std::getline(std::cin, out))
		{
			std::cout << "\nEOF detected. ADDED canceled.\n";
            return false;
		}
        if (!isBlank(out))
            return true;
        std::cout << "Invalid input; please try again." << std::endl;
    }
}

void Contact::init(void) {
    std::string tmp;
    if (!_getInput("Please enter your first name: ", tmp)) return;
    this->_firstName = tmp;
    if (!_getInput("Please enter your last name: ", tmp)) return;
    this->_lastName = tmp;
    if (!_getInput("Please enter your nickname: ", tmp)) return;
    this->_nickname = tmp;
    if (!_getInput("Please enter your phone number: ", tmp)) return;
    this->_phoneNumber = tmp;
    if (!_getInput("Please enter your darkest secret: ", tmp)) return;
    this->_darkestSecret = tmp;
	std::cout << "Contact added successfully.\n";
    std::cout << "----------------------------------" << std::endl;
}


std::string Contact::_printLen(const std::string str) const {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void    Contact::setIndex(int i) {
    this->_index = i;
}

void    Contact::view(int index) const {
    if (this->_firstName.empty() || this->_lastName.empty() || this->_nickname.empty())
        return ;
    std::cout << "|" << std::setw(10) << index << std::flush;
    std::cout << "|" << std::setw(10) << this->_printLen(this->_firstName) << std::flush;
    std::cout << "|" << std::setw(10) << this->_printLen(this->_lastName) << std::flush;
    std::cout << "|" << std::setw(10) << this->_printLen(this->_nickname) << std::flush;
    std::cout << "|" << std::endl;
}

void    Contact::display(int index) const {
    if (this->_firstName.empty() || this->_lastName.empty() || this->_nickname.empty())
        return ;
    std::cout << std::endl;
    std::cout << "---->> CONTACT #" << index << " <<----" << std::endl;
    std::cout << "First Name:\t" << this->_firstName << std::endl;
    std::cout << "Last Name:\t" << this->_lastName << std::endl;
    std::cout << "Nickname:\t" << this->_nickname << std::endl;
    std::cout << std::endl;
}