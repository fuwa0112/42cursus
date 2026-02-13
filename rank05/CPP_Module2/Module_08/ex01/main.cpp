/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:45:31 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/12 13:45:31 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main( void )
{
    std::cout << "---- TEST #1 -----" << std::endl;

    Span sp = Span( 5 );

    sp.addNumber( 6 );
    sp.addNumber( 3 );
    sp.addNumber( 9 );
    sp.addNumber( 17 );
    sp.addNumber( 11 );

    std::cout << "sp: " << sp << std::endl;

    std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
    std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;

    std::cout << "\n---- TEST #1 -----" << std::endl;

    try {
        std::list<int>    l( 10000 );
        std::srand( time ( NULL ) );
        std::generate( l.begin(), l.end(), std::rand );

        Span span( l.size() );

        span.addNumber( l.begin(), l.end() );

        std::cout << "Longest span: " << span.longestSpan() << std::endl;
        std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
        
    } catch ( std::exception& e ) {
        std::cout << e.what() << std::endl; 
    }

    return EXIT_SUCCESS;
}