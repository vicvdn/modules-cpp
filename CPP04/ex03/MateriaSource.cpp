/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:53:00 by victoirevau       #+#    #+#             */
/*   Updated: 2024/08/02 15:28:30 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
	for(int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& copy){
	for(int i = 0; i < 4; i++){
		if (this->inventory[i] != NULL)
			delete this->inventory[i];
		if (copy.inventory[i] != NULL)
			this->inventory[i] = copy.inventory[i];
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs){
	if (this != &rhs){
		for (int i = 0; i < 4; i++){
			if (this->inventory[i] != NULL)
				delete this->inventory[i];
			if (rhs.inventory[i] != NULL)
				this->inventory[i] = rhs.inventory[i];
		}
	}
}

MateriaSource::~MateriaSource(){
	for (int i = 0; i < 4; i++){
		if (this->inventory[i] != NULL)
			delete this->inventory[i];
	}
}

void MateriaSource::learnMateria(AMateria* material){
	for(int i = 0; i < 4; i++){
		if (this->inventory[i] = NULL){
			this->inventory[i] = material;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type){
	for (int i = 0; i < 4; i++){
		if(this->inventory[i]){
			if(this->inventory[i]->getType() == type){
				return (this->inventory[i]->clone());
			}
		}
	}
}