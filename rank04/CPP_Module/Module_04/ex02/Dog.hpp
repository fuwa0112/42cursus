/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:35:58 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/12 12:35:59 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"

class Dog : public AAnimal
{
private:
    Brain   *_brain;

public:
    Dog( void );
    ~Dog( void );

    Dog( const Dog& src );
    Dog& operator=( const Dog& src );

    void   makeSound( void ) const;
};

#endif // DOG_HPP