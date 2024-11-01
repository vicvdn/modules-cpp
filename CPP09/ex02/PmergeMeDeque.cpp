/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeDeque.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:41:41 by victoirevau       #+#    #+#             */
/*   Updated: 2024/11/01 12:22:08 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMeDeque::PmergeMeDeque()
{
}

PmergeMeDeque::PmergeMeDeque(std::string str) : PmergeMe(str)
{
	PmergeMeDeque::createDeque(str);
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

void PmergeMeDeque::parseDeque()
{
    PmergeMeDeque deq(getStr());
    if (deq.isDuplicate() == true)
        throw PmergeMe::DuplicateException();
}

void PmergeMeDeque::createDeque(std::string str)
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
            this->deq.push_back(i);
            temp.clear();
        }
    }
}

bool PmergeMeDeque::isDuplicate(void)
{
	for (std::deque<int>::iterator it = this->deq.begin(); it != this->deq.end(); it++)
	{
		for (std::deque<int>::iterator it2 = it + 1; it2 != this->deq.end(); it2++)
		{
			if (*it == *it2)
				return true;
		}
	}
	return false;
}

std::deque<int> PmergeMeDeque::getDeq(void) const
{
	return this->deq;
}

static std::deque<std::pair<int, int> > makePairs(std::deque<int> deq)
{
    std::deque<std::pair<int, int> > pairs;
    if (deq.size() % 2 != 0)
        deq.push_back(std::numeric_limits<int>::min());
    for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); it += 2)
    {
        if (it + 1 != deq.end())
            pairs.push_back(std::make_pair(*it, *(it + 1)));
    }
    return pairs;
}
//to remove
void printPairDeq(std::deque<std::pair<int, int> > pairs)
{
    for (std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
    {
        std::cout << it->first << " " << it->second << " ";
    }
    std::cout << std::endl;
}

std::deque<std::pair<int, int> > PmergeMeDeque::merge(std::deque<std::pair<int, int> >& deq, int left, int mid, int right)
{
    std::deque<std::pair<int, int> > ResultDeq;
    int i = left;
    int j = mid + 1;
    while (i <= mid && j <= right)
    {
        if (deq[i].first <= deq[j].first)
            ResultDeq.push_back(deq[i++]);
        else
            ResultDeq.push_back(deq[j++]);
    }
    while (i <= mid)
        ResultDeq.push_back(deq[i++]);
    while (j <= right)
        ResultDeq.push_back(deq[j++]);
    for (std::deque<std::pair<int, int> >::size_type k = 0; k < ResultDeq.size(); k++) {
        deq[left + k] = ResultDeq[k];
    }
    return deq;
}

std::deque<std::pair<int, int> > PmergeMeDeque::mergeSort(std::deque<std::pair<int, int> >& deq, int left, int right) {
    std::deque<std::pair<int, int> > ResultDeq;
    if (left > right)
        return ResultDeq;
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(deq, left, mid);
        mergeSort(deq, mid + 1, right);
        ResultDeq = merge(deq, left, mid, right);
    }
    return ResultDeq;
}

static std::deque<int> generateJacobstahlSequence(int limit) {
    std::deque<int> sequence;
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

static int BinarySearch(std::deque<int>& deq, int& value){
  int left = 0;
  int right = deq.size() - 1;
  int mid;
  while (left <= right)
  {
    mid = floor( (left + right) / 2 );
    if (deq[mid] < value)
      left = mid + 1;
    else if (deq[mid] > value)
      right = mid - 1;
    else
      return mid;
  }
  return right;
}

void PmergeMeDeque::insertSort(std::deque<int> main, std::deque<int> pend)
{
    //let's insert the elements of pend in main in a sorted way using the jacobsthal sequence
    std::deque<int> jacobsthal = generateJacobstahlSequence(pend.size());
    
    int toInsert;
    int gap;
    std::deque<int>::reverse_iterator ritPendStart = pend.rend();
    std::deque<int>::reverse_iterator ritPendEnd = pend.rend();
    for (size_t i = 0; i < pend.size(); i++) {
        ritPendEnd = ritPendStart;
        if (i + jacobsthal[i] < pend.size() - 1) {
            ritPendStart = ritPendEnd - jacobsthal[i];
        } else {
            ritPendStart = pend.rbegin();
        }
        for (std::deque<int>::reverse_iterator rit = ritPendStart; rit != ritPendEnd; rit++) {
            toInsert = *rit;
            gap = BinarySearch(main, toInsert);
            try {
                main.insert(main.begin() + gap + 1, toInsert);
            } catch (std::out_of_range) {
                main.insert(main.begin() + gap, toInsert);
            }
        }
    }
    this->deq = main;
}

// static void printDeq(std::deque<int> deq)
// {
//     for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); it++)
//     {
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;
// }

void PmergeMeDeque::sortFJ()
{
    clock_t startTime = clock();
    unsigned long size = this->deq.size();
    if (size == 1)
        return;
    if (size >= 2)
    {
        std::deque<std::pair<int, int> > pairs = makePairs(this->deq);
        this->deq.clear();
        for (std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
        {
            if (it->first > it->second)
                std::swap(it->first, it->second);
        }
        std::deque<std::pair<int, int> > res = mergeSort(pairs, 0, pairs.size() - 1);
        std::deque<int> main;
        std::deque<int> pend;
        for (std::deque<std::pair<int, int> >::iterator it = res.begin(); it != res.end(); it++)
        {
            main.push_back(it->first);
            pend.push_back(it->second);
        }
        if (main.size() + pend.size() != size)
        {
            std::deque<int>::iterator it = std::find(pend.begin(), pend.end(), std::numeric_limits<int>::min());
            std::deque<int>::iterator it2 = std::find(main.begin(), main.end(), std::numeric_limits<int>::min());
            if (it != pend.end())
                pend.erase(it);
            if (it2 != main.end())
                main.erase(it2);
        }
        insertSort(main, pend);
    }
    time = (clock() - startTime) / (double) CLOCKS_PER_SEC * 1000; // in ms
	// printDeq(this->deq);
    std::cout << BOLDYELLOW << "Time to process a range of " << size 
    << " elements with std::deque : " << RESET << time << " us" << std::endl;
}