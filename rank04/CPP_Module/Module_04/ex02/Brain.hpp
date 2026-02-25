/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 08:44:53 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/25 11:45:03 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

#define GREEN "\033[0;32m"
#define NOCOL "\033[0m"

class Brain
{
private:
    std::string ideas[100];

public:
    Brain();
    Brain(const Brain& other);
    ~Brain();

    Brain& operator=(const Brain& other);

    void setIdea(int idx, const std::string& idea);
    std::string getIdea(int idx) const;
};

#endif