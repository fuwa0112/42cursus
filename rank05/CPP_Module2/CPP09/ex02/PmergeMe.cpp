/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 10:55:49 by thitoe            #+#    #+#             */
/*   Updated: 2026/11/20 20:53:58 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <climits>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <sys/time.h>

PmergeMe::Item::Item() : value(0), id(0) {}
PmergeMe::Item::Item(int number, std::size_t identifier)
    : value(number), id(identifier) {}

PmergeMe::Pending::Pending() : small(), partner_id(0), has_partner(false) {}
PmergeMe::Pending::Pending(const Item &item, std::size_t id, bool paired)
    : small(item), partner_id(id), has_partner(paired) {}

PmergeMe::PmergeMe() : _vector_time(0), _deque_time(0) {}

PmergeMe::PmergeMe(const PmergeMe &other)
    : _vector(other._vector), _deque(other._deque),
      _original(other._original), _vector_time(other._vector_time),
      _deque_time(other._deque_time) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _vector = other._vector;
        _deque = other._deque;
        _original = other._original;
        _vector_time = other._vector_time;
        _deque_time = other._deque_time;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

const char *PmergeMe::InvalidInput::what() const throw()
{
    return "Error";
}

// Accept decimal digits only. Reject 0 and values above INT_MAX.
int PmergeMe::parse_number(const std::string &text)
{
    if (text.empty())
        throw InvalidInput();

    unsigned long number = 0;
    for (std::size_t i = 0; i < text.size(); ++i)
    {
        if (text[i] < '0' || text[i] > '9')
            throw InvalidInput();
        const unsigned int digit = static_cast<unsigned int>(text[i] - '0');
        if (number > (static_cast<unsigned long>(INT_MAX) - digit) / 10)
            throw InvalidInput();
        number = number * 10 + digit;
    }
    if (number == 0)
        throw InvalidInput();
    return static_cast<int>(number);
}

// Wall-clock microseconds, available in C++98 on Linux and macOS.
double PmergeMe::now_microseconds()
{
    struct timeval tv;
    if (gettimeofday(&tv, NULL) != 0)
        throw std::runtime_error("Error: could not read clock");
    return static_cast<double>(tv.tv_sec) * 1000000.0 + tv.tv_usec;
}

// Binary-search only the prefix before the corresponding larger element.
void PmergeMe::binary_insert_vector(std::vector<Item> &chain,
    const Item &item, std::size_t limit)
{
    std::size_t left = 0;
    std::size_t right = limit;
    while (left < right)
    {
        const std::size_t mid = left + (right - left) / 2;
        if (chain[mid].value < item.value)
            left = mid + 1;
        else
            right = mid;
    }
    chain.insert(chain.begin() + left, item);
}

void PmergeMe::binary_insert_deque(std::deque<Item> &chain,
    const Item &item, std::size_t limit)
{
    std::size_t left = 0;
    std::size_t right = limit;
    while (left < right)
    {
        const std::size_t mid = left + (right - left) / 2;
        if (chain[mid].value < item.value)
            left = mid + 1;
        else
            right = mid;
    }
    chain.insert(chain.begin() + left, item);
}

void PmergeMe::insert_pending_vector(std::vector<Item> &chain,
    const std::vector<Pending> &pending, std::size_t index)
{
    std::size_t limit = chain.size();
    if (pending[index].has_partner)
    {
        limit = 0;
        while (limit < chain.size()
            && chain[limit].id != pending[index].partner_id)
            ++limit;
        if (limit == chain.size())
            throw std::runtime_error("Error: missing pair partner");
    }
    binary_insert_vector(chain, pending[index].small, limit);
}

void PmergeMe::insert_pending_deque(std::deque<Item> &chain,
    const std::deque<Pending> &pending, std::size_t index)
{
    std::size_t limit = chain.size();
    if (pending[index].has_partner)
    {
        limit = 0;
        while (limit < chain.size()
            && chain[limit].id != pending[index].partner_id)
            ++limit;
        if (limit == chain.size())
            throw std::runtime_error("Error: missing pair partner");
    }
    binary_insert_deque(chain, pending[index].small, limit);
}

// Ford-Johnson merge-insertion sort on std::vector.
void PmergeMe::ford_johnson_vector(std::vector<Item> &arr,
    std::size_t original_count)
{
    if (arr.size() <= 1)
        return;

    std::vector<Item> winners;
    std::vector<Item> small_by_winner_id(original_count);
    const bool has_stray = (arr.size() % 2 != 0);
    Item stray;
    if (has_stray)
        stray = arr.back();

    for (std::size_t i = 0; i + 1 < arr.size(); i += 2)
    {
        Item big = arr[i];
        Item small = arr[i + 1];
        if (big.value < small.value)
        {
            Item temp = big;
            big = small;
            small = temp;
        }
        winners.push_back(big);
        small_by_winner_id[big.id] = small;
    }

    // Sort winners recursively without losing their original IDs.
    ford_johnson_vector(winners, original_count);

    // Main chain: b1, a1, a2, ... ; pending: b1, b2, ...
    std::vector<Item> chain;
    std::vector<Pending> pending;
    for (std::size_t i = 0; i < winners.size(); ++i)
    {
        const Item &big = winners[i];
        pending.push_back(Pending(small_by_winner_id[big.id], big.id, true));
        if (i == 0)
            chain.push_back(pending[0].small);
        chain.push_back(big);
    }
    if (has_stray)
        pending.push_back(Pending(stray, 0, false));

    // Jacobsthal insertion order (one-based): 3,2,5,4,11,10,...
    std::size_t previous_jacob = 1;
    std::size_t jacob = 3;
    std::size_t last = 1;  // b1 is already in the chain.

    while (last < pending.size())
    {
        const std::size_t upper =
            (jacob < pending.size()) ? jacob : pending.size();
        for (std::size_t number = upper; number > last; --number)
            insert_pending_vector(chain, pending, number - 1);
        last = upper;
        if (last == pending.size())
            break;
        const std::size_t next = jacob + 2 * previous_jacob;
        previous_jacob = jacob;
        jacob = next;
    }
    arr.swap(chain);
}

// Same Ford-Johnson algorithm, but all working sequences use std::deque.
void PmergeMe::ford_johnson_deque(std::deque<Item> &arr,
    std::size_t original_count)
{
    if (arr.size() <= 1)
        return;

    std::deque<Item> winners;
    std::deque<Item> small_by_winner_id(original_count);
    const bool has_stray = (arr.size() % 2 != 0);
    Item stray;
    if (has_stray)
        stray = arr.back();

    for (std::size_t i = 0; i + 1 < arr.size(); i += 2)
    {
        Item big = arr[i];
        Item small = arr[i + 1];
        if (big.value < small.value)
        {
            Item temp = big;
            big = small;
            small = temp;
        }
        winners.push_back(big);
        small_by_winner_id[big.id] = small;
    }

    ford_johnson_deque(winners, original_count);

    std::deque<Item> chain;
    std::deque<Pending> pending;
    for (std::size_t i = 0; i < winners.size(); ++i)
    {
        const Item &big = winners[i];
        pending.push_back(Pending(small_by_winner_id[big.id], big.id, true));
        if (i == 0)
            chain.push_back(pending[0].small);
        chain.push_back(big);
    }
    if (has_stray)
        pending.push_back(Pending(stray, 0, false));

    std::size_t previous_jacob = 1;
    std::size_t jacob = 3;
    std::size_t last = 1;
    while (last < pending.size())
    {
        const std::size_t upper =
            (jacob < pending.size()) ? jacob : pending.size();
        for (std::size_t number = upper; number > last; --number)
            insert_pending_deque(chain, pending, number - 1);
        last = upper;
        if (last == pending.size())
            break;
        const std::size_t next = jacob + 2 * previous_jacob;
        previous_jacob = jacob;
        jacob = next;
    }
    arr.swap(chain);
}

void PmergeMe::print_before() const
{
    std::cout << "Before:";
    for (std::size_t i = 0; i < _original.size(); ++i)
        std::cout << " " << _original[i];
    std::cout << '\n';
}

void PmergeMe::print_after() const
{
    std::cout << "After:";
    for (std::size_t i = 0; i < _vector.size(); ++i)
        std::cout << " " << _vector[i].value;
    std::cout << '\n';
}

void PmergeMe::print_time(const std::string &container,
    double microseconds) const
{
    std::cout << "Time to process a range of " << _vector.size()
              << " elements with std::" << container << " : "
              << std::fixed << std::setprecision(3)
              << microseconds << " us" << std::endl;
}

void PmergeMe::sort(int argc, char **argv)
{
    if (argc < 2)
        throw InvalidInput();

    _vector.clear();
    _deque.clear();
    _original.clear();

    // Time input parsing, container population, AND sorting for vector.
    const double vector_start = now_microseconds();
    for (int i = 1; i < argc; ++i)
    {
        const int number = parse_number(argv[i]);
        _vector.push_back(Item(number, static_cast<std::size_t>(i - 1)));
        _original.push_back(number);
    }
    ford_johnson_vector(_vector, _vector.size());
    _vector_time = now_microseconds() - vector_start;

    // Repeat the same parsing and sorting with deque.
    const double deque_start = now_microseconds();
    for (int i = 1; i < argc; ++i)
    {
        const int number = parse_number(argv[i]);
        _deque.push_back(Item(number, static_cast<std::size_t>(i - 1)));
    }
    ford_johnson_deque(_deque, _deque.size());
    _deque_time = now_microseconds() - deque_start;

    print_before();
    print_after();
    print_time("vector", _vector_time);
    print_time("deque", _deque_time);
}
