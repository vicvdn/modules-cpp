/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:00:06 by victoirevau       #+#    #+#             */
/*   Updated: 2024/08/03 12:23:57 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

#define BLUE "\033[34m"
#define RESET "\033[0m"

class Character : public ICharacter {
	
	private:
		std::string _name;
		AMateria*	inventory[4];
		int			_free_space;
	
	public:
		Character();
		Character(const Character& copy);
		Character& operator=(const Character& rhs);
		virtual ~Character();
		
		Character(std::string name);
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif