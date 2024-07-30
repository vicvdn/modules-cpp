/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:10:53 by victoirevau       #+#    #+#             */
/*   Updated: 2024/07/30 15:01:51 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

// int	main(void){
// 	Animal	animal;
// 	Cat		catkittycat;
// 	Dog		doggo;

// 	std::cout << "I am a " << animal.getType() << std::endl;
// 	std::cout << "I am a " << catkittycat.getType() << std::endl;
// 	std::cout << "I am a " << doggo.getType() << std::endl;
	
// 	animal.makeSound();
// 	catkittycat.makeSound();
// 	doggo.makeSound();
// 	return 0;
// }

int main() {
	const Animal* meta = new Animal(); 
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
    meta->makeSound();
	
	delete i;
	delete j;
	delete meta;
	return 0;
}