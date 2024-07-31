/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:00:36 by victoirevau       #+#    #+#             */
/*   Updated: 2024/07/31 16:39:44 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void){
	std::cout << GREEN << "This is the Brain default constructor" << RESET << std::endl;
}

Brain::~Brain(void){
	std::cout << RED << "This is the Brain destructor" << RESET << std::endl;
}

Brain::Brain(const Brain &copy){
	std::cout << GREEN << "This is the Brain copy constructor" << RESET << std::endl;
	*this = copy;
}

void	Brain::setIdeas(std::string ids){
	for(int i = 0; i < 100; i++)
		this->ideas[i] = ids;
}

Brain& Brain::operator=(const Brain& rhs){
	if (this != &rhs){
		for (int i = 0; i < 100; i++)
			this->ideas[i] = rhs.ideas[i];
	}
	return (*this);
}

const std::string *Brain::getIdeas(void) const{
	const std::string	*ptr = this->ideas;
	return (ptr);
}