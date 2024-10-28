/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:53:55 by vvaudain          #+#    #+#             */
/*   Updated: 2024/10/28 17:03:12 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
#include <sstream>
#include <vector>

class PmergeMe
{
    private:
        std::string str;
    public:
        PmergeMe();
        PmergeMe(std::string str);
        PmergeMe(PmergeMe const & src);
        PmergeMe & operator=(PmergeMe const & src);
        ~PmergeMe();
        void print();
};

#endif