/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 10:55:09 by thitoe            #+#    #+#             */
/*   Updated: 2026/07/08 15:31:27 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
    	if (argc == 1)
        	std::cerr << "Error: could not open file." << std::endl;
    	else
        	std::cerr << "Error: Invalid Argument." << std::endl;
    	return (1);
	}
    try
    {
        BitcoinExchange exchange;
        exchange.process_input_file(argv[1]);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}
