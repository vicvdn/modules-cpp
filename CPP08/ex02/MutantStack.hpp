/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-22 11:40:10 by vvaudain          #+#    #+#             */
/*   Updated: 2024-10-22 11:40:10 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

template <typename T, typename Container = std::deque<T>> 
class MutantStack : public std::stack<T, Container>
{
    public:
        MutantStack();
        MutantStack(MutantStack const & src);
        ~MutantStack();
        MutantStack & operator=(MutantStack const & rhs);
        // typedef typename Container::iterator iterator;
        Container::iterator begin();
        Container::iterator end();
};

#endif