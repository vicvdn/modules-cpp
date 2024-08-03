/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:59:48 by victoirevau       #+#    #+#             */
/*   Updated: 2024/08/03 12:59:23 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void	MandatoryTests(void){
	IMateriaSource* src = new MateriaSource();
	
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	AMateria* tmp;

	std::cout << std::endl;
	std::cout << GREEN << "MANDATORY TESTS" << RESET << std::endl;
	std::cout << std::endl;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	//adding a materia that is not in the inventory
	tmp = src->createMateria("Error");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	
	std::cout << std::endl;
	
	delete bob;
	delete me;
	delete src;
}

void	AdditionnalTests(void){
	ICharacter* character1 = new Character("first");
	ICharacter* character2 = new Character("second");
	IMateriaSource* src = new MateriaSource();
	
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();
	
	std::cout << std::endl;
	std::cout << GREEN << "ADDITIONNAL TESTS" << RESET << std::endl;
	std::cout << std::endl;

	
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());


	// Test 1: Use a materia without equipping it
	std::cout << "Test 1: Use a materia without equipping it" << std::endl;
	ice->use(*character1);
	std::cout << std::endl;

	// Test 2: Equip a materia and use it
	std::cout << "Test 2: Equip a materia and use it" << std::endl;
	character1->equip(ice);
	character1->use(0, *character2);
	std::cout << std::endl;

	// Test 3: Overequip a character
	std::cout << "Test 3: Overequip a character" << std::endl;
	character1->equip(ice);
	character1->equip(cure);
	character1->equip(ice);
	character1->equip(cure); // This one should not be equipped because we already equipped char1 with 4 materias

	// Test 4: Unequip a materia and use it
	std::cout << "Test 4: Unequip a materia and use it" << std::endl;
	character2->equip(ice);
	character2->unequip(0);
	character2->use(0, *character1);
}

int	main() {
	MandatoryTests();
	AdditionnalTests();
	return 0;
}