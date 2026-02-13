/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:49:57 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/12 12:49:59 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( const std::string& name, int grade ) : _name(name), _grade(grade) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat( const Bureaucrat& src ) : _name(src._name), _grade(src._grade) {
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& rhs ) {
    if ( this != &rhs )
        _grade = rhs.getGrade();
    return *this;
}

std::string Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void    Bureaucrat::incrementGrade() {
    if ( _grade - 1 < 1 )
        throw Bureaucrat::GradeTooHighException();
    _grade--;
}

void    Bureaucrat::decrementGrade() {
    if ( _grade + 1 > 150 )
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}

std::ostream& operator<<( std::ostream& o, const Bureaucrat& rhs ) {
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
    return o;
}