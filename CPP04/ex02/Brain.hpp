/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:36:31 by victoirevau       #+#    #+#             */
/*   Updated: 2024/07/31 16:40:06 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

class Brain {
	
	protected:
		std::string ideas[100];
	
	public:
		Brain();
		~Brain();
		Brain(const Brain& copy);
		Brain &operator=(const Brain& rhs);
		void setIdeas(std::string ideas);
		const std::string *getIdeas(void) const;
};

#endif