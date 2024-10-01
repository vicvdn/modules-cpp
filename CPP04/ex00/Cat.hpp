/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:58:31 by victoirevau       #+#    #+#             */
/*   Updated: 2024/08/14 12:09:25 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <string>
#include <iostream>

#define CYAN  "\033[36m"
#define RESET   "\033[0m"

class Cat : public Animal {
	public:
		Cat();
		Cat(const Cat &copy);
		~Cat();
		void makeSound(void) const;
		Cat& operator=(const Cat &rhs);
};

#endif