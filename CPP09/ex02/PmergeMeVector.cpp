/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVector.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:43:18 by victoirevau       #+#    #+#             */
/*   Updated: 2024/10/29 17:12:25 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMeVector::PmergeMeVector()
{
}

PmergeMeVector::PmergeMeVector(std::string str) : PmergeMe(str)
{
	PmergeMeVector::createVector(str);
}

PmergeMeVector::PmergeMeVector(PmergeMeVector const & src)
{
	*this = src;
}

PmergeMeVector & PmergeMeVector::operator=(PmergeMeVector const & src)
{
	if (this != &src)
		this->vec = src.vec;
	return *this;
}

void PmergeMeVector::createVector(std::string str)
{
    int strLen = str.size();
    std::string temp;
    for (int i = 0; i < strLen; i++)
    {
        if (str[i] != ' ' && str[i] != '\t')
            temp += str[i];
        if (str[i] == ' ' || str[i] == '\t' || i == strLen - 1)
        {
            std::stringstream ss;
            ss << temp;
            if (temp.length() > 10)
                throw PmergeMe::OverflowException();
            long n;
            ss >> n;
            if (n < -2147483648 || n > 2147483647)
                throw PmergeMe::OverflowException();
            int i = static_cast<int>(n);
            this->vec.push_back(i);
            temp.clear();
        }
    }
}

bool PmergeMeVector::isDuplicate(void)
{
	for (std::vector<int>::iterator it = this->vec.begin(); it != this->vec.end(); it++)
	{
		for (std::vector<int>::iterator it2 = it + 1; it2 != this->vec.end(); it2++)
		{
			if (*it == *it2)
				return true;
		}
	}
	return false;
}

std::vector<int> PmergeMeVector::getVec(void) const
{
	return this->vec;
}

void PmergeMeVector::sortFJ()
{
	//first we want to make pairs of two elements
	
}