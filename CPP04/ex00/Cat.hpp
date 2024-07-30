/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:58:31 by victoirevau       #+#    #+#             */
/*   Updated: 2024/07/30 14:52:02 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <string>
#include <iostream>

class Cat : virtual public Animal {
	public:
		Cat();
		Cat(const Cat &copy);
		virtual ~Cat();
		virtual void makeSound(void) const;
		Cat& operator=(const Cat &rhs);
};

#endif