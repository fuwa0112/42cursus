/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 10:55:52 by thitoe            #+#    #+#             */
/*   Updated: 2026/11/20 20:54:43 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstddef>
#include <deque>
#include <exception>
#include <string>
#include <vector>
#include <climits>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <sys/time.h>

class PmergeMe
{
private:
    struct Item
    {
        int value;
        std::size_t id;

        Item();
        Item(int number, std::size_t identifier);
    };

    struct Pending
    {
        Item small;
        std::size_t partner_id;
        bool has_partner;

        Pending();
        Pending(const Item &item, std::size_t id, bool paired);
    };

    std::vector<Item> _vector;
    std::deque<Item> _deque;
    std::vector<int> _original;
    double _vector_time;
    double _deque_time;

    static int parse_number(const std::string &text);
    static double now_microseconds();

    static void binary_insert_vector(std::vector<Item> &chain,
        const Item &item, std::size_t limit);
    static void binary_insert_deque(std::deque<Item> &chain,
        const Item &item, std::size_t limit);

    static void insert_pending_vector(std::vector<Item> &chain,
        const std::vector<Pending> &pending, std::size_t index);
    static void insert_pending_deque(std::deque<Item> &chain,
        const std::deque<Pending> &pending, std::size_t index);

    static void ford_johnson_vector(std::vector<Item> &arr,
        std::size_t original_count);
    static void ford_johnson_deque(std::deque<Item> &arr,
        std::size_t original_count);

    void print_before() const;
    void print_after() const;
    void print_time(const std::string &container, double microseconds) const;

public:
    class InvalidInput : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    void sort(int argc, char **argv);
};

#endif
