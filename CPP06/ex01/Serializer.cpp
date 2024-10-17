/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:25:56 by victoirevau       #+#    #+#             */
/*   Updated: 2024/10/17 10:55:40 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(Serializer const & src) 
{
	*this = src;
}

Serializer::~Serializer() {}

Serializer &	Serializer::operator=(Serializer const & rhs) 
{
	if (this != &rhs) {
		*this = rhs;
	}
	return *this;
}

uintptr_t	Serializer::serialize(Data* ptr) 
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}