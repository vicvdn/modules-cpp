/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:02:09 by vvaudain          #+#    #+#             */
/*   Updated: 2024/11/01 11:04:40 by victoirevau      ###   ########.fr       */
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

std::string PmergeMe::getStr(void) const
{
    return this->str;
}



