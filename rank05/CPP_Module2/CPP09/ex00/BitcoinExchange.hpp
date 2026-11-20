/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 10:55:05 by thitoe            #+#    #+#             */
/*   Updated: 2026/11/20 15:14:23 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <exception>
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <limits>
#include <locale>
#include <sstream>
#include <utility>

class BitcoinExchange
{
private:
    std::map<std::string, double> _map;

    static std::string trim(const std::string &str);
    static bool check_header(const std::string &line, char delimiter,
                             const std::string &left, const std::string &right);
    static bool check_date(const std::string &date);
    static bool parse_number(const std::string &text, double &number);

    bool get_close_rate(const std::string &date, double &rate) const;
    void calculate_value(const std::string &date,
                         const std::string &value) const;

public:
    class CanNotOpenFile : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class BadData : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &obj);
    BitcoinExchange &operator=(const BitcoinExchange &obj);
    ~BitcoinExchange();

    void process_input_file(const std::string &file_name) const;
};

#endif