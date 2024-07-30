/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:58:31 by victoirevau       #+#    #+#             */
/*   Updated: 2024/07/30 18:07:11 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <string>
#include <iostream>

#define CYAN  "\033[36m"
#define RESET   "\033[0m"

class Cat : virtual public Animal {
	public:
		Cat();
		Cat(const Cat &copy);
		virtual ~Cat();
		virtual void makeSound(void) const;
		Cat& operator=(const Cat &rhs);
};

#endif