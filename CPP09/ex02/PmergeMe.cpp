/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:02:09 by vvaudain          #+#    #+#             */
/*   Updated: 2024/10/29 17:00:17 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(std::string str) : str(str)
{
}

PmergeMe::PmergeMe(PmergeMe const & src)
{
    *this = src;
}

PmergeMe & PmergeMe::operator=(PmergeMe const & src)
{
    if (this != &src)
    {
        this->str = src.str;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
}

const char *PmergeMe::OverflowException::what() const throw()
{
    return "Error: Overflow";
}

const char *PmergeMe::DuplicateException::what() const throw()
{
    return "Error: Duplicate number";
}

void PmergeMe::handleVector()
{
    PmergeMeVector vec(str);
    if (vec.isDuplicate() == true)
        throw PmergeMe::DuplicateException();
    vec.sortFJ();
}



