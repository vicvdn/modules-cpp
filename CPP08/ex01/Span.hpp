/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:28:06 by victoirevau       #+#    #+#             */
/*   Updated: 2024/10/21 15:43:44 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

class Span {

	private :
		unsigned int n;
		std::vector<int> vec;

	public :
		Span();
		Span(unsigned int n);
		Span(Span const & src);
		~Span();
		Span & operator=(Span const & rhs);
		class tooManyNumbers : public std::exception {
			public : 
			const char *what() const throw() {
				return "Too many numbers in the span";
			}
		};
		class notEnoughNumbers : public std::exception {
			public : 
			const char *what() const throw() {
				return "Not enough numbers in the span";
			}
		};
		void addRange(std::vector<int> &range);
		void addNumber(int n);
		int shortestSpan();
		int longestSpan();
};

#endif