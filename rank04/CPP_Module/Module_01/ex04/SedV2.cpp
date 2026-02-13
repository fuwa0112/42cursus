/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedV2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:29:17 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/12 12:29:18 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedV2.hpp"

SedV2::SedV2(std::string filename) : _inFile(filename){
    this->_outFile = this->_inFile + ".replace";
}

SedV2::~SedV2 ( void ) {

}

void            SedV2::replace( std::string toFind, std::string replace) {
    std::ifstream   ifs(this->_inFile);
    if (ifs.is_open()) {
        std::string content;
        if (std::getline(ifs, content, '\0')) {
            std::ofstream   ofs(this->_outFile);
            size_t          pos = content.find(toFind);
            while ( pos != std::string::npos ) {
                content.erase(pos, toFind.length());
                content.insert(pos, replace);
                pos = content.find(toFind);
            }
            ofs << content;
            ofs.close();
        }
        else {
            std::cerr << "Empty file found." << std::endl;
        }
        ifs.close();
    } else {
        std::cerr << "Unable to open the file." << std::endl;
        exit(EXIT_FAILURE);
    }
}
