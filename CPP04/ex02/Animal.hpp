/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:14:07 by victoirevau       #+#    #+#             */
/*   Updated: 2024/07/31 18:17:00 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class Animal{

	protected:
		std::string	_type;
		
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal &copy);
		virtual ~Animal();
		Animal &operator=(const Animal &rhs);
		virtual void makeSound(void) const = 0;
		std::string getType(void) const;
};

#endif