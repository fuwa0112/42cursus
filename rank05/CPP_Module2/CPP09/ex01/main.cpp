/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 10:55:19 by thitoe            #+#    #+#             */
/*   Updated: 2026/07/03 10:55:20 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error: Invalid Number Of Argument\n";
        return (1);
    }
    try
    {
        RPN obj;
        obj.solution(argv[1]);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
