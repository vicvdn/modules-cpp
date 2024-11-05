/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:40:10 by vvaudain          #+#    #+#             */
/*   Updated: 2024/11/05 16:56:40 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <sstream>
#include <list>

#define BOLDBLUE "\033[1m\033[34m"
#define RESET "\033[0m"

/*the stack is a container adapter, so it is not a container itself
it uses a container to store its elements and the default container
used is deque, which happens to have iterators */

template <typename T, typename Container = std::deque<T> > 
class MutantStack : public std::stack<T, Container>
{
    public:
        MutantStack();
        MutantStack(MutantStack const & src);
        ~MutantStack();
        MutantStack & operator=(MutantStack const & rhs);
        typedef typename Container::iterator iterator;
        iterator begin();
        iterator end();
};

#include "MutantStack.tpp"

#endif