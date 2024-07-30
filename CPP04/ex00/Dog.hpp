/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:27:43 by victoirevau       #+#    #+#             */
/*   Updated: 2024/07/30 14:52:07 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <string>
#include <iostream>

class Dog : virtual public Animal {
	public:
		Dog();
		Dog(const Dog &copy);
		virtual ~Dog();
		virtual void makeSound(void) const;
		Dog& operator=(const Dog &rhs);
};

#endif