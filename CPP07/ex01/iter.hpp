/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:43:34 by victoirevau       #+#    #+#             */
/*   Updated: 2024/10/17 15:43:53 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T> void print(T const &x)
{
	std::cout << x << std::endl;
}

template <typename T> void changeTo0(T const &x)
{
	//cast away the constness of x
	const_cast<T &>(x) = 0;
}

//specialization for std::string because we can't cast away the constness of a string
template <> void changeTo0<std::string>(const std::string &x)
{
	//cast away the constness of x
	const_cast<std::string &>(x) = "0";
}

template <typename T> void iter(T *array, size_t size, void (*f)(T const &))
{
	for (size_t i = 0; i < size; i++)
		f(array[i]);
}

#endif