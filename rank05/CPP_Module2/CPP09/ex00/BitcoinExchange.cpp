/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 10:55:02 by thitoe            #+#    #+#             */
/*   Updated: 2026/11/20 15:14:17 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

const char *BitcoinExchange::CanNotOpenFile::what() const throw()
{
    return "Error: could not open file";
}

const char *BitcoinExchange::BadData::what() const throw()
{
    return "Error: file is bad data";
}

std::string BitcoinExchange::trim(const std::string &str)
{
    const std::string::size_type first = str.find_first_not_of(" \t\r");
    if (first == std::string::npos)
        return "";
    const std::string::size_type last = str.find_last_not_of(" \t\r");
    return str.substr(first, last - first + 1);
}

bool BitcoinExchange::check_header(const std::string &line, char delimiter,
                                   const std::string &left,
                                   const std::string &right)
{
    const std::string::size_type pos = line.find(delimiter);
    if (pos == std::string::npos)
        return false;
    return trim(line.substr(0, pos)) == left
        && trim(line.substr(pos + 1)) == right;
}

bool BitcoinExchange::check_date(const std::string &date)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    for (std::size_t i = 0; i < date.size(); ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (date[i] < '0' || date[i] > '9')
            return false;
    }

    const int year = (date[0] - '0') * 1000 + (date[1] - '0') * 100
                   + (date[2] - '0') * 10 + (date[3] - '0');
    const int month = (date[5] - '0') * 10 + (date[6] - '0');
    const int day = (date[8] - '0') * 10 + (date[9] - '0');

    if (year == 0 || month < 1 || month > 12)
        return false;

    static const int days_in_month[12] =
        {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int last_day = days_in_month[month - 1];
    if (month == 2 && (year % 400 == 0 ||
        (year % 4 == 0 && year % 100 != 0)))
        last_day = 29;

    return day >= 1 && day <= last_day;
}

bool BitcoinExchange::parse_number(const std::string &text, double &number)
{
    if (text.empty())
        return false;

    std::istringstream stream(text);
    stream.imbue(std::locale::classic());
    stream >> std::noskipws >> number;

    if (stream.fail() || !stream.eof())
        return false;

    const double max = std::numeric_limits<double>::max();
    return number == number && number <= max && number >= -max;
}

BitcoinExchange::BitcoinExchange()
{
    std::ifstream file("data.csv");
    if (!file.is_open())
        throw CanNotOpenFile();

    std::string line;
    if (!std::getline(file, line)
        || !check_header(line, ',', "date", "exchange_rate"))
        throw BadData();

    while (std::getline(file, line))
    {
        const std::string::size_type pos = line.find(',');
        if (pos == std::string::npos || line.find(',', pos + 1) != std::string::npos)
            throw BadData();

        const std::string date = trim(line.substr(0, pos));
        const std::string rate_text = trim(line.substr(pos + 1));
        double rate;

        if (!check_date(date) || !parse_number(rate_text, rate) || rate < 0)
            throw BadData();

        if (!_map.insert(std::make_pair(date, rate)).second)
            throw BadData();
    }

    if (!file.eof() || _map.empty())
        throw BadData();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
    : _map(obj._map)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj)
{
    if (this != &obj)
        _map = obj._map;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

bool BitcoinExchange::get_close_rate(const std::string &date,
                                     double &rate) const
{
    std::map<std::string, double>::const_iterator it = _map.lower_bound(date);

    if (it == _map.begin())
    {
        if (it == _map.end() || it->first != date)
            return false;
    }
    else if (it == _map.end() || it->first != date)
        --it;

    rate = it->second;
    return true;
}

void BitcoinExchange::calculate_value(const std::string &date,
                                      const std::string &value) const
{
    if (!check_date(date))
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return;
    }

    double amount;
    if (!parse_number(value, amount))
    {
        std::cerr << "Error: bad input => " << date
                  << " | " << value << std::endl;
        return;
    }
    if (amount < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return;
    }
    if (amount > 1000)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return;
    }

    double rate;
    if (!get_close_rate(date, rate))
    {
        std::cerr << "Error: no rate available => " << date << std::endl;
        return;
    }

    std::cout << date << " => " << value << " = "
              << rate * amount << std::endl;
}

void BitcoinExchange::process_input_file(const std::string &file_name) const
{
    std::ifstream file(file_name.c_str());
    if (!file.is_open())
        throw CanNotOpenFile();

    std::string line;
    if (!std::getline(file, line)
        || !check_header(line, '|', "date", "value"))
        throw BadData();

    while (std::getline(file, line))
    {
        const std::string::size_type pos = line.find('|');
        if (pos == std::string::npos || line.find('|', pos + 1) != std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        const std::string date = trim(line.substr(0, pos));
        const std::string value = trim(line.substr(pos + 1));
        calculate_value(date, value);
    }

    if (!file.eof())
        throw BadData();
}
