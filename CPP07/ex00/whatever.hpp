/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:03:37 by victoirevau       #+#    #+#             */
/*   Updated: 2024/10/17 14:27:29 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>
#include <string>

#define BOLDBLUE	"\033[1m\033[34m"
#define BOLDGREEN	"\033[1m\033[32m"
#define BOLDRED		"\033[1m\033[31m"
#define BOLDYELLOW	"\033[1m\033[33m"
#define RESET		"\033[0m"

template <typename T> void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}
template <typename T> T min(T &a, T &b)
{
	if (a < b)
		return a;
	else
		return b;
}
template <typename T> T max(T &a, T &b)
{
	if (a > b)
		return a;
	else
		return b;
}

#endif