/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:10:53 by victoirevau       #+#    #+#             */
/*   Updated: 2024/08/14 12:05:51 by vvaudain         ###   ########.fr       */
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

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << std::endl;
	
	std::cout << meta->getType() << " : ";
	meta->makeSound(); //will output the cat sound!
	std::cout << j->getType() << " : ";
	j->makeSound();
	std::cout << i->getType() << " : ";
	i->makeSound();
	
	std::cout << std::endl;
	delete j;
	delete i;
	delete meta;
	std::cout << "----------------------------------" << std::endl;
	
	Animal	ani = Animal();
	ani.makeSound();
	ani = Cat();
	std::cout << ani.getType() << " : ";
	ani.makeSound();
	
	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;

	
	const WrongAnimal* wanimal = new WrongAnimal();
	const WrongAnimal* wcat = new WrongCat();
	
	std::cout << wanimal->getType() << " : ";
	wanimal->makeSound();
	std::cout << wcat->getType() << " : ";
	wcat->makeSound();
	
	delete wanimal;
	delete wcat;
	
	return 0;
}