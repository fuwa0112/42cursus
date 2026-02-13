/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:46:16 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/12 13:46:17 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{

	if (ac != 2)
	{
		std::cout << "Error: could not open file" << std::endl;
		return (EXIT_FAILURE);
	}

	BitcoinExchange exchange;

	exchange.run(av[1]);

	return (EXIT_SUCCESS);
}