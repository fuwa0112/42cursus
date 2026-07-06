/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 16:04:18 by thitoe            #+#    #+#             */
/*   Updated: 2026/07/02 11:32:54 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>

ScalarConverter::ScalarConverter()
{}

ScalarConverter::~ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
    (void)obj;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
{
    (void)obj;
    return (*this);
}

namespace
{
    bool is_special(const std::string &str)
    {
        return (
            str == "nan"
            || str == "nanf"
            || str == "+inf"
            || str == "+inff"
            || str == "-inf"
            || str == "-inff"
        );
    }

    bool is_char(const std::string &str)
    {
        size_t length = str.length();

        return (
            (length == 1 && !std::isdigit(str[0]))
            || (length == 3
                && str[0] == '\''
                && str[2] == '\'')
        );
    }

    bool is_int(const std::string &str)
    {
        size_t i = 0;

        if (str.empty())
            return false;

        if (str[i] == '+' || str[i] == '-')
            i++;

        if (i >= str.length())
            return false;

        while (i < str.length())
        {
            if (!std::isdigit(str[i]))
                return false;
            i++;
        }
        return true;
    }

    bool is_float(const std::string &str)
    {
        size_t dot = str.find('.');

        if (dot == std::string::npos)
            return false;

        if (str[str.length() - 1] != 'f')
            return false;

        for (size_t i = 0; i < dot; i++)
        {
            if (!std::isdigit(str[i])
                && !(i == 0 && (str[i] == '+' || str[i] == '-')))
                return false;
        }

        for (size_t i = dot + 1; i < str.length() - 1; i++)
        {
            if (!std::isdigit(str[i]))
                return false;
        }

        return true;
    }

    bool is_double(const std::string &str)
    {
        size_t dot = str.find('.');

        if (dot == std::string::npos)
            return false;

        for (size_t i = 0; i < dot; i++)
        {
            if (!std::isdigit(str[i])
                && !(i == 0 && (str[i] == '+' || str[i] == '-')))
                return false;
        }

        for (size_t i = dot + 1; i < str.length(); i++)
        {
            if (!std::isdigit(str[i]))
                return false;
        }

        return true;
    }

    type_of which_type(const std::string &str)
    {
        if (is_special(str))
            return SPECIAL;

        if (is_char(str))
            return CHAR;

        if (is_int(str))
            return INT;

        if (is_float(str))
            return FLOAT;

        if (is_double(str))
            return DOUBLE;

        return INVALID;
    }

    void print_special(const std::string &str)
    {
        if (str == "nan" || str == "nanf")
        {
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            std::cout << "float: nanf\n";
            std::cout << "double: nan\n";
        }
        else if (str == "+inf" || str == "+inff")
        {
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            std::cout << "float: +inff\n";
            std::cout << "double: +inf\n";
        }
        else
        {
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            std::cout << "float: -inff\n";
            std::cout << "double: -inf\n";
        }
    }

    void convert_char(const std::string &str)
    {
        char c;

        if (str.length() == 1)
            c = str[0];
        else
            c = str[1];

        std::cout << "char: ";

        if (std::isprint(c))
            std::cout << "'" << c << "'\n";
        else
            std::cout << "Non displayable\n";

        std::cout << "int: " << static_cast<int>(c) << "\n";
        std::cout << "float: " << static_cast<float>(c) << ".0f\n";
        std::cout << "double: " << static_cast<double>(c) << ".0\n";
    }

    void convert_int(const std::string &str)
    {
        long num = std::atol(str.c_str());

        std::cout << "char: ";

        if (num < 0 || num > 127)
            std::cout << "impossible\n";
        else if (std::isprint(static_cast<char>(num)))
            std::cout << "'" << static_cast<char>(num) << "'\n";
        else
            std::cout << "Non displayable\n";

        std::cout << "int: ";

        if (num < std::numeric_limits<int>::min()
            || num > std::numeric_limits<int>::max())
            std::cout << "impossible\n";
        else
            std::cout << static_cast<int>(num) << "\n";

        std::cout << "float: "
                  << static_cast<float>(num)
                  << ".0f\n";

        std::cout << "double: "
                  << static_cast<double>(num)
                  << ".0\n";
    }

    void convert_float(const std::string &str)
    {
        float num = std::atof(str.c_str());

        bool integer =
            std::fabs(num - static_cast<int>(num))
            < 1e-10;

        std::cout << "char: ";

        if (num < 0 || num > 127)
            std::cout << "impossible\n";
        else if (std::isprint(static_cast<char>(num)))
            std::cout << "'" << static_cast<char>(num) << "'\n";
        else
            std::cout << "Non displayable\n";

        std::cout << "int: ";

        if (num < std::numeric_limits<int>::min()
            || num > std::numeric_limits<int>::max())
            std::cout << "impossible\n";
        else
            std::cout << static_cast<int>(num) << "\n";

        std::cout << "float: ";

        if (integer)
            std::cout << num << ".0f\n";
        else
            std::cout << num << "f\n";

        std::cout << "double: ";

        if (integer)
            std::cout << static_cast<double>(num) << ".0\n";
        else
            std::cout << static_cast<double>(num) << "\n";
    }

    void convert_double(const std::string &str)
    {
        double num = std::atof(str.c_str());

        bool integer =
            std::fabs(num - static_cast<int>(num))
            < 1e-10;

        std::cout << "char: ";

        if (num < 0 || num > 127)
            std::cout << "impossible\n";
        else if (std::isprint(static_cast<char>(num)))
            std::cout << "'" << static_cast<char>(num) << "'\n";
        else
            std::cout << "Non displayable\n";

        std::cout << "int: ";

        if (num < std::numeric_limits<int>::min()
            || num > std::numeric_limits<int>::max())
            std::cout << "impossible\n";
        else
            std::cout << static_cast<int>(num) << "\n";

        std::cout << "float: ";

        if (integer)
            std::cout << static_cast<float>(num) << ".0f\n";
        else
            std::cout << static_cast<float>(num) << "f\n";

        std::cout << "double: ";

        if (integer)
            std::cout << num << ".0\n";
        else
            std::cout << num << "\n";
    }
}

void ScalarConverter::convert(const std::string &str)
{
    switch (which_type(str))
    {
        case SPECIAL:
            print_special(str);
            break;

        case CHAR:
            convert_char(str);
            break;

        case INT:
            convert_int(str);
            break;

        case FLOAT:
            convert_float(str);
            break;

        case DOUBLE:
            convert_double(str);
            break;

        default:
            std::cout << "Invalid input" << std::endl;
    }
}
