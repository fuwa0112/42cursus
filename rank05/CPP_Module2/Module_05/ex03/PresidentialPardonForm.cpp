/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:54:21 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/12 12:54:22 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : Form( "PresidentialPardonForm", 25, 5 ), _target( target ) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : Form( src ), _target( src._target ) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs) {
    (void)rhs;
    return *this;
}

void    PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    if ( executor.getGrade() > this->getGradeToExecute() )
        throw Form::GradeTooLowException();
    else {
        std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    }
}