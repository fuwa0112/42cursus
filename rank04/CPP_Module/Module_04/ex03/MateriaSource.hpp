/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:39:18 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/12 12:39:19 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria*       materias[4];

    public:
        MateriaSource();
        ~MateriaSource();

        MateriaSource( MateriaSource const & );
        MateriaSource&  operator=( MateriaSource const & );

        AMateria*       getMateria( std::string const & type );
        AMateria*       createMateria( std::string const & type );
        void            learnMateria( AMateria* );
};


#endif // MATERIASOURCE_HPP