/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:53:55 by vvaudain          #+#    #+#             */
/*   Updated: 2024/10/31 18:16:45 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <limits>
#include <sys/time.h>

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
        void handleVector();
        // void handleDeque();
        virtual void sortFJ() = 0;
        // void print();
};

class PmergeMeVector : public PmergeMe
{
    private:
        std::vector<int> vec;
        struct timeval start;
        struct timeval end;
    public:
        PmergeMeVector();
        PmergeMeVector(std::string str);
        PmergeMeVector(PmergeMeVector const & src);
        PmergeMeVector & operator=(PmergeMeVector const & src);
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
    public:
        PmergeMeDeque();
        PmergeMeDeque(std::string str);
        PmergeMeDeque(PmergeMeDeque const & src);
        PmergeMeDeque & operator=(PmergeMeDeque const & src);
};

#endif