/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 06:22:24 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/15 19:42:35 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#define STD_FORMAT std::setfill(' ') << std::setw(20) << std::left

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << STD_FORMAT << "String address:" << &str << std::endl;
    std::cout << STD_FORMAT << "Pointer add: " << stringPTR << std::endl;
    std::cout << STD_FORMAT << "Reference add: " << &stringREF << std::endl;

    std::cout << std::endl;

    std::cout << STD_FORMAT << "String value:" << str << std::endl;
    std::cout << STD_FORMAT << "Pointer value:" << *stringPTR << std::endl;
    std::cout << STD_FORMAT << "Reference value:" << stringREF << std::endl;
    return (0);
}
