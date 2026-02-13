/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:44:06 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/12 13:44:07 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

struct Data
{
    std::string name;
    int         age;
};

uintptr_t    serialize( Data *data ) {
    return ( reinterpret_cast< uintptr_t >( data ) );
}

Data*   deserialize( uintptr_t data ) {
    return ( reinterpret_cast< Data* >( data ) );
}

int main( void )
{
    Data *data = new Data;

    data->name = "achraf";
    data->age = 30;

    std::cout << "Name: " << deserialize( serialize( data ) )->name << std::endl;
    std::cout << "Age: " << deserialize( serialize( data ) )->age << std::endl;

    delete data;

    return EXIT_SUCCESS;
}