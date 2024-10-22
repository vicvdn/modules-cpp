/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-22 12:24:37 by vvaudain          #+#    #+#             */
/*   Updated: 2024-10-22 12:24:37 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

MutantStack<T>::MutantStack() : std::stack<T>() {}

MutantStack<T>::MutantStack(MutantStack const & src) : std::stack<T>(src) {
    *this = src;
}

MutantStack<T>::~MutantStack() {}

MutantStack<T> & MutantStack<T>::operator=(MutantStack const & rhs)
{
    if (this != &rhs)
        std::stack<T>::operator=(rhs);
    return *this;
}

MutantStack<T>::iterator MutantStack<T>::begin()
{
    return this->c.begin();
}

MutantStack<T>::iterator MutantStack<T>::end()
{
    return this->c.end();
}