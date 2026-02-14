/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:25:15 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/14 22:30:13 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact
{
private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;
    int         _index;

    std::string _printLen(const std::string str) const;
	bool _getInput(const std::string& prompt, std::string& out) const;

public:
    Contact();
    ~Contact();
    void    init(void);
    void    view(int index) const;
    void    display(int index) const;
    void    setIndex(int i);
};

#endif