/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:46:22 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/12 13:46:23 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: ./RPN \"<expression>\"" << std::endl;
        return EXIT_FAILURE;
    }

    RPN rpn;
    rpn.run(av[1]);

    return EXIT_SUCCESS;
}
