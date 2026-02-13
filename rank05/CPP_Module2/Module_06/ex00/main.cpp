/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:55:53 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/12 12:55:53 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

int main( int ac, char ** av )
{
    if ( ac != 2 ) {
        std::cout << "Usage: ./convert number" << std::endl;
        return EXIT_FAILURE;
    }

    Converter c;

    try
    {
        c.setStr( av[1] );
        c.convert();

        std::cout << c;
    }
    catch( const std::exception& e ) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    

    return EXIT_SUCCESS;
}