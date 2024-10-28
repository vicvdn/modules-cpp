/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:02:09 by vvaudain          #+#    #+#             */
/*   Updated: 2024/10/28 17:03:25 by vvaudain         ###   ########.fr       */
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

