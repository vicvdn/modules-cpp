/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:47:22 by victoirevau       #+#    #+#             */
/*   Updated: 2024/10/17 16:00:36 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void printSeparator()
{
	std::cout << "---------------------------------" << std::endl;
}

int main(void)
{
	std::cout << "String array" << std::endl;
	
	std::string array[] = {"Hello", "World", "!"};
	size_t arraySize = sizeof(array) / sizeof(array[0]);
	printSeparator();
	iter(array, arraySize, &print);
	printSeparator();
	iter(array, arraySize, &changeTo0);
	iter(array, arraySize, &print);
	printSeparator();
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Int array" << std::endl;
	
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intArraySize = sizeof(intArray) / sizeof(intArray[0]);
	printSeparator();
	iter(intArray, intArraySize, &print);
	printSeparator();
	iter(intArray, intArraySize, &changeTo0);
	iter(intArray, intArraySize, &print);
	printSeparator();

	std::cout << "Empty array" << std::endl;
	
	int emptyArray[] = {};
	size_t emptyArraySize = sizeof(emptyArray) / sizeof(emptyArray[0]);
	printSeparator();
	iter(emptyArray, emptyArraySize, &print);
	printSeparator();
	iter(emptyArray, emptyArraySize, &changeTo0);
	iter(emptyArray, emptyArraySize, &print);
	printSeparator();
	
	return 0;
}