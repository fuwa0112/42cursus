/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:54:01 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/12 12:54:03 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"

class Intern {

public:
    Intern();
    Intern( const Intern& src );
    ~Intern();

    Intern& operator=( const Intern& rhs );

    Form*   makeForm( std::string name, std::string target );
};

#endif // INTERN_HPP