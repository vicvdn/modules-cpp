/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:53:55 by vvaudain          #+#    #+#             */
/*   Updated: 2024/11/04 15:25:36 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <limits>
#include <ctime>
#include <algorithm>
#include <cmath>

#define BOLDBLUE "\033[1m\033[34m"
#define BOLDRED "\033[1m\033[31m"
#define BOLDGREEN "\033[1m\033[32m"
#define BOLDYELLOW "\033[1m\033[33m"
#define RESET "\033[0m"

class PmergeMe
{
    private:
        std::string str;
    public:
        PmergeMe();
        PmergeMe(std::string str);
        PmergeMe(PmergeMe const & src);
        PmergeMe & operator=(PmergeMe const & src);
        virtual ~PmergeMe();
        class OverflowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class DuplicateException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        std::string getStr(void) const;
        // void handleDeque();
        virtual void sortFJ() = 0;
        // void print();
};

class PmergeMeVector : public PmergeMe
{
    private:
        std::vector<int> vec;
        double time;
    public:
        PmergeMeVector();
        PmergeMeVector(std::string str);
        PmergeMeVector(PmergeMeVector const & src);
        PmergeMeVector & operator=(PmergeMeVector const & src);
        void parseVector();
        void createVector(std::string str);
        bool isDuplicate(void);
        std::vector<int> getVec(void) const;
        void sortFJ();
        std::vector<std::pair<int, int> > mergeSort(std::vector<std::pair<int, int> >& vec, int left, int right);
        std::vector<std::pair<int, int> > merge(std::vector<std::pair<int, int> >& vec, int left, int mid, int right);
        void insertSort(std::vector<int> main, std::vector<int> pend);
};

class PmergeMeDeque : public PmergeMe
{
    private:
        std::deque<int> deq;
        double time;
    public:
        PmergeMeDeque();
        PmergeMeDeque(std::string str);
        PmergeMeDeque(PmergeMeDeque const & src);
        PmergeMeDeque & operator=(PmergeMeDeque const & src);
        void parseDeque();
        void createDeque(std::string str);
        bool isDuplicate(void);
        std::deque<int> getDeq(void) const;
        void sortFJ();
        std::deque<std::pair<int, int> > mergeSort(std::deque<std::pair<int, int> >& deq, int left, int right);
        std::deque<std::pair<int, int> > merge(std::deque<std::pair<int, int> >& deq, int left, int mid, int right);
        void insertSort(std::deque<int>& main, std::deque<int>& pend);
};

#endif