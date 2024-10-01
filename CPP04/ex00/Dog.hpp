/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:27:43 by victoirevau       #+#    #+#             */
/*   Updated: 2024/08/14 12:09:21 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <string>
#include <iostream>

class Dog : public Animal {
	public:
		Dog();
		Dog(const Dog &copy);
		~Dog();
		void makeSound(void) const;
		Dog& operator=(const Dog &rhs);
};

#endif