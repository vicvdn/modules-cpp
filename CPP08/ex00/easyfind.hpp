/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:30:52 by victoirevau       #+#    #+#             */
/*   Updated: 2024/11/05 16:56:55 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>

#define BOLDBLUE "\033[1m\033[34m"
#define BOLDRED "\033[1m\033[31m"
#define BOLDGREEN "\033[1m\033[32m"
#define RESET "\033[0m"

template <typename T> int easyfind(T &container, int value);

//we define a personnalized exception
class ValueNotFound : public std::exception
{
    virtual const char *what() const throw()
    {
        return "Value not found in container";
    }
};

#include "easyfind.tpp"
#endif