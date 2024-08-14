/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:10:53 by victoirevau       #+#    #+#             */
/*   Updated: 2024/08/14 13:44:51 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

void testDog(void){
	//shallow copy example

	// std::cout << std::endl;
	// std::cout << "SHALLOW COPY DOG TEST" << std::endl;
	// std::cout << std::endl;
	
	// Dog *dog = new Dog();
	// dog->getBrain()->setIdeas("Croquettes");
	// Dog *dog2 = dog;
	
	// std::cout << "Before changing idea" << std::endl;
	// std::cout << "Dog idea : " << dog->getBrain()->getIdeas()[0] << std::endl;
	// std::cout << "Dog2 idea : " << dog2->getBrain()->getIdeas()[0] << std::endl;

	// std::cout << "After changing dog idea" << std::endl;
	// dog->getBrain()->setIdeas("Cheese is better");
	// std::cout << "Dog idea : " << dog->getBrain()->getIdeas()[0] << std::endl;
	// std::cout << "Dog2 idea : " << dog2->getBrain()->getIdeas()[0] << std::endl;
	
	// std::cout << std::endl;
	// delete dog;
	
	//deep copy example

	std::cout << std::endl;
	std::cout << "DEEP COPY DOG TEST" << std::endl;
	std::cout << std::endl;
	
	Dog *dogdeep = new Dog();
	std::cout << "------------------" << std::endl;
	dogdeep->getBrain()->setIdeas("Croquettes");
	Dog dogdeep2(*dogdeep);
	std::cout << "------------------" << std::endl;
	
	std::cout << "Before changing idea" << std::endl;
	std::cout << "Dog idea : " << dogdeep->getBrain()->getIdeas()[0] << std::endl;
	std::cout << "Dog2 idea : " << dogdeep2.getBrain()->getIdeas()[0] << std::endl;

	std::cout << "After changing dog idea" << std::endl;
	dogdeep->getBrain()->setIdeas("Cheese is better");
	std::cout << "Dog idea : " << dogdeep->getBrain()->getIdeas()[0] << std::endl;
	std::cout << "Dog2 idea : " << dogdeep2.getBrain()->getIdeas()[0] << std::endl;
	
	std::cout << std::endl;
	delete dogdeep;
}

void testCat(void){
	//shallow copy example
	
	// std::cout << std::endl;
	// std::cout << "SHALLOW COPY CAT TEST" << std::endl;
	// std::cout << std::endl;
	
	// Cat *cat = new Cat();
	// cat->getBrain()->setIdeas("Croquettes");
	// Cat *cat2 = cat;
	
	// std::cout << "Before changing idea" << std::endl;
	// std::cout << "cat idea : " << cat->getBrain()->getIdeas()[0] << std::endl;
	// std::cout << "cat2 idea : " << cat2->getBrain()->getIdeas()[0] << std::endl;

	// std::cout << "After changing cat idea" << std::endl;
	// cat->getBrain()->setIdeas("Cheese is better");
	// std::cout << "cat idea : " << cat->getBrain()->getIdeas()[0] << std::endl;
	// std::cout << "cat2 idea : " << cat2->getBrain()->getIdeas()[0] << std::endl;
	
	// std::cout << std::endl;
	// delete cat;
	
	// //deep copy example
	
	// std::cout << std::endl;
	// std::cout << "DEEP COPY CAT TEST" << std::endl;
	// std::cout << std::endl;
	
	// Cat *catdeep = new Cat();
	// catdeep->getBrain()->setIdeas("Croquettes");
	// Cat catdeep2 = Cat(*catdeep);
	
	// std::cout << "Before changing idea" << std::endl;
	// std::cout << "cat idea : " << catdeep->getBrain()->getIdeas()[0] << std::endl;
	// std::cout << "cat2 idea : " << catdeep2.getBrain()->getIdeas()[0] << std::endl;

	// std::cout << "After changing cat idea" << std::endl;
	// catdeep->getBrain()->setIdeas("Cheese is better");
	// std::cout << "cat idea : " << catdeep->getBrain()->getIdeas()[0] << std::endl;
	// std::cout << "cat2 idea : " << catdeep2.getBrain()->getIdeas()[0] << std::endl;
	
	// std::cout << std::endl;
	// delete catdeep;
}

int main()
{
	// Animal** array = new Animal*[6];

	// for (int i = 0; i < 4; i++){
	// 	if (i % 2 == 0)
	// 		array[i] = new Dog();
	// 	else
	// 		array[i] = new Cat();
	// }
	// std::cout << std::endl;
	// for (int i = 0; i < 4; i++){
	// 	std::cout << array[i]->getType() << " : ";
	// 	array[i]->makeSound();
	// }
	// std::cout << std::endl;
	// std::cout << "Let's free the array!" << std::endl;
	// std::cout << std::endl;
	// for (int i = 0; i < 4; i++){
	// 	delete array[i];
	// }
	// delete[] array;
	// std::cout << std::endl;
	std::cout << "------------------------------------" << std::endl;
	testDog();
	std::cout << "------------------------------------" << std::endl;
	testCat();
	return 0;
}

// int main() {
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	delete j;//should not create a leak delete i;
// 	delete i;
// 	return 0;
// }


//est-ce que le brain destructor ne doit pas être appele avant de delete le dog ou le cat ?
