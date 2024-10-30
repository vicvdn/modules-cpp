/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeDeque.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:41:41 by victoirevau       #+#    #+#             */
/*   Updated: 2024/10/29 16:52:08 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMeDeque::PmergeMeDeque()
{
}

PmergeMeDeque::PmergeMeDeque(std::string str) : PmergeMe(str)
{
	// PmergeMe::createDeque(str);
}

PmergeMeDeque::PmergeMeDeque(PmergeMeDeque const & src)
{
	*this = src;
}

PmergeMeDeque & PmergeMeDeque::operator=(PmergeMeDeque const & src)
{
	if (this != &src)
		this->deq = src.deq;
	return *this;
}