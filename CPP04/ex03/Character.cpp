/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:41:10 by victoirevau       #+#    #+#             */
/*   Updated: 2024/08/03 12:23:38 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(): _name("default"), _free_space(4) {
	// std::cout << "This is the character constructor" << std::endl;

	for(int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(std::string name): _name(name), _free_space(4) {
	// std::cout << "This is the character init constructor" << std::endl;

	for(int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(const Character& copy){
	
	// std::cout << "This is the character copy constructor" << std::endl;

	if (this != &copy){
		this->_name = copy.getName();
		for(int i = 0; i < 4; i++){
			if (this->inventory[i] != NULL)
				delete this->inventory[i];
			if (copy.inventory[i] != NULL)
				this->inventory[i] = copy.inventory[i];
		}
	}
}

Character::~Character(){
	// std::cout << "This is the character destructor" << std::endl;
	for (int i = 0; i < 4; i++){
		if (this->inventory[i] != NULL)
			delete this->inventory[i];
	}
}

Character& Character::operator=(const Character& rhs){
	if (this != &rhs){
		this->_name = rhs.getName();
		for (int i = 0; i < 4; i++){
			if (this->inventory[i] != NULL)
				delete this->inventory[i];
			if (rhs.inventory[i] != NULL)
				this->inventory[i] = rhs.inventory[i];
		}
	}
	return (*this);
}

std::string const & Character::getName() const {
	return (this->_name);
}

void Character::equip(AMateria* m){
	this->_free_space--;
	if (this->_free_space < 0)
		return ;
	for (int i = 0; i < 4; i++){
		if (this->inventory[i] == NULL){
			this->inventory[i] = m;
			std::cout << BLUE << this->_name << RESET << " is equiped with " << m->getType() << " in " << i << std::endl;
			break;
		}
	}
}

void Character::unequip(int idx){
	if (idx >= 0 && idx < 4)
		this->inventory[idx] = NULL;
	this->_free_space--;
}

void Character::use(int idx, ICharacter& target){
	if (idx >= 0 && idx < 4){
		if(this->inventory[idx] != NULL)
			this->inventory[idx]->use(target);
		else
			std::cout << "Doesn't do anything: Materia " << idx << " not available"  << std::endl;
	}
	else
		std::cout << "Doesn't do anything: Materia " << idx << " not available"  << std::endl;
}