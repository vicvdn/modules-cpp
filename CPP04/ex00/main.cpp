/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:10:53 by victoirevau       #+#    #+#             */
/*   Updated: 2024/07/30 17:27:46 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// int main()
// {
//   const Animal* meta = new Animal();
//   const Animal* j = new Dog();
//   const Animal* i = new Cat();
//   std::cout << j->getType() << " " << std::endl;
//   std::cout << i->getType() << " " << std::endl;
//   i->makeSound(); //will output the cat sound!
//   j->makeSound();
//   meta->makeSound();
//   delete j;
//   delete i;
//   delete meta;

  
// return 0;
// }

// int main()
// {
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
	
// 	std::cout << meta->getType() << " " << std::endl;
// 	i->makeSound(); //will output the cat sound!
// 	std::cout << j->getType() << " " << std::endl;
// 	j->makeSound();
// 	std::cout << i->getType() << " " << std::endl;
// 	meta->makeSound();
	
// 	delete j;
// 	delete i;
// 	delete meta;
	
// 	Animal	ani = Animal();
// 	ani.makeSound();
// 	ani = Cat();
// 	std::cout << ani.getType() << ": ";
// 	ani.makeSound();
// 	// std::cout << std::endl;
	
// 	const WrongAnimal* wanimal = new WrongAnimal();
// 	const WrongAnimal* wcat = new WrongCat();
	
// 	std::cout << wanimal->getType() << " " << std::endl;
// 	std::cout << wcat->getType() << " " << std::endl;
// 	wanimal->makeSound();
// 	wcat->makeSound();
	
// 	delete wanimal;
// 	delete wcat;
	
// 	return 0;
// }

int	main(void)
{
	const Animal*	ani = new Animal();
	const Animal*	dog = new Dog();
	const Animal*	cat = new Cat();

	std::cout << ani->getType() << " " << std::endl;
	ani->makeSound();
	std::cout << dog->getType() << " " << std::endl;
	dog->makeSound();
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound();

	delete ani;
	delete dog;
	delete cat;

	std::cout << std::endl;

	Animal	ana = Animal();
	ana.makeSound();
	ana = Cat();
	std::cout << ana.getType() << ": ";
	ana.makeSound();

	std::cout << std::endl;

	const WrongAnimal*	wani = new WrongAnimal();
	const WrongAnimal*	wcat = new WrongCat();

	std::cout << wani->getType() << " " << std::endl;
	wani->makeSound();
	std::cout << wcat->getType() << " " << std::endl;
	wcat->makeSound();

	delete wani;
	delete wcat;

	std::cout << std::endl;
	return 0;
}
