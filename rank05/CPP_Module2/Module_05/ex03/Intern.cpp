/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:53:51 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/12 12:53:59 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern( const Intern& src ) {
    *this = src;
}

Intern::~Intern() {}

Intern& Intern::operator=( const Intern& rhs ) {
    ( void ) rhs;
    return (*this);
}

Form*   Intern::makeForm( std::string name, std::string target ) {

    std::string formNames[] = {
        "robotomy request",
        "presidential pardon",
        "shrubbery creation"
    };
    Form*    forms[] = {
        new RobotomyRequestForm( target ),
        new PresidentialPardonForm( target ),
        new ShrubberyCreationForm( target )
    };
    
    for ( int i(0); i < 3; i++ ) {
        if ( name == formNames[i] ) {
            std::cout << "Intern creates " << name << std::endl;
            return forms[i];
        }
    }
    std::cout << "Intern cannot create " << name << " form" << std::endl;
    return nullptr;
}