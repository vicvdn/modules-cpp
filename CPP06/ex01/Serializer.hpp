/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:26:34 by victoirevau       #+#    #+#             */
/*   Updated: 2024/10/17 10:48:29 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "Data.hpp"
#include <iostream>

class Serializer {
	public:
		Serializer();
		Serializer(Serializer const & src);
		~Serializer();
		Serializer &	operator=(Serializer const & rhs);
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif