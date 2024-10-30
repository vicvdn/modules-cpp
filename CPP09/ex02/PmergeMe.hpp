/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:53:55 by vvaudain          #+#    #+#             */
/*   Updated: 2024/10/30 14:58:26 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <limits>

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