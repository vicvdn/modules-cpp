/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVector.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:43:18 by victoirevau       #+#    #+#             */
/*   Updated: 2024/11/04 13:50:50 by vvaudain         ###   ########.fr       */
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

void PmergeMeVector::parseVector()
{
    PmergeMeVector vec(getStr());
    if (vec.isDuplicate() == true)
        throw PmergeMe::DuplicateException();
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
        vec.push_back(std::numeric_limits<int>::min());
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

// The merge function takes two sorted halves (vec[left to mid] and vec[mid + 1 to right]) and merges them in sorted order into ResultVec.

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

static std::vector<int> generateJacobstahlSequence(int limit) {
    std::vector<int> sequence;
    int a = 0, b = 1;
    while (a <= limit) {
        sequence.push_back(a);
        int next = a + 2 * b;
        a = b;
        b = next;
    }
    if (!sequence.empty() && sequence[0] == 0) 
        sequence.erase(sequence.begin());
    return sequence;
}

static int BinarySearch(std::vector<int>& vec, int& value){
  int left = 0;
  int right = vec.size() - 1;
  int mid;
  while (left <= right)
  {
    mid = floor( (left + right) / 2 );
    if (vec[mid] < value)
      left = mid + 1;
    else if (vec[mid] > value)
      right = mid - 1;
    else
      return mid;
  }
  return right;
}

void PmergeMeVector::insertSort(std::vector<int> main, std::vector<int> pend)
{
    //let's insert the elements of pend in main in a sorted way using the jacobsthal sequence
    std::vector<int> jacobsthal = generateJacobstahlSequence(pend.size());
    
    int toInsert;
    int gap;
    std::vector<int>::reverse_iterator ritPendStart = pend.rend();
    std::vector<int>::reverse_iterator ritPendEnd = pend.rend();
    for (size_t i = 0; i < pend.size(); i++) {
        ritPendEnd = ritPendStart;
        if (i < jacobsthal.size() && i + jacobsthal[i] < pend.size())
            ritPendStart = ritPendEnd - jacobsthal[i];
        else
            ritPendStart = pend.rbegin();

        if (ritPendStart < pend.rbegin() || ritPendStart > pend.rend())
            ritPendStart = pend.rbegin();
        
        for (std::vector<int>::reverse_iterator rit = ritPendStart; rit != ritPendEnd; rit++)
        {
            toInsert = *rit;
            
            gap = BinarySearch(main, toInsert);
            
            // if (gap >= 0 && gap < static_cast<int>(main.size()))
            //     main.insert(main.begin() + gap + 1, toInsert);
            // else
            //     main.insert(main.begin() + gap, toInsert);
            try {
                main.insert(main.begin() + gap + 1, toInsert);
            } catch (std::out_of_range) {
                main.insert(main.begin() + gap, toInsert);
            }
        }
    }
    this->vec = main;
}

static void printVec(std::vector<int> vec, int size)
{
    if (size > 10)
    {
        for (int i = 0; i < 10; i++)
        {
            std::cout << vec[i] << " ";
        }
        std::cout << "[...]";
    }
    else
    {
        for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        {
            std::cout << *it << " ";
        }
    }
    std::cout << std::endl;
}

void PmergeMeVector::sortFJ()
{
    clock_t startTime = clock();
    unsigned long size = this->vec.size();
    printVec(this->vec, size);
    if (size == 1)
        return;
    if (size >= 2)
    {
        std::vector<std::pair<int, int> > pairs = makePairs(this->vec);
        this->vec.clear();
        for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
        {
            if (it->first < it->second)
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
        if (main.size() + pend.size() != size)
        {
            std::vector<int>::iterator it = std::find(pend.begin(), pend.end(), std::numeric_limits<int>::min());
            std::vector<int>::iterator it2 = std::find(main.begin(), main.end(), std::numeric_limits<int>::min());
            if (it != pend.end())
                pend.erase(it);
            if (it2 != main.end())
                main.erase(it2);
        }
        insertSort(main, pend);
    }
    time = (clock() - startTime) / (double) CLOCKS_PER_SEC * 1000; // in ms
    std::cout << BOLDGREEN << "After: " << RESET;
	printVec(this->vec, size);
    std::cout << BOLDBLUE << "Time to process a range of " << size 
    << " elements with std::vector : " << RESET << time << " us" << std::endl;
}