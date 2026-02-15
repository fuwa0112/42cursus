/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 06:22:46 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/15 21:28:52 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

static bool readWholeFile(const std::string &filename, std::string &out)
{
    std::ifstream in(filename.c_str(), std::ios::in | std::ios::binary);
    if (!in)
        return false;

    std::string content;
    char ch;
    while (in.get(ch))
        content += ch;

    out = content;
    return true;
}
static void replaceAll(std::string &text, const std::string &s1, const std::string &s2)
{
    std::string result;
    size_t pos = 0;
    size_t found = 0;

    while ((found = text.find(s1, pos)) != std::string::npos)
    {
        result.append(text, pos, found - pos);
        result += s2;
        pos = found + s1.size();
    }
    result.append(text, pos, std::string::npos);
    text = result;
}

static int doReplace(const std::string &sourceFileName,
                     const std::string &toBeReplaced,
                     const std::string &toReplaceWith)
{
    std::string content;
    if (!readWholeFile(sourceFileName, content))
    {
        std::cerr << "Error: Unable to open source file" << std::endl;
        return 1;
    }
	if (toBeReplaced.empty())
    {
        std::cerr << "Error: s1 must not be empty" << std::endl;
        return 1;
    }
    replaceAll(content, toBeReplaced, toReplaceWith);

    const std::string outName = sourceFileName + ".replace";
    std::ofstream out(outName.c_str(), std::ios::out | std::ios::binary);
    if (!out)
    {
        std::cerr << "Error: Unable to open target file" << std::endl;
        return 1;
    }

    out << content;
    if (!out)
    {
        std::cerr << "Error: Failed while writing target file" << std::endl;
        return 1;
    }

    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cerr << "Error: usage: ./sed <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    return doReplace(argv[1], argv[2], argv[3]);
}
