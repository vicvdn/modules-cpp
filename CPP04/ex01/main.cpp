/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:10:53 by victoirevau       #+#    #+#             */
/*   Updated: 2024/07/31 17:08:23 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	Animal** array = new Animal*[6];

	for (int i = 0; i < 4; i++){
		if (i % 2 == 0)
			array[i] = new Dog();
		else
			array[i] = new Cat();
	}
	std::cout << std::endl;
	for (int i = 0; i < 4; i++){
		array[i]->makeSound();
	}
	std::cout << std::endl;
	std::cout << "Let's free the array!" << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < 4; i++){
		delete array[i];
	}
	delete[] array;
	
	//shallow copy example
	Dog *dog = new Dog();
	dog->getBrain()->setIdeas("Croquettes");
	Dog *dog2 = dog;
	
	std::cout << "Before changing idea" << std::endl;
	std::cout << "Dog idea : " << dog->getBrain()->getIdeas()[0] << std::endl;
	std::cout << "Dog2 idea : " << dog2->getBrain()->getIdeas()[0] << std::endl;

	std::cout << "After changing dog idea" << std::endl;
	dog->getBrain()->setIdeas("Cheese is better");
	std::cout << "Dog idea : " << dog->getBrain()->getIdeas()[0] << std::endl;
	std::cout << "Dog2 idea : " << dog2->getBrain()->getIdeas()[0] << std::endl;
	
	delete dog;
	
	//deep copy example
	Dog *dogdeep = new Dog();
	dogdeep->getBrain()->setIdeas("Croquettes");
	Dog dogdeep2 = Dog(*dogdeep);
	
	std::cout << "Before changing idea" << std::endl;
	std::cout << "Dog idea : " << dogdeep->getBrain()->getIdeas()[0] << std::endl;
	std::cout << "Dog2 idea : " << dogdeep2.getBrain()->getIdeas()[0] << std::endl;

	std::cout << "After changing dog idea" << std::endl;
	dogdeep->getBrain()->setIdeas("Cheese is better");
	std::cout << "Dog idea : " << dogdeep->getBrain()->getIdeas()[0] << std::endl;
	std::cout << "Dog2 idea : " << dogdeep2.getBrain()->getIdeas()[0] << std::endl;
	
	delete dogdeep;
	delete &dogdeep2;
}