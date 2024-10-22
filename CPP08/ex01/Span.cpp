/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:40:12 by victoirevau       #+#    #+#             */
/*   Updated: 2024/10/21 15:43:38 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : n(0) {}

Span::Span(unsigned int n) : n(n) {}

Span::Span(Span const & src) {
	*this = src;
}

Span::~Span() {}

Span & Span::operator=(Span const & rhs) {
	if (this != &rhs) {
		this->n = rhs.n;
		this->vec = rhs.vec;
	}
	return *this;
}

void Span::addRange(std::vector<int> &range)
{
	if (this->vec.size() + range.size() <= this->n)
		this->vec.insert(this->vec.end(), range.begin(), range.end());
	else
		throw tooManyNumbers();
}

void Span::addNumber(int i) 
{
	if (this->vec.size() < this->n)
		this->vec.push_back(i);
	else
		throw tooManyNumbers();
}

int Span::shortestSpan() 
{
	if (this->vec.size() < 2)
		throw notEnoughNumbers();
	
	std::vector<int> tmp = this->vec;
	std::sort(tmp.begin(), tmp.end());
	
	int min = std::numeric_limits<int>::max();
	int diff = 0;
	for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end(); it++)
	{
		for (std::vector<int>::iterator it2 = it + 1; it2 != tmp.end(); it2++)
		{
			diff = *it2 - *it;
			if (diff < min)
				min = diff;
		}
	}
	return min;
}

int Span::longestSpan() 
{
	if (this->vec.size() < 2)
		throw notEnoughNumbers();
	
	std::vector<int> tmp = this->vec;
	std::sort(tmp.begin(), tmp.end());

	int a = *std::max_element(this->vec.begin(), this->vec.end());
	int b = *std::min_element(this->vec.begin(), this->vec.end());

	return (abs(a - b));
}