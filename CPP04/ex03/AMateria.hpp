/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:00:03 by victoirevau       #+#    #+#             */
/*   Updated: 2024/08/02 15:56:45 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

class ICharacter; 
/*Forward declaration because of circular dependency : AMateria.hpp
includes ICharacter.hpp and ICharacter.hpp includes AMateria.hpp*/
class AMateria {
	protected:
		std::string _type;
	
	public:
		AMateria();
		AMateria(const AMateria &copy);
		AMateria& operator=(const AMateria &rhs);
		virtual ~AMateria();
		AMateria(std::string const & type);
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif