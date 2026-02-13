/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:44:50 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/12 13:44:52 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

#define N 5

int main( void )
{
    int arr1[] = { 1, 2, 3, 4, 5 };

    std::cout << "arr1: " << std::endl;
    iter(arr1, N, &print);

    double arr2[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };

    std::cout << "\narr2: " << std::endl;
    iter(arr2, N, &print);

    char arr3[] = { 'a', 'b', 'c', 'd', 'e' };

    std::cout << "\narr3: " << std::endl;
    iter(arr3, N, &print);

    std::string arr4[] = { "one", "two", "three", "four", "five" };

    std::cout << "\narr4: " << std::endl;
    iter(arr4, N, &print);

    return 0;
}

/* ************************************************************************** */

// class Awsome{

// public:
//     Awsome(void): _n(42) {return;}
//     int get(void)const {return this->_n;}
// private:
//     int _n;
// };

// std::ostream &operator<<(std::ostream &o, Awsome const &rhs) {o<<rhs.get(); return o;}

// template <typename T>
// void print(T const &x){std::cout << x << std::endl; return;}

// int main(){
//     int tab[] = {0,1,2,3,4};
//     Awsome tab2[5];

//     iter(tab, 5, print);
//     iter(tab2, 5, print);
// }