/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVector.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:43:18 by victoirevau       #+#    #+#             */
/*   Updated: 2024/10/30 16:02:12 by vvaudain         ###   ########.fr       */
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

static std::vector<std::pair<int, int> > makePairs(std::vector<int> vec)
{
    std::vector<std::pair<int, int> > pairs;
    if (vec.size() % 2 != 0)
        vec.push_back(std::numeric_limits<int>::max());
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it += 2)
    {
        if (it + 1 != vec.end())
            pairs.push_back(std::make_pair(*it, *(it + 1)));
    }
    return pairs;
}

void printPairVec(std::vector<std::pair<int, int> > pairs)
{
    for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
    {
        std::cout << it->first << " " << it->second << " ";
    }
    std::cout << std::endl;
}

std::vector<std::pair<int, int> > PmergeMeVector::merge(std::vector<std::pair<int, int> >& vec, int left, int mid, int right)
{
    std::vector<std::pair<int, int> > ResultVec;
    int i = left;
    int j = mid + 1;
    while (i <= mid && j <= right)
    {
        if (vec[i].first <= vec[j].first)
            ResultVec.push_back(vec[i++]);
        else
            ResultVec.push_back(vec[j++]);
    }
    while (i <= mid)
        ResultVec.push_back(vec[i++]);
    while (j <= right)
        ResultVec.push_back(vec[j++]);
    for (std::vector<std::pair<int, int> >::size_type k = 0; k < ResultVec.size(); k++) {
        vec[left + k] = ResultVec[k];
    }
    return vec;
}

std::vector<std::pair<int, int> > PmergeMeVector::mergeSort(std::vector<std::pair<int, int> >& vec, int left, int right) {
    std::vector<std::pair<int, int> > ResultVec;
    if (left > right)
        return ResultVec;
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(vec, left, mid);
        mergeSort(vec, mid + 1, right);
        ResultVec = merge(vec, left, mid, right);
    }
    return ResultVec;
}

void PmergeMeVector::sortFJ()
{
    int size = this->vec.size();
    if (size == 1)
        return;
    if (size >= 2)
    {
        std::vector<std::pair<int, int> > pairs = makePairs(this->vec);
        this->vec.clear();
        for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
        {
            if (it->first > it->second)
                std::swap(it->first, it->second);
        }
        std::vector<std::pair<int, int> > res = mergeSort(pairs, 0, pairs.size() - 1);
        std::vector<int> main;
        std::vector<int> pend;
        for (std::vector<std::pair<int, int> >::iterator it = res.begin(); it != res.end(); it++)
        {
            main.push_back(it->first);
            pend.push_back(it->second);
        }
        
    }
	
}