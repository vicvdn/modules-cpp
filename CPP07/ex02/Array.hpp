/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:11:06 by victoirevau       #+#    #+#             */
/*   Updated: 2024/10/17 16:43:33 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

#define BOLDBLUE "\033[1m\033[34m"
#define BOLDRED "\033[1m\033[31m"
#define RESET "\033[0m"

template <typename T> class Array {
	private:
		T *array;
		unsigned int arraySize;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &copy);
		~Array();
		// Array &operator=(const Array &copy);
		T &operator[](unsigned int i);
		unsigned int size() const;
		// class out_of_range: public std::exception {
		// public:
		// 	virtual const char* what(void) const throw();
		// };

};

#include "Array.tpp"

#endif