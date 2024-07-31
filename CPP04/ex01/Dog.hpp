/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:27:43 by victoirevau       #+#    #+#             */
/*   Updated: 2024/07/31 16:10:01 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

class Dog : public Animal {
	
	private:
		Brain	*_brain;
	
	public:
		Dog();
		Dog(const Dog &copy);
		virtual ~Dog();
		virtual void makeSound(void) const;
		Dog& operator=(const Dog &rhs);
		Brain* getBrain(void) const;
};

#endif